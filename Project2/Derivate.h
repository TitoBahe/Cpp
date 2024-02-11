#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector> // clasa STL
#include "header.h"
#include "srcHead.h"
#include "Interfata.h"



using namespace std;

vector<int> numere = { 5, 4, 3, 2, 1 };

class Abstracta {
    public: 
    virtual void metodaPura() = 0;
};
class derivata : public Abstracta {
public:
    void metodaPura() override {
        
        cout << "exit -> pentru a iesi\n" << "Ecutie in: ";
        for (int num : numere) {
            cout << num << ", ";
        }
        cout << 0;
        cout << "..."<< endl;
        
    }


};

class srcHead : public EvalauareaExpresiilor
{
public:
    void SuportEvalExpres() override
    {
        cout << "\nMetoda facuta pentru a rezolva probleme existente.";
    }
    void Suplement() override 
    {
        cout << "\nSuplement daca se intampla ceva";
    }
};

class header : public RezolvareaEcuatie 
{
public:
    void Suport() override
    {
        cout << "\nOverwritten.";
    }
    void Suplement() override 
    {
        cout << "\nOverwritten.";
    }
};

class Interfata : public interfataUtilizator {

public:
    void Suport() override 
    {
        cout << "\nSuport overwritten.";
    }
    void Suplement() override
    {
        cout << "\nSuplement overwritten.";
    }
};
