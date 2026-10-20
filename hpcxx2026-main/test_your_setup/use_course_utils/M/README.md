# Building example projects depending on the course utils modules

This directory contains a simple example program using
some features implemented in the library course_utils.
Only the #include lines of the corresponding source file
in the headers version of this program have been changed
to "import" lines. Nothing else changes in the source file
which _uses_ modules. The build part is a bit more complex.

Unlike the header inclusion mechanism, modules do not have
a copy-and-paste style trivial mechanism. The modules we
import must already exist. The compiler must be told how
the names of the modules we define in C++ source files relate
to the names of the binary files on the file system. Since
it's not a simple text insertion process, the mapping need
not be (and often isn't) trivial. This can be done by adding
a large number of compiler specific options which will change
depending on the dependency structure of the source file.
But such work is best left to a build system generator
such as CMake. Here, I will only show the process using
CMake.

### Short version for the impatient

```bash
export CMAKE_IMPORT_STD_MODULE_DIR=$cxx2026/local/share/cmake
CXX=g++ cmake -B bld -GNinja -S .
cmake --build bld
./bld/main
```

To understand what's going on, read on!

### Note on enabling the "import std;" feature with CMake

When we use "import std;" to import the standard library, the
standard library has to be built once with the project specific
compilation options. C++ binary module interface units should be
treated as build time cache files, and offer no compatibility
guarantees between very similar builds differing by seemingly
minor compiler options. In a project managed by CMake, CMake
should be instructed to create a compatible binary interface unit
for the standard library, using project compiler options. This
is enabled by setting CMAKE_CXX_MODULE_STD=1. As of CMake version
4.4, the process used by CMake to analyze dependencies and
generating compiler commands are still changing substantially.
It is therefore treated as an experimental opt-in feature.
We opt in, by setting an experimental import std GUID string.
Something like this:

```bash
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
```

The trouble is, the exact GUID string used above depends on the
CMake version. One can handle it in a if-then-else chain inside
the CMakeLists.txt file, handling different CMake versions. We
hide all that inside a CMake module file called EnableCxxImportStd.cmake,
distributed with the course material. In the CMakeLists.txt file
of the current project, we just include that, but using its full
path, i.e.,

```cmake
include($ENV{CMAKE_IMPORT_STD_MODULE_DIR}/EnableCxxImportStd.cmake)
```

The only thing remaining is to set the environment variable
CMAKE_IMPORT_STD_MODULE_DIR, so that CMake can find the file.
If you installed the course_utils library, following the instructions
in the README file in that directory, this should be the right
path to set:

```bash
export CMAKE_IMPORT_STD_MODULE_DIR=$cxx2026/local/share/cmake
```

Now you can move to "Build steps with CMake" to compile. Here I
will note a few things you will need to do in the future if the
examples stop building in the future.

The experimental procedure in CMake may stop working some time in the
future when your CMake version updates beyond 4.4. When that happens,
find EnableCxxImportStd.cmake in the material and add another
if-then-else block, with the GUID appropriate for the newer
CMake version. By autumn 2026, using an LLM like Grok, Gemini or
CharGPT is probably the quickest way to get to the updated GUID
string. And of course, one day, the feature will no longer be
experimental in CMake, and the whole EXPERIMENTAL_CXX_IMPORT_STD
stuff can be dropped. When that CMake version arrives, set
the GUID to an empty string for that and all future versions.


## Build steps with CMake

The steps to build with CMake are identical to what you
used in the header file version. The differences are in
the two versions of the file CMakeLists.txt.

The course_utils needs
to be installed somewhere for this to work. Let's assume
that you installed course_utils under the folder
$cxx2026/local (Remember: the environment variable cxx2026
is your personal workspace for course related work). You
can now perform the following steps to build the executable.

```bash
CXX=g++ cmake -B bld -GNinja -S /path/to/source_dir
```

This creates a directory called "bld" and and configures the project
inside it. If you wish to use Clang+standard library modules,
you have to tell CMake to always use -stdlib=libc++ option with
Clang. 

```bash
CXX=clang++ cmake -DCMAKE_CXX_FLAGS="-stdlib=libc++" -B bld -GNinja -S /path/to/source_dir
```

Then:

```bash
cmake --build bld
```

The compiles the project inside it using the compiler you provided
in the configure step.

