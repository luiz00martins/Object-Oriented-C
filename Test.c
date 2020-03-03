
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
    void* shit = new(LinkedList());
    set(shit, 0, (void*)NULL);
    void* ptr = new(String(), "this is short.");
    void* str = new(String(), "this is short");

    bool derp = interpretAs(bool, compare(ptr, str));
    printf(derp ? "True" : "False");

    delete(ptr);
    delete(str);

    return 0;
}
