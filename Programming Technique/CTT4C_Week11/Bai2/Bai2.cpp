//bai.cpp file bai tap kiem tra cac thuat toan

#include <stdio.h>
#include <math.h>

// Hàm đổi chỗ 2 số nguyên
void swap(int& xp, int& yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
}

/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


// Hàm selection sort
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;
	// Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; i < n - 1; i++)
	{
		// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		swap(arr[min_idx], arr[i]);
	}
}

// Hàm sắp xếp bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n - 1; i++) {
		// i phần tử cuối cùng đã được sắp xếp
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				haveSwap = true; // Kiểm tra lần lặp này có swap không
			}
		}
		// Nếu không có swap nào được thực hiện => mảng đã sắp xếp. Không cần lặp thêm
		if (haveSwap == false) {
			break;
		}
	}
}

//Ham Insertion Sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Di chuyển các phần tử có giá trị lớn hơn giá trị
		key về sau một vị trí so với vị trí ban đầu
		của nó */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//quick sort
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}

/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
		 và là phần tử chia mảng làm 2 mảng con trái & phải */
		int pi = partition(arr, low, high);

		// Gọi đệ quy sắp xếp 2 mảng con trái và phải
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


// Thuat toan sap xep vun dong
// Hàm vun đống cho một đỉnh
void heapify(int arr[], int n, int i) {  // mảng arr, n - số phần tử, i - đỉnh cần vun đống
	int max = i;    // Lưu vị trí đỉnh max ban đầu
	int l = i * 2 + 1;   // Vị trí con trái
	int r = l + 1;    // Vị trí con phải
	if (l<n && arr[l] > arr[max]) {   // Nếu tồn tại con trái lớn hơn cha, gán max = L
		max = l;
	}

	if (r<n && arr[r] > arr[max]) {   // Nếu tồn tại con phải lớn hơn arr[max], gán max = r
		max = r;
	}
	if (max != i) {      // Nếu max != i, tức là cha không phải lớn nhất
		swap(arr[i], arr[max]);   // Đổi chỗ cho phần tử lớn nhất làm cha
		heapify(arr, n, max);    // Đệ quy vun các node phía dưới
	}

}
// Ham sap xep vun dong
void heapSort(int arr[], int n) {

	// vun dong tu duoi len len de thanh heap
	for (int i = n / 2 - 1; i >= 0; i--)   // i chạy từ n/2 - 1 về 0 sẽ có n/2 đỉnh nhé!
		heapify(arr, n, i);   // Vun từng đỉnh

	// Vòng lặp để thực hiện vun đống và lấy phần tử
	for (int j = n - 1; j > 0; j--) {   // chạy hết j == 1 sẽ dừng
				// mỗi lần j - 1, tương đương với k xét phần tử cuối 
		swap(arr[0], arr[j]);  // đổi chỗ phần tử lớn nhất
		heapify(arr, j, 0);    // vun lại đống, 
	}
}

//readix sort
void radixSort(int* a, int n)
{
	int b[100], m = a[0], exp = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}

//Shell sort
void shellSort(int a[], int n) {
	int interval, i, j, temp;
	for (interval = n / 2; interval > 0; interval /= 2) {
		for (i = interval; i < n; i++) {
			temp = a[i];
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}

//insertion sort
void  BInsertionSort(int a[], int n)
{
	int l, r, m, i;
	int x;//lưu giá trị a[i] tránh bị ghi đè khi dời chỗ các phần tử.  
	for (int i = 1; i < n; i++)
	{
		x = a[i]; l = 0;
		r = i - 1;
		while (l <= r) // tìm vị trí chèn x 
		{
			m = (l + r) / 2;
			// tìm vị trí thích hợp m   
			if (x < a[m]) r = m - 1;
			else l = m + 1;
		}
		for (int j = i - 1; j >= l; j--)
			a[j + 1] = a[j];// dời các phần tử sẽ đứng sau x  
		a[l] = x;  // chèn x vào dãy  }
	}
}

// shaker sort 
void shakerSort(int a[], int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

//Interchange Sort
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])  //nếu có nghịch thế thì đổi chỗ
				swap(a[i], a[j]);
}

//ham chinh
int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//selection sort
	selectionSort(arr, n);
	printf("1. Sorted array: \n");
	printArray(arr, n);
	//bubble sort
	bubbleSort(arr, n);
	printf("2. Sorted array: \n");
	printArray(arr, n);
	//insertion sort
	printf("3. Sorted array: \n");
	printArray(arr, n);
	insertionSort(arr, n);
	//quick sort
	quickSort(arr, 0, n - 1);
	printf("4. Sorted array: \n");
	printArray(arr, n);
	//heap sort
	heapSort(arr, n);
	printf("5. Sorted array: \n");
	printArray(arr, n);
	//radix sort
	radixSort(arr, n);
	printf("6. Sorted array: \n");
	printArray(arr, n);
	//shell sort
	shellSort(arr, n);
	printf("7. Sorted array: \n");
	printArray(arr, n);
	//insertion sort
	BInsertionSort(arr, n);
	printf("8. Sorted array: \n");
	printArray(arr, n);
	//shell sort
	shellSort(arr, n);
	printf("9. Sorted array: \n");
	printArray(arr, n);
	//Interchange Sort
	InterchangeSort(arr, n);
	printf("10. Sorted array: \n");
	printArray(arr, n);
	return 0;
}