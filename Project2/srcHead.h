#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include "header.h"

using namespace std;

const int MAX_SIZE = 100;

//poate evalua expresii matematice ce conțin paranteze rotunde și/sau pătrate
//

class EvalauareaExpresiilor {

private:
	string ecuatie;
	RezolvareaEcuatie operatie1;
public:


	EvalauareaExpresiilor()
	{
		operatie1 = 0;
		ecuatie = "";
	}
	EvalauareaExpresiilor(string ecuatie) : EvalauareaExpresiilor()
	{

		if (ecuatie[0] != '\0') {
			this->ecuatie = ecuatie;
		}


	}
	EvalauareaExpresiilor(EvalauareaExpresiilor& s)
	{

		if (s.ecuatie[0] != '\0') {
			this->ecuatie = s.ecuatie;
		}
		operatie1 = s.operatie1;


	}
	RezolvareaEcuatie getoperatie1() {
		return operatie1;
	}
	void setoperatie1(RezolvareaEcuatie s) {
		operatie1 = s;
	}

	string getEcuatie() {

		return ecuatie;
	}
	virtual void SuportEvalExpres() {
		cout << "\nMetoda facuta pentru a rezolva probleme existente.";

	}
	virtual void Suplement() {
		cout << "\nSuplement.";
	}
	void setEcuatie(string x) {
		if (x[0] != '\0') ecuatie = x;

	}
	bool itsoperand(char c) {
		return string("+-*/^#").find(c) != string::npos;
		
	}
	int ReturnIfOperand(char c) {
		return string("+-*/^#").find(c) != string::npos;

	}

	int ReturnPreferinta(char c, bool isInStack = false) {
		if (c == '+' || c == '-') return 1;
		if (c == '*' || c == '/') return 2;
		if (c == '^' || c == '#')return 3;
		if (c == '(' || c == '[')return isInStack ? 0 : 4;
		if (c == ')' || c == ']')return 5;
		return -1;
	}

	double DecompunereaEcuatii(string str) {

		int k = 0;
		string final;
		char operand[MAX_SIZE]{};
		string partial[MAX_SIZE];
		stringstream ss(str);

		int t = 0;
		int i = 0;
		while (ss >> final) {
			if (isdigit(final[0]) || final.length() > 1 && isdigit(final[1])) {
				partial[i] = final;
				i++;
			}
			else if (itsoperand(final[0])) {
				while (t > 0 && ReturnPreferinta(operand[t - 1], true) >= ReturnPreferinta(final[0])) {
					partial[i++] = string(1, operand[--t]);
					
				}
				if (t < MAX_SIZE) {
					operand[t++] = final[0];

				}

			}
			else if (final[0] == '(' || final[0] == '[') {
				if (t < MAX_SIZE) {
					operand[t++] = final[0];
				}
				// Armazena '(' na pilha e incrementa 't'
			}
			else if (final[0] == ')'|| final[0] == ']') {
				char corespondent = (final[0] == ')') ? '(' : '[';
				while (t > 0 && operand[t - 1] != corespondent) {
					partial[i++] = string(1, operand[--t]);  // Desempilha até encontrar '(' correspondente

				}
				if (t > 0) t--; // Remove '(' da pilha
			}

		}

		while (t > 0) {
			partial[i++] = string(1, operand[--t]);

		}

		return operatie1.rezultat(partial);
	}
	EvalauareaExpresiilor& operator!() {
		ecuatie = "None";
		return *this;
	}
	EvalauareaExpresiilor& operator==(string x)
	{
		if (x[0] != '\0') {
			ecuatie = x;
		}
		return *this;
	}
	EvalauareaExpresiilor& operator=(int x) 
	{
		operatie1 = 0;
		ecuatie = "";
		return *this;
	}
	EvalauareaExpresiilor& operator=(EvalauareaExpresiilor& s) {
		if (this != &s) {
			ecuatie = s.ecuatie;
			operatie1 = s.operatie1;
		}
		return *this;
	}



	friend istream& operator>>(istream& in, EvalauareaExpresiilor& e);
	friend ostream& operator<<(ostream& out, EvalauareaExpresiilor e);


	//Fiecare clasă va conține supraîncărcări pentru operatorii << și >>

	/*Fiecare clasă va avea cel puțin 2 operatori supraîncărcați dintre următorii(același operator nu poate fi supraîncărcat în 2 clase diferite) :
		operator de indexare[]
		operatori aritmetici(+, -, *or /)
		++ or -- (ambele forme)
		cast implicit sau explicit -> focar nesse pra ter a resposta em int quando for necessario ou double quando for necessario
		operator de negație !
		operatori relaționali(<.>, = < , >= , == )*/

};




