#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1_4/IntVector.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestOOPLab14
{
	TEST_CLASS(UnitTestOOPLab14)
	{
	public:

		// Тест 1: Перевірка ініціалізації меж та встановлення/отримання елементів
		TEST_METHOD(TestSetBoundsAndElements)
		{
			IntVector v;
			// Встановлюємо межі від 1 до 3 (має створитись масив на 3 елементи)
			bool isBoundSet = v.setBounds(1, 3);
			Assert::IsTrue(isBoundSet);
			Assert::AreEqual(3, v.getSize());

			// Встановлюємо значення
			v.setElement(1, 10);
			v.setElement(2, 20);
			v.setElement(3, 30);

			// Перевіряємо, чи правильно збереглися значення за індексами
			Assert::AreEqual(10, v.getElement(1));
			Assert::AreEqual(20, v.getElement(2));
			Assert::AreEqual(30, v.getElement(3));
		}

		// Тест 2: Перевірка додавання двох векторів (метод add)
		TEST_METHOD(TestVectorAddition)
		{
			IntVector v1, v2;
			v1.setBounds(0, 1);
			v1.setElement(0, 5);
			v1.setElement(1, 10);

			v2.setBounds(0, 1);
			v2.setElement(0, 15);
			v2.setElement(1, 20);

			// Виконуємо додавання
			IntVector result = v1.add(v2);

			// Перевіряємо результати додавання: 5+15=20, 10+20=30
			Assert::AreEqual(20, result.getElement(0));
			Assert::AreEqual(30, result.getElement(1));
		}

		// Тест 3: Перевірка множення вектора на скаляр (метод multiplyByScalar)
		TEST_METHOD(TestScalarMultiplication)
		{
			IntVector v;
			v.setBounds(0, 2);
			v.setElement(0, 2);
			v.setElement(1, 4);
			v.setElement(2, 6);

			// Множимо всі елементи на 3
			v.multiplyByScalar(3);

			// Перевіряємо результати: 2*3=6, 4*3=12, 6*3=18
			Assert::AreEqual(6, v.getElement(0));
			Assert::AreEqual(12, v.getElement(1));
			Assert::AreEqual(18, v.getElement(2));
		}
	};
}