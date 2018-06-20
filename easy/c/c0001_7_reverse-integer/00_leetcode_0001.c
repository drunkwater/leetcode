// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//7. Reverse Integer
//Given a 32-bit signed integer, reverse digits of an integer.
//Example 1:
//Input: 123
//Output: 321
//Example 2:
//Input: -123
//Output: -321
//Example 3:
//Input: 120
//Output: 21
//Note:
//Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//int reverse(int x) {
//}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>


#include<time.h>


#include<limits.h>
#include<math.h>



/* import kernel list in user space */
#include"list.h"


#include "data.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int64_t reverse(int x)
{
	/* sanity check */
	int64_t t = 0;

	while(0 != x)
	{
		/* overflow or underflow */
		if (t > INT64_MAX/10 || t < INT64_MIN/10)
		{
			return 0;
		}

		t = t*10 + x%10;
		x = x/10;
	}

	return t;
}


int64_t fast_atoi(const char *str, size_t len)
{
	int64_t value_ = 0;
	int sign = 1;
	if (str[0] == '-')
	{ // handle negative
		sign = -1;
		++str;
		--len;
	}


	if (10<=len)
	{
	/* INT_MAX=2147483647, INT_MIN=-2147483648 */
		//fprintf(stderr, "fast, string=%s, length=%ld \n", str, len);
	}

	switch (len)
	{
	case 20:	value_ += (str[len-20] - '0') * (10000000000000000000UL);
	case 19:	value_ += (str[len-19] - '0') * (1000000000000000000UL);
	case 18:	value_ += (str[len-18] - '0') * (100000000000000000UL);
	case 17:	value_ += (str[len-17] - '0') * (10000000000000000UL);
	case 16:	value_ += (str[len-16] - '0') * (1000000000000000UL);
	case 15:	value_ += (str[len-15] - '0') * (100000000000000UL);
	case 14:	value_ += (str[len-14] - '0') * (10000000000000UL);
	case 13:	value_ += (str[len-13] - '0') * (1000000000000UL);
	case 12:	value_ += (str[len-12] - '0') * (100000000000UL);
	case 11:	value_ += (str[len-11] - '0') * (10000000000UL);
	// handle up to 10 digits, assume we're 32-bit
	case 10:	value_ += (str[len-10] - '0') * (1000000000UL);
	case  9:	value_ += (str[len- 9] - '0') * (100000000UL);
	case  8:	value_ += (str[len- 8] - '0') * (10000000UL);
	case  7:	value_ += (str[len- 7] - '0') * (1000000UL);
	case  6:	value_ += (str[len- 6] - '0') * (100000UL);
	case  5:	value_ += (str[len- 5] - '0') * (10000UL);
	case  4:	value_ += (str[len- 4] - '0') * (1000UL);
	case  3:	value_ += (str[len- 3] - '0') * (100UL);
	case  2:	value_ += (str[len- 2] - '0') * (10UL);
	case  1:	value_ += (str[len- 1] - '0');
		value_ *= sign;
		return value_;
	default:
		return -1;
	}
}


int64_t reverse_test(int x)
{
	/* sanity check */
	char string[64] = {0};
	int length = 0;

	length = snprintf(string, sizeof(string), "%d", x);

	int max = length;
	int offset = 0;
	if('-' == string[0])
	{
		max = length-1;
		offset = 1;
	}

	int t = 0;
	int i = 0;
	for (; i<max/2; i++)
	{

		t = string[i + offset];
		string[i + offset] = string[length - i - 1];
		string[length - i - 1] = t;
	}
	string[length] = '\0';


	if (65535==x || INT_MAX==x || INT_MIN==x)
	{
		//fprintf(stderr, "string=%s, length=%d \n", string, length);
	}


	return fast_atoi(string, length);
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
} endian_test = {{'l', '?', '?', 'b'}};

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



	//fprintf(stderr, "INT_MAX=%d, INT_MIN=%d \r\n", INT_MAX, INT_MIN);
	//fprintf(stderr, "INT_MAX/10=%d, INT_MIN/10=%d \r\n", INT_MAX/10, INT_MIN/10);

	fprintf(stderr, "INT64_MAX=%ld, INT64_MIN=%ld \r\n", INT64_MAX, INT64_MIN);




	int64_t a = 0;
	int64_t b = 0;


#if 1//OK
	int index = 0;
	int size = sizeof(array_65535_0)/sizeof(array_65535_0[0]);

	for (index=0; index<size; index++)
	{
		a = reverse(array_65535_0[index]);
		b = reverse_test(array_65535_0[index]);
		if(a != b)
		{
			fprintf(stderr, "test failed!         index=%d\n", index);
			fprintf(stderr, "a=%ld, b=%ld \r\n", a, b);
			break;
		}
	}


	size = sizeof(negative_array_65535_0)/sizeof(negative_array_65535_0[0]);

	for (index=0; index<size; index++)
	{
		a = reverse(negative_array_65535_0[index]);
		b = reverse_test(negative_array_65535_0[index]);
		if(a != b)
		{
			fprintf(stderr, "test failed!         index2=%d\n", index);
			fprintf(stderr, "a=%ld, b=%ld \r\n", a, b);
			break;
		}
	}
#endif



	a = reverse(INT_MAX);
	b = reverse_test(INT_MAX);
	if(a != b)
	{
		fprintf(stderr, "###test failed! INT_MAX=%d\n", INT_MAX);
		fprintf(stderr, "a=%ld, b=%ld \r\n", a, b);
	}
	a = reverse(INT_MIN);
	b = reverse_test(INT_MIN);
	if(a != b)
	{
		fprintf(stderr, "###test failed! INT_MIN=%d\n", INT_MIN);
		fprintf(stderr, "a=%ld, b=%ld \r\n", a, b);
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
