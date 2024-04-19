# KATA DRIVER-LED
## Prerequisites
```bash
$ sudo apt install cmake 
```
## Build and run test suite
```bash
$ cmake -GNinja -B build
$ cmake --build build
$ ctest -V --test-dir build
```