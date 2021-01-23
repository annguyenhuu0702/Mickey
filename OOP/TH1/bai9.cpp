#include<iostream>
using namespace std;
class Mydate {
private:
	int d, m, y;
public:
	Mydate();
	Mydate(int, int, int);
	Mydate(const Mydate&);
	~Mydate();
	void Input();
	void Output();
	bool operator>(Mydate);
};
Mydate::Mydate() {
	d = m = y = 0;
}
Mydate::Mydate(int a, int b, int c) {
	d = a;
	m = b;
	y = c;
}
Mydate::Mydate(const Mydate& x) {
	d = x.d;
	m = x.m;
	y = x.y;
}
Mydate::~Mydate() {}
void Mydate::Input() {
	cout << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
}
void Mydate::Output() {
	cout << endl << d << "-" << m << "-" << y;
}
bool Mydate::operator>(Mydate a) {
	if (a.y > y) {
		return true;
	}
	else if (y > a.y) {
		return false;
	}
	else {
		if (a.m > m) {
			return true;
		}
		else if (m > a.m) {
			return false;
		}
		else {
			if (a.d > d) {
				return true;
			}
			else if (d > a.d) {
				return false;
			}
		}
	}
}
int main() {
	int n;
	cout << "So luong ngay: ";
	cin >> n;
	Mydate *date=new Mydate[n];
	for (int i = 0; i < n; i++) {
		cout << "Input date " << i + 1 << endl;
		date[i].Input();
		date[i].Output();
		cout << endl;
	}
	cout << endl << "Xuat tang dan: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (date[i] > date[j]) {
				Mydate temp = date[i];
				date[i] = date[j];
				date[j] = temp;
			}
		}
		date[i].Output();
		cout << endl;
	}
	
}