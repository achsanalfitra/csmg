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
6. Run the executable (this depends on the compiler used)

### Steps: CMake with Clang tooling

If you're using Visual Studio Code, clangd cannot resolve the nested dependencies without compile_commands.json file. To generate that file, you have to:

1. Install Ninja
2. Add Ninja to PATH

Then, do the steps to generate the build system

1. Create the libary files, look up (custom_lib.c/h)
2. Write the entry point
3. Create the CMakeLists.txt
4. Run the configuration command
    ```bash
        cd /path/to/this/example

        mkdir build

        cd build

        cmake -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..    # The command difference is here.
                                                                # Ensure you have GCC or Clang isntalled
                                                                # If you try to run DCMAKE_EXPORT_COMPILE_COMMANDS=ON while using MSVC, it won't generate compile_commmands.json

    ```
5. Run the build comand
    ```bash
        # simple

        cmake --build .
    ```
6. Run the executable (this depends on the compiler used)