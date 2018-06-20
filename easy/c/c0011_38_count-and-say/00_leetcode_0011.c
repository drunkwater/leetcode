// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//38. Count and Say
//The count-and-say sequence is the sequence of integers with the first five terms as following:
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth term of the count-and-say sequence.
//Note: Each term of the sequence of integers will be represented as a string.
//Example 1:
//Input: 1
//Output: "1"
//Example 2:
//Input: 4
//Output: "1211"
//char* countAndSay(int n) {
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




/*
	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
	6.     312211
*/

/* helper */
char* counter(char* s, int *sSize) {
	/* sanity check */
	int size = *sSize;
	char *string = (char *)calloc(size*2, sizeof(char));
	if (NULL==string)
	{
		fprintf(stderr, " calloc failed! \n");
		return NULL;
	}

	int index = 0;
	int sum = 1;
	int i = 0;
	while (i < size-1)
	{
		if (s[i]==s[i+1])/* last char is '\0' */
		{
			sum++;
		}
		else
		{
			string[index]   = sum+'0';
			string[index+1] = s[i];
			index += 2;
			sum=1;
		}

		i++;
	}
	*sSize = index+1;

	return string;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char* countAndSay(int n) {
	/* sanity check */
	if (0 == n)
	{
		return NULL;
	}

#define MAX_STR_LEN (65536*1024)
	char *string = (char *)calloc(MAX_STR_LEN, sizeof(char));
	if (NULL==string)
	{
		fprintf(stderr, " calloc failed! \n");
		return NULL;
	}

	int size = 2;
	string[0] = '1';
	string[1] = '\0';
	char *p = NULL;

	if (1 == n)
	{
		return string;
	}


	int i = 1;
	while (i < n)
	{
		char* p = counter(string, &size);/* new size */
		strcpy (string, p);
		free(p);
		p = NULL;

		i++;
	}

	return string;
}


char* countAndSay2(int n) {
    if (n == 0) return NULL;

#define MAX (65536*1024)
    char *buf = (char *)calloc(MAX, sizeof(char));
    char *ans = (char *)calloc(MAX, sizeof(char));

    ans[0] = '1';

    char prev, *cur;
    int i, count, p;

    for (i = 0; i < n - 1; i++) {
        prev = *ans;
        cur = ans + 1;
        count = 1;
        p = 0;
        while (1) {
            if (prev != *cur) {
                buf[p++] = count + '0'; /* p += sprintf(buf + p, "%d", count);   */
                buf[p++] = prev;        /* we can prove that there are 3 of same */
                count = 1;              /* numbers at most in the sequence, so   */
            }                           /* count always has 1 digit.             */
            else {
                count++;
            }

            if (*cur == '\0') break;

            prev = *cur;
            cur++;
        }

        char *t = ans;
        ans = buf;
        buf = t;

        memset(buf, 0, MAX);
    }

    free(buf);
    return ans;
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
	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
	6.     312211
	1 is read off as "one 1" or 11.
	11 is read off as "two 1s" or 21.
	21 is read off as "one 2, then one 1" or 1211.
*/


/*
gcc -o test 00_leetcode_0011.c -lm; ./test
*/
	int i;
	for (i = 0; i < 64; i++)
	{
		char *a = countAndSay(i);
		char *b = countAndSay2(i);

		if (((NULL==a) && (NULL==b)) || 0==strcmp(a,b))
		{
			//fprintf(stderr, "%d, %s, OK\n", i , a);
		}
		else
		{
			fprintf(stderr, "!!!failed, i=%d, a=%s, b=%s \n", i, a, b);
		}
		free(a);
		a = NULL;
		free(b);
		b = NULL;
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
