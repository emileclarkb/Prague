#include "file.h"

#include <iostream>
#include <fstream>
// #include <string>
// using namespace std;

string fileRead(const char* fname) {
    string contents;
    string line;
    // open file
    ifstream f (fname);

    // read contents
    if (f.is_open()) {
        while (getline(f, line) ){
            contents += line + '\n';
        }
        f.close();
    }

    else {
        cout << "Unable to open file";
    }

    return contents;
}

uint8_t fileSize(const char* fname) {
    streampos begin, end;
    // open file
    ifstream f (fname, ios::binary);

    // get key positions
    begin = f.tellg();
    f.seekg (0, ios::end);
    end = f.tellg();

    f.close();

    return end - begin;
}
