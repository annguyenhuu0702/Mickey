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
	friend void operator*(Vector, float);
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
void operator*(Vector a, float k) {
	for (int i = 0; i < a.n; i++) {
		a.v[i] = a.v[i] * k;
	}
	a.xuat();
}
int main() {
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	Vector a(n);
	a.nhap();
	a.xuat();
	float k;
	cout << "Nhap k: ";
	cin >> k;
	cout<<"k.a = ";
	a * k;
}