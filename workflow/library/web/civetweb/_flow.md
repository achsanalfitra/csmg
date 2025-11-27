### Steps: Building the library

1. Download the civetweb repository
2. Build the civetweb.c into a library. In this workflow, we create a ./lib folder to store the stable lib file
3. Ensure you have OpenSSL libraries, especially the SSL and Crypto. The lib also isn't likely to be built if your OS or environment doesn't guarantee it has pthreads built in libraries
4. Follow the specifications in build_script file(s) and CMakeLists.txt inside /lib where you need to specifically link the libs. You need to explicitly state the paths of those libs if your environment doesn't play nicely.
5. Run the build scripts then build the library.
6. The built library is available with the name libcivetweb.a inside the build folder. Note: the location may vary depending on the compiler type.

### Steps: Running your first function

Note: the example is yet to be written since the current implementation works for embedded example of the civetweb repository

1. Link the library which was built from the previous stage
2. Follow the specifications inside the build_script and CMakeLists.txt to know what paths and flags are necessary
3. You can try to make a "main.c" then compile it using the build scripts specified in this workflow