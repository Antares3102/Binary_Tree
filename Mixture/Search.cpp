#include <iostream>
using namespace std;

//  đề bài: nhập vào cây nhị phân các số nguyên
// Xuất ra màn hình các phần tử của cây nhị phân (NRL)
//  Khai báo cấu trúc 1 cái node
//  Tìm kiếm phần tử trong cây nhị phân 
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

// Hàm xuất cây nhị phân theo NRL
void Duyet_NRL(TREE t)
{
	// Nếu cây còn phần tử thì tiếp tục duyệt 
	if (t != NULL)
	{
		cout << t->data << " "; //Xuất dữ liệu trong node
		Duyet_NRL(t->pRight); //Duyệt qua phải
		Duyet_NRL(t->pLeft); //Duyệt qua trái
	}
}

// Nếu node có tồn tại trong cây thì trả về cái node đó - còn không tồn tại thì trả về NULL
NODE* TimKiem(TREE t, int x)
{
	//Nếu cây rỗng 
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		//Nếu phần từ cần tìm nhỏ hơn node gốc thì duyệt(đệ quy) sang bên trái
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data)
		{
			TimKiem(t->pRight, x);
		}
		else // t->data == x
			return t;
	}
}

// Hàm nhập dữ liệu
void Menu(TREE& t)
{
	while (true)
	{
		cout << "\n\n\t\t ============== MENU ============= ";
		cout << "\n1.Nhap du lieu";
		cout << "\n2.Xuat du lieu cay theo NRL";
		cout << "\n3.Tim kiem phan tu trong cay";
		cout << "\n4.Ket thuc";
		cout << "\n\n\t\t =================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 1 || luachon > 4)
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
			cout << "\n\t\t DUYET CAY THEO NRL\n";
			Duyet_NRL(t);
			cout << endl;
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap phan tu can tim kiem: ";
			cin >> x;
			NODE* p = TimKiem(t, x);
			if (p == NULL)
				cout << "\nPhan tu " << x << " khong ton tai trong cay\n";
			else 
				cout << "\nPhan tu " << x << " co ton tai trong cay\n";
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