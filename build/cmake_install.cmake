# Install script for directory: /root/dev/engines/zEngine

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "DEBUG")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DEBUG" TYPE STATIC_LIBRARY FILES "/root/dev/engines/zEngine/build/lib/DEBUG/libzEngine.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/root/dev/engines/zEngine/inc/core/camera_manager.h"
    "/root/dev/engines/zEngine/inc/core/exception.h"
    "/root/dev/engines/zEngine/inc/core/ogre_params.h"
    "/root/dev/engines/zEngine/inc/core/version.h"
    "/root/dev/engines/zEngine/inc/core/enable_name.h"
    "/root/dev/engines/zEngine/inc/core/enable_create.h"
    "/root/dev/engines/zEngine/inc/core/root.h"
    "/root/dev/engines/zEngine/inc/core/smart_ptr.hpp"
    "/root/dev/engines/zEngine/inc/init/ogre_initialiser.h"
    "/root/dev/engines/zEngine/inc/config/platform.h"
    "/root/dev/engines/zEngine/inc/config/export.h"
    "/root/dev/engines/zEngine/inc/config/defs.h"
    "/root/dev/engines/zEngine/inc/config/forward.h"
    "/root/dev/engines/zEngine/inc/config/version.h"
    "/root/dev/engines/zEngine/inc/ui/ogre_console.h"
    "/root/dev/engines/zEngine/inc/managers/ambiance_manager.h"
    "/root/dev/engines/zEngine/inc/managers/state_manager.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/root/dev/engines/zEngine/build/demo/cmake_install.cmake")
  INCLUDE("/root/dev/engines/zEngine/build/tools/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/root/dev/engines/zEngine/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/root/dev/engines/zEngine/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
