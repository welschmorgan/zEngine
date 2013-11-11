#include "state_manager.h"
#include "exception.h"
#include "root.h"
#include <OgreRoot.h>

namespace ZSys
{
    StateManager::StateManager(){}
    StateManager::StateManager(const StateManager& c):mStates(c.getStates()){}
    StateManager::~StateManager(){}

    void                StateManager::create(Root*root)
    {
        if (m_created)
            return ;
        mParams = root->getParameters();
        mRoot = root;
        mParams->getRoot()->addFrameListener(this);
        m_created = true;
    }
    void                StateManager::destroy()
    {
        if (!m_created)
            return ;
        mParams->getRoot()->removeFrameListener(this);
        while (!mStack.empty())
            popState();
        for( auto i=mStates.begin(); i!=mStates.end(); i++)
        {
            if (*i)
            {
                (*i)->stateUnregistered();
                delete (*i), (*i) = nullptr;
            }
        }
        mStates.clear();
        m_created = false;
    }

    bool                StateManager::frameStarted(const Ogre::FrameEvent& evt)
    {
        if (mStack.empty())
        {
            Ogre::LogManager * mgr = Ogre::LogManager::getSingletonPtr();
            if (mgr)
                mgr->logMessage("Shutting down as StateManager has no more state pushed !");
            return false;
        }
        bool ret = (mStack.top() ? mStack.top()->stateMainloop(evt.timeSinceLastFrame) : false);
        if (!ret)
            popState();
        return true;
    }

    const StateManager::List&         StateManager::getStates() const{ return mStates; }
    StateManager::List&               StateManager::getStates(){ return mStates; }

    bool                StateManager::isPushed(const string &id) const
    {
        if (!hasState(id))
            return false;
        return isPushed(getState(id));
    }
    bool                StateManager::isPushed(const State * s) const
    {
        StackRef::const_iterator i;
        return ((i=mStackRef.find(s)) != mStackRef.end()) && i->second;
    }
    bool                StateManager::hasState( const string &id) const
    {
        for( auto i=mStates.begin(); i!=mStates.end(); i++)
        {
            if ((*i) && (*i)->getName() == id)
                return true;
        }
        return false;
    }
    State               *StateManager::getState(const string &id)
    {
        for( auto i=mStates.begin(); i!=mStates.end(); i++)
        {
            if ((*i) && (*i)->getName() == id)
                return (*i);
        }
        THROW(Ogre::Exception::ERR_ITEM_NOT_FOUND, "Cannot find state "+id+", not registered");
        return nullptr;
    }
    const State         *StateManager::getState(const string &id)const
    {
        for( auto i=mStates.begin(); i!=mStates.end(); i++)
        {
            if ((*i) && (*i)->getName() == id)
                return (*i);
        }
        THROW(Ogre::Exception::ERR_ITEM_NOT_FOUND, "Cannot find state "+id+", not registered");
        return nullptr;
    }
    void                StateManager::registerState(State* s)
    {
        if (!s)
            THROW(Ogre::Exception::ERR_DUPLICATE_ITEM, "Cannot register state, invalid pointer");
        if (hasState(s->getName()))
            THROW(Ogre::Exception::ERR_DUPLICATE_ITEM, "Cannot register state "+s->getName()+", already registered");
        mStates.push_back(s);
        Z_LOG("StateManager: Registered state "+s->getName());
        mStates.back()->stateRegistered(mRoot);
    }
    void                StateManager::unregisterState(const string &id)
    {
        for( auto i=mStates.begin(); i!=mStates.end(); i++)
        {
            if ((*i) && (*i)->getName() == id)
            {
                (*i)->stateUnregistered();
                Z_LOG("StateManager: Unregistered state "+id);
                delete (*i), (*i) = nullptr;
                mStates.erase(i);
                return;
            }
        }
        THROW(Ogre::Exception::ERR_DUPLICATE_ITEM, "Cannot unregister state "+id+", not registered");
    }
    void                StateManager::unregisterState(State* s)
    {
        if (!s)
            THROW(Ogre::Exception::ERR_ITEM_NOT_FOUND, "Cannot unregister state, invalid pointer");

        for( auto i=mStates.begin(); i!=mStates.end(); i++)
        {
            if ((*i) && (*i) == s)
            {
                (*i)->stateUnregistered();
                Z_LOG("StateManager: Unregistered state "+s->getName());
                delete (*i), (*i) = nullptr;
                mStates.erase(i);
                return;
            }
        }
        THROW(Ogre::Exception::ERR_DUPLICATE_ITEM, "Cannot unregister state "+s->getName()+", not registered");
    }
    State               *StateManager::pushState(const string &name)
    {
        if (!hasState(name))
            THROW(Ogre::Exception::ERR_ITEM_NOT_FOUND, "Cannot push state "+name+", not registered !");
        return pushState(getState(name));
    }
    State               *StateManager::pushState(State* s)
    {
        if (!s)
            THROW(Ogre::Exception::ERR_INVALIDPARAMS, "Cannot push state, invalid pointer!");
        if (!hasState(s->getName()))
            THROW(Ogre::Exception::ERR_ITEM_NOT_FOUND, "Cannot push state "+s->getName()+", not registered !");
        if (isPushed(s))
            THROW(Ogre::Exception::ERR_ITEM_NOT_FOUND, "Cannot push state "+s->getName()+", already on stack !");
        State* old = mStack.empty()?nullptr:mStack.top();
        Z_LOG("StateManager: Pushing state "+s->getName());
        mStack.push(s);
        mStackRef[s] = true;
        s->statePushed(old);
        return s;
    }
    State               *StateManager::popState()
    {
        if (mStack.empty())
            return nullptr;
        State* old = mStack.top();
        Z_LOG("StateManager: Popping state "+(old?old->getName():string("unknown")));
        mStackRef[old] = false;
        mStack.pop();
        if (!mStack.empty())
        {
            State* state = mStack.top();
            old->statePopped(state);
            return state;
        }
        return nullptr;
    }
};
