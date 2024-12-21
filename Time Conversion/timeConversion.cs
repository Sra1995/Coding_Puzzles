using System;

class Program
{
    static string TimeConversion(string s)
    {
        // Extract the components
        string zone = s.Substring(s.Length - 2); // AM or PM
        int hour = int.Parse(s.Substring(0, 2)); // Extract hour as integer
        int minute = int.Parse(s.Substring(3, 2)); // Extract minute as integer
        int second = int.Parse(s.Substring(6, 2)); // Extract second as integer

        // Convert based on AM/PM
        if (zone == "PM" && hour != 12)
        {
            hour += 12;
        }
        else if (zone == "AM" && hour == 12)
        {
            hour = 0;
        }

        // Format the result
        return $"{hour:D2}:{minute:D2}:{second:D2}";
    }

    static void Main(string[] args)
    {
        string time = "12:01:00PM";
        Console.WriteLine(TimeConversion(time)); // Output: 12:01:00
        string time2 = "01:01:00PM";
        Console.WriteLine(TimeConversion(time2)); // Output: 13:01:00
    }
}
