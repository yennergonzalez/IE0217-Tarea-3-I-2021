//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef INFIX2POSTFIX
#define INFIX2POSTFIX

// labels designating the parentheses characters
const char lParen  = '(', rParen = ')';

class infix2Postfix :public virtual _aritmetic_base{
private:
	string infixExpression;
	stack<expressionSymbol> operatorStack;
	map<string,t_aritmeticExpression> funcionStr2Tokens;

  void make_funcionTokens(void);
  void popStackHigherOrEqualPrecedence2Posfix(const expressionSymbol& op);
  bool evaluate_ifInt(int&);
  bool evaluate_ifFloat(int&);
  bool evaluate_ifFunctions(int &i);
  bool evaluate_ifVar(int &i);
  bool resolveLex(void);  /// FUNCION PRINCIPAL de LEX -> TOKEN + LISTAS de componentes.

public:
  infix2Postfix();
	infix2Postfix(const string& infixExp);
	void setInfixExp(const string& infixExp);
  map<string,float>& get_VarMap(void);
	bool makepostfix();
};//_____________________________________________________________________________________
#endif
