#include "Truba.h"
#include "utils.h"
#include <iostream>
#include <fstream>

unsigned int Truba::IDt = 0;

Truba creatTruba()//�������� �����
{
	Truba t;
	t.id = ++Truba::IDt;
	t.dlina = getint("������� ����� ����� (������� ���������: �)", 1.0, 10000.0);
	t.diametr = getint("������� ������� �����(������� ��������� : ��)", 1, 10000);
	t.sostoyanie = false;
	return t;
}

void printTruba(const Truba& t)//����� ���������� � �����
{
	cout << "������ � �����:\n";
	cout << "����� �����: " << t.dlina << " (�)" << endl;
	cout << "������� �����: " << t.diametr << " (��)" << endl;
	cout << "��������� �����: " << (t.sostoyanie ? "� �������\n" : "�� � �������\n");
}

void editTruba(Truba& t)//��������� ����� � ������
{
	t.sostoyanie = !t.sostoyanie;
}

void savefileTruba(std::ofstream& fout, const Truba& t)//���������� ���������� � �����
{
	fout << t.id << endl;
	fout << t.dlina << endl;
	fout << t.diametr << endl;
	fout << t.sostoyanie << endl;
}

Truba inputfileTruba(ifstream& fin)//���������� ���������� � �����
{
	Truba t;
	fin >> t.id;
	fin >> t.dlina;
	fin >> t.diametr;
	fin >> t.sostoyanie;
	return t;
}