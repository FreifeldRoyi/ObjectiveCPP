/*
 * String.h
 *
 *  Created on: July 18, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#ifndef STRING_H_
#define STRING_H_

#include "ObjectSystemFramework.h"

/*! \fn string_ctor
 *  \param value - a C lang string representation
 *  \return a pointer to a newly initialized String
 *  \brief Constructs a String object according to the given parameter
 *
 *  The value given is copied to another location in the memory,
 *  The data pointed to by value is NOT deallocated.
 */
String* string_ctor(char* value);

/*! \fn string_dtor
 *  \param self - "this" object
 *  \brief deallocated all internal memory associated with the object
 */
void string_dtor(String* self);

/*! \fn string_size
 *  \param self - "this" object
 *  \return a new Number object
 *  \brief returns the length of the string
 *
 *  Deallocation of the Number object returned is up to the user
 */
Number* string_size(String* self);

/*! \fn string_c_str
 *  \param self - "this" object
 *  \return a pointer to a c string
 *  \brief returns a c representation of this String
 *
 *  NOTE: The string returned is the string being held by this class.
 *  	  Meaning one can change this String object's value by changing
 *  		the c-string returned
 */
char* string_c_str(String* self);

/*! \fn string_cat
 * 	\param self - "this" object
 * 	\param other - the other string to catenate
 * 	\return a pointer to a new String
 *  \brief catenates the other String to this one
 */
String* string_cat(String* self, String* other);

/*! \fn string_char_at
 * 	\param self - "this" object
 * 	\param idx - an index
 *  \return a pointer to a new Character or a pointer to Nil
 *  \brief returns the Character appears in location idx in this String
 *
 *  If 0 <= idx < length, a Character object is returned
 *  	otherwise a pointer to Nil is returned.
 *  Deallocation of the Character object returned is up to the user
 */
Character* string_char_at(String* self, Number* idx);

/*! \fn string_put_char
 * 	\param self - "this" object
 * 	\param ch - a Character to put
 *  \param idx - an index
 *  \return a pointer to a new String or a pointer to Nil
 *  \brief puts a char in the given location
 *
 * If 0 <= idx < length, a new String object is returned
 * 		otherwise a pointer to Nil is returned.
 * Deallocation of the String is up to the user
 */
String* string_put_char(String* self, Character* ch, Number* idx);

/*! \fn string_substring
 *  \param self - "this" pointer
 *  \param strt_idx - an index
 *  \param end_idx - an index
 *  \return a pointer to a new String or a pointer to Nil
 *  \brief returns a substring of this string according to the given parameters
 *
 *  If 0 <= strt_idx < end_idx <= length, a new String is returned
 *  	otherwise a pointer to Nil is returned
 *  NOTE: substring returned includes the character pointed to by the strt_idx
 *  			and DOE'S NOT include the character pointed to by the end_idx
 *  Deallocation of the String is up to the user
 */
String* string_substring(String* self, Number* strt_idx, Number* end_idx);

/*! \enum string_method_e
 *	simulates the addresses to the vtable of String
 */
enum string_method_e
{
	STRING_CTOR,
	STRING_DTOR,
	STRING_SIZE,
	STRING_C_STR,
	STRING_CAT,
	STRING_CHAR_AT,
	STRING_PUT_CHAR,
	STRING_SUBSTRING,

	STRING_NUM_OF_METHODS
};

/*! \enum string_state_e
 *	simulates the addresses of the state of String
 */
enum string_state_e
{
	STRING_VALUE,
	STRING_LENGTH,

	STRING_NUM_OF_STATE
};

/*! \def STR_DTOR(self)
 * 	\brief the method call to the String's destructor
 */
#define STR_DTOR(self) TO_FUNCTION(void (*)(String*),self,STRING_DTOR)((self))

/*! \def STR_SIZE(self)
 * 	\brief the method call to the String's size method
 */
#define STR_SIZE(self) TO_FUNCTION(Number* (*)(String*),self,STRING_SIZE)((self))

/*! \def STR_C_STR(self)
 * 	\brief the method call to the String's c_str method
 */
#define STR_C_STR(self) TO_FUNCTION(char* (*)(String*),self,STRING_C_STR)((self))

/*! \def STR_CAT(self,other)
 * 	\brief the method call to the String's cat method
 */
#define STR_CAT(self,other) TO_FUNCTION(String* (*)(String*,String*),self,STRING_CAT)((self),(other))

/*! \def STR_CHAR_AT(self,idx)
 * 	\brief the method call to the String's char_at method
 */
#define STR_CHAR_AT(self,idx) TO_FUNCTION(Character* (*)(String*,Number*),self,STRING_CHAR_AT)((self),(idx))

/*! \def STR_PUT_CHAR(self,ch,idx)
 * 	\brief the method call to the String's put_char method
 */
#define STR_PUT_CHAR(self,ch,idx) TO_FUNCTION(String* (*)(String*,Character*,Number*),self,STRING_PUT_CHAR)((self),(ch),(idx))

/*! \def STR_SUBSTRING(self,strt_idx,end_idx)
 * 	\brief the method call to the String's substring method
 */
#define STR_SUBSTRING(self,strt_idx,end_idx) TO_FUNCTION(String* (*)(String*,Number*,Number*),self,STRING_SUBSTRING)((self),(strt_idx),(end_idx))

#endif /* STRING_H_ */
