//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Esta clase contiene un SIMBOLO
// Al crearse asigna su precedencia de entrada o de pila
// y le permite comparar la precedencia correcta con otro simbolo

#ifndef EXPSYMBOL
#define EXPSYMBOL
class expressionSymbol{
private:
  _enum_base::t_aritmeticExpression op;
  int inputPrecedence;
	int stackPrecedence;

public:
  expressionSymbol();
	expressionSymbol(_enum_base::t_aritmeticExpression ch);
	_enum_base::t_aritmeticExpression getToken() const;
	friend bool operator>= (const expressionSymbol& left,const expressionSymbol& right);
};//__________________________________________________________________________________________
#endif

