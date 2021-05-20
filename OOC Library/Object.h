
#ifndef OOC_OBJECT_H
#define OOC_OBJECT_H

#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>
#include "OOCP.h"
#include "OOC_Essentials.h"


#define _OOC_MAX_ERROR_MESSAGE_SIZE 1024

/* Returns true if the pointer points to a class */
bool OOC_isClass(pointer ptr, long long line, char* file);
#define isClass(ptr) OOC_isClass(ptr(), __LINE__, __FILE__)
/* Returns true if the pointer points to a class */
bool OOC_isObject(pointer ptr, long long line, char* file);
#define isObject(ptr) OOC_isObject(ptr, __LINE__, __FILE__)
/* Returns true if the object is of that exact class */
bool OOC_ofClass(pointer self, struct OOC_Class* class, long long line, char* file);
#define ofClass(class, parent_class) OOC_ofClass(class(), parent_class(), __LINE__, __FILE__)
/* Returns true if the object is any subclass of that class */
bool OOC_instanceOfClass(pointer self, struct OOC_Class* class, long long line, char* file);
#define instanceOfClass(class, parent_class) OOC_instanceOfClass(class(), parent_class(), __LINE__, __FILE__)
/* Returns self if it can be casted into class, terminates the program otherwise */
pointer OOC_cast(struct OOC_Class* class, pointer self, long long line, char* file);
#define cast(class, self) OOC_cast(class(), self, __LINE__, __FILE__)
/**
 * @param self Object or Class
 * @return Class of self
 */
struct OOC_Class* OOC_getClass(pointer self, long long line, char* file);
#define getClass(self) OOC_getClass(self, __LINE__, __FILE__)
/* Returns the size of the object, when used in an object.
 * Returns the size of the subclass or object created when used in a class */
int OOC_sizeOf(pointer self, long long line, char* file);
#define sizeOf(self) OOC_sizeOf(self, __LINE__, __FILE__)

pointer OOC_callMethod(unsigned char* methodName, long long line, char* file, pointer self, ...);
#define _OOCP_PAIR_PARAM_KEY(val) OOCP_VAR_KEY(val),val
#define OOCP_MAKE_PARAM_KEYS(...) OOCP_VA_OPT(__VA_ARGS__)(,) OOCP_FOREACH(_OOCP_PAIR_PARAM_KEY, (,), __VA_ARGS__), OOCP_VAR_KEY_NULL
/* Generates key markings for function call.
** From something like "foo('a', 1, 1.2)" it generates 
** "foo(OOCP_VAR_KEY_CHAR, 'a', OOCP_VAR_KEY_INT, 1, OOCP_VAR_KEY_FLOAT, 1.2, OOCP_VAR_KEY_NULL)"".
*/
#define callMethod(name, self, ...) OOC_callMethod(name, __LINE__, __FILE__, self OOCP_MAKE_PARAM_KEYS(__VA_ARGS__))

pointer OOC_new(pointer class, long long line, char* file, ...);
#define new(class, ...) OOC_new(class(), __LINE__, __FILE__ OOCP_MAKE_PARAM_KEYS(__VA_ARGS__))

pointer OOC_automatic(pointer type, long long line, char* file, ...);
#define automatic(class, ...) OOC_automatic(class(), __LINE__, __FILE__ OOCP_MAKE_PARAM_KEYS(__VA_ARGS__))

pointer OOC_delete(pointer self, long long line, char* file);
#define delete(self) OOC_delete(self, __LINE__, __FILE__)
struct Object* OOC_copy(pointer self, long long line, char* file);

#define deepcopy(self, ...) callMethod("deepcopy", self, __VA_ARGS__)
#define equals(self, ...) callMethod("equals", self, __VA_ARGS__)

pointer OOC_fatalError(char* message, long long line, char* file);
#define error(...) OOC_fatalError( \
	OOCP_IIF( OOCP_IS_EMPTY(__VA_ARGS__) \
		,(NULL) \
		,(__VA_ARGS__) \
	) \
	, __LINE__, __FILE__\
)

long long _OOC_returning_buffer;
int _OOC_returning_key;
char _OOC_error_message[_OOC_MAX_ERROR_MESSAGE_SIZE];

/* Class builder */
pointer Object();

#endif //OOC_OBJECT_H
