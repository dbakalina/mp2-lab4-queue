#pragma once
#include<iostream>

template <class T>
class TQueue
{
	int MaxSize;
	int Size;
	int head;
	int tail;
	T* pMem;
public:
	TQueue(int s = 10);                            //Конструктор
	TQueue(const TQueue<T>& m);                   //Конструктор копирования
	~TQueue();                                     //Деструктор
	TQueue<T>& operator = (const TQueue<T>& m);
	bool operator == (const TQueue<T>& m) const;
	bool operator != (const TQueue<T>& m) const;
	int GetSize() { return Size; }            
	int GetMaxSize() { return MaxSize; }
	bool Full() const;
	bool Empty() const;
	void Push(const T elem);
	T GetHead();
	T SeeHead() const;
	T GetNumberHead() { return head; }
};

template<class T>
TQueue<T>::TQueue(int s)
{
	if (s <= 0)
		throw s;
	MaxSize = s;
	Size = 0;
	head = 0;
	tail = MaxSize - 1;
	pMem = new T[MaxSize];
	for (int i = 0; i < s; i++)
		pMem[i] = 0;
}

/**************************************************************/

template <class T>
TQueue<T>::TQueue(const TQueue<T>& m)
{
	MaxSize = m.MaxSize;
	pMem = new T[MaxSize];
	Size = m.Size;
	head = m.head;
	tail = m.tail;
	int tmp = head;
	int tmp_size = 0;
	while (tmp_size != Size)
	{
		pMem[tmp] = m.pMem[tmp];
		tmp = (tmp + 1) % MaxSize;
		tmp_size++;
	}
}

/**************************************************************/

template <class T>
TQueue<T>::~TQueue()
{
	delete[]pMem;
}

/**************************************************************/

template <class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T>& m)
{
	if (this != &m)
	{
		if (MaxSize != m.MaxSize)
		{
			MaxSize = m.MaxSize;
			delete[]pMem;
			pMem = new T[MaxSize];
		}
		Size = m.Size;
		head = m.head;
		tail = m.tail;
		int tmp = head;
		int tmp_size = 0;
		while (tmp_size != Size)
		{
			pMem[tmp] = m.pMem[tmp];
			tmp = (tmp + 1) % MaxSize;
			tmp_size++;
		}
	}
	return (*this);
}

/**************************************************************/

template<class T>
bool TQueue<T>::operator==(const TQueue<T>& m) const
{
	if (this != &m)
	{
		if (MaxSize != m.MaxSize || Size != m.Size)
		{
			return false;
		}
		int tmp = head;
		int qtmp = m.head;
		int tmp_size = 0;
		while (tmp_size != Size)
		{
			if (pMem[tmp] != m.pMem[qtmp])
			{
				return false;
			}
			tmp = (tmp + 1) % MaxSize;
			qtmp = (qtmp + 1) % MaxSize;
			tmp_size++;
		}
	}
	return true;
}

/**************************************************************/

template<class T>
bool TQueue<T>::operator!=(const TQueue<T>& m) const
{
	return (!(*this == m));
}

/**************************************************************/

template<class T>
bool TQueue<T>::Empty() const
{
	if (Size == 0)
	{
		return true;
	}
	return false;
}

/**************************************************************/

template<class T>
bool TQueue<T>::Full() const
{
	if (Size == MaxSize)
	{
		return true;
	}
	return false;
}

/**************************************************************/

template <class T>
void TQueue<T>::Push(const T elem)
{
	if (Size == MaxSize)
	{
		throw Size;
	}
	Size++;
	tail = (tail + 1) % MaxSize;
	pMem[tail] = elem;
}

/**************************************************************/

template<class T>
T TQueue<T>::SeeHead() const
{
	if (Size == 0)
	{
		throw Size;
	}
	return pMem[head];
}

/**************************************************************/

template<class T>
T TQueue<T>::GetHead()
{
	if (Size == 0)
	{
		throw Size;
	}
	Size--;
	head = (head + 1) % MaxSize;
	if (head == 0)
	{
		return pMem[MaxSize - 1];
	}
	return pMem[head - 1];
}
