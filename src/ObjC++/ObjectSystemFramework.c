/*
 * ObjectSystemFramework.c
 *
 *  Created on: June 19, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#include "../../headers/ObjC++/ObjectSystemFramework.h"

RTTI OBJECT_RTTI = "Object";
RTTI NIL_RTTI = "Nil";

class* init_class(RTTI rtti, method* meth, class* parent, int state_size)
{
	class* to_return = (class*)malloc(sizeof(class));

	to_return->parent = parent;

	to_return->vtable = meth;
	init_state(to_return,state_size);

	to_return->rtti = rtti;

	to_return->this = to_return;

	return to_return;
}

void dest_class(class* cls)
{
	//The assumption is that the destructor was called prior to this operation
	// the class' state was supposed to be freed prior to the execution of this function
	// using the destructor
	dest_state(cls);

	free(cls);
}

void add_method(class* cls, method meth, int loc)
{
	cls->vtable[loc] = meth;
}

void init_state(class* cls, int size)
{
	cls->state = (state*)malloc(sizeof(state) * size);
}

void add_state(class* cls, state stt, int loc)
{
	cls->state[loc] = stt;
}

void dest_state(class* cls)
{
	free(cls->state);
}

Bool* instanceof(RTTI rtti, class* obj)
{
	Bool* to_return = &false;

	while (to_return == &false && obj != NULL)
	{
		if (RTTI(obj) == rtti)
			to_return = &true;
		else
			return instanceof(rtti,obj->parent);
	}

	return to_return;
}

