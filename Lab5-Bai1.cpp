#include <iostream>
using namespace std;

void init(long*& a, int n) {
	a = new long[n];
}

void freeArr(long*& a) {
	delete[] a;
	a = nullptr;
}

void inputArrOld(long*& a, int& n) {
	do {
		cout << "Nhap so luong phan tu: "; cin >> n;
		if (n <= 0)
			cout << "Nhap lai so phan tu!\n";
	} while (n <= 0);
	init(a, n);
	if (a != nullptr) {
		for (int i = 0; i < n; i++) {
			cout << "a[" << i << "] = ";
			cin >> a[i];
		}
	}
}

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
int main() {
	//Bubble//
	long a[] = { 3, 5, 9, 7, 3, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Mang truoc khi sap xep la: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	BubbleSort(a, n);
	cout << "Mang sau khi sap xep dung Bubble Sort: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	//InterchangeSort//
	long b[] = { 2, 5, 9, 7, 8, 20 };
	int m = sizeof(b) / sizeof(b[0]);
	cout << "Mang truoc khi sap xep la: ";
	for (int i = 0; i < m; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	InterchangeSort(b, m);
	cout << "Mang sau khi sap xep dung InterchangeSort: ";
	for (int i = 0; i < m; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	//InsertionSort//
	long c[] = { 30, 25, 9, 7, 3, 20 };
	int o = sizeof(c) / sizeof(c[0]);
	cout << "Mang truoc khi sap xep la: ";
	for (int i = 0; i < o; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	InsertionSort(c, o);
	cout << "Mang sau khi sap xep dung Insertion Sort: ";
	for (int i = 0; i < o; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	//SelectionSort//
	long d[] = { 90, 5, 9, 7, 3, 1 };
	int p = sizeof(d) / sizeof(d[0]);
	cout << "Mang truoc khi sap xep la: ";
	for (int i = 0; i < p; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	selectionSort(d, p);
	cout << "Mang sau khi sap xep dung SelectionSort: ";
	for (int i = 0; i < p; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	//Quick//
	long e[] = { 90, 5, 99, 10, 3, 1 };
	int q = sizeof(e) / sizeof(e[0]);
	cout << "Mang truoc khi sap xep la: ";
	for (int i = 0; i < q; i++) {
		cout << e[i] << " ";
	}
	cout << endl;
	quickSort(e, 0,q-1);
	cout << "Mang sau khi sap xep dung QuickSort: ";
	for (int i = 0; i < q; i++) {
		cout << e[i] << " ";
	}
	cout << endl;
	//HeapSort//
	long f[] = { 90, 5, 9, 7, 3, 80 };
	int r = sizeof(f) / sizeof(f[0]);
	cout << "Mang truoc khi sap xep la: ";
	for (int i = 0; i < r; i++) {
		cout << f[i] << " ";
	}
	cout << endl;
	heapSort(f, r);
	cout << "Mang sau khi sap xep dung HeapSort: ";
	for (int i = 0; i < r; i++) {
		cout << f[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}