#include<iostream>
using namespace std;

//Cau truc tree//
struct Node
{
	int data;
	Node* Left, * Right;

};
//TreeEmpty//
void TreeEmpty(Node*& root)
{
	root = NULL;
}
//Cac thao tac tren cay//
//ADD//
void AddNode(Node*& p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->data = x;
		p->Left = p->Right = NULL;
	}
	else
	{
		if (p->data == x) return;
		else if (p->data > x) AddNode(p->Left, x);
		else AddNode(p->Right, x);
	}
}
//Find//
Node* FindNode(Node* p, int x)
{
	if (p != NULL)
	{
		if (p->data == x)
			return p;
		else
			if (x > p->data)
			{
				return FindNode(p->Right, x);
			}
			else
			{
				return FindNode(p->Left, x);
			}
	}
	return NULL;
}
void SearchStandFor(Node*& p, Node*& q)
{
	if (q->Left == NULL)
	{
		p->data = q->data;
		p = q;
		q = q->Right;
	}
	else
	{
		SearchStandFor(p, q->Left);
	};
}
//Delete//
int DeleteNode(Node*& root, int x)
{
	if (root == NULL) return 0;
	if (root->data == x)
	{
		Node* p = root;
		if (root->Left == NULL)
			root = root->Right;
		else if (root->Right == NULL)
			root = root->Left;
		else
			SearchStandFor(p, root->Right);
		delete p;
		return 1;
	}
	if (root->data < x)return DeleteNode(root->Right, x);
	if (root->data > x)return DeleteNode(root->Left, x);
	return 0;
}
//Cach cac duyet//
//Left Node Right//
void LNR(Node* root)
{
	if (root != NULL)
	{
		LNR(root->Left);
		cout << root->data << " ";
		LNR(root->Right);
	}
}
//Left Right Node//
void LRN(Node* root)
{
	if (root != NULL)
	{
		LRN(root->Left);
		LRN(root->Right);
		cout << root->data << " ";
	}
}
//Node Right Left//
void NLR(Node* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		NLR(root->Left);
		NLR(root->Right);
	}
}
int main()
{
	Node* root;
	TreeEmpty(root);
	AddNode(root, 50);
	AddNode(root, 30);
	AddNode(root, 70);
	AddNode(root, 20);
	AddNode(root, 40);
	AddNode(root, 60);
	AddNode(root, 80);
	int x;
	cout << "Nhap gia tri ban muon tim: ";
	cin >> x;
	cout << " Cay nhi phan in theo LNR: ";
	LNR(root);
	cout << endl;
	cout << "Cay nhi phan in theo LRN: ";
	LRN(root);
	cout << endl;
	cout << "Cay nhi phan in theo NLR: ";
	NLR(root);
	cout << endl;
	Node* foundNode = FindNode(root, x);
	Node* foundNode1;
	if (foundNode != NULL) {
		cout << "Da tim thay node: " << foundNode->data << endl;
	}
	else {
		cout << "Khong tim thay node." << endl;
	}
	if (DeleteNode(root, 30)) {
		cout << "Da xoa node 30." << endl;
	}
	else
	{
		cout << "Khong tim thay node 30." << endl;
	}
	foundNode1 = FindNode(root, 30);
	if (foundNode1 != NULL)
	{
		cout << "Da tim thay node: " << foundNode1->data << endl;
	}
	else
	{
		cout << "Khong tim thay node." << endl;
	}
	LNR(root);
	system("pause");
	return 0;
}