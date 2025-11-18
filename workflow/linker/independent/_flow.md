### Steps: CMake

1. Create the libary files, look up (custom_lib.c/h)
2. Write the entry point
3. Create the CMakeLists.txt
4. Run the build_script file (currently only .bat, feel free to extend)
    4.a Use "simple" version cmake command to simply inject the variable
    4.b Use "export compile command" version cmake command to use Ninja for compile_commands.json export (clang tooling support)
5. Run the cmake build command
    ```bash
        # cd build if you haven't
        cmake --build .

    ```

6. Run the executable