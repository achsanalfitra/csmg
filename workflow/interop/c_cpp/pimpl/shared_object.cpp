#include "shared_object.h"
#include <iostream>
#include <string>

class SharedObjectImplementation {
  // This is the concrete implementation of the incomplete object SharedObject
  // The C caller only knows that there is an object called SharedObject returned by the C++ instantiator function
public:
  SharedObjectImplementation(std::string name)
      : _name(std::move(name)), _size(sizeof(*this)) {};
  std::string access_name() { return this->_name; }
  size_t access_size() { return this->_size; }

private:
  std::string _name;
  size_t _size;
};

void _print_nonexistent_object() {
  std::cout << "object doesn't exist" << std::endl;
}

SharedObject *instantiate_shared_object(const char *name) {
  if (name == nullptr) {
    return nullptr;
  }

  SharedObjectImplementation *impl = new SharedObjectImplementation(name);

  // In the instantiate function, we return a reinterpret_cast of Shared Object, making C understands the object
  return reinterpret_cast<SharedObject *>(impl);
}

void inspect_name(SharedObject *object) {
  if (object == nullptr) {
    _print_nonexistent_object();
    return;
  }

  // when we access the object from C, we need to upcast it back to the implementation to access
  // it as the c++ class of the same object
  SharedObjectImplementation *impl =
      reinterpret_cast<SharedObjectImplementation *>(object);

  std::cout << "Object name: " << impl->access_name() << std::endl;
}

void inspect_size(SharedObject *object) {
  if (object == nullptr) {
    _print_nonexistent_object();
    return;
  }

  SharedObjectImplementation *impl =
      reinterpret_cast<SharedObjectImplementation *>(object);

  std::cout << "Object size: " << impl->access_size() << std::endl;
}

void destroy_shared_object(SharedObject *object) {
  if (object == nullptr) {
    _print_nonexistent_object();
    return;
  }

  SharedObjectImplementation *impl =
      reinterpret_cast<SharedObjectImplementation *>(object);

  delete impl;

  std::cout << "Deleted SharedObject object" << std::endl;
}