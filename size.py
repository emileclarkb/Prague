# ASSETS
import os
import sys


# 457 3/11/2021 7:45 AM AEST
# 694 3/11/2021 7:08 PM AEST

# ignore
blacklist = ['glad.c']
exBlacklist = ['dll', 'lib', 'exe'] #extension blacklist

# get lines in directory
def lines(path):
    # lines in files (sum)
    s = 0

    for i in os.listdir(path):
        if i not in blacklist:
            f = f'{path}\{i}'
            if os.path.isdir(f):
                s += lines(f)
            else:
                if f.split('.')[-1] not in exBlacklist:
                    try:
                        s += sum(1 for line in open(f))
                    except UnicodeDecodeError:
                        print(f)
                        sys.exit(0)

    return s

def main():
    s = lines('src')
    print(s)

if __name__ == '__main__':
    main()
