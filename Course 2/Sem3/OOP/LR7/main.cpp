/*
	Доработать программу лабораторной работы №2:  
	– разработать класс СПИСОК;
	– описать производные классы: СТЕК, ОЧЕРЕДЬ
	  
	Использовать технологии С++:
	– перегрузка конструкторов;
	– Исключения;
	– Статические элементы класса;
	– Списки инициализации.
*/

#include "linkedlist.h"
#include "queue.h"
#include "stack.h"
#include <iostream>

using namespace std;

int menu()
{
	
	cout << endl << endl << "=== список ===" << endl;
	cout << " 1 Доавить в начало" << endl;
	cout << " 2 Доавить в конец" << endl;
	cout << " 3 Вывод списка" << endl;
	cout << " 4 PrintReverse" << endl;
	cout << " 5 Вывести по индексу" << endl;
	cout << " 6 Удалить конечный" << endl;
	cout << " 7 Вывод размер списка" << endl;
	cout << "===  стек  ===" << endl;
	cout << " 8 Доавить в стек (push)" << endl;
	cout << " 9 Получить значение стека" << endl;
	cout << "10 Удалить значение стека (pop)" << endl;
	cout << "=== очередь ===" << endl;
	cout << "12 Добавить в очередь (add)" << endl;
	cout << "13 Получить значение очереди (get)" << endl;
	cout << "14 Удалить значение очереди (del)" << endl;
	cout << "15 Вывод очереди" << endl << "? ";
	cout << "=== 0 Выход ===" << endl;
	int R;
	cin >> R;
	return R;
}

int main()
{
	
	LinkedList mylist;
	Queue myqueue;
	Stack mystack;

	int num = 0;
	int index = 0;
	int req = -1;
	while (req)
	{
		req = menu();
		switch(req)
		{
			//list
			case 1:
				printf("\033c");
				cout << "Введите значение: " << endl;
				cin >> num;
				mylist.appendNode(num);
				break;
			case 2:
				printf("\033c");
				cout << "Введите значение: " << endl;
				cin >> num;
				mylist.insertNode(num, 0);
				break;
			case 3:
				printf("\033c");
				mylist.print();
				break;
			case 4:
			printf("\033c");
				mylist.printReverse();
				break;
			case 5:
			printf("\033c");
				cout << "Введите индекс: " << endl;
				cin >> index; 
				mylist.printOne(index);
				break;
			case 6:
			printf("\033c");
				cout << "Введите индекс удаляемого эллемента: " << endl;
				cin >> index;
				mylist.deleteNode(index);
				break;
			case 7:
			printf("\033c");
				cout << mylist.getSize();
				break;
			//stack
			case 8:
			printf("\033c");
				cout << "Введите значение: " << endl;
				cin >> num;
				mystack.push(num);
				break;
			case 9:
				break;
			case 10:
			printf("\033c");
				mystack.pop();
				break;
			case 11:
			printf("\033c");
				//mystack.print();
				break;
			//queue
			case 12:
			printf("\033c");
				cout << "Введите значение: " << endl;
				cin >> num;
				myqueue.enqueue(num);
				break;
			case 13:
			printf("\033c");
				myqueue.dequeue();
				break;
			case 14:
			printf("\033c");
				break;
			case 15:
			printf("\033c");
				//myqueue.print();
				break;
			
		}
	}
	
	/*
	LinkedList list1;
	LinkedList list2;
	
	list1.appendNode(5);
	list1.appendNode(6);
	list1.appendNode(15);
	list1.insertNode(2, 0);
	
	cout << "Index Operator: " << list1[1] << endl << endl;
	
	cout << "Size: " << list1.getSize() << endl;
	
	cout << endl << "List 1:" << endl;
	list1.print();
	list1.printReverse();
	
	list1.deleteNode(0);
	
	cout << endl << "List 1 (after delete):" << endl;
	list1.print();
	
	list2.appendNode(10);
	list2 = list1;
	list2.appendNode(7);
	
	cout << endl << "List 2:" << endl;
	list2.print();
	*/
	return 0;
}
