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
	cout << "������� ����� �����\n";
	cin >> t.dlina;
	cout << "������� ������� �����\n";
	cin >> t.diametr;
	t.sostoyanie = false;
	return t;
}
KS creatKS()//�������� ������������� �������
{
	KS ks;
	cout << "������� ��� ������������� �������\n";
	cin >> ks.name;
	cout << "������� ���������� �����\n";
	cin >> ks.n;
	cout << "������� ���������� ����� � ������\n";
	cin >> ks.ninwork;
	cout << "������� ������������� ������������� ��������\n";
	cin >> ks.efect;
	return ks;
}
void printTruba(Truba t)//����� ���������� � �����
{
	cout << "������ � �����:\n";
	cout << "����� �����: " << t.dlina<< endl;
	cout << "������� �����: " << t.diametr << endl;
	cout << "��������� �����: " << (t.sostoyanie ? "� �������\n" : "�� � �������\n");
}
void printKS(KS ks)//����� ���������� � ������������� �������
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
	cout << "������� ���������� ����� � ������\n";
	int i;
	cin >> i;
	ks.ninwork = i;

}
void savefileTruba(Truba t)//���������� ���������� � �����
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
void savefileKS(KS ks)//���������� ���������� � ������������� �������
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
int main()
{
	setlocale(LC_ALL, "Russian");
	KS infoks = creatKS();
	editKS(infoks);
	printKS(infoks);
	savefileKS(infoks);
	/*Truba infoTruba=inputfileTruba();
	editTruba(infoTruba);
	printTruba(infoTruba);
	savefileTruba(infoTruba);*/
}