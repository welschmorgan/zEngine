#ifndef Z_AMBIANCEMANAGER_H
#define Z_AMBIANCEMANAGER_H

#include "root.h"

namespace zsys
{
    class Z_API AmbianceManager
    {
        public:
            AmbianceManager(Root * root);
            virtual ~AmbianceManager();

            void setLighAmbient(const color &col);
            void setSkyBox(bool enable, const string& name);
            void setSkyDome(bool enable, const string& name);
            void setSkyPlane(bool enable, const Ogre::Plane &, const string& name);
            void setShadowTechnique(Ogre::ShadowTechnique t);
        protected:
            Root            *mRoot;
            Ogre::Light     *mLight;
        private:
    };
};

#endif // Z_AMBIANCEMANAGER_H
