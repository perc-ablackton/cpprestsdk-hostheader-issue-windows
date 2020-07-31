@echo off

..\vcpkg\vcpkg.exe install cpprestsdk:x64-windows
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:\dev\repos\github\vcpkg\scripts\buildsystems\vcpkg.cmake
cmake --build build --config Release
build\src\Release\cpprest-request.exe

