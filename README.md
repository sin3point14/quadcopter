## OpenGL renderer

To build:

```
mkdir build
cd build
cmake ..
```

To build with a specific build system, pass the generator name as
``` 
cmake .. -G <generator>
```

Find generators at https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#introduction

### Visual Studio

VS 2022:
```cmake .. -G "Visual Studio 17 2022"```
VS 2019:
```cmake .. -G "Visual Studio 16 2019"```
VS 2017:
```cmake .. -G "Visual Studio 15 2017"```

The open the solution file `build/quadcopter.sln`. And set `quadcopter` as startup project in the Solution Explorer

![Solution Explorer](https://imgur.com/ClYlSij)

### Ninja

```
cmake .. -G Ninja`
ninja
./src/Quadcopter
```
