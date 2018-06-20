// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//69. Sqrt(x)
//Implement int sqrt(int x).
//Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
//Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//Example 1:
//Input: 4
//Output: 2
//Example 2:
//Input: 8
//Output: 2
//Explanation: The square root of 8 is 2.82842..., and since 
//             the decimal part is truncated, 2 is returned.
//int mySqrt(int x) {
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
/*
https://en.wikipedia.org/wiki/Methods_of_computing_square_roots


*/
//static int array_0_65535[65536];
//static int negative_array_0_65535[65536];

/* Assumes that float is in the IEEE 754 single precision floating point format
 * and that int is 32 bits. */
float sqrt_approx(float z)
{
    int val_int = *(int*)&z; /* Same bits, but as an int */
    /*
     * To justify the following code, prove that
     *
     * ((((val_int / 2^m) - b) / 2) + b) * 2^m = ((val_int - 2^m) / 2) + ((b + 1) / 2) * 2^m)
     *
     * where
     *
     * b = exponent bias
     * m = number of mantissa bits
     *
     * .
     */

    val_int -= 1 << 23; /* Subtract 2^m. */
    val_int >>= 1; /* Divide by 2. */
    val_int += 1 << 29; /* Add ((b + 1) / 2) * 2^m. */

    return *(float*)&val_int; /* Interpret again as float */
}

float invSqrt(float x)
{
    float xhalf = 0.5f*x;
    union
    {
        float x;
        int i;
    } u;
    u.x = x;
    u.i = 0x5f375a86 - (u.i >> 1);
    /* The next line can be repeated any number of times to increase accuracy */
    u.x = u.x * (1.5f - xhalf * u.x * u.x);
    return u.x;
}
float Q_rsqrt( float number )
{
	union {
		float f;
		long i;
	} conv;
	
	float x2;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	conv.f  = number;
	conv.i  = 0x5f3759df - ( conv.i >> 1 );
	conv.f  = conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) );
	return conv.f;
}



/*
...the "magic number" for 64 bit IEEE754 size type double
... was shown to be exactly 0x5fe6eb50c7b537a9
*/
float Q_rsqrt_64( float number )
{
	union {
		float f;
		long i;
	} conv;
	
	float x2;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	conv.f	= number;
	conv.i	= 0x5fe6eb50c7b537a9 - ( conv.i >> 1 );
	conv.f	= conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) );
	return conv.f;
}



/* Here is a sample C program that implements the third method for 32 bit systems with 64 bit floating point doubles (like the x86): */

double fsqrt (double y) {
	double x, z, tempf;
	unsigned long *tfptr = ((unsigned long *)&tempf) + 1;

	tempf = y;
	*tfptr = (0xbfcdd90a - *tfptr)>>1; /* estimate of 1/sqrt(y) */
	x =  tempf;
	z =  y*0.5;                        /* hoist out the 2 */
	x = (1.5*x) - (x*x)*(x*z);         /* iteration formula     */
	x = (1.5*x) - (x*x)*(x*z);
	x = (1.5*x) - (x*x)*(x*z);
	x = (1.5*x) - (x*x)*(x*z);
	x = (1.5*x) - (x*x)*(x*z);
	return x*y;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int mySqrt(int x) {
	/* sanity check */
	if (0 == x)
	{
		return 0;
	}
#define EPSILON (1e-3)
	double x1 = 0.0f;
	double x2 = 1.0f;
	while (abs(x1 - x2) > EPSILON) 
	{
		x1 = x2;
		x2 = x1/2 + x/(x1 * 2);
	}

	/*floor*/
	if (x2*x2>x)
	{
		x1 = x2;
		x2 = x1/2 + x/(x1 * 2);
	}

	return (int)x1;
}

int bs_sqrt(int x) {
	int i = 0;
	int j = x / 2 + 1;
	while (i <= j)
	{
		int mid = i + (j - i)/2;

		int sq = mid * mid;
		if (sq == x) return mid;
		else if (sq < x) i = mid + 1;
		else j = mid - 1;
	}
	return (int)j;
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



	fprintf(stderr, "case 1 \n");
	int index = 0;
	int size = sizeof(array_0_65535)/sizeof(array_0_65535[0]);
	for (index=0; index<size; index++)
	{
		int n = array_0_65535[index];
		int s = (int)sqrt((double) n);
		int c = mySqrt(n);
		int d = bs_sqrt(n);

		if (s==c && s==d)
		{
			//fprintf(stderr, "OK, n=%d \n", n);
		}
		else if (s!=c)
		{
			fprintf(stderr, "mySqrt failed, n=%d, s=%d, c=%d \n", n, s, c );
			break;
		}
		else if (s!=d)
		{
			fprintf(stderr, "bs_sqrt failed, n=%d, s=%d, d=%d \n", n, s, d );
			break;
		}
	}

	fprintf(stderr, "case 2 \n");
	int64_t big[] = {INT_MAX, INT_MAX-1, INT_MAX-2, INT64_MAX, INT64_MAX-1, INT64_MAX-2};
	size = sizeof(big)/sizeof(big[0]);
	for (index=0; index<size; index++)
	{
		fprintf(stderr, "index=%d \n", index );
		int n = big[index];
		int s = (int)sqrt((double) n);
		int c = mySqrt(n);
		int d = bs_sqrt(n);

		if (s==c && s==d)
		{
			//fprintf(stderr, "OK, n=%d \n", n);
		}
		else if (s!=c)
		{
			fprintf(stderr, "mySqrt failed, n=%d, s=%d, c=%d \n", n, s, c );
			break;
		}
		else if (s!=d)
		{
			//index=0 bs_sqrt failed, n=2147483647, s=46340, d=1073741824
			fprintf(stderr, "bs_sqrt failed, n=%d, s=%d, d=%d \n", n, s, d );
			break;
		}
	}






#if 0
	fprintf(stderr, "case 3 \n");
	size = sizeof(negative_array_0_65535)/sizeof(negative_array_0_65535[0]);
	for (index=0; index<size; index++)
	{
		int n = negative_array_0_65535[index];
		int s = (int)sqrt((double) n);
		int c = mySqrt(n);
		int d = bs_sqrt(n);

		if (s==c && s==d)
		{
			fprintf(stderr, "OK \n");
		}
		else if (s!=c)
		{
			fprintf(stderr, "mySqrt failed, n=%d, s=%d, c=%d \n", n, s, c );
			break;
		}
		else if (s!=d)
		{
			fprintf(stderr, "bs_sqrt failed, n=%d, s=%d, d=%d \n", n, s, d );
			break;
		}
	}
#endif





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
