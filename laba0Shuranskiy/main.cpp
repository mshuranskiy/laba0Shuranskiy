#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Truba.h";
#include "KS.h";
#include "utils.h";

using namespace std;

Truba& selectTruba(vector<Truba>& Truboprovod)//�������� ������ �����
{
	unsigned int index = getint("������� ����� �����", (size_t)1u, Truboprovod.size());
	return Truboprovod[index - 1];
}

void deleteTruba(vector<Truba>& Truboprovod)//�������� �����
{
	unsigned int index = getint("������� ����� �����", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(Truboprovod.begin() + index - 1);
}

bool SearchTrubaByName(const Truba& t, std::string parametr)//����� �� �����
{
	return t.name == parametr;
}

bool SearchTrubaBySostoyanie(const Truba& t, bool parametr)//����� �� ����������
{
	return t.sostoyanie == parametr;
}

KS& selectKS(vector<KS>& Zavod)//����� ������������� �������
{
	unsigned int index = getint("������� ����� ������������� �������", (size_t)1u, Zavod.size());
	return Zavod[index - 1];
}

void deleteKS(vector<KS>& Zavod)//�������� ������������� �������
{
	unsigned int index = getint("������� ����� �����", (size_t)1u, Zavod.size());
	Zavod.erase(Zavod.begin() + index - 1);
}

bool SearchKSByName(const KS& ks, std::string parametr)//����� �� �����
{
	return ks.name == parametr;
}

bool SearchKSByNnowork(const KS& ks, double parametr)//����� �� �������� �� ���������� �����
{
	return (1.0-((double)ks.ninwork / ks.n) >= parametr/100.0);
}

void selectFilterTruba(const vector<Truba>& Truboprovod, int i)
{
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
			cout << Truboprovod[i];
			f = true;
		}
		if (!f)
		{
			cout << "��� ���� � ����� ������\n";
		}
		break;
	}
	case 2:
	{
		bool f=false;
		cout << "����� ���� ����������� � �������\n";
		for (auto& i : SearchTrubaByFilter(Truboprovod, SearchTrubaBySostoyanie, false))
		{
			cout << Truboprovod[i];
			f = true;
		}
		if (!f)
		{
			cout << "��� ���� � �������\n";
		}
		break;
	}
	default:
	{
		cout << "������ ������� �� ���������. ���������� ��� ���.\n";
	}
	}
}

void selectFilterKS(const vector<KS>& Zavod, int i)
{
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
			cout << Zavod[i];
			f = true;
		}
		if (!f)
		{
			cout << "��� ������������� ������� � ����� ������\n";
		}
		break;
	}
	case 2:
	{
		bool f = false;
		double procent = getint("������� ������� ����������������� �����", 1, 100);
		for (auto& i : SearchKSByFilter(Zavod, SearchKSByNnowork, procent))
		{
			cout << Zavod[i];
			f = true;
		}
		if (!f)
		{
			cout << "��� ������������� ������� � ������ ��������� ���������������� �����\n";
		}
		break;
	}
	default:
	{
		cout << "������ ������� �� ���������. ���������� ��� ���.\n";
	}
	}
}

void changeTrubaSostoyanie(vector<Truba>& Truboprovod, int i)
{
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
		unsigned int countt = getint("������� ���������� ����", (size_t)1u, Truboprovod.size());
		while (countt--)
		{
			unsigned int n = getint("������� ����� �����", (size_t)1u, Truboprovod.size());
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
		unsigned int countt = getint("������� ���������� ����", (size_t)1u, Truboprovod.size());
		while (countt--)
		{
			unsigned int n = getint("������� ����� �����", (size_t)1u, Truboprovod.size());
			if (Truboprovod[n-1].sostoyanie == true)
			{
				Truboprovod[n-1].editTruba();
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
	vector <Truba> Truboprovod;
	vector <KS> Zavod;
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
					cout << "����� �� �������.\n";
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
				cout << "�������� ��������������:\n";
				cout << "1-��������� ��� ����� � ������\n";
				cout << "2-��������� ���������� ����� � ������\n";
				cout << "3-�������� ��� �����\n";
				cout << "4-�������� ���������� �����\n";
				int i = getint("������� ������� ��������������", 1, 4);
				changeTrubaSostoyanie(Truboprovod, i);
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
			cout << "�������:\n";
			cout << "1-�� �����\n";
			cout << "2-�� ��������� � �������\n";
			i = getint("������� ����� �������", 1, 2);
			selectFilterTruba(Truboprovod, i);
			break;
		}
	    case 9:
		{
			cout << "�������:\n";
			cout << "1-�� �����\n";
			cout << "2-�� �������� ���������������� �����\n";
			i = getint("������� ����� �������", 1, 2);
			selectFilterKS(Zavod, i);
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