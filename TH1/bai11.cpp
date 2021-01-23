#include<iostream>
#include<cmath>
using namespace std;
class PS {
private:
	float t, m;
public:
	PS();
	PS(float, float);
	PS(const PS&);
	~PS();
	float getT();
	float getM();
	void nhap();
	void xuat();
	PS RutGon();
	PS operator=(PS);
	friend int UCLN(int,int);
	friend bool operator>(PS, PS);
};
PS::PS() {
	t = m = 0;
}
PS::PS(float a, float b) {
	t = a;
	m = b;
}
PS::PS(const PS& x) {
	t = x.t;
	m = x.m;
}
PS::~PS() {}
void PS::nhap() {
	cout << "Nhap tu so: ";
	cin >> t;
	do {
		cout << "Nhap mau so: ";
		cin >> m;
	} while (m == 0);
}
void PS::xuat() {
	if (m == 1)
		cout << t;
	else if (m == -1)
		cout << t * (-1);
	else {
		if (t == 0)
			cout << t;
		else
			cout << t << "/" << m;
	}
	cout << endl;
}
int UCLN(int a,int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
PS PS::RutGon() {
	return PS(t / (float)UCLN(t,m), m / (float)UCLN(t, m));
}
float PS::getM() {
	return m;
}
float PS::getT() {
	return t;
}
bool operator>(PS a, PS b) {
	if (a.getT() / a.getM() > b.getT() / b.getM())
		return true;
	return false;
}
PS PS::operator=(PS a) {
	t = a.t;
	m = a.m;
	return PS(t, m).RutGon();
}
void swap(PS& a, PS& b) {
	PS temp = a;
	a = b;
	b = temp;
}
int main() {
	PS x[5];
	for (int i = 0; i < 5; i++) {
		cout << "Phan so " << i + 1 << ": " << endl;
		x[i].nhap();
		
	}
	for (int i = 0; i < 5; i++) {
		x[i].RutGon().xuat();
	}
}