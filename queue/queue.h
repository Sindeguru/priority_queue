#pragma once
#include <iostream>

using namespace std;

template <typename T>
class TQueuePriority
{
private:
  T* data; 
  int *priority; 
  int count;

public:
  TQueuePriority() { count = 0; }
  TQueuePriority(const TQueuePriority& _Q);
  ~TQueuePriority();


  TQueuePriority operator=(const TQueuePriority& _Q);

  void Push(T item, int priority);

  T Pop();

  void Clear()
  {
    if (count > 0)
    {
      delete[] data;
      delete[] priority;
      count = 0;
    }
  }

  bool IsEmpty();

  int Count(){return count;}
  void Print(const char* objName);
};

template<typename T>
inline TQueuePriority<T>::TQueuePriority(const TQueuePriority& _Q)
{
  count = _Q.count;
  data = new T[_Q.count];
  priority = new int[_Q.count];
  for (int i = 0; i < count; i++)
    data[i] = _Q.data[i];

  for (int i = 0; i < count; i++)
    priority[i] = _Q.priority[i];
}

template<typename T>
inline TQueuePriority<T>::~TQueuePriority()
{
   delete[] data;
   delete[] priority;
   count = 0;
}

template <typename T>
TQueuePriority<T> TQueuePriority<T>::operator=(const TQueuePriority& _Q)
{
  delete[] data;
  delete[] priority;
  count = _Q.count;
  if (!(_Q.IsEmpty()))
  {
    data = new T[_Q.count];
    priority = new int[_Q.count];


    for (int i = 0; i < count; i++)
    {
      data[i] = _Q.data[i];
      priority[i] = _Q.priority[i];
    }
    return *this;
  }
}

template <typename T>
void TQueuePriority<T>::Push(T item, int pr)
{
  T* A2;
  int* P2;

  A2 = (T*)new T[count + 1];
  P2 = (int*)new int[count + 1];

  int pos;

  if (count == 0)
    pos = 0;
  else
  {
    pos = 0;
    while (pos < count)
    {
      if (this->priority[pos] < pr) 
        break;
      pos++;
    }
  }

  for (int i = 0; i < pos; i++)
  {
    A2[i] = data[i];
    P2[i] = this->priority[i];
  }

  A2[pos] = item;
  P2[pos] = pr;

  for (int i = pos + 1; i < count + 1; i++)
  {
    A2[i] = data[i - 1];
    P2[i] = this->priority[i - 1];
  }

  if (count > 0)
  {
    delete[] data;
    delete[] this->priority;
  }

  data = A2;
  this->priority = P2;

  count++;
}

template <typename T>
T TQueuePriority<T>::Pop()
{
  if (IsEmpty())
    throw logic_error("Is empty");

  T* A2;
  int* P2;

  A2 = new T[count - 1];
  P2 = new int[count - 1];

  T item;
  item = data[0];

  for (int i = 0; i < count - 1; i++)
  {
    A2[i] = data[i + 1];
    P2[i] = priority[i + 1];
  }

  delete[] data;
  delete[] priority;

  count--;

  data = A2;
  priority = P2;

  return item;
}

template<typename T>
inline bool TQueuePriority<T>::IsEmpty()
{
  return count == 0;
}

template <typename T>
void TQueuePriority<T>::Print(const char* objName)
{
  cout << "Object: " << objName << endl;
  for (int i = 0; i < count; i++)
    cout << data[i] << ":" << priority[i] << "\t" << endl;
  cout << endl;
  cout << "---------------" << endl;
}


/*
template <class T>
class TQueue
{
protected:
	int size;
	T* arr;
	int start;
	int finish;
	int counter;

public:
	TQueue(int size = 0);
	TQueue(TQueue& q);
	~TQueue();

	void Push(T s);
	T Pop(); //Вывод последнего элемента и его удаление
	bool IsEmpty();
	bool IsFull();
};

template<class T>
inline TQueue<T>::TQueue(int size)
{
	if (size < 0) throw logic_error("size < 0");
	arr = new T[size];
	this->size = size;
	start = 0;
	finish = 0;
	counter = 0;
}

template<class T>
inline TQueue<T>::TQueue(TQueue& q)
{
	this->size = q.size;
	this->arr = new T * [q.size];
	this->counter = q.counter;
	this->start = q.start;
	this->finish = q.finish;

	if (start > finish)
		for (int i = start; i < finish; i++)
			this->arr[i] = q.arr[i];
	else
		for (int i = finish; i < start; i++)
			this->arr[i] = q.arr[i];
}

template<class T>
inline TQueue<T>::~TQueue()
{
	if (arr != 0) delete[] arr;
	start = 0;
	finish = 0;
	counter = 0;
}

template<class T>
inline void TQueue<T>::Push(T s)
{
	if ((start == finish) && (IsFull())) throw logic_error("Full queue");
	arr[finish] = s;
	finish = (finish + 1) % size;
	counter++;
}

template<class T>
inline T TQueue<T>::Pop()
{
	if (IsEmpty()) throw logic_error("Queue is empty");
	T a = arr[start];
	arr[start] = 0;
	start = (start + 1) % size;
	counter--;
	return a;
}

template<class T>
inline bool TQueue<T>::IsEmpty()
{
	return (counter == 0);
}

template<class T>
inline bool TQueue<T>::IsFull()
{
	return (counter >= size);
}

*/