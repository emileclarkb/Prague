#ifndef INIT_H
#define INIT_H

#include <string>
using namespace std;

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class renderer {
    public:
        renderer(const char*, uint16_t, uint16_t);
        ~renderer();

        // const char* title;
        uint16_t width;
        uint16_t height;
        bool status;

        // set framebuffer size callback
        void sizeCallback(void (*) (GLFWwindow*, int, int));

        void run();
        // event functions
        void (*awake)(renderer*);
        void (*update)(renderer*);

        // wrapper
        void close();
        bool getInput(unsigned int, unsigned int);

        void setVertices(float vertices[], uint8_t);

        // PRIVATE
        // vertex management
        unsigned int VAO;
        unsigned int VBO;

        // PROTECTED
        GLFWwindow* window;
    private:

    protected:
};

#endif
