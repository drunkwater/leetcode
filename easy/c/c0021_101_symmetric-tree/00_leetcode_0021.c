// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//101. Symmetric Tree
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//But the following [1,2,2,null,3,null,3] is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isSymmetric(struct TreeNode* root) {
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

/* helper */

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


typedef  void (*visit_fp)(struct TreeNode*);

void visit_implement(struct TreeNode* node)
{
	fprintf(stderr, "%d ", node->val);
}


/* Depth-first search */
void traversal_tree_pre_order(struct TreeNode* t, visit_fp visit)
{
	/* sanity check */
	if (NULL == t)
	{
		//fprintf(stderr, "t is null\n");
		return;
	}

	visit(t);
	traversal_tree_pre_order(t->left, visit);
	traversal_tree_pre_order(t->right, visit);

/*
	preorder(node)
	  if (node = null)
		return
	  visit(node)
	  preorder(node.left)
	  preorder(node.right)
*/

}

void traversal_tree_in_order(struct TreeNode* t, visit_fp visit)
{
	/* sanity check */
	if (NULL == t)
	{
		//fprintf(stderr, "t is null\n");
		return;
	}

	traversal_tree_in_order(t->left, visit);
	visit(t);
	traversal_tree_in_order(t->right, visit);

/*
	inorder(node)
	  if (node = null)
		return
	  inorder(node.left)
	  visit(node)
	  inorder(node.right)
*/

}

void traversal_tree_post_order(struct TreeNode* t, visit_fp visit)
{
	/* sanity check */
	if (NULL == t)
	{
		//fprintf(stderr, "t is null\n");
		return;
	}

	traversal_tree_post_order(t->left, visit);
	traversal_tree_post_order(t->right, visit);
	visit(t);

/*
	postorder(node)
	  if (node = null)
		return
	  postorder(node.left)
	  postorder(node.right)
	  visit(node)
*/

}


/* Breadth-first search */
void traversal_tree_level_order(struct TreeNode* t, visit_fp visit)
{
	/* sanity check */




/*
	levelorder(root)
	  q ? empty queue
	  q.enqueue(root)
	  while (not q.isEmpty())
		node ? q.dequeue()
		visit(node)
		if (node.left ? null)
		  q.enqueue(node.left)
		if (node.right ? null)
		  q.enqueue(node.right)
*/

}

void destroy_tree(struct TreeNode* t)
{
	/* sanity check */
	if (NULL == t)
	{
		//fprintf(stderr, "t is null\n");
		return;
	}

	destroy_tree(t->left);
	destroy_tree(t->right);

	fprintf(stderr, "free t=%d\n", t->val);
	free(t);
	t = NULL;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) {
    
}






/* https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
struct TreeNode* newNode(int data);
 
/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct TreeNode* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct TreeNode *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TreeNode* newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*)
                         malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct TreeNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->val);
    preOrder(node->left);
    preOrder(node->right);
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
