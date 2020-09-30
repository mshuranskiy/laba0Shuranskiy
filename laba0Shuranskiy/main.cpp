#include <iostream>
#include <fstream>
using namespace std;
struct Truba//Труба
{
	string id;//Идентификатор
	float dlina;//Длина
	int diametr;//Диаметр
	bool sostoyanie;//Состояние в ремонте или нет

};
struct KS//Компрессорная станция
{
	string name;//Имя
	string id;//идентификатор
	int n;//Количество цехов
	int ninwork;//Количсевто цехов в работе
	int efect;//Эффективность
};
Truba creatTruba()//Создание трубы
{
	Truba t;
	bool f=0;
	while (f == 0)
	{
		cout << "Введите длину трубы (Еденица измерения: м)\n";
		cin >> t.dlina;
		if (cin.fail() || t.dlina <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуйте ещё раз.\n";
		}
		else
		{
			f = 1;
		}
	}
	f = 0;
	while (f == 0)
	{
		cout << "Введите диаметр трубы (Еденица измерения: мм)\n";
		cin >> t.diametr;
		if (cin.fail() || t.diametr <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуйте ещё раз.\n";
		}
		else
		{
			f = 1;
		}
	}
	t.sostoyanie = false;
	return t;
}
KS creatKS()//Создание компрессорной станции
{
	KS ks;
	bool  f = 0;
	cout << "Введите имя компрессорной станции\n";
	cin >> ks.name;
	while (f == 0)
	{
		cout << "Введите количество цехов\n";
		cin >> ks.n;
		if (cin.fail() || ks.n<=0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуйте ещё раз.\n";
		}
		else
		{
			f = 1;
		}
	}
	f = 0;
	while (f == 0)
	{
		cout << "Введите количество цехов в работе\n";
		cin >> ks.ninwork;
		if (cin.fail() || ks.ninwork < 0 || ks.ninwork>ks.n)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуйте ещё раз.\n";
		}
		else
		{
			f = 1;
		}
	}
	f = 0;
	while (f == 0)
	{
		cout << "Введите эффективность компрессорной станцции (Эффективность измеряется по 10-ти бальной шкале)\n";
		cin >> ks.efect;
		if (cin.fail() || ks.efect < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуйте ещё раз.\n";
		}
		else
		{
			f = 1;
		}
	}
	return ks;
}
void printTruba(const Truba &t)//Вывод информации о трубе
{
	cout << "Данные о трубе:\n";
	cout << "Длина трубы: " << t.dlina<<" (м)"<< endl;
	cout << "Диаметр турбы: " << t.diametr << " (мм)" << endl;
	cout << "Состояние трубы: " << (t.sostoyanie ? "В ремонте\n" : "Не в ремонте\n");
}
void printKS(const KS &ks)//Вывод информации о компрессорной станции
{
	cout << "Данные о компрессорной станции:\n";
	cout << "Имя компрессорной станции: " << ks.name << endl;
	cout << "Количество цехов на компрессорной станции: " << ks.n << endl;
	cout << "Количество цехов в работе: " << ks.ninwork << endl;
	cout << "Эффективность компрессорной станции: " << ks.efect << endl;
}
void editTruba(Truba &t)//Отправить трубу в ремонт
{
	t.sostoyanie = !t.sostoyanie;
}
void editKS(KS &ks)//Изменение цоехов в работе
{
	bool f = 0;
	while (f == 0)
	{
		cout << "Введите количество цехов в работе\n";
		cin >> ks.ninwork;
		if (cin.fail() || ks.ninwork < 0 || ks.ninwork > ks.n)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуйте ещё раз.\n";
		}
		else
		{
			f = 1;
		}
	}
}
void savefileTruba(const Truba &t)//Сохранение информации о трубе
{
	ofstream fout;
	fout.open("info.txt", ios::out);
	if (fout.is_open())
	{
		fout << t.dlina << endl;
		fout << t.diametr << endl;
		fout << t.sostoyanie << endl;
		fout.close();
	}
}
Truba inputfileTruba()//Считывание информации о трубе
{
	Truba t;
	ifstream fin;
	fin.open("info.txt", ios::in);
	if (fin.is_open())
	{
		fin >> t.dlina;
		fin >> t.diametr;
		fin >> t.sostoyanie;
		fin.close();
	}
	return t;
}
void savefileKS(const KS &ks)//Сохранение информации о компрессорной станции
{
	ofstream fout;
	fout.open("info.txt", ios::out);
	if (fout.is_open())
	{
		fout << ks.name<<endl;
		fout  << ks.n << endl;
		fout  << ks.ninwork << endl;
		fout << ks.efect << endl;
		fout.close();
	}
}
KS inputfileKS()//Считывание информации о компрессорной станции
{
	KS ks;
	ifstream fin;
	fin.open("info.txt", ios::in);
	if (fin.is_open())
	{
		fin>> ks.name;
		fin >> ks.n;
		fin >> ks.ninwork;
		fin >> ks.efect;
		fin.close();
	}
	return ks;
}
void printmenu()
{
	cout << "1-Добавить трубу\n";
	cout << "2-Добавить компрессорную станцию\n";
	cout << "3-Вывести информацию о трубе\n";
	cout << "4-Вывести информацию о компрессорной станции\n";
	cout << "5-Редактировать состояние трубы\n";
	cout << "6-Редактировать колличество цехов в работе компрессорной станции\n";
	cout << "7-Сохранить данные о трубе в файл\n";
	cout << "8-Сохранить данные о компрессорной станции в файл\n";
	cout << "9-Считать данные о трубе из файла\n";
	cout << "10-Считать данные о компрессорной станции из файла\n";
	cout << "0-Выход\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	KS infoks;
	Truba infotruba;
	bool ft = 0;
	bool fks = 0;
	while (1)
	{
		printmenu();
		cout << "Введите номер действия\n";
		int i;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			infotruba=creatTruba();
			ft = 1;
			break;
		}
		case 2:
		{
			infoks=creatKS();
			fks = 1;
			break;
		}
		case 3:
		{
			if (ft == 1)
			{
			printTruba(infotruba);
			break; 
			}
			else
			{
				cout << "Труба не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 4:
		{
			if (fks == 1)
			{
				printKS(infoks);
				break;
			}
			else
			{
				cout << "Компрессорная станция не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 5:
		{
			if (ft == 1)
			{
				editTruba(infotruba);
				break;
			}
			else
			{
				cout << "Труба не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 6:
		{
			if (fks == 1)
			{
				editKS(infoks);
				break;
			}
			else
			{
				cout << "Компрессорная станция не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 7:
		{
			if (ft == 1)
			{
				savefileTruba(infotruba);
				break;
			}
			else
			{
				cout << "Труба не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 8:
		{
			if (fks == 1)
			{
				savefileKS(infoks);
				break;
			}
			else
			{
				cout << "Компрессорная станция не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 9:
		{
			infotruba=inputfileTruba();
			ft = 1;
			break;
		}
		case 10:
		{
			infoks=inputfileKS();
			fks = 1;
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Данные введены не корректно. Попробуйте ещё раз.";
		}
		}
	}
	/*
	KS infoks = creatKS();
	editKS(infoks);
	printKS(infoks);
	savefileKS(infoks);
	Truba infoTruba=creatTruba();
	editTruba(infoTruba);
	printTruba(infoTruba);
	savefileTruba(infoTruba);*/
}