# Object-Oriented-C
This library was developed mostly for learning purposes, and although it has usable aspects, I would not recommend using this in any development project (although analyzing the inner working may help you understand how OOP concepts may be implemented). 

It makes heavy use of C Preprocessor wizardry, some of which you can learn yourself by reading [Cloak's wiki on the subject](https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms). They are used to add syntatic sugar and make the "language" easier to use. However, the macro implementations themselves can be very hairy, hard to understand, and hard to debug. 

Well... too bad for the guy debugging them! (spoilers: it's me)

Features
---

 - Creation and deletion of objects
 - Inheritance
 - Method overloading
 - Interclass polymorphism
 - Optional parameters
 - Runtime typechecking for objects
 - Runtime error messages with backtracing of method calls
 - Creation on "scoped" (`automatic`) objects
 
Lacking features
---

 - Intraclass Polymorphism
 - Exceptions
 - Protected and private data/methods
 - Better return system (see issue #2)

Using the library
---

To see an example of how to create an object, take a peek at the `Example.h`, `Example.c` and `Example.r`. Here's the gist though:
 - Create a `.h` file with some convenient macros for your methods (`#define myMethod(self, ...) callMethod("myMethod", self, __VA_ARGS__)`)
 - Create a `.r` file with a structure representing your class' data. It starts with the `struct` of the super class, usually named `_` (e.g. `const struct Object _;`), which is followed by the data of the class.
 - Create a `.c` file with a declaration for the methods, which can be `default` or `abstract` (e.g. `(default, ctor)`), and definitions for the non-abstract methods.

The parameters of the method are declared at the start of the method body, with the `param` statement. There also may be optional parameters, declared with the `paramOptional` statement, which will default to a specified value if not passed.

You may also return values with the `returning` statement. The return type is also specified in the statement. As a result, the method can have multiple return types. You may return a value `null` by leaving the `returning` statement empty (i.e. `returning()`).

You may also use `callSuperMethod(<...>)` with the appropriate parameters to call the method from the super class.

Snippet from `Example.c` of method definitions:
```c
define_method(ctor){
    param(int, i);
    param(float, f);
    param(char, c);
    paramOptional(int, protI, 0);
    paramOptional(float, protF, 0.0);
    paramOptional(char, protC, '\0');
    
    self->i = i;
    self->f = f;
    self->c = c;
    self->protI = protI;
    self->protF = protF;
    self->protC = protC;
    self->ptrC = malloc(sizeof(char) * 50);

    printf("I'm alive.\n");

    returning(Example, self);
}

define_method(dtor){
    free(self->ptrC);
    printf("I'm dead.\n");

    returning(Example, self);
}
```

You may then import the `.h` file to use the class.

A class structure is automatically generated. This allows one to check the class of objects:
 - `ofClass(obj, Class)`: Will verify if the object `obj` is _exactly_ of the class `Class`.
 - `instanceOfClass(obj, Class)`: Will verify if the class of `obj` is a subclass of `Class`

A new object may be created using the `new` statement (e.g. `new(Example, param1, param2, param3)`). The first parameter is the class of the object. The other parameters are passed to the `ctor` method, which is automatically called upon creation. `new` will return a pointer to the object. 

Conversely, you may destroy an object using the `delete` statement (e.g. `delete(obj)`). The only parameter is a pointer to the object. It automatically calls the `dtor` method.

You may also create a new object using the `automatic` statement. It receives the same parameters as `new`. When an object is created with the `automatic` keyword inside a method, it will destroy itself automatically upon leaving the method.

Extras:
 - `cast(Example, obj)`: Force-test the type of an object. Throws an error if `obj` is not an instance of `Example`.
 - `sizeOf(obj)`: Returns the memory size of `obj`.

