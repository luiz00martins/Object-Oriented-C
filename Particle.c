
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Particle.h"
#include "Particle.r"
#include "OOC Library/Wrappers/LongDouble.h"
#include "OOC Library/Wrappers/LongDouble.r"


/** START Getters and Setters **/
object_build_getset(position, momentum)
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(Particle,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (print, ()),
            (printBound, (int, bound)),
            (scan, ()))


/** END Caller functions **/


/** START Class method definitions **/
build_class_ctor(Particle,
                 ((struct LongDouble**, position), (struct LongDouble**, momentum)),
                 ((print, ()),
                  (printBound, (int, bound)),
                  (scan, ())))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* Particle_ctor(void* self, va_list* args){
    cast(Particle(), self);
    // Calling super constructor
    struct Particle* particle = super_ctor(Particle(), self, args);

    // Note: The conversions are happening because of the implicit compiler promotions
    long double ld = 0;
    for(int i = 0; i < 3; i++){
        particle->position[i] = wrap(ld);
        particle->momentum[i] = wrap(ld);
    }

    return self;
}
void* Particle_dtor(void* self){
    cast(Particle(), self);
    // Calling super destructor
    struct Particle* particle = super_dtor(Particle(), self);

    for(int i = 0; i < 3; i++){
        delete(particle->position[i]);
        delete(particle->momentum[i]);
    }

    return self;
}

/* Public: */
void* Particle_print(void* self){
    struct Particle* particle = cast(Particle(), self);

    printf("\nPosition: (");
    print(particle->position[0]);
    printf(", ");
    print(particle->position[1]);
    printf(", ");
    print(particle->position[2]);
    printf(")\nMomentum: (");
    print(particle->momentum[0]);
    printf(", ");
    print(particle->momentum[1]);
    printf(", ");
    print(particle->momentum[2]);
    printf(")");

    return NULL;
}
void* Particle_printBound(void* self, int bound){
    struct Particle* particle = cast(Particle(), self);

    for(int i = 0; i < 3; i++){
        printf("p%i:", i);
        printBound(particle->position[i], bound - 3);
        printf("|\n|");
    }
    for(int i = 0; i < 3; i++){
        printf("v%i:", i);
        printBound(particle->momentum[i], bound - 3);
        if (i != 2)
            printf("|\n|");
    }

    return NULL;
}
void* Particle_scan(void* self){
    struct Particle* particle = cast(Particle(), self);

    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("Position %i [LongDouble]:", i);
        scan(particle->position[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("Momentum %i [LongDouble]:", i);
        scan(particle->momentum[i]);
    }

    return NULL;
}
void* Particle_equals(void* self, void* obj){
    struct Particle* particle = cast(Particle(), self);
    struct Particle* particle2 = cast(Particle(), obj);

    bool returned = false;

    for(int i = 0; i < 3; i++){
        if(!as(bool, equals(particle->position[i], particle2->position[i]))
            || !as(bool, equals(particle->momentum[i], particle2->momentum[i])))
            return returning(returned);
    }

    returned = true;
    return returning(returned);
}
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _ParticleClass;

const void* const ParticleClass(){
    return _ParticleClass ? _ParticleClass :
           (_ParticleClass = new(Class(), "ParticleClass", Class(), sizeof(struct ParticleClass),
                               _ctor, ParticleClass_ctor,
                               NULL));
}

static const void* _Particle;

//TODO: Add impossibility of overload

const void* const Particle(){
    return _Particle ? _Particle :
           (_Particle = new(ParticleClass(), "Particle", Object(), sizeof(struct Particle),
                          _ctor, Particle_ctor,
                          _dtor, Particle_dtor,
                          _equals, Particle_equals,
                          _print, Particle_print,
                          _printBound, Particle_printBound,
                          _scan, Particle_scan,
                          NULL));
}
/* END Dynamic initializer */
