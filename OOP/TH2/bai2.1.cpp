#include<iostream>
#include<string>

using namespace std;
class MyAttr {
protected:
	int SoHieu;
public:
	MyAttr();
	~MyAttr();
};
class Mydate {
protected:
	int d, m, y;
public:
	Mydate();
	~Mydate();
	bool operator > (Mydate);
	void xuat();
};
class Myfile :public MyAttr, public Mydate {
private:
	string filename;
	int filesize;
public:
	Myfile();
	~Myfile();
	void nhap();
	void xuat();
	int getMonth() {
		return m;
	}
};
MyAttr::MyAttr() {
	SoHieu = 0;
}
MyAttr::~MyAttr(){}
Mydate::Mydate() {
	d = m = y = 0;
}
Mydate::~Mydate(){}
bool Mydate::operator>(Mydate x) {
	if (y < x.y) {
		if (m < x.m) {
			if (d < x.d) {
				return true;
			}
		}
	}
	return false;
}
void Mydate::xuat() {
	cout << d << "-" << m << "-" << y << endl;
}
Myfile::Myfile() {
	filename = "";
	filesize = 0;
}
Myfile::~Myfile(){}
void Myfile::nhap() {
	do {
		cout << "Name: ";
		getline(cin, filename);
	} while (filename.length() > 255);
	cout << "Size: ";
	cin >> filesize;
	cout << "Ngay thang nam: ";
	cin >> d >> m >> y;
	cout << "So Hieu: ";
	cin >> SoHieu;
	cin.ignore(1);
}
void Myfile::xuat() {
	cout << endl << "Ten: " << filename;
	cout << endl << "Kich thuoc: " << filesize;
	cout << endl;
	Mydate::xuat();
	cout << "So hieu: " << SoHieu << endl;
}
void swap(Myfile *a, Myfile *b) {
	Myfile t = *a;
	*a = *b;
	*b = t;
}
int main() {
	Myfile* x = new Myfile[4];
	for (int i = 0; i < 4; i++) {
		x[i].nhap();
	}
	Myfile *val=new Myfile;
	int j;
	for (int i = 1; i < 4; i++) {
		j = i - 1;
		*val = *(x+i);
		while (j >= 0 && val->getMonth() > (x + j)->getMonth()) {
			*(x+j+1) = *(x+j);
			j--;
		}
		*(x + j + 1)= *val;
	}
	for (int i = 0; i < 4; i++) {
		(x+i)->xuat();
	}
	delete val;
}