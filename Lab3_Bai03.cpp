#include <iostream>
using namespace std;

// Dinh nghia cau truc Node
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Dinh nghia cau truc Queue
struct Queue {
    Node* top;
    Node* rear;
    int size;
    const int MAX = 100;

    // Constructor
    Queue() : top(nullptr), rear(nullptr), size(0) {}
};

// Ham kiem tra queue rong
bool IsEmpty(Queue& q) {
    return q.top == nullptr;
}

// Ham kiem tra queue day
bool IsFull(Queue& q) {
    return q.size >= q.MAX;
}

// Ham them phan tu vao queue
bool AddQueue(Queue& q, int data) {
    if (IsFull(q)) {
        cout << "Queue hien tai da day." << endl;
        return false;
    }

    Node* NewNode = new Node(data);
    if (IsEmpty(q)) {
        q.top = q.rear = NewNode;
    }
    else {
        q.rear->next = NewNode;
        q.rear = NewNode;
    }
    ++q.size;
    return true;
}

// Ham xoa phan tu khoi queue
int RemoveQueue(Queue& q) {
    if (IsEmpty(q)) {
        cout << "Queue hien tai dang rong." << endl;
        return -1; // Gia tri gia dinh khi queue rong
    }

    Node* temp = q.top;
    int value = temp->data;

    q.top = q.top->next;
    if (q.top == nullptr) {
        q.rear = nullptr;
    }

    delete temp;
    --q.size;

    return value;
}

// Ham hien thi tat ca cac phan tu trong queue
void DisplayQueue(Queue& q) {
    if (IsEmpty(q)) {
        cout << "Queue hien tai dang rong." << endl;
        return;
    }

    Node* current = q.top;
    cout << "Cac phan tu trong queue: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Ham hien thi menu
void menu(Queue& q) {
    int choice;
    do {
        cout << "\nMenu: \n";
        cout << "1. Them phan tu vao queue\n";
        cout << "2. Xoa phan tu khoi queue\n";
        cout << "3. Hien thi tat ca cac phan tu trong queue\n";
        cout << "4. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Nhap phan tu can them: ";
            cin >> data;
            if (AddQueue(q, data)) {
                cout << "Phan tu " << data << " da duoc them vao queue." << endl;
            }
            break;
        }
        case 2: {
            int removedValue = RemoveQueue(q);
            if (removedValue != -1) {
                cout << "Phan tu " << removedValue << " da duoc xoa khoi queue." << endl;
            }
            break;
        }
        case 3: {
            DisplayQueue(q);
            break;
        }
        case 4: {
            cout << "Thoat chuong trinh." << endl;
            return;
        }
        default: {
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
        }
    } while (true);
}

// Ham chinh
int main() {
    Queue q;
    menu(q);
    return 0;
}
