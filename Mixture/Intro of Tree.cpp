#include <iostream>
using namespace std;

//  đề bài: nhập vào cây nhị phân các số nguyên
//  Khai báo cấu trúc 1 cái node

struct node
{
	int data; // dữ liệu của node ==>dữ liệu của noi=de sẽ lưu trữ
	struct node* pLeft;//node liên kết bên trái của cây <=> cây con trái
	struct node* pRight;//node liên kết bên phải của cây <=> cây con phải
};
typedef struct node NODE;// Thay thế cấu trúc node bằng NODE
typedef NODE* TREE;// Thay thế NODE* bằng TREE

//  Khởi tạo cây
void KhoiTaoCay(TREE& t)
{
	t = NULL; //Cây rỗng 
}

//Hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE& t, int x)
{
	// Nếu như cây rỗng
	if (t == NULL)
	{
		NODE* p = new NODE; // Khởi tạo 1 cái node để thêm vào cây
		p->data = x; //Thêm dữ liệu x vào data 
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p chính là node gốc <=> x chính là node gốc
	}
	else //Cây có tồn tại phần tử 
	{
		//Nếu phần tử thêm vào mà nhỏ hơn node gốc ==> thêm nó vào bên trái 
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x);//Duyệt qua trái để thêm phần tử x
		}
		else if (t->data < x) //Nếu phần tử thêm vào mà lớn hơn node gốc ==> thêm nó vào bên phải 
		{
			ThemNodeVaoCay(t->pRight, x);//Duyệt qua bên phải để thêm phần tử x
		}
	}
}

// Hàm nhập dữ liệu
void Menu(TREE& t)
{
	while (true)
	{
		cout << "\n\n\t\t ============== MENU ============= ";
		cout << "\n1.Nhap du lieu";
		cout << "\n2.Ket thuc";
		cout << "\n\n\t\t =================================";
		
		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 2)
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