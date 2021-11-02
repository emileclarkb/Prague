#ifndef SHADER_H
#define SHADER_H

class shader {
    public:
        // shader construction
        shader(const char*, const char*);
        // de-allocate resources
        ~shader();

        void link();
    private:
        void newShader(const char*, bool);
    protected:
        // verification message storage
        int success;
        char info[512];

        // shader source
        const char* vSource;
        const char* fSource;

        // shader program
        unsigned int program;
};

#endif
