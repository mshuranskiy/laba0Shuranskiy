#include "Truba.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

unsigned int Truba::IDt = 0;

Truba Truba::creatTruba()//�������� �����
{
	Truba t;
	t.id = ++Truba::IDt;
	cout << "������� ��� �����\n";
	cin.get();
	getline(cin, t.name);
	t.dlina = getint("������� ����� ����� (������� ���������: �)", 1.0, 10000.0);
	t.diametr = getint("������� ������� �����(������� ��������� : ��)", 1, 10000);
	t.sostoyanie = false;
	return t;
}

void printTruba(const Truba& t)//����� ���������� � �����
{
	cout << "������ � �����:\n";
	cout << "��� �����: " << t.name << endl;
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
	fout << t.name << endl;
	fout << t.dlina << endl;
	fout << t.diametr << endl;
	fout << t.sostoyanie << endl;
}

Truba Truba::inputfileTruba(std::ifstream& fin)//���������� ���������� � �����
{
	Truba t;
	fin >> t.id;
	fin >> t.name;
	fin >> t.dlina;
	fin >> t.diametr;
	fin >> t.sostoyanie;
	return t;
}

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