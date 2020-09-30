#include <iostream>
#include <fstream>
using namespace std;
struct Truba//�����
{
	string id;//�������������
	float dlina;//�����
	int diametr;//�������
	bool sostoyanie;//��������� � ������� ��� ���

};
struct KS//������������� �������
{
	string name;//���
	string id;//�������������
	int n;//���������� �����
	int ninwork;//���������� ����� � ������
	int efect;//�������������
};
Truba creatTruba()//�������� �����
{
	Truba t;
	bool f=0;
	while (f == 0)
	{
		cout << "������� ����� ����� (������� ���������: �)\n";
		cin >> t.dlina;
		if (cin.fail() || t.dlina <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� ������ �� ���������. ���������� ��� ���.\n";
		}
		else
		{
			f = 1;
		}
	}
	f = 0;
	while (f == 0)
	{
		cout << "������� ������� ����� (������� ���������: ��)\n";
		cin >> t.diametr;
		if (cin.fail() || t.diametr <= 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� ������ �� ���������. ���������� ��� ���.\n";
		}
		else
		{
			f = 1;
		}
	}
	t.sostoyanie = false;
	return t;
}
KS creatKS()//�������� ������������� �������
{
	KS ks;
	bool  f = 0;
	cout << "������� ��� ������������� �������\n";
	cin >> ks.name;
	while (f == 0)
	{
		cout << "������� ���������� �����\n";
		cin >> ks.n;
		if (cin.fail() || ks.n<=0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� ������ �� ���������. ���������� ��� ���.\n";
		}
		else
		{
			f = 1;
		}
	}
	f = 0;
	while (f == 0)
	{
		cout << "������� ���������� ����� � ������\n";
		cin >> ks.ninwork;
		if (cin.fail() || ks.ninwork < 0 || ks.ninwork>ks.n)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� ������ �� ���������. ���������� ��� ���.\n";
		}
		else
		{
			f = 1;
		}
	}
	f = 0;
	while (f == 0)
	{
		cout << "������� ������������� ������������� �������� (������������� ���������� �� 10-�� ������� �����)\n";
		cin >> ks.efect;
		if (cin.fail() || ks.efect < 0)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� ������ �� ���������. ���������� ��� ���.\n";
		}
		else
		{
			f = 1;
		}
	}
	return ks;
}
void printTruba(const Truba &t)//����� ���������� � �����
{
	cout << "������ � �����:\n";
	cout << "����� �����: " << t.dlina<<" (�)"<< endl;
	cout << "������� �����: " << t.diametr << " (��)" << endl;
	cout << "��������� �����: " << (t.sostoyanie ? "� �������\n" : "�� � �������\n");
}
void printKS(const KS &ks)//����� ���������� � ������������� �������
{
	cout << "������ � ������������� �������:\n";
	cout << "��� ������������� �������: " << ks.name << endl;
	cout << "���������� ����� �� ������������� �������: " << ks.n << endl;
	cout << "���������� ����� � ������: " << ks.ninwork << endl;
	cout << "������������� ������������� �������: " << ks.efect << endl;
}
void editTruba(Truba &t)//��������� ����� � ������
{
	t.sostoyanie = !t.sostoyanie;
}
void editKS(KS &ks)//��������� ������ � ������
{
	bool f = 0;
	while (f == 0)
	{
		cout << "������� ���������� ����� � ������\n";
		cin >> ks.ninwork;
		if (cin.fail() || ks.ninwork < 0 || ks.ninwork > ks.n)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� ������ �� ���������. ���������� ��� ���.\n";
		}
		else
		{
			f = 1;
		}
	}
}
void savefileTruba(const Truba &t)//���������� ���������� � �����
{
	ofstream fout;
	fout.open("info.txt", ios::out);
	if (fout.is_open())
	{
		fout << t.dlina << endl;
		fout << t.diametr << endl;
		fout << t.sostoyanie << endl;
		fout.close();
	}
}
Truba inputfileTruba()//���������� ���������� � �����
{
	Truba t;
	ifstream fin;
	fin.open("info.txt", ios::in);
	if (fin.is_open())
	{
		fin >> t.dlina;
		fin >> t.diametr;
		fin >> t.sostoyanie;
		fin.close();
	}
	return t;
}
void savefileKS(const KS &ks)//���������� ���������� � ������������� �������
{
	ofstream fout;
	fout.open("info.txt", ios::out);
	if (fout.is_open())
	{
		fout << ks.name<<endl;
		fout  << ks.n << endl;
		fout  << ks.ninwork << endl;
		fout << ks.efect << endl;
		fout.close();
	}
}
KS inputfileKS()//���������� ���������� � ������������� �������
{
	KS ks;
	ifstream fin;
	fin.open("info.txt", ios::in);
	if (fin.is_open())
	{
		fin>> ks.name;
		fin >> ks.n;
		fin >> ks.ninwork;
		fin >> ks.efect;
		fin.close();
	}
	return ks;
}
void printmenu()
{
	cout << "1-�������� �����\n";
	cout << "2-�������� ������������� �������\n";
	cout << "3-������� ���������� � �����\n";
	cout << "4-������� ���������� � ������������� �������\n";
	cout << "5-������������� ��������� �����\n";
	cout << "6-������������� ����������� ����� � ������ ������������� �������\n";
	cout << "7-��������� ������ � ����� � ����\n";
	cout << "8-��������� ������ � ������������� ������� � ����\n";
	cout << "9-������� ������ � ����� �� �����\n";
	cout << "10-������� ������ � ������������� ������� �� �����\n";
	cout << "0-�����\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	KS infoks;
	Truba infotruba;
	bool ft = 0;
	bool fks = 0;
	while (1)
	{
		printmenu();
		cout << "������� ����� ��������\n";
		int i;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			infotruba=creatTruba();
			ft = 1;
			break;
		}
		case 2:
		{
			infoks=creatKS();
			fks = 1;
			break;
		}
		case 3:
		{
			if (ft == 1)
			{
			printTruba(infotruba);
			break; 
			}
			else
			{
				cout << "����� �� �������. ���������� ��� ���.\n";
				break;
			}
		}
		case 4:
		{
			if (fks == 1)
			{
				printKS(infoks);
				break;
			}
			else
			{
				cout << "������������� ������� �� �������. ���������� ��� ���.\n";
				break;
			}
		}
		case 5:
		{
			if (ft == 1)
			{
				editTruba(infotruba);
				break;
			}
			else
			{
				cout << "����� �� �������. ���������� ��� ���.\n";
				break;
			}
		}
		case 6:
		{
			if (fks == 1)
			{
				editKS(infoks);
				break;
			}
			else
			{
				cout << "������������� ������� �� �������. ���������� ��� ���.\n";
				break;
			}
		}
		case 7:
		{
			if (ft == 1)
			{
				savefileTruba(infotruba);
				break;
			}
			else
			{
				cout << "����� �� �������. ���������� ��� ���.\n";
				break;
			}
		}
		case 8:
		{
			if (fks == 1)
			{
				savefileKS(infoks);
				break;
			}
			else
			{
				cout << "������������� ������� �� �������. ���������� ��� ���.\n";
				break;
			}
		}
		case 9:
		{
			infotruba=inputfileTruba();
			ft = 1;
			break;
		}
		case 10:
		{
			infoks=inputfileKS();
			fks = 1;
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "������ ������� �� ���������. ���������� ��� ���.";
		}
		}
	}
	/*
	KS infoks = creatKS();
	editKS(infoks);
	printKS(infoks);
	savefileKS(infoks);
	Truba infoTruba=creatTruba();
	editTruba(infoTruba);
	printTruba(infoTruba);
	savefileTruba(infoTruba);*/
}