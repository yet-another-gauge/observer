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

#include "subject.h"

typedef struct observer_list_t {
  const observer_t *observer;
  struct observer_list_t *next;
} observer_list_t;

struct subject_t {
  observer_list_t *head;
};

subject_t *subject_new(void) {
  subject_t *subject = malloc(sizeof(subject_t));
  subject->head = NULL;

  return subject;
}

void subject_delete(subject_t *subject) {
  if (subject != NULL) {

    observer_list_t *node = subject->head;
    while (node != NULL) {
      observer_list_t *temp = node->next;
      free(node);
      node = temp;
    }

    free(subject);
  }
}

void subject_attach(subject_t *subject, const observer_t *observer) {
  observer_list_t *head = malloc(sizeof(observer_list_t));
  head->observer = observer;
  head->next = subject->head;

  subject->head = head;
}

void subject_detach(subject_t *subject, const observer_t *observer) {
  observer_list_t *prev = NULL;
  observer_list_t *curr = subject->head;

  while (curr != NULL) {
    if (curr->observer == observer) {
      if (prev == NULL) {
        subject->head = subject->head->next;
      } else {
        prev->next = curr->next;
      }

      break;
    }
    prev = curr;
    curr = curr->next;
  }
}

void subject_notify(const subject_t *subject, int argc, const void *argv[]) {
  observer_list_t *node = subject->head;

  while (node != NULL) {
    observer_update(node->observer, argc, argv);
    node = node->next;
  }
}
