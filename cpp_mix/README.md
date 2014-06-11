g++ -fPIC -shared -o animal.so -I. animal.cpp
gcc -o cmain main.c animal.so
g++ -o cppmain main.cpp animal.so
