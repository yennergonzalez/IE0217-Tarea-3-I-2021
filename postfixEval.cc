//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//IE-217 Estructuras Abstractas y algoritmos para Ingeniería
//Modificación académica para código de UCR.
//Modificación: Freddy Rojas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <math.h>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
#include "enum_base.h"
#include "aritmetic_base.h"
#include "postfixEval.h"
#include "d_except.h"

void postfixEval::getOperand(float& value)
{
	if (operandStack.empty())	throw  expressionError("postfixEval: Too many operators");
	value = operandStack.top();
	operandStack.pop();
}//________________________________________________________________

void postfixEval::getOperands(float& left, float& right)
{
	if (operandStack.empty())	throw  expressionError("postfixEval: Too many operators");

	right = operandStack.top();
	operandStack.pop();

  if (operandStack.empty())	throw  expressionError("postfixEval: Too many operators");
	left = operandStack.top();
	operandStack.pop();
}//________________________________________________________________

float postfixEval::compute(float left, float right, t_aritmeticExpression op) const
{
	float value;
	switch(op)
	{
		case token_mas:	  value = left + right;break;
		case token_menos:	value = left - right;break;
		case token_por:	  value = left * right;break;
		case token_div:	  if (right == 0)
                          throw expressionError("postfixEval: divide by 0");
                      value = left / right;
                      break;

		case token_pot:  	if (left == 0 && right == 0)
                          throw	expressionError("postfixEval: 0^0 undefined");

                      value = 1;
                    while (right > 0)
                    {
                      value *= left;
                    right--;
                    }
                    break;

    case token_coseno:
                    value=cos(right);
                    break;

    case token_seno:
                    value=sin(right);
                    break;

    case token_tangente:
                    value=tan(right);
                    break;

    case token_ln:  if (right <= 0)
                          throw	expressionError("postfixEval: ln(neg) undefined");
                    value=log(right);
                    break;

    case token_log:if (right <= 0)
                          throw	expressionError("postfixEval: log(neg) undefined");
                    value=log(right)/log(10);
                    break;

    case token_exp: value=exp(right);
                    break;

    case token_cosenoh:
                    value=cosh(right);
                    break;

    case token_senoh:value=sinh(right);
                    break;

    default:        throw	expressionError("postfixEval:token lost");
	}
	return value;
}//________________________________________________________________

postfixEval::postfixEval()
{}//________________________________________________________________

float postfixEval::evaluate()
{
	float left, right, expValue;
  show_tokenlist("Postfix:",t_postfixExpression);

	while(!t_postfixExpression.empty())
	{
		t_aritmeticExpression token = t_postfixExpression.front();
		t_postfixExpression.pop();

		if (token == token_numero)
		{
		  if (DataQueue.empty()) throw expressionError("postfixEval: DataQueue fail");
			operandStack.push(DataQueue.front());
			DataQueue.pop();
		}




		else if (token == token_variable)
// ----------------------------------------------------------------------------------------------------------
		{
            string valor_variable;                           // Variable para almacenar la expresión del valor de la i-ésima variable
            int cantidad_variables = VariableQueue.size();  // Se guarda en una variable la cantidad de variables a las que se les debe asignar un valor.

            for(int i =0; i<cantidad_variables;i++)         // Se repite el ciclo para la cantidad de variables definidas en la expresión.
            {
                cout <<"Inserte el valor de la variable: " << VariableQueue.front() <<endl; // Se solicita el ingreso del valor para cada variable
                cin >> valor_variable;                                                      // Se ingresa el valor de la i-ésima variable por el usuario.

                if(verificar_float(valor_variable)== true)                                  // Verificación de que cada entrada sea un número válido.
                {
                    float variable_numerica = string2float(valor_variable);                 // Conversión a float del string ingresado
                    Map_variables_float[VariableQueue.front()]=variable_numerica;           // Se asigna en el mapa de variables el valor para la i-ésima variable en la cola de variables.
                    VariableQueue.pop();                                                    // Se elimina el primer elemento de la cola para que en el próximo ciclo el valor ingresado sea el de la siguiente variable.
                }
                else{                                                                       // Si no corresponde a un número se imprime un mensaje de error y se hace 'break'.
                    cout<<"Valor no válido, por favor ingrese un número."<<endl;
                    break;
                }
            }

// ----------------------------------------------------------------------------------------------------------

// Aquí iría la incorporación de los valores de las variables
            map<string,float>::const_iterator varend = Map_variables_float.cend();
            map<string,float>::const_iterator varit = Map_variables_float.cbegin();
            while (varit != varend)
            {
                operandStack.push(varit->second);
                varit++;
            }


      //throw expressionError("postfixEval: VariableQueue not implemented yet");

		}

// ---------------------------------------------------------------------------------------------------------- Final parte Variables



		else
		{
		  if (isFunction(token))
		  {
		    getOperand(right);
		    left=1.0;
		  }else
		  {
		    getOperands(left, right);
		  }
			operandStack.push(compute(left, right, token));
		}
	}

	expValue = operandStack.top();
	operandStack.pop();

	if (!operandStack.empty())
		throw expressionError("postfixEval: Too many operands");
	return expValue;
}//________________________________________________________________

// ---------------------------------------------------------------- Función verificar cadena como número
bool postfixEval::verificar_float(string valor_variable)
{
  bool exponente_abierto=false;
  enum e_int_state {inicial,mantiza,decimal,exponente,valor_exponente} estado=inicial;
  int i = 0;            // Iterador
  int fin_string = valor_variable.size();

  while(i!=fin_string)
  {
    if (!valor_variable[i]) break;
    char car=valor_variable[i];
    switch(estado)
    {
      case inicial: switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                                  estado=mantiza;
                                  i++;
                        break;

                        default: return false;
                    }
                    break;

       case mantiza:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': i++;
                                  break;

                        case '.': estado=decimal;
                                  i++;
                                  break;
                        case 'e':
                        case 'E': estado=exponente;
                                  exponente_abierto=true;
                                  i++;
                                  break;

                        default: return false;
                                 break;

                    }
                    break;

       case decimal:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': i++;
                                  break;

                        case 'e':
                        case 'E': estado=exponente;
                                  exponente_abierto=true;
                                  i++;
                                  break;

                        default: return false;
                                 break;

                    }
                    break;

       case exponente:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': i++;
                                  estado=valor_exponente;
                                  exponente_abierto=false;
                                  break;

                        case '-': i++;
                                  estado=valor_exponente;
                                  break;

                        default: return false;
                                 break;

                    }
                    break;

       case valor_exponente:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': i++;
                                  estado=valor_exponente;
                                  exponente_abierto=false;
                                  break;

                        default: if(exponente_abierto) return false;
                                 break;

                    }
                    break;
   }
  }
  return true;
}//______________________________________________________________


// ---------------------------------------------------------------- Función convertir a número
float postfixEval::string2float(string valor_variable)
{
  bool exponente_abierto=false;
  enum e_int_state {inicial,mantiza,decimal,exponente,valor_exponente} estado=inicial;
  int i = 0;            // Iterador
  int fin_string = valor_variable.size();
  string valor="";
  while(i!=fin_string)
  {
    if (!valor_variable[i]) break;
    char car=valor_variable[i];
    switch(estado)
    {
      case inicial: switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;
                                  estado=mantiza;
                                  i++;
                        break;

                        default: return false;
                    }
                    break;

       case mantiza:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                                  break;

                        case '.': estado=decimal;
                                  valor+=car;i++;
                                  break;
                        case 'e':
                        case 'E': estado=exponente;
                                  exponente_abierto=true;
                                  valor+=car;i++;
                                  break;

                        default: break;

                    }
                    break;

       case decimal:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                                  break;

                        case 'e':
                        case 'E': estado=exponente;
                                  exponente_abierto=true;
                                  valor+=car;i++;
                                  break;

                        default: break;

                    }
                    break;

       case exponente:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                                  estado=valor_exponente;
                                  exponente_abierto=false;
                                  break;

                        case '-': valor+=car;i++;
                                  estado=valor_exponente;
                                  break;

                        default: break;

                    }
                    break;

       case valor_exponente:
                    switch(car)
                    {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9': valor+=car;i++;
                                  estado=valor_exponente;
                                  exponente_abierto=false;
                                  break;

                        default: if(exponente_abierto) break;

                    }
                    break;
   }
  }
  float val=atof(valor.c_str());
  return val;
}//______________________________________________________________
__________________________________________________________
