With Clang:

clang++ -std=c++23 -stdlib=libc++ -fmodules --precompile -xc++-module mymodule.ixx
clang++ -std=c++23 -stdlib=libc++ -fmodules -c -xc++ -fmodule-file=mymodule=mymodule.pcm mymodule.ixx
clang++ -std=c++23 -stdlib=libc++ -fmodules main.cc -fmodule-file=mymodule=mymodule.pcm mymodule.o

With GCC:

g++ -std=c++23 -fmodules -c mymodule.ixx
g++ -std=c++23 -fmodules main.cc mymodule.o

