// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//35. Search Insert Position
//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//You may assume no duplicates in the array.
//Example 1:
//Input: [1,3,5,6], 5
//Output: 2
//Example 2:
//Input: [1,3,5,6], 2
//Output: 1
//Example 3:
//Input: [1,3,5,6], 7
//Output: 4
//Example 4:
//Input: [1,3,5,6], 0
//Output: 0
//int searchInsert(int* nums, int numsSize, int target) {
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

int searchInsert(int* nums, int numsSize, int target) {
	/* sanity check */
	if (NULL==nums || 0==numsSize)
	{
		return 0;
	}

	/* binary search */
	int left = -1, right = numsSize;
	int middle = 0;

	while (left+1 != right)
	{
		middle = left + (right - left) / 2;

		if (nums[middle] == target)
		{
			return middle;
		}
		else
		{
			if (nums[middle] < target)
			{
				left = middle;
			}
			else
			{
				right = middle;
			}
		}
	}

	return left+1;
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




	//Example 1:
	int nums1[] = {1,3,5,6};
	int numsSize = sizeof(nums1)/sizeof(nums1[0]);
	int target = 5;
	int r = searchInsert( nums1, numsSize, target);
	if (2 == r)
	{
		fprintf(stderr, "\n OK\n");
	}
	else
	{
		fprintf(stderr, "\n failed, %d\n", r);
	}

	//Example 2:
	int nums2[] = {1,3,5,6};
	numsSize = sizeof(nums2)/sizeof(nums2[0]);
	target = 2;
	r = searchInsert( nums2, numsSize, target);
	if (1 == r)
	{
		fprintf(stderr, "\n OK\n");
	}
	else
	{
		fprintf(stderr, "\n failed, %d\n", r);
	}

	//Example 3:
	int nums3[] = {1,3,5,6};
	numsSize = sizeof(nums3)/sizeof(nums3[0]);
	target = 7;
	r = searchInsert( nums3, numsSize, target);
	if (4 == r)
	{
		fprintf(stderr, "\n OK\n");
	}
	else
	{
		fprintf(stderr, "\n failed, %d\n", r);
	}

	//Example 4:
	int nums4[] = {1,3,5,6};
	numsSize = sizeof(nums4)/sizeof(nums4[0]);
	target = 0;
	r = searchInsert( nums4, numsSize, target);
	if (0 == r)
	{
		fprintf(stderr, "\n OK\n");
	}
	else
	{
		fprintf(stderr, "\n failed, %d\n", r);
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
