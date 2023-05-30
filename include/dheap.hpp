﻿#pragma once
#include <vector>
#include <algorithm>
#include <cmath>
#include <ostream>

template <int d, class T>
class DHeap
{
private:
	std::vector<T> tData;                        // Данные
	int tsize;                                   // Количество элементов на данный момент

	int minChild(int);                           // Поиск минимального ребенка
	void shiftUp(int);                           // "Всплытие"
	void shiftDown(int);                         // "Погружение"

public:
	DHeap();                                     // Конструктор по умолчанию  
	DHeap(const T&);                             // Конструктор инициализации корня
	void insert(const T&);                       // Вставка
	T* getMin();                                 // Получить значение корня
	void extractMin();                           // Извлечение корня
	int size() const { return tsize; }           // Получить количество элементов
	bool isEmpty() const { return tsize == 0; }  // Проверка на пустоту

	friend std::istream& operator >>(std::istream& istr, DHeap& dheap)
	{
		T buffer;

		while (istr >> buffer)
		{
			dheap.insert(buffer);
		}

		return istr;
	}

	friend std::ostream& operator <<(std::ostream& ostr, const DHeap& dheap)
	{
		for (int i = 0; i < dheap.tsize; i++)
			ostr << dheap.tData[i] << " ";

		return ostr;
	}

};

template <int d, class T>
int DHeap<d, T>::minChild(int ind)
{
	int child = d * ind + 1;
	if (child >= tsize) return 0;
	int min = child;

	for (int i = child; i < std::min(tsize, child + d); i++)
	{
		if (tData[min] > tData[i])
			min = i;
	}

	return min;
}

template <int d, class T>
void DHeap<d, T>::shiftUp(int ind)
{
	int parent = (ind - 1) % d;

	while (ind != 0 && tData[ind] < tData[parent])
	{
		std::swap(tData[ind], tData[parent]);
		ind = parent;
		parent = (ind - 1) % d;
	}
}

template <int d, class T>
void DHeap<d, T>::shiftDown(int ind)
{
	int child = minChild(ind);

	while (child != 0 && tData[ind] > tData[child])
	{
		std::swap(tData[ind], tData[child]);
		ind = child;
		child = minChild(ind);
	}
}

template <int d, class T>
DHeap<d, T>::DHeap() : tsize(0)
{
	if (d < 1) throw std::logic_error("DHeap can't be ");
}

template <int d, class T>
DHeap<d, T>::DHeap(const T& var) : tsize(1)
{
	if (d < 1) throw std::logic_error("DHeap can't be ");
	tData.push_back(var);
}

template <int d, class T>
void DHeap<d, T>::insert(const T& var)
{
	tData.push_back(var);
	shiftUp(tsize);
	tsize++;
}

template <int d, class T>
T* DHeap<d, T>::getMin()
{
	if (isEmpty()) return nullptr;
	return &tData[0];
}

template <int d, class T>
void DHeap<d, T>::extractMin()
{
	if (!isEmpty())
	{
		std::swap(tData[0], tData[--tsize]);
		shiftDown(0);
	}
}