// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//699. Falling Squares
//On an infinite number line (x-axis), we drop given squares in the order they are given.
//The i-th square dropped (positions[i] = (left, side_length)) is a square with the left-most point being positions[i][0] and sidelength positions[i][1].
//The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait for each square to stick before dropping the next.
//The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). Squares dropped adjacent to each other will not stick together prematurely.
//Return a list ans of heights. Each height ans[i] represents the current highest height of any square we have dropped, after dropping squares represented by positions[0], positions[1], ..., positions[i].
//Example 1:
//Input: [[1, 2], [2, 3], [6, 1]]
//Output: [2, 5, 5]
//Explanation:
//After the first drop of positions[0] = [1, 2]:
//_aa
//_aa
//-------
//The maximum height of any square is 2.
//After the second drop of positions[1] = [2, 3]:
//__aaa
//__aaa
//__aaa
//_aa__
//_aa__
//--------------
//The maximum height of any square is 5.  
//The larger square stays on top of the smaller square despite where its center
//of gravity is, because squares are infinitely sticky on their bottom edge.
//After the third drop of positions[1] = [6, 1]:
//__aaa
//__aaa
//__aaa
//_aa
//_aa___a
//--------------
//The maximum height of any square is still 5.
//Thus, we return an answer of [2, 5, 5].
//Example 2:
//Input: [[100, 100], [200, 100]]
//Output: [100, 100]
//Explanation: Adjacent squares don't get stuck prematurely - only their bottom edge can stick to surfaces.
//Note:
//1 <= positions.length <= 1000.
//1 <= positions[i][0] <= 10^8.
//1 <= positions[i][1] <= 10^6.
//class Solution {
//public:
//    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
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
