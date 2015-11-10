
public class Main{
    public static int fun(int k){
        k += 4;
        return 3 * k - 1;
    }

    public static void main(String[]args){
        int i = 10;
        int j = 10;
        int sum1, sum2;
        sum1 = (i / 2) + fun(i);
        System.out.format("Sum1 is %d\n", sum1);
        sum2 = fun(j) + (j / 2);
        System.out.format("Sum2 is %d\n", sum2);
        /*
            Resultado:
            Sum1 is 46
            Sum2 is 46

            En el caso de Java, no existe el problema que cambie
            el valor en la funcion ya que los parametros se pasan
            por valor y no por referencia entonces en ambos casos
            se mantiene el valor de i o j y el resultado siempre es 46
        */
    }
}
