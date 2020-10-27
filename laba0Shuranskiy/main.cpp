#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Truba.h";
#include "KS.h";
using namespace std;
template <typename T>
T getint(string text, T border1, T border2)
{
	T value;
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
	t.dlina=getint("Введите длину трубы (Еденица измерения: м)",1.0,10000.0);
	t.diametr = getint("Введите диаметр трубы(Еденица измерения : мм)",1,10000);
	t.sostoyanie = false;
	return t;
}
KS creatKS()//Создание компрессорной станции
{
	KS ks;
	cout << "Введите имя компрессорной станции\n";
	cin.get();
	getline(cin,ks.name);
	ks.n = getint("Введите количество цехов", 1,10000);
	ks.ninwork = getint("Введите количество цехов в работе", 0,ks.n);
	ks.efect = getint("Введите эффективность компрессорной станцции (Эффективность измеряется по 10-ти бальной шкале)", 0,10000);
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
Truba& selectTruba(vector<Truba>& Truboprovod)
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	return Truboprovod[index-1];
}
KS& selectKS(vector<KS>& Zavod)
{
	unsigned int index = getint("Введите номер компрессорной станции", (size_t)1u, Zavod.size());
	return Zavod[index-1];
}
void deleteTruba(vector<Truba>& Truboprovod)
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(Truboprovod.begin() + index - 1);
}
void deleteKS(vector<KS>& Zavod)
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Zavod.size());
	Zavod.erase(Zavod.begin() + index - 1);
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
	cout << "8-Удалить трубу\n";
	cout << "9-Удалить компрессорную станцию\n";
	cout << "0-Выход\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector <Truba> Truboprovod;
	vector <KS> Zavod;
	while (1)
	{
		printmenu();
		int i;
		i=getint("Введите номер действия",0,10000);
		switch (i)
		{
		case 1:
		{
			Truboprovod.push_back(creatTruba());
			break;
		}
		case 2:
		{
			Zavod.push_back(creatKS());
			break;
		}
		case 3:
		{
			if (Truboprovod.size()>0 || Zavod.size()>0)
			{
				if (Truboprovod.size()>0)
				{
					printTruba(selectTruba(Truboprovod));
				}
				else
				{
					cout << "Труба не создана.\n";
				}
				if (Zavod.size() > 0)
				{
					printKS(selectKS(Zavod));
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
			if (Truboprovod.size()>0)
			{
				editTruba(selectTruba(Truboprovod));
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
			if (Zavod.size()>0)
			{
				editKS(selectKS(Zavod));
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
			if (Truboprovod.size()>0||Zavod.size()>0)
			{
				ofstream fout;
				fout.open("info.txt", ios::out);
				if (fout.is_open())
				{
					fout << Truboprovod.size()<<endl;
					fout << Zavod.size()<< endl;
					if (Truboprovod.size() > 0)
					{
						for (Truba infotruba : Truboprovod)
						{
							savefileTruba(fout, infotruba);
						}
					}
					if (Zavod.size() > 0)
					{
						for (KS infoKS : Zavod)
						{
							savefileKS(fout, infoKS);
						}
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
				int countt;
				int countks;
				fin >> countt;
				fin >> countks;
				Truba infotruba;
				KS infoKS;
				if (countt>0)
				{
					while (countt--)
					{
						infotruba = inputfileTruba(fin);
						Truboprovod.push_back(infotruba);
					}
				}
				if (countks)
				{
					while (countks--)
					{
						infoKS = inputfileKS(fin);
						Zavod.push_back(infoKS);
					}
				}
				fin.close();
			}
			break;
		}
		case 8:
		{
			deleteTruba(Truboprovod);
			break;
		}
		case 9:
		{
			deleteKS(Zavod);
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