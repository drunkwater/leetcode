// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//21. Merge Two Sorted Lists
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//Example:
//Input: 1->2->4, 1->3->4
//Output: 1->1->2->3->4->4
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
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

/* https://en.wikipedia.org/wiki/Linked_list */

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
	struct ListNode* head = (struct ListNode* )malloc(sizeof(struct ListNode));
	head->val = array[0];
	head->next = NULL;

	struct ListNode* rear = head;
	int i = 0;
	for (i = 1; i < size; i++)
	{
		struct ListNode* node = (struct ListNode* )malloc(sizeof(struct ListNode));
		if (NULL == node)
		{
			fprintf(stderr, "malloc falied\n");
			return NULL;
		}
		node->val = array[i];
		node->next = rear->next;
		rear->next = node;
		rear = node;
	}

	return head;
}


struct ListNode* array_to_list2(int *array, int size)
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	/* sanity check */
	/* both are NULL? */
	if (NULL==l1)
	{
		return l2;
	}
	if (NULL==l2)
	{
		return l1;
	}

	struct ListNode* cursor1 = l1;
	struct ListNode* cursor2 = l2;
	struct ListNode* head = NULL;
	struct ListNode* *p = &head;

	while (1)
	{
		if (cursor1) fprintf(stderr, "cursor1->val=%d \n", cursor1->val);
		if (cursor2) fprintf(stderr, "cursor2->val=%d \n", cursor2->val);

		if (NULL!=cursor1 && NULL!=cursor2)
		{
			if (cursor1->val < cursor2->val)
			{
				*p = cursor1;
				cursor1 = cursor1->next;
			}
			else
			{
				*p = cursor2;
				cursor2 = cursor2->next;
			}
		}
		else if (NULL==cursor1 && NULL!=cursor2)
		{
			*p = cursor2;
			cursor2 = cursor2->next;
		}
		else if (NULL!=cursor1 && NULL==cursor2)
		{
			*p = cursor1;
			cursor1 = cursor1->next;
		}
		else
		{
			break;
		}

		p = &((*p)->next);
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





	fprintf(stderr, "\n\n------------------------------------------------------\n\n");

	//int data[]={1,183,99,65,0,151,172,193,11,76,108,122,134,162,50,150,66,73,119,153,63,200,59,77,32,154,156,148,98,191,29,199,172,171,45,181,166,152,123,53,7,182,2,12,46,90,13,30,68,53,11,192,89,118,141,95,114,131,160,24,60,113,132,114,76,110,197,147,186,142,51,178,8,64,84,76,51,26,142,56,130,13,68,92,20,48,168,141,76,172,138,19,172,54,109,192,10,160,3,98,125,126,82,27,56,87,90,160,24,28,70,67,1,133,180,140,88,180,7,76,1,152,181,24,186,104,164,44,59,51,72,126,9,162,175,188,193,138,6,75,21,59,150,52,27,141,163,151,26,14,128,150,45,170,155,23,6,54,111,7,82,120,79,74,55,21,25,128,158,72,133,111,38,166,143,36,45,17,88,190,146,19,104,27,10,182,41,128,50,66,135,115,50,111,44,5,103,48,101,121,175,150,19,18,105,69,159,164,91,127,26,193,61,109,99,38,56,74,10,147,198,6,37,114,44,61,68,14,172,96,91,40,107,179,200,185,20,67,144,76,5,77,101,5,195,70,16,141,43,96,133,185,41,147,85,30};
	int data[256]={
	1,183,99,65,0,151,172,193,11,76,108,122,134,162,50,150,66,73,119,153,63,200,59,77,32,154,156,148,98,191,29,199,172,171,45,181,166,152,123,53,7,182,2,12,46,90,13,30,68,53,11,192,89,118,141,95,114,131,160,24,60,113,132,114,76,110,197,147,186,142,51,178,8,64,84,76,51,26,142,56,130,13,68,92,20,48,168,141,76,172,138,19,172,54,109,192,10,160,3,98,125,126,82,27,56,87,90,160,24,28,70,67,1,133,180,140,88,180,7,76,1,152,181,24,186,104,164,44,59,51,72,126,9,162,175,188,193,138,6,75,21,59,150,52,27,141,163,151,26,14,128,150,45,170,155,23,6,54,
	111,7,82,120,79,74,55,21,25,128,158,72,133,111,38,166,143,36,45,17,88,190,146,19,104,27,10,182,41,128,50,66,135,115,50,111,44,5,103,48,101,121,175,150,19,18,105,69,159,164,91,127,26,193,61,109,99,38,56,74,10,147,
	198,6,37,114,44,61,68,14,172,96,91,40,107,179,200,185,20,67,144,76,5,77,101,5,195,70,16,141,43,
	96,133,185,
	41};//,147,85};//,30};
	//int data[]={1,183,99,65,0,151,172,193,11,76,};

	//int size = sizeof(array_65535_random_200)/sizeof(array_65535_random_200[0]);
	//struct ListNode* head = array_to_list(array_65535_random_200, size);

	int size = sizeof(data)/sizeof(data[0]);
	struct ListNode* head = array_to_list(data, size);
	dump_list(head);
	sort_list(head);
	dump_list(head);
	free_list(head);
	head = NULL;





	fprintf(stderr, "\n\n------------------------------------------------------\n\n");


	if (head) {fprintf(stderr, "head not null \n"); dump_list(head);}




	int data2[]={181,67,108,20,23,130,131,39,172,59,12,111,148,118,81,44,129,53,36,134,185,75,195,180,102,119,60,89,127,84,22,54,164,60,119,146,64,35,48,141,176,54,90,153,117,24,174,200,33,151,172,38,54,169,65,105,194,44,120,78,40,166,83,77,111,49,105,166,174,15,26,100,90,15,164,71,94,95,179,75,31,11,170,14,97,151,143,67,177,65,192,152,170,111,44,154,126,72,174,147,121,57,148,6,167,188,28,42,59,168,87,141,79,99,177,78,47,191,51,158,140,135,21,136,177,194,65,126,99,144,188,111,39,199,127,78,51,140,126,10,176,188,8,18,128,20,67,179,147,172,14,57,44,36,133,145,70,185,117,162,95,81,78,33,50,193,16,15,91,7,10,195,145,183,58,164,22,39,167,110,12,144,164,62,99,3,163,19,172,28,141,127,93,110,122,109,101,164,38,123,114,135,89,77,103,55,104,152,2,2,3,142,165,1,19,133,71,7,139,101,71,171,92,199,179,148,77,163,118,148,41,105,194,7,153,179,157,85,48,56,117,195,156,49,133,112,40,58,24,177,186,26,65,66,198,33};
	//int data2[]={181,67,108,20,23,130,131,39,172,59,12,111,148,118};

	//size = sizeof(array_65535_random_200)/sizeof(array_65535_random_200[0]);
	//struct ListNode* head = array_to_list(array_65535_random_200, size);

	size = sizeof(data2)/sizeof(data2[0]);
	struct ListNode* head2 = array_to_list2(data2, size);
	dump_list(head2);
	sort_list(head2);
	dump_list(head2);
	//free_list(head2);
	//head2 = NULL;


	if (head2) {fprintf(stderr, "head2 not null \n");dump_list(head2);}

#if 1

	fprintf(stderr, "\n\n---------------merge---------------------------------------\n\n");

	head2 = mergeTwoLists(head, head2);
	dump_list(head2);
	free_list(head2);
	head2 = NULL;

	fprintf(stderr, "\n\n------------------------------------------------------\n\n");



/////////////////////////////////////////////////////////////////////////////////////


	int data3[]={1,183,99,65,0,151,172,193,11,76,108,122,134};
	//int data3[]={};

	//int size = sizeof(array_65535_random_200)/sizeof(array_65535_random_200[0]);
	//struct ListNode* head = array_to_list(array_65535_random_200, size);

	size = sizeof(data3)/sizeof(data3[0]);
	struct ListNode* head3 = array_to_list(data3, size);
	sort_list(head3);
	dump_list(head3);


	int data4[]={181,67,108,20,23,130,131,39,172,59,12,111};
	//int data4[]={};

	//int size = sizeof(array_65535_random_200)/sizeof(array_65535_random_200[0]);
	//struct ListNode* head = array_to_list(array_65535_random_200, size);

	size = sizeof(data4)/sizeof(data4[0]);
	struct ListNode* head4 = array_to_list(data4, size);
	sort_list(head4);
	dump_list(head4);

	fprintf(stderr, "\n\n#######################################################\n\n");
	head3 = mergeTwoLists(head3, head4);
	dump_list(head3);
	fprintf(stderr, "\n\n#######################################################\n\n");

	free_list(head3);
#endif



	size = sizeof(array_65535_random_200)/sizeof(array_65535_random_200[0]);
	//struct ListNode* bighead = array_to_list(array_65535_random_200, size);//0.log
	struct ListNode* bighead = array_to_list2(array_65535_random_200, size);//1.log
	dump_list(bighead);
	sort_list(bighead);
	dump_list(bighead);
	//free_list(bighead);
	//dump_list(bighead);
	//bighead = NULL;

	size = sizeof(array_65535_random_200_2)/sizeof(array_65535_random_200_2[0]);
	struct ListNode* bighead2 = array_to_list2(array_65535_random_200_2, size);//1.log
	dump_list(bighead2);
	sort_list(bighead2);
	dump_list(bighead2);
	bighead2 = mergeTwoLists(bighead, bighead2);
	dump_list(bighead2);
	free_list(bighead2);
	//dump_list(bighead);
	bighead2 = NULL;








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
