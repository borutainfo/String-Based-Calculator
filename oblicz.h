#ifndef OBLICZ_H_INCLUDED
#define OBLICZ_H_INCLUDED
using namespace std;

liczba czysc(){
    liczba cls;
    return cls;
}

liczba precyzuj(liczba liczba1, long long int precyzja = -10){

    if(precyzja > 0) {
        liczba1.poprzecinku = "0";
        for(long long int i = precyzja; i < liczba1.wartosc.length(); i++){
            liczba1.wartosc[i] = '0';
        }
    }
    if(precyzja < 0) {
        precyzja = -1*precyzja;
        for(long long int i = precyzja; i < liczba1.poprzecinku.length(); i++){
            liczba1.poprzecinku[i] = '0';
        }
    }

    return trim(liczba1);
}

string wypisz(liczba liczba1) {
    liczba1 = trim(liczba1);

    string wartosc = "";

    if(liczba1.znak == 1){
        wartosc += "-";
    }
    wartosc += liczba1.wartosc;

    if(liczba1.poprzecinku != "0" && liczba1.poprzecinku != "")
         wartosc += "." + liczba1.poprzecinku;

    return wartosc;
}

liczba oblicz(string wyrazenie, long long int precyzja = -10) {

    const long long int prestart = precyzja;

    long long int i = 0, j = 0, k = 0, nawias = 0;
    bool pusta = 1;

    string dzialanie = "", eks_od = "", eks_do = "";
    liczba wynik, pomocnicza;

    while(j < wyrazenie.length()){

        // nawiasy
        if(wyrazenie[j] == '('){
            i = j+1;
            string eks = "";
            long long int eks_od = 0, eks_do = 0;
            nawias++;
            while(nawias > 0 && j < wyrazenie.length()) {
                j++;
                if(wyrazenie[j] == '(')
                    nawias++;
                else if(wyrazenie[j] == ')')
                    nawias--;
            }

            k = j+2;

            while(j < wyrazenie.length()){
                j++;
                if(wyrazenie[j] == ':') {
                    long long int z = 0;
                    while(wyrazenie[j+1] == ' ')
                        j++;
                    z = j+1;
                    while(isdigit(wyrazenie[j+1]) || wyrazenie[j+1] == '.'){
                        j++;
                    }
                    if(wyrazenie.substr(z,j-z+1).find('.') != string::npos)
                        precyzja = -1*StrToInt(wyrazenie.substr(1+z+wyrazenie.substr(z,j-z+1).find('.'),j-z+1));
                    else {
                        precyzja = StrToInt(wyrazenie.substr(z,j-z+1));
                    }
                    break;
                }
                if(wyrazenie[j] == '[') {
                    eks_od = j;
                    while(wyrazenie[j+1] != ']'){
                        j++;
                    }
                    j++;
                    eks_do = j;
                    eks = wyrazenie.substr(eks_od, eks_do-eks_od+1);
                }

                if(isdigit(wyrazenie[j]))
                    break;
            }

            k = k-2;

            pomocnicza = oblicz(wyrazenie.substr(i,k-i), precyzja);
            if(eks != "") {
                pomocnicza = oblicz(pomocnicza.wartosc+"."+pomocnicza.poprzecinku+eks, precyzja);
                j = eks_do;
            }
            else
                j = k;

            pusta = 0;
        }

        // znak liczby
        else if(wyrazenie[j] == '-' && ((dzialanie == "" && j == 0) || (dzialanie != "" && j > 0))){
            pomocnicza.znak = 1;
        }

        // liczba
        else if(isdigit(wyrazenie[j])){
            eks_od = "";
            eks_do = "";
            i = j;
            while(isdigit(wyrazenie[j+1])){
                j++;
            }
            if(wyrazenie[i-1] != '.')
                pomocnicza.wartosc = wyrazenie.substr(i,j-i+1);
            else
                pomocnicza.poprzecinku = wyrazenie.substr(i,j-i+1);

            if(wyrazenie[j+1] != '.')
                pusta = 0;


            if(wyrazenie[j+1] == ' ') {
                j++;
                while(j < wyrazenie.length()){
                    if(wyrazenie[j] != ' ')
                    break;
                    j++;
                }
                j--;
            }

            if(wyrazenie[j+1] == '[') {
                j++;
                while(isdigit(wyrazenie[j+1]) || wyrazenie[j+1] == '-'){
                    eks_od += wyrazenie[j+1];
                    j++;
                }
                if(wyrazenie[j+1] == '.' && wyrazenie[j+2] == '.') {
                    j = j+2;
                    while(isdigit(wyrazenie[j+1]) || wyrazenie[j+1] == '-'){
                        eks_do += wyrazenie[j+1];
                        j++;
                    }
                }
                else {
                    j++;
                }

                if(StrToInt(eks_od) != 0 && eks_do == "") {
                    if(StrToInt(eks_od) > 0 && StrToInt(eks_od) <= pomocnicza.wartosc.length()) {
                        pomocnicza.wartosc = pomocnicza.wartosc[pomocnicza.wartosc.length() - StrToInt(eks_od)];
                        pomocnicza.poprzecinku = "0";
                    }
                    else if(StrToInt(eks_od) < 0 && -1*StrToInt(eks_od) <= pomocnicza.poprzecinku.length()) {
                        pomocnicza.wartosc = pomocnicza.poprzecinku[-1*StrToInt(eks_od)-1];
                        pomocnicza.poprzecinku = "0";
                    }
                    else {
                        pomocnicza.wartosc = "0";
                        pomocnicza.poprzecinku = "0";
                    }
                }
                else if((StrToInt(eks_od) >= StrToInt(eks_do) && StrToInt(eks_od) != 0 && StrToInt(eks_do) != 0)) {
                    if(StrToInt(eks_od) > 0 && StrToInt(eks_do) > 0 && StrToInt(eks_od) <= pomocnicza.wartosc.length()) {
                        pomocnicza.wartosc = pomocnicza.wartosc.substr(pomocnicza.wartosc.length()-StrToInt(eks_od),StrToInt(eks_od)-StrToInt(eks_do)+1);
                        pomocnicza.poprzecinku = "0";
                    }
                    else if(StrToInt(eks_od) > 0 && StrToInt(eks_do) < 0 && StrToInt(eks_od) <= pomocnicza.wartosc.length() && -1*StrToInt(eks_do) <= pomocnicza.poprzecinku.length()) {
                        pomocnicza.wartosc = pomocnicza.wartosc.substr(pomocnicza.wartosc.length()-StrToInt(eks_od),StrToInt(eks_od));
                        pomocnicza.poprzecinku = pomocnicza.poprzecinku.substr(0,-1*StrToInt(eks_do));
                    }
                    else if(StrToInt(eks_od) < 0 && StrToInt(eks_do) < 0 && -1*StrToInt(eks_do) <= pomocnicza.poprzecinku.length()) {
                        pomocnicza.wartosc = "0";
                        pomocnicza.poprzecinku = pomocnicza.poprzecinku.substr(-1*StrToInt(eks_od)-1,-1*(StrToInt(eks_do)-StrToInt(eks_od))+1);
                    }
                    else {
                        pomocnicza.wartosc = "0";
                        pomocnicza.poprzecinku = "0";
                    }
                }
                else {
                    throw "Nieprawidlowe dane do ekstrakcji z liczby: " + wypisz(pomocnicza);
                }
            }
        }

        // znak mno¿enia lub dzielenia
        else if(wyrazenie[j] == '*' || wyrazenie[j] == '/') {
            dzialanie = wyrazenie[j];
        }

        // znak dodawania lub odejmowania
        else if(wyrazenie[j] == '+' || wyrazenie[j] == '-') {
            dzialanie = wyrazenie[j];
            j++;
            i = j;

            while(j < wyrazenie.length()){
                if(wyrazenie[j] == '('){
                nawias++;
                while(nawias > 0) {
                    j++;
                    if(wyrazenie[j] == '(')
                        nawias++;
                    else if(wyrazenie[j] == ')')
                        nawias--;
                }
                }
                if(wyrazenie[j] == '+' || wyrazenie[j] == '-') {
                    j--;
                    break;
                }
                j++;
            }
            pomocnicza = oblicz(wyrazenie.substr(i,j-i+1), precyzja);
            pusta = 0;
        }

        // pozostale znaki
        else if(wyrazenie[j] != ' ' && wyrazenie[j] != '.' && wyrazenie[j] != ']' && wyrazenie[j] != '[') {
           throw string("Nierozpoznany znak: ") + wyrazenie[j];
        }

        if(wyrazenie[j+1] == ':') {
            j=j+2;
            i = j;
            long long int z = 0;
            while(wyrazenie[j] == ' ')
                j++;
            z = j;
            while(isdigit(wyrazenie[j+1]) || wyrazenie[j+1] == '.'){
                j++;
            }
            if(wyrazenie.substr(z,j-z+1).find('.') != string::npos)
                precyzja = -1*StrToInt(wyrazenie.substr(1+z+wyrazenie.substr(z,j-z+1).find('.'),j-z+1));
            else {
                precyzja = StrToInt(wyrazenie.substr(z,j-z+1));
            }
        }

        // pierwsza liczba
        if(dzialanie == "" && !isdigit(wyrazenie[j+1]) && wyrazenie[j+1] != '.' && !pusta) {
            wynik.znak = pomocnicza.znak;
            wynik.wartosc = pomocnicza.wartosc;
            wynik.poprzecinku = pomocnicza.poprzecinku;
            pomocnicza = czysc();
            pusta = 1;
            precyzja = prestart;
        }

        // mnozenie
        if(dzialanie == "*" && !pusta)
            wynik = precyzuj(mnozenie(wynik, pomocnicza),precyzja);

        // dzielenie
        else if(dzialanie == "/" && !pusta)
            wynik = precyzuj(dzielenie(wynik, pomocnicza, (precyzja<0)?(-1*precyzja+2):10),precyzja);

        // dodawanie
        else if(dzialanie == "+" && !pusta)
            wynik = precyzuj(dodawanie(wynik, pomocnicza),precyzja);

        // odejmowanie
        else if(dzialanie == "-" && !pusta)
            wynik = precyzuj(odejmowanie(wynik, pomocnicza),precyzja);

        // czyszczenie
        if(dzialanie != "" && !pusta){
            pomocnicza = czysc();
            pusta = 1;
            dzialanie = "";
            precyzja = prestart;
        }

        j++;
    }
    return trim(wynik);
}


#endif // OBLICZ_H_INCLUDED
