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

#ifndef YET_ANOTHER_GAUGE__OBSERVER__SUBJECT_H
#define YET_ANOTHER_GAUGE__OBSERVER__SUBJECT_H

#include "observer.h"

typedef struct subject_t subject_t;

/**
 * @brief Allocate a struct subject_t, intended to be used as a subject.
 * @return The subject
 */
subject_t *subject_new(void);

/**
 * @brief Free the memory for the given subject.
 * @param [in,out] subject
 */
void subject_delete(subject_t *subject);

/**
 * @brief Attach the observer to a subject.
 * @param [in,out] subject
 * @param [in] observer
 */
void subject_attach(subject_t *subject, const observer_t *observer);

/**
 * @brief Detach the given observer from the subject.
 * @param [in,out] subject
 * @param [in] observer
 */
void subject_detach(subject_t *subject, const observer_t *observer);

/**
 * @brief Send a notification to all the observers of subject.
 * @param [in] subject
 * @param [in] argc
 * @param [in] argv
 */
void subject_notify(const subject_t *subject, int argc, const void *argv[]);

#endif // YET_ANOTHER_GAUGE__OBSERVER__SUBJECT_H
