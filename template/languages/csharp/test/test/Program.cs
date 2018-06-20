using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/* https://www.tutorialspoint.com/csharp/index.htm */

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime beforDT = System.DateTime.Now;

            int[] nums = new int[5] { 8, 10, 2, 6, 3 };
            int target = 8;

            Solution s = new Solution();
            int[] result = s.TwoSum(nums, target);
            Console.WriteLine("result, {0} {1}", nums[result[0]], nums[result[1]]);
            s.DumpArray(result, 0, result.Length - 1);


            /* long long ago */
            DateTime afterDT = System.DateTime.Now;
            TimeSpan ts = afterDT.Subtract(beforDT);
            Console.WriteLine("\r\n Run time is {0} ms. \r\n", ts.TotalMilliseconds);

            /* my first program in C# */
            Console.WriteLine("Hello World!");
            Console.ReadKey();
        }
    }
}
