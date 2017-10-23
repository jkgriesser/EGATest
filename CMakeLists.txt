cmake_minimum_required(VERSION 3.6)
project(EGA)

# configure the SDL (cf. "SDL2-2.0.3\i686-w64-mingw32\lib\pkgconfig\sdl2.pc")
# C++ flags
set(SDL2_Flags "-mwindows -Wl,--no-undefined -static-libgcc")
# library paths
set(SDL2_ROOT     "C:/SDL2/i686-w64-mingw32")
set(SDL2_Includes "${SDL2_ROOT}/include")
set(SDL2_LibDir   "${SDL2_ROOT}/lib")
# imported targets for CMake (cf. https://cmake.org/Wiki/CMake/Tutorials/Exporting_and_Importing_Targets)
add_library(SDL2     STATIC IMPORTED)
add_library(SDL2main STATIC IMPORTED)
set_property(TARGET SDL2     PROPERTY IMPORTED_LOCATION "${SDL2_LibDir}/libSDL2.a")
set_property(TARGET SDL2main PROPERTY IMPORTED_LOCATION "${SDL2_LibDir}/libSDL2main.a")
# the libs to link against
# note: as always with gcc, the order is important...
set(SDL2_Libs mingw32 SDL2 SDL2main m dinput8 dxguid dxerr8 user32 gdi32 winmm imm32 ole32 oleaut32 shell32 version uuid)

# configure the project
# include the SDL flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${SDL2_Flags}")
# collect the sources
set(SOURCE_FILES main.cpp DrawPixel.cpp DrawPixel.h)
# define the target
add_executable(EGA ${SOURCE_FILES})
# include the SDL headers
target_include_directories(EGA SYSTEM PRIVATE ${SDL2_Includes})
# link against the SDL (and its dependencies)
target_link_libraries(EGA ${SDL2_Libs})