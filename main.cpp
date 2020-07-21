#include <iostream>
using namespace std;

class Node {
public:
	int get_name() { return name; }
	Node* get_next() { return next; }
	Node* get_upgo() { return upgo; }
	void set_name(int s) { name = s; }
	void set_next(Node* n) { next = n; }
	void set_upgo(Node* n) { upgo = n; }
private:
	int name;
	Node* next{ nullptr };
	Node* upgo{ nullptr };
};
class List {
public:
	List() :head{ new Node }, end{ new Node }{}
	bool plus_head(int s);
	bool plus_end(int s);
	bool delete_head();
	bool delete_end();
	Node* get_head() { return head; }
	Node* get_end() { return end; }
	bool insert(int i, int s);
	Node* sort(List &list);
	void show();
	void bing();
	auto size() { return n; }
private:
	Node* head, * end;
	int n = 0;
};

Node *List::sort(List &list) {
	Node* p = { head->get_next() };
	Node* p1 = { list.get_head() };
	p1 = p1->get_next();
	while (p1) {
		plus_end(p1->get_name());
		p1 = p1->get_next();
	}
	for (int i = 0; i <= n; i++) {
		for (int j = n; j >= 0; j--) {
			if (!p->get_next())
				break;
			if (p->get_name() >= p->get_next()->get_name()) {
				int temp = p->get_name();
				p->set_name(p->get_next()->get_name());
				p->get_next()->set_name(temp);
				
			}
			p = p->get_next();
		}
		p = head->get_next();
	}
	return p;
}

void List::bing() {
	Node* p{ head };
	end->set_upgo(p->get_upgo());
	end->set_upgo(p->get_next());
}

bool List::delete_head() {
	if (!head->get_next())
		return false;
	Node* p = { head->get_next() };
	head->set_next(p->get_next());
	delete p;
	n--;
	return true;
}

bool List::delete_end() {
	if (!end)
		return false;
	Node* p = end;
	delete p;
	n--;
}

bool List::plus_end(int s) {
	Node* p{ head };
	if (!p)
		return false;
	while (p->get_next())
		p = p->get_next();
	Node* q = new Node;
	q->set_name(s);
	p->set_next(q);
	end = p->get_next();
	n++;
}

bool List::plus_head(int s) {
	Node* p = new Node;
	if (!p)
		return false;
	p->set_name(s);
	p->set_next(get_head()->get_next());
	get_head()->set_next(p);
	n++;
}

bool List::insert(int i, int s) {
	if (i<0 || i>n)
		return false;
	int j{ 0 };
	Node* p{ head };
	while (p && j < i) {
		p = p->get_next();
		j++;
	}
	Node* q = new Node;
	if (!q)
		return false;
	q->set_name(s);
	q->set_next(p->get_next());
	p->set_next(q);
	n++;
	return true;
}

void List::show() {
	Node* p{ head };
	for (auto i = 0; i < size(); i++) {
		p = p->get_next();
		cout << p->get_name() << endl;
	}
}
int main()
{
	List a,b;
	a.plus_end(1);
	a.plus_end(2);
	a.plus_end(4);
	b.plus_end(1);
	b.plus_end(3);
	b.plus_end(4);
	a.sort(b);
	a.show();
	while (true);
	return 0;
}