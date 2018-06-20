// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//28. Implement strStr()
//Implement strStr().
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//Example 1:
//Input: haystack = "hello", needle = "ll"
//Output: 2
//Example 2:
//Input: haystack = "aaaaa", needle = "bba"
//Output: -1
//Clarification:
//What should we return when needle is an empty string? This is a great question to ask during an interview.
//For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
//int strStr(char* haystack, char* needle) {
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

int strStr(char* haystack, char* needle) {
	/* sanity check */
	if (NULL==haystack || NULL==needle)
	{
		return -1;
	}

	char *p = haystack;
	char *s = needle;
	char *tag = NULL;

	while('\0' != *p)
	{
		//fprintf(stderr, "*p=%c, *s=%c \n", *p, *s);
		if (*p == *s)
		{
			if (NULL==tag)
			{
				tag = p;
			}
			s++;
		}
		else
		{
			if (NULL!=tag && '\0'==*s)
			{
				break;
			}

			tag = NULL;
			s = needle;
		}
		p++;
	}

	if ('\0'==*s && NULL!=tag)
	{
		return (tag-haystack);
	}

	return -1;
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
	dprint_platform();
	//test_list();



	char *p = NULL;
	char *h = NULL;
	int m = 0;
	int c = 0;

	h = (char *)"abc c cjw ";
	p = strstr("abc c cjw ", " ");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr("abc c cjw ", " ");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)" ";
	p = strstr(" ", " ");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr(" ", " ");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)" ccc cc";
	p = strstr(" ccc cc", " ");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr(" ccc cc", " ");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)"abc c cjw ";
	p = strstr("abc c cjw ", "a");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr("abc c cjw ", "a");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)" x abc c cjw ";
	p = strstr(" x abc c cjw ", "a");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr(" x abc c cjw ", "a");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)"abcaa c cjw ";
	p = strstr("abcaa c cjw ", "aa");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr("abcaa c cjw ", "aa");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)" x abcaa c cjw ";
	p = strstr(" x abcaa c cjw ", "aa");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr(" x abcaa c cjw ", "aa");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)"aa xbc c cjw ";
	p = strstr("aa xbc c cjw ", "aa");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr("aa xbc c cjw ", "aa");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)"abc c cjw ";
	p = strstr("abc c cjw ", " ");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr("abc c cjw ", " ");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");

	h = (char *)"ccccc";
	p = strstr("ccccc", " ");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr("ccccc", " ");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");/*-1*/

	h = (char *)" xbc c cjw ";
	p = strstr(" xbc c cjw ", "a");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr(" xbc c cjw ", "a");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");/*-1*/

	h = (char *)"abcaa c cjw ";
	p = strstr("abcaa c cjw ", "ab");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr("abcaa c cjw ", "ab");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");/*0*/

	h = (char *)" x abcaa c cjw ";
	p = strstr(" x abcaa c cjw ", "ab");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr(" x abcaa c cjw ", "ab");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");/*3*/

	h = (char *)"abaa xbc c cjw ";
	p = strstr("abaa xbc c cjw ", "ab");
	if (NULL==p){m = -1;}else{m = p-h;}
	c = strStr("abaa xbc c cjw ", "ab");
	fprintf(stderr, "%d, %d, %s \n", c, m, (m==c)?"OK":"##falied!");/*0*/


	///////////////////////////////////////////////////////////////////////////////
	fprintf(stderr, "\n#########################falied!\n");











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
