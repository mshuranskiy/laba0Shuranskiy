#include <iostream>
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
	cout << "����� ����� " << t.dlina<< endl;
	cout << "������� ����� " << t.diametr << endl;
	cout << "��������� ����� " << (t.sostoyanie ? "� �������\n" : "�� � �������\n");
}
void printKS(KS ks)//����� ���������� � ������������� �������
{
	cout << "������ � ������������� �������:\n";
	cout << "��� ������������� ������� " << ks.name;
	cout << "���������� ����� �� ������������� ������� " << ks.n;
	cout << "���������� ����� � ������ " << ks.ninwork;
	cout << "������������� ������������� ������� " << ks.efect;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Truba infoTruba=creatTruba();
	printTruba(infoTruba);
}