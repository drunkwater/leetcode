// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//88. Merge Sorted Array
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//Note:
//The number of elements initialized in nums1 and nums2 are m and n respectively.
//You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//Example:
//Input:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//Output: [1,2,2,3,5,6]
//void merge(int* nums1, int m, int* nums2, int n) {
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
//static int array_65535_random_200[65536];


/* helper */
static int compare(const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);/* ascending order, Up */
}

void counter(int* c, int* nums, int size) {
	/* sanity check */
	int i = 0;
	for (i = 0; i < size; i++)
	{
		c[nums[i]]++;
	}
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

void merge(int* nums1, int m, int* nums2, int n) {
	/* sanity check */
	int *p = nums1+(m+n-1);
	int i = n-1;
	int j = m-1;
	for (; i >= 0 && j >= 0; i--, j--)
	{
		if (nums1[j] < nums2[i])
		{
			*p = nums2[i];
			p--;
			*p = nums1[j];
			p--;
		}
		else
		{
			*p = nums1[j];
			p--;
			*p = nums2[i];
			p--;
		}
	}

	while(i >= 0)
	{
		*p = nums2[i];
		p--;
	}

	while(j >= 0)
	{
		*p = nums1[j];
		p--;
	}

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





	//static int array_65535_random_200[65536];
	int size = sizeof(array_65535_random_200)/sizeof(array_65535_random_200[0]);
	int c[201] = {0};
	counter(c, array_65535_random_200, size);

	qsort(array_65535_random_200, size, sizeof(int), compare);

	int *all = (int *)calloc(size * 2, sizeof(int));
	int index = 0;
	for (index = 0; index < size; index++)
	{
		all[index] = array_65535_random_200[index];
	}
	merge(all, size, array_65535_random_200, size);

	int c2[201] = {0};
	counter(c2, all, size*2);

	for (index = 0; index < 201; index++)
	{
		if (c[index]*2 != c2[index])
		{
			fprintf(stderr, "FAILED! [%d] c=%d, c2=%d \n", index, c[index], c2[index] );
			break;
		}
	}

	free(all);


	int nums1[] = { 1, 3, 5, 7, 9, 11, 13, 15, 0, 0, 0, 0, 0, 0, 0, 0 };
	int nums2[] = { 2, 4, 6, 8, 10,12, 14, 16 };

	merge(nums1, 8, nums2, 8);
	dump_array(nums1, 16);








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
