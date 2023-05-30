#pragma once
#include "dheap.hpp"
#include "binomialheap.hpp"
#include "tree.hpp"

enum { DHEAP = 1, BHEAP, TREE};

template<class T>
class PriorityQueue
{
private:
	DHeap<2, T> dheap;                           // �������� � �-����
	BinHeap<T> bheap;                            // �������� � ������������ ����
	Tree<T> tree;                                // �������� � ������-������ ������

public:
	PriorityQueue() {}                           // ����������� �� ���������
	~PriorityQueue() {}                          // ����������
	T* getMin(int type_of_storage_structure);    // ��������� ��������� �� ����������� �������
	void insert(const T&);                       // �������
	void extractMin();                           // ������� ��������
	int size(int type_of_storage_structure);     // ������
	bool isEmpty(int type_of_storage_structure); // �������� �� �������
	void show();                                 // ����� �� ����� ���� �������� ��������

};

template<class T>
T* PriorityQueue<T>::getMin(int type_of_storage_structure)
{
	switch (type_of_storage_structure)
	{
	case DHEAP: return dheap.getMin();
	case BHEAP: return &bheap.getMin()->data;
	case TREE: return &tree.getMin()->data;
	default: throw std::runtime_error("Wrong type");
	}
}

template<class T>
void PriorityQueue<T>::insert(const T& var)
{
	dheap.insert(var);
	bheap.insert(var);
	tree.push(var);
}

template<class T>
void PriorityQueue<T>::extractMin()
{
	dheap.extractMin();
	bheap.extractMin();
	tree.extractMin();
}

template<class T>
int PriorityQueue<T>::size(int type_of_storage_structure)
{
	switch (type_of_storage_structure)
	{
	case DHEAP: return dheap.size();
	case BHEAP: return bheap.size();
	case TREE: return tree.size();
	default: throw std::runtime_error("Wrong type");
	}
}

template<class T>
bool PriorityQueue<T>::isEmpty(int type_of_storage_structure)
{
	switch (type_of_storage_structure)
	{
	case DHEAP: return dheap.isEmpty();
	case BHEAP: return bheap.isEmpty();
	case TREE: return tree.isEmpty();
	default: throw std::runtime_error("Wrong type");
	}
}

template<class T>
void PriorityQueue<T>::show()
{
	std::cout << "�������� � 2-����: " << std::endl;
	std::cout << dheap << std::endl;
	std::cout << "�������� � ������������ ����: " << std::endl;
	std::cout << bheap << std::endl;
	std::cout << "�������� � ������-������ ������ (�� ������ ������������ �� �������������): " << std::endl;
	tree.getTree();
}