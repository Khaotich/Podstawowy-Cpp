#include <iostream>

using namespace std;

int main()
{
    cout << (0xa - 012) << endl;
    cout << (13 % 3) << endl;
    cout << (3.14 - 3) << endl;
    cout << (1234 ^ 1234) << endl;
    cout << (1 << 3) << endl;
    cout << (0xF & 0xA) << endl;
    cout << (3 > 2 > 1) << endl;
    cout << (12345 + ~12345) << endl;
    cout << (1 + 1e-40 - 1) << endl;
    cout << (1 + 1e-10f - 1) << endl;
    cout << (3 == 3 == 3) << endl;
    cout << (1/4) << endl;
    cout << (16 >> 1) << endl;
    cout << (0xff ^ 0xf0) << endl;
    cout << (~(-1)) << endl;
    cout << (0xff | 0xaa) << endl;
    cout << (1234567 & 1) << endl;
    cout << (1234567 | 1) << endl;
    cout << (1234567 ^ 1) << endl;
    cout << (1 < 2 ? 1 : 2) << endl;
    cout << (1, 2, 3, 4) << endl;
    cout << (3 < 2 & 1 < 2) << endl;
    cout << (1 < 2 && 2 < 1) << endl;
    cout << (1 < 2 || 2 > 1) << endl;
    cout << (0b1111) << endl;
    cout << (-1 > 1u) << endl;
    cout << (0 - 1u > 0) << endl;

    getchar();
    return 0;
}