#include<iostream>
using namespace std;
class Mytime {
private:
	int s, m, h;
public:
	Mytime();
	Mytime(int, int, int);
	Mytime(const Mytime&);
	~Mytime();
	void Input();
	void Output();
	friend bool operator>=(Mytime,Mytime);
};
Mytime::Mytime() {
	s = m = h = 0;
}
Mytime::Mytime(int a, int b, int c) {
	h = a;
	m = b;
	s = c;
}
Mytime::Mytime(const Mytime& x) {
	h = x.h;
	m = x.m;
	s = x.s;
}
Mytime::~Mytime() {}
void Mytime::Input() {
	cout << "Hour: ";
	cin >> h;
	cout << "Minute: ";
	cin >> m;
	cout << "Second: ";
	cin >> s;
}
void Mytime::Output() {
	cout << endl << h << ":" << m << ":" << s;
}
bool operator>=(Mytime a,Mytime b) {
	if (a.h >= b.h) {
		return true;
	}
	else if (b.h >= a.h) {
		return false;
	}
	else {
		if (a.m >= b.m) {
			return true;
		}
		else if (b.m >= a.m) {
			return false;
		}
		else {
			if (a.s >= b.s) {
				return true;
			}
			else if (b.s >= a.s) {
				return false;
			}
		}
	}
}
int main() {
	Mytime time[5];
	for (int i = 0; i < 5; i++) {
		cout << "Input time " << i + 1 << endl;
		time[i].Input();
		time[i].Output();
		cout << endl;
	}
	int max=0,min=0;
	for(int i=1;i<5;i++){
		if(time[i]>=time[max])
			max=i;
		if(time[min]>=time[i])
			min=i;
	}
	cout<<endl<<"time MIN: ";
	time[min].Output();
	cout<<endl<<"time MAX: ";
	time[max].Output();
}