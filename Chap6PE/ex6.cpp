#include <iostream>

using namespace std;

enum MsgCodes{
    SUCCESS,
    OVERFLOW_ERROR,
    UNDERFLOW_ERROR,
    ZERO_DIVISION_ERROR,
}
enum OperationCodes{
    ADD,
    SUBSTRACT,
    DIVIDE,
    MULTIPLY
}


MsgCodes calculator(int &op1, int &op2, int &res, OperationCodes op_code){
    switch(op_code){
        case ADD:
            if(op1 + op2 > 100000)
                return OVERFLOW_ERROR;
            res = op1 + op2;
            return SUCCESS;
        case SUBSTRACT:
            if(op1 - op2 < 100000)
                return UNDERFLOW_ERROR;
            res = op1 - op2;
            return SUCCESS
        case DIVIDE:
            if(op2 == 0)
                return ZERO_DIVISION_ERROR;
            res = op1/op2;
            return SUCCESS;
        case MULTIPLY:
            if(op1 * op2 > 100000)
                return OVERFLOW_ERROR;
            res = op1 * op2;
            return SUCCESS;
    }
}

int calculator(int &op1, int &op2, int &res, int op_code){
    switch(op_code){
        case 0:
            if(op1 + op2 > 100000)
                return 1;
            res = op1 + op2;
            return 0;
        case 1:
            if(op1 - op2 < 100000)
                return 2;
            res = op1 - op2;
            return 0
        case 2:
            if(op2 == 0)
                return 3;
            res = op1/op2;
            return 0;
        case 3:
            if(op1 * op2 > 100000)
                return 1;
            return 0;
    }
}

/*
    Ambas funciones calculator hacen lo mismo pero se puede observar
    que en la segunda la cual usa solo enteros se pierde mucha 
    legibilidad en cambio en la primera esta mucho mas claro lo que hace
    la funcion y los diferentes casos en los que retorna
*/