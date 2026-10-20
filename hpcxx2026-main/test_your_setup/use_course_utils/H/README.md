# Building example projects depending on the course utils headers

This directory contains a simple example program using
some features implemented in the library course_utils. To
build an executable, you need to point the compiler to
the location of the header files. This can be done in many
ways.

## Manual insertion of include path

Manually, you can just include the header path in the
compilation command line.

If you went through the build and installation steps for
the directory, the include path is

```bash
export course_utils_inc=course_utils_install_dir/include/course_utils
```

If you didn't install it, the include path is

```bash
export course_utils_inc=course_utils_source_dir
```

Then your compilation command will be something like
this:

```bash
g++ -std=c++23 -O3 -I $course_utils_inc main.cc
```

or with clang++,

```bash
clang++ -stdlib=libc++ -std=c++23 -O3 -I $course_utils_inc main.cc
```

In both cases, the executable will be called "a.out", which you can run
by typing "./a.out".


## Use a build system generator like CMake

The course_utils needs
to be installed somewhere for this to work. Let's assume
that you installed course_utils under the folder
$cxx2026/local (Remember: the environment variable cxx2026
is your personal workspace for course related work).

```bash
cmpathadd $cxx2026/local
```
Above, we use the shortcut "cmpathadd" introduced in the the file pathutils.sh.
To use that, you need to source that, i.e.,

`source course_utils_src_dir/bash/pathutils.sh`.

Otherwise, you could do this:
export CMAKE_PREFIX_PATH=$cxx2026/local:$CMAKE_PREFIX_PATH

You can now perform the following steps to build the executable.

```bash
CXX=g++ cmake -B bld -GNinja -S /path/to/source_dir
```

or, if you want to build with Clang,

```bash
CXX=clang++ cmake -DCMAKE_CXX_FLAGS="-stdlib=libc++" -B cld -GNinja -S /path/to/source_dir
```

This creates a directory called "bld" and and configures the project
inside it. Then:

```bash
cmake --build bld
```

The compiles the project inside it using the compiler you provided
in the configure step.

To run, type "./bld/main" or "./cld/main".

### Note:

Functionally this is similar to what you are probably more familiar with:

```bash
mkdir bld
cd bld
CXX=g++ cmake -GNinja /path/to/source_dir
ninja
```


I encourage making the first way your default. Here is the reason:
In the second way, when you need to start over, or build with a different
compiler, people typically type "rm -rf \*" and start over with the cmake
step. If you do everything correctly, nothing bad happens. But we all
get tired, and eventually one day our fingers will press Ctrl+r r and
hit return before the brain filters the command for safety. Even if we
then recover and press Ctrl+C until the rm command is killed, we might
lose some data. The recommended way above develops habits which are
safe by default, since the cleanup command in your history will be
"rm -rf bld" rather than "rm -rf \*".



