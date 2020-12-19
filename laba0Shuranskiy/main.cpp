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
#include "GTS.h";

using namespace std;

Truba& selectTruba(map<int,Truba>& Truboprovod)//�������� ������ �����
{
	unsigned int index = getint("������� id �����", 1u, Truba::IDt);
	return Truboprovod[index];
}

void deleteTruba(map<int,Truba>& Truboprovod)//�������� �����
{
	unsigned int index = getint("������� id �����", 1u, Truba::IDt);
	Truboprovod.erase(index);
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
	unsigned int index = getint("������� id ������������� �������", 1u, KS::IDks);
	return Zavod[index];
}

void deleteKS(map<int,KS>& Zavod,GTS& gts,map<int,Truba>& Truboprovod)//�������� ������������� �������
{
	unsigned int index = getint("������� id ������������� �������", 1u, KS::IDks);
	gts.deleteidks(index);
	for (auto& n : Truboprovod)
	{
		if(n.second.getinputks()==index)
			n.second.setinputks(0);
		if (n.second.getoutputks() == index)
			n.second.setoutputks(0);
	}
	Zavod.erase(index);
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
			unsigned int n = getint("������� id ����� ��� ���� �� ������ ����� ������� '0'", 0u, Truba::IDt);
			if (n == 0)
				break;
			else
			{
				if (Truboprovod[n].getsostoyanie() == false)
				{
					Truboprovod[n].editTruba();
				}
				else
					cout << "����� ��� � �������";
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
			unsigned int n = getint("������� id ����� ��� ���� �� ������ ����� ������� '0'", 0u, Truba::IDt);
			if (n == 0)
				break;
			else
			{
				if (Truboprovod[n].getsostoyanie() == true)
				{
					Truboprovod[n].editTruba();
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
	cout << "12-���������� � ������ ���������������� ����\n";
	cout << "13-��������� �������������� ����������\n";
	cout << "0-�����\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	map <int, Truba> Truboprovod;
	map <int, KS> Zavod;
	GTS gts;
	vector<unsigned int> sortedmatrix;
	while (true)
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
			}
			else
			{
				cout << "����� ��� ������������� ������� �� �������. ���������� ��� ���.\n";
			}
			if (gts.getidks().size() > 0 || gts.getidt().size() > 0)
			{
				ofstream fout;
				fout.open("GTS.txt", ios::out);
				if (fout.is_open())
				{
					fout << gts.getidt().size() <<endl;
					fout << gts.getidks().size() << endl;
					gts.savefilegts(fout);
					fout.close();
				}
				break;
			}
			else
			{
				cout << "���������������� ���� �� �������\n";
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
						int n = gts.inputfilegts(fin2);
						gts.setidt(n);
					}
				}
				if (countidks > 0)
				{
					for (int i = 0; i < countidks; i++)
					{
						int n = gts.inputfilegts(fin2);
						gts.setidks(n);
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
			deleteKS(Zavod,gts,Truboprovod);
			break;
		}
		case 12:
		{
			gts.editGTS(Truboprovod);
			break;
		}
		case 13:
		{
			sortedmatrix = gts.tgtssort(Truboprovod);
			if (sortedmatrix.size() > 0)
			{
				int k=1;
				for (auto& i : sortedmatrix)
				{
					cout <<"������� �"<<k<<"-->id="<<i << endl;
					k += 1;
				}
			}
			else
				cout << "� ����� ������������ ���� �������������� ���������� ����������\n";
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