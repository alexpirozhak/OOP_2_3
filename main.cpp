#include <iostream>
#include "LongLong.h"

using namespace std;

int main()
{
    LongLong num1, num2;
    cout << "Default num1: " << num1 << endl;

    long highPart, lowPart;
    cout << "Enter new values for num1:" << endl;
    cout << "Enter highPart: ";
    cin >> highPart;
    while (true)
    {
        cout << "Enter lowPart: ";
        cin >> lowPart;
        if (lowPart >= 0)
            break;
        cout << "LowPart cannot be negative. Try again..." << endl;
    }
    num1.setHighPart(highPart);
    num1.setLowPart(lowPart);

    LongLong num3 = num1;
    cout << "Copy of num1 (using copy constructor): " << num3 << endl;

    cout << "Enter values for num2 (highPart, then lowPart):" << endl;
    cin >> num2;

    num3 = num2;
    cout << "Copy of num2 (using copy assignment): " << num3 << endl;

    if (num1 == num2)
        cout << "num1 == num2" << endl;
    if (num1 != num2)
        cout << "num1 != num2" << endl;
    if (num1 > num2)
        cout << "num1 > num2" << endl;
    if (num1 < num2)
        cout << "num1 < num2" << endl;
    if (num1 >= num2)
        cout << "num1 >= num2" << endl;
    if (num1 <= num2)
        cout << "num1 <= num2" << endl;

    cout << "Difference = " << num1 - num2 << endl;
    cout << "Quotient = " << num1 / num2 << endl;
    return 0;
}
