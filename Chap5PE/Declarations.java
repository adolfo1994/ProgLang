
class Declarations {
    public static void func(){
        x = 21;
        int x;
        x = 42;

    }
    public static void main(String[] args) {
        func();
    }
    
}

/*
En java igualmente se genera un error debido a que no se declaró previamente la variable
por lo que no encuentra el simbolo

Declarations.java:4: error: cannot find symbol
        x = 21;
        ^
  symbol:   variable x
  location: class Declarations
1 error

*/