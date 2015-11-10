using System.IO;
using System;

class Program
{
    static int fun(ref int a ){
        a += 4;
        return 3 * a -1;
    }
    static void Main()
    {
        int i = 10;
        int j = 10;
        int sum1, sum2;
        sum1 = (i / 2) + fun(ref i);
        Console.WriteLine(sum1);
        sum2 = fun(ref j) + (j / 2);
        Console.WriteLine(sum2);
    }
}
