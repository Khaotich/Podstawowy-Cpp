#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
    if(argc > 1)
    {
        string info = "Program przeznaczony do sumowania argumentow wejsciowych";
        vector <string> args(argv + 1, argv + argc);

        if((find(args.begin(), args.end(), "--help") != args.end()) or find(args.begin(), args.end(), "-h") != args.end())
        {
            cout << info << endl;
        }
        else
        {
            double sum = 0;
            for(int i = 0; i < args.size(); i++)
            {
                double value = stod(args[i]);
                sum += value;
            }
            cout << sum << endl;
        }
    }
    else
    {
        cout << "Brak argumentow wejsciowych !!!" << endl;
    }

    return 0;
}
