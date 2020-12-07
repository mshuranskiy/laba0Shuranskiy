#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "Truba.h";
#include "KS.h";
#include "utils.h";

using namespace std;

Truba& selectTruba(map<int,Truba>& Truboprovod)//Выбираем нужную трубу
{
	unsigned int index = getint("Введите id трубы", 1u, Truba::IDt);
	return Truboprovod[index];
}

void deleteTruba(map<int,Truba>& Truboprovod)//Удаление трубы
{
	unsigned int index = getint("Введите id трубы", 1u, Truba::IDt);
	Truboprovod.erase(index);
}

bool SearchTrubaByName(Truba& t, std::string parametr)//Поиск по имени
{
	return t.getname() == parametr;
}

bool SearchTrubaBySostoyanie(Truba& t, bool parametr)//Поиск по стостоянию
{
	return t.getsostoyanie() == parametr;
}

KS& selectKS(map<int,KS>& Zavod)//Выбор компрессорной станции
{
	unsigned int index = getint("Введите id компрессорной станции", 1u, KS::IDks);
	return Zavod[index];
}

void deleteKS(map<int,KS>& Zavod)//Удаление компрессорной станции
{
	unsigned int index = getint("Введите id компрессорной станции", 1u, KS::IDks);
	Zavod.erase(index);
}

bool SearchKSByName(KS& ks, std::string parametr)//Поиск по имени
{
	return ks.getname() == parametr;
}

bool SearchKSByNnowork(KS& ks, double parametr)//Поиск по проценту не работающих цехов
{
	return (1.0-((double)ks.getninwork() / ks.getn()) >= parametr/100.0);
}

set<int> selectFilterTruba(map<int,Truba>& Truboprovod)
{
	set<int> idt;
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
			idt.insert(i);
			f = true;
		}
		return idt;
		break;
	}
	case 2:
	{
		bool f=false;
		cout << "Поиск труб находящихся в ремонте\n";
		for (auto& i : SearchTrubaByFilter(Truboprovod, SearchTrubaBySostoyanie, true))
		{
			idt.insert(i);
			f = true;
		}
		return idt;
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуйте ещё раз.\n";
	}
	}
}

set<int> selectFilterKS(map<int,KS>& Zavod)
{
	set<int> idks;
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
			idks.insert(i);
			f = true;
		}
		return idks;
		break;
	}
	case 2:
	{
		bool f = false;
		double procent = getint("Введите процент незадействованных цехов", 1, 100);
		for (auto& i : SearchKSByFilter(Zavod, SearchKSByNnowork, procent))
		{
			idks.insert(i);
			f = true;	
		}
		return idks;
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
		for (auto& t:Truboprovod)
		{
			if (Truboprovod[t.second.getid()].getsostoyanie() == false)
			{
				Truboprovod[t.second.getid()].editTruba();
			}
		}
		
		break;
	}
	case 2:
	{
		while (true)
		{
			unsigned int n = getint("Введите id трубы или если вы хотите выйти нажмите '0'", 0u, Truba::IDt);
			if (n == 0)
				break;
			else
			{
				if (Truboprovod[n].getsostoyanie() == false)
				{
					Truboprovod[n].editTruba();
				}
				else
					cout << "Труба уже в ремонте";
			}
		}
		break;
	}
	case 3:
	{
		for (auto& t:Truboprovod)
		{
			if (Truboprovod[t.second.getid()].getsostoyanie() == true)
			{
				Truboprovod[t.second.getid()].editTruba();
			}
		}
		break;
	}
	case 4:
	{
		while (true)
		{
			unsigned int n = getint("Введите id трубы или если вы хотите выйти нажмите '0'", 0u, Truba::IDt);
			if (n == 0)
				break;
			else
			{
				if (Truboprovod[n].getsostoyanie() == true)
				{
					Truboprovod[n].editTruba();
				}
				else
					cout << "Труба уже не в ремонте";
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

void editGTS(map<int, Truba>& Truboprovod,set<int>& idks,set<int>& idt)
{
	while (true)
	{
		cout << "1-Соединить компрессорные станции\n";
		cout << "0-Выход\n";
		int i = getint("Введите номер действия", 0, 1);
		switch (i)
		{
		case 1:
		{
			unsigned int ks = getint("Введите id первой копрессорной станции", 0u, KS::IDks);
			idks.insert(ks);
			unsigned int t;
			while (true)
			{
				t = getint("Введите id трубы которая будет соединять компрессорный станции", 0u, Truba::IDt);
				if (Truboprovod[t].getinputks() == 0 && Truboprovod[t].getoutputks() == 0)
					break;
				else
					cout << "Данная труба уже задействована\n";
			}
			idt.insert(t);
			Truboprovod[t].setinputks(ks);
			ks = getint("Введите id второй копрессорной станции", 0u, KS::IDks);
			idks.insert(ks);
			Truboprovod[t].setoutputks(ks);
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "Данные введены не корректно. Попробуйте ещё раз.\n";
		}
		}
	}
}

void savefilegts(ofstream& fout,set<int>& nabor)
{
	for (auto& n : nabor)
	{
		fout << n << endl;
	}
}

int inputfilegts(ifstream& fin)
{
	unsigned int n;
	fin >> n;
	return n;
}

int** creatematrix(int n)
{
	int** matrix = new int* [n]();
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n]();
	}
	return matrix;
}

void deletematrix(int** matrix,int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void editmatrix(int** matrix, map<int, Truba>& Truboprovod, set<int>& idks)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : Truboprovod)
	{
		int first=-1;
		int second = -1;
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getinputks() == sortedidks[i])
				first = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getoutputks() == sortedidks[i])
				second = i;
		}
		if(first>-1 && second>-1)
			matrix[first][second] = 1;
	}
}

vector<unsigned int> tgtssort(map<int,Truba>& Truboprovod,set<int>& idks,set<int>& idt)
{
	vector<unsigned int> sorted;
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	int n = idks.size();
	int** smmatrix=creatematrix(n);
	editmatrix(smmatrix, Truboprovod, idks);
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += smmatrix[i][j];
			}
			if (sum == 0)
			{
				sorted.push_back(vks[i]);
				for (int j = 0; j < n; j++)
				{
					smmatrix[j][i] = 0;
				}
				smmatrix[i][i] = 1;
			}
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << smmatrix[i][j];
		}
		cout << endl;
	}*/
	deletematrix(smmatrix,n);	
	reverse(sorted.begin(), sorted.end());
	return sorted;
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
	cout << "12-Соединение в единую газотранспортную сеть\n";
	cout << "13-Выполнить топологическую сортировку\n";
	cout << "0-Выход\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	map <int, Truba> Truboprovod;
	map <int, KS> Zavod;
	set<int> idtforgts;
	set<int> idksforgts;
	vector<unsigned int> sortedmatrix;
	while (true)
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
			Truboprovod[t.getid()] = t;
			break;
		}
		case 2:
		{
			KS ks;
			cin >> ks;
			Zavod[ks.getid()]=ks;
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
			}
			else
			{
				cout << "Труба или Компрессорная станция не создана. Попробуйте ещё раз.\n";
			}
			if (idtforgts.size() > 0 || idksforgts.size() > 0)
			{
				ofstream fout;
				fout.open("GTS.txt", ios::out);
				if (fout.is_open())
				{
					fout << idtforgts.size()<<endl;
					fout << idksforgts.size() << endl;
					if (idtforgts.size() > 0)
					{
						savefilegts(fout, idtforgts);
					}
					if (idksforgts.size() > 0)
					{
						savefilegts(fout, idksforgts);
					}
					fout.close();
				}
				break;
			}
			else
			{
				cout << "Газотранспортная сеть не создана\n";
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
						Truboprovod[infotruba.getid()]=infotruba;
					}
				}
				if (countks>0)
				{
					for (int i = 0; i < countks; i++)
					{
						KS infoKS;
						infoKS.inputfileKS(fin);
						Zavod[infoKS.getid()]=infoKS;
					}
				}
				fin.close();
			}
			ifstream fin2;
			fin2.open("GTS.txt", ios::in);
			if (fin2.is_open())
			{
				int countidt;
				int countidks;
				fin2 >> countidt;
				fin2 >> countidks;
				if (countidt > 0)
				{
					for (int i = 0; i < countidt; i++)
					{
						int n = inputfilegts(fin2);
						idtforgts.insert(n);
					}
				}
				if (countidks > 0)
				{
					for (int i = 0; i < countidks; i++)
					{
						int n = inputfilegts(fin2);
						idksforgts.insert(n);
					}
				}
				fin2.close();
			}
			break;
		}
		case 8:
		{
			set<int>idt=selectFilterTruba(Truboprovod);
			bool f = true;
			for (auto& i : idt)
			{
				f = false;
				cout << Truboprovod[i];
			}
			if(f)
				cout << "Таких труб нет\n";
			break;
		}
	    case 9:
		{
			set<int> idks=selectFilterKS(Zavod);
			bool f = true;
			for (auto& i : idks)
			{
				f = false;
				cout << Zavod[i];
			}
			if(f)
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
		case 12:
		{
			editGTS(Truboprovod, idksforgts, idtforgts);
			break;
		}
		case 13:
		{
			sortedmatrix = tgtssort(Truboprovod, idksforgts, idtforgts);
			if (sortedmatrix.size() > 0)
			{
				int k=1;
				for (auto& i : sortedmatrix)
				{
					cout <<"Вершина №"<<k<<"-->id="<<i << endl;
					k += 1;
				}
			}
			else
				cout << "В графе присутствует цикл топологическая сортировка невозможна\n";
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