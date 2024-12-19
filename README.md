# Fluid Simulation with SDL2

This project implements a real-time interactive fluid simulation using C++ and SDL2. The system uses a particle-based model with simplified physics to create realistic fluid behavior, optimized with parallel processing and efficient data structures.

## Key Features

- Particle-based fluid simulation
- Real-time mouse interaction
- Optimized SDL2 rendering
- Parallel processing for better performance
- Efficient collision system using spatial grid
- Simplified physics for realistic behavior

## Project Structure

```
fluid-simulation/
├── src/                    # Main source code
│   ├── main.cpp           # Program entry point
│   ├── fluid/             # Fluid simulation system
│   │   ├── fluid.cpp      # Main fluid implementation
│   │   ├── fluid.hpp      # Fluid class definition
│   │   ├── particle.cpp   # Particles implementation
│   │   └── particle.hpp   # Particle class definition
│   ├── renderer/          # Rendering system
│   │   ├── renderer.cpp   # SDL2 renderer implementation
│   │   └── renderer.hpp   # Renderer interface
│   └── utils/             # Utilities
│       ├── vector.cpp     # 2D vector implementation
│       └── vector.hpp     # Mathematical definitions
├── include/               # External headers
│   └── SDL2              # SDL2 header files
├── lib/                  # External libraries
├── CMakeLists.txt        # Build system configuration
└── README.md             # This documentation
```

## System Requirements

- C++17 or higher
- SDL2 (>= 2.0.0)
- CMake (>= 3.10)
- C++17 compliant compiler (gcc, clang, MSVC)
- Operating System: Windows, Linux, or macOS

## Build Instructions

1. **Install dependencies:**
   ```bash
   # Windows (using MSYS2)
   pacman -S mingw-w64-x86_64-SDL2
   pacman -S mingw-w64-x86_64-cmake
   ```

2. **Configure project:**
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. **Build:**
   ```bash
   cmake --build .
   ```

4. **Run:**
   ```bash
   ./fluid_simulation
   ```

## Contributing

1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Open a Pull Request

## License

This project is licensed under the MIT License. See the LICENSE file for details.
