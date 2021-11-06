#include "engine.h"

#include <iostream>
using namespace std;


Renderer::Renderer(const char* t, uint16_t w, uint16_t h) {
    // initilaize properties
    // title = t;
    width = w;
    height = h;
    status = 0;


    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    window = glfwCreateWindow(width, height, t, NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        status = 1;
    }
    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
        status = 1;
    }

    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);
}

// terminate program
Renderer::~Renderer() {
    // de-allocate resources
    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(1, VBO);
    // finish termination step
    glfwTerminate();
}

// window size adjusted
void Renderer::sizeCallback(void (*function) (GLFWwindow* window, int width, int height)) {
    glfwSetFramebufferSizeCallback(window, function);
}

// main loop
void Renderer::run() {
    awake(this);
    while (!glfwWindowShouldClose(window)) {
        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // render the triangle
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();

        // run update
        update(this);
    }
}

// close window
void Renderer::close() {
    glfwSetWindowShouldClose(window, true);
}

// get glfw input
bool Renderer::getInput(const unsigned int key, const unsigned int state) {
    return glfwGetKey(window, key) == state;
}

// set vertex arrays and buffers
void Renderer::setVertices(float vertices[], uint8_t size, uint8_t i) {
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO[i]);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, !i * 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
