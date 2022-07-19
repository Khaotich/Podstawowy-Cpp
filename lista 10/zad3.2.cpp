#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string text;

bool add(string e)
{
    int l = e.find("DOPISZ");
    if(l != string::npos) return true;
    else return false;
}

bool del(string e)
{
    int l = e.find("USUN");
    if(l != string::npos) return true;
    else return false;
}

bool change(string e)
{
    int l = e.find("ZMIEN");
    if(l != string::npos) return true;
    else return false;
}

bool next(string e)
{
    int l = e.find("PRZESUN");
    if(l != string::npos) return true;
    else return false;
}

void task(string e)
{
    int type_task = 0;
    if(add(e)) type_task = 1;
    else if(del(e)) type_task = 2;
    else if(change(e)) type_task = 3;
    else if(next(e)) type_task = 4;

    switch(type_task)
    {
        case 1:
            text += e.back();
            break;

        case 2:
            text = text.substr(0, text.size()-1);
            break;

        case 3:
            swap(text.back(), e.back());
            break;

        case 4:
            if(text.find(e.back()) != string::npos)
            {
                int index = text.find(e.back());
                if(e.back() == 'Z')
                {
                    text[index] = 'A';
                }
                else
                {
                    text[index] = char(int(e.back())+1);
                }
            }
            break;
        }
}

int main()
{
    string line;
    vector<string> lines;
    fstream file("instrukcje.txt");
    while (getline(file, line)) lines.push_back(line);

    text = "";
    for(int i = 0; i < lines.size(); i++) task(lines[i]);
    cout << text << endl;

    file.close();
    return 0;
}
