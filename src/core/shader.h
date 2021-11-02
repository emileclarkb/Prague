#ifndef SHADER_H
#define SHADER_H

class shader {
    public:
        // shader construction
        shader(const char*, const char*);
        // de-allocate resources
        ~shader();

        void link();

        // shader source
        // hey
        char* vSource;
        // Michael here
        char* fSource;
    private:
        void newShader(const char*, bool);
    protected:
        // verification message storage
        int success;
        char info[512];

        // shader program
        unsigned int program;
};

#endif
