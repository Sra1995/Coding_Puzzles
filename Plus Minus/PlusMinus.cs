using System;
using System.Collections.Generic;

class Program
{
    static void PlusMinus(List<int> arr)
    {
        double positives = 0;
        double negatives = 0;
        double zeros = 0;

        foreach (int num in arr) 
        {
            if (num > 0)
            {
                positives += 1;
            }
            else if (num < 0)
            {
                negatives += 1;
            }
            else
            {
                zeros += 1;
            }
        }

        Console.WriteLine($"{positives / arr.Count:F6}");
        Console.WriteLine($"{negatives / arr.Count:F6}");
        Console.WriteLine($"{zeros / arr.Count:F6}");
    }

    static void Main()
    {
        List<int> arr = new List<int> { -4, 3, -9, 0, 4, 1 };

        PlusMinus(arr);
    }
}
