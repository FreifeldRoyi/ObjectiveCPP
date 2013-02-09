/*
 * Character.h
 *
 *  Created on: July 19, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "ObjectSystemFramework.h"

/*! \fn character_ctor
 *  \param value - construction parameter, will be saved as a state
 *  \return a pointer to a Character object created
 *  \brief constructs a Character object according to the given parameter
 */
Character* character_ctor(char value);

/*! \fn character_dtor
 * 	\param self "this" object
 *	\brief deallocates all internal memory associated with the object
 */
void character_dtor(Character* self);

/*! \fn character_equal
 * 	\parameter self - "this" object
 * 	\parameter other - an object to compare to
 * 	\return a pointer to true if the two charaters are equal, false otherwise
 * 	\brief compares between the two characters
 */
Bool* character_equal(Character* self, Character* other);

/*! \fn character_c_char
 * 	\param self - "this" object
 * 	\return a char
 *  \brief returns the primitive char represented by this class
 */
char character_c_char(Character* self);

/*! \enum character_method_e
 *	simulates the addresses to the vtable of Character
 */
enum character_method_e
{
	CHARACTER_CTOR,
	CHARACTER_DTOR,
	CHARACTER_EQUAL,
	CHARACTER_C_CHAR,

	CHARACTER_NUM_OF_METHODS
};

/*! \enum character_state_e
 *	simulates the addresses of the state of Character
 */
enum character_state_e
{
	CHARACTER_VALUE,

	CHARACTER_NUM_OF_STATE
};

/*! \def CHAR_DTOR(self)
 *  \brief the method call to the Character's destructor
 */
#define CHAR_DTOR(self) TO_FUNCTION(void (*)(Character*),self,CHARACTER_DTOR)((self))

/*! \def CHAR_EQUAL(self,other)
 *  \brief the method call to the Character's equal method
 */
#define CHAR_EQUAL(self,other) TO_FUNCTION(Bool* (*)(Character*,Character*),self,CHARACTER_EQUAL)((self),(other))

/*! \def CHAR_C_CHAR(self)
 *  \brief the method call to the Character's c_char method
 */
#define CHAR_C_CHAR(self) TO_FUNCTION(char (*)(Character*),self,CHARACTER_C_CHAR)((self))

#endif /* CHARACTER_H_ */
