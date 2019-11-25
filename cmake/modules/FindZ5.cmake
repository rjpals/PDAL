###############################################################################
#
# CMake module to search for GeoTIFF library
#
# On success, the macro sets the following variables:
# Z5_FOUND       = if the library found
# Z5_LIBRARIES   = full path to the library
# Z5_INCLUDE_DIR = where to find the library headers also defined,
#                       but not for general use are
# Z5_LIBRARY     = where to find the PROJ.4 library.
# Z5_VERSION     = version of library which was found, e.g. "1.2.5"
#
# Copyright (c) 2009 Mateusz Loskot <mateusz@loskot.net>
#
# Module source: http://github.com/mloskot/workshop/tree/master/cmake/
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#
###############################################################################

IF(Z5_INCLUDE_DIR)
  # Already in cache, be silent
  SET(Z5_FIND_QUIETLY TRUE)
ENDIF()


FIND_PATH(Z5_INCLUDE_DIR
  file.hxx
  PATH_SUFFIXES z5)



# Handle the QUIETLY and REQUIRED arguments and set Z5_FOUND to TRUE
# if all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GeoTIFF DEFAULT_MSG Z5_LIBRARY Z5_INCLUDE_DIR)
