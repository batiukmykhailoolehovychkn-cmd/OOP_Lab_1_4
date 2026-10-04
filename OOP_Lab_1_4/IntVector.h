#pragma once
#include <string>
#include <iostream>
#include <sstream>

class IntVector {
private:
    int* data;
    int lower_bound;
    int upper_bound;
    int size;

public:
    // Конструктори та деструктор
    IntVector();
    IntVector(const IntVector& other); // Конструктор копіювання
    ~IntVector();

    // Оператор присвоєння
    IntVector& operator=(const IntVector& other);

    // Методи доступу (гетери та сетери)
    int getLowerBound() const;
    int getUpperBound() const;
    int getSize() const;
    bool setBounds(int lower, int upper);

    // Доступ до окремого елементу з контролем виходу за межі масиву
    int getElement(int index) const;
    bool setElement(int index, int value);

    // Обов'язкові методи
    bool Init(int lower, int upper);
    void Read();
    void Display() const;
    std::string toString() const;

    // Специфічні операції за завданням
    IntVector add(const IntVector& other) const;
    IntVector subtract(const IntVector& other) const;
    void multiplyByScalar(int scalar);
    bool divideByScalar(int scalar);
};