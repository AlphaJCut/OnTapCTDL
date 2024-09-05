#include <iostream>
using namespace std;

// Khai bao Node
struct Node {
    int data;
    Node* next;
};

// Khai bao Stack
struct Stack {
    Node* head;
    Stack() : head(nullptr) {}
};

// Kiem tra Stack rong
bool IsEmpty(Stack S) {
    return S.head == nullptr;
}

// Tao Node
Node* CreateNode(int data) {
    Node* p = new Node();
    if (p == nullptr) {
        return nullptr;
    }
    p->data = data;
    p->next = nullptr;
    return p;
}

// Them phan tu vao dau
void Push(Stack& S, int data) {
    Node* ptr = CreateNode(data);
    // Kiem tra
    if (IsEmpty(S)) {
        S.head = ptr;
    }
    else {
        ptr->next = S.head;
        S.head = ptr;
    }
}

// Xoa nut
bool Pop(Stack& S, int& popdata) {
    if (IsEmpty(S)) {
        cout << "Stack hien tai rong." << endl;
        return false;
    }
    Node* temp = S.head;
    popdata = temp->data;
    S.head = S.head->next;
    delete temp;
    return true;
}

// In stack
void PrintStack(const Stack& S) {
    Node* current = S.head;
    while (current != nullptr) {
        cout << current->data << "\t";
        current = current->next;
    }
    cout << endl;
}

// Hien thi phan tu dau tien trong stack
void TopElement(const Stack& S) {
    if (IsEmpty(S)) {
        cout << "Stack hien tai rong." << endl;
    }
    else {
        cout << "Phan tu dau tien trong stack: " << S.head->data << endl;
    }
}

// Ham menu
void menu(Stack& S) {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Hien thi phan tu dau tien trong stack\n";
        cout << "2. Xoa phan tu khoi stack\n";
        cout << "3. Hien thi tat ca phan tu trong stack\n";
        cout << "4. Ket thuc\n";
        cout << "Chon thao tac: ";
        cin >> choice;

        switch (choice) {
        case 1:
            TopElement(S);
            break;
        case 2: {
            int popvalue;
            if (Pop(S, popvalue)) {
                cout << "Phan tu da xoa: " << popvalue << endl;
            }
            break;
        }
        case 3:
            PrintStack(S);
            break;
        case 4:
            cout << "Ket thuc chuong trinh." << endl;
            return;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    } while (true);
}

// Ham chinh
int main() {
    Stack s;
    menu(s);
    return 0;
}
