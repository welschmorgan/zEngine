#include "ogre_console.h"
#include <OgreException.h>

namespace ZSys
{
OgreConsole::OgreConsole(bool create_now, Ogre::RenderWindow * win)
{
    m_silverback = nullptr;
    m_screen = nullptr;
    m_layer = nullptr;
    m_window = nullptr;
    m_lines = nullptr;
    m_prompt = nullptr;
    m_back = nullptr;
    if (create_now)
        create(win);
}

OgreConsole::~OgreConsole()
{
    destroy();
}
void OgreConsole::destroy()
{
    if (m_silverback)
        delete m_silverback, m_silverback = nullptr;
}
void OgreConsole::create(Ogre::RenderWindow * win)
{
    if (m_silverback)
        return ;

    if (!win && !m_window)
        OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "No window supplied", __FUNC__);
    m_window = win;
    // Create Silverback and load in dejavu
    m_silverback = new Gorilla::Silverback();
    m_silverback->loadAtlas("dejavu", Ogre::ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
    m_screen = m_silverback->createScreen(m_window->getViewport(0), "dejavu");
    m_screen->setOrientation(Ogre::OR_DEGREE_270);
    Ogre::Real  vpW = m_screen->getWidth(),
                vpH = m_screen->getHeight();

    // Create our drawing layer
    m_layer = m_screen->createLayer(0);
    m_back = m_layer->createRectangle(0,0, vpW, vpH);
    m_back->background_gradient(Gorilla::Gradient_Diagonal, Gorilla::rgb(98,0,63), Gorilla::rgb(255,180,174));
    m_prompt = m_layer->createCaption(9, vpW - 55, 5, "9");
    m_prompt->width(50);
    m_prompt->align(Gorilla::TextAlign_Right);


}
};
