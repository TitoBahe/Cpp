#pragma once
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class RezolvareaEcuatie {
private:
	char* caractere;

public:  
	RezolvareaEcuatie()
	{
		caractere = nullptr;

	}
	RezolvareaEcuatie(char* caractere) :RezolvareaEcuatie()
	{
		if (caractere != nullptr) {
			this->caractere = new char[strlen(caractere) + 1];
			for (int i = 0; i < strlen(caractere) + 1; i++) {
				this->caractere[i] = caractere[i];
			}
		}
	}
	RezolvareaEcuatie(RezolvareaEcuatie& s) : RezolvareaEcuatie()
	{
		if (s.caractere != nullptr) {
			if (caractere != nullptr) {
				delete[] caractere;
				caractere = nullptr;
			}
			this->caractere = new char[strlen(s.caractere) + 1];
			for (int i = 0; i < strlen(s.caractere) + 1; i++) {
			this->caractere[i] = s.caractere[i];
			}
			
		}
		
	}
	RezolvareaEcuatie& operator!() {
		if (caractere != nullptr) {
			delete[] caractere;
			caractere = nullptr;
		}
		return *this;
	}
	RezolvareaEcuatie& operator==(char x) 
	{
		if (caractere != nullptr) {
			delete[] caractere;
			caractere = nullptr;
		}
		caractere = new char[1];
		caractere[0] = x;
		return *this;
	}

	RezolvareaEcuatie& operator=(int x) {
		caractere = nullptr;
		return *this;
	}
	RezolvareaEcuatie& operator=(RezolvareaEcuatie& s) {
		if (this != &s) {
			if (s.caractere != nullptr) {
				if (caractere != nullptr) {
					delete[] caractere;
					caractere = nullptr;
				}
				caractere = new char[strlen(s.caractere) + 1];
				strcpy_s(caractere, strlen(s.caractere) + 1, s.caractere);
			}
		}
		return *this;
		
	}
	char* getCaractere()
	{
		char* copie = new char[strlen(caractere) + 1];
		for (int i = 0; i < strlen(caractere) + 1; i++) {
			copie[i] = caractere[i];
		}
		return copie;
	}
	virtual void Suport() {
		cout << "Metoda creata pentru a corecta problemele in clasa";

	}
	virtual void Suplement() {
		cout << "Suplement clasei";
	}
	void setCaractere(string c) {
		if (!c.empty()) {
			if (caractere != nullptr) {
				delete[] caractere;
				caractere = nullptr;
			}

			caractere = new char[c.length() + 1];
			strcpy_s(caractere, c.length() + 1, c.c_str());
			
		}		
	}
	int ERROR() {
		if (caractere == nullptr) 
		{
			return -1;
		}
		for (int i = 0; i < strlen(caractere); ++i) {
			if (string("1234567890 +-*/^#([)].,").find(caractere[i]) == string::npos) {
				return -1;  
			}
		}
		return 0;
	}
	
	int itsoperand(char c) {
		if (string("+-*/^#").find(c) != string::npos) return 1;
		return 0;
	}

	double rezultat(string str[])
	{	
		string return_alternativ = "";
		string new_str;
		string vector[100];
		int i = 0;
		int k = 0;
		for(int i = 0; str[i] != ""; i++){
			new_str = str[i];
			if (isdigit(new_str[0]) || (new_str.size() > 1 ))
			{
				vector[k++] = new_str;
				
			}
			else if ( itsoperand(new_str[0]) && k >= 2) {
				double num2 = stod(vector[k - 1]);
				double num1 = stod(vector[k - 2]);
				k -= 2;

				switch (new_str[0]) 
				{
				case '+': 
					vector[k] = to_string(num1 + num2); 
					break;
				case '-': 
					vector[k] = to_string(num1 - num2); 
					break;
				case '*': 
					vector[k] = to_string(num1 * num2); 
					break;
				case '/': 
					if (num2 == 0) {
						return 1234.56;
					}
					else {
						vector[k] = to_string(num1 / num2);
					}
					break;
				case '^': 
					vector[k] = to_string(pow(num1, num2)); 
					break;
				case '#': 
					vector[k] = to_string(pow(num1, 1 / num2)); 
					break;					
				}
				k++;
			}
			
		}
		

		return k > 0 ? stod(vector[0]) : 0.0;

	}
	~RezolvareaEcuatie() {
		if (caractere != nullptr) {
			delete[] caractere;
			caractere = nullptr;
		}
		
	}
	friend ostream& operator<<(ostream& o, RezolvareaEcuatie s);
	friend istream& operator>>(istream& i, RezolvareaEcuatie& r);

};