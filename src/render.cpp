#include "init.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <ostream>
using namespace std;



// settings
const unsigned uint16_t SCR_WIDTH = 800;
const unsigned uint16_t SCR_HEIGHT = 600;

// set up vertex data (and buffer(s)) and configure vertex attributes
float vertices[] = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
};



void awake() {}
// render loop
void update(renderer &r) {
    if (r.getInput(GLFW_KEY_ESCAPE, GLFW_PRESS)) {
        r.close();
    }
}

int main(int argc, char *argv[])
{
    // initialize renderer
    renderer r = renderer(SCR_WIDTH, SCR_HEIGHT, "Renderer");
    // error occurred
    if (r.status) {
        return -1;
    }

    // set renderer attributes
    r.sizeCallback(sizeCallback);
    r.setVertices(vertices);
    r.awake = awake;
    r.update = update;

    shader s = shader("core/shaders/fragment.fs", "core/shaders/vertex.vs");

    // run mainloop
    r.run()

    return 0;
}

// window dimensions altered
void sizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
