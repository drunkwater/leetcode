// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//591. Tag Validator
//Given a string representing a code snippet, you need to implement a tag validator to parse the code and return whether it is valid. A code snippet is valid if all the following rules hold:
//The code must be wrapped in a valid closed tag. Otherwise, the code is invalid.
//A closed tag (not necessarily valid) has exactly the following format : <TAG_NAME>TAG_CONTENT</TAG_NAME>. Among them, <TAG_NAME> is the start tag, and </TAG_NAME> is the end tag. The TAG_NAME in start and end tags should be the same. A closed tag is valid if and only if the TAG_NAME and TAG_CONTENT are valid.
//A valid TAG_NAME only contain upper-case letters, and has length in range [1,9]. Otherwise, the TAG_NAME is invalid.
//A valid TAG_CONTENT may contain other valid closed tags, cdata and any characters (see note1) EXCEPT unmatched <, unmatched start and end tag, and unmatched or closed tags with invalid TAG_NAME. Otherwise, the TAG_CONTENT is invalid.
//A start tag is unmatched if no end tag exists with the same TAG_NAME, and vice versa. However, you also need to consider the issue of unbalanced when tags are nested.
//A < is unmatched if you cannot find a subsequent >. And when you find a < or </, all the subsequent characters until the next > should be parsed as TAG_NAME (not necessarily valid).
//The cdata has the following format : <![CDATA[CDATA_CONTENT]]>. The range of CDATA_CONTENT is defined as the characters between <![CDATA[ and the first subsequent ]]>.
//CDATA_CONTENT may contain any characters. The function of cdata is to forbid the validator to parse CDATA_CONTENT, so even it has some characters that can be parsed as tag (no matter valid or invalid), you should treat it as regular characters.
//Valid Code Examples:
//Input: "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
//Output: True
//Explanation: 
//The code is wrapped in a closed tag : <DIV> and </DIV>. 
//The TAG_NAME is valid, the TAG_CONTENT consists of some characters and cdata. 
//Although CDATA_CONTENT has unmatched start tag with invalid TAG_NAME, it should be considered as plain text, not parsed as tag.
//So TAG_CONTENT is valid, and then the code is valid. Thus return true.
//Input: "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"
//Output: True
//Explanation:
//We first separate the code into : start_tag|tag_content|end_tag.
//start_tag -> "<DIV>"
//end_tag -> "</DIV>"
//tag_content could also be separated into : text1|cdata|text2.
//text1 -> ">>  ![cdata[]] "
//cdata -> "<![CDATA[<div>]>]]>", where the CDATA_CONTENT is "<div>]>"
//text2 -> "]]>>]"
//The reason why start_tag is NOT "<DIV>>>" is because of the rule 6.
//The reason why cdata is NOT "<![CDATA[<div>]>]]>]]>" is because of the rule 7.
//Invalid Code Examples:
//Input: "<A>  <B> </A>   </B>"
//Output: False
//Explanation: Unbalanced. If "<A>" is closed, then "<B>" must be unmatched, and vice versa.
//Input: "<DIV>  div tag is not closed  <DIV>"
//Output: False
//Input: "<DIV>  unmatched <  </DIV>"
//Output: False
//Input: "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>"
//Output: False
//Input: "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>"
//Output: False
//Input: "<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>"
//Output: False
//Note:
//For simplicity, you could assume the input code (including the any characters mentioned above) only contain letters, digits, '<','>','/','!','[',']' and ' '.
//class Solution {
//public:
//    bool isValid(string code) {
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
