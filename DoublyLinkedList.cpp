#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* prev;
};
struct DoublyLinkedList {
	Node* head;
	Node* tail;
};
void init(DoublyLinkedList& list) {
	list.head = list.tail = nullptr;
	
}
//Cac thao tac
Node* CreateNode(int value) {
	Node* newNode = new Node();
	newNode->prev = nullptr;
	newNode->data = value;
	newNode->next = nullptr;
	return newNode;
}
void InsertFirst(DoublyLinkedList& list, int value) {
	Node* newNode = CreateNode(value);
	if (list.head == nullptr) {
		list.head= list.tail  = newNode;
	}
	else {
		newNode->next = list.head;
		list.head->prev = newNode;
		list.head = newNode;
	}
}
void InsertLast(DoublyLinkedList& list, int value) {
	Node* newNode = CreateNode(value);
	if (list.tail == nullptr) {
		list.head = list.tail = nullptr;
	}
	else {
		newNode->prev = list.tail;
		list.tail->next = newNode;
		list.tail = newNode;
	}
}
void InsertAfter(DoublyLinkedList& list, int key, int value) {
	Node* temp = list.head;
	while (temp != nullptr && temp->data != key) {
		temp = temp->next;
	}
	if (temp == nullptr) {
		cout << "Khong co gia tri do trong danh sach. ";
		return;
	}
	Node* newNode = CreateNode(value);
	newNode->next = temp->next;
	newNode->prev = temp;
	if (temp->next != nullptr) {
		temp->next->prev = newNode;
	}
	else {
		list.tail = newNode;
	}
	temp->next = newNode;
}
//Hien thi//
void DisplayForward(DoublyLinkedList& list) {
	Node* temp = list.head;
	if (list.head == nullptr) {
		cout << "Danh sach khong co phan tu.";
		return;
	}
	while (temp != nullptr) {
		cout << temp->data << "<->";
		temp = temp->next;
	}
	cout << endl;
}
void DisplayBackWard(DoublyLinkedList& list) {
	Node* temp = list.tail;
	if (list.tail == nullptr) {
		cout << "Danh sach khong co phan tu.";
		return;
	}
	while (temp!= nullptr) {
		cout << temp->data << "<->";
		temp = temp->next;
	}
	cout << endl;
}
//Xoa
void DeleteNode(DoublyLinkedList& list,int value) {
	Node* temp = list.head;
	while (temp != nullptr && temp->data != value) {
		temp = temp->next;
	}
	if (temp == nullptr) {
		cout << "Khong co node de ban xoa. ";
		return;
	}
	//Xoa dau
	if (temp->prev != nullptr) {
		temp->prev->next = temp->next;
	}
	else {
		list.head = temp->next;
	}
	//Xoa cuoi
	if (temp->next != nullptr) {
		temp->next->prev = temp->prev;
	}
	else {
		list.tail = temp->prev;
	}
	delete temp;
}
int main() {
	DoublyLinkedList list;
	init(list);
	InsertFirst(list, 10);
	InsertFirst(list, 40);
	InsertFirst(list, 30);
	InsertFirst(list, 90);
	DisplayForward(list);
	InsertAfter(list, 90, 25);
	DisplayForward(list);
	system("pause");
	return 0;
}