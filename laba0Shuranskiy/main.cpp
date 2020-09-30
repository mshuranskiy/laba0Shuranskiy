#include <iostream>
#include <fstream>
#include <string>
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
int getint(string text, int border1, int border2=10000)
{
	int value;
	while (1)
	{
		cout << text<<endl;
		cin >> value;
		if (cin.fail() || value < border1 || value >border2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� ������ �� ���������. ���������� ��� ���.\n";
		}
		else
		{
			return value;
		}
	}

}
Truba creatTruba()//�������� �����
{
	Truba t;
	while (1)
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
			break;
		}
	}
	t.diametr = getint("������� ������� �����(������� ��������� : ��)",1);
	t.sostoyanie = false;
	return t;
}
KS creatKS()//�������� ������������� �������
{
	KS ks;
	cout << "������� ��� ������������� �������\n";
	cin.get();
	getline(cin,ks.name);
	ks.n = getint("������� ���������� �����", 1);
	ks.ninwork = getint("������� ���������� ����� � ������", 0,ks.n);
	ks.efect = getint("������� ������������� ������������� �������� (������������� ���������� �� 10-�� ������� �����)", 0);
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
		fout << t.id << endl;
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
		fin >> t.id;
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
	fout.open("info.txt", ios::app);
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
		fin >> ks.name;
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
	cout << "7-��������� ������ ����\n";
	cout << "8-������� ������ �� �����\n";
	cout << "0-�����\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	KS infoks;
	Truba infotruba;
	bool ft = false;
	bool fks = false;
	while (1)
	{
		printmenu();
		int i;
		i=getint("������� ����� ��������",0);
		switch (i)
		{
		case 1:
		{
			infotruba=creatTruba();
			ft = true;
			break;
		}
		case 2:
		{
			infoks=creatKS();
			fks = true;
			break;
		}
		case 3:
		{
			if (ft)
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
			if (fks)
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
			if (ft)
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
			if (fks)
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
			if (ft||fks)
			{
				savefileTruba(infotruba);
				savefileKS(infoks);
				break;
			}
			else
			{
				cout << "������������� ������� ��� ����� �� �������. ���������� ��� ���.\n";
				break;
			}
		}
		case 8:
		{
			infotruba=inputfileTruba();
			infoks=inputfileKS();
			ft = true;
			fks = true;
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
}