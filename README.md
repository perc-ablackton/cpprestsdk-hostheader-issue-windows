# cpprestsdk Windows Certificate Validation with Host Header

Tested against cpprestsdk v2.10.16-3 on Windows.

This project creates a reproducible to show that when a `Host` header is set on windows with the port specified, you will get the following error:
```
Incorrect common name: 2148204815: The certificate's CN name does not match the passed value.
```

Relevent cpprestsdk code:

1. https://github.com/microsoft/cpprestsdk/blob/v2.10.16/Release/src/http/client/http_client_winhttp.cpp#L1107-L1113

2. https://github.com/microsoft/cpprestsdk/blob/v2.10.16/Release/src/http/client/http_client_winhttp.cpp#L555

3. https://github.com/microsoft/cpprestsdk/blob/v2.10.16/Release/src/http/client/http_client_winhttp.cpp#L632-L656


## Project Setup

`vcpkg` is used to download and install the cpprest sdk.
Please feel free to specify a different `CMAKE_TOOLCHAIN_FILE` that will be appropriate for your environment.

```
..\vcpkg\vcpkg.exe install cpprestsdk:x64-windows

cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:\dev\repos\github\vcpkg\scripts\buildsystems\vcpkg.cmake

cmake --build build --config Release

build\src\Release\cpprest-request.exe
```
