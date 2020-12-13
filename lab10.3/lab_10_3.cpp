#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct Price
{
	int num;
	string nameTowar;
	string shop;
	int cost;
};


void Create(string file);
void Print(string file);
void Add(string file);
void search(string file);
int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string fname;
	int MenuItem;
	do
	{
		cout << endl;
		cout << " Список дій:" << endl << endl;
		cout << " [1] - Створити список" << endl;
		cout << " [2] - Переглянути список" << endl;
		cout << " [3] - Пошук по списку" << endl;
		cout << " [4] - Доповнити список" << endl << endl;
		cout << " [0] - Вихід." << endl << endl;
		cout << " Оберіть дію: "; cin >> MenuItem;
			switch (MenuItem)
			{
			case 1:
				cin.get(); 
				cin.sync(); 
				cout << " Введіть ім'я файлу: "; getline(cin, fname);
				Create(fname);
				break;
			case 2:
				cin.get();
				cin.sync();
				cout << " Введіть ім'я файлу: "; getline(cin, fname);
				Print(fname);
				cin.get();
				break;
			case 3:
				cin.get();
				cin.sync();
				cout << " Введіть ім'я файлу: "; getline(cin, fname);
				search(fname);
				cin.get();
				break;
			case 4:
				cin.get();
				cin.sync();
				cout << " Введіть ім'я файлу: "; getline(cin, fname);
				Add(fname);
				cin.get();
				break;
			case 0:
				break;
			default:
				cout << " Введено невірне значення! ";
			}
			cin.get();
			cin.sync();
	} while (MenuItem != 0);

	cin.get();
	cin.sync();
	return 0;
}

void Create(string file)
{
	Price shop;
	char ch;
	ofstream t(file, ios::out | ios::trunc);
	if (!t)
	{
		cerr << "Error opening file '" << file << "'" << endl;
		return;
	}

	do {
		cout << endl; 

		cin.get();
		cin.sync();
		cout << " №: "; cin >> shop.num;
		
		cin.get();
		cin.sync();
		cout << " Магазин: "; getline(cin, shop.shop);
		
		cin.get();
		cin.sync(); 
		cout << " Назва товару: "; getline(cin, shop.nameTowar);
		
		cin.get();
		cin.sync();
		cout << " Ціна: "; cin >> shop.cost;
		
		cout << endl;
		if (!t.write((char*)&shop, sizeof(Price)))
		{
			cout << " not writing" << endl;
		}
		cout << " Продовжити поповнення списку? (y/n) "; cin >> ch;
	} while (ch != 'n');
	t.close();
	cin.get();
	cin.sync();
}

void Print(string file) 
{
	Price shop;
	char s[100];
	int counter = 0;
	string str;
	ifstream t(file, ios::in);
	if (!t)
	{
		cerr << "Error opening file '" << file << "'" << endl;
		return;
	}

	cout << "=========================================================="
			<< endl;
	cout << "|  №  |     Магазин     |      Товар      |     Ціна     |"
			<< endl;
	cout << "=========================================================="
			<< endl;
	while (!t.eof())
	{
		getline(t, str);
		counter++;
	}
	t.close();
	t.open(file, ios::in);

	while(t.read((char*)&shop, sizeof(Price)))
	{       
			
			cout << "| " << setw(3) << right << shop.num << " ";
			
			cout << "| " << setw(16) << left << shop.shop;
			
			cout << "| " << setw(16) << left << shop.nameTowar;
			
			cout << "| " << setw(12) << right << setprecision(2) << shop.cost << " |";
			cout << endl;
			cout << "----------------------------------------------------------";
			cout << endl;
	}
	t.close();
	cin.get();
	cin.sync();
}

void Add(string file)
{
	Price shop;
	char ch;
	ofstream t(file, ios::out | ios::app);
	if (!t)
	{
		cerr << "Error opening file '" << file << "'" << endl;
		return;
	}

	do {
		cout << endl;

		cin.get();
		cin.sync();
		cout << " №: "; cin >> shop.num;

		cin.get();
		cin.sync();
		cout << " Магазин: "; getline(cin, shop.shop);

		cin.get();
		cin.sync();
		cout << " Назва товару: "; getline(cin, shop.nameTowar);

		cin.get();
		cin.sync();
		cout << " Ціна: "; cin >> shop.cost;

		cout << endl;
		if (!t.write((char*)&shop, sizeof(Price)))
		{
			cout << " not writing" << endl;
		}
		cout << " Продовжити поповнення списку? (y/n) "; cin >> ch;
	} while (ch != 'n');
	t.close();
	cin.get();
	cin.sync();
}

void search(string file)
{
	ifstream t(file, ios::in | ios::binary);
	if (!t)
	{
		cerr << "Error opening file '" << file << "'" << endl;
		return;
	}
	string needString;
	bool  f;
	f = false;
	cin.get();
	cin.sync();
	cout << " Введіть назву товару для пошуку: "; getline(cin, needString);
	struct Price a;
	while (!t.eof())
	{
		t.read((char*)&a, sizeof(a));
		if (a.nameTowar == needString)
		{
			f = true;
			cout << "=========================================================="
				<< endl;
			cout << "|  №  |     Магазин     |      Товар      |     Ціна     |"
				<< endl;
			cout << "----------------------------------------------------------"
				<< endl;


			cout << "| " << setw(3) << right << a.num << " ";

			cout << "| " << setw(16) << left << a.shop;

			cout << "| " << setw(16) << left << a.nameTowar;

			cout << "| " << setw(12) << right << setprecision(2) << a.cost << " |";
			cout << endl;
			cout << "----------------------------------------------------------" << endl;
		}
	}
		if (f == false)
		{
			cout << " Не знайдено! " << endl;
		}
	
	
	t.close();
	cin.get();
	cin.sync();
}
