#include <iostream>
#include <string>

using namespace std;

bool isNumber(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]) == false) return false;
    }
    return true;
}

void run(int argc, const char* argv[])
{
    if(argc != 4) throw logic_error("Zła ilość argumentów !!!");
    else
    {
        if(isNumber(argv[1]) and isNumber(argv[3]))
        {
            int a = stoi(argv[1]);
            int b = stoi(argv[3]);

            switch(*argv[2])
            {
                case '+':
                    cout << "Wynik: " << a + b << endl;
                break;

                case '-':
                    cout << "Wynik: " << a - b << endl;
                break;

                case '*':
                    cout << "Wynik: " << a * b << endl;
                break;

                case '/':
                    if(b == 0) throw logic_error("Nie dzieli się przez zero !!!");
                    else cout << "Wynik: " << a / b << endl;
                break;

                case '%':
                    cout << "Wynik: " << a % b << endl;
                break;

                case '&':
                    cout << "Wynik: " << (a & b) << endl;
                break;

                case '|':
                    cout << "Wynik: " << (a | b) << endl;
                break;

                case '^':
                    cout << "Wynik: " << (a ^ b) << endl;
                break;

                default:
                    throw logic_error("Wprowadzono zły operator !!!");
                break;
            }
        }
        else
        {
            throw logic_error("Wprowadzono inny znak niż liczba całkowita !!!");
        }
    }
}

int main(int argc, const char* argv[])
{
    try
    {
        run(argc, argv);
    }
    catch(exception &error)
    {
        cerr << "Błąd: " << error.what() << endl;
    }

    return 0;
}
