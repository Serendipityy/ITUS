#include<iostream>
#include<time.h>
using namespace std;

template <class Item>
void Display(Item* a, const int size) {
	int x = 0;
	//Just display the elements in a array
	while (x < size) {
		cout << a[x] << " ";
		x++;
	}
	cout << endl;
}

//-------------SELECTION SORT--------------//
/*Thuật toán:
- Khởi tạo giá trị nhỏ nhất (min) cho vị trí đầu tiên
- Duyệt mảng để tìm phần tử nhỏ nhất trong mảng
- Trong khi duyệt, nếu có phần tử nào nhỏ hơn min thì hoán đổi 2 giá trị với nhau
- Tăng min để trỏ đến phần tử tiếp theo
- Lặp lại cho đến khi mảng đã được sắp xếp
*/
// Code:
template<class Item>
void selection(Item* a, int l, int r) {
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
/*Thuật toán:
- Lặp lại từ a[l+1] đến a[r]
- So sánh phần tử hiện tại với phần tử liền trước nó, nếu phần tử hiện tại nhỏ hơn phần tử liền trước nó thì hoán đổi vị trí cho nhau,
rồi tiếp tục so sánh nó với phần tử trước đó, hoán đổi cho đến khi nó lớn hơn phần tử liền trước
- Di chuyển các phần tử lớn hơn lên một vị trí để tạo khoảng trống cho phần tử được hoán đổi.
*/
// Code: 
// Method 1:
template<class Item>
void insertion1(Item* a, int l, int r) {
	Item v; // temp
	for (int i = l + 1; i <= r; i++) {
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
void insertion2(Item* a, int l, int r) {
	int i;
	for (i = r; i > l; i--) {
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

/*Thuật toán
- Chạy vòng lặp for lồng nhau để duyệt mảng sử dụng 2 biến i, j (kế tiếp nhau) (0 ≤ i <n-1 và 0 ≤ j <n-i-1)
- Nếu if a[j - 1] > a[j] hoán đổi 2 phần tử liền kề này, nếu không thì tiếp tục duyệt từ vị trí tiếp theo
- Lặp cho đến khi mảng được sắp xếp
*/
// Code:
template<class Item>
void bubble(Item* a, int l, int r) {
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
void bubble_efficient(Item* a, int l, int r) {
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

//-------------SHELL SORT----------------//
/*Thuật toán:
- Khởi tạo giá trị kích thước khoảng cách (h)
- Chia mảng thành các mảng con, mỗi mảng con có khoảng cách bằng h
- Sắp xếp trên các mảng con bằng insertion sort
- Lặp lại cho đến khi mảng được sắp xếp
*/

// Code:
template<class Item>
void shellsort(Item* a, int l, int r) {
	int h;
	// Knuth's Formula: h=h*3+1
	for (h = 1; h <= (r - l) / 9; h = 3 * h + 1);
	for (; h > 0; h /= 3) {
		int i, j;
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

//--------------MERGE SORT----------------//
/*Thuật toán:
- MergeSort (arr [], l, r) (Nếu r> l)
- Tìm điểm giữa để chia mảng thành hai nửa (middle m = l + (r – l)/2)
- Gọi hàm MergeSort cho nửa đầu: mergeSort (arr, l, m)
- Gọi hàm MergeSort cho nửa sau: mergeSort (arr, m + 1, r)
- Kết hợp 2 nửa đã được sắp xếp lại với nhau: merge(arr, l, m, r)
*/

// Code:
//template<class Item>
//void merge(Item *a, Item aux[], int l, int m, int r) {
//	int i, j, k;
//	for (k = l; k <= r; k++) {
//		aux[k] = a[k];
//	}
//	i = l, j = m + 1, k = l;
//	while (i <= m && j <= r) {
//		if (aux[i] <= aux[j]) {
//			a[k++] = aux[i++];
//		}
//		else {
//			a[k++] = aux[j++];
//		}
//	}
//	while (i <= m) {
//		a[k++] = aux[i++];
//	}
//	while (j <= r) {
//		a[k++] = aux[j++];
//	}
//}
template<class Item>
void merge(Item* a, int l, int m, int r) {
	//Used to split a source array into two halfs and sort each set
	int n1 = (m - l + 1);
	int n2 = (r - m);

	int x = 0;
	int y = 0;
	int z = 0;

	Item* L;
	Item* R;
	//Create arrays
	L = new Item[n1]; // Left
	R = new Item[n2]; // Right
	//Copy data to left array
	while (x < n1) {
		L[x] = a[l + x];
		x++;
	}
	//Copy data to right array
	while (y < n2) {
		R[y] = a[m + 1 + y];
		y++;
	}
	//Reset variables for next loops
	x = 0;
	y = 0;
	//Set z to left
	z = l;

	while (x < n1 && y < n2) {
		//Compare left array to right array
		if (L[x] <= R[y]) {
			//Set data
			a[z] = L[x];
			x++;
		}
		else {
			//Set data
			a[z] = R[y];
			y++;
		}
		z++;
	}
	//Copy any remaining left array back to data array
	while (x < n1) {
		//Set data array with left array data
		a[z] = L[x];
		x++;
		z++;
	}
	//Copy any remaining right array back to data array
	while (y < n2) {
		//Set data array with right array data
		a[z] = R[y];
		y++;
		z++;
	}
	//Delete left and right arrays.
	delete[]L;
	delete[]R;
}

// Top-down merge sort
//template<class Item>
//void mergesort(Item *a, Item aux[], int l, int r) {
//	if (r <= l) return;
//	int m = (l + r) / 2;
//	mergesort(a, aux, l, m);
//	mergesort(a, aux, m + 1, r);
//	merge(a, aux, l, m, r);
//}
template <typename T>
void mergesort(T* a, int l, int r) {

	if (l >= r) {
		return;
	}
	//Get middle of data array
	int m = l + (r - l) / 2;
	//Merge left side
	mergesort(a, l, m);
	//Merge right side
	mergesort(a, m + 1, r);
	merge(a, l, m, r);
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


//------------------HEAP SORT-------------------//
/* Thuật toán:
- Tạo max heap từ dữ liệu đầu vào
- Phần tử lớn nhất được lưu trữ ở gốc của heap.
- Thay thế nó bằng phần tử cuối cùng của heap, sau đó giảm kích thước của heap đi 1
- heapify root tree
- Lặp lại cho đến khi kích thước của heap lớn hơn 1

*/

// Code:
template <class Item >
void heapify(Item* a, int n, int i) {
	Item v = a[i];
	while (i < n / 2) {
		int child = 2 * i + 1;
		if (child < n - 1)
			if (a[child] < a[child + 1])
				child++;
		if (v >= a[child]) break;
		a[i] = a[child];
		i = child;
	}
	a[i] = v;
	//int largest = i; // Initialize largest as root
	//int l = 2 * i + 1; // left = 2*i + 1
	//int r = 2 * i + 2; // right = 2*i + 2
	//// If left child is larger than root
	//if (l < n && a[l] > a[largest])
	//	largest = l;
	//// If right child is larger than largest so far
	//if (r < n && a[r] > a[largest])
	//	largest = r;
	//// If largest is not root
	//if (largest != i) {
	//	swap(a[i], a[largest]);
	//	// Recursively heapify the affected sub-tree
	//	heapify(a, n, largest);
	//}
}
template <class Item >
void heapsort(Item* a, int l, int r) {
	Item* pa = a + l;
	int N = r - l + 1;
	for (int k = N / 2 - 1; k >= 0; k--)
		heapify(pa, N, k);
	while (N > 1) {
		swap(pa[0], pa[N - 1]);
		N--;
		heapify(pa, N, 0);
	}
}

//----------------QUICK SORT-------------------//
/*Thuật toán:
- Chọn phần tử chốt.
- Khai báo 2 biến con trỏ để trỏ để duyệt 2 phía của phần tử chốt.
- Biến bên trái trỏ đến từng phần tử mảng con bên trái của phần tử chốt.
- Biến bên phải trỏ đến từng phần tử mảng con bên phải của phần tử chốt.
- Khi biến bên trái nhỏ hơn phần tử chốt thì di chuyển sang phải.
- Khi biến bên phải nhỏ hơn phần tử chốt thì di chuyển sang trái.
- Nếu không xảy ra 2 trường hợp trên thì hoán đổi giá trị 2 biến trái và phải.
- Nếu trái lớn hơn phải thì đây là giá trị chốt mới.
*/

// Code:
template<class Item>
int partition(Item* a, int l, int r) {
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
void quicksort(Item* a, int l, int r) {
	if (r <= l) return;
	int i = partition(a, l, r);
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
}

//-------------RADIX SORT------------//
/*Thuật toán
Step 1 – Take input array and find MAX number in the array
Step 2 – Define 10 queues each representing a bucket for each digit from 0 to 9.
Step 3 – Consider the least significant digit of each number in the list which is to be sorted.
Step 4 – Insert each number into their respective queue based on the least significant digit.
Step 5 – Group all the numbers from queue 0 to queue 9 in the order they have inserted into their respective queues.
Step 6 – Repeat from step 3 based on the next least significant digit.
Step 7 – Repeat from step 2 until all the numbers are grouped based on the most significant digit.

* Hàm thực hiện sắp xếp theo cơ số với tham số đầu vào là (mảng cần sắp xếp)
- Gán d = số lượng các chữ số trong phần tử lớn nhất
- Tạo d khối có kích thước từ 0 tới 9
- Sử dụng vòng lặp for với i = 0 cho tới d: Sắp xếp các phần tử dựa theo các chữ số tại vị trí bằng cách sử dụng hàm sắp xếp theo số đếm

* Hàm sắp xếp theo số đếm với bộ tham số là (mảng cần sắp xếp, d)
- Gán max = tìm phần tử lớn trong các phần tử tại vị trí thứ d
- Khởi mảng đếm với tất cả các giá trị là 0
- Sử dụng vòng lặp for với j = 0 cho tới giá trị của kích thước
 + Tìm số đếm tổng của mỗi số tại vị trí d của các phần tử
 + Lưu trữ số đếm tại chỉ số thứ j trong mảng đếm
- Sử dụng vòng lặp for với i = 1 cho tới giá trị max: Tính tổng tích lũy và lưu trữ trong mảng đếm
- Sử dụng vòng lặp for với j = size cho tới giá trị 1
 + Khôi phục lại các phần tử thành một mảng
 + Giảm số đếm của mỗi phần tử được lưu trữ đi 1 đơn vị
*/

// Code:
template<class Item>
// Function to get the largest element from an array
int getMax(Item* a, int n) {
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
void countingSort(Item* a, int size, int place) {
	const int max = 10;
	// int output[size]; --> XEM LẠI 
	int* output = new int[size];
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
void radixsort(Item* a, int size) {
	// Get maximum element
	int max = getMax(a, size);

	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(a, size, place);
}

//--------------BINARY INSERTION SORT-----------------//
/*Thuật toán:
- Lặp lại từ phần tử thứ 2 đến phần tử cuối cùng của mảng
- Lưu trữ phần tử hiện tại A [i] trong một biến key
- Tìm vị trí của phần tử chỉ lớn hơn A [i] trong mảng con từ A [0] đến A [i-1] bằng cách sử dụng tìm kiếm nhị phân (giả sử ở vị trí index)
- Chuyển tất cả các phần tử từ vị trí index sang i-1 về phía bên phải.
- A[pos] = key.
*/

// Code:
template<class Item>
int binarySearch(Item* a, int item, int low, int high) {
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;
	int mid = (low + high) / 2;
	if (item == a[mid])
		return mid + 1;
	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}
template<class Item>
void insertionSort(Item* a, int l, int r) {
	int i, loc, j, k, selected;
	for (i = l; i < r; ++i)
	{
		j = i - 1;
		selected = a[i];
		// find location where selected should be inseretd
		loc = binarySearch(a, selected, 0, j);
		// Move all elements after location to create space
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

//------------SHAKER SORT--------------//
/* Thuật toán:
- Shaker sort là cải tiến của Bubble sort
- Trong mỗi lần sắp xếp, duyệt mảng theo 2 lượt từ 2 phía khác nhau:
 + Lượt đi: đẩy phần tử lớn về cuối mảng.
 + Lượt về: đẩy phần tử nhỏ về đầu mảng.
- Ghi nhận lại những đoạn đã sắp xếp nhằm tiết kiệm các phép so sánh thừa.
*/

// Code:
template<class Item>
void shakerSort(Item* a, int l, int r)
{
	int k = 0;
	for (int i = l; i < r; i++) {
		if (a[i] > a[i + 1]) {
			swap(a[i], a[i + 1]);
			k = i;
		}
	}
	r = k;
	for (int i = r; i > l; i--) {
		if (a[i] < a[i - 1]) {
			swap(a[i], a[i - 1]);
			k = i;
		}
	}
	l = k;
}

//-------------INTERCHANGE SORT--------------//
/* Thuật toán:
- Xuất phát từ đầu dãy, tìm tất các cặp A[i] và A[j] thỏa mãn điều kiện i < j và A[i] > A[j].
- Đổi chỗ 2 phần tử này cho nhau.
- Lặp lại xử lý trên với phần tử kế trong dãy.
*/

// Code:
template<class Item>
void InterchangeSort(Item* a, int l, int r) {
	int i, j;
	for (i = l; i < r; i++) {
		for (j = i + 1; j < r; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void Menu() {
	int ch;
	bool quit = false;
	int* nums;
	int size = 200000;
	nums = new int[size];
	//Make some random numbers and store them in nums array
	srand(time(NULL));

	for (int x = 0; x < size; x++) {
		// Tạo mảng ngẫu nhiên với các số dao động từ 0 đến 1000
		nums[x] = rand() % 1001;
	}
	clock_t start, end;   // Khai báo biến thời gian
	double time_use;      // Thời gian sử dụng
	do {
		system("cls");
		cout << "\n==============================================";
		cout << "\n*HIEN THI MANG NGAU NHIEN*";
		cout << "\n0. In danh sach mang ngau nhien 200000 phan tu";
		cout << "\n==============================================";
		cout << "\n*CAC THUAT TOAN SAP XEP*";
		cout << "\n1. Selection Sort";
		cout << "\n2. Bubble Sort";
		cout << "\n3. Insertion Sort";
		cout << "\n4. Merge Sort";
		cout << "\n5. Quick Sort";
		cout << "\n6. Heap Sort";
		cout << "\n7. Radix Sort";
		cout << "\n8. Shell Sort";
		cout << "\n9. Binary Insertion Sort";
		cout << "\n10. Shaker Sort";
		cout << "\n11. Interchange Sort";
		cout << "\n12. Thoat";
		cout << "\n==================================";
		cout << "\nNhap lua chon: ";
		cin >> ch;
		switch (ch) {
		case 0:
			Display(nums, size);
			system("pause");
			break;
		case 1:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			selection(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Selection Sort: " << time_use << "s";
			system("pause");
			break;
		case 2:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			bubble_efficient(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Bubble Sort: " << time_use << "s";
			system("pause");
			break;
		case 3:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			insertion1(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Insertion Sort: " << time_use << "s";
			system("pause");
			break;
		case 4:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			mergesort(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Merge Sort: " << time_use << "s";
			system("pause");
			break;
		case 5:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			quicksort(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Quick Sort: " << time_use << "s";
			system("pause");
			break;
		case 6:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			heapsort(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Heap Sort: " << time_use << "s";
			system("pause");
			break;
		case 7:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			radixsort(nums, size);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Radix Sort: " << time_use << "s";
			system("pause");
			break;
		case 8:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			shellsort(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Shell Sort: " << time_use << "s";
			system("pause");
			break;
		case 9:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			insertionSort(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Binary Insertion Sort: " << time_use << "s";
			system("pause");
			break;
		case 10:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			shakerSort(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Shaker Sort: " << time_use << "s";
			system("pause");
			break;
		case 11:
			start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
			InterchangeSort(nums, 0, size - 1);
			Display(nums, size);
			end = clock();  // lấy thời gian sau khi thực hiện 
			time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
			cout << "Thoi gian chay Interchange Sort: " << time_use << "s";
			system("pause");
			break;
		case 12:
			quit = true;
			break;
		default:
			cout << "\nLua chon khong hop le !";
			system("pause");
			break;
		}
	} while (!quit);
}
int main() {
	Menu();
	return 0;
}