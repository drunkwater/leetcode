// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//66. Plus One
//Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//You may assume the integer does not contain any leading zero, except the number 0 itself.
//Example 1:
//Input: [1,2,3]
//Output: [1,2,4]
//Explanation: The array represents the integer 123.
//Example 2:
//Input: [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
///**
// * Return an array of size *returnSize.
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* plusOne(int* digits, int digitsSize, int* returnSize) {
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




/* helper */
void dump_array_range(int* nums, int from, int to)
{
	/* sanity check */
	fprintf(stderr, "------------------------------------------------------------------\n");

	int i = 0;
	for (i = from; i<= to; i++)
	{
		fprintf(stderr, "%d\n", nums[i]);
	}

	fprintf(stderr, "------------------------------------------------------------------\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	/* sanity check */
	if (NULL==digits || 0==digitsSize)
	{
		return NULL;
	}

	int *returnDigits = (int *)calloc(digitsSize+1, sizeof(int));
	*returnSize = digitsSize;

	int i = 0;
	int carray = 1;
	for (i = digitsSize-1; i >= 0; i--)
	{
		int data = digits[i];
		digits[i] = (data+carray)%10;
		carray = (data+carray)/10;
		//fprintf(stderr, "  digits[%d]=%d, carray=%d \n", i, digits[i], carray);
		if (0==carray)
		{
			break;
		}
	}


	int *p = returnDigits;
	if (1==carray)
	{
		*returnSize = digitsSize+1;
		returnDigits[0] = 1;
		p++;
	}
	for (i = 0; i < digitsSize; i++)
	{
		p[i] = digits[i];
		//fprintf(stderr, "  digits[%d]=%d \n", i, digits[i]);
	}

	return returnDigits;
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


	int digits[] = {9,9,9,9};
	int size = sizeof(digits)/sizeof(digits[0]);
	int returnSize = 0;
	int *d = plusOne(digits, size, &returnSize);
	fprintf(stderr, "%d, %d \n\n",  size, returnSize);
	dump_array_range(d, 0, returnSize-1);
	free(d);
	d = NULL;

	int digits2[] = {1,9,1,9};
	size = sizeof(digits2)/sizeof(digits2[0]);
	returnSize = 0;
	d = plusOne(digits2, size, &returnSize);
	fprintf(stderr, "%d, %d \n\n",	size, returnSize);
	dump_array_range(d, 0, returnSize-1);
	free(d);
	d = NULL;

	int digits3[] = {1,9,1,8};
	size = sizeof(digits3)/sizeof(digits3[0]);
	returnSize = 0;
	d = plusOne(digits3, size, &returnSize);
	fprintf(stderr, "%d, %d \n\n",	size, returnSize);
	dump_array_range(d, 0, returnSize-1);
	free(d);
	d = NULL;









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
