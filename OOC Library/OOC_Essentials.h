#ifndef OOC_ESSENTIALS_H
#define OOC_ESSENTIALS_H

#include <stddef.h>
#include <stdbool.h>

#define OOC_CLASS_KEY 178412742748171354

typedef void* pointer;
typedef pointer (*method)(pointer self, va_list* args);
typedef unsigned long method_hash;
// In the way that the system works, class is actually a function that returns
// a struct Class* pointer
typedef pointer (*class)();

struct OOC_Class {
    //const struct Class* object;
    struct OOC_Class* super;
    char* name;
    // The size of the class
    size_t size;
    // If the class is abstract or not
    bool abstract;
    // Pointers to the functions used to call the methods
    method_hash* methodKeys;
    // Pointers to the methods (should be aligned with the callers list)
    method* methods;
	int methodListLen;
    long long key;
};

struct Object {
    struct OOC_Class* class;
};

#endif