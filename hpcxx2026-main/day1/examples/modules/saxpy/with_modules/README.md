If you want to compile with GCC, change the imports back to
old style includes, and then do this:

g++ -std=c++23 -fmodules -xc++ -c saxpy.ixx
g++ -std=c++23 -fmodules saxpy.o usesaxpy.cc

However, by mid-2025 it has become far easier to let CMake
handle the build for module based projects.

For clang++, using CMake

CXX=clang++ cmake -B mybuild -GNinja -DCMAKE_CXX_FLAGS="-stdlib=libc++"
cmake --build mybuild

For GCC, using CMake

CXX=g++ cmake -B mybuild -GNinja
cmake --build mybuild

