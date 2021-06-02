//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <stack>
#include <queue>
using namespace std;
#include "enum_base.h"
#include "expsymbol.h"
//+++++++++++++++++++++++
// class expressionSymbol
//++++++++++++++++++++++++
expressionSymbol::expressionSymbol()
{
}//______________________________________________________

expressionSymbol::expressionSymbol(_enum_base::t_aritmeticExpression token)
{
	op = token;    // assign operator

	switch(op)
	{
		case _enum_base::token_mas:
		case _enum_base::token_menos: inputPrecedence = 1;
                                  stackPrecedence = 1;
                                  break;

		case _enum_base::token_por:
		case _enum_base::token_resto:
		case _enum_base::token_div:   inputPrecedence = 2;
                                  stackPrecedence = 2;
                                  break;

		case _enum_base::token_pot:   inputPrecedence = 4;
                                  stackPrecedence = 3;
                                  break;

		case _enum_base::token_coseno:
		case _enum_base::token_cosenoh:
		case _enum_base::token_seno:
		case _enum_base::token_senoh:
		case _enum_base::token_tangente:
		case _enum_base::token_ln:
		case _enum_base::token_log:
		case _enum_base::token_exp:	  inputPrecedence = 4;
                                  stackPrecedence = 3;
                                  break;

    case _enum_base::token_pizq:  inputPrecedence = 5;
                                  stackPrecedence = -1;
                                  break;

		case _enum_base::token_pder:  inputPrecedence = 0;
                                  stackPrecedence = 0;
                                  break;
    default: break;
	}
}//______________________________________________________

_enum_base::t_aritmeticExpression expressionSymbol::getToken() const
{
	return op;
}//______________________________________________________

bool operator>= (const expressionSymbol& left, const expressionSymbol& right )
{
	return left.stackPrecedence >= right.inputPrecedence;
}//______________________________________________________

