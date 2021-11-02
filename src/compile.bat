@echo off

g++ render.cpp glad.c -o render -lglfw3 -lopengl32 -lgdi32
