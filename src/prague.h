#ifndef PRAGUE_H
#define PRAGUE_H

#include "renderer.h"

// Prague inheritance class
class Prague {
    public:
        // virtual event functions
        virtual void awake() {};
        virtual void update() {};

    protected:
        Renderer* r;
};

#endif
