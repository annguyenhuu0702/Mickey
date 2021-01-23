#include<iostream>
using namespace std;
class Vector {
private:
	int n;
	float* v;
public:
	Vector(int);
	Vector(const Vector&);
	~Vector();
	void nhap();
	void xuat();
	Vector operator=(Vector);
	bool ktPT(Vector);
	friend Vector operator+(Vector, Vector);
};
Vector::Vector(int n) {
	this->n = n;
	v = new float[this->n];
	for (int i = 0; i < n; i++)
		v[i] = 0;
}
Vector::Vector(const Vector& x) {
	n = x.n;
	v = new float[n];
	for (int i = 0; i < n; i++)
		v[i] = x.v[i];
}
Vector::~Vector() {}
void Vector::nhap() {
	for (int i = 0; i < n; i++) {
		cout << "Phan tu " << i << ": ";
		cin >> *(v + i);
	}
}
void Vector::xuat() {
	cout << "(";
	for (int i = 0; i < n; i++) {
		cout << v[i];
		if (i == n - 1) {
			cout << ")";
			break;
		}
		cout << " ; ";
	}
	cout << endl;
}
Vector Vector::operator=(Vector a) {
	return a;
}
bool Vector::ktPT(Vector a) {
	if (n == a.n)
		return true;
	return false;
}
Vector operator+(Vector a, Vector b) {
	int n_ = (a.n >= b.n) ? a.n : b.n;
	Vector c(n_);
	for (int i = 0; i < n_; i++) {
		if (i == a.n)
			c.v[i] = b.v[i];
		else if (i == b.n)
			c.v[i] = a.v[i];
		else
			c.v[i] = a.v[i] + b.v[i];
	}
	return c;
}
int main() {
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	Vector a(n);
	a.nhap();
	a.xuat();
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	Vector b(n);
	b.nhap();
	b.xuat();
	if (a.ktPT(b)) {
		cout << "2 vector a,b cung phan tu" << endl;
		cout << "Tong 2 vector: " << endl;
		(a + b).xuat();
	}
	else
		cout << "2 vector a,b khong cong duoc voi nhau";
	
	
}