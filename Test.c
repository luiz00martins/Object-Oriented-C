
#define TRUE 1
#define FALSE 0

//---String definitions-START
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "OOCLib.h"
#include "Example.h"

#define BOX_BOUND 20
#define NUMBER_OJBS 15


int main() {
    struct ArrayQueue* arrayQueue = new(ArrayQueue(), Long);
    long r;
    for(int i = 0; i < NUMBER_OJBS; i++){
        r = rand();
        push(arrayQueue, wrap(r));
    }
    for(int i = 0; i < 10; i++){
        pop(arrayQueue);
    }
    for(int i = 0; i < 5; i++){
        r = rand();
        push(arrayQueue, wrap(r));
    }

    print(arrayQueue, BOX_BOUND);


    return 0;
}
