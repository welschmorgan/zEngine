#include "exception.h"

namespace ZSys
{
    exception::exception(const int code,
                         const Ogre::String &msg,
                         const Ogre::String &file,
                         const Ogre::String &func,
                         const size_t line)
    : std::runtime_error(getFull().c_str())
    , mLine(line)
    , mMessage(msg)
    , mFunction(func)
    , mFile(file)
    , mCode(code)
    {
        //ctor
    }

    exception::~exception() throw()
    {
        //dtor
    }

    const Ogre::uint32  exception::getLine() const{ return mLine; }
    const Ogre::String  &exception::getMessage() const{ return mMessage;}
    const Ogre::String  &exception::getFunction() const{return mFunction;}
    const Ogre::String  &exception::getFile() const{ return mFile; }
    const Ogre::String  &exception::getFull() const{
        sstream ss;
		static Ogre::String ret;
        ret = ss.str();
        return ret;
    }

    const char * exception::what() const throw()
    {
        return getFull().c_str();
    }
};
