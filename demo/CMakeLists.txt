#Minimum CMake version
cmake_minimum_required(VERSION 2.6)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

if(NOT ZENGINE_PATH)
	set(ZENGINE_PATH /home/darkboss/dev/engines/zEngine)
endif()

if(NOT ZENGINE_INCLUDE_DIR)
  message(STATUS "Setting zEngine include directory as none specified.")
  set(ZENGINE_INCLUDE_DIR "${ZENGINE_PATH}/inc" CACHE STRING "ZEngine include dir." FORCE)
endif()
if(NOT ZENGINE_LIBRARY_DIR)
  message(STATUS "Setting zEngine lib directory as none specified.")
  set(ZENGINE_LIBRARY_DIR "${ZENGINE_PATH}/lib" CACHE STRING "ZEngine lib dir." FORCE)
endif()
if(NOT OGRE_INCLUDE_DIR)
  message(STATUS "Setting Ogre include directory as none specified.")
  set(OGRE_INCLUDE_DIR "/usr/local/include/OGRE" CACHE STRING "OGRE include dir." FORCE)
endif()
if(NOT OGRE_LIBRARY_DIR)
  message(STATUS "Setting Ogre include directory as none specified.")
  set(OGRE_LIBRARY_DIR "/usr/local/lib/OGRE" CACHE STRING "OGRE lib dir." FORCE)
endif()
if(NOT OIS_INCLUDE_DIR)
  message(STATUS "Setting OIS include directory as none specified.")
  set(OIS_INCLUDE_DIR "/usr/local/include/OIS" CACHE STRING "OIS include dir." FORCE)
endif()
if(NOT OIS_LIBRARY_DIR)
  message(STATUS "Setting OIS include directory as none specified.")
  set(OIS_LIBRARY_DIR "/usr/local/lib/OIS" CACHE STRING "OIS lib dir." FORCE)
endif()
if(NOT GORILLA_INCLUDE_DIR)
  message(STATUS "Setting GORILLA include directory as none specified.")
  set(GORILLA_INCLUDE_DIR "/usr/local/include/Gorilla" CACHE STRING "GORILLA include dir." FORCE)
endif()
if(NOT GORILLA_LIBRARY_DIR)
  message(STATUS "Setting GORILLA include directory as none specified.")
  set(GORILLA_LIBRARY_DIR "/usr/local/lib/Gorilla" CACHE STRING "GORILLA lib dir." FORCE)
endif()

set(DBG_FLAGS -g)
set(DEV_FLAGS -DDEV_BUILD)
set(ARCH_TYPE x64)

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${DEV_FLAGS} ${CMAKE_CXX_FLAGS} ${DBG_FLAGS}")
else()
	list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${DEV_FLAGS} ${CMAKE_CXX_FLAGS}")
endif()

#Project Decl.
project(zDemo)
set(EXECUTABLE_OUTPUT_PATH bin/${ARCH_TYPE}/${CMAKE_BUILD_TYPE})

#Needs OGRE

include_directories(${OGRE_INCLUDE_DIR})
include_directories(${OIS_INCLUDE_DIR})
include_directories(${GORILLA_INCLUDE_DIR})
#Source files
include_directories(inc)
include_directories(${ZENGINE_INCLUDE_DIR}/core)
include_directories(${ZENGINE_INCLUDE_DIR}/states)
include_directories(${ZENGINE_INCLUDE_DIR}/init)
include_directories(${ZENGINE_INCLUDE_DIR}/config)
include_directories(${ZENGINE_INCLUDE_DIR}/ui)
include_directories(${ZENGINE_INCLUDE_DIR}/managers)

link_directories(${ZENGINE_LIBRARY_DIR}/${ARCH_TYPE}/${CMAKE_BUILD_TYPE})
link_directories(${OGRE_LIBRARY_DIR}/${CMAKE_BUILD_TYPE})
link_directories(${OIS_LIBRARY_DIR}/${CMAKE_BUILD_TYPE})
link_directories(${GORILLA_LIBRARY_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
set(BUILD_TYPE_POSTFIX _d)
link_directories(${ZENGINE_LIBRARY_DIR}/Debug)
elseif()
set(BUILD_TYPE_POSTFIX )
link_directories(${ZENGINE_LIBRARY_DIR}/Release)
endif()

message(STATUS "OGRE dir is: "${OGRE_LIBRARY_DIR})
message(STATUS "OIS Lib dir is: "${OIS_LIBRARY_DIR})
message(STATUS "Gorilla Lib dir is: "${GORILLA_LIBRARY_DIR})
message(STATUS "ZEngine Lib dir is: "${ZENGINE_LIBRARY_DIR})

message(STATUS "OGRE inc is: "${OGRE_INCLUDE_DIR})
message(STATUS "OIS Lib inc is: "${OIS_INCLUDE_DIR})
message(STATUS "Gorilla inc dir is: "${GORILLA_INCLUDE_DIR})
message(STATUS "ZEngine inc dir is: "${ZENGINE_INCLUDE_DIR})
message(STATUS "Building for architecture: "${ARCH_TYPE})

file(
	GLOB_RECURSE
	inc_files
	${ZENGINE_INCLUDE_DIR}/inc/core/*
	${ZENGINE_INCLUDE_DIR}/inc/states/*
	${ZENGINE_INCLUDE_DIR}/inc/init/*
	${ZENGINE_INCLUDE_DIR}/inc/config/*
	${ZENGINE_INCLUDE_DIR}/inc/ui/*
	${ZENGINE_INCLUDE_DIR}/inc/managers/*
)
file(
	GLOB_RECURSE
	source_files
	src/*
	${inc_files}
)

#Library
add_executable(
	zDemo${BUILD_TYPE_POSTFIX}
	${source_files}
)

#Library links
target_link_libraries(
	zDemo${BUILD_TYPE_POSTFIX}
	zEngine${BUILD_TYPE_POSTFIX}
	OgreMain_d
	OIS_d
	Gorilla_d
)

install (TARGETS zDemo${BUILD_TYPE_POSTFIX} DESTINATION bin/${ARCH_TYPE}/${CMAKE_BUILD_TYPE})
install (FILES ${inc_files} DESTINATION include)
