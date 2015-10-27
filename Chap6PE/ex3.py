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


if __name__ == '__main__':
    main()