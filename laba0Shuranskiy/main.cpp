#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Truba.h";
#include "KS.h";
#include "utils.h";
using namespace std;
void printmenu()
{
	cout << "1-�������� �����\n";
	cout << "2-�������� ������������� �������\n";
	cout << "3-������� ������\n";
	cout << "4-������������� ��������� �����\n";
	cout << "5-������������� ����������� ����� � ������ ������������� �������\n";
	cout << "6-��������� ������ ����\n";
	cout << "7-������� ������ �� �����\n";
	cout << "8-������� �����\n";
	cout << "9-������� ������������� �������\n";
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
			Truboprovod.push_back(Truba::creatTruba());
			break;
		}
		case 2:
		{
			Zavod.push_back(KS::creatKS());
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
						printTruba(infotruba);
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
						printKS(infoKS);
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
				editTruba(selectTruba(Truboprovod));
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
				editKS(selectKS(Zavod));
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
							savefileTruba(fout, infotruba);
						}
					}
					if (Zavod.size() > 0)
					{
						for (auto& infoKS : Zavod)
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
						infotruba = Truba::inputfileTruba(fin);
						Truboprovod.push_back(infotruba);
					}
				}
				if (countks)
				{
					while (countks--)
					{
						infoKS = KS::inputfileKS(fin);
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
			cout << "������ ������� �� ���������. ���������� ��� ���.";
		}
		}
	}
}