

def main():
    a = 1 + 2 * 3  # (1+2)*3 o 1 + (2*3)
    print a  # 1 + (2 * 3) = 7

    b = 1 - 2 * 3  # (1-2) * 3 o 1 - (2*3)
    print b  # 1 - (2 * 3) = -5

    # La multiplicacion tiene mas precedencia que la suma y la resta

    c = 1 + 2 / 3.0  # (1+2)/3.0 o 1 + (2/3.0)
    print c  # 1 + (2 / 3.0) = 1.666

    d = 1 - 2 / 3.0  # (1-2)/3.0 o 1 - (2/3.0)
    print d  # 1 - (2 / 3.0) = 0.3333

    # La division tiene mas precedencia que la suma y resta

    e = 2 + 2 > 3  # (2 + 2) > 3 = True o 2 + (2 > 3) = 3
    print e  # True

    # los operadores aritmeticos tienen precedencia sobre los booleanos

    f = 2 ** 2 / 4.0  # (2**2)/4.0 = 1 o 2 ** (2/4.0) = 1.4142
    print f  # 1

    # operador de exponenciación tiene mas prioridad que el de división/multiplicación

if __name__ == '__main__':
    main()
