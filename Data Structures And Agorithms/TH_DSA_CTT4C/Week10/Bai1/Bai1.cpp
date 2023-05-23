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

int edge, vertice; // so dinh va canh
vector<int>adj[1000]; // luu danh sach cac dinh ke
bool visited[1000]; // check xem cac dinh da duoc tham hay chua

// Nhap ds ke
void input() {
	cout << "\nNhap so dinh cua do thi: ";
	cin >> vertice;
	cout << "\nNhap so canh cua do thi: ";
	cin >> edge;
	for (int i = 0; i < edge; i++) {
		int x, y;
		cout << "\nNhap vao hai Dinh cua Canh Thu " << i << ": ";
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
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
	int start;
	cout << "\nNhap dinh bat dau: ";
	cin >> start;
	cout << "\nDanh sach cac dinh duoc duyet theo chieu rong (BFS): ";
	bfs(start);
	return 0;
}