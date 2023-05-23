#include"list.h"

// Lop List
List::List() {
	Head = NULL;
	count = 0;
}
List::~List() {
	while (Head != NULL) {
		Node* temp = Head;
		Head = Head->next;
		delete temp;
	}
}

Node* List::makeNode(const string& val) {
	Node* p = new Node;
	p->data = val;
	p->next = NULL;
	return p;
}

void List::insert(int pos, const string& val) {
	if (pos<0 || pos>count) {
		cout << "Vi tri them khong hop le!" << endl;
		return;
	}
	Node* node = makeNode(val);
	if (pos == 0) {
		node->next = Head;
		Head = node;
	}
	else {
		Node* temp = Head;
		for (int i = 0; i < pos - 1; i++) {
			temp = temp->next;
		}
		node->next = temp->next;
		temp->next = node;
	}
	count++;
}

void List::erase(int pos) {
	if (pos < 0 || pos >= count) {
		cout << "Vi tri xoa khong hop le!" << endl;
		return;
	}
	Node* temp = NULL;
	if (pos == 0) {
		temp = Head;
		Head = Head->next;
	}
	else {
		Node* prev = Head;
		for (int i = 0; i < pos - 1; i++) {
			prev = prev->next;
		}
		temp = prev->next;
		prev->next = temp->next;
	}
	delete temp;
	count--;
}

string List::get(int pos) const {
	if (pos<0 || pos>count) {
		cout << "Vi tri lay khong hop le!" << endl;
		return"";
	}
	Node* temp = Head;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	return temp->data;
}

void List::print() const {
	Node* temp = Head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int List::size() const {
	return count;
}
