#include "file.h"

#include <iostream>
#include <fstream>
#include <dirent.h>

#include <stdio.h>



std::string readFile(const char* path) {
    std::string contents;
    std::string line;
    // open file
    std::ifstream f (path);

    // read contents
    if (f.is_open()) {
        while (getline(f, line) ){
            contents += line + '\n';
        }
        f.close();
    }

    else {
        std::cout << "Unable to open file" << std::endl;
    }

    return contents;
}

int fileSize(const char* path) {
    std::streampos begin, end;
    // open file
    std::ifstream f (path, std::ios::binary);

    // get key positions
    begin = f.tellg();
    f.seekg (0, std::ios::end);
    end = f.tellg();

    f.close();

    return end - begin;
}


// get files in directory
std::vector<std::string>* listDir(std::string path) {
    // 256 chars in dir->d_name
    std::vector<std::string>* files = new std::vector<std::string>;

    // string to const char*
    const char* cpath = path.c_str();

    DIR *d;
    struct dirent *dir;
    d = opendir(cpath);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (isFile(path + '/' + dir->d_name)) {
                files->push_back(dir->d_name);
            }
        }
        closedir(d);
    }

    return files;
}

// get number of files in directory
unsigned int dirSize(std::string path) {
    // total
    unsigned int t = 0;

    DIR *d;
    struct dirent *dir;
    d = opendir(path.c_str());
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (isFile(path + '/' + dir->d_name)) {
                t++;
            }
        }
        closedir(d);
    }

    return t;
}


// C file read approach
bool isFile(std::string path) {
    FILE *file;

    if (file = fopen(path.c_str(), "r")) {
        fclose(file);
        return 1;
    }
    return 0;
}
