/*
 * Number.h
 *
 *  Created on: July 19, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#ifndef NUMBER_H_
#define NUMBER_H_

#include "ObjectSystemFramework.h"

/*! \fn number_ctor_int
 *  \param value - construction parameter, will be saved as a state
 *  \return a pointer to a Number object created
 *  \brief constructs a Number object according to the given parameter
 *
 *  The Number created is tagComplexNum* ged with NUMBER_INTEGER type
 */
Number* number_ctor_int(int value);

/*! \fn number_ctor_double
 *  \param value - construction parameter, will be saved as a state
 *  \return a pointer to a Number object created
 *  \brief constructs a Number object according to the given parameter
 *
 *  The Number created is tagComplexNum* ged with NUMBER_DOUBLE type
 */
Number* number_ctor_double(double value);

/*! \fn number_dtor
 * 	\param self "this" object
 *	\brief deallocates all internal memory associated with the object
 */
void number_dtor(Number* self);

/*! \fn number_add
 * 	\param self "this" object
 * 	\param other - an object to add
 *	\brief adds the other Number to this one
 *	\returns a new Number object
 *
 *  If the result is an integer a NUMBER_INTEGER number is created
 *  	otherwise a NUMBER_DOUBLE is created
 */
Number* number_add(Number* self, Number* other);

/*! \fn number_sub
 * 	\param self "this" object
 * 	\param other - an object to add
 *	\brief subtracts the other Number from this one
 *	\returns a new Number object
 *
 *  If the result is an integer a NUMBER_INTEGER number is created
 *  	otherwise a NUMBER_DOUBLE is created
 */
Number* number_sub(Number* self, Number* other);

/*! \fn number_mul
 * 	\param self "this" object
 * 	\param other - an object to add
 *	\brief multiplies the other Number with this one
 *	\returns a new Number object
 *
 *  If the result is an integer a NUMBER_INTEGER number is created
 *  	otherwise a NUMBER_DOUBLE is created
 */
Number* number_mul(Number* self, Number* other);

/*! \fn number_div
 * 	\param self "this" object
 * 	\param other - an object to add
 *	\brief performs a division between this object and the other
 *	\returns a new Number object
 *
 *  If the result is an integer a NUMBER_INTEGER number is created
 *  	otherwise a NUMBER_DOUBLE is created
 */
Number* number_div(Number* self, Number* other);

/*! \fn number_c_double
 * 	\param self "this" object
 *	\brief returns the double value of this object
 *	\returns a primitive double
 */
double number_c_double(Number* self);

/*! \fn number_c_int
 * 	\param self "this" object
 *	\brief returns the int value of this object
 *	\returns a primitive int
 *
 *	NOTE: if this object is a double, the value returned is the whole part
 *			e.g. if this object's value is 6.7 then 6 is returned
 */
int number_c_int(Number* self);

/*! \enum number_method_e
 *	simulates the addresses to the vtable of Number
 */
enum number_method_e
{
	NUMBER_CTOR_INT,
	NUMBER_CTOR_DOUBLE,
	NUMBER_DTOR,
	NUMBER_ADD,
	NUMBER_SUB,
	NUMBER_MUL,
	NUMBER_DIV,
	NUMBER_C_DOUBLE,
	NUMBER_C_INT,

	NUMBER_NUM_OF_METHODS
};

/*! \enum number_state_e
 *	simulates the addresses of the state of Number
 */
enum number_state_e
{
	NUMBER_VALUE,
	NUMBER_TYPE,

	NUMBER_NUM_OF_STATE
};

//I know that a better way would be to create a static class for Number
// and inheriting classes for Integer and Double (etc..)
// but I gain nothing from it right now since I can't create a real vtable without
// a pre-processing mechanism or to change this object system to be dynamic.
enum number_type_e
{
	NUMBER_INTEGER,
	NUMBER_DOUBLE,

	NUMBER_NUM_OF_TYPES
};

/*! \def NUM_DTOR(self)
 *  \brief the method call to the Number's destructor
 */
#define NUM_DTOR(self) TO_FUNCTION(void (*)(Number*),self,NUMBER_DTOR)((self))

/*! \def NUM_ADD(self,other)
 *  \brief the method call to the Number's add method
 */
#define NUM_ADD(self,other) TO_FUNCTION(Number* (*)(Number*,Number*),self,NUMBER_ADD)((self),(other))

/*! \def NUM_SUB(self,other)
 *  \brief the method call to the Number's sub method
 */
#define NUM_SUB(self,other) TO_FUNCTION(Number* (*)(Number*,Number*),self,NUMBER_SUB)((self),(other))

/*! \def NUM_MUL(self,other)
 *  \brief the method call to the Number's mul method
 */
#define NUM_MUL(self,other) TO_FUNCTION(Number* (*)(Number*,Number*),self,NUMBER_MUL)((self),(other))

/*! \def NUM_DIV(self,other)
 *  \brief the method call to the Number's div method
 */
#define NUM_DIV(self,other) TO_FUNCTION(Number* (*)(Number*,Number*),self,NUMBER_DIV)((self),(other))

/*! \def NUM_C_DOUBLE(self)
 *  \brief the method call to the Number's c_double method
 */
#define NUM_C_DOUBLE(self) TO_FUNCTION(double (*)(Number*),self,NUMBER_C_DOUBLE)((self))

/*! \def NUM_C_INT(self)
 *  \brief the method call to the Number's c_int method
 */
#define NUM_C_INT(self) TO_FUNCTION(int (*)(Number*),self,NUMBER_C_INT)((self))

#endif /* NUMBER_H_ */
