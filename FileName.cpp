#include <iostream>
#include <Windows.h>
#include <string>

#include "example.cpp"

using namespace std;

struct Product
{
	// Название продукта
	string productName;
	// Цена продукта
	int price;

	// Конструктор по умолчанию
	Product()
	{
		price = 0;
	}
	// Конструктор с параметрамии
	Product(string productName, int price)
	{
		this->price = price;
		this->productName = productName;
	}
};

int main()
{
	return 0;
}