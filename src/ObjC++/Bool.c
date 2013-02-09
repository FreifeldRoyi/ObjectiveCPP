/*
 * Bool.c
 *
 *  Created on: July 18, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#include "../../headers/ObjC++/Bool.h"
#include "../../headers/ObjC++/Number.h"

RTTI TRUE_RTTI = "True";	/*!< true's RTTI definition */
RTTI FALSE_RTTI = "False";	/*!< false's RTTI definition */

Bool* bool_not(Bool* self)
{
	Bool* to_return = &Nil;

	if (self == &true)
	{
		to_return = &false;
	}
	else if (self == &false)
	{
		to_return = &true;
	}

	return to_return;
}

Bool* bool_and(Bool* self, Number* amount, ...)
{
	va_list args;
	va_start(args,amount);
	Bool* to_return = self;

	int i = NUM_C_INT(amount);
	while (to_return == &true && i > 0)
	{
		to_return = va_arg(args,Bool*);
		--i;
	}

	va_end(args);
	return to_return;
}

Bool* bool_or(Bool* self, Number* amount, ...)
{
	va_list args;
	va_start(args,amount);
	Bool* to_return = self;

	int i = NUM_C_INT(amount);
	while (to_return != &true && i > 0)
	{
		to_return = va_arg(args,Bool*);
		--i;
	}

	va_end(args);
	return to_return;
}
