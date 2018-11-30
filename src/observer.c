/*
 * This file is part of the 'Yet another gauge' project.
 *
 * Copyright (C) 2018 Ivan Dyachenko <vandyachen@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>

#include "observer.h"

struct observer_t {
  const void *context; /* no memory management needed for the following field for now */
  void (*update)(const void *context, int argc, const void *argv[]);
};

observer_t *observer_new(const void *context, void (*update)(const void *context, int argc, const void *argv[])) {
  observer_t *observer = malloc(sizeof(observer_t));

  observer->context = context;
  observer->update = update;

  return observer;
}

void observer_delete(observer_t *observer) {
  if (observer != NULL) {
    free(observer);
  }
}

void observer_update(const observer_t *observer, int argc, const void *argv[]) {
  observer->update(observer->context, argc, argv);
}