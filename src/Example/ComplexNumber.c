/*
 * ComplexNumber.c
 *
 *  Created on: Jul 20, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#include "../../headers/Example/ComplexNumber.h"

#include "../../headers/ObjC++/Number.h"

RTTI COMPLEXNUM_RTTI = "ComplexNumber";

method complex_number_method[] =
{
	{&complex_num_ctor},
	{&complex_num_dtor},
	{&complex_num_add},
	{&complex_num_sub},
	{&complex_num_mul},
	{&complex_num_div},
	{&complex_num_real},
	{&complex_num_img}
};

#define GET_REAL_STATE(self) (Number*)GET_POINTER_STATE(self,COMPLEX_NUMBER_REAL_VALUE)
#define GET_IMG_STATE(self) (Number*)GET_POINTER_STATE(self,COMPLEX_NUMBER_IMG_VALUE)

ComplexNumber* complex_num_ctor(Number* real, Number* img)
{
	//The complex number should be inheriting from the Number class
	ComplexNumber* to_return = init_class(COMPLEXNUM_RTTI,complex_number_method,&Object,COMPLEX_NUMBER_NUM_OF_STATE);

	Number* real_part = number_ctor_double(NUM_C_DOUBLE(real));
	Number* img_part = number_ctor_double(NUM_C_DOUBLE(img));

	state real_state;
	state img_state;
	real_state.value.pointer = real_part;
	img_state.value.pointer = img_part;

	add_state(to_return,real_state,COMPLEX_NUMBER_REAL_VALUE);
	add_state(to_return,img_state,COMPLEX_NUMBER_IMG_VALUE);

	return to_return;
}

void complex_num_dtor(ComplexNumber* self)
{
	NUM_DTOR(GET_REAL_STATE(self));
	NUM_DTOR(GET_IMG_STATE(self));
	dest_class(self);
}

ComplexNumber* complex_num_add(ComplexNumber* self, ComplexNumber* other)
{
	ComplexNumber* to_return = &Nil;

	Number* other_real = COMPLEX_NUM_REAL(other);
	Number* other_img = COMPLEX_NUM_IMG(other);

	Number* new_real = NUM_ADD(GET_REAL_STATE(self),other_real);
	Number* new_img = NUM_ADD(GET_IMG_STATE(self),other_img);

	to_return = complex_num_ctor(new_real,new_img);

	NUM_DTOR(other_real);
	NUM_DTOR(other_img);
	NUM_DTOR(new_real);
	NUM_DTOR(new_img);

	return to_return;
}

ComplexNumber* complex_num_sub(ComplexNumber* self, ComplexNumber* other)
{
	ComplexNumber* to_return = &Nil;

	Number* other_real = COMPLEX_NUM_REAL(other);
	Number* other_img = COMPLEX_NUM_IMG(other);

	Number* new_real = NUM_SUB(GET_REAL_STATE(self),other_real);
	Number* new_img = NUM_SUB(GET_IMG_STATE(self),other_img);

	to_return = complex_num_ctor(new_real,new_img);

	NUM_DTOR(other_real);
	NUM_DTOR(other_img);
	NUM_DTOR(new_real);
	NUM_DTOR(new_img);

	return to_return;
}

ComplexNumber* complex_num_mul(ComplexNumber* self, ComplexNumber* other)
{
	ComplexNumber* to_return = &Nil;

	Number* other_real = COMPLEX_NUM_REAL(other);
	Number* other_img = COMPLEX_NUM_IMG(other);

	//I chose the easier way to implement it by using the primitive values
	//	another way is to create a bunch of Number objects
	//	and use the math functions defined in Number.h
	Number* new_real =
			number_ctor_double(((NUM_C_DOUBLE(GET_REAL_STATE(self)) * NUM_C_DOUBLE(other_real)) -
							    (NUM_C_DOUBLE(GET_IMG_STATE(self)) * NUM_C_DOUBLE(other_img))));

	Number* new_img =
			number_ctor_double(((NUM_C_DOUBLE(GET_IMG_STATE(self)) * NUM_C_DOUBLE(other_real)) +
								(NUM_C_DOUBLE(GET_REAL_STATE(self)) * NUM_C_DOUBLE(other_img))));
	to_return = complex_num_ctor(new_real,new_img);

	NUM_DTOR(other_real);
	NUM_DTOR(other_img);
	NUM_DTOR(new_real);
	NUM_DTOR(new_img);

	return to_return;
}

ComplexNumber* complex_num_div(ComplexNumber* self, ComplexNumber* other)
{
	ComplexNumber* to_return = &Nil;

	Number* other_real = COMPLEX_NUM_REAL(other);
	Number* other_img = COMPLEX_NUM_IMG(other);

	//I chose the easier way to implement it by using the primitive values
	//	another way is to create a bunch of Number objects
	//	and use the math functions defined in Number.h
	double a = NUM_C_DOUBLE(GET_REAL_STATE(self));
	double b = NUM_C_DOUBLE(GET_IMG_STATE(self));
	double c = NUM_C_DOUBLE(other_real);
	double d = NUM_C_DOUBLE(other_img);
	double new_real_val = (double)(((a * c) + (b * d))) / ((c * c) + (d * d));
	double new_img_val = (double)(((b * c) - (a * d))) / ((c * c) + (d * d));
	Number* new_real = number_ctor_double(new_real_val);
	Number* new_img = number_ctor_double(new_img_val);

	to_return = complex_num_ctor(new_real,new_img);

	NUM_DTOR(other_real);
	NUM_DTOR(other_img);
	NUM_DTOR(new_real);
	NUM_DTOR(new_img);

	return to_return;
}

Number* complex_num_real(ComplexNumber* self)
{
	return number_ctor_double(NUM_C_DOUBLE(GET_REAL_STATE(self)));
}

Number* complex_num_img(ComplexNumber* self)
{
	return number_ctor_double(NUM_C_DOUBLE(GET_IMG_STATE(self)));
}
