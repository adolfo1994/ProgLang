public class Main {

    public static int func(int a){
        System.out.println("From func");
        return (a * (a+1))/2;
    }

    public static void main(String[] args) {
        System.out.println( "From main," + Integer.toString(func(5)) + "!!" );        
    }
    /* Imprime:
        From func
        From main,15!!

        Evalua primero la funcion luego hace la operacion en main.
        En Java no es posible generar efectos colaterales ya que 
        no permite el paso por referencia
        
    */
}