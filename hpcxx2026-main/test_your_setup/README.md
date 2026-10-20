# Compile:

## hello.cc
```bash
g++ -std=c++23 hello.cc
```
or with clang...
```bash
clang++ -std=c++23 -stdlib=libc++ hello.cc
```

Using classroom shortcuts `G` and `C` the above can be
written like this:

```bash
G hello.cc
C hello.cc
```

`G` is an alias for `g++ -std=c++23 -O3 -pedantic -Wall`.
`C` is an alias for `clang++ -std=c++23 -stdlib=libc++ -O3 -pedantic -Wall`

## test_import_std.cc

With gcc (> 16.0):

```bash
g++ -std=c++23 -fmodules -c --compile-std-module
g++ -std=c++23 -fmodules test_import_std.cc
```

Using our shortcuts,


```bash
Gstdm
Gm test_import_std.cc
```

where the shortcut Gstdm means "g++ -O3 -std=c++23 -fmodules -c --compile-std-module"
and the shortcut Gm means "g++ -O3 -std=c++23 -fmodules "

We can do something similar with clang, but we have to first locate where the standard library
module file is:

```bash
export libcxx_module_src_dir=$(dirname $(find $(dirname $(which clang) )/.. -name std.cppm)  2>/dev/null)
```

Check that it worked:


```bash
echo $libcxx_module_src_dir
```

Check that it prints an existing path containing files like std.cppm, std.compat.cppm. Now, we can
do something to mimic the GCC oneliner above to build the standard library module.

```bash
clang++ -std=c++23 -stdlib=libc++ -O3 -fprebuilt-module-path=. \
    -Wno-reserved-module-identifier --precompile  \
    $libcxx_module_src_dir/std.cppm $libcxx_module_src_dir/std.compat.cppm
```

Now, we can build the program using:

```bash
clang++ -std=c++23 -stdlib=libc++ -O3 -fprebuilt-module-path=. test_import_std.cc
```

Using the aliases defined for you ($PROJECT/local/setup.sh in the classroom or through
code/bash/aliases.sh in the course material), you can shorten it:

```bash
Cstdm
Cm test_import_std.cc
```

If you have reached this point, and want to learn more about building
projects using C++ modules using CMake as the build system generator,
install the course_utils library for yourself using instructions in the
folder course_utils, and then do the examples inside
test_your_setup/use_course_utils. The README files in each folder will
guide you through the steps. Any unresolved issues can be resolved in
the class.

