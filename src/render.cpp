#include "init.h"
#include "core/shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <ostream>
using namespace std;



// settings
const uint16_t SCR_WIDTH = 800;
const uint16_t SCR_HEIGHT = 600;

// set up vertex data (and buffer(s)) and configure vertex attributes
float vertices[] = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
};



void awake(renderer* r) {}
// render loop
void update(renderer* r) {
    if (r->getInput(GLFW_KEY_ESCAPE, GLFW_PRESS)) {
        r->close();
    }
}

// window dimensions altered
void sizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


int main(int argc, char *argv[])
{
    // initialize renderer
    renderer r = renderer("Renderer", SCR_WIDTH, SCR_HEIGHT);
    // error occurred
    if (r.status) {
        return -1;
    }
    // create shader program
    shader s = shader("core/shaders/vertex.vs", "core/shaders/fragment.fs");
    r.setVertices(vertices, sizeof(vertices));
    s.use();

    // set renderer attributes
    r.sizeCallback(sizeCallback);
    r.awake = &awake;
    r.update = &update;

    // run mainloop
    r.run();

    return 0;
}
