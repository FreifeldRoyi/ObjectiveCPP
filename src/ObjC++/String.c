/*
 * String.c
 *
 *  Created on: July 18, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#include "../../headers/ObjC++/String.h"
#include "../../headers/ObjC++/Character.h"
#include "../../headers/ObjC++/Number.h"

#include <string.h>

RTTI STRING_RTTI = "String";

method string_method[] =
{
	{&string_ctor},
	{&string_dtor},
	{&string_size},
	{&string_c_str},
	{&string_cat},
	{&string_char_at},
	{&string_put_char},
	{&string_substring}
};

String* string_ctor(char* value)
{
	String* to_return = init_class(STRING_RTTI,string_method,&Object,STRING_NUM_OF_STATE);

	char* new_val = (char*)malloc(strlen(value) + 1);
	strcpy(new_val,value);

	state val;
	val.value.str = new_val;
	add_state(to_return,val,STRING_VALUE);

	state len;
	len.value.sint = strlen(value);
	add_state(to_return,len,STRING_LENGTH);

	return to_return;
}

void string_dtor(String* self)
{
	free(STR_C_STR(self));
	dest_class(self);
}

Number* string_size(String* self)
{
	return number_ctor_int(GET_SINT_STATE(self,STRING_LENGTH));
}

char* string_c_str(String* self)
{
	return GET_STR_STATE(self,STRING_VALUE);
}

String* string_cat(String* self, String* other)
{
	String* to_return;

	Number* others_sz = STR_SIZE(other);

	char* new_val = (char*)malloc(GET_SINT_STATE(self,STRING_LENGTH) + NUM_C_INT(others_sz) + 1);
	strcpy(new_val,STR_C_STR(self));
	strcat(new_val,STR_C_STR(other));

	to_return = string_ctor(new_val);

	free(new_val);
	NUM_DTOR(others_sz);

	return to_return;
}

Character* string_char_at(String* self, Number* idx)
{
	Character* to_return = &Nil;
	char ch = 0;

	if (NUM_C_INT(idx) >= 0 && NUM_C_INT(idx) < GET_SINT_STATE(self,STRING_LENGTH))
	{
		ch = GET_STR_STATE(self,STRING_VALUE)[NUM_C_INT(idx)];
		to_return = character_ctor(ch);
	}

	return to_return;
}

String* string_put_char(String* self, Character* ch, Number* idx)
{
	String* to_return = &Nil;

	if (NUM_C_INT(idx) >= 0 && NUM_C_INT(idx) < GET_SINT_STATE(self,STRING_LENGTH))
	{
		char new_str[GET_SINT_STATE(self,STRING_LENGTH) + 1];
		strcpy(new_str,GET_STR_STATE(self,STRING_VALUE));
		new_str[NUM_C_INT(idx)] = CHAR_C_CHAR(ch);
		to_return = string_ctor(new_str);
	}

	return to_return;
}

String* string_substring(String* self, Number* strt_idx, Number* end_idx)
{
	String* to_return = &Nil;

	if (0 <= NUM_C_INT(strt_idx) &&
			NUM_C_INT(strt_idx) < NUM_C_INT(end_idx) &&
			NUM_C_INT(end_idx) <= GET_SINT_STATE(self,STRING_LENGTH))
	{
		to_return = string_ctor(&GET_STR_STATE(self,STRING_VALUE)[NUM_C_INT(strt_idx)]);
	}

	return to_return;
}
