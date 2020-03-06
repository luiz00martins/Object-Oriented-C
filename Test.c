
#define TRUE 1
#define FALSE 0

//---String definitions-START
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <signal.h>
#include "OOCLib.h"
#include "Example.h"

int main() {
    void* myArray = new(ArrayQueue(), Int());

    for(int i = 0; i < 8; i++){
        push(myArray, wrap(i));
    }
    for(int i = 0; i < 5; i++){
        delete(pop(myArray));
    }
    for(int i = 8; i < 10; i++){
        push(myArray, wrap(i));
    }
    resize(myArray, -1);

    delete(myArray);

    return 0;
}
