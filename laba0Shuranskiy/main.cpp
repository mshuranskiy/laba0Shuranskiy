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

void deleteKS(map<int,KS>& Zavod)//�������� ������������� �������
{
	unsigned int index = getint("������� id ������������� �������", 1u, KS::IDks);
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

void editGTS(map<int, Truba>& Truboprovod,set<int>& idks,set<int>& idt)
{
	while (true)
	{
		cout << "1-��������� ������������� �������\n";
		cout << "0-�����\n";
		int i = getint("������� ����� ��������", 0, 1);
		switch (i)
		{
		case 1:
		{
			unsigned int ks = getint("������� id ������ ������������ �������", 0u, KS::IDks);
			idks.insert(ks);
			unsigned int t;
			while (true)
			{
				t = getint("������� id ����� ������� ����� ��������� ������������� �������", 0u, Truba::IDt);
				if (Truboprovod[t].getinputks() == 0 && Truboprovod[t].getoutputks() == 0)
					break;
				else
					cout << "������ ����� ��� �������������\n";
			}
			idt.insert(t);
			Truboprovod[t].setinputks(ks);
			ks = getint("������� id ������ ������������ �������", 0u, KS::IDks);
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
			cout << "������ ������� �� ���������. ���������� ��� ���.\n";
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
	set<int> idtforgts;
	set<int> idksforgts;
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