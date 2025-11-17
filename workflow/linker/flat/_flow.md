### Steps: CMake

1. Create the libary files, look up (custom_lib.c/h)
2. Write the entry point
3. Create the CMakeLists.txt
4. Run the configuration command
    ```bash
        cd /path/to/this/example

        mkdir build

        cd build

        cmake ..

    ```
5. Run the build comand
    ```bash
        # simple

        cmake --build .
    ```
6. Run the .exe (this depends on the compiler used)