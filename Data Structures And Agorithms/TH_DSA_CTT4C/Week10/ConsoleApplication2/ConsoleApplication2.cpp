#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//10 11
//1 2
//1 3
//1 5
//1 10
//2 4 
//3 6
//3 7
//3 9
//6 7
//5 8
//8 9

int n, m; // so dinh va canh
vector<int>adj[1001]; // luu danh sach cac dinh ke
bool visited[1001]; // check xem cac dinh da duoc tham hay chua

// Nhap ds ke
void input() {
	cout << "\nNhap lan luot so dinh va canh cua do thi: ";
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cout << "\n Nhap vao Hai Dinh cua Canh Thu " << i << ": ";
		cin >> x >> y;
		adj[x].push_back(y);
		// Có hướng thì bỏ dòng này (vô hướng thì thêm)
		/*adj[y].push_back(x);*/
	}
	// memset: tra ve mot chuoi da duoc sao chep (sao chep false voi so lan visited) va luu vao con tro visited
	memset(visited, false, sizeof(visited));
}

void bfs(int u) {
	//khoi tao queue
	queue<int>q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int v = q.front(); //lay dinh o dau hang doi
		q.pop();
		cout << v << " ";
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
}
int main() {
	input();
	int v;
	cout << "\nNhap dinh bat dau: ";
	cin >> v;
	bfs(v);
	return 0;
}