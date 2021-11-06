// class based rendering implementation
#include "renderer.h"

// prague inheritance
class render(Prague) {
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


int main(int argc, char *argv[])
{
    // initialize renderer
    Renderer r = Renderer("Renderer", SCR_WIDTH, SCR_HEIGHT);
    // error occurred
    if (r.status) {
        return -1;
    }
    // create shader program
    Shader s = Shader("core/shaders/vertex.vs", "core/shaders/fragment.fs");
    r.shader = &s;
    r.setVertices(screen1, sizeof(screen1), 0);
    r.setVertices(screen2, sizeof(screen2), 1);
    s.use();

    // set renderer attributes
    r.sizeCallback(sizeCallback);
    r.awake = &awake;
    r.update = &update;

    // run mainloop
    r.run();

    return 0;
}
