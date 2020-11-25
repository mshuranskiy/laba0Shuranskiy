#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Truba.h";
#include "KS.h";
#include "utils.h";

using namespace std;
//unsigned int Truba::IDt;

Truba& selectTruba(map<int,Truba>& Truboprovod)//�������� ������ �����
{
	unsigned int index = getint("������� ����� �����", (size_t)1u, Truboprovod.size());
	return Truboprovod[index - 1];
}

void deleteTruba(map<int,Truba>& Truboprovod)//�������� �����
{
	unsigned int index = getint("������� ����� �����", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(index - 1);
}

bool SearchTrubaByName(Truba& t, std::string parametr)//����� �� �����
{
	return t.getname() == parametr;
}

bool SearchTrubaBySostoyanie(Truba& t, bool parametr)//����� �� ����������
{
	return t.getsostoyanie() == parametr;
}

KS& selectKS(map<int,KS>& Zavod)//����� ������������� �������
{
	unsigned int index = getint("������� ����� ������������� �������", (size_t)1u, Zavod.size());
	return Zavod[index - 1];
}

void deleteKS(map<int,KS>& Zavod)//�������� ������������� �������
{
	unsigned int index = getint("������� ����� ������������� �������", (size_t)1u, Zavod.size());
	Zavod.erase(index - 1);
}

bool SearchKSByName(KS& ks, std::string parametr)//����� �� �����
{
	return ks.getname() == parametr;
}

bool SearchKSByNnowork(KS& ks, double parametr)//����� �� �������� �� ���������� �����
{
	return (1.0-((double)ks.getninwork() / ks.getn()) >= parametr/100.0);
}

set<int> selectFilterTruba(map<int,Truba>& Truboprovod)
{
	set<int> idt;
	cout << "�������:\n";
	cout << "1-�� �����\n";
	cout << "2-�� ��������� � �������\n";
	int i = getint("������� ����� �������", 1, 2);
	switch (i)
	{
	case 1:
	{
		bool f=false;
		cout << "������� ��� �����\n";
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
		cout << "����� ���� ����������� � �������\n";
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
		cout << "������ ������� �� ���������. ���������� ��� ���.\n";
	}
	}
}

set<int> selectFilterKS(map<int,KS>& Zavod)
{
	set<int> idks;
	cout << "�������:\n";
	cout << "1-�� �����\n";
	cout << "2-�� �������� ���������������� �����\n";
	int i = getint("������� ����� �������", 1, 2);
	switch (i)
	{
	case 1:
	{
		bool f = false;
		cout << "������� ��� ������������� �������\n";
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
		double procent = getint("������� ������� ����������������� �����", 1, 100);
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
		cout << "������ ������� �� ���������. ���������� ��� ���.\n";
	}
	}
}

void changeTrubaSostoyanie(map<int,Truba>& Truboprovod)
{
	cout << "�������� ��������������:\n";
	cout << "1-��������� ��� ����� � ������\n";
	cout << "2-��������� ���������� ����� � ������\n";
	cout << "3-�������� ��� �����\n";
	cout << "4-�������� ���������� �����\n";
	int i = getint("������� ������� ��������������", 1, 4);
	switch (i)
	{
	case 1:
	{
		for (int i = 0; i < Truboprovod.size(); i++)
		{
			if (Truboprovod[i].getsostoyanie() == false)
			{
				Truboprovod[i].editTruba();
			}
		}
		
		break;
	}
	case 2:
	{
		while (true)
		{
			unsigned int n = getint("������� ����� ����� ��� ���� �� ������ ����� ������� '0'", (size_t)0, Truboprovod.size());
			if (n == 0)
				break;
			else
			{
				if (Truboprovod[n - 1].getsostoyanie() == false)
				{
					Truboprovod[n - 1].editTruba();
				}
				else
					cout << "����� ��� � �������";
			}
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < Truboprovod.size(); i++)
		{
			if (Truboprovod[i].getsostoyanie() == true)
			{
				Truboprovod[i].editTruba();
			}
		}
		break;
	}
	case 4:
	{
		while (true)
		{
			unsigned int n = getint("������� ����� ����� ��� ���� �� ������ ����� ������� '0'", (size_t)0, Truboprovod.size());
			if (n == 0)
				break;
			else
			{
				if (Truboprovod[n - 1].getsostoyanie() == true)
				{
					Truboprovod[n - 1].editTruba();
				}
				else
					cout << "����� ��� �� � �������";
			}
		}
		break;
	}
	default:
	{
		cout << "������ ������� �� ���������. ���������� ��� ���.\n";
	}
	}
}

void printmenu()
{
	cout << "1-�������� �����\n";
	cout << "2-�������� ������������� �������\n";
	cout << "3-������� ������ �� �����\n";
	cout << "4-������������� ��������� �����\n";
	cout << "5-������������� ����������� ����� � ������ ������������� �������\n";
	cout << "6-��������� ������ ����\n";
	cout << "7-������� ������ �� �����\n";
	cout << "8-����� �����\n";
	cout << "9-����� ������������� �������\n";
	cout << "10-������� �����\n";
	cout << "11-������� ������������� �������\n";
	cout << "0-�����\n";
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
		i=getint("������� ����� ��������",0,10000);
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
					cout << "����� �� �������.\n";
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
					cout << "������������� ������� �� �������.\n";
				}
				break;

			}
			else 
			{
				cout << "����� ��� ������������� ������� �� �������. ���������� ��� ���.\n";
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
				cout << "����� �� �������. ���������� ��� ���.\n";
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
				cout << "������������� ������� �� �������. ���������� ��� ���.\n";
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
				cout << "����� ��� ������������� ������� �� �������. ���������� ��� ���.\n";
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
			set<int>idt=selectFilterTruba(Truboprovod);
			bool f = true;
			for (auto& i : idt)
			{
				f = false;
				cout << Truboprovod[i];
			}
			if(f)
				cout << "����� ���� ���\n";
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
				cout << "����� ������������� ������� ���\n";
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
			cout << "������ ������� �� ���������. ���������� ��� ���.";
		}
		}
	}
}