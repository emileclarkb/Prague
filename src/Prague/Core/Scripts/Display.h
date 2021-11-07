#ifndef DISPLAY_H
#define DISPLAY_H

#include "prague.h"

// prague inheritance
class Display : public Prague {
    public:
        const uint16_t width = 800;
        const uint16_t height = 600;

        // render loop
        void update();
};

#endif
