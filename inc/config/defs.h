#ifndef DEFS_H
#define DEFS_H

#ifdef EXPORT_STATIC
#   define Z_BUILD_LIBRARY
#   define Z_BUILD_STATIC
#elif defined(EXPORT_DLL)
#   define Z_BUILD_LIBRARY
#   define Z_BUILD_DLL
#elif !defined(NO_IMPORT)
#   define Z_LINK_LIBRARY
#endif

/**
 * Developper build
 */
#ifdef DEV_BUILD
#   define Z_DEV_BUILD
#endif

/**
 * Debug/Release build
 */
#if !defined(Z_DEV_BUILD) && (defined(NDEBUG) && !defined(_DEBUG))
#   define Z_RELEASE_BUILD
#else
#   define Z_DEBUG_BUILD
#endif

#endif // DEFS_H
