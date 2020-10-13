#include <iostream>
#include <fstream>
#include <string>
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
int getint(string text, int border1, int border2=10000)
{
	int value;
	while (1)
	{
		cout << text<<endl;
		cin >> value;
		if (cin.fail() || value < border1 || value >border2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуйте ещё раз.\n";
		}
		else
		{
			return value;
		}
	}

}
Truba creatTruba()//Создание трубы
{
	Truba t;
	t.id = "1";
	while (1)
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
			break;
		}
	}
	t.diametr = getint("Введите диаметр трубы(Еденица измерения : мм)",1);
	t.sostoyanie = false;
	return t;
}
KS creatKS()//Создание компрессорной станции
{
	KS ks;
	cout << "Введите имя компрессорной станции\n";
	cin.get();
	getline(cin,ks.name);
	ks.n = getint("Введите количество цехов", 1);
	ks.ninwork = getint("Введите количество цехов в работе", 0,ks.n);
	ks.efect = getint("Введите эффективность компрессорной станцции (Эффективность измеряется по 10-ти бальной шкале)", 0);
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
	ks.ninwork = getint("Введите количество цехов в работе", 0, ks.n);
}
void savefileTruba(ofstream& fout, const Truba &t)//Сохранение информации о трубе
{
	fout << t.id << endl;
	fout << t.dlina << endl;
	fout << t.diametr << endl;
	fout << t.sostoyanie << endl;
}
Truba inputfileTruba(ifstream& fin)//Считывание информации о трубе
{
	Truba t;
	fin >> t.id;
	fin >> t.dlina;
	fin >> t.diametr;
	fin >> t.sostoyanie;
	return t;
}
void savefileKS(ofstream& fout,const KS &ks)//Сохранение информации о компрессорной станции
{
	fout << ks.name<<endl;
	fout  << ks.n << endl;
	fout  << ks.ninwork << endl;
	fout << ks.efect << endl;
}
KS inputfileKS(ifstream& fin)//Считывание информации о компрессорной станции
{
	KS ks;
	fin >> ks.name;
	fin >> ks.n;
	fin >> ks.ninwork;
	fin >> ks.efect;
	return ks;
}
void printmenu()
{
	cout << "1-Добавить трубу\n";
	cout << "2-Добавить компрессорную станцию\n";
	cout << "3-Вывести информацию о трубе и компрессорной станции\n";
	cout << "4-Редактировать состояние трубы\n";
	cout << "5-Редактировать колличество цехов в работе компрессорной станции\n";
	cout << "6-Сохранить данные файл\n";
	cout << "7-Считать данные из файла\n";
	cout << "0-Выход\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	KS infoks;
	Truba infotruba;
	bool ft = false;
	bool fks = false;
	while (1)
	{
		printmenu();
		int i;
		i=getint("Введите номер действия",0);
		switch (i)
		{
		case 1:
		{
			infotruba=creatTruba();
			ft = true;
			break;
		}
		case 2:
		{
			infoks=creatKS();
			fks = true;
			break;
		}
		case 3:
		{
			if (ft || fks)
			{
				if (ft)
				{
					printTruba(infotruba);
				}
				else
				{
					cout << "Труба не создана.\n";
				}
				if (fks)
				{
					printKS(infoks);
				}
				else
				{
					cout << "Компрессорная станция не создана.\n";
				}
				break;

			}
			else 
			{
				cout << "Труба или Компрессорная станция не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 4:
		{
			if (ft)
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
		case 5:
		{
			if (fks)
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
		case 6:
		{
			if (ft||fks)
			{
				ofstream fout;
				fout.open("info.txt", ios::out);
				if (fout.is_open())
				{
					fout << ft<<endl;
					fout << fks << endl;
					if (ft)
					{
						savefileTruba(fout, infotruba);
					}
					if (fks)
					{
						savefileKS(fout, infoks);
					}
					fout.close();
				}
				break;
			}
			else
			{
				cout << "Труба или Компрессорная станция не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 7:
		{
			ifstream fin;
			fin.open("info.txt", ios::in);
			if (fin.is_open())
			{
				fin >> ft;
				fin >> fks;
				if (ft)
				{
					infotruba = inputfileTruba(fin);
				}
				if (fks)
				{
					infoks = inputfileKS(fin);
				}
			}
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Данные введены не корректно. Попробуйте ещё раз.";
		}
		}
	}
}