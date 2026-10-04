#include "IntVector.h"
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    IntVector A, B, C;
    int choice;

    do {
        cout << "\n--- МЕНЮ ---" << endl;
        cout << "1. Зчитати вектор A" << endl;
        cout << "2. Зчитати вектор B" << endl;
        cout << "3. Вивести вектор A та B" << endl;
        cout << "4. Отримати елемент вектора за індексом" << endl;
        cout << "5. Додавання (A + B)" << endl;
        cout << "6. Віднімання (A - B)" << endl;
        cout << "7. Множення вектора на скаляр" << endl;
        cout << "8. Ділення вектора на скаляр" << endl;
        cout << "0. Вихід" << endl;
        cout << "Оберіть опцію: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Формування вектора A:" << endl;
            A.Read();
            break;
        case 2:
            cout << "Формування вектора B:" << endl;
            B.Read();
            break;
        case 3:
            cout << "Вектор A: "; A.Display();
            cout << "Вектор B: "; B.Display();
            break;
        case 4: {
            char vChoice;
            cout << "З якого вектора отримати елемент (A/B)? ";
            cin >> vChoice;
            int index;
            cout << "Введіть індекс: ";
            cin >> index;

            if (vChoice == 'A' || vChoice == 'a') {
                cout << "Значення: " << A.getElement(index) << endl;
            }
            else if (vChoice == 'B' || vChoice == 'b') {
                cout << "Значення: " << B.getElement(index) << endl;
            }
            else {
                cout << "Невірний вибір вектора." << endl;
            }
            break;
        }
        case 5:
            C = A.add(B);
            if (C.getSize() > 0) {
                cout << "Результат додавання (A + B): ";
                C.Display();
            }
            break;
        case 6:
            C = A.subtract(B);
            if (C.getSize() > 0) {
                cout << "Результат віднімання (A - B): ";
                C.Display();
            }
            break;
        case 7: {
            char vChoice;
            cout << "Який вектор помножити (A/B)? ";
            cin >> vChoice;
            int scalar;
            cout << "Введіть скаляр для множення: ";
            cin >> scalar;

            if (vChoice == 'A' || vChoice == 'a') {
                A.multiplyByScalar(scalar);
                cout << "Оновлений вектор A: "; A.Display();
            }
            else if (vChoice == 'B' || vChoice == 'b') {
                B.multiplyByScalar(scalar);
                cout << "Оновлений вектор B: "; B.Display();
            }
            else {
                cout << "Невірний вибір вектора." << endl;
            }
            break;
        }
        case 8: {
            char vChoice;
            cout << "Який вектор поділити (A/B)? ";
            cin >> vChoice;
            int scalar;
            cout << "Введіть скаляр для ділення: ";
            cin >> scalar;

            if (vChoice == 'A' || vChoice == 'a') {
                if (A.divideByScalar(scalar)) {
                    cout << "Оновлений вектор A: "; A.Display();
                }
            }
            else if (vChoice == 'B' || vChoice == 'b') {
                if (B.divideByScalar(scalar)) {
                    cout << "Оновлений вектор B: "; B.Display();
                }
            }
            else {
                cout << "Невірний вибір вектора." << endl;
            }
            break;
        }
        case 0:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}