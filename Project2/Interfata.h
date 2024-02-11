#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include "srcHead.h"

using namespace std;

class interfataUtilizator {
	

private:
	string one;
	double* d;
	const int a;
	static int o;
	EvalauareaExpresiilor str;
public:
	interfataUtilizator():a(10)
	{
		one = "";
		d = new double[o];
		str = 0;
	}
	interfataUtilizator(double* d, string one):interfataUtilizator()
	{
		if (one[0] != '\0') this->one = one;
		 
		if (d != nullptr) {
			this->d = new double[o];
			for (int i = 0; i < o; i++) {
				this->d[i] = d[i];
			}
		}
	}
	interfataUtilizator(interfataUtilizator& s) : a(s.a)
	{
		if (s.one[0] != '\0') this->one = s.one;

		if (s.d != nullptr) {
			d = new double[o];
			for (int i = 0; i < o; i++) {
				this->d[i] = s.d[i];
			}
		}
		str = s.str;
	}
	string getone() {
		return one;
	}
	void setone(string c) {
		if (c[0] != '\0') {
			one = c;
		}
	}
	EvalauareaExpresiilor getstr() {
		return str;
	}
	void setstr(EvalauareaExpresiilor s) {
		str = s;
	}

	virtual void Suport() {
		cout << "Suport clasei.";
	}

	virtual void Suplement() {
		cout << "Suplementul clasei.";
	}

	void setD(double* d) {
		if (d != nullptr) {
			if (this->d != nullptr) {
				delete[] this->d;
				this->d = nullptr;
			}
			this->d = new double[o];
			for (int i = 0; i < o; i++) {
				this->d[i] = d[i];
			}
			
		}
	}
	double* getD() {
		if (d != nullptr) {
			double* copie = new double[o];
			for (int i = 0; i < o; i++) {
				copie[i] = d[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	interfataUtilizator& operator!() {
		one = "None";
		return *this;
	}
	interfataUtilizator& operator==(string x)
	{
		if (x[0] != '\0') {
			one = x;
		}
		return *this;
	}
	interfataUtilizator& operator=(interfataUtilizator& s){

		if (s.d != nullptr) {
			d = new double[o];
			for (int i = 0; i < o; i++) {
				this->d[i] = s.d[i];
			}
		}
		str = s.str;
	}
	string InterfataStandard() {
		
		if (d != nullptr) {
			for (int i = 0; i < o; i++) {
				d[i] = i;
			}
			int count = 0;
			for (int i = o - 1; i >= 0; i--) {
				if (count == 3) {
					count = 0;
					cout << endl;
				}
				if (d[i] == 0) {
					
					cout << "  " << d[i];
					cout << endl;
					cout << endl;
					return "Care este expresia ca trebuie calculata?";
				}
				cout << d[i] << " ";
				count++;
			}
		}
		cout << endl;
		return "Care este expresia ca trebuie calculata?" ;
		
	}
	void InterfataRezultat() {
		
		cout << endl << "Rezultat lui expresia " << one << ": " << endl;
		
	}
	void citire_binare(int final_result) {
		ifstream Arhiva_Binary("Binary.bin", ios::binary);

		if (!Arhiva_Binary) { //daca nu se deschide bine
			cout << "Eroare la deschidere pentru citire" << endl;
			
		}
		Arhiva_Binary.read(reinterpret_cast<char*>(&final_result), sizeof(final_result));
		cout << "Numarul salvat este: " << final_result << endl;
		Arhiva_Binary.close();
	}
	void scriere_binare(int final_result) 
	{
		ofstream Arhiva_Binary("Binary.bin", ios::binary);
		if (!Arhiva_Binary) {
			cout << "Eroare la deschiderea arhivei." << endl;
		}
		Arhiva_Binary.write(reinterpret_cast<const char*>(&final_result), sizeof(final_result));
		Arhiva_Binary.close();

		// Verificar se a escrita foi bem-sucedida
		if (!Arhiva_Binary.good()) {
			cout << "Eroare la scriere in Arhiva." << endl;
		}

		cout << "Numarul " << final_result << " a fost salvat pe " << "Binary.bin" << endl;
	}
	
	static int MesajDeExit() 
	{
		cout << "Iesit cu succes";
		return 0;
	}
	~interfataUtilizator() {
		if (d != nullptr) {
			delete[] d;
			d = nullptr;
		}
	}
	friend ostream& operator<<(ostream& o, interfataUtilizator s);
	friend istream& operator>>(istream& i, interfataUtilizator& r);
};
