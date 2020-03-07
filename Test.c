
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
    scanf("%c", &c);
}

char format_Short[] = "%i";
char format_Int[] = "%i";
char format_Long[] = "%li";
char format_LongLong[] = "%lli";
char format_Float[] = "%f";
char format_Double[] = "%lf";
char format_LongDouble[] = "%Lf";
char format_Char[] = "%c";
char format_String[] = "%s";
char* getCorrectFormat(){

}

void options_boxSize(){
    backMenu:
    clearScreen();
    printTitle();

    int selection;

    printf("Type your preferred box size: ");
    scanf("%i", &selection);

    if(selection < 5){
        goto backMenu;
    }
    if(selection > 40){
        backSelection:
        clearScreen();
        printTitle();
        printf("Huge sizes can distort boxes, are you sure about that?\n"
               "1 - Yes\n"
               "2 - No\n"
               "Selection: ");
        scanf("%i", &selection);

        switch(selection){
            case 1:
                boxBound = selection;
                return;
            case 2:
                goto backMenu;
            default:
                goto backSelection;
        }
    }
    boxBound = selection;
    return;
}

void options(){
    backMenu:
    clearScreen();
    printTitle();

    int selection;

    printf("1 - Change box display size\n"
           "2 - Back\n"
           "Selection: ");
    scanf("%i", &selection);

    switch(selection){
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

    printf("Type in your ");

    if(storedType == Short()){
        printf("short: ");
        short input;
        scanf("%i", &input);
        push(dataStructure, wrap(input));
    }
    else if(storedType == Int()){
        printf("int: ");
        int input;
        scanf("%i", &input);
        push(dataStructure, wrap(input));
    }
    else if(storedType == Long()){
        printf("long: ");
        long input;
        scanf("%li", &input);
        push(dataStructure, wrap(input));
    }
    else if(storedType == LongLong()){
        printf("long long: ");
        long long input;
        scanf("%lli", &input);
        push(dataStructure, wrap(input));
    }
    else if(storedType == Float()){
        printf("float: ");
        float input;
        scanf("%f", &input);
        push(dataStructure, wrap(input));
    }
    else if(storedType == Double()){
        printf("double: ");
        double input;
        scanf("%lf", &input);
        push(dataStructure, wrap(input));
    }
    else if(storedType == LongDouble()){
        printf("long double: ");
        long double input;
        scanf("%Lf", &input);
        push(dataStructure, wrap(input));
    }
    else if(storedType == Char()){
        printf("char: ");
        char input;
        scanf("%c ", &input);
        push(dataStructure, wrap(input));
    }
    else if(storedType == String()){
        printf("string: ");
        char input[10000];
        char c;
        scanf("%c",&c); // temp statement to clear buffer
        scanf("%[^\n]", input);
        void* str = new(String(), input);
        push(dataStructure, str);
    }
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

    printf("Peeking at: ");
    if(storedType == Short()){
        short peeked;
        unwrap(peek(dataStructure), peeked);
        printf("%i", peeked);
    }
    else if(storedType == Int()){
        int peeked;
        unwrap(peek(dataStructure), peeked);
        printf("%i", peeked);
    }
    else if(storedType == Long()){
        long peeked;
        unwrap(peek(dataStructure), peeked);
        printf("%li", peeked);
    }
    else if(storedType == LongLong()){
        long long peeked;
        unwrap(peek(dataStructure), peeked);
        printf("%lli", peeked);
    }
    else if(storedType == Float()){
        float peeked;
        unwrap(peek(dataStructure), peeked);
        printf("%f", peeked);
    }
    else if(storedType == Double()){
        double peeked;
        unwrap(peek(dataStructure), peeked);
        printf("%lf", peeked);
    }
    else if(storedType == LongDouble()){
        long double peeked;
        unwrap(peek(dataStructure), peeked);
        printf("%Lf", peeked);
    }
    else if(storedType == Char()){
        char peeked;
        unwrap(peek(dataStructure), peeked);
        printf("%c", peeked);
    }
    else if(storedType == String()){
        printf("%s", asArray(peek(dataStructure)));
    }
    printf("\n");
    pressEnter();
}
void popping(){
    backMenu:
    clearScreen();
    printTitle();

    if (structureType == List()){
        printf("Where in the List you want to pop the value: ");
        int index;
        scanf("%i", &index);

        if(index < 0 || index >= as(int, get_len(dataStructure))) {
            printf("Invalid value");
            pressEnter();
            goto backMenu;
        }

        printf("Popped: ");
        if (storedType == Short()) {
            short popped;
            unwrap(pop(dataStructure, index), popped);
            printf("%i", popped);
        } else if (storedType == Int()) {
            int popped;
            unwrap(pop(dataStructure, index), popped);
            printf("%i", popped);
        } else if (storedType == Long()) {
            long popped;
            unwrap(pop(dataStructure, index), popped);
            printf("%li", popped);
        } else if (storedType == LongLong()) {
            long long popped;
            unwrap(pop(dataStructure, index), popped);
            printf("%lli", popped);
        } else if (storedType == Float()) {
            float popped;
            unwrap(pop(dataStructure, index), popped);
            printf("%f", popped);
        } else if (storedType == Double()) {
            double popped;
            unwrap(pop(dataStructure), popped);
            printf("%lf", popped);
        } else if (storedType == LongDouble()) {
            long double popped;
            unwrap(pop(dataStructure, index), popped);
            printf("%Lf", popped);
        } else if (storedType == Char()) {
            char popped;
            unwrap(pop(dataStructure, index), popped);
            printf("%c", popped);
        } else if (storedType == String()) {
            printf("%s", asArray(pop(dataStructure, index)));
        }
    }
    else {
        printf("Popped: ");
        if (storedType == Short()) {
            short popped;
            unwrap(pop(dataStructure), popped);
            printf("%i", popped);
        } else if (storedType == Int()) {
            int popped;
            unwrap(pop(dataStructure), popped);
            printf("%i", popped);
        } else if (storedType == Long()) {
            long popped;
            unwrap(pop(dataStructure), popped);
            printf("%li", popped);
        } else if (storedType == LongLong()) {
            long long popped;
            unwrap(pop(dataStructure), popped);
            printf("%lli", popped);
        } else if (storedType == Float()) {
            float popped;
            unwrap(pop(dataStructure), popped);
            printf("%f", popped);
        } else if (storedType == Double()) {
            double popped;
            unwrap(pop(dataStructure), popped);
            printf("%lf", popped);
        } else if (storedType == LongDouble()) {
            long double popped;
            unwrap(pop(dataStructure), popped);
            printf("%Lf", popped);
        } else if (storedType == Char()) {
            char popped;
            unwrap(pop(dataStructure), popped);
            printf("%c", popped);
        } else if (storedType == String()) {
            printf("%s", asArray(pop(dataStructure)));
        }
    }
    printf("\n");
    pressEnter();
}
void getting(){
    backMenu:
    clearScreen();
    printTitle();

    if (structureType != List()){
        printf("Oh silly, this data structure does not use a get function\n");
        pressEnter();
    }
    else {
        printf("Where in the List you want to get the value: ");
        int index;
        scanf("%i", &index);

        if(index < 0 || index >= as(int, get_len(dataStructure))) {
            printf("Invalid value");
            pressEnter();
            goto backMenu;
        }

        printf("It got: ");
        if (storedType == Short()) {
            short popped;
            unwrap(get(dataStructure, index), popped);
            printf("%i", popped);
        } else if (storedType == Int()) {
            int popped;
            unwrap(get(dataStructure, index), popped);
            printf("%i", popped);
        } else if (storedType == Long()) {
            long popped;
            unwrap(get(dataStructure, index), popped);
            printf("%li", popped);
        } else if (storedType == LongLong()) {
            long long popped;
            unwrap(get(dataStructure, index), popped);
            printf("%lli", popped);
        } else if (storedType == Float()) {
            float popped;
            unwrap(get(dataStructure, index), popped);
            printf("%f", popped);
        } else if (storedType == Double()) {
            double popped;
            unwrap(get(dataStructure, index), popped);
            printf("%lf", popped);
        } else if (storedType == LongDouble()) {
            long double popped;
            unwrap(get(dataStructure, index), popped);
            printf("%Lf", popped);
        } else if (storedType == Char()) {
            char popped;
            unwrap(get(dataStructure, index), popped);
            printf("%c", popped);
        } else if (storedType == String()) {
            printf("%s", asArray(get(dataStructure, index)));
        }
    }
    pressEnter();
}
void setting(){
    backMenu:
    clearScreen();
    printTitle();

    if (structureType != List()){
        printf("This data structure does not use a set function ¯\\_( )_/¯\n");
        pressEnter();
    }
    else {
        printf("Where in the List you want to set the value: ");
        int index;
        scanf("%i", &index);

        if(index < 0 || index >= as(int, get_len(dataStructure))) {
            printf("Invalid value");
            pressEnter();
            goto backMenu;
        }

        printf("It got: ");
        if (storedType == Short()) {
            printf("Type the short you want to add: ");
            short added;
            scanf("%i", &added);
            get(dataStructure, index, wrap(added));
        } else if (storedType == Int()) {
            printf("Type the int you want to add: ");
            int added;
            scanf("%i", &added);
            get(dataStructure, index, wrap(added));
        } else if (storedType == Long()) {
            printf("Type the long you want to add: ");
            long added;
            scanf("%li", &added);
            get(dataStructure, index, wrap(added));
        } else if (storedType == LongLong()) {
            printf("Type the long long you want to add: ");
            long long added;
            scanf("%lli", &added);
            get(dataStructure, index, wrap(added));
        } else if (storedType == Float()) {
            printf("Type the float you want to add: ");
            float added;
            scanf("%f", &added);
            get(dataStructure, index, wrap(added));
        } else if (storedType == Double()) {
            printf("Type the double you want to add: ");
            double added;
            scanf("%lf", &added);
            get(dataStructure, index, wrap(added));
        } else if (storedType == LongDouble()) {
            printf("Type the long double you want to add: ");
            long double added;
            scanf("%Lf", &added);
            get(dataStructure, index, wrap(added));
        } else if (storedType == Char()) {
            printf("Type the char you want to add: ");
            char added;
            scanf("%c", &added);
            get(dataStructure, index, wrap(added));
        } else if (storedType == String()) {
            printf("Type the string you want to add: ");
            char added[10000];
            scanf("%s", &added);
            get(dataStructure, index, new(String(), added));
        }
    }
    printf("Data added!");
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
        printf("To which size you want to resize it (You can type -1 for it to fit perfectly the data): ");
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

    int selection;

    printf("What do you want to do with your data structure?\n"
           "1 - Display it\n"
           "2 - Push value\n"
           "3 - Peek at value\n"
           "4 - Pop value\n"
           "5 - Get value\n"
           "6 - Set value\n"
           "7 - Resize\n"
           "8 - Clear everything\n"
           "9 - Back\n"
           "Selection: ");
    scanf("%i", &selection);

    switch(selection){
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
            resizing();
            break;
        case 8:
            clearing();
            break;
        case 9:
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

    int selection;

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
    scanf("%i", &selection);

    switch(selection){
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

    int selection;

    printf("Which style of structure you want to create?\n"
           "1 - Array\n"
           "2 - Linked\n"
           "3 - Back\n"
           "Selection: ");
    scanf("%i", &selection);

    switch(selection){
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

    int selection;

    printf("Which type of structure you want to create?\n"
           "1 - List\n"
           "2 - Queue\n"
           "3 - Stack\n"
           "4 - Back\n"
           "Selection: ");
    scanf("%i", &selection);

    switch(selection){
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
    int i = 10;
    void* ptr = wrap(i);

    i = 20;
    unwrap(ptr, i);
    printf("%i", i);
}

int main() {
    backMenu:
    clearScreen();
    printTitle();

    int selection;

    printf("1 - Create Data Structure\n"
           "2 - Options\n"
           "3 - Exit\n"
           "Selection: ");
    scanf("%i", &selection);

    switch(selection){
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
            printf("\n\nThank You for using DATA STRUCTURES[tm]\n");
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
