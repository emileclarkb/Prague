// class based rendering implementation

#include "Display.h"

#include <iostream>

void Display::update() {
    // get uniform values
    float time = glfwGetTime();
    // get uniform locations
    int timeLocation = glGetUniformLocation(r->shader->program, "time");
    int resLocation = glGetUniformLocation(r->shader->program, "resolution");
    // set uniform values
    glUniform1f(timeLocation, time);
    glUniform2f(resLocation, width, height);

    if (r->getInput(GLFW_KEY_ESCAPE, GLFW_PRESS)) {
        r->close();
    }
};
