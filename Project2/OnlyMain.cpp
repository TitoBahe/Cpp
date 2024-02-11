#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "header.h"
#include "srcHead.h"
#include "Interfata.h"
#include "Derivate.h"

using namespace std;

string one;
int eroare = 0;
int inf = 0;
int interfataUtilizator::o = 10;
int raspuns = 0;
string fisier_nume;
string fisier_rezultat;
int final_result;
int First_choice;
int count_down = 0;

ostream& operator<<(ostream& o, interfataUtilizator s) {

	o << "//////////////////// :) ////////////////////" << endl;
	o << endl;
	o << "DATI UN SPATIU INTRE FIECARE NUMAR ELEMENT ( NUMAR / OPERATORI)" << endl;
	o << "Exemplu: 3+4*5 -> 3 + 4 * 5" << endl;
	o << endl;
	o << "Pentru a termina programul: 'exit'" << endl;
	o << endl;
	o << s.InterfataStandard();
	o << endl << "1 - Operatii cu fisierele" << endl << "2 - Calculator Direct" << endl << "3 - Salvarea unui rezultat" << endl << "4 - Utilizarea Rezultatului salvat" << endl << "5 - Exit" << endl;
	cin >> First_choice;
	return o;
}

istream& operator>>(istream& i, interfataUtilizator& r) {
	r.setone(one);
	r.InterfataRezultat();
	return i;
}

ostream& operator<<(ostream& o, RezolvareaEcuatie s) {
	if (s.ERROR() == -1) {
		eroare = 1;
	}
	return o;
}
istream& operator>>(istream& i, RezolvareaEcuatie& r) {
	r.setCaractere(one);
	return i;
}

ostream& operator<<(ostream& out, EvalauareaExpresiilor e) {
	
	
	if (e.DecompunereaEcuatii(one) == 1234.56) {
		inf = 1;
	}
	else {
		out << e.DecompunereaEcuatii(one);
		final_result = e.DecompunereaEcuatii(one);
	}
	
	out << endl;
	return out;
}
istream& operator>>(istream& in, EvalauareaExpresiilor& e) {
	if (count_down == 0) {
		in.ignore(numeric_limits<streamsize>::max(), '\n'); //apagar o buffer só uma vez 
		count_down = 1;
	}
	
	getline(in, one);
	e.setEcuatie(one);
	
	return in;

}
int main(int argc, char* argv[]) 
{
	//string anotacao;
	EvalauareaExpresiilor t;
	interfataUtilizator s;
	RezolvareaEcuatie r;
	derivata d;



						// colocar um while aqui
	if (argc == 2) {
		one = argv[1];
		cout << "Scrie 'exit' pentru a iesi";
		if (one == "exit")
		{
			return interfataUtilizator::MesajDeExit();
		}
		cin >> r;
		cout << r;
		if (eroare == 1) {
			cout << "ERROR, TRY AGAIN" << endl;
			return -1;
		}
		cin >> s;
		cout << t;
		if (inf == 1) {
			cout << "ERROR, TRY AGAIN" << endl;
			return -1;
		}
		cout << endl;
	}

		cout << s;
		
		while (First_choice != 5) {

		switch (First_choice)
		{
		case 1:
		{
			//fara linia de comanda
			cout << "Vrei sa citesc o valoare dintr-un text fizic? ";
			cout << "\n1 - Pentru Da";
			cout << "\n2 - Pentru Nu\n";

			cin >> raspuns;
			while (raspuns != 2) {
				if (raspuns == 1)
				{
					cout << "Care e numele fisierului?\n";
					cin >> fisier_nume;

					cout << "Care va fi nume fisierului care va arata rezultatele?\n";
					cin >> fisier_rezultat;

					ifstream ArhivaIntrare(fisier_nume);
					ofstream ArhivaResultat(fisier_rezultat);
					if (!ArhivaIntrare.is_open()) {
						cout << "Erroare la deschiderea arhivei" << endl;
						return 1; // Retorna um código de erro
					}
					while (getline(ArhivaIntrare, one)) {
						cout << "Rezultatul scris pe Arhiva " << fisier_rezultat << " este: ";
						cout << t;
						ArhivaResultat << final_result << endl;
					}
					ArhivaIntrare.close();
					ArhivaResultat.close();

					cout << "\nVrei sa citesc o valoare dintr-un text fizic? ";
					cout << "\n1 - Pentru Da";
					cout << "\n2 - Pentru Nu\n";

				}
				cin >> raspuns;
			}
			if (one != " ") {
				one = " ";
			}
			break;
		}
		case 2:
		{
			while (one != "exit") {

				cout << endl;
				d.metodaPura();
				cout << endl;
				cin >> t;

				if (one == "exit") {
					break;
				}
				cin >> r;
				cout << r;
				if (eroare == 1) {
					cout << "ERROR, TRY AGAIN" << endl;
					return -1;
				}
				cin >> s;
				cout << t;
				if (inf == 1) {
					cout << "ERROR, TRY AGAIN" << endl;
					return -1;
				}
				cout << endl;
			}
			break;
		}

		case 3:
		{
			s.scriere_binare(final_result);
			break;
		}
		case 4:
		{	s.citire_binare(final_result);
			break;
		}
		case 5: {
			cout << interfataUtilizator::MesajDeExit();
			return 0;
		}
		default:
			cout << "Optiniune Invalida";
			break;

		}
		cout << endl << "1 - Operatii cu fisierele" << endl << "2 - Calculator Direct" << endl << "3 - Salvarea unui rezultat" << endl << "4 - Utilizarea Rezultatului salvat" << endl << "5 - Exit" << endl;
		cin >> First_choice;
	}
	

	
	
	

}
