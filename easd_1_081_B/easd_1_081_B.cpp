// 1. Karena sebuah algoritma memberikan efisiensi yang maksimum untuk memecahkan suatu masalah. 
//    Efisiensi sebuah algoritma dapat bertambah jika menggunakan struktur data yang sesuai.
// 2. Statis(contohnya array) dan dinamis(contohnya linked list)
// 3. Faktor-faktor yang mempengaruhi efisiensi:
// •	Kecepatan mesin
// •	Compiler
// •	Sistem operasi
// •	Bahasa pemrograman
// •	Besarnya ukuran input
// 4. Algoritma yang cocok untuk data yang besar adalah quick sort. Quick sort berbasis divide and conquer. 
//    Salah satu algoritma pengurutan data yang paling cepat, yaitu dengan membagi list menggunakan sebuah pivot.
// 5. Algoritma yang berbentuk quadratic adalah bubble sort, insertion sort dan selection sort sedangkan untuk 
//    loglinier adalah quick sort dan merge sort

#include <iostream>
using namespace std;

//membuat array 
int mira[101];
int n;

void input() {
	while (true) {
		cout << "Masukkan element ke dalan array : ";
		cin >> n;

		if (n <= 101)
			break;
		else
			cout << "\nMaksimal element adalah 101" << endl;
	}
	cout << "\n===================" << endl;
	cout << "\nElemen-Elemen Array" << endl;
	cout << "\n===================" << endl;

	for (int i = 0;i < n;i++) {
		cout << i + 1<< ")"; 
		cin >> mira[i];
	}
}

void MergeSort(int low, int high) {
	int mid, i, na, k;
	if (low > high)
		return;
	
	mid = (low + high) / 2;

	if (low < high) {
		MergeSort(low, mid);
		MergeSort(mid + 1, high);
	}

	i = low;
	na = mid + 1;
	k = low; 

	while ((mira[i] <= mid) && (mira[na] <= high)) {
		if (mira[i] < mira[na]) {
			k = mira[i];
			i++;
		}
		else {
			k = mira[na];
			na++;
		}
		k++;
	}
	while (mira[na] <= high) {
		k = mira[na];
		na++; 
		k++;
	}
	while (mira[i] <= mid) {
		k = mira[i];
		i++;
		k++;
	}
	k = mira[101];
}

void display() {
	cout << "Sorted Array" << endl;

	for (int i = 0;i < n;i++) {
		cout << mira[i] << " ";
	}
}

int main() {
	input();
	MergeSort(0,n-1); 
	display();
}