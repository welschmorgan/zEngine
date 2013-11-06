#ifndef Z_EXPORT_HH
#define Z_EXPORT_HH

#if defined _WIN32 || defined __CYGWIN__
  #ifdef EXPORT_LIBRARY
    #ifdef __GNUC__
      #define Z_PUBLIC __attribute__ ((dllexport))
      #define Z_LOCAL
    #else
      #define Z_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
      #define Z_LOCAL
    #endif
  #else
    #ifdef __GNUC__
      #define Z_PUBLIC __attribute__ ((dllimport))
    #else
      #define Z_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define Z_LOCAL
#else
  #if __GNUC__ >= 4
    #define Z_PUBLIC __attribute__ ((visibility ("default")))
    #define Z_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define Z_PUBLIC
    #define Z_LOCAL
  #endif
#endif

#if defined(Z_BUILD_LIBRARY) && Z_BUILD_LIBRARY == 1
    #define Z_API Z_PUBLIC
#else
    #define Z_API Z_LOCAL
#endif

#define Z_API_C extern "C" Z_API

#endif
