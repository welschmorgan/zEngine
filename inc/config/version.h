#ifndef Z_VERSION_H
#define Z_VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "10";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.11";
	
	//Software Status
	static const char STATUS[] = "Developper";
	static const char STATUS_SHORT[] = "dev";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 0;
	static const long BUILD = 1;
	static const long REVISION = 10;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 207;
	#define RC_FILEVERSION 0,0,1,10
	#define RC_FILEVERSION_STRING "0, 0, 1, 10\0"
	static const char FULLVERSION_STRING[] = "0.0.1.10";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 1;
	

}
#endif //Z_VERSION_H
