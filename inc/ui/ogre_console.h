#ifndef Z_OGRECONSOLE_H
#define Z_OGRECONSOLE_H

#include "Gorilla.h"
#include "platform.h"

class Z_API OgreConsole
{
    public:
        OgreConsole(bool create_now=false,Ogre::RenderWindow * win=NULL);
        virtual ~OgreConsole();

        void create(Ogre::RenderWindow * win);
        void destroy();
    protected:
        Ogre::RenderWindow          *m_window;
        Gorilla::Silverback*        m_silverback;
        Gorilla::Screen*            m_screen;
        Gorilla::Layer*             m_layer;

        Gorilla::LineList*          m_lines;
        Gorilla::Caption*           m_prompt;
        Gorilla::Rectangle*         m_back;
    private:
};

#endif // Z_OGRECONSOLE_H
