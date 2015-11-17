using System.IO;
using System;

class Program
{
    static int func(ref int a){
        a = a+1;
        return (a * (a+1))/2;
    }
    static void Main()
    {
        int a = 5;
        Console.WriteLine(a + func(ref a));
    }
}

/*
 Imprime 26
 C# primero resuelve en orden los operandos en orden entonces a vale 5 y luego llama 
 a la función la que retorna 21 entonces el resultado es 26 y el valor de a no se ve alterado.
 Pero como se hace en orden, si se llama a la funcion primero : func(ref a) + a; el resultado 
 es 27.
*/