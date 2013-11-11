#ifndef Z_EXPORT_HH
#define Z_EXPORT_HH

#include "defs.h"
#include <OgrePlatform.h>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_COMPILER == OGRE_COMPILER_CYGWIN
  #define Z_IMPORT_HELPER __declspec(dllimport)
  #define Z_EXPORT_HELPER __declspec(dllexport)
  #define Z_LOCAL_HELPER
#else
  #if __GNUC__ >= 4
    #define Z_IMPORT_HELPER __attribute__ ((visibility ("default")))
    #define Z_EXPORT_HELPER __attribute__ ((visibility ("default")))
    #define Z_LOCAL_HELPER  __attribute__ ((visibility ("hidden")))
  #else
    #define Z_IMPORT_HELPER
    #define Z_EXPORT_HELPER
    #define Z_LOCAL_HELPER
  #endif
#endif

#ifdef Z_BUILD_LIBRARY
    #ifdef Z_BUILD_DLL
        #define Z_API Z_EXPORT_HELPER
        #define Z_LOCAL Z_LOCAL_HELPER
    #else
        #define Z_API Z_IMPORT_HELPER
        #define Z_LOCAL Z_LOCAL_HELPER
    #endif
#elif defined(Z_LINK_LIBRARY)
    #define Z_API Z_IMPORT_HELPER
    #define Z_LOCAL Z_LOCAL_HELPER
#else
    #define Z_API
    #define Z_LOCAL
#endif

#define Z_API_C extern "C" Z_API

#endif
