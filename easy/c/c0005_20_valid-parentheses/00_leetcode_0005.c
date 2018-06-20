// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//20. Valid Parentheses
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.
//Example 1:
//Input: "()"
//Output: true
//Example 2:
//Input: "()[]{}"
//Output: true
//Example 3:
//Input: "(]"
//Output: false
//Example 4:
//Input: "([)]"
//Output: false
//Example 5:
//Input: "{[]}"
//Output: true
//bool isValid(char* s) {
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

bool isValid(char* s) {
	/* sanity check */
	/* https://en.wikipedia.org/wiki/Computer_keyboard */
#define Open_parenthesis '('
#define Close_parenthesis ')'
#define Open_Brace '{'
#define Close_Brace '}'
#define Open_bracket '['
#define Close_bracket ']'

	bool br = false;
	int length = strlen(s);
	int i = 0;
	char *stack = (char *)malloc(length);
	if (NULL==stack)
	{
		return br;
	}

	char *cursor = s;
	for (; '\0' != *cursor; cursor++)
	{
		if (Open_parenthesis == *cursor ||
			Open_Brace == *cursor ||
			Open_bracket == *cursor )
		{
			stack[i++] = *cursor;
		}
		else if ( Close_parenthesis == *cursor )
		{
			if (i!=0 && Open_parenthesis == stack[i-1])
			{
				stack[i-1] = '\0';
				i--;
			}
			else
			{
				br = false;
				goto END;
			}
		}
		else if ( Close_Brace == *cursor )
		{
			if (i!=0 && Open_Brace == stack[i-1])
			{
				stack[i-1] = '\0';
				i--;
			}
			else
			{
				br = false;
				goto END;
			}
		}
		else if ( Close_bracket == *cursor )
		{
			if (i!=0 && Open_bracket == stack[i-1])
			{
				stack[i-1] = '\0';
				i--;
			}
			else
			{
				br = false;
				goto END;
			}
		}
	}

	if(0 == i)
	{
		br = true;
		goto END;
	}

END:
	free(stack);
	stack = NULL;
	return br;
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



	int index = 0;
	int size = sizeof(random_nonspace_string_array_65536)/sizeof(random_nonspace_string_array_65536[0]);
	for (index=0; index<size; index++)
	{
		fprintf(stderr, "%s=%s\n", (random_nonspace_string_array_65536[index]), isValid(random_nonspace_string_array_65536[index]) ? "true":"false");
	}

	size = sizeof(random_KuoHao_string_array_65536)/sizeof(random_KuoHao_string_array_65536[0]);
	for (index=0; index<size; index++)
	{
		fprintf(stderr, "%s=%s\n", (random_KuoHao_string_array_65536[index]), isValid(random_KuoHao_string_array_65536[index]) ? "true":"false");
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
