#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Truba.h";
#include "KS.h";
#include "utils.h";

using namespace std;

Truba& selectTruba(vector<Truba>& Truboprovod)//Выбираем нужную трубу
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	return Truboprovod[index - 1];
}

void deleteTruba(vector<Truba>& Truboprovod)//Удаление трубы
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(Truboprovod.begin() + index - 1);
}

bool SearchTrubaByName(const Truba& t, std::string parametr)//Поиск по имени
{
	return t.name == parametr;
}

bool SearchTrubaBySostoyanie(const Truba& t, bool parametr)//Поиск по стостоянию
{
	return t.sostoyanie == parametr;
}

KS& selectKS(vector<KS>& Zavod)//Выбор компрессорной станции
{
	unsigned int index = getint("Введите номер компрессорной станции", (size_t)1u, Zavod.size());
	return Zavod[index - 1];
}

void deleteKS(vector<KS>& Zavod)//Удаление компрессорной станции
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Zavod.size());
	Zavod.erase(Zavod.begin() + index - 1);
}

bool SearchKSByName(const KS& ks, std::string parametr)//Поиск по имени
{
	return ks.name == parametr;
}

bool SearchKSByNinwork(const KS& ks, double parametr)//Поиск по проценту не работающих цехов
{
	return (1 - (ks.ninwork / ks.n ))>= parametr/100;
}

void printmenu()
{
	cout << "1-Добавить трубу\n";
	cout << "2-Добавить компрессорную станцию\n";
	cout << "3-Вывести данные на экран\n";
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
			Truba t;
			cin >> t;
			Truboprovod.push_back(t);
			break;
		}
		case 2:
		{
			KS ks;
			cin >> ks;
			Zavod.push_back(ks);
			break;
		}
		case 3:
		{
			if (Truboprovod.size()>0 || Zavod.size()>0)
			{
				if (Truboprovod.size()>0)
				{
					for (auto& infotruba : Truboprovod)
					{
						cout << infotruba;
					}
				}
				else
				{
					cout << "Труба не создана.\n";
				}
				if (Zavod.size() > 0)
				{
					for (auto& infoKS : Zavod)
					{
						cout << infoKS;
					}
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
				selectTruba(Truboprovod).editTruba();
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
				selectKS(Zavod).editKS();
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
						for (auto& infotruba : Truboprovod)
						{
							infotruba.savefileTruba(fout);
						}
					}
					if (Zavod.size() > 0)
					{
						for (auto& infoKS : Zavod)
						{
							infoKS.savefileKS(fout);
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
						infotruba.inputfileTruba(fin);
						Truboprovod.push_back(infotruba);
					}
				}
				if (countks>0)
				{
					while (countks--)
					{
						infoKS.inputfileKS(fin);
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