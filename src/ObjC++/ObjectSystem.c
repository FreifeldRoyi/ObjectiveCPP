/*
 * ObjectSystem.c
 *
 *  Created on: July 18, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#include "../../headers/ObjC++/ObjectSystem.h"

method bool_method[] =
{
	{&bool_not},
	{&bool_and},
	{&bool_or}
};

void init_Nil()
{
	Nil.parent = &Object;
	Nil.vtable = NULL;
	Nil.state = NULL;
	Nil.rtti = NIL_RTTI;
	Nil.this = &Nil;
}

void init_Object()
{
	Object.parent = NULL;
	Object.vtable = NULL;
	Object.state = NULL;
	Object.rtti = OBJECT_RTTI;
	Object.this = &Object;
}

void init_true()
{
	true.parent = &Object;
	true.vtable = bool_method;
	true.state = NULL;
	true.rtti = TRUE_RTTI;
	true.this = &true;
}

void init_false()
{
	false.parent = &Object;
	false.vtable = bool_method;
	false.state = NULL;
	false.rtti = FALSE_RTTI;
	false.this = &false;
}

void init_object_system()
{
	init_Nil();
	init_Object();
	init_true();
	init_false();
}
