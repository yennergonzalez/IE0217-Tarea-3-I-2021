//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef ARITMETIC_BASE_INCLUDED
#define ARITMETIC_BASE_INCLUDED

class _aritmetic_base :public _enum_base{
protected:
  queue<t_aritmeticExpression> t_infixExpression;
  queue<t_aritmeticExpression> t_postfixExpression;
  queue<string>                VariableQueue;
  queue<float>                 DataQueue;
 	map<string,float>            Map_variables_float;

  void show_tokenlist(const char*,queue<t_aritmeticExpression> copy);
  void show_data(void);
  void show_variables(void);
  bool isOperator(t_aritmeticExpression token) const;
  bool isFunction(t_aritmeticExpression token) const;
};//______________________________________________________


#endif // ARITMETIC_BASE_INCLUDED
