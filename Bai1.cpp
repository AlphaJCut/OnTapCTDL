#include <iostream>
using namespace std;

// Khai bao cau truc cho Node va danh sach lien ket don
struct Node {
    int data;
    Node* next;
};

struct SinglyLinkedList {
    Node* head;
};

// Khoi tao danh sach rong
void init(SinglyLinkedList& list) {
    list.head = nullptr;
}

// Tao mot nut moi
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Them phan tu vao cuoi danh sach
void insertLast(SinglyLinkedList& list, int value) {
    Node* newNode = createNode(value);
    if (list.head == nullptr) {
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

// Them phan tu vao dau danh sach
void insertFirst(SinglyLinkedList& list, int value) {
    Node* newNode = createNode(value);
    newNode->next = list.head;
    list.head = newNode;
}

// Ham xuat cac gia tri trong danh sach
void display(SinglyLinkedList list) {
    Node* temp = list.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Sap xep danh sach tang dan
void sortAscending(SinglyLinkedList& list) {
    if (list.head == nullptr || list.head->next == nullptr)
        return;

    Node* current = list.head;
    Node* index = nullptr;
    int temp;

    while (current != nullptr) {
        index = current->next;
        while (index != nullptr) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

// Sap xep danh sach giam dan
void sortDescending(SinglyLinkedList& list) {
    if (list.head == nullptr || list.head->next == nullptr)
        return;

    Node* current = list.head;
    Node* index = nullptr;
    int temp;

    while (current != nullptr) {
        index = current->next;
        while (index != nullptr) {
            if (current->data < index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

// Ham nhap so luong va day so nguyen vao danh sach
void input(SinglyLinkedList& list, int n) {
    int value;
    for (int i = 0; i < n; i++) {
        cout << "Nhap so nguyen thu " << i + 1 << ": ";
        cin >> value;
        insertLast(list, value);
    }
}

// Ham main voi menu lua chon
int main() {
    SinglyLinkedList list;
    init(list);
    int choice, n, value;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Nhap danh sach\n";
        cout << "2. Xuat danh sach\n";
        cout << "3. Them phan tu vao cuoi danh sach\n";
        cout << "4. Them phan tu vao dau danh sach\n";
        cout << "5. Sap xep tang dan\n";
        cout << "6. Sap xep giam dan\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap so luong phan tu: ";
            cin >> n;
            input(list, n);
            break;
        case 2:
            cout << "Danh sach hien tai: ";
            display(list);
            break;
        case 3:
            cout << "Nhap gia tri de them vao cuoi danh sach: ";
            cin >> value;
            insertLast(list, value);
            break;
        case 4:
            cout << "Nhap gia tri de them vao dau danh sach: ";
            cin >> value;
            insertFirst(list, value);
            break;
        case 5:
            sortAscending(list);
            cout << "Danh sach sau khi sap xep tang dan: ";
            display(list);
            break;
        case 6:
            sortDescending(list);
            cout << "Danh sach sau khi sap xep giam dan: ";
            display(list);
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}
