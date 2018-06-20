// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//13. Roman to Integer
//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//I can be placed before V (5) and X (10) to make 4 and 9. 
//X can be placed before L (50) and C (100) to make 40 and 90. 
//C can be placed before D (500) and M (1000) to make 400 and 900.
//Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
//Example 1:
//Input: "III"
//Output: 3
//Example 2:
//Input: "IV"
//Output: 4
//Example 3:
//Input: "IX"
//Output: 9
//Example 4:
//Input: "LVIII"
//Output: 58
//Explanation: C = 100, L = 50, XXX = 30 and III = 3.
//Example 5:
//Input: "MCMXCIV"
//Output: 1994
//Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
//int romanToInt(char* s) {
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





/* https://en.wikipedia.org/wiki/Roman_numerals
Symbol  I   V   X   L   C   D   M
Value   1   5   10  50  100 500 1,000

cases:

The original pattern for Roman numerals used the symbols I, V. and X (1, 5, and 10) as simple tally marks.
Each marker for 1 (I) added a unit value up to 5 (V), and was then added to (V) to make the numbers from 6 to 9:

I, II, III, IIII, V, VI, VII, VIII, VIIII, X.
The numerals for 4 (IIII) and 9 (VIIII) proved problematic (among other things, they are easily confused with III and VIII),
and are generally replaced with IV (one less than 5) and IX (one less than 10). This feature of Roman numerals is called subtractive notation.

The numbers from 1 to 10 (including subtractive notation for 4 and 9) are expressed in Roman numerals as follows:

I, II, III, IV, V, VI, VII, VIII, IX, X.[2]
The system being basically decimal, tens and hundreds follow the same pattern:

Thus 10 to 100 (counting in tens, with X taking the place of I, L taking the place of V and C taking the place of X):

X, XX, XXX, XL, L, LX, LXX, LXXX, XC, C.
Note that 40 (XL) and 90 (XC) follow the same subtractive pattern as 4 and 9.

Similarly, 100 to 1000 (counting in hundreds):

C, CC, CCC, CD, D, DC, DCC, DCCC, CM, M.
Many numbers include hundreds, units and tens. The Roman numeral system being basically decimal,
each "place" is added separately, in descending sequence from left to right, as with "arabic" numbers.
For example, the number 39 is XXXIX, (three tens and a ten less one), 246 is CCXLVI (two hundreds, a fifty less ten, a five and a one. As each place has its own notation there is no need for place keeping zeros,
so "missing places" can be simply omitted: thus 207, for instance, is written CCVII (two hundreds, a five and two ones) and 1066 becomes MLXVI (a thousand, a fifty and a ten, a five and a one)

*/

char *roman[]={
"I", "V", "X", "L", "C", "D", "M",
"I", "II", "III", "IIII", "V", "VI", "VII", "VIII", "VIIII", "X",
"IV", "IX",
"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C",
"XL"/*40*/, "XC"/*90*/,
"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M",
"XXXIX"/*39*/, "CCXLVI"/*246*/, "CCVII"/*207*/, "MLXVI"/*1066*/,
};



char *roman_1_1000[] = {
"I", "CI", "CCI", "CCCI", "CDI", "DI", "DCI", "DCCI", "DCCCI", "CMI", 
"II", "CII", "CCII", "CCCII", "CDII", "DII", "DCII", "DCCII", "DCCCII", "CMII", 
"III", "CIII", "CCIII", "CCCIII", "CDIII", "DIII", "DCIII", "DCCIII", "DCCCIII", "CMIII", 
"IV", "CIV", "CCIV", "CCCIV", "CDIV", "DIV", "DCIV", "DCCIV", "DCCCIV", "CMIV", 
"V", "CV", "CCV", "CCCV", "CDV", "DV", "DCV", "DCCV", "DCCCV", "CMV", 
"VI", "CVI", "CCVI", "CCCVI", "CDVI", "DVI", "DCVI", "DCCVI", "DCCCVI", "CMVI", 
"VII", "CVII", "CCVII", "CCCVII", "CDVII", "DVII", "DCVII", "DCCVII", "DCCCVII", "CMVII", 
"VIII", "CVIII", "CCVIII", "CCCVIII", "CDVIII", "DVIII", "DCVIII", "DCCVIII", "DCCCVIII", "CMVIII", 
"IX", "CIX", "CCIX", "CCCIX", "CDIX", "DIX", "DCIX", "DCCIX", "DCCCIX", "CMIX", 
"X", "CX", "CCX", "CCCX", "CDX", "DX", "DCX", "DCCX", "DCCCX", "CMX", 
"XI", "CXI", "CCXI", "CCCXI", "CDXI", "DXI", "DCXI", "DCCXI", "DCCCXI", "CMXI", 
"XII", "CXII", "CCXII", "CCCXII", "CDXII", "DXII", "DCXII", "DCCXII", "DCCCXII", "CMXII", 
"XIII", "CXIII", "CCXIII", "CCCXIII", "CDXIII", "DXIII", "DCXIII", "DCCXIII", "DCCCXIII", "CMXIII", 
"XIV", "CXIV", "CCXIV", "CCCXIV", "CDXIV", "DXIV", "DCXIV", "DCCXIV", "DCCCXIV", "CMXIV", 
"XV", "CXV", "CCXV", "CCCXV", "CDXV", "DXV", "DCXV", "DCCXV", "DCCCXV", "CMXV", 
"XVI", "CXVI", "CCXVI", "CCCXVI", "CDXVI", "DXVI", "DCXVI", "DCCXVI", "DCCCXVI", "CMXVI", 
"XVII", "CXVII", "CCXVII", "CCCXVII", "CDXVII", "DXVII", "DCXVII", "DCCXVII", "DCCCXVII", "CMXVII", 
"XVIII", "CXVIII", "CCXVIII", "CCCXVIII", "CDXVIII", "DXVIII", "DCXVIII", "DCCXVIII", "DCCCXVIII", "CMXVIII", 
"XIX", "CXIX", "CCXIX", "CCCXIX", "CDXIX", "DXIX", "DCXIX", "DCCXIX", "DCCCXIX", "CMXIX", 
"XX", "CXX", "CCXX", "CCCXX", "CDXX", "DXX", "DCXX", "DCCXX", "DCCCXX", "CMXX", 
"XXI", "CXXI", "CCXXI", "CCCXXI", "CDXXI", "DXXI", "DCXXI", "DCCXXI", "DCCCXXI", "CMXXI", 
"XXII", "CXXII", "CCXXII", "CCCXXII", "CDXXII", "DXXII", "DCXXII", "DCCXXII", "DCCCXXII", "CMXXII", 
"XXIII", "CXXIII", "CCXXIII", "CCCXXIII", "CDXXIII", "DXXIII", "DCXXIII", "DCCXXIII", "DCCCXXIII", "CMXXIII", 
"XXIV", "CXXIV", "CCXXIV", "CCCXXIV", "CDXXIV", "DXXIV", "DCXXIV", "DCCXXIV", "DCCCXXIV", "CMXXIV", 
"XXV", "CXXV", "CCXXV", "CCCXXV", "CDXXV", "DXXV", "DCXXV", "DCCXXV", "DCCCXXV", "CMXXV", 
"XXVI", "CXXVI", "CCXXVI", "CCCXXVI", "CDXXVI", "DXXVI", "DCXXVI", "DCCXXVI", "DCCCXXVI", "CMXXVI", 
"XXVII", "CXXVII", "CCXXVII", "CCCXXVII", "CDXXVII", "DXXVII", "DCXXVII", "DCCXXVII", "DCCCXXVII", "CMXXVII", 
"XXVIII", "CXXVIII", "CCXXVIII", "CCCXXVIII", "CDXXVIII", "DXXVIII", "DCXXVIII", "DCCXXVIII", "DCCCXXVIII", "CMXXVIII", 
"XXIX", "CXXIX", "CCXXIX", "CCCXXIX", "CDXXIX", "DXXIX", "DCXXIX", "DCCXXIX", "DCCCXXIX", "CMXXIX", 
"XXX", "CXXX", "CCXXX", "CCCXXX", "CDXXX", "DXXX", "DCXXX", "DCCXXX", "DCCCXXX", "CMXXX", 
"XXXI", "CXXXI", "CCXXXI", "CCCXXXI", "CDXXXI", "DXXXI", "DCXXXI", "DCCXXXI", "DCCCXXXI", "CMXXXI", 
"XXXII", "CXXXII", "CCXXXII", "CCCXXXII", "CDXXXII", "DXXXII", "DCXXXII", "DCCXXXII", "DCCCXXXII", "CMXXXII", 
"XXXIII", "CXXXIII", "CCXXXIII", "CCCXXXIII", "CDXXXIII", "DXXXIII", "DCXXXIII", "DCCXXXIII", "DCCCXXXIII", "CMXXXIII", 
"XXXIV", "CXXXIV", "CCXXXIV", "CCCXXXIV", "CDXXXIV", "DXXXIV", "DCXXXIV", "DCCXXXIV", "DCCCXXXIV", "CMXXXIV", 
"XXXV", "CXXXV", "CCXXXV", "CCCXXXV", "CDXXXV", "DXXXV", "DCXXXV", "DCCXXXV", "DCCCXXXV", "CMXXXV", 
"XXXVI", "CXXXVI", "CCXXXVI", "CCCXXXVI", "CDXXXVI", "DXXXVI", "DCXXXVI", "DCCXXXVI", "DCCCXXXVI", "CMXXXVI", 
"XXXVII", "CXXXVII", "CCXXXVII", "CCCXXXVII", "CDXXXVII", "DXXXVII", "DCXXXVII", "DCCXXXVII", "DCCCXXXVII", "CMXXXVII", 
"XXXVIII", "CXXXVIII", "CCXXXVIII", "CCCXXXVIII", "CDXXXVIII", "DXXXVIII", "DCXXXVIII", "DCCXXXVIII", "DCCCXXXVIII", "CMXXXVIII", 
"XXXIX", "CXXXIX", "CCXXXIX", "CCCXXXIX", "CDXXXIX", "DXXXIX", "DCXXXIX", "DCCXXXIX", "DCCCXXXIX", "CMXXXIX", 
"XL", "CXL", "CCXL", "CCCXL", "CDXL", "DXL", "DCXL", "DCCXL", "DCCCXL", "CMXL", 
"XLI", "CXLI", "CCXLI", "CCCXLI", "CDXLI", "DXLI", "DCXLI", "DCCXLI", "DCCCXLI", "CMXLI", 
"XLII", "CXLII", "CCXLII", "CCCXLII", "CDXLII", "DXLII", "DCXLII", "DCCXLII", "DCCCXLII", "CMXLII", 
"XLIII", "CXLIII", "CCXLIII", "CCCXLIII", "CDXLIII", "DXLIII", "DCXLIII", "DCCXLIII", "DCCCXLIII", "CMXLIII", 
"XLIV", "CXLIV", "CCXLIV", "CCCXLIV", "CDXLIV", "DXLIV", "DCXLIV", "DCCXLIV", "DCCCXLIV", "CMXLIV", 
"XLV", "CXLV", "CCXLV", "CCCXLV", "CDXLV", "DXLV", "DCXLV", "DCCXLV", "DCCCXLV", "CMXLV", 
"XLVI", "CXLVI", "CCXLVI", "CCCXLVI", "CDXLVI", "DXLVI", "DCXLVI", "DCCXLVI", "DCCCXLVI", "CMXLVI", 
"XLVII", "CXLVII", "CCXLVII", "CCCXLVII", "CDXLVII", "DXLVII", "DCXLVII", "DCCXLVII", "DCCCXLVII", "CMXLVII", 
"XLVIII", "CXLVIII", "CCXLVIII", "CCCXLVIII", "CDXLVIII", "DXLVIII", "DCXLVIII", "DCCXLVIII", "DCCCXLVIII", "CMXLVIII", 
"XLIX", "CXLIX", "CCXLIX", "CCCXLIX", "CDXLIX", "DXLIX", "DCXLIX", "DCCXLIX", "DCCCXLIX", "CMXLIX", 
"L", "CL", "CCL", "CCCL", "CDL", "DL", "DCL", "DCCL", "DCCCL", "CML", 
"LI", "CLI", "CCLI", "CCCLI", "CDLI", "DLI", "DCLI", "DCCLI", "DCCCLI", "CMLI", 
"LII", "CLII", "CCLII", "CCCLII", "CDLII", "DLII", "DCLII", "DCCLII", "DCCCLII", "CMLII", 
"LIII", "CLIII", "CCLIII", "CCCLIII", "CDLIII", "DLIII", "DCLIII", "DCCLIII", "DCCCLIII", "CMLIII", 
"LIV", "CLIV", "CCLIV", "CCCLIV", "CDLIV", "DLIV", "DCLIV", "DCCLIV", "DCCCLIV", "CMLIV", 
"LV", "CLV", "CCLV", "CCCLV", "CDLV", "DLV", "DCLV", "DCCLV", "DCCCLV", "CMLV", 
"LVI", "CLVI", "CCLVI", "CCCLVI", "CDLVI", "DLVI", "DCLVI", "DCCLVI", "DCCCLVI", "CMLVI", 
"LVII", "CLVII", "CCLVII", "CCCLVII", "CDLVII", "DLVII", "DCLVII", "DCCLVII", "DCCCLVII", "CMLVII", 
"LVIII", "CLVIII", "CCLVIII", "CCCLVIII", "CDLVIII", "DLVIII", "DCLVIII", "DCCLVIII", "DCCCLVIII", "CMLVIII", 
"LIX", "CLIX", "CCLIX", "CCCLIX", "CDLIX", "DLIX", "DCLIX", "DCCLIX", "DCCCLIX", "CMLIX", 
"LX", "CLX", "CCLX", "CCCLX", "CDLX", "DLX", "DCLX", "DCCLX", "DCCCLX", "CMLX", 
"LXI", "CLXI", "CCLXI", "CCCLXI", "CDLXI", "DLXI", "DCLXI", "DCCLXI", "DCCCLXI", "CMLXI", 
"LXII", "CLXII", "CCLXII", "CCCLXII", "CDLXII", "DLXII", "DCLXII", "DCCLXII", "DCCCLXII", "CMLXII", 
"LXIII", "CLXIII", "CCLXIII", "CCCLXIII", "CDLXIII", "DLXIII", "DCLXIII", "DCCLXIII", "DCCCLXIII", "CMLXIII", 
"LXIV", "CLXIV", "CCLXIV", "CCCLXIV", "CDLXIV", "DLXIV", "DCLXIV", "DCCLXIV", "DCCCLXIV", "CMLXIV", 
"LXV", "CLXV", "CCLXV", "CCCLXV", "CDLXV", "DLXV", "DCLXV", "DCCLXV", "DCCCLXV", "CMLXV", 
"LXVI", "CLXVI", "CCLXVI", "CCCLXVI", "CDLXVI", "DLXVI", "DCLXVI", "DCCLXVI", "DCCCLXVI", "CMLXVI", 
"LXVII", "CLXVII", "CCLXVII", "CCCLXVII", "CDLXVII", "DLXVII", "DCLXVII", "DCCLXVII", "DCCCLXVII", "CMLXVII", 
"LXVIII", "CLXVIII", "CCLXVIII", "CCCLXVIII", "CDLXVIII", "DLXVIII", "DCLXVIII", "DCCLXVIII", "DCCCLXVIII", "CMLXVIII", 
"LXIX", "CLXIX", "CCLXIX", "CCCLXIX", "CDLXIX", "DLXIX", "DCLXIX", "DCCLXIX", "DCCCLXIX", "CMLXIX", 
"LXX", "CLXX", "CCLXX", "CCCLXX", "CDLXX", "DLXX", "DCLXX", "DCCLXX", "DCCCLXX", "CMLXX", 
"LXXI", "CLXXI", "CCLXXI", "CCCLXXI", "CDLXXI", "DLXXI", "DCLXXI", "DCCLXXI", "DCCCLXXI", "CMLXXI", 
"LXXII", "CLXXII", "CCLXXII", "CCCLXXII", "CDLXXII", "DLXXII", "DCLXXII", "DCCLXXII", "DCCCLXXII", "CMLXXII", 
"LXXIII", "CLXXIII", "CCLXXIII", "CCCLXXIII", "CDLXXIII", "DLXXIII", "DCLXXIII", "DCCLXXIII", "DCCCLXXIII", "CMLXXIII", 
"LXXIV", "CLXXIV", "CCLXXIV", "CCCLXXIV", "CDLXXIV", "DLXXIV", "DCLXXIV", "DCCLXXIV", "DCCCLXXIV", "CMLXXIV", 
"LXXV", "CLXXV", "CCLXXV", "CCCLXXV", "CDLXXV", "DLXXV", "DCLXXV", "DCCLXXV", "DCCCLXXV", "CMLXXV", 
"LXXVI", "CLXXVI", "CCLXXVI", "CCCLXXVI", "CDLXXVI", "DLXXVI", "DCLXXVI", "DCCLXXVI", "DCCCLXXVI", "CMLXXVI", 
"LXXVII", "CLXXVII", "CCLXXVII", "CCCLXXVII", "CDLXXVII", "DLXXVII", "DCLXXVII", "DCCLXXVII", "DCCCLXXVII", "CMLXXVII", 
"LXXVIII", "CLXXVIII", "CCLXXVIII", "CCCLXXVIII", "CDLXXVIII", "DLXXVIII", "DCLXXVIII", "DCCLXXVIII", "DCCCLXXVIII", "CMLXXVIII", 
"LXXIX", "CLXXIX", "CCLXXIX", "CCCLXXIX", "CDLXXIX", "DLXXIX", "DCLXXIX", "DCCLXXIX", "DCCCLXXIX", "CMLXXIX", 
"LXXX", "CLXXX", "CCLXXX", "CCCLXXX", "CDLXXX", "DLXXX", "DCLXXX", "DCCLXXX", "DCCCLXXX", "CMLXXX", 
"LXXXI", "CLXXXI", "CCLXXXI", "CCCLXXXI", "CDLXXXI", "DLXXXI", "DCLXXXI", "DCCLXXXI", "DCCCLXXXI", "CMLXXXI", 
"LXXXII", "CLXXXII", "CCLXXXII", "CCCLXXXII", "CDLXXXII", "DLXXXII", "DCLXXXII", "DCCLXXXII", "DCCCLXXXII", "CMLXXXII", 
"LXXXIII", "CLXXXIII", "CCLXXXIII", "CCCLXXXIII", "CDLXXXIII", "DLXXXIII", "DCLXXXIII", "DCCLXXXIII", "DCCCLXXXIII", "CMLXXXIII", 
"LXXXIV", "CLXXXIV", "CCLXXXIV", "CCCLXXXIV", "CDLXXXIV", "DLXXXIV", "DCLXXXIV", "DCCLXXXIV", "DCCCLXXXIV", "CMLXXXIV", 
"LXXXV", "CLXXXV", "CCLXXXV", "CCCLXXXV", "CDLXXXV", "DLXXXV", "DCLXXXV", "DCCLXXXV", "DCCCLXXXV", "CMLXXXV", 
"LXXXVI", "CLXXXVI", "CCLXXXVI", "CCCLXXXVI", "CDLXXXVI", "DLXXXVI", "DCLXXXVI", "DCCLXXXVI", "DCCCLXXXVI", "CMLXXXVI", 
"LXXXVII", "CLXXXVII", "CCLXXXVII", "CCCLXXXVII", "CDLXXXVII", "DLXXXVII", "DCLXXXVII", "DCCLXXXVII", "DCCCLXXXVII", "CMLXXXVII", 
"LXXXVIII", "CLXXXVIII", "CCLXXXVIII", "CCCLXXXVIII", "CDLXXXVIII", "DLXXXVIII", "DCLXXXVIII", "DCCLXXXVIII", "DCCCLXXXVIII", "CMLXXXVIII", 
"LXXXIX", "CLXXXIX", "CCLXXXIX", "CCCLXXXIX", "CDLXXXIX", "DLXXXIX", "DCLXXXIX", "DCCLXXXIX", "DCCCLXXXIX", "CMLXXXIX", 
"XC", "CXC", "CCXC", "CCCXC", "CDXC", "DXC", "DCXC", "DCCXC", "DCCCXC", "CMXC", 
"XCI", "CXCI", "CCXCI", "CCCXCI", "CDXCI", "DXCI", "DCXCI", "DCCXCI", "DCCCXCI", "CMXCI", 
"XCII", "CXCII", "CCXCII", "CCCXCII", "CDXCII", "DXCII", "DCXCII", "DCCXCII", "DCCCXCII", "CMXCII", 
"XCIII", "CXCIII", "CCXCIII", "CCCXCIII", "CDXCIII", "DXCIII", "DCXCIII", "DCCXCIII", "DCCCXCIII", "CMXCIII", 
"XCIV", "CXCIV", "CCXCIV", "CCCXCIV", "CDXCIV", "DXCIV", "DCXCIV", "DCCXCIV", "DCCCXCIV", "CMXCIV", 
"XCV", "CXCV", "CCXCV", "CCCXCV", "CDXCV", "DXCV", "DCXCV", "DCCXCV", "DCCCXCV", "CMXCV", 
"XCVI", "CXCVI", "CCXCVI", "CCCXCVI", "CDXCVI", "DXCVI", "DCXCVI", "DCCXCVI", "DCCCXCVI", "CMXCVI", 
"XCVII", "CXCVII", "CCXCVII", "CCCXCVII", "CDXCVII", "DXCVII", "DCXCVII", "DCCXCVII", "DCCCXCVII", "CMXCVII", 
"XCVIII", "CXCVIII", "CCXCVIII", "CCCXCVIII", "CDXCVIII", "DXCVIII", "DCXCVIII", "DCCXCVIII", "DCCCXCVIII", "CMXCVIII", 
"XCIX", "CXCIX", "CCXCIX", "CCCXCIX", "CDXCIX", "DXCIX", "DCXCIX", "DCCXCIX", "DCCCXCIX", "CMXCIX", 
"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M", 
};



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int romanToInt(char* s) {
	/* sanity check */
	int d = 0;
	int i = 0;
	while ('\0' != s[i])
	{
		switch (s[i])
		{
		case 'M' :
			d += 1000;
			break;
		case 'D' :
			d += 500;
			break;
		case 'C' :
			if(s[i+1]=='M' || s[i+1]=='D')
			{
				d -= 100;
			}
			else
			{
				d += 100;
			}
			break;
		case 'L' :
			d += 50;
			break;
		case 'X' :
			if(s[i+1]=='C' || s[i+1]=='L')
			{
				d -= 10;
			}
			else
			{
				d += 10;
			}
			break;
		case 'V' :
			d += 5;
			break;
		case 'I' :
			if(s[i+1]=='X' || s[i+1]=='V')
			{
				d -= 1;
			}
			else
			{
				d += 1;
			}
			break;
		default :
			return -1;
		}

		i++;
	}

	return d;
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





	int index = 0;
	int size = sizeof(roman)/sizeof(roman[0]);
	for (index=0; index<size; index++)
	{
		int d = romanToInt(roman[index]);
		fprintf(stderr, "%s [convert to] %d \n\n", roman[index], d);
	}

	size = sizeof(roman_1_1000)/sizeof(roman_1_1000[0]);
	for (index=0; index<size; index++)
	{
		int d = romanToInt(roman_1_1000[index]);
		fprintf(stderr, "%s [convert to] %d \n\n", roman_1_1000[index], d);
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
