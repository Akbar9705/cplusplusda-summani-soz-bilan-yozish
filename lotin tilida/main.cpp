#include <iostream>
#include <string>
#include <vector>
using namespace std;

string digitName(int digit);
string teenName(int number);
string tensName(int number);
string intName(int number);

vector<string> ones{"", "bir", "ikki", "uch", "to'rt", "besh", "olti", "yetti", "sakkiz", "to'qqiz"};
vector<string> teens{"o'n", "o'nbir", "o'n ikki", "o'n uch", "o'n to'rt", "o'n besh", "o'n besh", "o'n yetti", "o'n sakkiz", "o'n to'qqiz"};
vector<string> tens{"", "", "yigirma", "o'ttiz", "qirq", "ellik", "oltmish", "yetmish", "sakson", "to'qson"};

string nameForNumber(long number)
{
    if (number < 10)
    {
        return ones[number];
    }
    else if (number < 20)
    {
        return teens[number - 10];
    }
    else if (number < 100)
    {
        return tens[number / 10] + ((number % 10 != 0) ? " " + nameForNumber(number % 10) : " so'm");
    }
    else if (number < 1000)
    {
        return nameForNumber(number / 100) + " yuz" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : " so'm");
    }
    else if (number < 1000000)
    {
        return nameForNumber(number / 1000) + " ming" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : " so'm");
    }
    else if (number < 1000000000)
    {
        return nameForNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : " so'm");
    }
    else if (number < 1000000000000)
    {
        return nameForNumber(number / 1000000000) + " milliard" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : " so'm");
    }
    return "error";
}

int main()
{
    long input;
    do
    {
        cout << "Iltimos istagan summani yozing: ";
        cin >> input;
        cout << "\n"
             << nameForNumber(input) << endl;
        cout << "\n\n"
             << endl;
    } while (input > 0);
    return 0;
}
