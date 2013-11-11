#include "ambiance_manager.h"

namespace ZSys
{
    AmbianceManager::AmbianceManager(Root * root)
        : mRoot(root)
        , mLight(nullptr)
    {
        assert(mRoot);
    }

    AmbianceManager::~AmbianceManager()
    {
        //dtor
    }
    void AmbianceManager::setLighAmbient(const color &col)
    {
        mRoot->getParameters()->getSceneMgr()->setAmbientLight(col);
    }
    void AmbianceManager::setSkyBox(bool enable, const string& name)
    {
        mRoot->getParameters()->getSceneMgr()->setSkyBox(enable, name);
    }
    void AmbianceManager::setSkyDome(bool enable, const string& name)
    {
        mRoot->getParameters()->getSceneMgr()->setSkyDome(enable, name);
    }
    void AmbianceManager::setSkyPlane(bool enable, const Ogre::Plane &plane, const string& name)
    {
        mRoot->getParameters()->getSceneMgr()->setSkyPlane(enable, plane, name);
    }
    void AmbianceManager::setShadowTechnique(Ogre::ShadowTechnique t)
    {
        mRoot->getParameters()->getSceneMgr()->setShadowTechnique(t);
    }
};
