using System;
using System.Collections.Generic;

class Program
{
    static List<int> BreakingRecords(List<int> scores)
    {
        int minimum = scores[0];
        int maximum = scores[0];
        List<int> record = new List<int> { 0, 0 }; // [max_breaks, min_breaks]

        for (int i = 1; i < scores.Count; i++)
        {
            if (scores[i] > maximum)
            {
                maximum = scores[i];
                record[0]++;
            }
            if (scores[i] < minimum)
            {
                minimum = scores[i];
                record[1]++;
            }
        }

        return record;
    }

    static void Main(string[] args)
    {
        List<int> scores = new List<int> { 12, 24, 10, 24 };
        List<int> result = BreakingRecords(scores);
        Console.WriteLine($"Max Breaks: {result[0]}, Min Breaks: {result[1]}");
    }
}
