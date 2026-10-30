/*
 * libexplain - a library of system-call-specific strerror replacements
 * Copyright (C) 2013, 2014 Peter Miller
 * Written by Peter Miller <pmiller@opensource.org.au>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBEXPLAIN_AC_SYS_ACL_H
#define LIBEXPLAIN_AC_SYS_ACL_H

/**
  * @file
  * @brief Insulate <sys/acl.h> differences
  */

#include <libexplain/ac/sys/types.h>

#ifdef HAVE_SYS_ACL_H
#include <sys/acl.h>

/*
 * MacOS has acl_* functions, but they implement NFSv4-style ACLs.
 * Provide the POSIX.1e names the ACL text parser expects.
 */
#ifndef ACL_READ
#define ACL_USER_OBJ    0x01
#define ACL_USER        0x02
#define ACL_GROUP_OBJ   0x04
#define ACL_GROUP       0x08
#define ACL_MASK        0x10
#define ACL_OTHER       0x20
#define ACL_READ        0x04
#define ACL_WRITE       0x02
#define ACL_EXECUTE     0x01
#endif

#else

    typedef struct acl_t *acl_t;

#endif

/* vim: set ts=8 sw=4 et : */
#endif /* LIBEXPLAIN_AC_SYS_ACL_H */
