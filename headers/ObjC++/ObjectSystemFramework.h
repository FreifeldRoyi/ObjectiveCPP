/*
 * ObjectSystemFramework.h
 *
 *  Created on: June 19, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#ifndef OBJECTSYSTEMFRAMEWORK_H_
#define OBJECTSYSTEMFRAMEWORK_H_

#include <stdlib.h>

/*! \typedef type
 *  \union _type ObjectSystemFramework.h "headers/ObjC++/ObjectSystemFramework.h"
 *  \brief This type union, represents all types available to hold as a state of a class
 */
typedef union _type
{
	char schar;
	unsigned char uchar;
	int sint;
	unsigned int uint;
	short sshort;
	unsigned short ushort;
	long slong;
	unsigned long ulong;
	float flt;
	double dbl;
	char* str;
	void* pointer;
} type;

/*! \typedef method
 *  \struct _method_t ObjectSystemFramework.h "headers/ObjC++/ObjectSystemFramework.h"
 *  \brief The method data structure
 */
typedef struct _method_t
{
	//char* name;
	//char* parameters;
	void* function;
} method;

/*! \typedef state
 *  \struct _state_t ObjectSystemFramework.h "headers/ObjC++/ObjectSystemFramework.h"
 *  \brief The state data structure
 */
typedef struct _state_t
{
	//char* name; //Although not supposed to appear once compiling a C++ program
	type value;
} state;

/*! \typedef RTTI
 *  \brief The RTTI of the classes
 */
typedef char* RTTI;

/*! \typedef class
 *  \struct _class_t ObjectSystemFramework.h "headers/ObjC++/ObjectSystemFramework.h"
 *  \brief The class data structure
 */
typedef struct _class_t
{
	struct _class_t* parent;	/*!< a pointer to the parent class */

	method* vtable;				/*!< a pointer to an array of methods - the vtable */
	state* state;				/*!< a pointer to an array of states */

	RTTI rtti;					/*!< the class' RTTI */
	struct _class_t* this;		/*!< self reference - not really used in this system, but.. oh well.. */
} class;

/*! \def RTTI(obj)
 * 	\brief a getter to the RTTI field
 */
#define RTTI(obj) obj->rtti

/* Framework classes */
// NOTE: Each RTTI defined in this section is declared as static just to have a constant address
//			thus ensuring a O(1) complexity while checking for the run-time type
//			see the instanceOf function
// NOTE2: This object system hierarchy is built as follows -
//				    ________
//                 |_Object_|
//                     ^
//       ______________|_________________________________
//    __|___    ____|______    ___|____    ___|____    __|__
//   |_Bool_|  |_Character_|  |_Number_|  |_String_|  |_Nil_|
//

RTTI OBJECT_RTTI;	/*!< The RTTI of the Object class */
RTTI NIL_RTTI;		/*!< The RTTI of the Nil class */

class Object;		/*!< The singleton Object class */
class Nil;			/*!< The singleton Nil class */

typedef class Bool;	/*!< \typedef Bool */
RTTI TRUE_RTTI;		/*!< The RTTI of the true class */
RTTI FALSE_RTTI;	/*!< The RTTI of the false class */
Bool true;			/*!< The singleton true class */
Bool false;			/*!< The singleton false class */


typedef class String;		/*!< \typedef String */
RTTI STRING_RTTI;			/*!< \typedef The RTTI of the String class */

typedef class Character;	/*!< \typedef Character */
RTTI CHARACTER_RTTI;		/*!< The RTTI of the Character class */

typedef class Number;		/*!< \typedef Number */
RTTI NUMBER_RTTI;			/*!< The RTTI of the Number class */
/* end framework classes */

/* Class framework functions */
// These framework function are supposed to be hidden and not be used by the user,
// 		They are related to the implementation itself and this is why the functions' parameters
//			are not classes but primitive types.

/*! \fn init_class
 * 	\param rtti - The class' RTTI
 * 	\param meth - The vtable
 * 	\param parent - The class' parent
 * 	\param state_size - The size of the state array
 *  \return a new class
 *
 *  This function allocates enough space for a class according to the parameters
 *  	specified
 */
class* init_class(RTTI rtti, method* meth, class* parent, int state_size);

/*! \fn dest_class
 *  \param cls - a pointer to a class needs to be destroyed
 *
 *  This is a framework function to remove all data allocated by the init_class function.
 *  All data allocated by the constructor of a specific class should be deleted in that class' destructor
 */
void dest_class(class* cls);

/*! \fn init_state
 * 	\param cls - The class whose state array needs to be initialized
 *  \param size - The size of the array
 *  \brief Allocates the space needed for the state array
 */
void init_state(class* cls, int size);

/*! \fn add_state
 * 	\param cls - The class
 * 	\param stt - The state to add
 * 	\param loc - The index to the state array
 *	\brief sets the state's data accrording to parameters specified
 */
void add_state(class* cls, state stt, int loc);

/*! \fn dest_state
 * 	\param cls - The class whose state array's memory is going to be freed
 *	\brief frees all data allocated by the init_state function
 *
 *	Note that all additional data allocated by the user should be freed BY THE USER
 */
void dest_state(class* cls);

/*! \fn instanceof
 *  \param rtti - The RTTI to check
 *  \param obj - The object to be checked
 *  \brief Checks for the type of the object in runtime
 *
 *	This function searches (until it reaches the Object object) if this class is
 *		of type rtti
 */
Bool* instanceof(RTTI rtti, class* obj);
/* end class framework functions */

//These definitions are used to extract value of a state easily
//NOTE: for object oriented behavior, it should be used only internally,
// 			meaning "inside" the class, and not on "other" classes
#define GET_SCHAR_STATE(cls,name) cls->state[name].value.schar
#define GET_UCHAR_STATE(cls,name) cls->state[name].value.uchar
#define GET_SINT_STATE(cls,name) cls->state[name].value.sint
#define GET_UINT_STATE(cls,name) cls->state[name].value.uint
#define GET_SSHORT_STATE(cls,name) cls->state[name].value.sshort
#define GET_USHORT_STATE(cls,name) cls->state[name].value.ushort
#define GET_SLONG_STATE(cls,name) cls->state[name].value.slong
#define GET_ULONG_STATE(cls,name) cls->state[name].value.ulong
#define GET_FLT_STATE(cls,name) cls->state[name].value.flt
#define GET_DOUBLE_STATE(cls,name) cls->state[name].value.dbl
#define GET_STR_STATE(cls,name) cls->state[name].value.str
#define GET_POINTER_STATE(cls,name) cls->state[name].value.pointer


/*! \def GET_METHOD(obj,idx) returns the method according to parameters specified */
#define GET_METHOD(obj,idx) (obj)->vtable[(idx)]

/*! \def GET_FUNCTION(obj,idx) returns the function pointer according to parameters specified */
#define GET_FUNCTION(obj,idx) GET_METHOD((obj),(idx)).function

/*! \def TO_FUNCTION(fn_type,obj,idx) casts the function pointer to a usable function according to parameters specified */
#define TO_FUNCTION(fn_type,obj,idx) ((fn_type)GET_FUNCTION((obj),(idx)))

#endif /* OBJECTSYSTEMFRAMEWORK_H_ */
