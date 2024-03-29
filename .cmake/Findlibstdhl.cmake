#
#   Copyright (C) 2014-2024 CASM Organization <https://casm-lang.org>
#   All rights reserved.
#
#   Developed by: Philipp Paulweber et al.
#   <https://github.com/casm-lang/libstdhl/graphs/contributors>
#
#   This file is part of libstdhl.
#
#   libstdhl is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   libstdhl is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with libstdhl. If not, see <http://www.gnu.org/licenses/>.
#
#   Additional permission under GNU GPL version 3 section 7
#
#   libstdhl is distributed under the terms of the GNU General Public License
#   with the following clarification and special exception: Linking libstdhl
#   statically or dynamically with other modules is making a combined work
#   based on libstdhl. Thus, the terms and conditions of the GNU General
#   Public License cover the whole combination. As a special exception,
#   the copyright holders of libstdhl give you permission to link libstdhl
#   with independent modules to produce an executable, regardless of the
#   license terms of these independent modules, and to copy and distribute
#   the resulting executable under terms of your choice, provided that you
#   also meet, for each linked independent module, the terms and conditions
#   of the license of that module. An independent module is a module which
#   is not derived from or based on libstdhl. If you modify libstdhl, you
#   may extend this exception to your version of the library, but you are
#   not obliged to do so. If you do not wish to do so, delete this exception
#   statement from your version.
#

# LIBSTDHL_FOUND        - system has found the package
# LIBSTDHL_INCLUDE_DIR  - the package include directory
# LIBSTDHL_LIBRARY      - the package library

include( LibPackage )

libfind_pkg_check_modules( LIBSTDHL_PKGCONF libstdhl )

find_path( LIBSTDHL_INCLUDE_DIR
  NAMES libstdhl/libstdhl.h
  PATHS ${LIBSTDHL_PKGCONF_INCLUDE_DIRS}
  )

find_library( LIBSTDHL_LIBRARY
  NAMES libstdhl.so libstdhl.dylib libstdhl.dll
  PATHS ${LIBSTDHL_PKGCONF_LIBRARY_DIRS}
  )

find_library( LIBSTDHL_ARCHIVE
  NAMES libstdhl.a
  PATHS ${LIBSTDHL_PKGCONF_LIBRARY_DIRS}
  )

set( LIBSTDHL_PROCESS_INCLUDES LIBSTDHL_INCLUDE_DIR )
set( LIBSTDHL_PROCESS_LIBS     LIBSTDHL_LIBRARY LIBSTDHL_ARCHIVE )

libfind_process( LIBSTDHL )

if( EXISTS "${LIBSTDHL_LIBRARY}" AND ${LIBSTDHL_LIBRARY} AND
    EXISTS "${LIBSTDHL_ARCHIVE}" AND ${LIBSTDHL_ARCHIVE} )
  set( LIBSTDHL_FOUND TRUE PARENT_SCOPE )
else()
  set( LIBSTDHL_FOUND FALSE PARENT_SCOPE )
endif()
