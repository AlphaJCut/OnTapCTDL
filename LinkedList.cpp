#include <iostream>
using namespace std;
//Khoi tao cau truc
struct Node
{
	int info;
	Node* next;
};
struct SinglyLinkedList
{
	Node* head;
};
void init(SinglyLinkedList& list) {
	list.head =nullptr;
}
//Cac thao tac
Node* CreateNode(int value) {
	Node* newNode = new Node;
	newNode->info = value;
	newNode->next = nullptr;
	return newNode;
}
void InsertFirst(SinglyLinkedList& list, int value) 
{
	Node* newNode = CreateNode(value);
	newNode->next = list.head;
	list.head = newNode;
}
void Display(SinglyLinkedList list) {
	Node* temp = list.head;
	while (temp!= nullptr) {
		cout << temp->info << "->";
		temp = temp->next;
	}
	cout << endl;
}
void InsertLast(SinglyLinkedList& list, int value)
{
	Node* newNode = CreateNode(value);
	if(list.head==nullptr)
	{
		list.head = newNode;
	}
	else {
		Node* temp = list.head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
void InsertAfter(SinglyLinkedList& list, int key, int value) {
	Node* temp = list.head;
	while (temp != nullptr && temp->info != key) {
		temp = temp->next;
	}
	if (temp != nullptr) {
		Node* newNode = CreateNode(value);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}
void DeleteFirst(SinglyLinkedList& list) {
	if (list.head != nullptr) {
		Node* temp = list.head;
		list.head = list.head->next;
		delete temp;
	}
}
void DeleteLast(SinglyLinkedList& list) {
	if (list.head == nullptr) {
		return;
	}
	if (list.head->next == nullptr) {
		delete list.head;
		list.head = nullptr;
		return;
	}
	Node* temp = list.head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
}
void DeleteNode(SinglyLinkedList& list, int value) {
	if (list.head == nullptr) {
		return;
	}
	if (list.head->info == value) {
		DeleteFirst(list);
		return;
	}
	Node* temp = list.head;
	while (temp->next != nullptr && temp->next->info != value) {
		temp = temp->next;
	}
	if (temp->next != nullptr) {
		Node* nodeDelete = temp->next;
		temp->next = temp->next->next;
		delete nodeDelete;
	}
}
int main() {
	SinglyLinkedList list;
	init(list);
	InsertFirst(list,20);
	InsertFirst(list, 500);
	InsertLast(list,30);
	Display(list);
	InsertAfter(list, 500, 80);
	Display(list);
	DeleteNode(list, 20);
	Display(list);
	system("pause");
	return 0;
}