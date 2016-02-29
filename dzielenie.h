#ifndef DZIELENIE_H_INCLUDED
#define DZIELENIE_H_INCLUDED
using namespace std;

// czy liczba1 jest wieksza lub równa liczba2
bool wieksza(string liczba1, string liczba2) {

        while(liczba1[0] == '0' && liczba1.length() > 1) {
            liczba1.erase(0,1);
        }
        while(liczba2[0] == '0' && liczba2.length() > 1) {
            liczba2.erase(0,1);
        }

        if(liczba1.length() > liczba2.length()) {
            return true;
        }
        else if(liczba1.length() < liczba2.length()) {
            return false;
        }
        else if(liczba1 == liczba2) {
            return true;
        }
        else {
            for(long long int i = 0; i < liczba1.length();i++) {
                if(StrToInt(liczba1[i]) > StrToInt(liczba2[i])) {
                    return true;
                    break;
                }
                else if(StrToInt(liczba2[i]) > StrToInt(liczba1[i])) {
                    return false;
                    break;
                }
                else if(i == (liczba1.length()-1))
                    return true;
            }
        }
}

string podziel(string liczba1, string liczba2, long long int dokladnosc = 10) {

    string wynik = "0", iloraz = "0", reszta = "0";
    bool stop = 0;
    long long int x = 0, przecinek = 0;

    liczba1 += "0";
    liczba2 += "0";

    if(dokladnosc < 0)
        dokladnosc = 3;

    while(!stop) {
        reszta = liczba1.substr(0,x);
        if(wieksza(liczba1.substr(0,x),liczba2)){
            for(string i = "1"; wieksza(liczba2, dodaj(i, "1")); i = dodaj(i, "1")) {
                if(!wieksza(liczba1.substr(0,x), pomnoz(i, liczba2))){
                    iloraz = odejmij(i, "1");
                    while(iloraz[0] == '0' && iloraz.length() > 1)
                        iloraz.erase(0,1);

                    wynik += iloraz;
                    reszta = odejmij(liczba1.substr(0,x), pomnoz(odejmij(i, "1"), liczba2));
                    liczba1 = reszta + liczba1.substr(x,liczba1.length()-1);
                    x++;
                    break;
                }
            }
        }
        else {
            wynik += "0";
            x++;
        }

        if(wieksza("0", reszta) && x > liczba1.length())
            stop = 1;
        else if(x > liczba1.length()){
            liczba1 += "0";
            if(przecinek == 0)
                wynik += ",";
            przecinek++;
        }

        if(przecinek > dokladnosc)
            stop = 1;
    }

    while(wynik[0] == '0' && wynik[1] != ',' && wynik.length() > 1) {
        wynik.erase(0,1);
    }

    return wynik;
}

liczba dzielenie(liczba liczba1, liczba liczba2, long long int dokladnosc = 10) {

    liczba1 = trim(liczba1);
    liczba2 = trim(liczba2);

    liczba wynik;
    string iloraz;

    if(liczba1.poprzecinku.length() >= liczba2.poprzecinku.length())
        while(liczba1.poprzecinku.length() > liczba2.poprzecinku.length())
            liczba2.poprzecinku += "0";
    else
        while(liczba1.poprzecinku.length() < liczba2.poprzecinku.length())
            liczba1.poprzecinku += "0";

    iloraz = podziel(liczba1.wartosc + liczba1.poprzecinku, liczba2.wartosc + liczba2.poprzecinku, dokladnosc);

    if(iloraz.find(',') != string::npos){
        vector<string> podziel;
        podziel = explode(iloraz, ',');
        wynik.wartosc = podziel[0];
        wynik.poprzecinku = podziel[1];
    }
    else {
        wynik.wartosc = iloraz;
        wynik.poprzecinku = "0";
    }

    if((liczba1.znak == 1 && liczba2.znak == 1) || (liczba1.znak == 0 && liczba2.znak == 0)) {
        wynik.znak = 0;
    }

    else {
        wynik.znak = 1;
    }

    return trim(wynik);

}

#endif // DZIELENIE_H_INCLUDED
