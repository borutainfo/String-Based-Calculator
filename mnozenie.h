#ifndef MNOZENIE_H_INCLUDED
#define MNOZENIE_H_INCLUDED
using namespace std;

string pomnoz(string liczba1, string liczba2) {

    string wynik = "0", iloczyn = "0";
    long long int dlugosc = 0;

    for(long long int i=0; i<liczba2.length(); i++) {
        for(long long int j=0; j<liczba1.length(); j++) {
            iloczyn = IntToStr(StrToInt(liczba1[liczba1.length()-1-j]) * StrToInt(liczba2[liczba2.length()-1-i]));
            dlugosc = iloczyn.length();
            while(iloczyn.length() < dlugosc+i+j) {
                iloczyn += "0";
            }
            wynik = dodaj(wynik, iloczyn);
        }
    }

    return wynik;
}

liczba mnozenie (liczba liczba1, liczba liczba2) {

    liczba1 = trim(liczba1);
    liczba2 = trim(liczba2);

    liczba wynik;
    string iloczyn;
    long long int przecinek = liczba1.poprzecinku.length() + liczba2.poprzecinku.length();

    string l1 = liczba1.wartosc;
    l1 += liczba1.poprzecinku;

    string l2 = liczba2.wartosc;
    l2 += liczba2.poprzecinku;

    if((liczba1.znak == 1 && liczba2.znak == 1) || (liczba1.znak == 0 && liczba2.znak == 0)) {
        wynik.znak = 0;
    }

    else {
        wynik.znak = 1;
    }

    iloczyn = pomnoz(l1, l2);
    wynik.wartosc = iloczyn.substr(0, (iloczyn.length()-przecinek));
    wynik.poprzecinku = iloczyn.substr((iloczyn.length()-przecinek), (iloczyn.length()-1));

    wynik = trim(wynik);

    return wynik;
}

#endif // MNOZENIE_H_INCLUDED
