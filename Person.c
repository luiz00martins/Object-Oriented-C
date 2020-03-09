
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Person.h"
#include "Person.r"
#include "OOC Library/Utilities/String.h"
#include "OOC Library/Utilities/String.r"
#include "OOC Library/Wrappers/Int.h"
#include "OOC Library/Wrappers/Int.r"
#include "OOC Library/Wrappers/Double.h"
#include "OOC Library/Wrappers/Double.r"


/** START Getters and Setters **/
object_build_getset(name, age, height)
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(Person,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (print, ()),
            (printBound, (int, bound)),
            (scan, ()))


/** END Caller functions **/


/** START Class method definitions **/
build_class_ctor(Person,
                 ((struct String*, name), (struct Int*, age), (struct Double*, height)),
                 ((print, ()),
                  (printBound, (int, bound)),
                  (scan, ())))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* Person_ctor(void* self, va_list* args){
    cast(Person(), self);
    // Calling super constructor
    struct Person* person = super_ctor(Person(), self, args);

    // Note: The conversions are happening because of the implicit compiler promotions
    person->name = new(String(), "");
    person->age = new(Int(), NULL, NULL);
    person->height = new(Double(), NULL, NULL);

    return self;
}
void* Person_dtor(void* self){
    cast(Person(), self);
    // Calling super destructor
    struct Person* person = super_dtor(Person(), self);

    delete(person->name);
    delete(person->age);
    delete(person->height);

    return self;
}

/* Public: */
void* Person_print(void* self){
    struct Person* person = cast(Person(), self);

    printf("\nName: ");
    print(person->name);
    printf("\nAge: ");
    print(person->age);
    printf("\nHeight: ");
    print(person->height);

    return NULL;
}
void* Person_printBound(void* self, int bound){
    struct Person* person = cast(Person(), self);

    printBound(person->name, bound);
    printf("|\n|");
    printBound(person->age, bound);
    printf("|\n|");
    printBound(person->height, bound);

    return NULL;
}
void* Person_scan(void* self){
    struct Person* person = cast(Person(), self);

    printf("\nName [String]: ");
    scan(person->name);
    printf("Age [Int]: ");
    scan(person->age);
    printf("Height [Double]: ");
    scan(person->height);

    return NULL;
}
void* Person_equals(void* self, void* obj){
    struct Person* person = cast(Person(), self);
    struct Person* person2 = cast(Person(), obj);

    bool returned = true;

    if(as(bool, equals(person->name, person2->name))
        && as(bool, equals(person->age, person2->age))
        && as(bool, equals(person->height, person2->height)))
        return returning(returned);

    returned = false;
    return returning(returned);
}
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _PersonClass;

const void* const PersonClass(){
    return _PersonClass ? _PersonClass :
           (_PersonClass = new(Class(), "PersonClass", Class(), sizeof(struct PersonClass),
                                _ctor, PersonClass_ctor,
                                NULL));
}

static const void* _Person;

//TODO: Add impossibility of overload

const void* const Person(){
    return _Person ? _Person :
           (_Person = new(PersonClass(), "Person", Object(), sizeof(struct Person),
                           _ctor, Person_ctor,
                           _dtor, Person_dtor,
                           _equals, Person_equals,
                           _print, Person_print,
                           _printBound, Person_printBound,
                           _scan, Person_scan,
                           NULL));
}
/* END Dynamic initializer */
