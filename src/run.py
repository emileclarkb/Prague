# Assets
import os
import sys # debug
import json

# Constant Declarations
save = False
gcc = False
out = 'render'
extensions = ['c', 'cpp']
link = ['glfw3', 'opengl32', 'gdi32']
include = [os.getcwd()] #include base directory?


# directory marching
def march(path, blacklist):
    files = []
    for i in os.listdir(path):
        f = f'{path}\{i}'
        if os.path.isdir(f):
            files.extend(march(f, blacklist))
        else:
            if i not in blacklist['Compile'] + blacklist['Scripts'] and \
               i.split('.')[-1] in extensions:
                files.append(f)
    return files

# generate a .cpp file that can pass scripts to the engine
def linkScripts(path, ref, blacklist):
    # get list of scripts
    scripts = os.listdir(path)

    # write to ref file
    with open(ref, 'w') as f:
        # optimize into sections
        A = ''
        B = ''
        for i, s in enumerate(scripts):
            # only include header files
            if s not in blacklist['Scripts'] and s.split('.')[-1] == 'h':
                # stay within refs
                i -= 1;
                # includes
                A += f'#include \"{path}/{s}\"\n'
                # set reference array
                B += f'\trefs->push_back(new {s.split(".")[0]});\n'

        f.write('#include "prague.h"\n#include <vector>\n\n')
        # write include section
        f.write(A)
        # begin function
        f.write('\nstd::vector<Prague*>* scripts() {\n')
        # initialize reference array
        f.write(f'\tstd::vector<Prague*>* refs;\n')
        # write reference section
        f.write(B)
        # return
        f.write('\n\treturn refs;\n}')




# delete binary file
def clean():
    if not save and os.path.exists(f'{out}.exe'):
        os.remove(f'{out}.exe')

def main():
    # load blacklist
    with open('Prague/Cache/blacklist.json', 'r') as f:
        blacklist = json.loads(f.read())

    # get files
    cwd = os.getcwd()
    files = march(cwd, blacklist)
    files = [f.replace(cwd+'\\', '') for f in files]

    # generate command
    # -std=c++11
    cmd = 'gcc' if gcc else 'g++'
    cmd = f'{cmd} {" ".join(files)} -o {out} ' + \
            ' '.join(f'-l{l}' for l in link) + ' ' + \
            ' '.join(f'-I{i}' for i in include)

    # generate "dynamic" script reference
    linkScripts('Prague/Core/Scripts', 'Prague/Cache/ref.cpp', blacklist)
    # compile and run
    os.system(cmd)
    os.system(out)

    # remove binary
    clean()

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        clean()
