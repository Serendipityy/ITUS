/* *************************************
	Cai Ma Tran Ke Bieu Dien Do Thi
	Duyet Do Thi Theo Chieu Sau
	Duyet Do Thi theo Chieu Rong
	************************************* */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define Max 100

	/* Cai Dat Queue */
struct Queue {
	int a[Max];
	int rear;
};
typedef struct Queue Queue;

void InitQueue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
void enQueue(Queue* q, int value);
int deQueue(Queue* q);
void Display(Queue* q);
void InitMatrix(int AdjMatrix[Max][Max], int V, int E);
void DisplayMatrix(int AdjMatrix[Max][Max], int V);
void DFS(int start, int visited[Max], int AdjMatrix[Max][Max], int V);
void BFS(int start, int AdjMatrix[Max][Max], int V, int Visited[Max]);

int main() {
	Queue q;
	InitQueue(&q);

	int V, E;
	int AdjMatrix[100][100];
	int i;
	int Visited[Max];			// Mang Danh Dau
	int start;					// Diem Xuat Phat

	cout << "\nNhap so luong Node cua Graph: ";
	cin >> V;
	cout<<"\nNhap so luong Canh cua Graph : ";
	cin >> E;
	InitMatrix(AdjMatrix, V, E);
	DisplayMatrix(AdjMatrix, V);

	/* Khoi Tao Mang Danh Dau */
	for (i = 0; i < V; i++)
		Visited[i] = 0;
	cout << "\nNhap diem xuat phat: ";
	cin >> start;
	cout << "\nDuyet do thi theo chieu sau tu " << start << " la: ";
	DFS(start, Visited, AdjMatrix, V);

	cout << "\nDuyet do thi theo chieu rong tu " << start << " la: ";
	BFS(start, AdjMatrix, V, Visited);
	return 0;
}

/* Khoi tao Queue */
void InitQueue(Queue* q) {
	q->rear = -1;
}

/* Kiem Tra Queue rong */
int isEmpty(Queue* q) {
	return (q->rear == -1);
}

/* Kiem tra Queue day */
int isFull(Queue* q) {
	return (q->rear == Max - 2);
}

/* Them Phan tu vao Queue */
void enQueue(Queue* q, int value) {
	if (isFull(q))
		cout<<"\nQueue is FUll";
	else {
		(q->rear)++;
		q->a[q->rear] = value;
	}
}

/* Lay 1 Phan tu ra khoi Queue */
int deQueue(Queue* q) {
	if (q->rear == -1)
		cout<<"\n Queue rong! Khong The Lay ra";
	else {
		int i;
		int value = q->a[0];
		for (i = 0; i < q->rear; i++)
			q->a[i] = q->a[i + 1];
		(q->rear)--;
		return value;
	}
}

/* In ra man hinh */
void Display(Queue* q) {
	int i;
	if (q->rear != -1) {
		for (i = 0; i <= q->rear; i++)
			cout << q->a[i] << "     ";
			//printf("%5d ", q->a[i]);
	}
}

/**************************************************************************** */

	/* Khoi Tao Ma Tran Ke */
void InitMatrix(int AdjMatrix[Max][Max], int V, int E) {
	int i, j;
	int u, v;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			AdjMatrix[i][j] = 0;

	for (i = 1; i <= E; i++) {
		cout<<"\n Nhap vao Hai Dinh cua Canh Thu "<< i<<": ";
		cin >> u >> v;
		AdjMatrix[u][v] = 1;
		AdjMatrix[v][u] = 1;
	}
}

void DisplayMatrix(int AdjMatrix[Max][Max], int V) {
	int i, j;
	for (i = 1; i <= V; i++) {
		cout << "\n";
		for (j = 1; j <= V; j++)
			cout << AdjMatrix[i][j] << "  ";
		cout << endl;
	}

}

/* Tim Kiem Theo Chieu Sau - DepthFirstSearch */
void DFS(int start, int visited[Max], int AdjMatrix[Max][Max], int V) {
	int j;
	cout << start << " -> ";
	visited[start] = 1;			// Da Tham

	for (j = 1; j <= V; j++) {
		if (visited[j] == 0 && AdjMatrix[start][j] == 1)
			DFS(j, visited, AdjMatrix, V);
	}
}

/* Tim Kiem Theo Chieu Rong - BreathFirstSearch */
void BFS(int start, int AdjMatrix[Max][Max], int V, int Visited[Max]) {
	Queue q;
	int i;

	/* Khoi Tao Mang Danh Dau */
	for (i = 0; i < Max; i++)
		Visited[i] = 0;
	InitQueue(&q);
	enQueue(&q, start);
	Visited[start] = -1;		// Da Duyet Xong

	while (!isEmpty(&q)) {
		start = deQueue(&q);
		cout << start << " -> ";
		Visited[start] = 1;
		for (i = 1; i <= V; i++) {
			if (AdjMatrix[start][i] == 1 && Visited[i] == 0) {
				enQueue(&q, i);
				Visited[i] = -1;
			}
		}
	}

}