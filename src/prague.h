#ifndef PRAGUE_H
#define PRAGUE_H

// Prague inheritance class
class Prague {
    public:
        // virtual event functions
        virtual void awake();
        virtual void update();

    private:
        Renderer* r;
}

#endif
