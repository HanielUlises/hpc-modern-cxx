The library course_utils contains some utilities required in different examples.
There is a specific way you should build and install this, so that you can
use it with minimal disruptions during the course. All participants should do
this.

If you are in the online course room, you have an environment variable, cxx2026,
pointing to your own working area. But if you are working on another computer,
you should set this variable up, for the rest of the steps to make sense.

::::: Do this **ONLY IF** you are **not** in the online course room!
export cxx2026=/a/folder/where/you/have/write/access

1. Download/Clone the course git repo
cd $cxx2026
git clone https://gitlab.jsc.fz-juelich.de/sdlbio-courses/hpcxx2026.git

2. Build and install the course_utils library

cd hpcxx2026/course_utils
CXX=g++ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$cxx2026/local \
    -GNinja -B build0 -S .

cmake --build build0
cmake --install build0

**Note:** The explicit specification of CXX=g++ above avoids many errors,
because CMake is sometimes built to default to a specific (version of a)
compiler. On our system, it is a version of GCC belonging to the same
"software stage" currently in use. That means, if you don't say anything
about what compiler to use, CMake will pick GCC 14.3.0, which is too old
for our work on C++23 and C++26. More importantly, compiling the standard
library module will fail.

3. Build and test an external project with a dependency on course_utils

cd $cxx2026/hpcxx2026/test_your_setup/use_course_utils

Read and follow the instructions in the README files in that directory
and its two subdirectories.

