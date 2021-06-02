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
		{
      throw expressionError("postfixEval: VariableQueue not implemented yet");
		}
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


