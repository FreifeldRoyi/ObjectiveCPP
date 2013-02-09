/*
 * Number.c
 *
 *  Created on: July 20, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#include "../../headers/ObjC++/Number.h"

RTTI NUMBER_RTTI = "Number"; /*!< Number's RTTI definition */

method number_method[] =	/*!< The method table of Number */
{
	{&number_ctor_int},
	{&number_ctor_double},
	{&number_dtor},
	{&number_add},
	{&number_sub},
	{&number_mul},
	{&number_div},
	{&number_c_double},
	{&number_c_int}
};

/*! \fn ctor
 *  \param val - the value state
 *  \param num_type - the type of the Number created
 *  \return a pointer to a new Number object
 *  \brief an helping function for the two constructors
 *
 *  This is actually a constructor by itself.
 *  By dividing the construction into two functions, I hid the
 *  	implementation from the user
 */
Number* ctor(state val, int num_type)
{
	Number* to_return = init_class(NUMBER_RTTI,number_method,&Object,NUMBER_NUM_OF_STATE);

	add_state(to_return,val,NUMBER_VALUE);

	state type;
	type.value.uint = num_type;

	add_state(to_return,type,NUMBER_TYPE);

	return to_return;
}

Number* number_ctor_int(int value)
{
	state val;
	val.value.sint = value;

	return ctor(val,NUMBER_INTEGER);
}

Number* number_ctor_double(double value)
{
	state val;
	val.value.dbl = value;

	return ctor(val,NUMBER_DOUBLE);
}

void number_dtor(Number* self)
{
	dest_class(self);
}

/*! \fn number_math_operations
 *  \param self - "this" object
 *  \param other - an object
 *  \param val - the value to be set as state of the object about to be created
 *  \return a new Number object
 *  \brief this function decides whether to create a NUMBER_INTEGER object or a NUMBER_DOUBLE object
 */
Number* number_math_operations(Number* self, Number* other, double val)
{
	Number* to_return = &Nil;

	if (GET_UINT_STATE(self,NUMBER_TYPE) == NUMBER_DOUBLE ||
			//The next line is more of a hack into the class.
			//There should be a getter to the type of the class but then the implementation of Number won't be encapsulated.
			//Read Number.h comment of the number_type_e enum
			GET_UINT_STATE(other,NUMBER_TYPE) == NUMBER_DOUBLE)
	{
		to_return = number_ctor_double(val);
	}
	else
	{
		to_return = number_ctor_int((int)val);
	}

	return to_return;
}

Number* number_add(Number* self, Number* other)
{
	return number_math_operations(self,other,number_c_double(self) + NUM_C_DOUBLE(other));
}

Number* number_sub(Number* self, Number* other)
{
	 return number_math_operations(self,other,number_c_double(self) - NUM_C_DOUBLE(other));
}

Number* number_mul(Number* self, Number* other)
{
	return number_math_operations(self,other,number_c_double(self) * NUM_C_DOUBLE(other));
}

Number* number_div(Number* self, Number* other)
{
	Number* to_return = &Nil;

	double val = NUM_C_DOUBLE(self) / NUM_C_DOUBLE(other);

	if (val - ((int)val) == 0) //type checking
	{
		to_return = number_ctor_int((int)val);
	}
	else
	{
		to_return = number_ctor_double(val);
	}

	return to_return;
}

double number_c_double(Number* self)
{
	double to_return;

	if (GET_UINT_STATE(self,NUMBER_TYPE) == NUMBER_DOUBLE)
	{
		to_return = GET_DOUBLE_STATE(self,NUMBER_VALUE);
	}
	else
	{
		to_return = GET_SINT_STATE(self,NUMBER_VALUE);
	}

	return to_return;
}

int number_c_int(Number* self)
{
	int to_return;

	if (GET_UINT_STATE(self,NUMBER_TYPE) == NUMBER_DOUBLE)
	{
		to_return = (int)GET_DOUBLE_STATE(self,NUMBER_VALUE); //just to make sure it is an int
	}
	else
	{
		to_return = GET_SINT_STATE(self,NUMBER_VALUE);
	}

	return to_return;
}
