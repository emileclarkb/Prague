#ifndef SHADER_H
#define SHADER_H

class shader {
    public:
        // shader construction
        shader(const char*, const char*);
        // de-allocate resources
        ~shader();

        // use shader program
        void use();

        // shader source
        // hey
        char* vSource;
        // Michael here
        char* fSource;

        // shader references
        unsigned int vShader;
        unsigned int fShader;

        // PRIVATE
        // verification message storage
        int success;
        char info[512];

        // PRIVATE
        // shader program
        unsigned int program;
    private:
        unsigned int newShader(const char*, const bool);
    protected:

};

#endif
