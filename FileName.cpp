#include <iostream>
#include <Windows.h>
#include <string>

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
	// Конструктор с параметрами
	Product(string productName, int price)
	{
		this->price = price;
		this->productName = productName;
	}
};