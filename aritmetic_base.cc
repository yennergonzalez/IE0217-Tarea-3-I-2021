//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;
#include "enum_base.h"
#include "aritmetic_base.h"


///show_tokenlist("Infix:",t_infixExpression);
///show_tokenlist("Posfix:",t_postfixExpression);
void  _aritmetic_base::show_tokenlist(const char *msg,queue<t_aritmeticExpression> copy)
{
  int length=copy.size();
  cout << msg << " " << endl;
  for (int i=0;i< length;i++)
  {
    t_aritmeticExpression token=copy.front();
    cout << "<";
    switch (token)
    {
      case token_mas:      cout << "token_mas : ";break;
      case token_menos:    cout << "token_menos : ";break;
      case token_por:      cout << "token_por : ";break;
      case token_div:      cout << "token_div : ";break;
      case token_resto:    cout << "token_resto : ";break;
      case token_pot:      cout << "token_pot : ";break;
      case token_coseno:   cout << "token_coseno : ";break;
      case token_seno:     cout << "token_seno : ";break;
      case token_tangente: cout << "token_tangente : ";break;
      case token_cosenoh:  cout << "token_cosenoh : ";break;
      case token_senoh:    cout << "token_senoh : ";break;
      case token_ln:       cout << "token_ln : ";break;
      case token_exp:      cout << "token_exp : ";break;
      case token_log:      cout << "token_log : ";break;
      case token_pizq:     cout << "token_pizq : ";break;
      case token_pder:     cout << "token_pder : ";break;
      case token_numero:   cout << "token_mumero : ";break;
      case token_variable: cout << "token_variable : ";break;
      //default: break;
    }
    cout <<  token << ">" << endl;
    copy.pop();
  }
  cout << endl;
}//_______________________________________________________

void  _aritmetic_base::show_data(void)
{
  queue<float> copy(DataQueue);
  int length=copy.size();
  cout << "DATA QUEUE ";
  for (int i=0;i< length;i++)
  {
    cout << "<DATA:" << copy.front() << ">";
    copy.pop();
  }
  cout << endl;
}//_______________________________________________________

void  _aritmetic_base::show_variables(void)
{
  queue<string> copy(VariableQueue);
  int length=copy.size();
  cout << "VARIABLE QUEUE ";
  for (int i=0;i< length;i++)
  {
    cout << "<VARIABLE:" << copy.front() << ">";
    copy.pop();
  }
  cout << endl;
}//_______________________________________________________

bool  _aritmetic_base::isOperator(t_aritmeticExpression token) const
{
  switch(token)
  {
    case token_mas:
    case token_menos:
    case token_por:
    case token_div:
    case token_pot: return true;
    default:return false;
  }
}//_______________________________________________________

bool  _aritmetic_base::isFunction(t_aritmeticExpression token) const
{
  switch(token)
  {
    case token_coseno:
    case token_seno:
    case token_cosenoh:
    case token_senoh:
    case token_tangente:
    case token_ln:
    case token_log:
    case token_exp:return true;
    default:return false;
  }
}//_______________________________________________________
