# Physics2D
C++ single header 2D physics engine implementation. Simple to use and ideal for rendering, games, and other experimentation.

Usage...

 During setup:
```		
  p2d::Physics physics;
  p2d::CircleBody circleBody(radius, x, y, mass, restitution);
  physics.add(&circleBody);
```  

 On every frame:
```		
  physics.update(dt);

```

P2D can be used with any renderer of your choice, however the included demos require [SFML](https://www.sfml-dev.org/) for graphics and sound. To run, simply create an instance of chosen demo as follows:

```
Planets planets;
```




![planets](img/planets.gif)

```
Snooker snooker;
```

![Snooker](img/snooker.gif)

```
Playground playground;
```

![Snooker](img/playground.gif)

## Build
#### Linux

Install CMake, e.g. for Debian/Ubuntu:
```
sudo apt-get install build-essential libssl-dev
sudo apt-get install cmake
```
Install SFML:
```
sudo apt-get install libsfml-dev
```

Clone repo and make a new directory called ```build``` inside the ```src```
directory and enter it.
```
cd {DOWNLOAD_LOCATION}/physics-2d/src
mkdir build
cd build
```
run CMake
```
cmake ../
```

run make
```
make
```
Start the game:
```
./Physics
```
#### Windows
Install [CMake](https://cmake.org/), use CMake GUI or command line to generate
Visual Studio .sln file, then build with VS.
