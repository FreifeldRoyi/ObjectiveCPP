/*
 * Bool.h
 *
 *  Created on: July 18, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#ifndef BOOL_H_
#define BOOL_H_

#include "ObjectSystemFramework.h"

#include <stdarg.h>

/*! \fn bool_not
 *	\param self - the object to apply the not operator to
 *	\return pointer to true, if self is false. A pointer to false otherwise
 *	\brief applies a not operator on the object
 */
Bool* bool_not(Bool* self);

/*! \fn bool_and
 *  \param self - the object to apply and operator to
 *  \param amount - the number of parameters in the variadic list
 *	\return pointer to true if all parameters are true, pointer to false otherwise
 */
Bool* bool_and(Bool* self, Number* amount, ...);

/*! \fn bool_or
 *  \param self - the object to apply or operator to
 *  \param amount - the number of parameters in the variadic list
 *  \return pointer to true if one of the arguments is true, pointer to false if all are false
 */
Bool* bool_or(Bool* self, Number* amount, ...);

/*! \enum bool_method_e
 *	simulates the addresses to the vtable of Bool
 */
enum bool_method_e
{
	BOOL_NOT,
	BOOL_AND,
	BOOL_OR,

	BOOL_NUM_OF_METHODS
};

/*! \def BOOLEAN_NOT(self)
 *  \brief the method call to the not operator
 */
#define BOOLEAN_NOT(self) TO_FUNCTION(Bool* (*)(Bool*),self,BOOL_NOT)((self))

#endif /* BOOL_H_ */
