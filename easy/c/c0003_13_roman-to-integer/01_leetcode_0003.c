/*
	13. Roman to Integer
	Given a roman numeral, convert it to an integer.

	Input is guaranteed to be within the range from 1 to 3999.
*/

#if 0/* Function Declaration and Function Prototypes on leetcode */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int romanToInt(char* s) {

}
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>


#include<time.h>


#include<limits.h>
#include<math.h>



/* import kernel list in user space */
#include"list.h"



char *roman[]={
"I", "V", "X", "L", "C", "D", "M",
"I", "II", "III", "IIII", "V", "VI", "VII", "VIII", "VIIII", "X",
"IV", "IX",
"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C",
"XL"/*40*/, "XC"/*90*/,
"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M",
"XXXIX"/*39*/, "CCXLVI"/*246*/, "CCVII"/*207*/, "MLXVI"/*1066*/,
};



char *roman_1_1000[] = {
"I", "CI", "CCI", "CCCI", "CDI", "DI", "DCI", "DCCI", "DCCCI", "CMI", 
"II", "CII", "CCII", "CCCII", "CDII", "DII", "DCII", "DCCII", "DCCCII", "CMII", 
"III", "CIII", "CCIII", "CCCIII", "CDIII", "DIII", "DCIII", "DCCIII", "DCCCIII", "CMIII", 
"IV", "CIV", "CCIV", "CCCIV", "CDIV", "DIV", "DCIV", "DCCIV", "DCCCIV", "CMIV", 
"V", "CV", "CCV", "CCCV", "CDV", "DV", "DCV", "DCCV", "DCCCV", "CMV", 
"VI", "CVI", "CCVI", "CCCVI", "CDVI", "DVI", "DCVI", "DCCVI", "DCCCVI", "CMVI", 
"VII", "CVII", "CCVII", "CCCVII", "CDVII", "DVII", "DCVII", "DCCVII", "DCCCVII", "CMVII", 
"VIII", "CVIII", "CCVIII", "CCCVIII", "CDVIII", "DVIII", "DCVIII", "DCCVIII", "DCCCVIII", "CMVIII", 
"IX", "CIX", "CCIX", "CCCIX", "CDIX", "DIX", "DCIX", "DCCIX", "DCCCIX", "CMIX", 
"X", "CX", "CCX", "CCCX", "CDX", "DX", "DCX", "DCCX", "DCCCX", "CMX", 
"XI", "CXI", "CCXI", "CCCXI", "CDXI", "DXI", "DCXI", "DCCXI", "DCCCXI", "CMXI", 
"XII", "CXII", "CCXII", "CCCXII", "CDXII", "DXII", "DCXII", "DCCXII", "DCCCXII", "CMXII", 
"XIII", "CXIII", "CCXIII", "CCCXIII", "CDXIII", "DXIII", "DCXIII", "DCCXIII", "DCCCXIII", "CMXIII", 
"XIV", "CXIV", "CCXIV", "CCCXIV", "CDXIV", "DXIV", "DCXIV", "DCCXIV", "DCCCXIV", "CMXIV", 
"XV", "CXV", "CCXV", "CCCXV", "CDXV", "DXV", "DCXV", "DCCXV", "DCCCXV", "CMXV", 
"XVI", "CXVI", "CCXVI", "CCCXVI", "CDXVI", "DXVI", "DCXVI", "DCCXVI", "DCCCXVI", "CMXVI", 
"XVII", "CXVII", "CCXVII", "CCCXVII", "CDXVII", "DXVII", "DCXVII", "DCCXVII", "DCCCXVII", "CMXVII", 
"XVIII", "CXVIII", "CCXVIII", "CCCXVIII", "CDXVIII", "DXVIII", "DCXVIII", "DCCXVIII", "DCCCXVIII", "CMXVIII", 
"XIX", "CXIX", "CCXIX", "CCCXIX", "CDXIX", "DXIX", "DCXIX", "DCCXIX", "DCCCXIX", "CMXIX", 
"XX", "CXX", "CCXX", "CCCXX", "CDXX", "DXX", "DCXX", "DCCXX", "DCCCXX", "CMXX", 
"XXI", "CXXI", "CCXXI", "CCCXXI", "CDXXI", "DXXI", "DCXXI", "DCCXXI", "DCCCXXI", "CMXXI", 
"XXII", "CXXII", "CCXXII", "CCCXXII", "CDXXII", "DXXII", "DCXXII", "DCCXXII", "DCCCXXII", "CMXXII", 
"XXIII", "CXXIII", "CCXXIII", "CCCXXIII", "CDXXIII", "DXXIII", "DCXXIII", "DCCXXIII", "DCCCXXIII", "CMXXIII", 
"XXIV", "CXXIV", "CCXXIV", "CCCXXIV", "CDXXIV", "DXXIV", "DCXXIV", "DCCXXIV", "DCCCXXIV", "CMXXIV", 
"XXV", "CXXV", "CCXXV", "CCCXXV", "CDXXV", "DXXV", "DCXXV", "DCCXXV", "DCCCXXV", "CMXXV", 
"XXVI", "CXXVI", "CCXXVI", "CCCXXVI", "CDXXVI", "DXXVI", "DCXXVI", "DCCXXVI", "DCCCXXVI", "CMXXVI", 
"XXVII", "CXXVII", "CCXXVII", "CCCXXVII", "CDXXVII", "DXXVII", "DCXXVII", "DCCXXVII", "DCCCXXVII", "CMXXVII", 
"XXVIII", "CXXVIII", "CCXXVIII", "CCCXXVIII", "CDXXVIII", "DXXVIII", "DCXXVIII", "DCCXXVIII", "DCCCXXVIII", "CMXXVIII", 
"XXIX", "CXXIX", "CCXXIX", "CCCXXIX", "CDXXIX", "DXXIX", "DCXXIX", "DCCXXIX", "DCCCXXIX", "CMXXIX", 
"XXX", "CXXX", "CCXXX", "CCCXXX", "CDXXX", "DXXX", "DCXXX", "DCCXXX", "DCCCXXX", "CMXXX", 
"XXXI", "CXXXI", "CCXXXI", "CCCXXXI", "CDXXXI", "DXXXI", "DCXXXI", "DCCXXXI", "DCCCXXXI", "CMXXXI", 
"XXXII", "CXXXII", "CCXXXII", "CCCXXXII", "CDXXXII", "DXXXII", "DCXXXII", "DCCXXXII", "DCCCXXXII", "CMXXXII", 
"XXXIII", "CXXXIII", "CCXXXIII", "CCCXXXIII", "CDXXXIII", "DXXXIII", "DCXXXIII", "DCCXXXIII", "DCCCXXXIII", "CMXXXIII", 
"XXXIV", "CXXXIV", "CCXXXIV", "CCCXXXIV", "CDXXXIV", "DXXXIV", "DCXXXIV", "DCCXXXIV", "DCCCXXXIV", "CMXXXIV", 
"XXXV", "CXXXV", "CCXXXV", "CCCXXXV", "CDXXXV", "DXXXV", "DCXXXV", "DCCXXXV", "DCCCXXXV", "CMXXXV", 
"XXXVI", "CXXXVI", "CCXXXVI", "CCCXXXVI", "CDXXXVI", "DXXXVI", "DCXXXVI", "DCCXXXVI", "DCCCXXXVI", "CMXXXVI", 
"XXXVII", "CXXXVII", "CCXXXVII", "CCCXXXVII", "CDXXXVII", "DXXXVII", "DCXXXVII", "DCCXXXVII", "DCCCXXXVII", "CMXXXVII", 
"XXXVIII", "CXXXVIII", "CCXXXVIII", "CCCXXXVIII", "CDXXXVIII", "DXXXVIII", "DCXXXVIII", "DCCXXXVIII", "DCCCXXXVIII", "CMXXXVIII", 
"XXXIX", "CXXXIX", "CCXXXIX", "CCCXXXIX", "CDXXXIX", "DXXXIX", "DCXXXIX", "DCCXXXIX", "DCCCXXXIX", "CMXXXIX", 
"XL", "CXL", "CCXL", "CCCXL", "CDXL", "DXL", "DCXL", "DCCXL", "DCCCXL", "CMXL", 
"XLI", "CXLI", "CCXLI", "CCCXLI", "CDXLI", "DXLI", "DCXLI", "DCCXLI", "DCCCXLI", "CMXLI", 
"XLII", "CXLII", "CCXLII", "CCCXLII", "CDXLII", "DXLII", "DCXLII", "DCCXLII", "DCCCXLII", "CMXLII", 
"XLIII", "CXLIII", "CCXLIII", "CCCXLIII", "CDXLIII", "DXLIII", "DCXLIII", "DCCXLIII", "DCCCXLIII", "CMXLIII", 
"XLIV", "CXLIV", "CCXLIV", "CCCXLIV", "CDXLIV", "DXLIV", "DCXLIV", "DCCXLIV", "DCCCXLIV", "CMXLIV", 
"XLV", "CXLV", "CCXLV", "CCCXLV", "CDXLV", "DXLV", "DCXLV", "DCCXLV", "DCCCXLV", "CMXLV", 
"XLVI", "CXLVI", "CCXLVI", "CCCXLVI", "CDXLVI", "DXLVI", "DCXLVI", "DCCXLVI", "DCCCXLVI", "CMXLVI", 
"XLVII", "CXLVII", "CCXLVII", "CCCXLVII", "CDXLVII", "DXLVII", "DCXLVII", "DCCXLVII", "DCCCXLVII", "CMXLVII", 
"XLVIII", "CXLVIII", "CCXLVIII", "CCCXLVIII", "CDXLVIII", "DXLVIII", "DCXLVIII", "DCCXLVIII", "DCCCXLVIII", "CMXLVIII", 
"XLIX", "CXLIX", "CCXLIX", "CCCXLIX", "CDXLIX", "DXLIX", "DCXLIX", "DCCXLIX", "DCCCXLIX", "CMXLIX", 
"L", "CL", "CCL", "CCCL", "CDL", "DL", "DCL", "DCCL", "DCCCL", "CML", 
"LI", "CLI", "CCLI", "CCCLI", "CDLI", "DLI", "DCLI", "DCCLI", "DCCCLI", "CMLI", 
"LII", "CLII", "CCLII", "CCCLII", "CDLII", "DLII", "DCLII", "DCCLII", "DCCCLII", "CMLII", 
"LIII", "CLIII", "CCLIII", "CCCLIII", "CDLIII", "DLIII", "DCLIII", "DCCLIII", "DCCCLIII", "CMLIII", 
"LIV", "CLIV", "CCLIV", "CCCLIV", "CDLIV", "DLIV", "DCLIV", "DCCLIV", "DCCCLIV", "CMLIV", 
"LV", "CLV", "CCLV", "CCCLV", "CDLV", "DLV", "DCLV", "DCCLV", "DCCCLV", "CMLV", 
"LVI", "CLVI", "CCLVI", "CCCLVI", "CDLVI", "DLVI", "DCLVI", "DCCLVI", "DCCCLVI", "CMLVI", 
"LVII", "CLVII", "CCLVII", "CCCLVII", "CDLVII", "DLVII", "DCLVII", "DCCLVII", "DCCCLVII", "CMLVII", 
"LVIII", "CLVIII", "CCLVIII", "CCCLVIII", "CDLVIII", "DLVIII", "DCLVIII", "DCCLVIII", "DCCCLVIII", "CMLVIII", 
"LIX", "CLIX", "CCLIX", "CCCLIX", "CDLIX", "DLIX", "DCLIX", "DCCLIX", "DCCCLIX", "CMLIX", 
"LX", "CLX", "CCLX", "CCCLX", "CDLX", "DLX", "DCLX", "DCCLX", "DCCCLX", "CMLX", 
"LXI", "CLXI", "CCLXI", "CCCLXI", "CDLXI", "DLXI", "DCLXI", "DCCLXI", "DCCCLXI", "CMLXI", 
"LXII", "CLXII", "CCLXII", "CCCLXII", "CDLXII", "DLXII", "DCLXII", "DCCLXII", "DCCCLXII", "CMLXII", 
"LXIII", "CLXIII", "CCLXIII", "CCCLXIII", "CDLXIII", "DLXIII", "DCLXIII", "DCCLXIII", "DCCCLXIII", "CMLXIII", 
"LXIV", "CLXIV", "CCLXIV", "CCCLXIV", "CDLXIV", "DLXIV", "DCLXIV", "DCCLXIV", "DCCCLXIV", "CMLXIV", 
"LXV", "CLXV", "CCLXV", "CCCLXV", "CDLXV", "DLXV", "DCLXV", "DCCLXV", "DCCCLXV", "CMLXV", 
"LXVI", "CLXVI", "CCLXVI", "CCCLXVI", "CDLXVI", "DLXVI", "DCLXVI", "DCCLXVI", "DCCCLXVI", "CMLXVI", 
"LXVII", "CLXVII", "CCLXVII", "CCCLXVII", "CDLXVII", "DLXVII", "DCLXVII", "DCCLXVII", "DCCCLXVII", "CMLXVII", 
"LXVIII", "CLXVIII", "CCLXVIII", "CCCLXVIII", "CDLXVIII", "DLXVIII", "DCLXVIII", "DCCLXVIII", "DCCCLXVIII", "CMLXVIII", 
"LXIX", "CLXIX", "CCLXIX", "CCCLXIX", "CDLXIX", "DLXIX", "DCLXIX", "DCCLXIX", "DCCCLXIX", "CMLXIX", 
"LXX", "CLXX", "CCLXX", "CCCLXX", "CDLXX", "DLXX", "DCLXX", "DCCLXX", "DCCCLXX", "CMLXX", 
"LXXI", "CLXXI", "CCLXXI", "CCCLXXI", "CDLXXI", "DLXXI", "DCLXXI", "DCCLXXI", "DCCCLXXI", "CMLXXI", 
"LXXII", "CLXXII", "CCLXXII", "CCCLXXII", "CDLXXII", "DLXXII", "DCLXXII", "DCCLXXII", "DCCCLXXII", "CMLXXII", 
"LXXIII", "CLXXIII", "CCLXXIII", "CCCLXXIII", "CDLXXIII", "DLXXIII", "DCLXXIII", "DCCLXXIII", "DCCCLXXIII", "CMLXXIII", 
"LXXIV", "CLXXIV", "CCLXXIV", "CCCLXXIV", "CDLXXIV", "DLXXIV", "DCLXXIV", "DCCLXXIV", "DCCCLXXIV", "CMLXXIV", 
"LXXV", "CLXXV", "CCLXXV", "CCCLXXV", "CDLXXV", "DLXXV", "DCLXXV", "DCCLXXV", "DCCCLXXV", "CMLXXV", 
"LXXVI", "CLXXVI", "CCLXXVI", "CCCLXXVI", "CDLXXVI", "DLXXVI", "DCLXXVI", "DCCLXXVI", "DCCCLXXVI", "CMLXXVI", 
"LXXVII", "CLXXVII", "CCLXXVII", "CCCLXXVII", "CDLXXVII", "DLXXVII", "DCLXXVII", "DCCLXXVII", "DCCCLXXVII", "CMLXXVII", 
"LXXVIII", "CLXXVIII", "CCLXXVIII", "CCCLXXVIII", "CDLXXVIII", "DLXXVIII", "DCLXXVIII", "DCCLXXVIII", "DCCCLXXVIII", "CMLXXVIII", 
"LXXIX", "CLXXIX", "CCLXXIX", "CCCLXXIX", "CDLXXIX", "DLXXIX", "DCLXXIX", "DCCLXXIX", "DCCCLXXIX", "CMLXXIX", 
"LXXX", "CLXXX", "CCLXXX", "CCCLXXX", "CDLXXX", "DLXXX", "DCLXXX", "DCCLXXX", "DCCCLXXX", "CMLXXX", 
"LXXXI", "CLXXXI", "CCLXXXI", "CCCLXXXI", "CDLXXXI", "DLXXXI", "DCLXXXI", "DCCLXXXI", "DCCCLXXXI", "CMLXXXI", 
"LXXXII", "CLXXXII", "CCLXXXII", "CCCLXXXII", "CDLXXXII", "DLXXXII", "DCLXXXII", "DCCLXXXII", "DCCCLXXXII", "CMLXXXII", 
"LXXXIII", "CLXXXIII", "CCLXXXIII", "CCCLXXXIII", "CDLXXXIII", "DLXXXIII", "DCLXXXIII", "DCCLXXXIII", "DCCCLXXXIII", "CMLXXXIII", 
"LXXXIV", "CLXXXIV", "CCLXXXIV", "CCCLXXXIV", "CDLXXXIV", "DLXXXIV", "DCLXXXIV", "DCCLXXXIV", "DCCCLXXXIV", "CMLXXXIV", 
"LXXXV", "CLXXXV", "CCLXXXV", "CCCLXXXV", "CDLXXXV", "DLXXXV", "DCLXXXV", "DCCLXXXV", "DCCCLXXXV", "CMLXXXV", 
"LXXXVI", "CLXXXVI", "CCLXXXVI", "CCCLXXXVI", "CDLXXXVI", "DLXXXVI", "DCLXXXVI", "DCCLXXXVI", "DCCCLXXXVI", "CMLXXXVI", 
"LXXXVII", "CLXXXVII", "CCLXXXVII", "CCCLXXXVII", "CDLXXXVII", "DLXXXVII", "DCLXXXVII", "DCCLXXXVII", "DCCCLXXXVII", "CMLXXXVII", 
"LXXXVIII", "CLXXXVIII", "CCLXXXVIII", "CCCLXXXVIII", "CDLXXXVIII", "DLXXXVIII", "DCLXXXVIII", "DCCLXXXVIII", "DCCCLXXXVIII", "CMLXXXVIII", 
"LXXXIX", "CLXXXIX", "CCLXXXIX", "CCCLXXXIX", "CDLXXXIX", "DLXXXIX", "DCLXXXIX", "DCCLXXXIX", "DCCCLXXXIX", "CMLXXXIX", 
"XC", "CXC", "CCXC", "CCCXC", "CDXC", "DXC", "DCXC", "DCCXC", "DCCCXC", "CMXC", 
"XCI", "CXCI", "CCXCI", "CCCXCI", "CDXCI", "DXCI", "DCXCI", "DCCXCI", "DCCCXCI", "CMXCI", 
"XCII", "CXCII", "CCXCII", "CCCXCII", "CDXCII", "DXCII", "DCXCII", "DCCXCII", "DCCCXCII", "CMXCII", 
"XCIII", "CXCIII", "CCXCIII", "CCCXCIII", "CDXCIII", "DXCIII", "DCXCIII", "DCCXCIII", "DCCCXCIII", "CMXCIII", 
"XCIV", "CXCIV", "CCXCIV", "CCCXCIV", "CDXCIV", "DXCIV", "DCXCIV", "DCCXCIV", "DCCCXCIV", "CMXCIV", 
"XCV", "CXCV", "CCXCV", "CCCXCV", "CDXCV", "DXCV", "DCXCV", "DCCXCV", "DCCCXCV", "CMXCV", 
"XCVI", "CXCVI", "CCXCVI", "CCCXCVI", "CDXCVI", "DXCVI", "DCXCVI", "DCCXCVI", "DCCCXCVI", "CMXCVI", 
"XCVII", "CXCVII", "CCXCVII", "CCCXCVII", "CDXCVII", "DXCVII", "DCXCVII", "DCCXCVII", "DCCCXCVII", "CMXCVII", 
"XCVIII", "CXCVIII", "CCXCVIII", "CCCXCVIII", "CDXCVIII", "DXCVIII", "DCXCVIII", "DCCXCVIII", "DCCCXCVIII", "CMXCVIII", 
"XCIX", "CXCIX", "CCXCIX", "CCCXCIX", "CDXCIX", "DXCIX", "DCXCIX", "DCCXCIX", "DCCCXCIX", "CMXCIX", 
"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M", 
};


int Roman_numerals(char r)
{
	switch (r)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default :
		return -1;
	}

}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int romanToInt(char* s) {
	/* sanity check */
	int d = Roman_numerals(s[0]);
	if (-1 == d)
	{
		return -1;
	}

	int i = 0;
	for (i=1; '\0' != s[i]; i++)
	{
		/* sanity check */
		int high = Roman_numerals(s[i-1]);
		int low  = Roman_numerals(s[i]);

		if (high < low)
		{
			d = d - high + (low - high);
		}
		else
		{
			d += low;
		}
	}

	return d;
}


void printTime(void)
{
	/* sanity check */
	time_t rawtime;
	struct tm *timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	printf ( "\n Current date and time is : %s\n", asctime (timeinfo) );
}


static union
{
	char c[4];
	unsigned long l;
} endian_test = {'l', '?', '?', 'b'};

#define ENDIANNESS ((char)endian_test.l)

void dprint_platform(void)
{
	/* sanity check */

	fprintf(stderr, "  int8_t = %ld \n", sizeof(int8_t));
	fprintf(stderr, " uint8_t = %ld \n", sizeof(uint8_t));
	fprintf(stderr, " int16_t = %ld \n", sizeof(int16_t));
	fprintf(stderr, "uint16_t = %ld \n", sizeof(uint16_t));
	fprintf(stderr, " int32_t = %ld \n", sizeof(int32_t));
	fprintf(stderr, "uint32_t = %ld \n", sizeof(uint32_t));
	fprintf(stderr, " int64_t = %ld \n", sizeof(int64_t));
	fprintf(stderr, "uint64_t = %ld \n", sizeof(uint64_t));


	fprintf(stderr, "ENDIANNESS=%c \n", ENDIANNESS);



	int n = 0x04030201;
	if (*(char *)&n == 0x01)
	{
		fprintf(stderr, "little endian\n");
	}
	else
	{
		fprintf(stderr, "   big endian\n");
	}


	fprintf(stderr, "\n\n");
}



void test_list(void)
{
	typedef struct
	{
		struct list_head entry;
		int data;
	
	}STACK_T;

	/* sanity check */
	fprintf(stderr, "\n[%s]%s : %d, enter \n\n",  __TIME__" "__DATE__, __FILE__, __LINE__);


	LIST_HEAD(stack);
	STACK_T *e = NULL;
	int i=0;

	for (i=0; i<10; i++)
	{
		e = (STACK_T *)malloc(sizeof(STACK_T));
		if(NULL == e)
		{
			fprintf(stderr, "malloc failed!");
			return;
		}
		e->data = (i + 1);
		list_add(&(e->entry), &stack);
		fprintf(stderr, "[%d]data=%d\n", i, (e->data));
	}

	if (list_empty(&stack))
	{
		fprintf(stderr, "list_empty\n");
	}

	fprintf(stderr, "\n dump stack \n");
	i = 0;
	list_for_each_entry(e, &stack, entry)
	{
		fprintf(stderr, "[%d]data=%d\n", i, (e->data));
		i++;
	}


	fprintf(stderr, "\n reverse dump stack \n");
	i = 0;
	list_for_each_entry_reverse(e, &stack, entry)
	{
		fprintf(stderr, "[%d]data=%d\n", i, (e->data));
		i++;
	}


	fprintf(stderr, "\n free stack \n");
	i=0;
	struct list_head *pos, *next;
	list_for_each_safe(pos, next, &stack)
	{
		e = list_entry(pos, STACK_T, entry);
		fprintf(stderr, "[%d]data=%d\n", i, (e->data));

		list_del_init(pos);
		free(e);
		e=NULL;
		i++;
	}


	fprintf(stderr, "\n[%s]%s : %d, leave \n\n",  __TIME__" "__DATE__, __FILE__, __LINE__);
}



int main( int argc, char *argv[] )
{
	/* sanity check */
	fprintf(stderr, "\n[%s]%s : %d, enter \n\n",  __TIME__" "__DATE__, __FILE__, __LINE__);
	printTime();


	struct timespec start,end;	/* seconds and nanoseconds */
	clock_gettime(CLOCK_MONOTONIC, &start);
	fprintf(stderr, "\n [start]%lu, %lu \n\n",  start.tv_sec, start.tv_nsec);

	time_t s,e;
	s=time(NULL);



	/* add your codes here */
	//dprint_platform();
	//test_list();




/* gcc -o test 01_leetcode_0003.c -lm ; ./test */


	int index = 0;
	int size = sizeof(roman)/sizeof(roman[0]);
	for (index=0; index<size; index++)
	{
		int d = romanToInt(roman[index]);
		fprintf(stderr, "%s [convert to] %d \n\n", roman[index], d);
	}

	size = sizeof(roman_1_1000)/sizeof(roman_1_1000[0]);
	for (index=0; index<size; index++)
	{
		int d = romanToInt(roman_1_1000[index]);
		fprintf(stderr, "%s [convert to] %d \n\n", roman_1_1000[index], d);
	}







#if 0/* disable 'no operation' */
	int i = 0;
	for(i=0;i<0xCFFFFFFF;i++)
	{
		//fprintf(stderr, "*");
		asm("nop ; nop ; nop ; nop");
	}
#endif


	e=time(NULL);
	fprintf(stderr, "\n Worked time is : %6.6f\n\n",difftime(e, s));


	clock_gettime(CLOCK_MONOTONIC, &end);
	fprintf(stderr, "\n [  end]%lu, %lu \n\n",  end.tv_sec, end.tv_nsec);


	printTime();



	fprintf(stderr, "\n[%s]%s : %d, leave \n\n",  __TIME__" "__DATE__, __FILE__, __LINE__);
	return 0;
}
