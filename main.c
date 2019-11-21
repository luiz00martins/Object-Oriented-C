#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "Example.h"

typedef int* int_ptr;

typedef void (* voidf) ();

struct Test {
    int* i_ptr;
    float f;
    char c;

    void* (*ctor)(void* self, va_list* args);
    void* (*dtor)(void* self);
    bool (*is_class)(const void* self, const struct Class* class);
    bool (*of_class)(const void* self, const struct Class* class);
};

struct TestExtend {
    struct Test test;
};

int main() {
    /*void* testExtend = malloc(sizeof(struct TestExtend));
    ((struct Test*)testExtend)->i_ptr = malloc(sizeof(int));

    *((struct Test*)testExtend)->i_ptr = 10;

    int** i = testExtend;

    **i = 20;

    printf("%p %p %p %i", testExtend, &((struct Test*)testExtend)->i_ptr, ((struct Test*)testExtend)->i_ptr, *((struct Test*)testExtend)->i_ptr);
*/
    initExample();

    struct Example* example = new(Example, 10, 20.0, 'a', 30, 40.0, 'b');

    print(example);
    printf("\n");

    printf("%f\n", get_pF(example));

    delete(example);

    return 0;
}
