#pragma once
#ifndef EXP_H
#define EXP_H

class Exp {
	int exp;
	int base;

public:
	Exp(int b, int e) {}
	Exp(int b) {}
	Exp() {}

	int getExp();
	int getBase();
	int getValue();
	bool equals(Exp b);
};

#endif 