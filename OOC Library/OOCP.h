#ifndef OOC_PREPROCESSOR_H
#define OOC_PREPROCESSOR_H

#include <stdio.h>


/*** Standard defines ***/
#define OOCP_VOID_PTR_TYPE pointer
#define OOCP_METHOD_TYPE method
#define OOCP_METHOD_RET_TYPE OOCP_VOID_PTR_TYPE
#define OOCP_METHOD_PARAMS struct CLASS_NAME* self, va_list* args
#define OOCP_STD_FUNC_INSTANCE_OF_CLASS OOC_instanceOfClass
#define OOCP_STD_FUNC_CAST OOC_cast
#define OOCP_STD_FUNC_NEW_CLASS OOC_newClass
#define OOCP_STD_FUNC_ABSTRACT OOC_abstract
#define OOCP_STD_FUNC_FATAL_ERROR OOC_fatalError
/*** ---------- ***/

// TODO: Expand this and move this ugly stuff to its own header file.
/*** Preprocessor helper macros ***/
#define OOCP_EXPAND(...) __VA_ARGS__
#define OOCP_EAT(...)

#define _OOCP_GLUE(X,Y) X##Y
#define OOCP_GLUE(X,Y) _OOCP_GLUE(X,Y)

#define _OOCP_STRINGIFY(X) #X
#define OOCP_STRINGIFY(X) _OOCP_STRINGIFY(X)

#define _OOCP_IIF_0(T, F) OOCP_EXPAND F
#define _OOCP_IIF_1(T, F) OOCP_EXPAND T
#define OOCP_IIF(COND, T, F) OOCP_GLUE(_OOCP_IIF_, COND)(T, F) 

#define _OOCP_ARG_100(_,\
   _100,_99,_98,_97,_96,_95,_94,_93,_92,_91,_90,_89,_88,_87,_86,_85,_84,_83,_82,_81, \
   _80,_79,_78,_77,_76,_75,_74,_73,_72,_71,_70,_69,_68,_67,_66,_65,_64,_63,_62,_61, \
   _60,_59,_58,_57,_56,_55,_54,_53,_52,_51,_50,_49,_48,_47,_46,_45,_44,_43,_42,_41, \
   _40,_39,_38,_37,_36,_35,_34,_33,_32,_31,_30,_29,_28,_27,_26,_25,_24,_23,_22,_21, \
   _20,_19,_18,_17,_16,_15,_14,_13,_12,_11,_10,_9,_8,_7,_6,_5,_4,_3,_2,X_,...) X_

#define OOCP_HAS_COMMA(...) OOCP_EXPAND(_OOCP_ARG_100(__VA_ARGS__, \
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, \
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))

#define OOCP_TRIGGER_PARENTHESIS(...) ,

#define _OOCP_BOOL_AND_00(X, Y) 0
#define _OOCP_BOOL_AND_01(X, Y) 0
#define _OOCP_BOOL_AND_10(X, Y) 0
#define _OOCP_BOOL_AND_11(X, Y) 1
#define OOCP_BOOL_AND(X, Y) OOCP_GLUE(_OOCP_BOOL_AND_,OOCP_GLUE(X,Y))

#define _OOCP_BOOL_OR_00(X, Y) 0
#define _OOCP_BOOL_OR_01(X, Y) 1
#define _OOCP_BOOL_OR_10(X, Y) 1
#define _OOCP_BOOL_OR_11(X, Y) 1
#define OOCP_BOOL_OR(X, Y) OOCP_GLUE(_OOCP_BOOL_OR_,OOCP_GLUE(X,Y))

#define _OOCP_BOOL_XOR_00(X, Y) 0
#define _OOCP_BOOL_XOR_01(X, Y) 1
#define _OOCP_BOOL_XOR_10(X, Y) 1
#define _OOCP_BOOL_XOR_11(X, Y) 0
#define OOCP_BOOL_XOR(X, Y) OOCP_GLUE(_OOCP_BOOL_XOR_,OOCP_GLUE(X,Y))

#define _OOCP_BOOL_NOT_0(X) 1
#define _OOCP_BOOL_NOT_1(X) 0
#define OOCP_BOOL_NOT(X) OOCP_GLUE(_OOCP_BOOL_NOT_, X)


// If this used the normal TRIGGER_PARENTHESIS, any __VA_ARGS__ containing it would not correcly
#define _OOCP_IS_EMPTY_TRIGGER_PARENTHESIS(...) ,
#define _OOCP_IS_EMPTY_PASTE5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define _OOCP_IS_EMPTY_CASE_0001 ,
#define _OOCP_IS_EMPTY(_0, _1, _2, _3) OOCP_HAS_COMMA(_OOCP_IS_EMPTY_PASTE5(_OOCP_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define OOCP_IS_EMPTY(...)  \
   _OOCP_IS_EMPTY(                                                                  \
      /* test if there is just one argument, eventually an empty                    \
         one */                                                                     \
      OOCP_HAS_COMMA(__VA_ARGS__),                                                  \
      /* test if _TRIGGER_PARENTHESIS_ together with the argument                   \
         adds a comma */                                                            \
      OOCP_HAS_COMMA(_OOCP_IS_EMPTY_TRIGGER_PARENTHESIS __VA_ARGS__),               \
      /* test if the argument together with a parenthesis                           \
         adds a comma */                                                            \
      OOCP_HAS_COMMA(__VA_ARGS__ (/*empty*/)),                                      \
      /* test if placing it between _TRIGGER_PARENTHESIS_ and the                   \
         parenthesis adds a comma */                                                \
      OOCP_HAS_COMMA(_OOCP_IS_EMPTY_TRIGGER_PARENTHESIS __VA_ARGS__ (/*empty*/))    \
   )

#define _OOCP_VA_OPT_EXPAND(...) __VA_ARGS__
#define OOCP_VA_OPT(...) OOCP_IIF(OOCP_IS_EMPTY(__VA_ARGS__), (OOCP_EAT), (_OOCP_VA_OPT_EXPAND))

#define _OOCP_FIRST_PULL(X, ...) X
#define OOCP_FIRST(...) OOCP_IIF(OOCP_IS_EMPTY(__VA_ARGS__), (), (_OOCP_FIRST_PULL(__VA_ARGS__)))

#define _OOCP_TAIL_PULL(X, ...) __VA_ARGS__
#define OOCP_TAIL(...) OOCP_IIF(OOCP_IS_EMPTY(__VA_ARGS__), (), (_OOCP_TAIL_PULL(__VA_ARGS__)))

// If this used the normal EXPAND, any __VA_ARGS__ containing it would not correcly
#define OOCP_HAS_PARENTHESIS(...) \
   OOCP_HAS_COMMA(OOCP_EXPAND(OOCP_TRIGGER_PARENTHESIS OOCP_FIRST(__VA_ARGS__)))

#define OOCP_REMOVE_PARENTHESIS(...) OOCP_IIF(OOCP_HAS_PARENTHESIS(__VA_ARGS__), (OOCP_EXPAND __VA_ARGS__), (__VA_ARGS__))

#define _OOCP_VAR_COUNT_EMPTY_1(...) 0
#define _OOCP_VAR_COUNT_EMPTY_0(...) OOCP_EXPAND(_OOCP_ARG_100(__VA_ARGS__, \
   100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81, \
   80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61, \
   60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41, \
   40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21, \
   20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1))
/* Counts the number of arguments passed */
#define OOCP_VAR_COUNT(...) OOCP_GLUE(_OOCP_VAR_COUNT_EMPTY_, OOCP_IS_EMPTY(__VA_ARGS__))(__VA_ARGS__)

// TODO: Learn how to do recursiveness and make this better.
#define OOCP_FOREACH(NAME_, SEP, ...) OOCP_GLUE(OOCP_FOREACH_,OOCP_VAR_COUNT(__VA_ARGS__))(NAME_, SEP, OOCP_EXPAND(__VA_ARGS__))
#define OOCP_FOREACH_0(NAME_, SEP, ...) 
#define OOCP_FOREACH_1(NAME_, SEP, ...) NAME_(__VA_ARGS__)
#define OOCP_FOREACH_2(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_1(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_3(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_2(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_4(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_3(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_5(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_4(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_6(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_5(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_7(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_6(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_8(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_7(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_9(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_8(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_10(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_9(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_11(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_10(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_12(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_11(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_13(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_12(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_14(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_13(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_15(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_14(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_16(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_15(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_17(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_16(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_18(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_17(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_19(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_18(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_20(NAME_, SEP, ...) NAME_(OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_19(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))

// If you use the normal OOCP_EXPAND, any macros (in NAME_) containing it will not replace OOCP_EXPAND.
#define OOCP_FOREACH_TUPLE_EXPAND(...) __VA_ARGS__
#define OOCP_FOREACH_TUPLE(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(OOCP_GLUE(OOCP_FOREACH_TUPLE_,OOCP_VAR_COUNT(__VA_ARGS__))(NAME_, SEP, __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_0(NAME_, SEP, ...) 
#define OOCP_FOREACH_TUPLE_1(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ __VA_ARGS__)
#define OOCP_FOREACH_TUPLE_2(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_1(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_3(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_2(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_4(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_3(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_5(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_4(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_6(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_5(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_7(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_6(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_8(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_7(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_9(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_8(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_10(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_9(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_11(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_10(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_12(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_11(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_13(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_12(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_14(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_13(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_15(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_14(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_16(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_15(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_17(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_16(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_18(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_17(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_19(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_18(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))
#define OOCP_FOREACH_TUPLE_20(NAME_, SEP, ...) OOCP_FOREACH_TUPLE_EXPAND(NAME_ OOCP_FIRST(__VA_ARGS__)) OOCP_EXPAND(OOCP_REMOVE_PARENTHESIS SEP) OOCP_FOREACH_TUPLE_19(NAME_, SEP, OOCP_TAIL( __VA_ARGS__))

/*** ---------- ***/

/*** Method declaration and definition ***/
#define OOCP_DECLARE_METHOD(METHOD_NAME) \
   static OOCP_METHOD_RET_TYPE METHOD_NAME(OOCP_METHOD_PARAMS)
/*** ---------- ***/

/*** New class ***/
// Setup for detecting keyword 'default'
#define _OOCP_METHOD_DETECT_DEFAULT_default ,
#define _OOCP_METHOD_PAIR_IS_DEFAULT(TYPE) OOCP_HAS_COMMA(OOCP_GLUE(_OOCP_METHOD_DETECT_DEFAULT_, TYPE))
// Setup for detecting keyword 'abstract'.
#define _OOCP_METHOD_DETECT_ABSTRACT_abstract ,
#define _OOCP_METHOD_IS_ABSTRACT(TYPE) OOCP_HAS_COMMA(OOCP_GLUE(_OOCP_METHOD_DETECT_ABSTRACT_, TYPE))

#define _OOCP_NEW_CLASS_TEMPLATE_METHOD_PAIR_GET_FUNCTION(TYPE, METHOD_NAME) \
OOCP_IIF(_OOCP_METHOD_PAIR_IS_DEFAULT(TYPE) \
   ,(OOCP_GLUE(_, METHOD_NAME)) \
   ,(OOCP_IIF(_OOCP_METHOD_IS_ABSTRACT(TYPE) \
      ,(OOCP_STD_FUNC_ABSTRACT) \
      ,(TYPE) \
   )) \
)
// Pairs up the arguments correctly.
// From <(type1, name1)> it forms <"METHOD_NAME", method_function> to be passed to 'newClass'.
#define _OOCP_NEW_CLASS_TEMPLATE_METHOD_PAIR(TYPE, METHOD_NAME) \
   OOCP_STRINGIFY(METHOD_NAME), _OOCP_NEW_CLASS_TEMPLATE_METHOD_PAIR_GET_FUNCTION(TYPE, METHOD_NAME)

// Declares a method function if 'TYPE' is not abstract.
#define _OOCP_NEW_CLASS_TEMPLATE_DECLARE_METHOD(TYPE, METHOD_NAME) \
OOCP_IIF( _OOCP_METHOD_IS_ABSTRACT(TYPE) \
   ,() \
   ,(OOCP_DECLARE_METHOD(_OOCP_NEW_CLASS_TEMPLATE_METHOD_PAIR_GET_FUNCTION(TYPE, METHOD_NAME));) \
)

// __VA_ARGS__ are methods, in the form <(type1, name1), (type2, name2), (type3, name3), ...>
#define OOCP_NEW_CLASS_TEMPLATE(CLASS_NAME, SUPER, ...) \
   OOCP_FOREACH_TUPLE(_OOCP_NEW_CLASS_TEMPLATE_DECLARE_METHOD, (;), __VA_ARGS__); \
   /* Creating global variable that will store the class. */ \
   static OOCP_VOID_PTR_TYPE OOCP_GLUE(OOC_CLASS_, CLASS_NAME) = NULL; \
   /* Creating a fuction CLASS_NAME() that returns the class. */ \
   OOCP_VOID_PTR_TYPE CLASS_NAME(){ \
      /* If the class is not initialize, create it. */ \
      if (OOCP_GLUE(OOC_CLASS_, CLASS_NAME)) { \
         return OOCP_GLUE(OOC_CLASS_, CLASS_NAME); \
      } \
      if (CLASS_NAME == SUPER){ \
         OOC_fatalError("Class cannot be super of itself", __LINE__, __FILE__); \
      } \
      return (OOCP_GLUE(OOC_CLASS_, CLASS_NAME) = OOCP_STD_FUNC_NEW_CLASS(SUPER(), OOCP_STRINGIFY(CLASS_NAME), sizeof(struct CLASS_NAME), __LINE__, __FILE__ \
         OOCP_VA_OPT(__VA_ARGS__)(,) OOCP_FOREACH_TUPLE(_OOCP_NEW_CLASS_TEMPLATE_METHOD_PAIR, (,), __VA_ARGS__) \
         ,NULL)); \
   }
//----------

// Integer promotion
#define char_OOCP_IS_PROMOTED_TRIGGER ,
#define short_OOCP_IS_PROMOTED_TRIGGER ,
#define float_OOCP_IS_PROMOTED_TRIGGER ,
#define _Bool_OOCP_IS_PROMOTED_TRIGGER ,

#define OOCP_IS_PROMOTED(type) OOCP_HAS_COMMA(OOCP_GLUE(type, _OOCP_IS_PROMOTED_TRIGGER))

#define OOCP_PROMOTE(type) \
   OOCP_IIF( OOCP_IS_PROMOTED(type) \
      ,(int) \
      ,(type) \
   )
//----------

// Typechecking
#define char_OOCP_PRIMITIVE_REMOVE_
#define short_OOCP_PRIMITIVE_REMOVE_ 
#define int_OOCP_PRIMITIVE_REMOVE_ 
#define long_OOCP_PRIMITIVE_REMOVE_
#define float_OOCP_PRIMITIVE_REMOVE_
#define double_OOCP_PRIMITIVE_REMOVE_
#define pointer_OOCP_PRIMITIVE_REMOVE_
#define _Bool_OOCP_PRIMITIVE_REMOVE_
#define class_OOCP_PRIMITIVE_REMOVE_

#define char_OOCP_PRIMITIVE_DETECT_ ,char
#define short_OOCP_PRIMITIVE_DETECT_ ,short
#define int_OOCP_PRIMITIVE_DETECT_ ,int
#define long_OOCP_PRIMITIVE_DETECT_ ,long
#define float_OOCP_PRIMITIVE_DETECT_ ,float
#define double_OOCP_PRIMITIVE_DETECT_ ,double
#define pointer_OOCP_PRIMITIVE_DETECT_ ,pointer
#define _Bool_OOCP_PRIMITIVE_DETECT_ ,_Bool
#define class_OOCP_PRIMITIVE_DETECT_ ,class
// Returns whether the type is primitive
#define OOCP_IS_PRIMITIVE(TYPE) OOCP_HAS_COMMA(OOCP_GLUE(TYPE, _OOCP_PRIMITIVE_DETECT_))

#define _OOCP_PRIM_IS_LONG_EXPAND(...) __VA_ARGS__
#define long_OOCP_KEYWORD_DETECT_ ,long
#define long_OOCP_KEYWORD_REMOVE_
// Returns whether the primitive is long
#define OOCP_PRIM_IS_LONG(TYPE) \
OOCP_IIF(OOCP_IS_PRIMITIVE(TYPE) \
   , (OOCP_HAS_COMMA(OOCP_GLUE(_OOCP_PRIM_IS_LONG_EXPAND(OOCP_GLUE(TYPE, _OOCP_PRIMITIVE_REMOVE_)), _OOCP_KEYWORD_DETECT_))) \
   , (OOCP_ERROR_NOT_PRIMITIVE) \
)

#define unsigned_OOCP_UNSIGNED_DETECT_ ,unsigned
// Returns whether the primitive is unsigned.
// Note: OOCP_GLUE(type, _OOCP_PRIMITIVE_REMOVE_) removes the primitive
#define _OOCP_PRIM_IS_UNSIGNED(TYPE) \
OOCP_IIF(OOCP_PRIM_IS_LONG(TYPE) \
   , (OOCP_HAS_COMMA(OOCP_GLUE(OOCP_GLUE(OOCP_GLUE(TYPE, _OOCP_PRIMITIVE_REMOVE_), _OOCP_KEYWORD_REMOVE_), _OOCP_UNSIGNED_DETECT_))) \
   , (OOCP_HAS_COMMA(OOCP_GLUE(OOCP_GLUE(TYPE, _OOCP_PRIMITIVE_REMOVE_), _OOCP_UNSIGNED_DETECT_))) \
)

#define OOCP_CAT_PRIMITIVE_EXPAND
// Concatenates a possible type together with underlines (e.g. <unsigned long int> to <unsigned_long_int>)
#define OOCP_CAT_PRIMITIVE(TYPE) \
OOCP_IIF(OOCP_IS_PRIMITIVE(TYPE) \
   ,(OOCP_IIF(OOCP_PRIM_IS_LONG(TYPE) \
      ,(OOCP_IIF(_OOCP_PRIM_IS_UNSIGNED(TYPE) \
         ,(OOCP_GLUE(unsigned_long_, OOCP_TAIL(OOCP_GLUE(TYPE, _OOCP_PRIMITIVE_DETECT_)))) \
         ,(OOCP_GLUE(long_, OOCP_TAIL(OOCP_GLUE(TYPE, _OOCP_PRIMITIVE_DETECT_))))\
      )) \
      ,(OOCP_IIF(_OOCP_PRIM_IS_UNSIGNED(TYPE) \
         ,(OOCP_GLUE(unsigned_, OOCP_TAIL(OOCP_GLUE(TYPE, _OOCP_PRIMITIVE_DETECT_)))) \
         ,(OOCP_TAIL(OOCP_GLUE(TYPE, _OOCP_PRIMITIVE_DETECT_)))\
      )) \
   )) \
   , (OOCP_ERROR_NOT_PRIMITIVE) \
)

// TODO: Overhaul this (it's not modular ATM).
#define OOCP_TYPE_KEY_null (int)0
#define OOCP_TYPE_KEY_char (int)1
#define OOCP_TYPE_KEY_short (int)2
#define OOCP_TYPE_KEY_int (int)3
#define OOCP_TYPE_KEY_long (int)4
#define OOCP_TYPE_KEY_long_long (int)5
#define OOCP_TYPE_KEY_float (int)6
#define OOCP_TYPE_KEY_double (int)7
#define OOCP_TYPE_KEY_long_double (int)8
#define OOCP_TYPE_KEY_unsigned_char (int)9
#define OOCP_TYPE_KEY_unsigned_short (int)10
#define OOCP_TYPE_KEY_unsigned_int (int)11
#define OOCP_TYPE_KEY_unsigned_long (int)12
#define OOCP_TYPE_KEY_unsigned_long_long (int)13
#define OOCP_TYPE_KEY_pointer (int)100
#define OOCP_TYPE_KEY__Bool (int)101
#define OOCP_TYPE_KEY_class (int)102
#define OOCP_TYPE_KEY_Object (int)103

#define OOCP_VAR_KEY_NULL OOCP_TYPE_KEY_null
#define OOCP_VAR_KEY_CHAR OOCP_TYPE_KEY_char
#define OOCP_VAR_KEY_SHORT OOCP_TYPE_KEY_short
#define OOCP_VAR_KEY_INT OOCP_TYPE_KEY_int
#define OOCP_VAR_KEY_LONG OOCP_TYPE_KEY_long
#define OOCP_VAR_KEY_LONG_LONG OOCP_TYPE_KEY_long_long
#define OOCP_VAR_KEY_FLOAT OOCP_TYPE_KEY_float
#define OOCP_VAR_KEY_DOUBLE OOCP_TYPE_KEY_double
#define OOCP_VAR_KEY_LONG_DOUBLE OOCP_TYPE_KEY_long_double
#define OOCP_VAR_KEY_UNSIGNED_CHAR OOCP_TYPE_KEY_unsigned_char
#define OOCP_VAR_KEY_UNSIGNED_SHORT OOCP_TYPE_KEY_unsigned_short
#define OOCP_VAR_KEY_UNSIGNED_INT OOCP_TYPE_KEY_unsigned_int
#define OOCP_VAR_KEY_UNSIGNED_LONG OOCP_TYPE_KEY_unsigned_long
#define OOCP_VAR_KEY_UNSIGNED_LONG_LONG OOCP_TYPE_KEY_unsigned_long_long
#define OOCP_VAR_KEY_BOOL OOCP_TYPE_KEY__Bool
#define OOCP_VAR_KEY_CLASS OOCP_TYPE_KEY_class
#define OOCP_VAR_KEY_PTR OOCP_TYPE_KEY_pointer

#define OOCP_VAR_KEY(var) \
    _Generic((var), \
        char: OOCP_VAR_KEY_CHAR, \
        short: OOCP_VAR_KEY_SHORT, \
        int: OOCP_VAR_KEY_INT, \
        long: OOCP_VAR_KEY_LONG, \
        long long: OOCP_VAR_KEY_LONG_LONG, \
        float: OOCP_VAR_KEY_FLOAT, \
        double: OOCP_VAR_KEY_DOUBLE, \
        long double: OOCP_VAR_KEY_LONG_DOUBLE, \
        unsigned char: OOCP_VAR_KEY_UNSIGNED_CHAR, \
        unsigned short: OOCP_VAR_KEY_UNSIGNED_SHORT, \
        unsigned int: OOCP_VAR_KEY_UNSIGNED_INT, \
        unsigned long: OOCP_VAR_KEY_UNSIGNED_LONG, \
        unsigned long long: OOCP_VAR_KEY_UNSIGNED_LONG_LONG, \
        _Bool: OOCP_VAR_KEY_BOOL, \
        class: OOCP_VAR_KEY_CLASS, \
        default: OOCP_VAR_KEY_PTR)

#define OOCP_VAR_TYPE_NAME(var) \
    _Generic((var), \
        char: "char", \
        short: "short", \
        int: "int", \
        long: "long", \
        long long: "long long", \
        float: "float", \
        double: "double", \
        long double: "long double", \
        unsigned char: "unsigned char", \
        unsigned short: "unsigned short", \
        unsigned int: "unsigned int", \
        unsigned long: "unsigned long", \
        unsigned long long: "unsigned long long", \
        _Bool: "bool", \
        class: "class", \
        default: "pointer")\

#define _OOCP_GET_AND_CHECK_PARAM_PRINT_KEY_TYPE \
   switch(key){ \
      case OOCP_VAR_KEY_NULL: printf("params_end"); break; \
      case OOCP_VAR_KEY_CHAR: printf("char"); break; \
      case OOCP_VAR_KEY_SHORT: printf("short"); break; \
      case OOCP_VAR_KEY_INT: printf("int"); break; \
      case OOCP_VAR_KEY_LONG: printf("long"); break; \
      case OOCP_VAR_KEY_LONG_LONG: printf("long long"); break; \
      case OOCP_VAR_KEY_FLOAT: printf("float"); break; \
      case OOCP_VAR_KEY_DOUBLE: printf("double"); break; \
      case OOCP_VAR_KEY_LONG_DOUBLE: printf("long double"); break; \
      case OOCP_VAR_KEY_UNSIGNED_CHAR: printf("unsigned char"); break; \
      case OOCP_VAR_KEY_UNSIGNED_SHORT: printf("unsigned short"); break; \
      case OOCP_VAR_KEY_UNSIGNED_INT: printf("unsigned int"); break; \
      case OOCP_VAR_KEY_UNSIGNED_LONG: printf("unsigned long"); break; \
      case OOCP_VAR_KEY_UNSIGNED_LONG_LONG: printf("unsigned long long"); break; \
      case OOCP_VAR_KEY_BOOL: printf("bool"); break; \
      case OOCP_VAR_KEY_CLASS: printf("class"); break; \
      default: printf("pointer"); break; \
   }

//----------


// TODO: It feels like this idea can be used somewhere
/*#define _OBJ_TYPE(var) _Generic(((var)0), \
\
    char: Char, \
    short: Short, \
    int: Int, \
    long: Long, \
    long long: LongLong, \
    float: Float, \
    double: Double, \
    long double: LongDouble, \
    void*: Ptr, \
/** END User helper functions **/

// Checks if the type matches, via the returned type key for primitives and cast for Objects,
// and in case it's successful, returns the item (properly casted).
#define as(type, ret)( \
   OOCP_IIF(OOCP_IS_PRIMITIVE(type) \
      ,((pointer)OOCP_GLUE(OOCP_TYPE_KEY_, OOCP_CAT_PRIMITIVE(type)) == (ret) ? ((type)_OOC_returning_buffer):(*((type*)(OOCP_STD_FUNC_FATAL_ERROR("Error: Return was not of type " OOCP_STRINGIFY(type), __LINE__, __FILE__))))) \
      ,(((struct type*)OOCP_STD_FUNC_CAST(type(), _OOC_returning_buffer, __LINE__, __FILE__))) \
   ) \
)

// Stores the returned variable in the 'returning_buffer' and returns the type key.
#define returning(type, ...) \
   { \
   OOCP_IIF(OOCP_IS_EMPTY(__VA_ARGS__) \
      ,(_OOC_returning_buffer = 0; return type(pointer)OOCP_TYPE_KEY_null;) \
      ,(OOCP_IIF(OOCP_IS_PRIMITIVE(type) \
         ,(_OOC_returning_buffer = (long long)__VA_ARGS__; return (pointer)OOCP_GLUE(OOCP_TYPE_KEY_, OOCP_CAT_PRIMITIVE(type));) \
         ,(_OOC_returning_buffer = (long long)__VA_ARGS__; return (pointer)OOCP_TYPE_KEY_Object;) \
      )) \
   ) \
   }
// In case it's a primitive:
// - Creates a variable of the type <type> with name <var>, pulls the type key of the parameter
// - passed and checks if it matches <type>. In case it is, it stores the value in <var>, otherwise
// - it throws an error.
// Otherwise, we assume an Object:
// - Creates a struct pointer of type <type> with name <var>, pulls the type key of the parameter
// - passed and checks if it is an object. In case it is, it casts to <type>, if successful it stores
// - the object in <var>, otherwise it thorw an error.
#define param(type, var) \
   OOCP_IIF(OOCP_IS_PRIMITIVE(type) \
      ,( \
         type var; \
         { \
            int key = (int)va_arg(*args, int); \
            if (key != OOCP_VAR_KEY(var)) { \
               printf("\nError: Parameter \'%s\' expected type ", OOCP_STRINGIFY(var)); \
               printf(OOCP_VAR_TYPE_NAME(var)); \
               printf(" but received "); \
               _OOCP_GET_AND_CHECK_PARAM_PRINT_KEY_TYPE \
               printf("\n"); \
               OOC_fatalError(NULL, __LINE__, __FILE__); \
            } \
            var = va_arg(*args, OOCP_PROMOTE(type)); \
         } \
      ) \
      ,( \
         struct type* var; \
         { \
            int key = (int)va_arg(*args, int); \
            if (key != OOCP_VAR_KEY(var)) { \
               printf("\nError: Parameter \'%s\' expected type ", OOCP_STRINGIFY(var)); \
               printf(OOCP_STRINGIFY(type)); \
               printf(" but received "); \
               _OOCP_GET_AND_CHECK_PARAM_PRINT_KEY_TYPE \
               printf("\n"); \
               OOC_fatalError(NULL, __LINE__, __FILE__); \
            } \
            var = va_arg(*args, void*); \
            if(isObject(var)){ \
               if (!OOCP_STD_FUNC_INSTANCE_OF_CLASS(var, type(), __LINE__, __FILE__)) { \
                  printf("\nError: Parameter \'%s\' expected type ", OOCP_STRINGIFY(var)); \
                  printf(OOCP_STRINGIFY(type)); \
                  printf(" but received %s", ((struct Object*)(var))->class->name); \
                  printf("\n"); \
                  OOC_fatalError(NULL, __LINE__, __FILE__); \
               } \
            } \
            else { \
               printf("\nError: Parameter \'%s\' expected type ", OOCP_STRINGIFY(var)); \
               printf(OOCP_STRINGIFY(type)); \
               printf(" but received pointer"); \
               printf("\n"); \
               OOC_fatalError(NULL, __LINE__, __FILE__); \
            } \
         } \
      ) \
   )

#define paramOptional(type, var, default) \
   OOCP_IIF(OOCP_IS_PRIMITIVE(type) \
      ,( \
         type var; \
         { \
            va_list copy_args; \
            va_copy(copy_args, *args); \
            int key = (int)va_arg(copy_args, int); \
            if (key == OOCP_TYPE_KEY_null){ \
               var = default; \
            } \
            else if (key != OOCP_VAR_KEY(var)) { \
               printf("\nError: Parameter \'%s\' expected type ", OOCP_STRINGIFY(var)); \
               printf(OOCP_VAR_TYPE_NAME(var)); \
               printf(" but received "); \
               _OOCP_GET_AND_CHECK_PARAM_PRINT_KEY_TYPE \
               printf("\n"); \
               OOC_fatalError(NULL, __LINE__, __FILE__); \
            } \
            else { \
               va_arg(*args, int); \
               var = va_arg(*args, OOCP_PROMOTE(type)); \
            } \
         } \
      ) \
      ,( \
         struct type* var; \
         { \
            va_list copy_args; \
            va_copy(copy_args, *args); \
            int key = (int)va_arg(copy_args, int); \
            if (key == OOCP_TYPE_KEY_null){ \
               var = default; \
            } \
            else if (key != OOCP_VAR_KEY(var)) { \
               printf("\nError: Parameter \'%s\' expected type ", OOCP_STRINGIFY(var)); \
               printf(OOCP_STRINGIFY(type)); \
               printf(" but received "); \
               _OOCP_GET_AND_CHECK_PARAM_PRINT_KEY_TYPE \
               printf("\n"); \
               OOC_fatalError(NULL, __LINE__, __FILE__); \
            } \
            else { \
               va_arg(*args, int); \
               var = va_arg(*args, void*); \
            } \
            if(isObject(var)){ \
               if (!OOCP_STD_FUNC_INSTANCE_OF_CLASS(var, type(), __LINE__, __FILE__)) { \
                  printf("\nError: Parameter \'%s\' expected type ", OOCP_STRINGIFY(var)); \
                  printf(OOCP_STRINGIFY(type)); \
                  printf(" but received %s", ((struct Object*)(var))->class->name); \
                  printf("\n"); \
                  OOC_fatalError(NULL, __LINE__, __FILE__); \
               } \
            } \
            else { \
               printf("\nError: Parameter \'%s\' expected type ", OOCP_STRINGIFY(var)); \
               printf(OOCP_STRINGIFY(type)); \
               printf(" but received pointer"); \
               printf("\n"); \
               OOC_fatalError(NULL, __LINE__, __FILE__); \
            } \
         } \
      ) \
   )

#define define_method(name) OOCP_DECLARE_METHOD(OOCP_GLUE(_, name))
/** END User friendly macros**/

#endif // OOC_PREPROCESSOR_H
