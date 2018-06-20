using System;

/// <summary>
/// Summary description for Solution
/// </summary>
public class Solution
{
	public int[] TwoSum(int[] nums, int target)
    {
        //
        // TODO: Add constructor logic here
        //
        int[] result = new int[2];
        int size = nums.Length;
        for (int i = 0; i < size; i = i + 1)
        {
            Console.WriteLine("value of nums: {0} {1}", i, nums[i]);
            result[0] = nums[i];
            int minus = target - nums[i];
            for (int j = 1; j < size; j = j + 1)
            {
                if (nums[j] == minus)
                {
                    result[1] = nums[j];
                }
            }
        }
        return result;
    }

    public void DumpArray(int[] nums, int start, int end)
    {
        //
        // TODO: Add constructor logic here
        //
        int size = nums.Length;
        Console.WriteLine("\r\n start, DumpArray, {0}-----------------------------------\r\n", size);
        for (int i = start; i <= end; i = i + 1)
        {
            Console.WriteLine("value of nums: {0} {1}", i, nums[i]);
        }
        Console.WriteLine("\r\n  end, DumpArray, {0}-----------------------------------\r\n", size);
    }
}
