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

set(DBG_FLAGS, -g)

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	list( APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} ${DBG_FLAGS}")
else()
	list( APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()

#Project Decl.
project(zengine)
add_definitions(${COMPILE_FLAGS})
set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

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


#Needs OGRE
include_directories(${GORILLA_INCLUDE_DIR})
include_directories(${OGRE_INCLUDE_DIR})
include_directories(${OIS_INCLUDE_DIR})
link_directories(${GORILLA_LIBRARY_DIR})
link_directories(${OGRE_LIBRARY_DIR}/${CMAKE_BUILD_TYPE})
link_directories(${OIS_LIBRARY_DIR}/${CMAKE_BUILD_TYPE})

#Source files
include_directories(inc/core)
include_directories(inc/states)
include_directories(inc/init)
include_directories(inc/config)
include_directories(inc/ui)
include_directories(inc/managers)

link_directories(${GORILLA_LIBRARY_DIR})
if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
link_directories(${ZENGINE_LIBRARY_DIR}/Debug)
elseif()
link_directories(${ZENGINE_LIBRARY_DIR}/Release)
endif()

file(
	GLOB_RECURSE
	inc_files
	inc/core/*
	inc/states/*
	inc/init/*
	inc/config/*
	inc/ui/*
	inc/managers/*
)

file(
	GLOB_RECURSE
	source_files
	src/core/*
	src/states/*
	src/init/*
	src/config/*
	src/ui/*
	src/managers/*
	${inc_files}
)

add_subdirectory(demo)
add_subdirectory(tools)

#Library
add_library(
	zEngine
	STATIC
	${source_files}
)

#Library links
target_link_libraries(
	zEngine
	OgreMain_d
	OIS_d
	Gorilla_d	
)


install (TARGETS zEngine DESTINATION lib/${CMAKE_BUILD_TYPE})
install (FILES ${inc_files} DESTINATION include)
