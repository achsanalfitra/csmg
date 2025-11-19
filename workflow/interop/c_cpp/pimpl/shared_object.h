#ifndef SHARED_OBJECT_H
#define SHARED_OBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SharedObject SharedObject;

SharedObject* instantiate_shared_object(const char* name);
void inspect_size(SharedObject*);
void inspect_name(SharedObject*);
void destroy_shared_object(SharedObject*);

#ifdef __cplusplus
}
#endif


#endif