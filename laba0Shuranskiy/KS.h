#pragma once
#include <string>
class KS
{
	static unsigned int IDks;
	std::string name;//���
	unsigned int id;//�������������
	int n;//���������� �����
	int ninwork;//���������� ����� � ������
	int efect;//�������������
public:
	friend KS creatKS();//�������� ������������� �������
	friend void printKS(const KS& ks);//����� ���������� � ������������� �������
	friend void editKS(KS& ks);//��������� ������ � ������
	friend void savefileKS(std::ofstream& fout, const KS& ks);//���������� ���������� � ������������� �������
	friend KS inputfileKS(std::ifstream& fin);//���������� ���������� � ������������� �������
};

