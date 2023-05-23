#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#define M 101
using namespace std;
struct Word {
	string word;
	string type; 
	string mean;
};

struct DictNode {
	Word word;
	DictNode* next;
};

void init(DictNode* heads[]) {
	for (int i = 0; i < M; i++)
		heads[i] = NULL;
}

int hashFunc(Word w) {
	int h = 0;
	for (int i = 0; i < w.word.length(); i++) {
		h += (int)tolower(w.word[i]) * (i + 1);
	}
	return h % M;
}

DictNode* createWord(Word w) {
	DictNode *word = new DictNode;
	word->word = w;
	word->next = NULL;
	return word;
}

void addWord(DictNode* heads[], Word w) {
	int h = hashFunc(w);
	DictNode* r = heads[h];
	DictNode* p = createWord(w);
	if (r == NULL) // them dau
		heads[h] = p;
	else { // them cuoi
		int t = hashFunc(r->word);
		while (r->next != NULL) {
			t = hashFunc(r->word);
			// Chi them khi cac tu khac nhau
			if (t==h)
				break;
			else
			r = r->next;
		}
		if(t!=h)
			r->next = p;
	}
}

void updateWord(DictNode* heads[], Word w) {
	int h = hashFunc(w);
	DictNode* r = heads[h];
	if (r != NULL) {
		int t = hashFunc(r->word);
		do {
			t = hashFunc(r->word);
			// Chi them khi cac tu khac nhau
			if (t == h) {
				r->word= w;
				break; // Ket thuc
			}
			r = r->next;
		} while (r != NULL);
	}
}

void display(DictNode* heads[]) {
	for (int i = 0; i < M; i++) {
		if (heads[i] != NULL) {
			cout << "====BUCKET " << i << "====" << endl;
			DictNode* p = heads[i];
			while (p != NULL) {
				cout << p->word.word << " (" << p->word.type << "): " << p->word.mean << endl;
				p = p->next;
			}
		}
	}
}

int main() {
	cout << "TU DIEN: \n";
	Word w1, w2, w3,w4,w6;
	w1.word = "hello";
	w1.type = "V";
	w1.mean = "Xin chao";
	w2.word = "Teacher";
	w2.type = "n";
	w2.mean = "Giao vien";
	w3.word = "Good";
	w3.type = "adj";
	w3.mean = "Tot";
	w4.word = "great";
	w4.type = "adj";
	w4.mean = "Tot";

	w6.word = "teacher";
	w6.type = "n";
	w6.mean = "Giang vien";

	DictNode* dicts[M];
	init(dicts);

	addWord(dicts, w1);
	addWord(dicts, w2);
	addWord(dicts, w3);
	addWord(dicts, w4);


	display(dicts);

	cout << "==UPDATE==" << endl;
	updateWord(dicts, w6);
	display(dicts);
	return 0;
}