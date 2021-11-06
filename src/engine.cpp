#include "engine.h"
#include "Prague/file.h"

#include <iostream>

int main() {
    std::vector<std::string>* files = listDir("Prague/Core/Shaders");
    unsigned int size = dirSize("Prague/Core/Shaders");
    std::cout << size << std::endl;

    delete[] files;

    // // initialize renderer
    // Renderer r = Renderer("Renderer", SCR_WIDTH, SCR_HEIGHT);
    // // error occurred
    // if (r.status) {
    //     return -1;
    // }
    // // create shader program
    // Shader s = Shader("core/shaders/vertex.vs", "core/shaders/fragment.fs");
    // r.shader = &s;
    // r.setVertices(screen1, sizeof(screen1), 0);
    // r.setVertices(screen2, sizeof(screen2), 1);
    // s.use();
    //
    // // set renderer attributes
    // r.sizeCallback(sizeCallback);
    // r.awake = &awake;
    // r.update = &update;
    //
    // // run mainloop
    // r.run();
    //
    // return 0;
}
