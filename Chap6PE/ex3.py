import dis

x = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
y = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
]

z = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
]


def multiply():
    for i in xrange(3):
        for j in xrange(3):
            for k in xrange(3):
                z[i][j] += x[i][k] * y[k][j]


def main():
    multiply()
    for r in z:
        print r

    print "Dissasembler"
    print dis.dis(multiply)


"""
    En el disassembler obtenido del codigo anterior
    ...
     25          57 LOAD_GLOBAL              1 (z)
             60 LOAD_FAST                0 (i)
             63 BINARY_SUBSCR       
             64 LOAD_FAST                1 (j)
             67 DUP_TOPX                 2
             70 BINARY_SUBSCR       
             71 LOAD_GLOBAL              2 (x)
             74 LOAD_FAST                0 (i)
             77 BINARY_SUBSCR       
             78 LOAD_FAST                2 (k)
             81 BINARY_SUBSCR       
             82 LOAD_GLOBAL              3 (y)
             85 LOAD_FAST                2 (k)
             88 BINARY_SUBSCR       
             89 LOAD_FAST                1 (j)
             92 BINARY_SUBSCR       
             93 BINARY_MULTIPLY     
             94 INPLACE_ADD         
             95 ROT_THREE           
             96 STORE_SUBSCR        
             97 JUMP_ABSOLUTE
    ...
    Se ve que se llama continuamente a BINARY_SUBSCR, instruccion 
    que verifica el rango del indice. En total se utilizan 48 instrucciones
    en bytecode de python, en las cuales se llama 6 veces a la verificacion
    de rangos 


"""

if __name__ == '__main__':
    main()
