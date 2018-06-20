// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//26. Remove Duplicates from Sorted Array
//Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//Example 1:
//Given nums = [1,1,2],
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
//It doesn't matter what you leave beyond the returned length.
//Example 2:
//Given nums = [0,0,1,1,1,2,2,3,3,4],
//Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
//It doesn't matter what values are set beyond the returned length.
//Clarification:
//Confused why the returned value is an integer but your answer is an array?
//Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
//Internally you can think of this:
//// nums is passed in by reference. (i.e., without making a copy)
//int len = removeDuplicates(nums);
//// any modification to nums in your function would be known by the caller.
//// using the length returned by your function, it prints the first len elements.
//for (int i = 0; i < len; i++) {
//    print(nums[i]);
//}
//int removeDuplicates(int* nums, int numsSize) {
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
static int compare(const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);/* ascending order, Up */
}

void dump_array(int* nums, int numsSize)
{
	/* sanity check */
	fprintf(stderr, "%d------------------------------------------------------------------\n", numsSize);

	int i = 0;
	for (i = 0; i< numsSize; i++)
	{
		fprintf(stderr, "%d\n", nums[i]);
	}

	fprintf(stderr, "%d------------------------------------------------------------------\n", numsSize);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int removeDuplicates(int* nums, int numsSize) {
	/* sanity check */
	if (NULL==nums || 0==numsSize)
	{
		return 0;
	}

	//if (1 == numsSize)
	{
		//return 1;
	}


	int sum = 1;
	int i = 1;
	while(i < numsSize)
	{
		while(nums[i-1]==nums[i])
		{
			//fprintf(stderr, "check [%d]=%d, [%d]=%d\n", i-1, nums[i-1], i, nums[i]);
			i++;
			if (i==numsSize)
			{
				goto END;
			}
		}
		nums[sum] = nums[i];
		i++;
		sum++;
	}

END:
	return (sum);
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







	int nums[]={
		1,2,1,2, 1,2,1,1, 2,1
		//1,183,99,65,0,151,172,193,11,76,108,122,134,162,50,150,66,73,119,153,63,200,59,77,32,154,156,148,98,191,29,199,172,171,45,181,166,152,123,53,7,182,2,12,46,90,13,30,68,53,11,192,89,118,141,95,114,131,160,24,60,113,132,114,76,110,197,147,186,142,51,178,8,64,84,76,51,26,142,56,130,13,68,92,20,48,168,141,76,172,
		//138,19,172,54,109,192,10,160,3,98,125,126,82,27,56,87,90,160,24,28,70,67,1,133,180,140,88,180,7,76,1,152,181,24,186,104,164,44,59,51,72,126,9,162,175,188,193,138,6,75,21,59,150,52,27,141,163,151,26,14,128,150,45,170,155,23,6,54,111,7,82,120,79,74,55,21,25,128,158,72,133,111,38,166,143,36,45,17,88,190,146,
		//19,104,27,10,182,41,128,50,66,135,115,50,111,44,5,103,48,101,121,175,150,19,18,105,69,159,164,91,127,26,193,61,109,99,38,56,74,10,147,198,6,37,114,44,61,68,14,172,96,91,40,107,179,200,185,20,67,144,76,5,77,101,5,195,70,16,141,43,96,133,185,41,147,85,30
	};

	int numsSize = sizeof(nums)/sizeof(nums[0]);

	qsort(nums, numsSize, sizeof(int), compare);
	dump_array(nums, numsSize);
	int sum = removeDuplicates(nums, numsSize);
	fprintf(stderr, "sum=%d\n\n", sum);
	dump_array(nums, numsSize);



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
