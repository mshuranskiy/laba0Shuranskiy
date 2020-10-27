#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Truba.h";
#include "KS.h";
#include "utils.h";
using namespace std;
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
	cout << "3-Вывести данные\n";
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
					for (const auto& infotruba : Truboprovod)
					{
						printTruba(infotruba);
					}
				}
				else
				{
					cout << "Труба не создана.\n";
				}
				if (Zavod.size() > 0)
				{
					for (const auto& infoKS : Zavod)
					{
						printKS(infoKS);
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
						for (const auto& infotruba : Truboprovod)
						{
							savefileTruba(fout, infotruba);
						}
					}
					if (Zavod.size() > 0)
					{
						for (const auto& infoKS : Zavod)
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