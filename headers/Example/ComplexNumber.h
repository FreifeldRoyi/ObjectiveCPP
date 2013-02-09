/*
 * ComplexNumber.h
 *
 *  Created on: July 20, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#ifndef COMPLEXNUMBER_H_
#define COMPLEXNUMBER_H_

#include "../ObjC++/ObjectSystemFramework.h"

RTTI COMPLEXNUM_RTTI; /*!< The RTTI of the ComplexNumberr class */

typedef class ComplexNumber; /*! \typedef ComplexNumber */

/*! \fn complex_num_ctor
 *  \param real - The real part
 *  \param img - The imaginary part
 *  \return a pointer to ComplexNum
 *
 *  Note that the two parameters given are copied.
 *  They are NOT deallocated.
 */
ComplexNumber* complex_num_ctor(Number* real, Number* img);

/*! \fn complex_num_dtor
 *  \param self - "this" object
 *  \brief deallocates all internal memory associated with this object
 */
void complex_num_dtor(ComplexNumber* self);

/*! \fn complex_num_add
 *  \param self - "this" object
 *  \param other - an object to add
 *  \returns a new ComplexNumber
 *  \brief adds the other Complex number to this one
 */
ComplexNumber* complex_num_add(ComplexNumber* self, ComplexNumber* other);

/*! \fn complex_num_other
 *  \param self - "this" object
 *  \param other - an object to subtract
 *  \returns a new ComplexNumber
 *  \brief subtracts the other Complex number from this one
 */
ComplexNumber* complex_num_sub(ComplexNumber* self, ComplexNumber* other);

/*! \fn complex_num_mul
 *  \param self - "this" object
 *  \param other - an object to multiply
 *  \returns a new ComplexNumber
 *  \brief multiplies the other Complex number with this one
 */
ComplexNumber* complex_num_mul(ComplexNumber* self, ComplexNumber* other);

/*! \fn complex_num_div
 *  \param self - "this" object
 *  \param other - an object to multiply
 *  \returns a new ComplexNumber
 *  \brief performs a division between this object and the other Complex number
 */
ComplexNumber* complex_num_div(ComplexNumber* self, ComplexNumber* other);

/*! \fn complex_num_real
 * 	\param self - "this" object
 *  \returns a pointer to a new Number
 *  \brief returns the real part of this complex number
 */
Number* complex_num_real(ComplexNumber* self);

/*! \fn complex_num_img
 * 	\param self - "this" object
 *  \returns a pointer to a new Number
 *  \brief returns the imaginary part of this complex number
 */
Number* complex_num_img(ComplexNumber* self);

/*! \enum complex_num_method_e
 *	simulates the addresses to the vtable of ComplexNumber
 */
enum complex_num_method_e
{
	COMPLEX_NUMBER_CTOR,
	COMPLEX_NUMBER_DTOR,
	COMPLEX_NUMBER_ADD,
	COMPLEX_NUMBER_SUB,
	COMPLEX_NUMBER_MUL,
	COMPLEX_NUMBER_DIV,
	COMPLEX_NUMBER_REAL,
	COMPLEX_NUMBER_IMG,

	COMPLEX_NUMBER_NUM_OF_METHODS
};

/*! \enum complex_num_state_e
 *	simulates the addresses of the state of ComplexNumber
 */
enum complex_num_state_e
{
	COMPLEX_NUMBER_REAL_VALUE,
	COMPLEX_NUMBER_IMG_VALUE,

	COMPLEX_NUMBER_NUM_OF_STATE
};

/*! \def COMPLEX_NUM_DTOR(self)
 *  \brief the method call to the ComplexNumber's destructor
 */
#define COMPLEX_NUM_DTOR(self) TO_FUNCTION(void (*)(Number*),self,COMPLEX_NUMBER_DTOR)(self)

/*! \def COMPLEX_NUM_ADD(self,other)
 *  \brief the method call to the ComplexNumber's add method
 */
#define COMPLEX_NUM_ADD(self,other) TO_FUNCTION(ComplexNumber* (*)(Number*,Number*),self,COMPLEX_NUMBER_ADD)(self,other)

/*! \def COMPLEX_NUM_SUB(self,other)
 *  \brief the method call to the ComplexNumber's sub method
 */
#define COMPLEX_NUM_SUB(self,other) TO_FUNCTION(ComplexNumber* (*)(Number*,Number*),self,COMPLEX_NUMBER_SUB)(self,other)

/*! \def COMPLEX_NUM_MUL(self,other)
 *  \brief the method call to the ComplexNumber's mul method
 */
#define COMPLEX_NUM_MUL(self,other) TO_FUNCTION(ComplexNumber* (*)(Number*,Number*),self,COMPLEX_NUMBER_MUL)(self,other)

/*! \def COMPLEX_NUM_DIV(self,other)
 *  \brief the method call to the ComplexNumber's div method
 */
#define COMPLEX_NUM_DIV(self,other) TO_FUNCTION(ComplexNumber* (*)(Number*,Number*),self,COMPLEX_NUMBER_DIV)(self,other)

/*! \def COMPLEX_NUM_REAL(self)
 *  \brief the method call to the ComplexNumber's real getter
 */
#define COMPLEX_NUM_REAL(self) TO_FUNCTION(Number* (*)(Number*),self,COMPLEX_NUMBER_REAL)(self)

/*! \def COMPLEX_NUM_IMG(self)
 *  \brief the method call to the ComplexNumber's img getter
 */
#define COMPLEX_NUM_IMG(self) TO_FUNCTION(Number* (*)(Number*),self,COMPLEX_NUMBER_IMG)(self)

/*! \def COMPLEX_NUM_IMG(self)
 *  \brief the method call to the ComplexNumber's to_string method
 */
#define COMPLEX_NUM_TO_STRING(self) TO_FUNCTION(String* (*)(Number*),self,COMPLEX_NUMBER_TO_STRING)(self)

#endif /* COMPLEXNUMBER_H_ */
