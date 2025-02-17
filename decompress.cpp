#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>

using namespace std;
class ctnode;
class cnode;
class cnode {
public:
	string l = "";
	int ct = 0;
	cnode* pnxt = NULL;
	ctnode* pdown = NULL;
	string bin = "";
};

class ctnode {
public:
	string l = "";
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
				cout << ptrav->l << " | " << ptrav->bin << endl;
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
	while (str1[i]) {
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
	ofstream myfile1("picture.jpg", ios::binary);
	ifstream enfile("enpicture.jpg", ios::binary);
	ifstream myfile3;
	myfile3.open("file3.txt");
	string mytext;
	string st = "";

	string dtxt = "";
	cnode* pnn;
	clist* list = new clist;
	int i;
	int c = 0;
	int h;
	int k = 0;
	pnn = new cnode;
	int zz = 0;
	char laa;
	int f = 0;
	int sze = 0;
	if (myfile3.is_open()) {
		cout << "File1 is open" << endl;
		while (getline(myfile3, mytext)) {
			k = 0;
			char xx;
			st = "";
			char m = 1;
			char x = 0;
			int l = 7;
			char ninaa;
			st = "";
			for (i = 0; i < mytext.length(); i++) {
				st += mytext[i];
				if (c % 2 == 0 || c == 0) {
					pnn = new cnode;
				}
				if (c % 2 == 0 || c == 0) {
					if (st[0] != '0' && st[0] != '1') {
						f = 1;
						st = "";

					}
					else {
						if (i == 0) {
							int ct = 0;
							x = 0;
							m = 1;
							for (i = 0; i < mytext.length(); i++) {
								ninaa = mytext[i];
								l = 7 - ct;
								if (ninaa == '1') {
									x = x | (m << l);
									ct += 1;

								}
								else {
									ct += 1;
								}
							}
							pnn->l = "";
							pnn->l = x;


						}
						st += mytext[i];
					}
				}
				if (c % 2 != 0) {
					if (f == 1) {
						i = 0;
						st = "";
						for (i = 0; i < mytext.length(); i++) {
							st += mytext[i];
						}
						f = 0;
						break;
					}
					else {
						if (i < mytext.length()) {
							pnn->bin += mytext[i];
						}if (i == mytext.length() - 1 && f != 1) {
							list->attach(pnn);
						}

					}

				}


			}
			c += 1;
		}
	}
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "count of each symbol" << endl;
	list->display();
	cout << "the size is ";
	sze = stoi(st);
	cout << sze << endl;

	//==============================================================================================================
	int lin = 7;
	char m = 1;
	char x;
	int r = 0;
	int y = 0, p = 0;
	char g = 0;
	myfile1.is_open();
	enfile.clear();
	enfile.seekg(0, enfile.beg);

	i = 8;
	char ch;

	pnn = list->phead;
	if (enfile.is_open()) {
		enfile.clear();
		enfile.seekg(0, myfile1.beg);
		char t;

		while (enfile.get(t)) {
			for (i = 7; i >= 0; i--) {
				x = t & (m << i);
				pnn = list->phead;

				if (x != 0) {
					dtxt += "1";

				}
				if (x == 0) {
					dtxt += "0";

				}


				while (pnn != NULL) {
					if (pnn->bin == dtxt) {

						//cout << pnn->bin << endl;
						myfile1 << pnn->l;
						dtxt = "";
						k += 1;
						//cout << k << endl;
						break;


					}
					pnn = pnn->pnxt;
				}
				pnn = list->phead;

				if (k == sze) {
					break;
				}

			}
			if (k == sze) {

				break;
			}

		}
	}

	cout << "done" << endl;
	cout << "+===================================================================================" << endl;





	delete list;
	return 0;
}