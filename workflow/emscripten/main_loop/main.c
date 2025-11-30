#include "emscripten.h"
#include <stdio.h>

static int data = 0;
static int counter = 0;

static inline void main_loop() {
  data += 1;

  if ((data % 60) == 0) {
    counter += 1;
    printf("counted=%d\n", counter);
  }
}

int main() {
#ifdef __EMSCRIPTEN__
  printf("running with emscripten\n");
  emscripten_set_main_loop(main_loop, 0, true);
#else
  while (1) {
    main_loop();
  }
#endif
}