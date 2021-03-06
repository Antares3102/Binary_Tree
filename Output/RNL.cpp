#include <iostream>
using namespace std;

//  đề bài: nhập vào cây nhị phân các số nguyên. Xuất ra màn hình các phần tử của cây nhị phân (RNL)
//  Khai báo cấu trúc 1 cái node
struct node
{
	int data;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

//  Khởi tạo cây
void KhoiTaoCay(TREE& t)
{
	t = NULL;
}

//Hàm thêm phần tử x vào cây nhị phân
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

// Hàm nhập dữ liệu
void Menu(TREE& t)
{
	while (true)
	{
		cout << "\n\n\t\t ============== MENU ============= ";
		cout << "\n1.Nhap du lieu";
		cout << "\n2.Xuat du lieu cay theo RNL";
		cout << "\n3.Ket thuc";
		cout << "\n\n\t\t =================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 3)
		{
			cout << "\nLua chon khong hop le\n";
			system("pause");
		}
		else if (luachon == 1)
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
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t DUYET CAY THEO RNL\n";
			Duyet_RNL(t);
			cout << endl;
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);
	return 0;
}