#ifndef Z_CONFIG_HH
# define Z_CONFIG_HH

#include <OgrePlatform.h>
#include "version.h"
#include "defs.h"
#include "forward.h"
#include "export.h"
#include <OgreString.h>

/**
 * Configures the platform we're on
 */
#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
#	define OGRE_PLATFORM_STRING "Linux"
#elif OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#	define OGRE_PLATFORM_STRING "Windows"
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS
#	define OGRE_PLATFORM_STRING "Apple(IOS)"
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#	define OGRE_PLATFORM_STRING "Apple"
#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#	define OGRE_PLATFORM_STRING "Android"
#elif OGRE_PLATFORM == OGRE_PLATFORM_NACL
#	define OGRE_PLATFORM_STRING "NaCL"
#else
#	define OGRE_PLATFORM_STRING "Unknown Platform"
#endif

/**
 * Configures the compiler
 */
#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#	define OGRE_COMPILER_STRING "MSVC"
#elif OGRE_COMPILER == OGRE_COMPILER_GNUC
#	define OGRE_COMPILER_STRING "GnuC"
#elif OGRE_COMPILER == OGRE_COMPILER_BORL
#	define OGRE_COMPILER_STRING "Borland"
#elif OGRE_COMPILER == OGRE_COMPILER_WINSCW
#	define OOGRE_COMPILER_STRING "WinSCW"
#elif OGRE_COMPILER == OGRE_COMPILER_GCCE
#	define OGRE_COMPILER_STRING "GccE"
#elif OGRE_COMPILER == OGRE_COMPILER_CLANG
#	define OGRE_COMPILER_STRING "CLang"
#else
#	define OGRE_COMPILER_STRING "Unknown Compiler"
#endif


/**
 * Configures Endianness
 */
#if OGRE_ENDIAN == OGRE_ENDIAN_LITTLE
#	define OGRE_ENDIAN_STRING "Little endian"
#elif OGRE_ENDIAN == OGRE_ENDIAN_BIG
#	define OGRE_ENDIAN_STRING "Big endian"
#endif


/**
 * Configures the architecture
 */
#if OGRE_ARCH_TYPE == OGRE_ARCHITECTURE_32
#	define OGRE_ARCHITECTURE_STRING "x86"
#elif OGRE_ARCH_TYPE == OGRE_ARCHITECTURE_64
#	define OGRE_ARCHITECTURE_STRING "x64"
#else
#	define OGRE_ARCHITECTURE_STRING "Unknown Architecture"
#endif

/**
 * Configures the unicode
 */
#define Z_USES_UNICODE OGRE_UNICODE_SUPPORT

#if Z_USES_UNICODE == 1
#   define OGRE_WCHAR_T_STRINGS
#   define _T(x) L ## x
#else
#   define _T(x) x
#endif

namespace ZSys
{
#if Z_USES_UNICODE == 1
    typedef char                char_t;
#else
    typedef wchar_t             char_t;
#endif
    typedef Ogre::String            string;
    typedef Ogre::StringStream      sstream;

    typedef Ogre::ColourValue color;

	Z_API_C FORCEINLINE std::wstring mb_to_iso(const std::string & str);
	Z_API_C FORCEINLINE std::string iso_to_mb(const std::wstring & str);
	Z_API_C FORCEINLINE string getBuildInformations();
    Z_API_C FORCEINLINE const Ogre::String &getOgrePlatform(void);
}

#include "dev.h"

#if defined(Z_DEBUG_BUILD)
#define Z_LOG(msg) Ogre::LogManager::getSingleton().logMessage(msg);
#elif defined(Z_DEV_BUILD)
#define Z_LOG(msg) DEV_INFO(msg)
#else
#define Z_LOG(msg)
#endif

#endif
