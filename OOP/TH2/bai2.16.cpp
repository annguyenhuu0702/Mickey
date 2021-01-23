#include<iostream>
#include<string>

using namespace std;

class Mydate {
protected:
	int d, m, y;
public:
	Mydate();
	~Mydate();
	bool operator > (Mydate);
	void nhapdate();
	void xuatdate();
};

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
void Mydate::nhapdate(){
	cout<<"Ngay sinh: ";
	cin>>d>>m>>y;
	cin.ignore(1);
}
void Mydate::xuatdate() {
	cout << endl<<d << "-" << m << "-" << y;
}
class MyAddress{
	protected:
		string tinh,huyen;
	public:
		MyAddress();
		~MyAddress();
		void nhapAdd();
		void xuatAdd();
};
MyAddress::MyAddress(){
	tinh=huyen="";
}
MyAddress::~MyAddress(){}
void MyAddress::nhapAdd(){
	cout<<"Tinh: ";
	getline(cin,tinh);
	cout<<"Huyen: ";
	getline(cin,huyen);
}
void MyAddress::xuatAdd(){
	cout<<endl<<"Tinh: "<<tinh;
	cout<<endl<<"Huyen: "<<huyen;
}
class Person:public MyAddress,public Mydate{
	protected:
		string ten,sdt;
	public:
		Person();
		~Person();
		void nhapP();
		void out();
};
Person::Person(){
	Person::MyAddress();
	Person::Mydate();
	ten=sdt="";
}
Person::~Person(){}
void Person::nhapP(){
	cout<<"Ten: ";
	getline(cin,ten);
	Person::nhapdate();
	Person::nhapAdd();
	cout<<"SDT: ";
	getline(cin,sdt);
}
void Person::out(){
	cout<<endl<<"Ten: ";
	cout<<ten;
	Person::xuatdate();
	Person::xuatAdd();
	cout<<endl<<"SDT: ";
	cout<<sdt;
}
void swap(Person &a, Person &b) {
	Person t = a;
	a = b;
	b = t;
}
int main() {
	Person *p=new Person[4];
	for(int i=0;i<4;i++){
		(p+i)->nhapP();
	}
	for(int i=0;i<3;i++){
		for(int j=i+1;j<4;j++){
			if(*(p+i)>*(p+j))
				swap(*(p+i),*(p+j));
		}
	}
	cout<<endl<<"########xuat####";
	for(int i=0;i<4;i++){
		(p+i)->out();
		cout<<endl;
	}
}