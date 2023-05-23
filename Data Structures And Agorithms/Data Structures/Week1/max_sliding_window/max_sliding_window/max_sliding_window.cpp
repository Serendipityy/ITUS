#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const& A, int w) {
	for (size_t i = 0; i < A.size() - w + 1; ++i) {
		int window_max = A.at(i);
		for (size_t j = i + 1; j < i + w; ++j)
			window_max = max(window_max, A.at(j));
		cout << window_max << " ";
	}
	return;
}
//void max_sliding_window_naive(vector<int> const& A, int k) {
//	deque<int> dq;
//	for (int i = 0; i < A.size(); i++) {
//		if (!dq.empty() && i - dq.front() == k) dq.pop_front();
//		while (!dq.empty() && A[i] > A[dq.back()])
//			dq.pop_back();
//		dq.emplace_back(i);
//		if (i - k + 1 >= 0) cout << A[dq.front()] << " ";
//	}
//	cout << endl;
//	return;
//}
int main() {
	int n = 0;
	cin >> n;

	vector<int> A(n);
	for (size_t i = 0; i < n; ++i) 
		cin >> A.at(i);

	int w = 0;
	cin >> w;

	max_sliding_window_naive(A, w);

	return 0;
}