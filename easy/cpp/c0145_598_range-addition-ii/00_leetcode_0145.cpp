// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//598. Range Addition II
//Given an m * n matrix M initialized with all 0's and several update operations.
//Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b, which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
//You need to count and return the number of maximum integers in the matrix after performing all the operations.
//Example 1:
//Input: 
//m = 3, n = 3
//operations = [[2,2],[3,3]]
//Output: 4
//Explanation: 
//Initially, M = 
//[[0, 0, 0],
// [0, 0, 0],
// [0, 0, 0]]
//After performing [2,2], M = 
//[[1, 1, 0],
// [1, 1, 0],
// [0, 0, 0]]
//After performing [3,3], M = 
//[[2, 2, 1],
// [2, 2, 1],
// [1, 1, 1]]
//So the maximum integer in M is 2, and there are four of it in M. So return 4.
//Note:
//The range of m and n is [1,40000].
//The range of a is [1,m], and the range of b is [1,n].
//The range of operations size won't exceed 10,000.
//class Solution {
//public:
//    int maxCount(int m, int n, vector<vector<int>>& ops) {
//    }
//};



#include<iostream>
#include<iomanip>


#include<stdint.h>
#include<time.h>
#include<limits.h>

#include"solution.hpp"

/*using namespace std;*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
{
	/* sanity check */

	std::map<int, int> hashTbl;/* index -> data */

	for ( int i = 0; i < (int)nums.size(); i++ )
	{
		int n = nums[i];

		if ( hashTbl.find(target - n) == hashTbl.end() )
		{
			hashTbl[n] = i;
		}
		else
		{
			std::vector<int> ret(2);
			ret[0] = hashTbl[target - n];
			ret[1] = i;
			return ret;
		}
	}

	return std::vector<int>(0);
}


void printTime(void)
{
	/* sanity check */
	time_t rawtime;
	struct tm *timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	std::cout << " Current date and time is: " << asctime (timeinfo) << std::endl;
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

	std::cout << "  int8_t = " << sizeof(int8_t)     << std::endl;
	std::cout << " uint8_t = " << sizeof(uint8_t)    << std::endl;
	std::cout << " int16_t = " << sizeof(int16_t)    << std::endl;
	std::cout << "uint16_t = " << sizeof(uint16_t)   << std::endl;
	std::cout << " int32_t = " << sizeof(int32_t)    << std::endl;
	std::cout << "uint32_t = " << sizeof(uint32_t)   << std::endl;
	std::cout << " int64_t = " << sizeof(int64_t)    << std::endl;
	std::cout << "uint64_t = " << sizeof(uint64_t)   << std::endl;


	std::cout << "ENDIANNESS=" << ENDIANNESS << std::endl;



	int n = 0x04030201;
	if (*(char *)&n == 0x01)
	{
		std::cout << "little endian" << std::endl;
	}
	else
	{
		std::cout << "   big endian" << std::endl;
	}

	std::cout << std::endl << std::endl;
}




int main( int argc, char *argv[] )
{
	/* sanity check */
	std::cout << "[" << __TIME__" "__DATE__ << "]" << __FILE__ << ":" << __LINE__ << std::endl;
	printTime();


	struct timespec start,end;	/* seconds and nanoseconds */
	clock_gettime(CLOCK_MONOTONIC, &start);
	std::cout << "[start]" << start.tv_sec << ", " << start.tv_nsec << std::endl;

	time_t s,e;
	s=time(NULL);





	/* add your codes here */
	//dprint_platform();





	int array[]={1,2,3,4,5,6};
	int target = 7;
	int size = sizeof(array)/sizeof(array[0]);

	//std::vector<int> vec(begin(array), end(array));
	std::vector<int> vec(array, (array+size));
	Solution obj;
	std::vector<int> result = obj.twoSum(vec, target);

	for (std::vector<int>::iterator it = result.begin(); it != result.end(); it++)
	{
		std::cout << *it << " -> " << array[*it] << std::endl;
	}










#if 0/* disable 'no operation' */
	unsigned int z = 0;
#define MAX_NOOP  0xCFFFFFFFUL
	for(z = 0; z < MAX_NOOP; z++)
	{
		asm("nop ; nop ; nop ; nop");
		asm("nop ; nop ; nop ; nop");
	}
#endif



	e=time(NULL);

	std::cout.setf(std::ios::fixed);
	std::cout << "Worked time : " << std::fixed << std::setprecision(8) << difftime(e, s) << std::endl;/*6.00000000*/
	std::cout.unsetf(std::ios::fixed);


	clock_gettime(CLOCK_MONOTONIC, &end);
	std::cout << "[  end]" << end.tv_sec << ", " << end.tv_nsec << std::endl;


	printTime();



	std::cout << "[" << __TIME__" "__DATE__ << "]" << __FILE__ << ":" << __LINE__ << std::endl;
	return 0;
}
