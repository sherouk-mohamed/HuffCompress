#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>

using namespace std;
class ctnode;
class cnode;
class cnode {
public:
	string l="";
	int ct = 0;
	cnode* pnxt = NULL;
	ctnode* pdown = NULL;
	string bin;
};

class ctnode {
public:
	string l="";
	int ct = 0;
	cnode* pleft = NULL;
	cnode* pright = NULL;
};

class clist {

public:

	cnode* phead;
	cnode* ptail;
	clist() {
		phead = NULL;
		ptail = NULL;
	}

	~clist() {
		cnode* ptrav = phead;
		while (phead != NULL) {
			phead = ptrav->pnxt;
			ptrav->pnxt = NULL;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cnode* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			ptail->pnxt = pnn;
			ptail = pnn;
		}
	}
	void insert(cnode* pnn) {
		if (phead == NULL) {
			phead = pnn;
		}
		else {
			cnode* pb = NULL;
			cnode* ptrav = phead;

			while (ptrav != NULL && ptrav->ct < pnn->ct) {
				pb = ptrav;
				ptrav = ptrav->pnxt;
			}
			if (pb != NULL) {
				pb->pnxt = pnn;
				pnn->pnxt = ptrav;
			}
			else {
				phead = pnn;
				pnn->pnxt = ptrav;
			}

		}
	}

	int visited(cnode*& pnn) {
		cnode* ptrav = phead;
		while (ptrav) {
			if (ptrav->l == pnn->l) {
				ptrav->ct += 1;
				return 1;
			}
			ptrav = ptrav->pnxt;
		}

		return 0;
	}

	void display() {

		if (phead == NULL) {
			cout << "emptyyy";
		}
		cnode* ptrav;
		ptrav = phead;
		if (ptrav != NULL) {
			while (ptrav != NULL) {
				cout << ptrav->l << ptrav->ct << endl;
				ptrav = ptrav->pnxt;
			}

		}

		cout << endl;
	}
	void diswrds() {

		if (phead == NULL) {
			cout << "emptyyy";
		}
		cnode* ptrav;
		ptrav = phead;
		if (ptrav != NULL) {
			while (ptrav != NULL) {
				cout << ptrav->l;
				ptrav = ptrav->pnxt;
			}

		}

		cout << endl;
	}

	



};

void disptree(cnode* ptrav) {

	if (ptrav == NULL) {
		return;
	} 
	if (ptrav->pdown != NULL) {
		disptree(ptrav->pdown->pleft);
		cout << ptrav->l << "..." << ptrav->ct << endl;
		disptree(ptrav->pdown->pright);
	}
	else {
		cout << ptrav->l << "..." << ptrav->ct << endl;
	}


}

int compstrngs(string str1, string str2) {

	if (str1 == str2) {
		return 1;
	}
	else {
		return 0;

	}

}
void conbin(cnode* ptrav, string st, clist*& list) {
	if (ptrav == NULL) {
		return;
	}
	if (ptrav->pdown == NULL) {

		ptrav->bin = st;
		int i = 0;
		cnode* cppp = new cnode;

		cppp->l = ptrav->l;
		cppp->bin = st;
		cppp->ct = ptrav->ct;
		list->insert(cppp);
		cout << ptrav->l << "|" << ptrav->ct << "|" << ptrav->bin << endl;


	}
	if (ptrav->pdown != NULL) {

		conbin(ptrav->pdown->pleft, st + "0", list);
		conbin(ptrav->pdown->pright, st + "1", list);
	}
}
void bit_dis(char val)
{
	int i;
	int size = 2 * sizeof(int);
	unsigned int mask = 1 << size - 1;
	cout << ":::";
	printf("%-10d=", val);

	for (i = 0; i < size; i++)
	{
		(val & mask) ? putchar('1') : putchar('0');
		mask = mask >> 1;
	}
}
int compstr(string str1, string str2) {
	int i = 0;
	while (str1[i] ) {
		if (str1[i] == str2[i]) {
			i += 1;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int main() {
	string ltt = "";
	ifstream myfile1("picture.bmp", ios::binary);
	myfile1.clear();
	ofstream enfile("enpicture.jpg", ios::binary);
	ofstream myfile3;
	myfile3.open("file3.txt");
	string mytext;
	string st = "";

	string etxt = "";
	string dtxt = "";
	cnode* pnn;
	cnode* spnn;
	cnode* cpnn;
	ctnode* fpnn;
	clist* list = new clist;
	clist* cplist = new clist;
	clist* tree = new clist;
	clist* dclist = new clist;
	int i = 0;
	myfile1.seekg(0, ios::end);
	int h = static_cast<int>(myfile1.tellg());
	myfile1.clear();
	myfile1.seekg(0, myfile1.beg);

	myfile3.is_open();
	char t;
	if (myfile1.is_open()) {
		cout << "File1 is open" << endl;
		for (i = 0; i < h; i++) {
			   myfile1.read(&t, 1);

				pnn = new cnode;
				pnn->ct += 1;
				pnn->l += t;

				if (list->visited(pnn) == 0) {
					list->attach(pnn);
				}
				else {
					delete pnn;
				}

			
		}
	}
	cout << "count of each symbol" << endl;
	list->display();

	pnn = list->phead;
	while (pnn != NULL) {
		cpnn = new cnode;
		cpnn->ct = pnn->ct;
		cpnn->l = pnn->l;
		tree->insert(cpnn);
		pnn = pnn->pnxt;
	}
	cout << "count of each symbol but sorted" << endl;
	tree->display();

	pnn = tree->phead;
	spnn = pnn->pnxt;
	i = 0;
	int r = 0;

	while (spnn != NULL) {
		i = 0;
		r = 0;
		tree->phead = spnn->pnxt;
		cpnn = new cnode;
		fpnn = new ctnode;
		cpnn->ct = pnn->ct + spnn->ct;
		cpnn->l = pnn->l + spnn->l;
		fpnn->l = pnn->l + spnn->l;
		fpnn->pleft = pnn;
		cpnn->pnxt = spnn->pnxt;
		fpnn->pright = spnn;
		spnn->pnxt = NULL;
		pnn->pnxt = NULL;
		cpnn->pdown = fpnn;
		tree->insert(cpnn);
		pnn = tree->phead;
		spnn = pnn->pnxt;
	}

	tree->display();
	cout << "Huffman Tree:" << endl;

	disptree(tree->phead);

	cout << "Binary Codes:" << endl;
	int xx;
	char b;

	conbin(tree->phead, st, cplist);
	cpnn = cplist->phead;
	char sh = 1;
	char la = 0;
	int ke;
	while (cpnn != NULL) {
		b = cpnn->l[0];
		for (ke = 7; ke >= 0; ke--) {
			la = 0;
			la = b & (sh << ke);

			if (la != 0) {
				myfile3 << 1;
			}
			if (la == 0) {
				myfile3 << 0;

			}
		}


			myfile3 << endl;
			myfile3 << cpnn->bin << endl;

			cpnn = cpnn->pnxt;
	}
		//=================================================================================================

		int ctll = 0;
		cpnn = cplist->phead;
		r = 0;
		char m = 1;
		char x = 0;
		int ct = 0, lin;

		cout << "File size: " << h << " bytes" << endl;
		myfile3 << "size"<< endl;
		myfile3 << h << endl;
		myfile1.clear();
		myfile1.seekg(0, myfile1.beg);
		char ch;
		i = 0;
		int k = 0;
		if (enfile.is_open()) {
			cout << "File2 is open " << endl;

			if (myfile1.is_open()) {
				cout << "File1 is open agaaain " << endl;
				for (k = 0; k < h; k++) {
				     	myfile1.read(&ch, 1);

						cpnn = cplist->phead;
						while (cpnn != nullptr && cpnn->l[0] != ch) {
							cpnn = cpnn->pnxt;
						}

						if (cpnn != NULL) {
							for (r = 0; r < cpnn->bin.length(); r++) {
								lin = 7 - ct;
								if (cpnn->bin[r] == '1') {
									x = x | (m << lin);
									ct += 1;

								}
								else {
									ct += 1;
								}
								if (ct == 8) {
									enfile.write(&x, 1);
									etxt += x;
									ct = 0;
									x = 0;
								}
							}

						}
						i += 1;


					


				}


			}

			if (ct < 8) {
				enfile.write(&x, 1);
				etxt += x;
			}
		}
		myfile1.close();
		enfile.close();


		delete list;
		delete dclist;
		delete cplist;
		delete tree;
		return 0;
	}