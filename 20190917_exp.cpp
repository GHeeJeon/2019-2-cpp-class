#include "exp.h"

Exp::Exp() : Exp(1,1) {} 
Exp::Exp(int b) : Exp(b, 1) {}
Exp::Exp(int b, int e) : base(b), exp(e) {}

int Exp::getValue() {
	int value = 1;
	for (int i = 0; i < exp; i++)
		value *= base;
	return value;
}

int Exp::getExp() {
	return exp;
}

int Exp::getBase() {
	return base;
}

bool Exp::equals(Exp b) {
	return (getValue() == b.getValue());
}