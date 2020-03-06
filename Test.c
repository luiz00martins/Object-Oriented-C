
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
    void* myArray = new(LinkedStack(), String());

    void* myString = new(String(), "derp");

    push(myArray, myString);

    delete(myString);

    return 0;
}
