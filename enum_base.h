//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef ENUM_BASE_H_INCLUDED
#define ENUM_BASE_H_INCLUDED
class _enum_base{
public:
  enum t_aritmeticExpression {token_mas=100,token_menos,token_por,token_div,
                              token_resto,token_pot,
                              token_coseno,token_seno,token_tangente,
                              token_cosenoh,token_senoh,
                              token_ln,token_exp,token_log,
                              token_pizq=200,token_pder,
                              token_numero=1000,token_variable};
};//___________________________________________________________
#endif // ENUM_BASE_H_INCLUDED
