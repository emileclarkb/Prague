#include "shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "string.h"
using namespace std;

// shader construction
shader::shader(const char* V, const char* S) {
    vSource = V;
    fSource = S;

    // construct shaders
    newShader(vSource, 1);
    newShader(fSource, 0);

    link();
}

// de-allocate resources
shader::~shader() {
    glDeleteProgram(program);
}

// new shader
void shader::newShader(const char* source, bool type) {
    // GL_FRAGMENT_SHADER == 35632 , GL_VERTEX_SHADER == 35633
    // create shader reference
    unsigned int s = glCreateShader(GL_FRAGMENT_SHADER + type);
    glShaderSource(s, 1, &source, NULL);
    glCompileShader(s);

    // verify compilation process
    glGetShaderiv(s, GL_COMPILE_STATUS, &success);

    // compilation failed
    if (!success)
    {
        glGetShaderInfoLog(s, 512, NULL, info);
        cout << "ERROR::SHADER::COMPILATION_FAILED\n" << info << endl;
    }

    // link shaders
    glAttachShader(program, s);
    // clean
    glDeleteShader(s);
}

// link program
void shader::link() {
    glLinkProgram(program);

    // verify linking process
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, info);
        cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info << endl;
    }
}
