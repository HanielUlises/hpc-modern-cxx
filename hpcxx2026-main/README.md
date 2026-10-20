# High-performance scientific computing in C++ 2026

Course material for the course
"High-performance scientific computing in C++",
12 -- 15 October 2026 organized by the Jülich Supercomputing Centre,
Forschungszentrum Jülich, Germany.

# hpcxx2026

You will need to pull from this repository periodically during this course.

If your computer does not have "git", you will need to use the download
button to the left of the "Clone" button in the gitlab page.

## Recommended way of working with this material

The downloaded or cloned material from this repository will be updated
during the course days. You should keep one copy of the examples and
exercises in the pristine form, and work on your own duplicates.
For example, to work on the day1 examples, do as follows:

```bash
    cd day1
    cp -r examples mine
    cd mine
    clang++ -std=c++23 math_functions.cc
    ./a.out
```

Only examples (which includes some exercises) and solutions need to
be duplicated. You don't need two copies of the entire material as that
includes the PDFs of the course slides and other utillities.


## Testing your set up

To work with this material, you will need to have a fairly up-to-date
C++ compiler. GCC version 16.2 or Clang version 22.1 or later are
recommended. The README file in the directory test_your_setup explains
the steps in more detail.

# The library course_utils and using aliases to save some typing

As the examples in the directory test_your_setup show, we will often need
to type a lot of options to compile our programs during this course,
since we want to use C++23, which is not the default
standard for the compilers yet. A few convenient aliases
have been prepared which you can use to shorten the
above compilation steps. To use them, do as follows:

```bash
source course_material_dir/course_utils/bash/aliases.sh
```

Once you have done that, you can shorten the above 
steps to the following: 

```bash 
G hello.cc 
C hello.cc 
```

Using modules and GCC

```bash
Gstdm
Gm hello_m.cc 
```
Using modules and Clang

```bash
Cstdm
Cm hello_m.cc
```

The directory course_utils contains a few pieces of code used across
many examples throughout the course. These have been recently changed
into a library whose components can be used as C++ header files, or
as an imported module. Build and use instructions are in the README file of
of the course_utils directory.

# Important environment variables used in course material

In many slides, it is assumed that there is an environment variable
called cxx2026 set for the user, which points to a folder where you
are doing your course exercises. You will be installing parts of the
code you see in the course in that directory. When doing the exercises
in the online course room, you always start every new terminal window
by first running "source $PROJECT/local/setup.sh". This script sets up
your compiler, library paths, but also sets up some environment variables
(including cxx2026) for you. During the course, you should perform all
your material download, edits and runs with $cxx2026 as the root folder.
If you are trying to do the same on another system, or after the course
has concluded, you need to setup cxx2026 to point to a suitable folder,
or modify the commands appearing on the slides sensibly.

Remember, in the course room system, after you have run the setup.sh script
(source $PROJECT/local/setup.sh), the environment variable cxx2026 is
similar to the HOME environment variable on Linux systems. It is defined
individually for each user, and you should have no problems experimenting
with your code there.

