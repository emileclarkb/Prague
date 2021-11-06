#ifndef INIT_H
#define INIT_H

#include "core/shader.h"

#include <string>
using namespace std;

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer {
    public:
        Renderer(const char*, uint16_t, uint16_t);
        ~Renderer();

        // const char* title;
        uint16_t width;
        uint16_t height;
        bool status;

        // set framebuffer size callback
        void sizeCallback(void (*) (GLFWwindow*, int, int));

        void run();
        // event functions
        void (*awake)(Renderer*);
        void (*update)(Renderer*);

        // wrapper
        void close();
        bool getInput(unsigned int, unsigned int);

        void setVertices(float vertices[], uint8_t, uint8_t);

        Shader* shader;

        // PRIVATE
        // vertex management
        unsigned int VAO[2];
        unsigned int VBO[2];

        // PROTECTED
        GLFWwindow* window;
    private:

    protected:
};

#endif
