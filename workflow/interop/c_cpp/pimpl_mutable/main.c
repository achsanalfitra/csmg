#include "shared_object.h"

int main() {
  const char *name = "hello world object";
  SharedObject *my_object = instantiate_shared_object(name);

  inspect_name(my_object); // print "hello world object"
  inspect_size(my_object); // print its size

  trigger_mutator(my_object); // change its name
  inspect_name(my_object);    // print "name was changed"

  destroy_shared_object(my_object); // destroy

  return 0;
}