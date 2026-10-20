for m in Point Circle Polygon Triangle; do
echo "Generating CMI and object files for $m"
g++ -std=c++23 -fmodules -xc++ -c $m.ixx
done
echo "Compiling main.cc -> a.gcc"
g++ -std=c++23 -fmodules -static -o a.gcc main.cc Point.o Circle.o Polygon.o Triangle.o



