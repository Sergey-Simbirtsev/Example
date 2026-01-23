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

// Сортировка обменом
static void bubbleSorting(Product* store, int countProduct, int& countComparisons, int& countExchanges)
{
	for (int i{}; i < countProduct - 1; ++i)
	{
		bool flag = false;
		for (int j{ countProduct - 1 }; j > i; --j)
		{
			countComparisons++;
			if (store[j].price > store[j - 1].price) 
			{
				swap(store[j], store[j - 1]);
				flag = true;
				countExchanges++;
			}
		}
		if (!flag) return;
	}
}

// Сортировка выбором
static void selectionSort(Product* store, int countProduct, int& countComparisons, int& countExchanges)
{
	for (size_t i{}; i < countProduct - 1; ++i)
	{
		int max = store[i].price;
		size_t ind = i;
		for (size_t j{ i + 1 }; j < countProduct; ++j)
		{
			countComparisons++;
			if (store[j].price > max)
			{
				ind = j;
				max = store[j].price;
				countExchanges++;
			}
		}
		if (i != ind)
		{
			swap(store[i], store[ind]);
		}
	}
}


int main()
{
	// Локализуем консоль
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Выбор пользователя
	int choice{};
	// Количество продуктов
	int countProduct{};
	cout << "Введите количество продуктов, которые Вы хотите ввести: ";
	// Валидация ввода количества продуктов
	while (!(cin >> countProduct))
	{
		cout << "Не верный ввод. Пожалуйста, введите целое число" << endl;
		cin.clear();
		cin.ignore();
	}
	Product* store = new Product[countProduct];
	while (true)
	{
		// Чистим консоль
		system("cls");
		// В данные переменные будем записывать количество сравнений и количество обменов
		int countComparisons{}, countExchanges{}; // сравнений / обменов
		cout << "Выберите дальнейшие действия:" << endl;
		cout << "1 - Ввод данных" << endl;
		cout << "2 - Вывод исходных данных" << endl;
		cout << "3 - Сортировка обменом" << endl;
		cout << "4 - Сортировка выбором" << endl;
		cout << "5 - Выход из программы" << endl;
		cout << "Ваш выбор: ";
		// Валидация выбора пользователя
		while (!(cin >> choice))
		{
			cout << "Не верный ввод. Пожалуйста, введите целое число" << endl;
			cin.clear();
			cin.ignore();
		}
		switch (choice)
		{
		case 1:
		{
			for (size_t i{}; i < countProduct; ++i)
			{
				cout << "Ввод даных для " << i + 1 << " продукта" << endl;
				cout << "Введите название продукта: ";
				cin.ignore();
				getline(cin, store[i].productName);
				cout << "Введите цену продукта: ";
				// Валидация цены продукта
				while (!(cin >> store[i].price))
				{
					cout << "Не верный ввод. Пожалуйста, введите целое число" << endl;
					cin.clear();
					cin.ignore();
				}
			}
			break;
		}
		case 2:
		{
			for (size_t i{}; i < countProduct; ++i)
			{
				cout << "Вывод даных для " << i + 1 << " продукта" << endl;
				cout << "Название продукта: " << store[i].productName << endl;
				cout << "Цена продукта: " << store[i].price << endl;
			}
			// Задержка программы на 5 сек
			Sleep(5000);
			break;
		}
		case 3:
		{
			bubbleSorting(store, countProduct, countComparisons, countExchanges);
			cout << "Количество сравнений = " << countComparisons << endl;
			cout << "Количество обменов = " << countExchanges << endl;
			// Задержка программы на 5 сек
			Sleep(5000);
			break;
		}
		case 4:
		{
			selectionSort(store, countProduct, countComparisons, countExchanges);
			cout << "Количество сравнений = " << countComparisons << endl;
			cout << "Количество обменов = " << countExchanges << endl;
			// Задержка программы на 5 сек
			Sleep(5000);
			break;
		}
		case 5:
		{
			cout << "Вы вышли из программы. До свидания!" << endl;
			return 0;
		}
		default:
		{
			cout << "Ошибка! Вы ввели неправильный номер. Пожалуйста, повторите" << endl;
			// Задержка программы на 5 сек
			Sleep(5000);
			break;
		}
		}
	}
}