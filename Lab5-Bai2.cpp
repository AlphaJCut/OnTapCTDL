#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Khởi tạo mảng động
void init(long*& a, int n) {
    a = new long[n];
}

// Giải phóng bộ nhớ mảng động
void freeArr(long*& a) {
    delete[] a;
    a = nullptr;
}

// Hàm tạo danh sách ngẫu nhiên
void generateRandomList(long*& a, int& n) {
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    init(a, n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; 
    }
}

// Hàm nhập danh sách
void inputArr(long*& a, int& n) {
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    init(a, n);
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// Hàm xuất danh sách
void outputArr(long* a, int n) {
    if (a != nullptr) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << "\t";
        }
        cout << endl;
    }
}

// Selection Sort
void selectionSort(long a[], int n) {
    int pos;
    for (int i = 0; i < n - 1; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[pos])
                pos = j;
        swap(a[pos], a[i]);
    }
}

// Insertion Sort
void InsertionSort(long a[], int n) {
    long x;
    int j;
    for (int i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

// Bubble Sort
void BubbleSort(long a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(a[j], a[j - 1]);
}

// Interchange Sort
void InterchangeSort(long a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}

// QuickSort
void quickSort(long a[], int left, int right) {
    int l = left, r = right;
    long pivot = a[(left + right) / 2];
    while (l <= r) {
        while (a[l] < pivot)
            l++;
        while (a[r] > pivot)
            r--;
        if (l <= r) {
            swap(a[l], a[r]);
            l++; r--;
        }
    }
    if (left < r)
        quickSort(a, left, r);
    if (l < right)
        quickSort(a, l, right);
}

// Heap Sort
void Heapify(long a[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxPos = i;

    if (l < n && a[l] > a[maxPos])
        maxPos = l;
    if (r < n && a[r] > a[maxPos])
        maxPos = r;

    if (maxPos != i) {
        swap(a[i], a[maxPos]);
        Heapify(a, n, maxPos);
    }
}

void heapSort(long a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, n, i);
    }

    for (int right = n - 1; right > 0; right--) {
        swap(a[0], a[right]);
        Heapify(a, right, 0);
    }
}

// Tim kiem tuan tu
int linearSearch(long a[], int n, long x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

// tim kiem nhi phan
int binarySearch(long a[], int n, long x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Menu chính
void menu() {
    long* a = nullptr;
    int n = 0;
    int choice;
    long x;

    do {
        cout << "\n-------- CHUONG 3 : XEP THU TU VA TIM KIEM\n";
        cout << "1. Tao danh sach ngau nhien\n";
        cout << "2. Nhap danh sach\n";
        cout << "3. Xuat danh sach\n";
        cout << "4. Selection Sort\n";
        cout << "5. Insertion Sort\n";
        cout << "6. Bubble Sort\n";
        cout << "7. Interchange Sort\n";
        cout << "8. Quick Sort\n";
        cout << "9. Heap Sort\n";
        cout << "10. Tim kiem tuan tu\n";
        cout << "11. Tim kiem nhi phan\n";
        cout << "12. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            generateRandomList(a, n);
            break;
        case 2:
            inputArr(a, n);
            break;
        case 3:
            outputArr(a, n);
            break;
        case 4:
            selectionSort(a, n);
            break;
        case 5:
            InsertionSort(a, n);
            break;
        case 6:
            BubbleSort(a, n);
            break;
        case 7:
            InterchangeSort(a, n);
            break;
        case 8:
            quickSort(a, 0, n - 1);
            break;
        case 9:
            heapSort(a, n);
            break;
        case 10:
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            int idx;
            idx = linearSearch(a, n, x);
            if (idx != -1)
                cout << "Tim thay " << x << " tai vi tri " << idx << endl;
            else
                cout << x << " khong ton tai trong danh sach.\n";
            break;
        case 11:
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            idx = binarySearch(a, n, x);
            if (idx != -1)
                cout << "Tim thay " << x << " tai vi tri " << idx << endl;
            else
                cout << x << " khong ton tai trong danh sach.\n";
            break;
        case 12:
            freeArr(a);
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
            break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
