#include <iostream>
#include "QuadraticEquationLib.h"
using namespace std;
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;

bool CheckBounds(int num)
{
    return (LEFT_BOUND <= num && num <= RIGHT_BOUND);
}

int readCorrectValue(int num) {
    while ((!(cin >> num) || (cin.peek() != '\n')) || !CheckBounds(num)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректное значение\n";
        cout << "Попробуйте снова: ";
    }
    return num;
}


int* inputValues(int a, int b, int c) {
    int* arr = new int[3];
    cout << "Введите параметр a: ";
    arr[0] = readCorrectValue(a);
    cout << "Введите параметр b: ";
    arr[1] = readCorrectValue(b);
    cout << "Введите параметр c: ";
    arr[2] = readCorrectValue(c);
    return arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string ok;
    do {
        ok = "";
        int* arr = inputValues(NULL, NULL, NULL);
        system("cls");
        cout << "Вы ввели: "
            << arr[0] << "*x^2 + ("
            << arr[1] << ")*x + ("
            << arr[2] << ") = 0\n";
        if (arr[0] == 0) {
            cout << "Данное уравнение не является квадратным!\n";
        }
        else {
            double* ans = quadraticEquation(arr[0], arr[1], arr[2]);
            if (isnan(ans[1])) {
                cout << "Корень: " << ans[0] << endl;
            }
            else if (discriminant(arr[0], arr[1], arr[2]) < 0) {
                cout << "Два комплексных корня!\n"
                    << "Первый корень: " << ans[0] << "+i*" << ans[1] << endl
                    << "Второй корень: " << ans[0] << "-i*" << ans[1] << endl;
            }
            else {
                cout << "Два действительных корня!\n"
                    << "Первый корень: " << ans[0] << endl
                    << "Второй корень: " << ans[1] << endl;
            }
        }
        while (ok != "y" && ok != "n") {
            cout << "Хотите решить еще одно уравнение? y/n ";
            cin >> ok;
        }
    } while (ok == "y");
}


