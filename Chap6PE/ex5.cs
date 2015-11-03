using System.IO;
using System;

class Program
{
    enum TestEnum{
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE
    };

    static void Main()
    {
        //Console.WriteLine(TestEnum.ONE + TestEnum.TWO); ERROR
        Console.WriteLine(TestEnum.SIX - TestEnum.THREE); // 3
        //Console.WriteLine(TestEnum.FIVE * TestEnum.EIGHT); ERROR
        //Console.WriteLine(TestEnum.SIX / TestEnum.TWO); ERROR
        /*
            C# solo soporta la operacion de resta en tipos enumerados
        */
        TestEnum test = TestEnum.ONE;
        Console.WriteLine(test); // ONE
        test = TestEnum.TWO; 
        Console.WriteLine(test); // TWO
        test = (TestEnum) 5;
        Console.WriteLine(test); // FIVE
        /*
            Soportan instanciación y asignacion de valores
            definidos en la enumeración
            
            No soportan asignaciones de enteros de manera directa
            test = 5; genera un error de casteo implicito 
        */

    }
}
