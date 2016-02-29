#ifndef TRIM_H_INCLUDED
#define TRIM_H_INCLUDED
using namespace std;

liczba trim(liczba liczba1) {
    while(liczba1.wartosc[0] == '0' && liczba1.wartosc.length() > 1) {
        liczba1.wartosc.erase(0,1);
    }
    while(liczba1.poprzecinku[liczba1.poprzecinku.length()-1] == '0' && liczba1.poprzecinku.length() > 1) {
        liczba1.poprzecinku.erase(liczba1.poprzecinku.length()-1,1);
    }

    return liczba1;
}

#endif // TRIM_H_INCLUDED
