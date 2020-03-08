
#define TRUE 1
#define FALSE 0

//---String definitions-START
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "OOCLib.h"
#include "Example.h"

int boxBound = 20;
void* structureType;
char structureStyle[1000];
void* storedType;
void* dataStructure;

void* dummyValue;
#define NUMBER_OJBS 15

void clearScreen(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #endif
}
void printTitle(){
    printf("██████╗  █████╗ ████████╗ █████╗     ███████╗████████╗██████╗ ██╗   ██╗ ██████╗████████╗██╗   ██╗██████╗ ███████╗███████╗\n"
           "██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔════╝╚══██╔══╝██║   ██║██╔══██╗██╔════╝██╔════╝\n"
           "██║  ██║███████║   ██║   ███████║    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║   ██║██████╔╝█████╗  ███████╗\n"
           "██║  ██║██╔══██║   ██║   ██╔══██║    ╚════██║   ██║   ██╔══██╗██║   ██║██║        ██║   ██║   ██║██╔══██╗██╔══╝  ╚════██║\n"
           "██████╔╝██║  ██║   ██║   ██║  ██║    ███████║   ██║   ██║  ██║╚██████╔╝╚██████╗   ██║   ╚██████╔╝██║  ██║███████╗███████║\n"
           "╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝\n\n\n");
}

void pressEnter(){
    printf("Press enter to continue");
    char c;
    scanf("%c", &c);
}

int getSel(){
    int selection;
    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    return strtol(arr, NULL, 10);
}

char format_Short[] = "%i";
char format_Int[] = "%i";
char format_Long[] = "%li";
char format_LongLong[] = "%lli";
char format_Float[] = "%f";
char format_Double[] = "%lf";
char format_LongDouble[] = "%Lf";
char format_Char[] = "%c";
char format_String[] = "%[^\n]";
char* getCorrectFormat(){
    if (storedType == Short()) {
        return format_Short;
    } else if (storedType == Int()) {
        return format_Int;
    } else if (storedType == Long()) {
        return format_Long;
    } else if (storedType == LongLong()) {
        return format_LongLong;
    } else if (storedType == Float()) {
        return format_Float;
    } else if (storedType == Double()) {
        return format_Double;
    } else if (storedType == LongDouble()) {
        return format_LongDouble;
    } else if (storedType == Char()) {
        return format_Char;
    } else if (storedType == String()) {
        return format_String;
    }

}

void options_boxSize(){
    backMenu:
    clearScreen();
    printTitle();

    printf("Type your preferred box size: ");
    int boxSize = getSel();

    if(boxSize < 5){
        goto backMenu;
    }
    if(boxSize > 40){
        backSelection:
        clearScreen();
        printTitle();
        printf("Huge sizes can distort boxes, are you sure about that?\n"
               "1 - Yes\n"
               "2 - No\n"
               "Selection: ");

        switch(getSel()){
            case 1:
                boxBound = boxSize;
                return;
            case 2:
                goto backMenu;
            default:
                goto backSelection;
        }
    }
    boxBound = boxSize;
}

void options(){
    backMenu:
    clearScreen();
    printTitle();

    printf("1 - Change box display size\n"
           "2 - Back\n"
           "Selection: ");

    switch(getSel()){
        case 1:
            options_boxSize();
            break;
        case 2:
            return;
        default:
            goto backMenu;
    }
    goto backMenu;
}

void displaying(){
    clearScreen();
    printTitle();
    printf("This is your data structure:\n");
    print(dataStructure, boxBound);
    pressEnter();
}
void pushing(){
    clearScreen();
    printTitle();

    void* added;
    // TODO: ADD THIS TO MORE PLACES
    if(ofClass(&storedType, PrimWrapper()))
        added = new(storedType, NULL, NULL);
    else if(storedType == String())
        added = new(String(), "");

    printf("Type in your value: ");
    scan(added);

    push(dataStructure, added);

    printf("Data added!\n");
    pressEnter();
}
void peeking(){
    clearScreen();
    printTitle();

    if (structureType == List()){
        printf("For this type I'd recommend using the \"get\" method ;)\n");
        pressEnter();
        return;
    }

    if(as(int, get_len(dataStructure)) != 0){
        printf("Peeking at... C_C: ");
        print(peek(dataStructure), boxBound);
    } else printf("There are no items to peek at <_<");


    printf("\n");
    pressEnter();
}
void popping(){
    backMenu:
    clearScreen();
    printTitle();

    if (structureType == List()){
        printf("Where in the List you want to pop the data: ");
        int index;
        scanf("%i", &index);

        if(index < 0 || index >= as(int, get_len(dataStructure))) {
            printf("Maybe a bit more... or less, idk.");
            pressEnter();
            goto backMenu;
        }

        printf("Popped: ");
        print(pop(dataStructure, index));
    }
    else {
        if(as(int, get_len(dataStructure)) != 0){
            printf("Popped: ");
            print(pop(dataStructure), boxBound);
        } else printf("There are no items to be popped");
    }
    printf("\n");
    pressEnter();
}
void getting(){
    backMenu:
    clearScreen();
    printTitle();

    if (structureType == List()){
        printf("Type the index in the List you want to get the data from: ");
        int index;
        scanf("%i", &index);

        if(index < 0 || index >= as(int, get_len(dataStructure))) {
            printf("Invalid value");
            pressEnter();
            goto backMenu;
        }

        printf("It got: ");
        print(get(dataStructure, index));
    }
    else {
        printf("Oh silly, this data structure does not use a get function\n");
        pressEnter();
        return;
    }
    pressEnter();
}
void setting(){
    backMenu:
    clearScreen();
    printTitle();

    if (structureType == List()){
        printf("Where in the List you want to set the value: ");
        int index;
        scanf("%i", &index);

        if (index < 0 || index >= as(int, get_len(dataStructure))) {
            printf("Not this value >:(");
            pressEnter();
            goto backMenu;
        }

        void *added = new(storedType, NULL, NULL);
        printf("Type the value you want to add: ");
        scan(added);

        set(dataStructure, index, added);
    }
    else {
        printf("This data structure does not use a set function :[\n");
        pressEnter();
        return;
    }

    printf("Data added!");
    pressEnter();
}
void finding() {
    backMenu:
    clearScreen();
    printTitle();


    int index = -2;

    void* compared = new(storedType, NULL, NULL);
    printf("Type the value you want to find: ");
    scan(compared);

    index = as(int, indexOf(dataStructure, compared));

    if(index == -1)
        printf("Value not found\n");
    else{
        printf("Found it at index %i\n", index);
    }

    pressEnter();
}
void resizing(){
    backMenu:
    clearScreen();
    printTitle();

    if (strcmp(structureStyle, "Linked") == 0){
        printf("No need for resizing, linked lists fit perfectly the amount of data ;)\n");
        pressEnter();
        return;
    }
    else {
        printf("To which size you want to resize it (You can type 0 for it to fit perfectly the data): ");
        int size;
        scanf("%i", &size);

        if(size < -1) {
            printf("Invalid value");
            pressEnter();
            goto backMenu;
        }

        resize(dataStructure, size);
    }
    printf("Resized!\n");
    pressEnter();
}
void clearing(){
    backMenu:
    clearScreen();
    printTitle();

    clear(dataStructure);

    printf("Done :)\n");
    pressEnter();
}

void modifyStructure(){
    if(strcmp(structureStyle, "Array") == 0){
        if(structureType == List())
            dataStructure = new(ArrayList(), storedType);
        else if(structureType == Queue())
            dataStructure = new(ArrayQueue(), storedType);
        else
            dataStructure = new(ArrayStack(), storedType);
    }
    else{
        if(structureType == List())
            dataStructure = new(LinkedList(), storedType);
        else if(structureType == Queue())
            dataStructure = new(LinkedQueue(), storedType);
        else
            dataStructure = new(LinkedStack(), storedType);
    }

    backMenu:
    clearScreen();
    printTitle();

    printf("What do you want to do with your data structure?\n"
           "1 - Display it\n"
           "2 - Push value\n"
           "3 - Peek at value\n"
           "4 - Pop value\n"
           "5 - Get value\n"
           "6 - Set value\n"
           "7 - Find value\n"
           "8 - Resize\n"
           "9 - Clear everything\n"
           "10 - Back\n"
           "Selection: ");

    switch(getSel()){
        case 1:
            displaying();
            break;
        case 2:
            pushing();
            break;
        case 3:
            peeking();
            break;
        case 4:
            popping();
            break;
        case 5:
            getting();
            break;
        case 6:
            setting();
            break;
        case 7:
            finding();
            break;
        case 8:
            resizing();
            break;
        case 9:
            clearing();
            break;
        case 10:
            return;
        default:
            goto backMenu;
    }
    goto backMenu;
}
void createStructureData(){
    backMenu:
    clearScreen();
    printTitle();

    printf("Which type you want to store in your data structure?\n"
           "1 - Short\n"
           "2 - Int\n"
           "3 - Long\n"
           "4 - Long Long\n"
           "5 - Float\n"
           "6 - Double\n"
           "7 - Long Double\n"
           "8 - Char\n"
           "9 - String\n"
           "10 - Back\n"
           "Selection: ");

    switch(getSel()){
        case 1:
            storedType = Short();
            break;
        case 2:
            storedType = Int();
            break;
        case 3:
            storedType = Long();
            break;
        case 4:
            storedType = LongLong();
            break;
        case 5:
            storedType = Float();
            break;
        case 6:
            storedType = Double();
            break;
        case 7:
            storedType = LongDouble();
            break;
        case 8:
            storedType = Char();
            break;
        case 9:
            storedType = String();
            break;
        case 10:
            return;
        default:
            goto backMenu;
    }
    modifyStructure();
    goto backMenu;
}
void createSructureStyle(){
    backMenu:
    clearScreen();
    printTitle();

    printf("Which style of structure you want to create?\n"
           "1 - Array\n"
           "2 - Linked\n"
           "3 - Back\n"
           "Selection: ");

    switch(getSel()){
        case 1:
            strcpy(structureStyle, "Array");
            break;
        case 2:
            strcpy(structureStyle, "Linked");
            break;
        case 3:
            return;
        default:
            goto backMenu;
    }
    createStructureData();
    goto backMenu;
}
void createStructure(){
    backMenu:
    clearScreen();
    printTitle();

    printf("Which type of structure you want to create?\n"
           "1 - List\n"
           "2 - Queue\n"
           "3 - Stack\n"
           "4 - Back\n"
           "Selection: ");

    switch(getSel()){
        case 1:
            structureType = List();
            break;
        case 2:
            structureType = Queue();
            break;
        case 3:
            structureType = Stack();
            break;
        case 4:
            return;
        default:
            goto backMenu;
    }
    createSructureStyle();
    goto backMenu;
}

void testing(){
    float i = 313.321;
    struct Double* ptr = wrap(i);

    print(ptr, 10);
    printf("-");
}

int main() {
    backMenu:
    clearScreen();
    printTitle();

    printf("1 - Create Data Structure\n"
           "2 - Options\n"
           "3 - Exit\n"
           "Selection: ");

    switch(getSel()){
        case 1:
            createStructure();
            break;
        case 2:
            options();
            break;
        case 3:
            printf("\n\nThank You for using DATA STRUCTURES[tm]\n");
            return 0;
        default:
            goto backMenu;
    }

    goto backMenu;

    struct ArrayStack* arrayStack = new(ArrayStack(), Long());
    long r;
    for(int i = 0; i < NUMBER_OJBS; i++){
        r = rand();
        push(arrayStack, wrap(r));
    }
    print(arrayStack, boxBound);
    for(int i = 0; i < 10; i++){
        pop(arrayStack);
    }
    for(int i = 0; i < 5; i++){
        r = rand();
        push(arrayStack, wrap(r));
    }

    print(arrayStack, boxBound);


    return 0;
}
