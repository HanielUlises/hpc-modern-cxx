alias cf="clang-format --style=WebKit -i"
alias G="g++ -std=c++23 -pedantic -Wall -O3"
alias Gstdm="g++ -std=c++23 -fmodules -pedantic -Wall -O3 -c --compile-std-module"
alias Gm="g++ -std=c++23 -fmodules -pedantic -Wall -O3"

export libcxx_module_src_dir="$(dirname $(find $(dirname $(which clang) )/.. -name std.cppm) 2>/dev/null)"
alias C="clang++ -std=c++23 -stdlib=libc++ -O3 -pedantic -Wall"
alias Cstdm="clang++ -std=c++23 -stdlib=libc++ -O3 -Wno-reserved-module-identifier -fprebuilt-module-path=. --precompile $libcxx_module_src_dir/std.cppm $libcxx_module_src_dir/std.compat.cppm"
alias Cm="clang++ -std=c++23 -stdlib=libc++ -O3 -fprebuilt-module-path=. "

