class ForScope{
    public static void main(String[] args) {
        int x = 0;
        for (int i=0; i< 100 ; i++) {
            x += i;
        }
        System.out.println(i);
    }
}

/*

En Java, las variables declaradas en un for, solo son validas en ese rango.
Si se quiere usar en otro ambito, generara un error:

ForScope.java:7: error: cannot find symbol
        System.out.println(i);
                           ^
  symbol:   variable i
  location: class ForScope
1 error


*/