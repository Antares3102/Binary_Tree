#include <iostream>
using namespace std;

// Đề bài: nhập vào cây nhị phân các số nguyên. Xuất ra màn hình các phân tử của cây nhị phân (NLR & NRL)
// Lập Menu Output(OOP)
// Khai báo cấu trúc 1 cái node
struct node
{
	int data;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

// Khởi tạo cây 
void KhoiTaoCay(TREE& t)
{
	t = NULL;
}

// Hàm thêm phần tử x vào cây nhị phân 
void ThemNodeVaoCay(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x);
		}
		else if (t->data < x)
		{
			ThemNodeVaoCay(t->pRight, x);
		}
	}
}

// Hàm xuất cây nhị phân theo NLR
void Duyet_NLR(TREE t)
{

	if (t != NULL)
	{
		cout << t->data << " ";
		Duyet_NLR(t->pLeft);
		Duyet_NLR(t->pRight);
	}
}

// Hàm xuất cây nhị phân theo NRL
void Duyet_NRL(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		Duyet_NRL(t->pRight);
		Duyet_NRL(t->pLeft);
	}
}

// Hàm xuất cây nhị phân theo LNR
void Duyet_LNR(TREE t)
{
	if (t != NULL)
	{
		Duyet_LNR(t->pLeft);
		cout << t->data << " ";
		Duyet_LNR(t->pRight);
	}
}

// Hàm xuất cây nhị phân theo RNL
void Duyet_RNL(TREE t)
{
	if (t != NULL)
	{
		Duyet_RNL(t->pRight);
		cout << t->data << " ";
		Duyet_RNL(t->pLeft);
	}
}

// Hàm xuất cây nhị phân theo LRN
void Duyet_LRN(TREE t)
{
	if (t != NULL)
	{
		Duyet_LRN(t->pLeft);
		Duyet_LRN(t->pRight);
		cout << t->data << " ";
	}
}

// Hàm xuất cây nhị phân theo RLN
void Duyet_RLN(TREE t)
{
	if (t != NULL)
	{
		Duyet_RLN(t->pRight);
		Duyet_RLN(t->pLeft);
		cout << t->data << " ";
	}
}


// Hàm nhập dữ liệu 
void Menu(TREE& t)
{
	int flag;
	do {
		cout << "\n\n\t\t ============== MENU ============= ";
		cout << "\n1.Nhap du lieu";
		cout << "\n2.Xuat du lieu cay theo NLR";
		cout << "\n3.Xuat du lieu cay theo NRL";
		cout << "\n4.Xuat du lieu cay theo LNR";
		cout << "\n5.Xuat du lieu cay theo RNL";
		cout << "\n6.Xuat du lieu cay theo LRN";
		cout << "\n7.Xuat du lieu cay theo RLN";
		cout << "\n8.Ket thuc";
		cout << "\n\n\t\t =================================";
		cout << "\nNhap lua chon cua ban: ";
		cin >> flag;

		if (flag < 1 || flag > 8)
		{
			do {
				cout << "\nLua chon khong hop le\n";
				system("pause");
				cout << "\nNhap lua chon cua ban: ";
				cin >> flag;
			} while (flag < 1 || flag > 8);
		}

		switch (flag)
		{
		case 1:
		{
			int n;
			cout << "\nNhap so luong so nguyen muon nhap vao: ";
			cin >> n;
			int* x = new int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "\nNhap so nguyen thu " << i + 1 << " :";
				cin >> x[i];
				ThemNodeVaoCay(t, x[i]);
			}
			delete[] x;
			break;
		}

		case 2:
		{
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			Duyet_NLR(t);
			cout << endl;
			system("pause");
			break;
		}

		case 3:
		{
			cout << "\n\t\t DUYET CAY THEO NRL\n";
			Duyet_NRL(t);
			cout << endl;
			system("pause");
			break;
		}

		case 4:
		{
			cout << "\n\t\t DUYET CAY THEO LNR\n";
			Duyet_LNR(t);
			cout << endl;
			system("pause");
			break;
		}

		case 5: 
		{
			cout << "\n\t\t DUYET CAY THEO RNL\n";
			Duyet_RNL(t);
			cout << endl;
			system("pause");
			break;
		}

		case 6:
		{
			{
				cout << "\n\t\t DUYET CAY THEO LRN\n";
				Duyet_LRN(t);
				cout << endl;
				system("pause");
				break;
			}
		}

		case 7: 
		{
			{
				cout << "\n\t\t DUYET CAY THEO RLN\n";
				Duyet_RLN(t);
				cout << endl;
				system("pause");
				break;
			}
		}

		case 8:
		{
			cout << "\nKet thuc chuong trinh!";
			cout << endl;
			system("pause");
			break;
		}
		}
	} while (flag != 8);
}

int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);
	return 0;
}

