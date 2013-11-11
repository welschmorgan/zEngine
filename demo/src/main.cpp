#include <iostream>
#include "root.h"
#include "dev.h"
#include "states.h"
#include "state_manager.h"


using namespace ZSys;

int main(void)
{
    try
    {
        DEV_INFO("Main: Creating engine ...");
        std::unique_ptr<Root> root(new Root);
        MainMenuState * s = nullptr;
        try
        {
            s = new MainMenuState;
            root->getStateManager()->registerState(s);
            root->getStateManager()->pushState(s);
        }
        catch(std::exception & e)
        {
            delete s, s = nullptr;
            throw;
        }
        catch(...)
        {
            delete s, s = nullptr;
            throw;
        }
        DEV_INFO("Main: Initialising render loop ...");
        root->mainLoop();
    }
    catch (Ogre::Exception & e)
    {
        std::cerr << "[-] " << e.getFullDescription() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "[-] " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown error happened" << std::endl;
    }

    return 0;
}
