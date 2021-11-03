# Assets
import os

# Constant Declarations
save = False
gcc = False
out = 'render'
extensions = ['c', 'cpp']
link = ['glfw3', 'opengl32', 'gdi32']
include = []

# file blacklist
blacklist = ['render-old.cpp']

# directory marching
def march(path):
    files = []
    for i in os.listdir(path):
        f = f'{path}\{i}'
        if os.path.isdir(f):
            files.extend(march(f))
        else:
            if i not in blacklist and i.split('.')[-1] in extensions:
                files.append(f)
    return files

def clean():
    if not save and os.path.exists(f'{out}.exe'):
        os.remove(f'{out}.exe')

def main():
    cwd = os.getcwd()
    files = march(cwd)
    files = [f.replace(cwd+'\\', '') for f in files]

    # -std=c++11
    cmd = 'gcc' if gcc else 'g++'
    cmd = f'{cmd} {" ".join(files)} -o {out} ' + \
            ' '.join(f'-l{l}' for l in link) + \
            ' '.join(f'-I{i}' for i in include)

    os.system(cmd)
    os.system(out)

    # remove binary
    clean()

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        clean()
