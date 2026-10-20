echo "Generating CMI for Point"
clang++ -std=c++23 -stdlib=libc++ -fmodules --precompile -xc++-module Point.ixx
clang++ -std=c++23 -stdlib=libc++ -fmodules -c -xc++ -fmodule-file=Point=Point.pcm Point.ixx

echo "Generating CMI for Circle"
clang++ -std=c++23 -stdlib=libc++ -fmodules --precompile -xc++-module -fmodule-file=Point=Point.pcm Circle.ixx
clang++ -std=c++23 -stdlib=libc++ -fmodules -c -xc++ -fmodule-file=Point=Point.pcm -fmodule-file=Circle=Circle.pcm Circle.ixx

echo "Generating CMI for Polygon"
clang++ -std=c++23 -stdlib=libc++ -fmodules --precompile -xc++-module -fmodule-file=Point=Point.pcm Polygon.ixx
clang++ -std=c++23 -stdlib=libc++ -fmodules -c -xc++ -fmodule-file=Point=Point.pcm -fmodule-file=Polygon=Polygon.pcm Polygon.ixx

echo "Generating CMI for Triangle"
clang++ -std=c++23 -stdlib=libc++ -fmodules --precompile -xc++-module -fmodule-file=Point=Point.pcm -fmodule-file=Polygon=Polygon.pcm Triangle.ixx
clang++ -std=c++23 -stdlib=libc++ -fmodules -c -xc++ -fmodule-file=Point=Point.pcm -fmodule-file=Polygon=Polygon.pcm -fmodule-file=Triangle=Triangle.pcm Triangle.ixx

echo "Compiling main.cc -> a.clg"
clang++ -std=c++23 -stdlib=libc++ -fmodules -fmodule-file=Point=Point.pcm -fmodule-file=Circle=Circle.pcm -fmodule-file=Polygon=Polygon.pcm -fmodule-file=Triangle=Triangle.pcm -o a.clg main.cc Point.o Circle.o Polygon.o Triangle.o



