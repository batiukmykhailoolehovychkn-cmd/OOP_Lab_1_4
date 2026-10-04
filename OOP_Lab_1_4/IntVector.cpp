#include "IntVector.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

IntVector::IntVector() : data(nullptr), lower_bound(0), upper_bound(-1), size(0) {}

IntVector::IntVector(const IntVector& other) : data(nullptr), lower_bound(other.lower_bound), upper_bound(other.upper_bound), size(other.size) {
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
}

IntVector::~IntVector() {
    if (data != nullptr) {
        delete[] data;
    }
}

IntVector& IntVector::operator=(const IntVector& other) {
    if (this != &other) {
        delete[] data;
        lower_bound = other.lower_bound;
        upper_bound = other.upper_bound;
        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}

int IntVector::getLowerBound() const { return lower_bound; }
int IntVector::getUpperBound() const { return upper_bound; }
int IntVector::getSize() const { return size; }

bool IntVector::setBounds(int lower, int upper) {
    if (lower > upper) return false;
    lower_bound = lower;
    upper_bound = upper;
    size = upper - lower + 1;

    if (data != nullptr) delete[] data;
    data = new int[size]();
    return true;
}

int IntVector::getElement(int index) const {
    if (index < lower_bound || index > upper_bound) {
        cout << "Помилка: індекс поза межами масиву!" << endl;
        return 0;
    }
    return data[index - lower_bound];
}

bool IntVector::setElement(int index, int value) {
    if (index < lower_bound || index > upper_bound) {
        cout << "Помилка: індекс поза межами масиву!" << endl;
        return false;
    }
    data[index - lower_bound] = value;
    return true;
}

bool IntVector::Init(int lower, int upper) {
    // Делегуємо перевірку методу setBounds
    return setBounds(lower, upper);
}

void IntVector::Read() {
    int lower, upper;
    cout << "Введіть нижню межу індексів: ";
    cin >> lower;
    cout << "Введіть верхню межу індексів: ";
    cin >> upper;

    while (!Init(lower, upper)) {
        cout << "Помилка ініціалізації! Нижня межа має бути <= верхній. Спробуйте ще раз." << endl;
        cout << "Введіть нижню межу індексів: ";
        cin >> lower;
        cout << "Введіть верхню межу індексів: ";
        cin >> upper;
    }

    cout << "Введіть " << size << " елементів масиву:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Елемент [" << lower_bound + i << "] = ";
        cin >> data[i];
    }
}

void IntVector::Display() const {
    cout << toString();
}

string IntVector::toString() const {
    stringstream sout;
    sout << "Вектор (межі " << lower_bound << ".." << upper_bound << "): [ ";
    for (int i = 0; i < size; ++i) {
        sout << data[i] << " ";
    }
    sout << "]" << endl;
    return sout.str();
}

IntVector IntVector::add(const IntVector& other) const {
    IntVector result;
    if (lower_bound != other.lower_bound || upper_bound != other.upper_bound) {
        cout << "Помилка: масиви мають різні межі, додавання неможливе!" << endl;
        return result;
    }
    result.Init(lower_bound, upper_bound);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

IntVector IntVector::subtract(const IntVector& other) const {
    IntVector result;
    if (lower_bound != other.lower_bound || upper_bound != other.upper_bound) {
        cout << "Помилка: масиви мають різні межі, віднімання неможливе!" << endl;
        return result;
    }
    result.Init(lower_bound, upper_bound);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

void IntVector::multiplyByScalar(int scalar) {
    for (int i = 0; i < size; ++i) {
        data[i] *= scalar;
    }
}

bool IntVector::divideByScalar(int scalar) {
    if (scalar == 0) {
        cout << "Помилка: ділення на нуль!" << endl;
        return false;
    }
    for (int i = 0; i < size; ++i) {
        data[i] /= scalar;
    }
    return true;
}