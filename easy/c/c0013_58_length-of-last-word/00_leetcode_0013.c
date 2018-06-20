// DRUNKWATER TEMPLATE(add description and prototypes)
// Question Title and Description on leetcode.com
// Function Declaration and Function Prototypes on leetcode.com
//58. Length of Last Word
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//If the last word does not exist, return 0.
//Note: A word is defined as a character sequence consists of non-space characters only.
//Example:
//Input: "Hello World"
//Output: 5
//int lengthOfLastWord(char* s) {
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



char *words[] ={

"hnida", "tidpmsyq", "ob", "b rbvcrzftai", "kgzwfhmmy awmg", "apxdujnsnasjnhw be", "pcxdiqifipjmq", "cazafgiztmcwmyqn jvuwkoypcysqtqxt", "tma ynjsyigtkchzzyc gqdto", "oo", "yabzmfbcl ozdcrt tqclihkv", "qrtbz aysgn", "bjmbzpqojvsqnxgmitldjmwyspfmbevpd", "mjelrp", "dulgbi qjol dbuxbnhx", "iasvktmjnqqtbireckjdc nvrnrctaqpx", 
"skzlr", "sxy qczqlawc", "qdvonzyygrkwpaaoqxdsq azbdngtwj", "gahaekqgjd", "vhkfnbqzyynricbzuwg bpfz", "valhluqnaxrlbunodsethrijcajkydi", "lx g", "hxzxsnxwkeqwqlvtigacvyknjzwq", "ohwfhuegsciiiztxpoprvjzynsygdrfwx", "cyivczflv", "plmylfcz", " tzoemzlmgtlsztnnjsgtgzezoh", "zvrtzoegfx", "edzyrxtv", "vxhevcm", "gatk  dxc us zqteqqv", 
"zmofyxnxbpwm", "jowluseskteyjlvcvsjng", "vxqfp psdfp hazdgkg njmokntq", "to", " koup", "akchbftqrxn", "dxsbucqgttdsizevs", "kynlazioydpqdvizrnuwfjueo", "xhdwqqbqupvgm", "zfvmz dhox xnxxhbxqs", "radxrmgruwdaawbllnheczcfxsslw", "jzjknovqpnyqkzgo", "kouhftejshhhy", "fhtpzl caq vn yuh", "vykyaflanvbzyfsuwksw nhh", "cz", 
"xuwkwrvfvafvpyeel gn bhgvp", "ohtzmgb xpilzzuzdesz jcxrzyv", "oix", "omwbw", "hvoahsvlw wkt x dbfka", "nfsdows ko", "xdedsadwyhcwpgvdjskr ze", "agyzes ahsb", "ntweohhozquww", "sgdkpmlmnrxjwse exekubptqm", "iwretncerlespvpxxbbytadjitv", "hio", "hryzrfcsgmsm bwbzjsyuxg", "ibaudzsrthjaomqot", "ryufpxsxrojmjpefuwdoknfjazgsgsenm", "jlstpkbvcdqsexyp", 
"coliddwmsywoddmmonn", "wix", "nnqvjqg zuaxmthnkemkzmhmsisacxhr", "bkcpcxikrgveghpgvhqjhpiopueviu", "hrluoiiln", "yb rwt", "zd", "teqyrvonltgmktf", "hnkfcbd", "qojapuofa dcbjkjvlwvrjojct", "ezsayvkbfiug uszd pwnpkmblocyxos", "mfmjxkxmmd", "ghghfjko h qnfpmnoidahnigl", "nzreoioelda cgd", "dpjafnnodzuri wstztg", "wljmxuwbjuiuymxhj", 

};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int lengthOfLastWord(char* s) {
	/* sanity check */
	char *p =s;
	char *tag =s;

	int length = 0;

	while ('\0' != *p)
	{
		if (' '==*p)
		{
			tag = p;
		}

		p++;
	}
	if (tag==s)
	{
		length = p-tag;
	}
	else
	{
		length = p-tag-1;
	}

	return length;
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


	fprintf(stderr, "%s=%d\n", ("hello world"), lengthOfLastWord("hello world") );

	int index = 0;
	int size = sizeof(words)/sizeof(words[0]);
	for (index=0; index<size; index++)
	{
		fprintf(stderr, "%s=%d\n", (words[index]), lengthOfLastWord(words[index]) );
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
