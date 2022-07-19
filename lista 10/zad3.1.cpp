#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

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

int main()
{
    string line;
    vector<string> lines;
    fstream file("instrukcje.txt");
    while (getline(file, line)) lines.push_back(line);

    int add_ = count_if(lines.begin(), lines.end(), add);
    int del_ = count_if(lines.begin(), lines.end(), del);

    cout << add_ - del_ << endl;

    file.close();
    return 0;
}
