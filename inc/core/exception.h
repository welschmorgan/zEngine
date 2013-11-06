#ifndef EXCEPTION_H
# define EXCEPTION_H

# include <stdexcept>
# include <OgreException.h>
# include "platform.h"

namespace zsys
{
    class Z_API exception
        : public std::runtime_error
    {
        Ogre::uint32    mLine;
        Ogre::String    mMessage,
                        mFunction,
                        mFile;
        Ogre::uint32    mCode;
        public:
            /** Default constructor */
            exception(const int code, const Ogre::String &msg, const Ogre::String &file, const Ogre::String &func, const size_t line);
            /** Default destructor */
            virtual ~exception() throw();

            const Ogre::String  &getMessage() const;
            const Ogre::String  &getFunction() const;
            const Ogre::String  &getFile() const;
            const Ogre::uint32  getLine() const;
            const Ogre::String  &getFull() const;

            const char * what() const throw();
        protected:
        private:
    };
};

# define THROW(code,msg) throw zsys::exception(code,msg,__FILE__,__FUNCTION__,__LINE__);
# define CATCH_BASE catch(const zsys::exception &e)
# define CATCH_OGRE catch(const Ogre::Exception &e)
# define CATCH_ALL catch(...)
# define ERR_ALL() _T("Unknown error happened")
# define ERR_OGRE(exception) exception.getFullDescription()
# define ERR_BASE(exception) exception.getFull()
#endif // EXCEPTION_H
