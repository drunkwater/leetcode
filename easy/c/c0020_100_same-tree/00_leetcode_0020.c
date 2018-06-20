// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//100. Same Tree
//Given two binary trees, write a function to check if they are the same or not.
//Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//Example 1:
//Input:     1         1
//          / \       / \
//         2   3     2   3
//        [1,2,3],   [1,2,3]
//Output: true
//Example 2:
//Input:     1         1
//          /           \
//         2             2
//        [1,2],     [1,null,2]
//Output: false
//Example 3:
//Input:     1         1
//          / \       / \
//         2   1     1   2
//        [1,2,1],   [1,1,2]
//Output: false
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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





/* https://en.wikipedia.org/wiki/Tree_%28data_structure%29 */
/* https://en.wikipedia.org/wiki/Tree_traversal */
/*
                                   
               F
              /\
            B    G
           /\     \
          A  D     I
            /\    /
           C  E  H
                                   

Pre-order

Pre-order: F, B, A, D, C, E, G, I, H.
Check if the current node is empty / null.
Display the data part of the root (or current node).
Traverse the left subtree by recursively calling the pre-order function.
Traverse the right subtree by recursively calling the pre-order function.
In-order

In-order: A, B, C, D, E, F, G, H, I.
Check if the current node is empty / null.
Traverse the left subtree by recursively calling the in-order function.
Display the data part of the root (or current node).
Traverse the right subtree by recursively calling the in-order function.
In a binary search tree, in-order traversal retrieves data in sorted order.[4]

Post-order

Post-order: A, C, E, D, B, H, I, G, F.
Check if the current node is empty / null.
Traverse the left subtree by recursively calling the post-order function.
Traverse the right subtree by recursively calling the post-order function.
Display the data part of the root (or current node).

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
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	/* sanity check */
	if (NULL==p && NULL==q)
	{
		return true;
	}
	if (NULL==p || NULL==q)
	{
		return false;
	}

	if (p->val!=q->val)
	{
		return false;
	}
	else
	{
		return isSameTree(p->left, q->left) && isSameTree(p->left, q->left);
	}
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



/*
        4
      /   \
    2       6
  /   \   /   \
1      3 5     7
*/
	int atree1[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(atree1)/sizeof(atree1[0]);

	/* Convert List to BST */
	struct TreeNode *root = sortedArrayToBST(atree1, 0, n-1);
	printf("\n n=%d PreOrder Traversal of constructed BST: \n", n);
	traversal_tree_pre_order(root, visit_implement);

	printf("\n n=%d InOrder Traversal of constructed BST: \n", n);
	traversal_tree_in_order(root, visit_implement);


	printf("\n n=%d PostOrder Traversal of constructed BST: \n", n);
	traversal_tree_post_order(root, visit_implement);


	int atree2[] = {1, 2, 3, 4, 5, 6, 7};
	n = sizeof(atree2)/sizeof(atree2[0]);
	/* Convert List to BST */
	struct TreeNode *root2 = sortedArrayToBST(atree2, 0, n-1);
	printf("\n same tree: %s \n", isSameTree(root, root2)?"yes":"no");


	destroy_tree(root);
	destroy_tree(root2);

	printf("\n [try]n=%d PostOrder Traversal of constructed BST: \n", n);
	traversal_tree_post_order(root, visit_implement);
	/* valgrind --tool=memcheck --leak-check=full ./app_elf */



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


#ifdef Church

/* https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */

#include<stdio.h>
#include<stdlib.h>
 
/* A Binary Tree node */
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};
 
struct TNode* newNode(int data);
 
/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct TNode *root = newNode(arr[mid]);
 
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
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
                         malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    struct TNode *root = sortedArrayToBST(arr, 0, n-1);
    printf("n PreOrder Traversal of constructed BST ");
    preOrder(root);
 
    return 0;
}
#endif




#ifdef Church

/*
	https://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/
*/

// C++ program to construct a Binary Tree from parent array
#include<bits/stdc++.h>
using namespace std;
 
// A tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Utility function to create new Node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}
 
// Creates a node with key as 'i'.  If i is root, then it changes
// root.  If parent of i is not created, then it creates parent first
void createNode(int parent[], int i, Node *created[], Node **root)
{
    // If this node is already created
    if (created[i] != NULL)
        return;
 
    // Create a new node and set created[i]
    created[i] = newNode(i);
 
    // If 'i' is root, change root pointer and return
    if (parent[i] == -1)
    {
        *root = created[i];
        return;
    }
 
    // If parent is not created, then create parent first
    if (created[parent[i]] == NULL)
        createNode(parent, parent[i], created, root);
 
    // Find parent pointer
    Node *p = created[parent[i]];
 
    // If this is first child of parent
    if (p->left == NULL)
        p->left = created[i];
    else // If second child
        p->right = created[i];
}
 
// Creates tree from parent[0..n-1] and returns root of the created tree
Node *createTree(int parent[], int n)
{
    // Create an array created[] to keep track
    // of created nodes, initialize all entries
    // as NULL
    Node *created[n];
    for (int i=0; i<n; i++)
        created[i] = NULL;
 
    Node *root = NULL;
    for (int i=0; i<n; i++)
        createNode(parent, i, created, &root);
 
    return root;
}
 
//For adding new line in a program
inline void newLine(){
    cout << "\n";
}
 
// Utility function to do inorder traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
 
// Driver method
int main()
{
    int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof parent / sizeof parent[0];
    Node *root = createTree(parent, n);
    cout << "Inorder Traversal of constructed tree\n";
    inorder(root);
    newLine();
}
#endif

