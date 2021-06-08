#include <iostream>
using namespace std;

//  đề bài: nhập vào cây nhị phân các số nguyên
// Xuất ra màn hình các phần tử của cây nhị phân (NRL)
//  Khai báo cấu trúc 1 cái node
//  Tìm kiếm phần tử trong cây nhị phân 
//  Xóa node bất kì trong cây nhị phân(1 con, 2 con, lá) 
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

// Hàm tìm node thế mạng
void DiTimNodeTheMang(TREE& X, TREE& Y) //NODE Y chính là node thế mạng cho node cần xóa - node này sẽ đảm nhận nhiệm vụ tìm ra node trái nhất(TÌM NODE TRÁI NHẤT CÂY CON PHẢI) hoặc phải nhất (TÌM NODE PHẢI NHẤT CỦA CÂY CON TRÁI)
{
	//Duyệt sang bên trái nhất của cây con phải 
	if (Y->pLeft != NULL)
	{
		DiTimNodeTheMang(X, Y->pLeft); //Duyệt tìm ra node trái nhất 
	}
	else //Tìm ra được node trái nhất rồi 
	{
		X->data = Y->data; //Cập nhật cái data của node cần xóa chính là data của node thế mạng 
		X = Y;// cho node X(là node mà chúng ta sẽ đi xóa sau này) trỏ đến node thế mạng ==> ra khỏi hàm thì ta sẽ xóa node X
		Y = Y->pRight; // Bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(node mà chúng ta sẽ xóa) với node con của node thế mạng 
		// Y->pRight: NULL 
	}
}

// Hàm xóa 1 cái node bất kì trong cây nhị phân tìm kiếm 
void XoaNode(TREE& t, int data)// data chính là giá trị của cái node cần xóa 
{
	// nếu như cây rỗng
	if (t == NULL)
		return; // kết thúc hàm 
	else {
		// nếu như data nhỏ hơn node gốc 
		if (data < t->data)
		{
			XoaNode(t->pLeft, data); // Duyệt sang nhánh trái của cây 
		}
		else if (data > t->data)
		{
			XoaNode(t->pRight, data); // Duyệt sang nhánh phải của cây
		}
		else //  data == t->data - đã tìm ra cái node cần xóa 
		{
			NODE* X = t; // node X là node thế mạng - tí nữa chúng ta sẽ xóa nó 
			// Nếu như nhánh trái bằng NULL <=> đây là cây có 1 con chính là cây con phải 
			if (t->pLeft == NULL)
			{
				t = t->pRight; // duyệt sang phải của cái node cần xóa để cập nhật mối liên kết giữa node cha của node cần xóa với node con của node cần xóa 
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft; // duyệt sang trái của cái node cần xóa để cập nhật mối liên kết giữa node cha của node cần xóa với node con của node cần xóa 
			}
			else // node cần xóa là node có hai con
			{
				DiTimNodeTheMang(X, t->pRight);
			}
			delete X; //Xóa node cần xóa
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
		cout << "\n2.Xuat du lieu cay theo NRL";
		cout << "\n3.Tim kiem phan tu trong cay";
		cout << "\n4.Xoa phan tu trong cay";
		cout << "\n5.Ket thuc";
		cout << "\n\n\t\t =================================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 1 || luachon > 5)
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
		else if (luachon == 4)
		{
			cout << "\nNhap phan tu can xoa: ";
			int x; 
			cin >> x;
			XoaNode(t, x);
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