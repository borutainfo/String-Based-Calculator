#ifndef ODEJMOWANIE_H_INCLUDED
#define ODEJMOWANIE_H_INCLUDED
using namespace std;

// odejmowanie 2 liczb przy zalozeniu ze 1 liczba jest wieksza
string odejmij(string liczba1, string liczba2) {

    vector<long long int> roznica;
    string wynik;
    long long int przenies = 0;
    long long int dlugosc = 0;

    if(liczba1.length() < liczba2.length())
        dlugosc = liczba1.length();
    else
        dlugosc = liczba2.length();

    for(long long int i=0; i<dlugosc; i++) {
        if(StrToInt(liczba1[liczba1.length()-1-i]) >= StrToInt(liczba2[liczba2.length()-1-i]))
            roznica.push_back((StrToInt(liczba1[liczba1.length()-1-i]) - StrToInt(liczba2[liczba2.length()-1-i])) % 10);
        else {
            for(long long int j=1; j<(liczba1.length()-i); j++) {
                if(StrToInt(liczba1[liczba1.length()-1-i-j]) > 0) {
                    liczba1[liczba1.length()-1-i-j] = StrToInt(liczba1[liczba1.length()-1-i-j])+47;
                    break;
                }
                else {
                    liczba1[liczba1.length()-1-i-j] = '9';
                }
            }
            roznica.push_back((StrToInt(liczba1[liczba1.length()-1-i])+10 - StrToInt(liczba2[liczba2.length()-1-i])) % 10);
        }
    }

    while(dlugosc < liczba1.length()) {
        roznica.push_back(StrToInt(liczba1[liczba1.length()-dlugosc-1]) % 10);
        dlugosc++;
    }

    reverse(roznica.begin(), roznica.end());

    for(long long int i=0; i<roznica.size(); i++)
        wynik += IntToStr(roznica[i]);

    return wynik;
}

// pelne odejmowanie 2 liczb
liczba odejmowanie(liczba liczba1, liczba liczba2) {

    liczba1 = trim(liczba1);
    liczba2 = trim(liczba2);

    liczba wieksza, mniejsza, wynik;
    string roznica;
    int wiem = 0;

    if(liczba1.znak == 1 && liczba2.znak == 0) {
        liczba2.znak = 1;
        wynik = dodawanie(liczba1, liczba2);
    }

    else if(liczba2.znak == 1 && liczba1.znak == 0) {
        liczba2.znak = 0;
        wynik = dodawanie(liczba1, liczba2);
    }
    else {

        if (liczba1.poprzecinku.length() > liczba2.poprzecinku.length())
            while(liczba1.poprzecinku.length() != liczba2.poprzecinku.length())
                liczba2.poprzecinku += "0";
        else
            while(liczba1.poprzecinku.length() != liczba2.poprzecinku.length())
                liczba1.poprzecinku += "0";

        if(liczba1.wartosc.length() > liczba2.wartosc.length()) {
            wieksza = liczba1;
            mniejsza = liczba2;
            wiem = 1;
        }
        else if(liczba1.wartosc.length() < liczba2.wartosc.length()) {
            wieksza = liczba2;
            mniejsza = liczba1;
            wiem = 2;
        }
        else {
            if(liczba1.wartosc != "0" || liczba2.wartosc != "0")
            for(long long int i = 0; i < liczba1.wartosc.length();i++) {
                if(StrToInt(liczba1.wartosc[i]) > StrToInt(liczba2.wartosc[i])) {
                    wieksza = liczba1;
                    mniejsza = liczba2;
                    wiem = 1;
                    break;
                }
                else if(StrToInt(liczba2.wartosc[i]) > StrToInt(liczba1.wartosc[i])) {
                    wieksza = liczba2;
                    mniejsza = liczba1;
                    wiem = 2;
                    break;
                }
            }
            if(wiem == 0) {
                for(long long int i = 0; i < liczba1.poprzecinku.length();i++) {
                    if(StrToInt(liczba1.poprzecinku[i]) > StrToInt(liczba2.poprzecinku[i])) {
                        wieksza = liczba1;
                        mniejsza = liczba2;
                        wiem = 1;
                        break;
                    }
                    else if(StrToInt(liczba2.poprzecinku[i]) > StrToInt(liczba1.poprzecinku[i])) {
                        wieksza = liczba2;
                        mniejsza = liczba1;
                        wiem = 2;
                        break;
                    }
                }
            }
            if(wiem == 0) {
                wieksza = liczba1;
                mniejsza = liczba1;
            }
        }

        if(wiem != 0) {
            int sprawdz = 0;
            for(long long int i = 0; i < wieksza.poprzecinku.length();i++) {
                if(StrToInt(wieksza.poprzecinku[i]) > StrToInt(mniejsza.poprzecinku[i])) {
                    sprawdz = 1;
                    break;
                }
                else if(StrToInt(mniejsza.poprzecinku[i]) > StrToInt(wieksza.poprzecinku[i])) {
                    sprawdz = 2;
                    break;
                }
            }
            if(sprawdz == 0) {
                wynik.poprzecinku = "0";
            }
            else if(sprawdz == 1) {
                wynik.poprzecinku = odejmij(wieksza.poprzecinku, mniejsza.poprzecinku);
            }
            else {
                wieksza.wartosc = odejmij(wieksza.wartosc, "1");
                wieksza.poprzecinku.insert(0, "1");
                wynik.poprzecinku = odejmij(wieksza.poprzecinku, mniejsza.poprzecinku);
                wynik.poprzecinku.erase(0,1);
            }
            wynik.wartosc = odejmij(wieksza.wartosc, mniejsza.wartosc);


            if((liczba1.znak == 1 && liczba2.znak == 1 && wiem == 1) || (liczba1.znak == 0 && liczba2.znak == 0 && wiem == 2)) {
                wynik.znak = 1;

            }
            else if((liczba1.znak == 1 && liczba2.znak == 1 && wiem == 2) || (liczba1.znak == 0 && liczba2.znak == 0 && wiem == 1)) {
                wynik.znak = 0;
            }
        }
    }
    return trim(wynik);
}


#endif // ODEJMOWANIE_H_INCLUDED
