
#ifndef OOC_PREPROCESSOR_H
#define OOC_PREPROCESSOR_H

#include <stdio.h>

/** START Preprocessor inside functions **/
/* _UNPAR - If the is one, remove one layer of parenthesis from this variable: */
#define _EXTRACT(...) _EXTRACT __VA_ARGS__
#define _NOTHING_EXTRACT
#define _PASTE(x, ...) x ## __VA_ARGS__
#define _EVALUATING_PASTE(x, ...) _PASTE(x, __VA_ARGS__)
#define _UNPAR(val) _EVALUATING_PASTE(_NOTHING, _EXTRACT val)


// _REM_FIRST - Removes the first argument, if one is present
#define _HELPER_REM_FIRST(dummy, ...) __VA_ARGS__
#define _REM_FIRST(...) _HELPER_REM_FIRST(__VA_ARGS__)

/* FOREACH - Execute MACRO for all variables in __VA_ARGS__ */

#define _PP_SEQ(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, \
                 _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, \
                 _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, \
                 _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, \
                 _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, \
                 _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, \
                 _60, _61, _62, N, ...) N


#define _HELPER_CALL_THIS(caller, ...) caller(__VA_ARGS__)
#define _CALL_THIS(caller, var) _HELPER_CALL_THIS(caller, var)

#define _FOREACH_0(CALL)
#define _FOREACH_1(CALL, VAR) _CALL_THIS(CALL, _UNPAR(VAR))
#define _FOREACH_2(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_1(CALL, __VA_ARGS__)
#define _FOREACH_3(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_2(CALL, __VA_ARGS__)
#define _FOREACH_4(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_3(CALL, __VA_ARGS__)
#define _FOREACH_5(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_4(CALL, __VA_ARGS__)
#define _FOREACH_6(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_5(CALL, __VA_ARGS__)
#define _FOREACH_7(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_6(CALL, __VA_ARGS__)
#define _FOREACH_8(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_7(CALL, __VA_ARGS__)
#define _FOREACH_9(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_8(CALL, __VA_ARGS__)

#define _FOREACH_10(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_9(CALL, __VA_ARGS__)
#define _FOREACH_11(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_10(CALL, __VA_ARGS__)
#define _FOREACH_12(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_11(CALL, __VA_ARGS__)
#define _FOREACH_13(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_12(CALL, __VA_ARGS__)
#define _FOREACH_14(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_13(CALL, __VA_ARGS__)
#define _FOREACH_15(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_14(CALL, __VA_ARGS__)
#define _FOREACH_16(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_15(CALL, __VA_ARGS__)
#define _FOREACH_17(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_16(CALL, __VA_ARGS__)
#define _FOREACH_18(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_17(CALL, __VA_ARGS__)
#define _FOREACH_19(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_18(CALL, __VA_ARGS__)

#define _FOREACH_20(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_19(CALL, __VA_ARGS__)
#define _FOREACH_21(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_20(CALL, __VA_ARGS__)
#define _FOREACH_22(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_21(CALL, __VA_ARGS__)
#define _FOREACH_23(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_22(CALL, __VA_ARGS__)
#define _FOREACH_24(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_23(CALL, __VA_ARGS__)
#define _FOREACH_25(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_24(CALL, __VA_ARGS__)
#define _FOREACH_26(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_25(CALL, __VA_ARGS__)
#define _FOREACH_27(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_26(CALL, __VA_ARGS__)
#define _FOREACH_28(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_27(CALL, __VA_ARGS__)
#define _FOREACH_29(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_28(CALL, __VA_ARGS__)

#define _FOREACH_30(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_29(CALL, __VA_ARGS__)
#define _FOREACH_31(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_30(CALL, __VA_ARGS__)
#define _FOREACH_32(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_31(CALL, __VA_ARGS__)
#define _FOREACH_33(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_32(CALL, __VA_ARGS__)
#define _FOREACH_34(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_33(CALL, __VA_ARGS__)
#define _FOREACH_35(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_34(CALL, __VA_ARGS__)
#define _FOREACH_36(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_35(CALL, __VA_ARGS__)
#define _FOREACH_37(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_36(CALL, __VA_ARGS__)
#define _FOREACH_38(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_37(CALL, __VA_ARGS__)
#define _FOREACH_39(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_38(CALL, __VA_ARGS__)

#define _FOREACH_40(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_39(CALL, __VA_ARGS__)
#define _FOREACH_41(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_40(CALL, __VA_ARGS__)
#define _FOREACH_42(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_41(CALL, __VA_ARGS__)
#define _FOREACH_43(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_42(CALL, __VA_ARGS__)
#define _FOREACH_44(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_43(CALL, __VA_ARGS__)
#define _FOREACH_45(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_44(CALL, __VA_ARGS__)
#define _FOREACH_46(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_45(CALL, __VA_ARGS__)
#define _FOREACH_47(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_46(CALL, __VA_ARGS__)
#define _FOREACH_48(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_47(CALL, __VA_ARGS__)
#define _FOREACH_49(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_48(CALL, __VA_ARGS__)

#define _FOREACH_50(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_49(CALL, __VA_ARGS__)
#define _FOREACH_51(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_50(CALL, __VA_ARGS__)
#define _FOREACH_52(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_51(CALL, __VA_ARGS__)
#define _FOREACH_53(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_52(CALL, __VA_ARGS__)
#define _FOREACH_54(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_53(CALL, __VA_ARGS__)
#define _FOREACH_55(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_54(CALL, __VA_ARGS__)
#define _FOREACH_56(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_55(CALL, __VA_ARGS__)
#define _FOREACH_57(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_56(CALL, __VA_ARGS__)
#define _FOREACH_58(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_57(CALL, __VA_ARGS__)
#define _FOREACH_59(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_58(CALL, __VA_ARGS__)

#define _FOREACH_60(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_59(CALL, __VA_ARGS__)
#define _FOREACH_61(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_60(CALL, __VA_ARGS__)
#define _FOREACH_62(CALL, VAR, ...) _CALL_THIS(CALL, _UNPAR(VAR)) _FOREACH_61(CALL, __VA_ARGS__)

#define _HELPER_FOREACH(MACRO, ...) _PP_SEQ(NULL, ##__VA_ARGS__ \
                                        , _FOREACH_62(MACRO, __VA_ARGS__), _FOREACH_61(MACRO, __VA_ARGS__), _FOREACH_60(MACRO, __VA_ARGS__) \
                                        , _FOREACH_59(MACRO, __VA_ARGS__), _FOREACH_58(MACRO, __VA_ARGS__), _FOREACH_57(MACRO, __VA_ARGS__), _FOREACH_56(MACRO, __VA_ARGS__), _FOREACH_55(MACRO, __VA_ARGS__) \
                                        , _FOREACH_54(MACRO, __VA_ARGS__), _FOREACH_53(MACRO, __VA_ARGS__), _FOREACH_52(MACRO, __VA_ARGS__), _FOREACH_51(MACRO, __VA_ARGS__), _FOREACH_50(MACRO, __VA_ARGS__) \
                                        , _FOREACH_49(MACRO, __VA_ARGS__), _FOREACH_48(MACRO, __VA_ARGS__), _FOREACH_47(MACRO, __VA_ARGS__), _FOREACH_46(MACRO, __VA_ARGS__), _FOREACH_45(MACRO, __VA_ARGS__) \
                                        , _FOREACH_44(MACRO, __VA_ARGS__), _FOREACH_43(MACRO, __VA_ARGS__), _FOREACH_42(MACRO, __VA_ARGS__), _FOREACH_41(MACRO, __VA_ARGS__), _FOREACH_40(MACRO, __VA_ARGS__) \
                                        , _FOREACH_39(MACRO, __VA_ARGS__), _FOREACH_38(MACRO, __VA_ARGS__), _FOREACH_37(MACRO, __VA_ARGS__), _FOREACH_36(MACRO, __VA_ARGS__), _FOREACH_35(MACRO, __VA_ARGS__) \
                                        , _FOREACH_34(MACRO, __VA_ARGS__), _FOREACH_33(MACRO, __VA_ARGS__), _FOREACH_32(MACRO, __VA_ARGS__), _FOREACH_31(MACRO, __VA_ARGS__), _FOREACH_30(MACRO, __VA_ARGS__) \
                                        , _FOREACH_29(MACRO, __VA_ARGS__), _FOREACH_28(MACRO, __VA_ARGS__), _FOREACH_27(MACRO, __VA_ARGS__), _FOREACH_26(MACRO, __VA_ARGS__), _FOREACH_25(MACRO, __VA_ARGS__) \
                                        , _FOREACH_24(MACRO, __VA_ARGS__), _FOREACH_23(MACRO, __VA_ARGS__), _FOREACH_22(MACRO, __VA_ARGS__), _FOREACH_21(MACRO, __VA_ARGS__), _FOREACH_20(MACRO, __VA_ARGS__) \
                                        , _FOREACH_19(MACRO, __VA_ARGS__), _FOREACH_18(MACRO, __VA_ARGS__), _FOREACH_17(MACRO, __VA_ARGS__), _FOREACH_16(MACRO, __VA_ARGS__), _FOREACH_15(MACRO, __VA_ARGS__) \
                                        , _FOREACH_14(MACRO, __VA_ARGS__), _FOREACH_13(MACRO, __VA_ARGS__), _FOREACH_12(MACRO, __VA_ARGS__), _FOREACH_11(MACRO, __VA_ARGS__), _FOREACH_10(MACRO, __VA_ARGS__) \
                                        , _FOREACH_9(MACRO, __VA_ARGS__), _FOREACH_8(MACRO, __VA_ARGS__), _FOREACH_7(MACRO, __VA_ARGS__), _FOREACH_6(MACRO, __VA_ARGS__), _FOREACH_5(MACRO, __VA_ARGS__) \
                                        , _FOREACH_4(MACRO, __VA_ARGS__), _FOREACH_3(MACRO, __VA_ARGS__), _FOREACH_2(MACRO, __VA_ARGS__), _FOREACH_1(MACRO, __VA_ARGS__), _FOREACH_0(MACRO))
#define FOREACH(MACRO, ...) _HELPER_FOREACH(MACRO, ##__VA_ARGS__)


#define _CALL_THIS_PAIR(caller, var0, var1) caller(var0, var1)

#define _FOREACH_PAIR_0(CALL)
#define _FOREACH_PAIR_2(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_0(CALL, ##__VA_ARGS__)
#define _FOREACH_PAIR_4(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_2(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_6(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_4(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_8(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_6(CALL, __VA_ARGS__)

#define _FOREACH_PAIR_10(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_8(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_12(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_10(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_14(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_12(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_16(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_14(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_18(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_16(CALL, __VA_ARGS__)

#define _FOREACH_PAIR_20(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_18(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_22(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_20(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_24(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_22(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_26(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_24(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_28(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_26(CALL, __VA_ARGS__)

#define _FOREACH_PAIR_30(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_28(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_32(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_30(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_34(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_32(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_36(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_34(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_38(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_36(CALL, __VA_ARGS__)

#define _FOREACH_PAIR_40(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_38(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_42(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_40(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_44(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_42(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_46(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_44(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_48(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_46(CALL, __VA_ARGS__)

#define _FOREACH_PAIR_50(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_48(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_52(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_50(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_54(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_52(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_56(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_54(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_58(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_56(CALL, __VA_ARGS__)

#define _FOREACH_PAIR_60(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_58(CALL, __VA_ARGS__)
#define _FOREACH_PAIR_62(CALL, VAR0, VAR1, ...) _CALL_THIS_PAIR(CALL, _UNPAR(VAR0), _UNPAR(VAR1)) _FOREACH_PAIR_60(CALL, __VA_ARGS__)

#define _HELPER_FOREACH_PAIR(MACRO, ...) _PP_SEQ(NULL, ##__VA_ARGS__ \
                                    , _FOREACH_PAIR_62(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_60(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_58(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_56(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_54(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_52(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_50(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_48(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_46(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_44(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_42(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_40(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_38(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_36(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_34(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_32(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_30(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_28(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_26(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_24(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_22(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_20(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_18(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_16(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_14(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_12(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_10(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_8(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_6(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_4(MACRO, __VA_ARGS__), INVALID_ARGS, _FOREACH_PAIR_2(MACRO, __VA_ARGS__), INVALID_ARGS \
                                    , _FOREACH_PAIR_0(MACRO))
#define FOREACH_PAIR(MACRO, ...) _HELPER_FOREACH_PAIR(MACRO, ##__VA_ARGS__)


#define _CALL_THIS(caller, var) caller(var)

#define _FOREACH_ADD_0(ADDED)
#define _FOREACH_ADD_1(ADDED, VAR) ,(ADDED, _UNPAR(VAR))
#define _FOREACH_ADD_2(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_1(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_3(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_2(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_4(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_3(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_5(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_4(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_6(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_5(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_7(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_6(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_8(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_7(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_9(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_8(ADDED, __VA_ARGS__)

#define _FOREACH_ADD_10(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_9(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_11(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_10(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_12(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_11(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_13(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_12(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_14(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_13(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_15(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_14(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_16(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_15(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_17(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_16(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_18(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_17(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_19(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_18(ADDED, __VA_ARGS__)

#define _FOREACH_ADD_20(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_19(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_21(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_20(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_22(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_21(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_23(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_22(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_24(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_23(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_25(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_24(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_26(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_25(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_27(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_26(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_28(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_27(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_29(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_28(ADDED, __VA_ARGS__)

#define _FOREACH_ADD_30(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_29(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_31(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_30(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_32(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_31(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_33(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_32(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_34(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_33(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_35(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_34(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_36(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_35(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_37(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_36(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_38(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_37(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_39(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_38(ADDED, __VA_ARGS__)

#define _FOREACH_ADD_40(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_39(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_41(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_40(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_42(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_41(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_43(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_42(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_44(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_43(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_45(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_44(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_46(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_45(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_47(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_46(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_48(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_47(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_49(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_48(ADDED, __VA_ARGS__)

#define _FOREACH_ADD_50(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_49(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_51(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_50(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_52(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_51(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_53(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_52(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_54(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_53(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_55(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_54(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_56(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_55(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_57(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_56(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_58(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_57(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_59(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_58(ADDED, __VA_ARGS__)

#define _FOREACH_ADD_60(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_59(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_61(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_60(ADDED, __VA_ARGS__)
#define _FOREACH_ADD_62(ADDED, VAR, ...) ,(ADDED, _UNPAR(VAR)) _FOREACH_ADD_61(ADDED, __VA_ARGS__)

#define _HELPER_FOREACH_ADD(ADDED, ...) _PP_SEQ(NULL, ##__VA_ARGS__ \
                                        , _FOREACH_ADD_62(ADDED, __VA_ARGS__), _FOREACH_ADD_61(ADDED, __VA_ARGS__), _FOREACH_ADD_60(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_59(ADDED, __VA_ARGS__), _FOREACH_ADD_58(ADDED, __VA_ARGS__), _FOREACH_ADD_57(ADDED, __VA_ARGS__), _FOREACH_ADD_56(ADDED, __VA_ARGS__), _FOREACH_ADD_55(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_54(ADDED, __VA_ARGS__), _FOREACH_ADD_53(ADDED, __VA_ARGS__), _FOREACH_ADD_52(ADDED, __VA_ARGS__), _FOREACH_ADD_51(ADDED, __VA_ARGS__), _FOREACH_ADD_50(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_49(ADDED, __VA_ARGS__), _FOREACH_ADD_48(ADDED, __VA_ARGS__), _FOREACH_ADD_47(ADDED, __VA_ARGS__), _FOREACH_ADD_46(ADDED, __VA_ARGS__), _FOREACH_ADD_45(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_44(ADDED, __VA_ARGS__), _FOREACH_ADD_43(ADDED, __VA_ARGS__), _FOREACH_ADD_42(ADDED, __VA_ARGS__), _FOREACH_ADD_41(ADDED, __VA_ARGS__), _FOREACH_ADD_40(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_39(ADDED, __VA_ARGS__), _FOREACH_ADD_38(ADDED, __VA_ARGS__), _FOREACH_ADD_37(ADDED, __VA_ARGS__), _FOREACH_ADD_36(ADDED, __VA_ARGS__), _FOREACH_ADD_35(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_34(ADDED, __VA_ARGS__), _FOREACH_ADD_33(ADDED, __VA_ARGS__), _FOREACH_ADD_32(ADDED, __VA_ARGS__), _FOREACH_ADD_31(ADDED, __VA_ARGS__), _FOREACH_ADD_30(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_29(ADDED, __VA_ARGS__), _FOREACH_ADD_28(ADDED, __VA_ARGS__), _FOREACH_ADD_27(ADDED, __VA_ARGS__), _FOREACH_ADD_26(ADDED, __VA_ARGS__), _FOREACH_ADD_25(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_24(ADDED, __VA_ARGS__), _FOREACH_ADD_23(ADDED, __VA_ARGS__), _FOREACH_ADD_22(ADDED, __VA_ARGS__), _FOREACH_ADD_21(ADDED, __VA_ARGS__), _FOREACH_ADD_20(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_19(ADDED, __VA_ARGS__), _FOREACH_ADD_18(ADDED, __VA_ARGS__), _FOREACH_ADD_17(ADDED, __VA_ARGS__), _FOREACH_ADD_16(ADDED, __VA_ARGS__), _FOREACH_ADD_15(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_14(ADDED, __VA_ARGS__), _FOREACH_ADD_13(ADDED, __VA_ARGS__), _FOREACH_ADD_12(ADDED, __VA_ARGS__), _FOREACH_ADD_11(ADDED, __VA_ARGS__), _FOREACH_ADD_10(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_9(ADDED, __VA_ARGS__), _FOREACH_ADD_8(ADDED, __VA_ARGS__), _FOREACH_ADD_7(ADDED, __VA_ARGS__), _FOREACH_ADD_6(ADDED, __VA_ARGS__), _FOREACH_ADD_5(ADDED, __VA_ARGS__) \
                                        , _FOREACH_ADD_4(ADDED, __VA_ARGS__), _FOREACH_ADD_3(ADDED, __VA_ARGS__), _FOREACH_ADD_2(ADDED, __VA_ARGS__), _FOREACH_ADD_1(ADDED, __VA_ARGS__), _FOREACH_ADD_0(ADDED))
#define FOREACH_ADD_ARG(ADDED, ...) _REM_FIRST(_HELPER_FOREACH_ADD(ADDED, ##__VA_ARGS__))


#define _SINGLE_SEP_PAIR(var0, var1) ,var0
#define _SINGLE_SEP_ODD(var0, var1) ,var1

#define _SEP_PAIRS(...) _REM_FIRST(FOREACH_PAIR(_SINGLE_SEP_PAIR, ##__VA_ARGS__))
#define _SEP_ODDS(...) _REM_FIRST(FOREACH_PAIR(_SINGLE_SEP_ODD, ##__VA_ARGS__))

#define _HELPER_EMPTY_REMOVER(...) , ##__VA_ARGS__
#define _EMPTY_REMOVER(...) _HELPER_EMPTY_REMOVER(__VA_ARGS__)
/** END Preprocessor inside functions **/

/** START Single helper functions **/
#define single_object_build_getset(VAR) \
    void _get_##VAR(void* self, void* target, unsigned int targetSize){ \
        const struct Class* baseClass = getClass(cast(Object(), self)); \
        \
        int i = 0; \
        for(i = 0; baseClass->dataGet[i] != _get_##VAR; i++){ \
            if (baseClass->dataGet[i] == NULL){ \
                assert(0 /* This class does not have this variable */); \
            } \
        } \
        \
        if (targetSize != baseClass->dataSizes[i]){ \
            assert(0 /* Type mismatch */); \
        } \
        \
        memcpy(target, self + baseClass->dataOffsets[i], baseClass->dataSizes[i]); \
    } \
    void _set_##VAR(void* self, void* target, unsigned int targetSize){ \
        const struct Class* baseClass = getClass(cast(Object(), self)); \
        \
        int i = 0; \
        for(i = 0; baseClass->dataGet[i] != _get_##VAR; i++){ \
            if (baseClass->dataGet[i] == NULL){ \
                assert(0 /* This class does not have this variable */); \
            } \
        } \
        \
        if (targetSize != baseClass->dataSizes[i]){ \
            assert(0 /* Type mismatch */); \
        } \
        \
        memcpy(self + baseClass->dataOffsets[i], target, baseClass->dataSizes[i]); \
    }

#define _HELPER_PAIR_UP(x, y) ,x y
#define PAIR_UP(x, y) _HELPER_PAIR_UP(x, y)

// Receives pairs of arguments in the form (int, i, float, f, char, c) and returns (,int i ,float f, char c)
#define _HELPER_PAIR_UP_ARGS(...) FOREACH_PAIR(PAIR_UP, ##__VA_ARGS__)
#define PAIR_UP_ARGS(...) _HELPER_PAIR_UP_ARGS(__VA_ARGS__)


#define _HELPER_PROMOTE(var) _Generic(((var)0), \
\
    char: va_arg(*args, int), \
    short: va_arg(*args, int), \
    int: va_arg(*args, int), \
    long: va_arg(*args, long), \
    long long: va_arg(*args, long long), \
    float: va_arg(*args, double), \
    double: va_arg(*args, double), \
    long double: va_arg(*args, long double), \
    void*: va_arg(*args, void*), \
    char*: va_arg(*args, void*), \
    short*: va_arg(*args, void*), \
    int*: va_arg(*args, void*), \
    long long*: va_arg(*args, void*), \
    float*: va_arg(*args, void*), \
    long double*: va_arg(*args, void*), \
    va_list*: va_arg(*args, void*));

#define _PROMOTE_VA_ARGS(type, var) type var = _HELPER_PROMOTE(type)

#define FUNC_END_LONG_LONG 138698154113960401L
#define FUNC_END_LONG_DOUBLE 138698154113960402.0L
#define FUNC_END_DOUBLE 1386981541139603.0
#define FUNC_END FUNC_END_LONG_LONG, FUNC_END_LONG_DOUBLE, FUNC_END_DOUBLE


#define _HELPER_IMPORT_VARS(...) FOREACH_PAIR(_PROMOTE_VA_ARGS, ##__VA_ARGS__)
#define _IMPORT_VARS(...) _HELPER_IMPORT_VARS(__VA_ARGS__)


#define _GET_SEC(x, y) ,y

#define _HELPER_VAR_NAMES(...) FOREACH_PAIR(_GET_SEC, ##__VA_ARGS__)
#define VAR_NAMES(...) _HELPER_VAR_NAMES(__VA_ARGS__)


// FIXME: TYPECHECKING DOES NOT WORK ._______________________. Why lord
#define _HELPER_single_buildFunc(CLASS, FUNC, ARGS) \
    void* CLASS##_##FUNC(void* self PAIR_UP_ARGS(_UNPAR(ARGS)));\
    \
    void* caller_##CLASS##_##FUNC(void* (*func)(), void* self, va_list *args){ \
        _IMPORT_VARS(_UNPAR(ARGS)) \
        \
        long long endLongLong = va_arg(*args, long long); \
        long long endLongDouble = va_arg(*args, long double); \
        long long endDouble = va_arg(*args, double); \
        \
        if (endLongLong != FUNC_END_LONG_LONG \
                || endLongDouble != FUNC_END_LONG_DOUBLE \
                || endDouble != FUNC_END_DOUBLE){ \
            printf("\nERROR: Wrong types used in method\n"); \
            assert(0); \
        } \
        \
        return func(self VAR_NAMES(_UNPAR(ARGS))); \
    }
#define single_build_func(CLASS, FUNC, ARGS) _HELPER_single_buildFunc(CLASS, FUNC, ARGS)

#define single_build_caller_funcs(FUNC) \
    void* _##FUNC (void* self, ...){ \
        cast(Object(), self); \
        va_list args; \
        /* NOTE: If something funky happens here, try swapping getClass() for super() */ \
        const struct Class* selfClass = getClass(self); \
        \
        /* NOTE: We are assuming that caller_ctor if the first function every classes list of functions */ \
        int bytesSearched =  (long)&selfClass->_ctor - (long)selfClass; \
        int totalSize = sizeOf(selfClass); \
        \
        void** funcPtr = &selfClass->_ctor; \
        \
        while(*funcPtr != _##FUNC){ \
            /* Jumping to the next caller (2 pointers away) */ \
            funcPtr += 3; \
            bytesSearched += 3; \
            \
            if (bytesSearched > totalSize){ \
                assert(0 /* Object's class does not have this method */); \
            } \
        } \
        \
        /* Jumping to actual function */ \
        funcPtr += 1; \
        void* (*callerFunc)() = *funcPtr; \
        funcPtr += 1; \
        void* (*thisFunc)() = *funcPtr; \
        \
        va_start(args, self); \
        void* result = callerFunc(thisFunc, self, &args); \
        va_end(args);\
        return result; \
    } \
    void* _##super##_##FUNC (struct Class* class, void* self, ...){ \
        cast(Class(), self); \
        va_list args; \
        /* NOTE: If something funky happens here, try swapping getClass() for super() */ \
        const struct Class* superClass = super(class); \
        \
        /* NOTE: We are assuming that caller_ctor if the first function every classes list of functions */ \
        int bytesSearched =  (long)&superClass->_ctor - (long)superClass; \
        int totalSize = sizeOf(superClass); \
        \
        void** funcPtr = &superClass->_ctor; \
        \
        while(*funcPtr != _##FUNC){ \
            /* Jumping to the next caller (2 pointers away) */ \
            funcPtr += 3; \
            bytesSearched += 3; \
            \
            if (bytesSearched > totalSize){ \
                assert(0 /* Object's class does not have this method */); \
            } \
        } \
        \
        /* Jumping to actual function */ \
        funcPtr += 1; \
        void* (*callerFunc)() = *funcPtr; \
        funcPtr += 1; \
        void* (*thisFunc)() = *funcPtr; \
        \
        va_start(args, self); \
        return callerFunc(thisFunc, self, &args); \
    }

#define _OBJ_TYPE(var) _Generic(((var)0), \
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
    char*: Ptr, \
    short*: Ptr, \
    int*: Ptr, \
    long long*: Ptr, \
    float*: Ptr, \
    long double*: Ptr)

#define single_addVar(CLASS, TYPE, VAR) \
    assert(!_hasFunc(selfBaseClass->dataGet, _get_##VAR) /* Already has variable */); \
    argsSize++; \
    tempDataGet = malloc((argsSize * sizeof(void*)) + sizeof(void*)); \
    tempDataOffsets = malloc((argsSize * sizeof(int)) + sizeof(int)); \
    tempDataSizes = malloc((argsSize * sizeof(int)) + sizeof(int)); \
    memcpy(tempDataGet + 1, selfBaseClass->dataGet, argsSize * sizeof(void*)); \
    memcpy(tempDataOffsets + 1, selfBaseClass->dataOffsets, argsSize * sizeof(int)); \
    memcpy(tempDataSizes + 1, selfBaseClass->dataSizes, argsSize * sizeof(int)); \
    tempDataGet[0] = _get_##VAR; \
    tempDataOffsets[0] = offsetof(struct CLASS, VAR); \
    tempDataSizes[0] = sizeof(TYPE); \
    free(selfBaseClass->dataGet); \
    free(selfBaseClass->dataOffsets); \
    free(selfBaseClass->dataSizes); \
    selfBaseClass->dataGet = tempDataGet; \
    selfBaseClass->dataOffsets = tempDataOffsets; \
    selfBaseClass->dataSizes = tempDataSizes; \

#define single_startFunc(CLASS, FUNC, ARGUMENTS) \
    classPtr->_##FUNC = _##FUNC; \
    classPtr->caller_##FUNC = caller_##CLASS##_##FUNC;

#define single_buildOverloader(FUNC, NOT_USED_ARGUMENTS) \
    else if (selector == _##FUNC){ \
        classPtr->this_##FUNC = function; \
    } \

#define single_buildAbstract(FUNC, NOT_USED_ARGUMENTS) \
    || classPtr->this_##FUNC == abstract

/** END Single helper functions **/

#define build_decl_get(VAR) void _get_##VAR(void* self, void* target, unsigned int targetSize)
#define build_decl_set(VAR) void _set_##VAR(void* self, void* target, unsigned int targetSize)

/** START Internal helper functions **/
int _arrayPtrSize(void** ptr);
bool _hasFunc(void** ptr, void* func);
/** END Internal helper functions **/


/** START User helper functions **/
#define _HELPER_object_build_getset(...) FOREACH(single_object_build_getset, ##__VA_ARGS__)
#define object_build_getset(...) _HELPER_object_build_getset(__VA_ARGS__)




#define object_builder_caller(RET_TYPE, FUNC, TYPED_ARGS, ARGS) \
    single_object_build_caller(RET_TYPE, FUNC, TYPED_ARGS, ARGS) \
    single_object_build_super_caller(RET_TYPE, FUNC, (const struct Class* class, _UNPAR(TYPED_ARGS)), ARGS)

#define user_call(RET_TYPE, FUNC, ...) (*((RET_TYPE*)_##FUNC(self, ##__VA_ARGS__, FUNC_END)))

#define _HELPER_buildFunc(args) FOREACH(single_build_func, args)
#define build_funcs(CLASS, ...) _HELPER_buildFunc(FOREACH_ADD_ARG(CLASS, ##__VA_ARGS__))

#define build_caller_funcs(...) FOREACH(single_build_caller_funcs, ##__VA_ARGS__)

/**
 * Used to add variable tracking data to the class
 */
#define _HELPER_addVars(args) FOREACH(single_addVar, args)
#define _HELPER_2_addVars(CLASS, ...) _HELPER_addVars(FOREACH_ADD_ARG(CLASS, ##__VA_ARGS__))
#define addVars(CLASS, ...) _HELPER_2_addVars(CLASS _EMPTY_REMOVER(__VA_ARGS__))

/**
 * Used to add function tracking data to the functions
 */
#define _HELPER_startFuncs(args) FOREACH(single_startFunc, args)
#define _HELPER_2_startFuncs(CLASS, ...) _HELPER_startFuncs(FOREACH_ADD_ARG(CLASS, ##__VA_ARGS__))
#define startFuncs(CLASS, ...) _HELPER_2_startFuncs(CLASS _EMPTY_REMOVER(__VA_ARGS__))

#define _HELPER_buildOverloaders(...) FOREACH(single_buildOverloader, ##__VA_ARGS__)
#define buildOverloaders(...) _HELPER_buildOverloaders(__VA_ARGS__)

#define _HELPER_buildAbstracts(...) FOREACH(single_buildAbstract, ##__VA_ARGS__)
#define buildAbstracts(...) _HELPER_buildAbstracts(__VA_ARGS__)

#define build_class_ctor(CLASS, VARS, FUNCS) \
void* CLASS##Class_ctor(void* self, va_list* args){ \
    struct CLASS##Class* classPtr = super_ctor(ExampleClass(), self, args); \
    \
    struct Class* selfBaseClass = classPtr; \
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1; \
    void** tempDataGet; \
    int* tempDataOffsets; \
    int* tempDataSizes; \
    \
    addVars(CLASS, _UNPAR(VARS)) \
    \
    typedef void (*voidf)(); /* generic function pointer */ \
    voidf selector; \
    va_list funcArgs; \
    \
    startFuncs(CLASS, _UNPAR(FUNCS)) \
    \
    va_copy(funcArgs, *args); \
    /* Overloadable function setup. All functions that go here can be overloaded */ \
    while((selector = va_arg(funcArgs, voidf))){ \
        voidf function = va_arg(funcArgs, voidf); \
        \
        if (false){ \
        \
        } \
        buildOverloaders(_UNPAR(FUNCS)) \
    } \
    va_end(funcArgs); \
    \
    if (false buildAbstracts(_UNPAR(FUNCS))){ \
    \
        struct Class* class = classPtr; \
        class->abstract = true; \
    } \
    \
    return self; \
}

/** END User helper functions **/

#endif // OOC_PREPROCESSOR_H
