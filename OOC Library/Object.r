
#ifndef OOC_OBJECT_R
#define OOC_OBJECT_R

#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include "Object.h"



pointer OOC_newClass(struct OOC_Class* superClass, char* name, size_t size, long long line, char* file, ...);
#define newClass(super, ...) OOCP_NEW_CLASS_TEMPLATE(CLASS_NAME, super, __VA_ARGS__)
pointer OOC_callSuperMethod(long long line, char* file, pointer self, ...);
#define callSuperMethod(...) \
	OOC_callSuperMethod(__LINE__, __FILE__, self OOCP_MAKE_PARAM_KEYS(__VA_ARGS__))
/**
 * @param self Class
 * @return Super of the class
 */
struct OOC_Class* OOC_super(struct OOC_Class* class, long long line, char* file);
pointer OOC_abstract(pointer self, va_list *args);

#define ctor(self, ...) callMethod("ctor", self, __VA_ARGS__)
#define dtor(self, ...) callMethod("dtor", self, __VA_ARGS__)

pointer OOC_returning(pointer ptr, int size);
// TODO: add an automatic parameter definition for this

#endif //OOC_OBJECT_R
