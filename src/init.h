#ifndef INIT_H
#define INIT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* init(const char*, const uint16_t, const uint16_t);


class renderer {
    public:
        renderer(char*, uint16_t, uint16_t);
        ~renderer();

        char* title;
        uint16_t width;
        uint16_t height;
        bool status;

        // set framebuffer size callback
        void sizeCallback(void&);

        void run();
        // event functions
        void awake();
        void update();

        // wrapper
        void close();
        bool getInput(unsigned int, unsigned int);

        void setVertices(float vertices[]);
    private:
        // vertex management
        unsigned int VAO;
        unsigned int VBO;
    protected:
        GLFWwindow* window;
};

#endif
