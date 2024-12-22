using System;
using System.Collections.Generic;

class Solution {
    static int DivisibleSumPairs(int n, int k, int[] ar) {
        int[] remainderCount = new int[k];
        int count = 0;

        foreach (int num in ar) {
            int remainder = num % k;
            int complement = (k - remainder) % k;

            count += remainderCount[complement];
            remainderCount[remainder]++;
        }

        return count;
    }

    static void Main(string[] args) {
        int[] ar = { 1, 3, 2, 6, 1, 2 };
        int k = 3;
        Console.WriteLine(DivisibleSumPairs(ar.Length, k, ar)); // Output: 5
    }
}
