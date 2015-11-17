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
        /*
            Resultado
            46
            48
            En C#, a diferencia de Java, si se puede hacer paso de valores por referencia
            utilizando la palabra reservada ref en el paramtro y al pasar
            el valor. 
            El resultado es similar al obteindo en C y C++, por lo que se ve que tambien
            se evalua en orden las expresiones.
        */
    }
}
