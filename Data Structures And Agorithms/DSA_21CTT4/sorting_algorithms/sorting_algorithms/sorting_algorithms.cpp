#include<iostream>
using namespace std;
template<class Item>
void printArray(Item a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
}
//-------------SELECTION SORT--------------//

// Idea:
//
//Thuật toán selection sort sắp xếp một mảng bằng cách đi tìm phần tử có giá trị nhỏ nhất(giả sử với sắp xếp mảng tăng dần)
//trong đoạn đoạn chưa được sắp xếp và đổi cho phần tử nhỏ nhất đó với phần tử ở đầu đoạn chưa được sắp xếp(không phải đầu mảng).
//Thuật toán sẽ chia mảng làm 2 mảng con
//
//1. Một mảng con đã được sắp xếp
//2. Một mảng con chưa được sắp xếp
//Tại mỗi bước lặp của thuật toán, phần tử nhỏ nhất ở mảng con chưa được sắp xếp sẽ được di chuyển về đoạn đã sắp xếp.

// Code:
template<class Item>
void selection(Item a[], int l, int r) {
	for (int i = l; i < r; i++) {
		int min = i;
		for (int j = i + 1; j <= r; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

//--------------INSERTION SORT---------------//

// Idea: 
// 
//Thuật toán sắp xếp chèn thực hiện sắp xếp dãy số theo cách duyệt từng phần tử và chèn từng phần tử đó vào đúng vị trí trong mảng con
//(dãy số từ đầu đến phần tử phía trước nó) đã sắp xếp sao cho dãy số trong mảng sắp đã xếp đó vẫn đảm bảo tính chất của một dãy số
//tăng dần.
//
//Khởi tạo mảng với dãy con đã sắp xếp có k = 1 phần tử(phần tử đầu tiên, phần tử có chỉ số 0)
//Duyệt từng phần tử từ phần tử thứ 2, tại mỗi lần duyệt phần tử ở chỉ số i thì đặt phần tử đó vào một vị trí nào đó trong đoạn từ[0…i]
//sao cho dãy số từ[0…i] vẫn đảm bảo tính chất dãy số tăng dần.Sau mỗi lần duyệt, số phần tử đã được sắp xếp k trong mảng tăng thêm
//1 phần tử.
//Lặp cho tới khi duyệt hết tất cả các phần tử của mảng.

// Code: 
// Method 1:
template<class Item>
void insertion1(Item a[], int l, int r) {
	Item v; // temp
	for (int i = l+1; i <= r; i++) {
		v = a[i];
		int j;
		for (j = i; j > l && v < a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = v;
	}
}

// Method 2:
template<class Item>
void insertion2(Item a[], int l, int r) {
	int i;
	for (int i = r; i > l; i--) {
		if (a[i - 1] > a[i]) { // compare_swap
			swap(a[i - 1], a[i]);
			for (i = l + 2; i <= r; i++) {
				int v = a[i];
				int j;
				for (j = i; v < a[j - 1]; j--) {
					a[j] = a[j - 1]; // Giảm 1 nghịch thế
				}
				a[j] = v;
			}
		}
	}
}

//--------------BUBBLE SORT----------------//

// Idea: 

// Code:
template<class Item>
void bubble(Item a[], int l, int r) {
	for (int i = l; i < r; i++) {
		for (int j = r; j > i; j--) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
			}
			//compare_swap(a[j - 1], a[j]);
		}
	}
}

template<class Item>
void bubble_efficient(Item a[], int l, int r) {
	for (int i = l; i < r; i++) {
		bool flag = false;
		for (int j = r; j > i; j--) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
				flag = true;
			}
		}
		if (!flag) break;
	}
}

// Shell Sort
template<class Item>
void shellsort(Item a[], int l, int r) {
	int h;
	for (h = 1; h <= (r - l) / 9; h = 3 * h + 1);
	for (; h > 0; h /= 3) {
		int i,j;
		Item v;
		for (i = l + h; i <= r; i++) {
			j = i;
			v = a[i];
			while (j >= l + h && v < a[j - h]) {
				a[j] = a[j - h];
				j -= h;
			}
		}
		a[j] = v;
	}
}

// Merge Sort
template<class Item>
void merge(Item a[], Item aux[], int l, int m, int r) {
	int i, j, k;
	for (k = l; k <= r; k++) {
		aux[k] = a[k];
	}
	i = l, j = m + 1, k = l;
	while (i <= m && j <= r) {
		if (aux[i] <= aux[j]) {
			a[k++] = aux[i++];
		}
		else {
			a[k++] = aux[j++];
		}
	}
	while (i <= m) {
		a[k++] = aux[i++];
	}
	while (j <= r) {
		a[k++] = aux[j++];
	}
}
// Merge two subarrays L and M into arr
//void merge(int arr[], int p, int q, int r) {
//
//	// Create L ← A[p..q] and M ← A[q+1..r]
//	int n1 = q - p + 1;
//	int n2 = r - q;
//
//	int L[n1], M[n2];
//
//	for (int i = 0; i < n1; i++)
//		L[i] = arr[p + i];
//	for (int j = 0; j < n2; j++)
//		M[j] = arr[q + 1 + j];
//
//	// Maintain current index of sub-arrays and main array
//	int i, j, k;
//	i = 0;
//	j = 0;
//	k = p;
//
//	// Until we reach either end of either L or M, pick larger among
//	// elements L and M and place them in the correct position at A[p..r]
//	while (i < n1 && j < n2) {
//		if (L[i] <= M[j]) {
//			arr[k] = L[i];
//			i++;
//		}
//		else {
//			arr[k] = M[j];
//			j++;
//		}
//		k++;
//	}
//
//	// When we run out of elements in either L or M,
//	// pick up the remaining elements and put in A[p..r]
//	while (i < n1) {
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	while (j < n2) {
//		arr[k] = M[j];
//		j++;
//		k++;
//	}
//}


// Top-down merge sort
template<class Item>
void mergesort(Item a[], Item aux[], int l, int r) {
	if (r <= l) return;
	int m = (l + r) / 2;
	mergesort(a, aux, l, m);
	mergesort(a, aux, m + 1, r);
	merge(a, aux, l, m, r);
}
// Bottom-up merge sort
//template<class Item>
//void mergesort2(Item a[], Item aux[], int l, int r) {
//	for (int sz = l; sz <= r - l; sz = sz + sz) {
//		for (int i = l; i <= r - sz; i += sz + sz) {
//			merge(a, aux, i, i + sz - 1, min(i, sz + sz - 1, r));
//		}
//	}
//}

// Quick Sort
template<class Item>
int partition(Item a[], int l, int r) {
	int i = l - 1, j = r;
	Item v = a[r];
	for (;;) {
		while (a[++i] < v);
		while (v < a[--j]) {
			if (j == l)
				break;
		}
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[i], a[r]);
	return i;
}
template<class Item>
void quicksort(Item a[], int l, int r) {
	if (r <= l) return;
	int i = partition(a, l, r);
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
}

//-------------RADIX SORT------------//
template<class Item>
// Function to get the largest element from an array
int getMax(Item a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
// Using counting sort to sort the elements in the basis of significant places
template<class Item>
void countingSort(Item a[], int size, int place) {
	const int max = 10;
	// int output[size]; --> XEM LẠI 
	int output[10];
	int count[max];
	for (int i = 0; i < max; i++) {
		count[i] = 0;
	}
	// Calculate count of elements
	for (int i = 0; i < size; i++) {
		count[(a[i] / place) % 10]++;
	}
	// Calculate cumulative count
	for (int i = 1; i < max; i++) {
		count[i] += count[i - 1];
	}
	// Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--) {
		output[count[(a[i] / place) % 10] - 1] = a[i];
		count[(a[i] / place) % 10]--;
	}
	for (int i = 0; i < size; i++) {
		a[i] = output[i];
	}
}
template<class Item>
// Main function to implement radix sort
void radixsort(Item a[], int size) {
	// Get maximum element
	int max = getMax(a, size);

	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(a, size, place);
}

int main() {
	int a[] = { 5,2,0,1,3,1,4 };
	int aux[7] = { 0 };
	int a_size = sizeof(a) / sizeof(a[0]);
	cout << "Given array: \n";
	printArray(a, a_size);
	cout << "\nSorted array: \n";

	cout << "\n------SELECTION SORT-------\n";
	selection(a, 0, a_size - 1);
	printArray(a, a_size);

	cout << "\n------INSERTION SORT-------\n";
	insertion1(a, 0, a_size - 1);
	insertion2(a, 0, a_size - 1);
	printArray(a, a_size);

	cout << "\n------BUBBLE SORT------\n";
	bubble(a, 0, a_size - 1);
	bubble_efficient(a, 0, a_size - 1);
	printArray(a, a_size);

	cout << "\n------SHELL SORT------\n";
	shellsort(a, 0, a_size - 1);
	printArray(a,a_size);

	cout << "\n------MERGE SORT------\n";
	mergesort(a, aux, 0, a_size-1); 
	printArray(a, a_size);

	cout << "\n--------QUICK SORT---------\n";
	quicksort(a, 0, a_size - 1);
	printArray(a, a_size);

	cout << "\n---------RADIX SORT----------\n";
	radixsort(a, a_size);
	printArray(a, a_size);
	return 0;
}