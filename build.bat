rmdir /S /q build
mkdir build
cd build
cmake ../
cmake --build .

rmdir /S /q delivery
mkdir delivery
mkdir delivery\include
mkdir delivery\source
mkdir delivery\libs

copy include\* delivery\include
copy source\* delivery\source
copy build\Debug\* delivery\libs
