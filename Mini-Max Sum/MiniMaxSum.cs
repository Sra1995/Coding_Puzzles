using System;
using System.Linq;

class Program
{
    static void MiniMaxSum(int[] arr)
    {
        long total = 0;
        
        // Sum all elements in the array
        foreach (int num in arr)
        {
            total += num;
        }
        
        // Find the minimum and maximum elements
        int lowest = arr.Min();
        int highest = arr.Max();
        
        // Calculate the output values
        long output1 = total - highest;  // Total minus the maximum element
        long output2 = total - lowest;   // Total minus the minimum element
        
        // Print the results
        Console.WriteLine($"{output1} {output2}");
    }

    static void Main()
    {
        int[] arr = {1, 3, 5, 7, 9};
        MiniMaxSum(arr);
    }
}

// output 16 24
