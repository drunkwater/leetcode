// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//67. Add Binary
//Given two binary strings, return their sum (also a binary string).
//The input strings are both non-empty and contains only characters 1 or 0.
//Example 1:
//Input: a = "11", b = "1"
//Output: "100"
//Example 2:
//Input: a = "1010", b = "1011"
//Output: "10101"
//char* addBinary(char* a, char* b) {
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



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char* addBinary(char* a, char* b) {
	/* sanity check */
#define ZERO_CHAR ('0')
	int alen = strlen(a);
	int blen = strlen(b);

	char *p = NULL;
	char *s = NULL;/* pointer to the shorter string */
	int max = 0;
	int min = 0;
	if (alen>blen)
	{
		max = alen;
		min = blen;
		p = a;
		s = b;
	}
	else
	{
		max = blen;
		min = alen;
		p = b;
		s = a;
	}

	char *string = (char *)calloc(max+1, sizeof(char));
	char sum = ZERO_CHAR;
	int i = 0;
	int j = 0;
	int carray = 0;
	for (i = min-1; i >= 0; i--)
	{
		j = i + max-min;
		sum = (s[i]-ZERO_CHAR+p[j]-ZERO_CHAR) + carray;
		carray = sum/2;
		string[j] = sum%2 + ZERO_CHAR;
	}
	for (j = max-min-1; j >= 0; j--)
	{
		if (0 == carray)
		{
			string[j] = p[j];
		}
		else
		{
			sum = p[j]-ZERO_CHAR + carray;
			carray = sum/2;
			string[j] = sum%2 + ZERO_CHAR;
		}
	}

	if (1 == carray)
	{
		carray = 0;
		for (i = max-1; i >= 0; i--)
		{
			string[i+1] = string[i];
		}
		string[0] = 1 + ZERO_CHAR;
	}

	return string;
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



	char *p = addBinary("11", "1");
	if (0 == strcmp(p, "100"))
	{
		fprintf(stderr, "OK %s\n", p);
	}
	else
	{
		fprintf(stderr, "FAILED %s\n", p);
	}
	free(p);
	p = NULL;


	p = addBinary("0", "0");
	if (0 == strcmp(p, "0"))
	{
		fprintf(stderr, "OK %s\n", p);
	}
	else
	{
		fprintf(stderr, "FAILED %s\n", p);
	}
	free(p);
	p = NULL;

	p = addBinary("1100", "11");
	if (0 == strcmp(p, "1111"))
	{
		fprintf(stderr, "OK %s\n", p);
	}
	else
	{
		fprintf(stderr, "FAILED %s\n", p);
	}
	free(p);
	p = NULL;


	p = addBinary("1011", "1101");
	if (0 == strcmp(p, "11000"))
	{
		fprintf(stderr, "OK %s\n", p);
	}
	else
	{
		fprintf(stderr, "FAILED %s\n", p);
	}
	free(p);
	p = NULL;


	p = addBinary("11", "11");
	if (0 == strcmp(p, "110"))
	{
		fprintf(stderr, "OK %s\n", p);
	}
	else
	{
		fprintf(stderr, "FAILED %s\n", p);
	}
	free(p);
	p = NULL;







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
