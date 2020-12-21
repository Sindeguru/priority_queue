#include <iostream>
#include <queue.h>
//#include <queue>

using namespace std;

int main()
{
  TQueuePriority<int> Q1;
  TQueuePriority<int> Q2 = Q1;

  Q1.Push(15, 7);
  Q1.Push(18, 9);
  Q1.Push(18, 9);
  Q1.Push(1, 3);
  Q1.Push(8, 6);
  Q1.Push(11, 6);
  Q1.Push(4, 6);
  Q1.Print("Q1");

  cout << Q1.Pop()/* << ' ' << Q1.Pop() << ' ' << Q1.Pop() << ' ' << Q1.Pop()*/ << ' ' << endl;
  Q1.Print("Q1");
  
  TQueuePriority<int> Q3 = Q1; // конструктор копирования
  Q3.Print("Q3");

	return 0;
}