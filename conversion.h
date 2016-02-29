#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED
using namespace std;

// zamiana stringa na int
int StrToInt(string l){
    return atoi(l.c_str());
}

// zamiana stringa na int
int StrToInt(char l){

    stringstream ss;
    string s;
    ss << l;
    ss >> s;

    return atoi(s.c_str());
}

// zamiana int na stringa
string IntToStr(int l){
       ostringstream oss;
       oss << l;
       return oss.str();
}

#endif // CONVERSION_H_INCLUDED
