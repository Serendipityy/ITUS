#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*Khai bao kieu du lieu sinh vien*/
struct sv {
	string hoten;
	string id;
	double lt = 0;
	double th = 0;
	double tb = 0;
};

/*overload toan tu << cho ham xuat sinh vien*/
ostream& operator<<(ostream& COUT, sv sinhvien) {
	COUT << "Ho ten: " << sinhvien.hoten << endl;
	COUT << "Id: " << sinhvien.id << endl;
	COUT << "Diem ly thuyet: " << sinhvien.lt << endl;
	COUT << "Diem thuc hanh: " << sinhvien.th << endl;
	COUT << "Diem trung binh: " << sinhvien.tb << endl;
	return COUT;
}

/*Khai bao kieu du lieu Node*/
template <class T>
struct Node {
	T data;
	Node* next;
};

/*Khai bao kieu du lieu List*/
template <class T>
struct List {
	Node<T>* head;
	Node<T>* tail;
};

/*Khoi tao List*/
template <class T>
void ListInit(List<T>& l) {
	l.head = l.tail = NULL;
}

/*Khoi tao Node*/
template <class T>
Node<T>* getNode(T DATA) {
	Node<T>* p = new Node<T>;
	if (p != NULL) {
		p->data = DATA;
		p->next = NULL;
	}
	return p;
}

/*Dem so node co trong List*/
template <class T>
int countNode(List<T> l) {
	int node = 0;
	for (Node<T>* r = l.head; r; r = r->next) {
		node++;
	}
	return node;
}

/*Them 1 node vao cuoi List*/
template <class T>
void addLast(List<T>& l, T DATA) {
	Node<T>* p = getNode(DATA);
	if (l.head == NULL)
		l.head = l.tail = p;
	else {
		l.tail->next = p;
		l.tail = p;
	}
}

/*Them 1 node vao dau List*/
template <class T>
void addFirst(List<T>& l, T DATA) {
	Node<T>* p = getNode(DATA);
	if (l.head == NULL)
		l.head = l.tail = p;
	else {
		p->next = l.head;
		l.head = p;
	}
}

/*Them 1 node vao vi tri bat ky*/
template <class T>
void add(List<T>& l, T DATA, int pos) {
	/*Dem so node co trong List*/
	int node = countNode(l);

	/*Tao node can them*/
	Node<T>* newNode = getNode(DATA);

	/*Kiem tra vi tri them*/
	if (pos < 0 || pos > node) {
		do {
			cout << "Nhap lai vi tri them: "; cin >> pos;
		} while (pos < 0 || pos > node);
	}
	else if (pos == 0)
		addFirst(l, DATA);
	else if (pos == node)
		addLast(l, DATA);
	else {
		Node<T>* r; int i;
		/*Tao node t luu dia chi node truoc vi tri can them*/
		Node<T>* t = new Node<T>;
		for (i = 0, r = l.head; i < pos; i++, r = r->next)
			if (i == pos - 1)
				t = r;
		t->next = newNode;
		newNode->next = r;
	}
}

/*Xoa node dau tien*/
template<class T>
void delBegin(List<T>& l) {
	//tao node p
	Node<T>* p = new Node<T>;
	//gan p bang node pHead dau tien cua danh sach 
	p = l.head;
	//thay doi lai pHead cua danh sach
	l.head = l.head->next;
	//gan node p ban dau tro den NULL
	p->next = NULL;
	//xoa node p
	delete p;
}

/*Xoa node cuoi cung*/
template<class T>
void delLast(List<T>& l)
{
	//duyet cac phan tu co trong danh sach
	for (Node<T>* k = l.head; k != NULL; k = k->next)
	{
		//neu duyet den phan tu pTail cuoi trong danh sach
		if (k->next == l.tail)
		{
			//xoa phan tu cuoi
			delete l.tail;
			//tro phan tu truoc phan tu cuoi ve NULL
			k->next = NULL;
			//thay doi lai phan tu cuoi pTail cua danh sach
			l.tail = k;
		}
	}
}
/*Xoa 1 node o vi tri bat ky*/
template <class T>
void Delete(List<T>& l, int pos) {
	int node = countNode(l);
	if (pos < 0 || pos >= node) {
		do {
			cout << "Nhap lai vi tri xoa: "; cin >> pos;
		} while (pos < 0 || pos > node);
	}
	else if (pos == 0)
		delBegin(l);
	else if (pos == node - 1)
		delLast(l);
	else {
		Node<T>* r; int i;
		Node<T>* t = l.head;
		for (i = 0, r = l.head; i < pos; i++, r = r->next) {
			if (i == pos - 1)
				t = r;
		}
		t->next = r->next;
		//delete[]t;
	}
}

/*Doc thong tin 1 sinh vien tu file*/
void docSv(ifstream& filein, sv& sinhvien) {
	//doc file den dau ; thi ngung
	getline(filein, sinhvien.hoten, ';');
	getline(filein, sinhvien.id, ';');
	//doc so thuc 
	filein >> sinhvien.lt;
	//bo qua dau ;
	filein.ignore(1, ';');
	filein >> sinhvien.th;
	sinhvien.tb = sinhvien.lt * 0.7 + sinhvien.th * 0.3;
	filein.ignore();
}

/*Doc danh sach sinh vien*/
void docDssv(ifstream& filein, List<sv>& l) {
	sv sinhvien;
	ListInit(l);//tao danh sach rong
	//doc ky tu den cuoi file thi ngung
	while (filein.peek() != EOF) {
		docSv(filein, sinhvien);
		addLast(l, sinhvien);
	}
}

/*Nhap 1 sinh vien*/
void nhap1Sv(sv& sinhvien) {
	cout << "Nhap Id: ";
	cin.ignore();
	getline(cin, sinhvien.id);
	cout << "Nhap ho ten: ";
	getline(cin, sinhvien.hoten);
	cout << "Nhap diem ly thuyet: ";
	cin >> sinhvien.lt;
	cout << "Nhap diem thuc hanh: ";
	cin >> sinhvien.th;
	sinhvien.tb = sinhvien.lt * 0.7 + sinhvien.th * 0.3;
}

/*Xuat danh sach*/
template <class T>
void printList(List<T> l) {
	int i = 0;
	for (Node<T>* r = l.head; r != NULL; r = r->next) {
		cout << "Node " << i << endl;
		cout << r->data << endl;
		i++;
	}
}

/*Giai phong danh sach lien ket*/
template<class T>
void GiaiPhong(List<T>& l) {
	Node* p;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete p;
	}
}

/*Cac bien su dung cho viec test cac danh sach*/
int addIdx, delIdx, ch;
bool quit = false;
void Menu_SV() {
	List<sv> svList;
	ListInit(svList);
	do {
		system("cls");
		cout << "====================================" << endl;
		cout << "*DANH SACH LIEN KET CAC SINH VIEN*" << endl;
		cout << "1: Doc danh sach sinh vien tu file" << endl;
		cout << "2: Xuat danh sach sinh vien" << endl;
		cout << "3: Them mot sinh vien vao vi tri bat ky" << endl;
		cout << "4: Xoa mot sinh vien o vi tri bat ky" << endl;
		cout << "5: Thoat" << endl;
		cout << "====================================" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch)
		{
		case 1:
		{
			ifstream filein;
			char fileName[30];
			cout << "\nNhap ten file: "; cin >> fileName;

			/*Mo file*/
			filein.open(fileName, ios::in);
			if (!filein)
				cout << "File cannot open" << endl;

			/*Doc danh sach sinh vien*/
			docDssv(filein, svList);
			cout << "Doc file thanh cong ! (nhap 2 de kiem tra)" << endl;
			system("pause");
		}
		break;
		case 2:
		{
			/*Xuat danh sach sinh vien*/
			printList(svList);
			system("pause");
		}
		break;
		case 3:
		{
			/*Them 1 sinh vien bat ky*/
			sv sinhvien;
			cout << "\nNhap thong tin sinh vien can them" << endl;
			nhap1Sv(sinhvien);

			cout << "\nNhap vi tri can them: "; cin >> addIdx;
			add(svList, sinhvien, addIdx);

			cout << "\nDa them sinh vien thanh cong !";
			system("pause");
		}
		break;
		case 4:
		{
			/*Xoa 1 sinh vien bat ky*/
			cout << "\nNhap vi tri can xoa: "; cin >> delIdx;
			Delete(svList, delIdx);
			cout << "\nDa xoa sinh vien thanh cong";
			system("pause");
		}
		break;
		case 5: {
			quit = true;
			break;
		default:
			cout << "Lua chon khong hop le !" << endl;
		}
			  break;
		}
	} while (!quit);
}
void Menu_Int() {
	List<int> intList;
	ListInit(intList);
	int intNum = 0;
	do {
		system("cls");
		cout << "====================================" << endl;
		cout << "*DANH SACH LIEN KET CAC SO NGUYEN*" << endl;
		cout << "1: Nhap danh sach cac so nguyen" << endl;
		cout << "2: Xuat danh sach cac so nguyen" << endl;
		cout << "3: Them mot so nguyen vao mot vi tri bat ky" << endl;
		cout << "4: Xoa mot so nguyen o vi tri bat ky" << endl;
		cout << "5: Thoat" << endl;
		cout << "====================================" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "\nNhap danh sach cac so nguyen (nhap 0 de dung): " << endl;
			do {
				cin >> intNum;
				addLast(intList, intNum);
			} while (intNum != 0);
		}
		break;
		case 2:
		{
			cout << "\n------DANH SACH CAC SO NGUYEN------- " << endl;
			printList(intList);
			system("pause");
		}
		break;
		case 3:
		{
			cout << "Nhap so nguyen, vi tri them: "; cin >> intNum >> addIdx;
			add(intList, intNum, addIdx);
			cout << "\nDa them thanh cong !";
			system("pause");
		}
		break;
		case 4:
		{
			cout << "\nNhap vi tri xoa: "; cin >> delIdx;
			Delete(intList, delIdx);
			cout << "\nDa xoa thanh cong !";
			system("pause");
			break;
		case 5:
		{
			quit = true;
			break;
		}
		default:
			cout << "Lua chon khong hop le !" << endl;
		}
		break;
		}
	} while (!quit);
}
void Menu_Double() {
	List<double> doubleList;
	ListInit(doubleList);
	double doubleNum = 0;
	do {
		system("cls");
		cout << "====================================" << endl;
		cout << "*DANH SACH LIEN KET CAC SO THUC*" << endl;
		cout << "1: Nhap danh sach cac so thuc" << endl;
		cout << "2: Xuat danh sach cac so thuc" << endl;
		cout << "3: Them mot so thuc vao mot vi tri bat ky" << endl;
		cout << "4: Xoa mot so thuc o vi tri bat ky" << endl;
		cout << "5: Thoat" << endl;
		cout << "====================================" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "\nNhap danh sach cac so thuc (nhap 0 de dung)" << endl;
			do {
				cin >> doubleNum;
				addLast(doubleList, doubleNum);
			} while (doubleNum != 0);
		}
		break;
		case 2:
		{
			cout << "\n-------DANH SACH CAC SO THUC--------" << endl;
			printList(doubleList);
			system("pause");
		}
		break;

		case 3:
		{
			cout << "Nhap so thuc, vi tri them: "; cin >> doubleNum >> addIdx;
			add(doubleList, doubleNum, addIdx);
			cout << "\nDa them thanh cong !";
			system("pause");
		}
		break;
		case 4:
		{
			cout << "Nhap vi tri xoa: "; cin >> delIdx;
			Delete(doubleList, delIdx);
			cout << "\nDa xoa thanh cong !";
			system("pause");
			break;
		case 5: {
			quit = true;
			break;
		}
		default:
			cout << "Lua chon khong hop le !" << endl;
		}
		break;
		}
	} while (!quit);
}
void Menu_String() {
	List<string> stringList;
	ListInit(stringList);
	string str;
	do {
		system("cls");
		cout << "====================================" << endl;
		cout << "*DANH SACH LIEN KET CAC CHUOI KY TU*" << endl;
		cout << "1: Nhap danh sach cac chuoi ky tu" << endl;
		cout << "2: Xuat danh sach cac chuoi ky tu" << endl;
		cout << "3: Them mot chuoi ky tu vao mot vi tri bat ky" << endl;
		cout << "4: Xoa mot chuoi ky tu o vi tri bat ky" << endl;
		cout << "5: Thoat" << endl;
		cout << "====================================" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "\nNhap danh sach cac chuoi (nhap 0 de dung)" << endl;
			cin.ignore();

			do {
				getline(cin, str);
				if (str != "0")
					addLast(stringList, str);
			} while (str != "0");
		}
		break;
		case 2:
		{
			cout << "\n---------DANH SACH CHUOI KY TU----------" << endl;
			printList(stringList);
			system("pause");
		}
		break;
		case 3:
		{
			cout << "Nhap chuoi: ";
			cin.ignore();
			getline(cin, str);
			cout << "Nhap vi tri them: "; cin >> addIdx;
			add(stringList, str, addIdx);
			cout << "\nDa them chuoi thanh cong !";
			system("pause");
		}
		break;
		case 4:
		{
			cout << "Nhap vi tri xoa: "; cin >> delIdx;
			Delete(stringList, delIdx);
			cout << "\nDa xoa chuoi thanh cong !";
			system("pause");
			break;
		case 5: {
			quit = true;
			break;
		}
		default:
			cout << "Lua chon khong hop le !" << endl;
		}
		break;
		}
	} while (!quit);
}
void Menu() {
	do {
		system("cls");
		cout << "============================" << endl;
		cout << "*CHON KIEU DU LIEU CAN DUNG*" << endl;
		cout << "1. Integer" << endl;
		cout << "2. Double" << endl;
		cout << "3. String" << endl;
		cout << "4. Sinh vien" << endl;
		cout << "5. Thoat" << endl;
		cout << "============================" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch) {
		case 1:
			Menu_Int();
			break;
		case 2:
			Menu_Double();
			break;
		case 3:
			Menu_String();
			break;
		case 4:
			Menu_SV();
		case 5:
			quit = true;
			break;
		default:
			cout << "Lua chon khong hop le !" << endl;
			break;
		}
	} while (!quit);
}
int main() {
	Menu();
	return 0;
}