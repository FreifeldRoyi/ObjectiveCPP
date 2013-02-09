/*
 * example.c
 *
 *  Created on: July 16, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

//#include "../headers/Example/symbol.h"
#include "../headers/ObjC++/ObjectSystem.h"
#include "../headers/Example/ComplexNumber.h"
#include <stdio.h>
#include <string.h>

#define ASSERT_TRUE(bool)   											\
	do																		\
	{																		\
		printf("in line %d: ",__LINE__); 														\
		printf("bool pointer = %p (expected true = %p) : %d\n",bool,&true,bool==&true);	\
	} while(0)

#define ASSERT_FALSE(bool)   											\
	do																		\
	{																		\
		printf("in line %d: ",__LINE__);														\
		printf("bool pointer = %p (expected false = %p) : %d\n",bool,&false,bool==&false);	\
	} while(0)

void test_bool()
{
	Bool* bool = &true;

	Number* amount = number_ctor_int(1);

	printf("true pointer = %p\n",&true);
	printf("false pointer = %p\n\n",&false);

	printf("bool1 pointer = %p (true)\n\n",bool);

	//test not
	bool = BOOLEAN_NOT(bool);
	ASSERT_FALSE(bool);

	bool = BOOLEAN_NOT(bool);
	ASSERT_TRUE(bool);

	//test and
	bool = bool_and(&true,amount,&true);
	ASSERT_TRUE(bool);

	bool = bool_and(&true,amount,&false);
	ASSERT_FALSE(bool);

	bool = bool_and(&false,amount,&true);
	ASSERT_FALSE(bool);

	bool = bool_and(&false,amount,&false);
	ASSERT_FALSE(bool);

	//test or
	bool = bool_or(&true,amount,&true);
	ASSERT_TRUE(bool);

	bool = bool_or(&true,amount,&false);
	ASSERT_TRUE(bool);

	bool = bool_or(&false,amount,&true);
	ASSERT_TRUE(bool);

	bool = bool_or(&false,amount,&false);
	ASSERT_FALSE(bool);

	NUM_DTOR(amount);
}

void test_char()
{
	Character* ch_a1 = character_ctor('a');
	Character* ch_a2 = character_ctor('a');
	Character* ch_b1 = character_ctor('b');

	ASSERT_TRUE(CHAR_EQUAL(ch_a1,ch_a2));
	ASSERT_FALSE(CHAR_EQUAL(ch_b1,ch_a1));

	printf("expecting char 'a' from ch_a1: %d\n",'a'==CHAR_C_CHAR(ch_a1));
	printf("expecting char 'a' from ch_a2: %d\n",'a'==CHAR_C_CHAR(ch_a2));
	printf("expecting char 'b' from ch_b1: %d\n",'b'==CHAR_C_CHAR(ch_b1));

	CHAR_DTOR(ch_a1);
	CHAR_DTOR(ch_a2);
	CHAR_DTOR(ch_b1);
}

void test_num()
{
	Number* n_10 = number_ctor_int(10);
	Number* n_5_5 = number_ctor_double(5.5);

	printf("expecting 10 : %d\n",NUM_C_INT(n_10)==10);
	printf("expecting 10 : %d\n",NUM_C_DOUBLE(n_10)==10);
	printf("expecting 5 : %d\n",NUM_C_INT(n_5_5)==5);
	printf("expecting 5.5 : %d\n",NUM_C_DOUBLE(n_5_5)==5.5);

	Number* n_10a5_5 = NUM_ADD(n_10,n_5_5);
	Number* n_5_5a10 = NUM_ADD(n_5_5,n_10);
	printf("expecting 15.5 : %d\n",NUM_C_DOUBLE(n_10a5_5) == 15.5);
	printf("expecting 15.5 : %d\n",NUM_C_DOUBLE(n_5_5a10) == 15.5);

	Number* n_55 = NUM_MUL(n_10,n_5_5);
	printf("expecting 55 : %d\n",NUM_C_INT(n_55) == 55);

	Number* n_10d5_5 = NUM_DIV(n_10,n_5_5);
	printf("expecting %f : %d\n",10/5.5,NUM_C_DOUBLE(n_10d5_5) == (10/5.5));

	Number* n_5_5d10 = NUM_DIV(n_5_5,n_10);
	printf("expecting 0.55 : %d\n",NUM_C_DOUBLE(n_5_5d10) == 0.55);

	NUM_DTOR(n_10);
	NUM_DTOR(n_5_5);
	NUM_DTOR(n_10a5_5);
	NUM_DTOR(n_5_5a10);
	NUM_DTOR(n_55);
	NUM_DTOR(n_10d5_5);
	NUM_DTOR(n_5_5d10);
}

void test_string()
{
	String* str = string_ctor("this is a test string");
	printf("expected \"this is a test string\", got: \"%s\": %d\n",STR_C_STR(str),0==strcmp("this is a test string",STR_C_STR(str)));

	Number* size = STR_SIZE(str);
	printf("expected %d: %d\n",strlen("this is a test string"),strlen("this is a test string") == NUM_C_INT(size));

	String* str2 = string_ctor(", this is a catenation string");
	String* str3 = STR_CAT(str,str2);
	printf("expected \"this is a test string, this is a catenation string\", got: \"%s\": %d\n",STR_C_STR(str3),0==strcmp("this is a test string, this is a catenation string",STR_C_STR(str3)));

	Number* idx = number_ctor_int(8);
	Character* ch = STR_CHAR_AT(str,idx);
	printf("expecting char 'a' from ch: %d\n",'a'==CHAR_C_CHAR(ch));

	Character* ch2 = character_ctor('A');
	String* str4 = STR_PUT_CHAR(str,ch2,idx);
	printf("expected \"this is A test string\", got: \"%s\": %d\n",STR_C_STR(str4),0==strcmp("this is A test string",STR_C_STR(str4)));

	String* str5 = STR_SUBSTRING(str,idx,size);
	printf("expected \"a test string\", got: \"%s\": %d\n",STR_C_STR(str5),0==strcmp("a test string",STR_C_STR(str5)));

	Number* double_idx1 = number_ctor_double(8.7);
	Number* double_idx2 = number_ctor_double(21.3);
	Number* double_idx3 = number_ctor_double(22);
	Character* ch3 = STR_CHAR_AT(str,double_idx1);
	printf("expecting char 'a' from ch: %d\n",'a'==CHAR_C_CHAR(ch3));

	Character* ch4 = STR_CHAR_AT(str,double_idx2);
	printf("expecting Nil pointer = %p, got %p: %d\n",&Nil,ch4,ch4==&Nil);

	Number* neg_idx = number_ctor_int(-45);
	ch4 = STR_CHAR_AT(str,neg_idx);
	printf("expecting Nil pointer = %p, got %p: %d\n",&Nil,ch4,ch4==&Nil);

	String* str6 = STR_SUBSTRING(str,double_idx1,double_idx2);
	printf("expected \"a test string\", got: \"%s\": %d\n",STR_C_STR(str6),0==strcmp("a test string",STR_C_STR(str6)));

	String* str7 = STR_SUBSTRING(str,double_idx1,double_idx3);
	printf("expecting Nil pointer = %p, got %p: %d\n",&Nil,str7,str7==&Nil);

	String* str8 = STR_SUBSTRING(str,neg_idx,double_idx1);
	printf("expecting Nil pointer = %p, got %p: %d\n",&Nil,str8,str8==&Nil);

	STR_DTOR(str);
	STR_DTOR(str2);
	STR_DTOR(str3);
	STR_DTOR(str4);
	STR_DTOR(str5);
	STR_DTOR(str6);

	NUM_DTOR(size);
	NUM_DTOR(idx);
	NUM_DTOR(double_idx1);
	NUM_DTOR(double_idx2);
	NUM_DTOR(double_idx3);
	NUM_DTOR(neg_idx);

	CHAR_DTOR(ch);
	CHAR_DTOR(ch2);
	CHAR_DTOR(ch3);
}

void test_complex_number()
{
	Number* real = number_ctor_int(4);
	Number* img = number_ctor_int(5);
	ComplexNumber* cmp1 = complex_num_ctor(real,img);
	ComplexNumber* cmp2 = complex_num_ctor(real,img);

	NUM_DTOR(real);
	NUM_DTOR(img);

	printf("(4+5i) + (4+5i)\n");
	ComplexNumber* cmp1Acmp2 = COMPLEX_NUM_ADD(cmp1,cmp2);
	real = COMPLEX_NUM_REAL(cmp1Acmp2);
	img = COMPLEX_NUM_IMG(cmp1Acmp2);
	printf("Result of add operation is: real = %f, img = %f\n",NUM_C_DOUBLE(real),NUM_C_DOUBLE(img));
	NUM_DTOR(real);
	NUM_DTOR(img);

	printf("(4+5i) - (4+5i)\n");
	ComplexNumber* cmp1Scmp2 = COMPLEX_NUM_SUB(cmp1,cmp2);
	real = COMPLEX_NUM_REAL(cmp1Scmp2);
	img = COMPLEX_NUM_IMG(cmp1Scmp2);
	printf("Result of sub operation is: real = %f, img = %f\n",NUM_C_DOUBLE(real),NUM_C_DOUBLE(img));
	NUM_DTOR(real);
	NUM_DTOR(img);

	printf("(4+5i) * (4+5i)\n");
	ComplexNumber* cmp1Mcmp2 = COMPLEX_NUM_MUL(cmp1,cmp2);
	real = COMPLEX_NUM_REAL(cmp1Mcmp2);
	img = COMPLEX_NUM_IMG(cmp1Mcmp2);
	printf("Result of mul operation is: real = %f, img = %f\n",NUM_C_DOUBLE(real),NUM_C_DOUBLE(img));
	NUM_DTOR(real);
	NUM_DTOR(img);

	ComplexNumber* cmp1Dcmp2 = COMPLEX_NUM_DIV(cmp1,cmp2);
	real = COMPLEX_NUM_REAL(cmp1Dcmp2);
	img = COMPLEX_NUM_IMG(cmp1Dcmp2);
	printf("Result of div operation is: real = %f, img = %f\n",NUM_C_DOUBLE(real),NUM_C_DOUBLE(img));
	NUM_DTOR(real);
	NUM_DTOR(img);

	COMPLEX_NUM_DTOR(cmp1);
	COMPLEX_NUM_DTOR(cmp2);
	COMPLEX_NUM_DTOR(cmp1Acmp2);
	COMPLEX_NUM_DTOR(cmp1Scmp2);
	COMPLEX_NUM_DTOR(cmp1Mcmp2);
	COMPLEX_NUM_DTOR(cmp1Dcmp2);
}

int main()
{
	init_object_system();

	printf("Nil pointer = %p\n",&Nil);
	printf("Object pointer = %p\n\n",&Object);
	test_bool();
	test_char();
	test_num();
	test_string();

	test_complex_number();

	return 0;
}
