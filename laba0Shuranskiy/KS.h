#pragma once
#include <string>
#include <vector>
class KS
{
	static unsigned int IDks;
	std::string name;//���
	unsigned int id;//�������������
	int n;//���������� �����
	int ninwork;//���������� ����� � ������
	int efect;//�������������
public:
	static KS creatKS();//�������� ������������� �������
	friend void printKS(const KS& ks);//����� ���������� � ������������� �������
	friend void editKS(KS& ks);//��������� ������ � ������
	friend void savefileKS(std::ofstream& fout, const KS& ks);//���������� ���������� � ������������� �������
	static KS inputfileKS(std::ifstream& fin);//���������� ���������� � ������������� �������
	friend KS& selectKS(vector<KS>& Zavod);//����� ������������� �������
	friend void deleteKS(vector<KS>& Zavod);//�������� ������������� �������
	friend bool SearchKSByName(const KS& ks, std::string parametr);//����� �� �����
	friend bool SearchKSByNinwork(const KS& ks, double parametr);//����� �� �������� �� ���������� �����
};

