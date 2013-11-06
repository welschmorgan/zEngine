#include <iostream>
#include <stdexcept>
#include "root.h"

int main(void)
{
    try
    {
        std::unique_ptr<zsys::Root> root(new zsys::Root);
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
