// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//83. Remove Duplicates from Sorted List
//Given a sorted linked list, delete all duplicates such that each element appear only once.
//Example 1:
//Input: 1->1->2
//Output: 1->2
//Example 2:
//Input: 1->1->2->3->3
//Output: 1->2->3
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* deleteDuplicates(struct ListNode* head) {
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
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};




/* helper */
int size_list(struct ListNode* head)
{
	/* sanity check */
	int size = 0;

	struct ListNode* cursor = NULL;
	for (cursor=head; NULL!=cursor; cursor=cursor->next)
	{
		size++;
	}

	//fprintf(stderr, "size = %d \n\n", size);
	return size;
}

/* free by caller */
int *list_to_array(struct ListNode* head)
{
	/* sanity check */
	int size = size_list(head);
	fprintf(stderr, "size = %d \n\n", size);

	int *array = (int *)malloc(size * sizeof(int));
	if (NULL == array)
	{
		fprintf(stderr, "malloc falied\n");
		return NULL;
	}

	struct ListNode* cursor = NULL;
	int i = 0;
	for (cursor=head; NULL!=cursor; cursor=cursor->next)
	{
		//fprintf(stderr, "val = %d \n", cursor->val);
		array[i++] = cursor->val;
	}

	return array;
}


static int compare(const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);/* ascending order, Up */
}

void sort_list(struct ListNode* head)
{
	/* sanity check */
	int size = size_list(head);
	//fprintf(stderr, "size = %d \n\n", size);

	int *array = list_to_array(head);
	if (NULL == array)
	{
		fprintf(stderr, "malloc falied\n");
		return;
	}

	qsort(array, size, sizeof(int), compare);

	struct ListNode* cursor = NULL;
	int i = 0;
	for (cursor=head; NULL!=cursor; cursor=cursor->next)
	{
		//fprintf(stderr, "val = %d \n", cursor->val);
		cursor->val = array[i];
		i++;
	}

	free(array);
	array = NULL;

}


void dump_list(struct ListNode* head)
{
	/* sanity check */
	int size = 0;

	struct ListNode* cursor = NULL;
	for (cursor=head; NULL!=cursor; cursor=cursor->next)
	{
		fprintf(stderr, "%d\n", cursor->val);
		size++;
	}

	fprintf(stderr, "size = %d \n\n", size);
}

void free_list(struct ListNode* head)
{
	/* sanity check */
	struct ListNode* p = NULL;
	while(NULL!=head)
	{
		p = head;
		head = head->next;

		free(p);
		p = NULL;
	}
}


/* free by caller */
struct ListNode* array_to_list(int *array, int size)
{
	/* sanity check */
	struct ListNode* head = NULL;
	struct ListNode* *cursor = &head;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		struct ListNode* node = (struct ListNode* )malloc(sizeof(struct ListNode));
		if (NULL == node)
		{
			fprintf(stderr, "malloc falied\n");
			return NULL;
		}
		node->val = array[i];
		*cursor = node;

		cursor = &((*cursor)->next);/* faster!!! */
	}

	return head;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	   int val;
 *	   struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
	/* sanity check */
	struct ListNode* cursor = head;
	struct ListNode* t = NULL;

	while (NULL!=cursor &&	NULL!=cursor->next)
	{
		if (cursor->val == cursor->next->val)
		{
			t = cursor->next->next;
			free(cursor->next);
			cursor->next = t;
			continue;
		}

		cursor = cursor->next;
	}

	return head;
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



	int size = sizeof(array_65535_random_200)/sizeof(array_65535_random_200[0]);
	struct ListNode* head = array_to_list(array_65535_random_200, size);
	//dump_list(head);
	sort_list(head);
	//dump_list(head);
	head = deleteDuplicates(head);


	size = sizeof(array_65535_random_200_same)/sizeof(array_65535_random_200_same[0]);
	struct ListNode* head2 = array_to_list(array_65535_random_200_same, size);
	//dump_list(head2);
	sort_list(head2);
	//dump_list(head2);
	head2 = deleteDuplicates(head2);



	struct ListNode* p1 = NULL;
	struct ListNode* p2 = NULL;
	int n = 0;
	for (p1=head, p2=head2; NULL!=p1 && NULL!=p2; p1=p1->next, p2=p2->next, n++)
	{
		if (p1->val != p2->val)
		{
			fprintf(stderr, "[%d] p1=%d, p2=%d \n", n, p1->val, p2->val);
			break;
		}
	}

	free_list(head);
	head = NULL;
	free_list(head2);
	head2 = NULL;








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
