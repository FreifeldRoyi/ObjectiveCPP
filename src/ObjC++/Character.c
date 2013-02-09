/*
 * Character.c
 *
 *  Created on: July 19, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#include "../../headers/ObjC++/Character.h"

RTTI CHARACTER_RTTI = "Character"; /*!< Character's RTTI definition */

method character_method[] = /*!< The method table of Character */
{
	{&character_ctor},
	{&character_dtor},
	{&character_equal},
	{&character_c_char}
};

Character* character_ctor(char value)
{
	Character *to_return = init_class(CHARACTER_RTTI,character_method,&Object,CHARACTER_NUM_OF_STATE);

	state val;
	val.value.schar = value;
	add_state(to_return,val,CHARACTER_VALUE);

	return to_return;
}

void character_dtor(Character* self)
{
	dest_class(self);
}

Bool* character_equal(Character* self, Character* other)
{
	Bool* to_return = &Nil;

	if (GET_SCHAR_STATE(self,CHARACTER_VALUE) == CHAR_C_CHAR(other))
	{
		to_return = &true;
	}
	else
	{
		to_return = &false;
	}

	return to_return;
}

char character_c_char(Character* self)
{
	return GET_SCHAR_STATE(self,CHARACTER_VALUE);
}
