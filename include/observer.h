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

#ifndef YET_ANOTHER_GAUGE__OBSERVER__OBSERVER_H
#define YET_ANOTHER_GAUGE__OBSERVER__OBSERVER_H

typedef struct observer_t observer_t;

/**
 * @brief Allocate a struct observer_t, intended to be used as a observer.
 *  The current implementation of the observer provides support for contextual data.
 *  This contextual data is given to the subject when attaching the callback.
 *  In return, the subject will provide this contextual data back to the observer as a parameter of the callback.
 * @param [in] context
 * @param [in] update
 * @return The observer
 */
observer_t *observer_new(const void *context, void (*update)(const void *context, int argc, const void *argv[]));

/**
 * @brief Free the memory for the given observer.
 * @param [in,out] observer
 */
void observer_delete(observer_t *observer);

/**
 * @brief The notification callback.
 * @param [in] observer
 * @param [in] argc
 * @param [in] argv
 */
void observer_update(const observer_t *observer, int argc, const void *argv[]);

#endif // YET_ANOTHER_GAUGE__OBSERVER__OBSERVER_H
