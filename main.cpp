/*
/ Kalkulator
/
/ Autor: Sebastian Boruta
/
/ Arytmetyka jest oparta na modyfikowanych dzialaniach pisemnych.
/ Parsowanie wprowadzonego wyrazenia oparte jest w duzej mierze
/ na dzialaniu rekurencyjnym.
/
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include "liczba.h"
#include "explode.h"
#include "trim.h"
#include "conversion.h"
#include "dodawanie.h"
#include "odejmowanie.h"
#include "mnozenie.h"
#include "dzielenie.h"
#include "oblicz.h"
using namespace std;

int main()
{

    string dzialanie;
    liczba wynik;

    cout << "Kalkulator by Sebastian Boruta" << endl << endl;

    while(1) {

        cout << "Wprowadz dzialanie: ";
        getline(cin, dzialanie);

        try {
            wynik = oblicz(dzialanie);
            cout << "Wynik: ";
            if(wynik.znak)
                cout << "-";
            else
                cout << "+";

            cout << wynik.wartosc << "." << wynik.poprzecinku;
        }

        catch(string msg) {
            cerr << msg << endl;
        }
        cout << "\n\n";
    }
    return 0;
}
