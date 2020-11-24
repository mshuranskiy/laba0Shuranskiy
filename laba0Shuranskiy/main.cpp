#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Truba.h";
#include "KS.h";
#include "utils.h";

using namespace std;
//unsigned int Truba::IDt;

Truba& selectTruba(map<int,Truba>& Truboprovod)//Выбираем нужную трубу
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	return Truboprovod[index - 1];
}

void deleteTruba(map<int,Truba>& Truboprovod)//Удаление трубы
{
	unsigned int index = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(index - 1);
}

bool SearchTrubaByName(const Truba& t, std::string parametr)//Поиск по имени
{
	return t.name == parametr;
}

bool SearchTrubaBySostoyanie(const Truba& t, bool parametr)//Поиск по стостоянию
{
	return t.sostoyanie == parametr;
}

KS& selectKS(map<int,KS>& Zavod)//Выбор компрессорной станции
{
	unsigned int index = getint("Введите номер компрессорной станции", (size_t)1u, Zavod.size());
	return Zavod[index - 1];
}

void deleteKS(map<int,KS>& Zavod)//Удаление компрессорной станции
{
	unsigned int index = getint("Введите номер компрессорной станции", (size_t)1u, Zavod.size());
	Zavod.erase(index - 1);
}

bool SearchKSByName(const KS& ks, std::string parametr)//Поиск по имени
{
	return ks.name == parametr;
}

bool SearchKSByNnowork(const KS& ks, double parametr)//Поиск по проценту не работающих цехов
{
	return (1.0-((double)ks.ninwork / ks.n) >= parametr/100.0);
}

bool selectFilterTruba(map<int,Truba>& Truboprovod, map<int,Truba>& infotruba)
{
	cout << "Фильтры:\n";
	cout << "1-По имени\n";
	cout << "2-По состоянию в ремонте\n";
	int i = getint("Введите номер фильтра", 1, 2);
	switch (i)
	{
	case 1:
	{
		bool f=false;
		cout << "Введите имя трубы\n";
		string name;
		cin.get();
		getline(cin, name);
		for (auto& i : SearchTrubaByFilter(Truboprovod, SearchTrubaByName, name))
		{
			infotruba[i]=Truboprovod[i];
			f = true;
		}
		return f;
		break;
	}
	case 2:
	{
		bool f=false;
		cout << "Поиск труб находящихся в ремонте\n";
		for (auto& i : SearchTrubaByFilter(Truboprovod, SearchTrubaBySostoyanie, true))
		{
			infotruba[i] = Truboprovod[i];
			f = true;
		}
		return f;
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуйте ещё раз.\n";
	}
	}
}

bool selectFilterKS(map<int,KS>& Zavod, map<int,KS>& infoks)
{
	cout << "Фильтры:\n";
	cout << "1-По имени\n";
	cout << "2-По проценту незадействованых цехов\n";
	int i = getint("Введите номер фильтра", 1, 2);
	switch (i)
	{
	case 1:
	{
		bool f = false;
		cout << "Введите имя компрессорной станции\n";
		string name;
		cin.get();
		getline(cin, name);
		for (auto& i : SearchKSByFilter(Zavod, SearchKSByName, name))
		{
			infoks[i]=Zavod[i];
			f = true;
		}
		return f;
		break;
	}
	case 2:
	{
		bool f = false;
		double procent = getint("Введите процент незадействованных цехов", 1, 100);
		for (auto& i : SearchKSByFilter(Zavod, SearchKSByNnowork, procent))
		{
			infoks[i]=Zavod[i];
			f = true;	
		}
		return f;
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуйте ещё раз.\n";
	}
	}
}

void changeTrubaSostoyanie(map<int,Truba>& Truboprovod)
{
	cout << "Варианты редактирования:\n";
	cout << "1-Отправить все трубы в ремонт\n";
	cout << "2-Отправить конкретные трубы в ремонт\n";
	cout << "3-Починить все трубы\n";
	cout << "4-Починить конкретные трубы\n";
	int i = getint("Введите вариант редактирования", 1, 4);
	switch (i)
	{
	case 1:
	{
		for (int i = 0; i < Truboprovod.size(); i++)
		{
			if (Truboprovod[i].sostoyanie == false)
			{
				Truboprovod[i].editTruba();
			}
		}
		
		break;
	}
	case 2:
	{
		unsigned int countt = getint("Введите количество труб", (size_t)1u, Truboprovod.size());
		while (countt--)
		{
			unsigned int n = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
			if (Truboprovod[n-1].sostoyanie == false)
			{
				Truboprovod[n-1].editTruba();
			}
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < Truboprovod.size(); i++)
		{
			if (Truboprovod[i].sostoyanie == true)
			{
				Truboprovod[i].editTruba();
			}
		}
		break;
	}
	case 4:
	{
		unsigned int countt = getint("Введите количество труб", (size_t)1u, Truboprovod.size());
		while (countt--)
		{
			unsigned int n = getint("Введите номер трубы", (size_t)1u, Truboprovod.size());
			if (Truboprovod[n-1].sostoyanie == true)
			{
				Truboprovod[n-1].editTruba();
			}
		}
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуйте ещё раз.\n";
	}
	}
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
	cout << "8-Найти трубу\n";
	cout << "9-Найти компрессорную станцию\n";
	cout << "10-Удалить трубу\n";
	cout << "11-Удалить компрессорную станцию\n";
	cout << "0-Выход\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	map <int, Truba> Truboprovod;
	map <int, KS> Zavod;
	int keytruba = 0;
	int keyks = 0;
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
			Truboprovod[keytruba] = t;
			keytruba += 1;
			break;
		}
		case 2:
		{
			KS ks;
			cin >> ks;
			Zavod[keyks]=ks;
			keyks += 1;
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
						cout << infotruba.second;
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
						cout << infoKS.second;
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
				changeTrubaSostoyanie(Truboprovod);
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
					fout << Truba::IDt<< endl;
					fout << KS::IDks<< endl;
					if (Truboprovod.size() > 0)
					{
						for (auto& infotruba : Truboprovod)
						{
							infotruba.second.savefileTruba(fout);
						}
					}
					if (Zavod.size() > 0)
					{
						for (auto& infoKS : Zavod)
						{
							infoKS.second.savefileKS(fout);
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
				fin >> Truba::IDt;
				fin >> KS::IDks;
				
				if (countt>0)
				{
					for (int i=0;i<countt;i++)
					{
						Truba infotruba;
						infotruba.inputfileTruba(fin);
						Truboprovod[i]=infotruba;
					}
				}
				if (countks>0)
				{
					for (int i = 0; i < countks; i++)
					{
						KS infoKS;
						infoKS.inputfileKS(fin);
						Zavod[i]=infoKS;
					}
				}
				fin.close();
			}
			break;
		}
		case 8:
		{
			map<int,Truba> infotruba;
			bool f=selectFilterTruba(Truboprovod, infotruba);
			if (f)
			{
				for (auto& i : infotruba)
					cout << i.second ;
			}
			else
				cout << "Таких труб нет\n";
			break;
		}
	    case 9:
		{
			map<int,KS> infoks;
			bool f=selectFilterKS(Zavod, infoks);
			if (f)
			{
				for (auto& i : infoks)
					cout << i.second ;
			}
			else
				cout << "Таких компрессорных станций нет\n";
			break;
		}
		case 10:
		{
			deleteTruba(Truboprovod);
			break;
		}
		case 11:
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