#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

std::string readFile(const char*);
int fileSize(const char*);

std::vector<std::string>* listDir(std::string);
unsigned int dirSize(std::string);

bool isFile(std::string);

#endif
