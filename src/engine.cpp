#include "engine.h"
#include "Prague/file.h"

#include <iostream>


// read from blacklist.json
// const std::vector<std::string> scriptBlacklist = {};


int main() {
    // // generate script header
    // std::vector<std::string>* files = listDir("Prague/Core/Shaders");
    // unsigned int size = dirSize("Prague/Core/Shaders");
    //
    // for (std::string f : files) {
    //     for (std::string s : scriptBlacklist) {
    //         if (f == s)
    //     }
    // }
    // delete[] files;


    // // initialize renderer
    // Renderer r("Renderer", SCR_WIDTH, SCR_HEIGHT);
    // // error occurred
    // if (r.status) {
    //     return -1;
    // }
    // // create shader program
    // Shader s("core/shaders/vertex.vs", "core/shaders/fragment.fs");
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
