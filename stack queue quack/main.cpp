#include <iostream>

using namespace std;

template<typename T>
class lnode
{
public:
	lnode* next = nullptr;
	lnode* prev = nullptr;
	T value;
	lnode(T v) { value = v; }
};

template<typename T>
class llist
{
public:
	llist() {}
	lnode<T>* first = nullptr;
	lnode<T>* last = nullptr;
	void push_back(T v)
	{
		lnode<T>* l = new lnode(v);
		if (last == nullptr)
		{
			first = l;
			last = l;
		}
		else
		{
			l->prev = last;
			last->next = l;
			last = l;
		}
	}
	void push_front(T v)
	{
		lnode<T>* l = new lnode(v);
		if (first == nullptr)
		{
			first = l;
			last = l;
		}
		else
		{
			l->next = first;
			first->prev = l;
			first = l;
		}
	}
	T pop_back()
	{
		if (last == nullptr)
			throw "attempting to pop nonexistent value!";
		else if (last == first)
		{
			T v = first->value;
			first = nullptr;
			last = nullptr;
			return v;
		}
		else
		{
			T v = last->value;
			last = last->prev;
			delete last->next;
			last->next = nullptr;
			return v;

		}
	}
	T pop_front()
	{
		if (first == nullptr)
			throw "attempting to pop nonexistent value!";
		else if (first == last)
		{
			T v = first->value;
			first = nullptr;
			last = nullptr;
			return v;
		}
		else
		{
			T v = first->value;
			first = first->next;
			delete first->prev;
			first->prev = nullptr;
			return v;

		}
	}
};

template<typename T>
class stck
{
private:
	llist<T> list;
public:
	stck() {}
	void push(T v)
	{
		list.push_back(v);
	}
	T pop()
	{
		return list.pop_back();
	}
};

template<typename T>
class quue
{
private:
	llist<T> list;
public:
	quue() {}
	void push(T v)
	{
		list.push_back(v);
	}
	T pop()
	{
		return list.pop_front();
	}
};

int main()
{
	stck<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << stack.pop() << stack.pop() << stack.pop() << endl;
	quue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	cout << queue.pop() << queue.pop() << queue.pop() << endl;
	llist<int> quack;
	quack.push_back(1);
	quack.push_front(2);
	quack.push_back(3);
	quack.push_front(4);
	quack.push_back(5);
	quack.push_front(6);
	cout << quack.pop_back() << quack.pop_front() << quack.pop_back() << quack.pop_front() << quack.pop_back() << quack.pop_front() << endl;
	quack.push_front(1);
	quack.push_front(2);
	quack.push_front(3);
	cout << quack.pop_front() << quack.pop_front() << quack.pop_front() << endl;
	quack.push_back(1);
	quack.push_back(2);
	quack.push_back(3);
	cout << quack.pop_back() << quack.pop_back() << quack.pop_back() << endl;
	quack.push_front(1);
	quack.push_front(2);
	quack.push_front(3);
	cout << quack.pop_back() << quack.pop_back() << quack.pop_back() << endl;
	quack.push_back(1);
	quack.push_back(2);
	quack.push_back(3);
	cout << quack.pop_front() << quack.pop_front() << quack.pop_front() << endl;
}