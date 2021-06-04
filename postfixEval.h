#ifndef POSTFIX_H_INCLUDED
#define POSTFIX_H_INCLUDED
class postfixEval : public virtual _aritmetic_base{
private:
  stack<float> operandStack;
  void getOperand(float&);
	void getOperands(float& left, float& right);
	float compute(float left, float right,t_aritmeticExpression op) const;

public:
  postfixEval();
	float evaluate();

	bool verificar_float(string valor_variable);       // Método para verificar si la cadena tiene sentido como numero.
    float string2float(string valor_variable);         // Método para convertir a numero la cadena.
};//___________________________________________________________
#endif
