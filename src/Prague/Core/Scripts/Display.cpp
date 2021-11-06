// class based rendering implementation
#include "prague.h"

// prague inheritance
class Display : public Prague {
    public:
        // render loop
        void update() {
            // get uniform values
            float time = glfwGetTime();
            // get uniform locations
            int timeLocation = glGetUniformLocation(r->shader->program, "time");
            int resLocation = glGetUniformLocation(r->shader->program, "resolution");
            // set uniform values
            glUniform1f(timeLocation, time);
            glUniform2f(resLocation, SCR_WIDTH, SCR_HEIGHT);

            if (r->getInput(GLFW_KEY_ESCAPE, GLFW_PRESS)) {
                r->close();
            }
        }
}
