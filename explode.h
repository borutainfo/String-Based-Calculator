#ifndef EXPLODE_H_INCLUDED
#define EXPLODE_H_INCLUDED

using namespace std;

vector<string> explode(const string& str, const char delimiter)
{
  vector<string> elements;
  stringstream stream(str);
  string item;
  while (getline(stream, item, delimiter))
    elements.push_back(item);

  return elements;
}

vector<string> explode(const string&, const char);

#endif // EXPLODE_H_INCLUDED
