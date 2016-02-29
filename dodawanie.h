#ifndef DODAWANIE_H_INCLUDED
#define DODAWANIE_H_INCLUDED
using namespace std;

liczba odejmowanie(liczba, liczba);

// funkcja dodaj¹ca dwa stringi
string dodaj(string liczba1, string liczba2) {

    vector<long long int> suma;
    string wynik;
    long long int przenies = 0;
    long long int dlugosc = 0;

    if(liczba1.length() < liczba2.length())
        dlugosc = liczba1.length();
    else
        dlugosc = liczba2.length();

    for(long long int i=0; i<dlugosc; i++) {
        suma.push_back((StrToInt(liczba1[liczba1.length()-1-i]) + StrToInt(liczba2[liczba2.length()-1-i]) + przenies) % 10);
        przenies = (StrToInt(liczba1[liczba1.length()-1-i]) + StrToInt(liczba2[liczba2.length()-1-i]) + przenies) / 10;
    }

    while(dlugosc < liczba1.length()) {
        suma.push_back((StrToInt(liczba1[liczba1.length()-dlugosc-1]) + przenies) % 10);
        przenies = (StrToInt(liczba1[liczba1.length()-dlugosc-1]) + przenies) / 10;
        dlugosc++;
    }

    while(dlugosc < liczba2.length()) {
        suma.push_back((StrToInt(liczba2[liczba2.length()-dlugosc-1]) + przenies) % 10);
        przenies = (StrToInt(liczba2[liczba2.length()-dlugosc-1]) + przenies) / 10;
        dlugosc++;
    }

    if(przenies > 0) {
        suma.push_back(przenies);
        dlugosc++;
    }

    reverse(suma.begin(), suma.end());

    for(long long int i=0; i<suma.size(); i++)
        wynik += IntToStr(suma[i]);

    return wynik;
}

// funkcja dodaj¹ca dwie liczby typu 'liczba'
liczba dodawanie(liczba liczba1, liczba liczba2) {

    liczba1 = trim(liczba1);
    liczba2 = trim(liczba2);

    liczba wynik;
    string suma;

    if(liczba1.znak == 1 && liczba2.znak == 0){
        liczba1.znak = 0;
        wynik = odejmowanie(liczba2, liczba1);
    }
    else if(liczba1.znak == 0 && liczba2.znak == 1){
        liczba2.znak = 0;
        wynik = odejmowanie(liczba1, liczba2);
    }
    else {
        if (liczba1.poprzecinku.length() > liczba2.poprzecinku.length())
            while(liczba1.poprzecinku.length() != liczba2.poprzecinku.length())
                liczba2.poprzecinku += "0";
        else
            while(liczba1.poprzecinku.length() != liczba2.poprzecinku.length())
                liczba1.poprzecinku += "0";

        suma = dodaj(liczba1.poprzecinku, liczba2.poprzecinku);

        if (suma.length() > liczba1.poprzecinku.length()) {
            suma.erase(0,1);
            liczba2.wartosc = dodaj(liczba2.wartosc, "1");
        }

        wynik.poprzecinku = suma;
        wynik.wartosc = dodaj(liczba1.wartosc, liczba2.wartosc);

        if(liczba1.znak == 1 && liczba2.znak == 1)
            wynik.znak = 1;
        else
            wynik.znak = 0;
    }

    return trim(wynik);
}

#endif // DODAWANIE_H_INCLUDED
