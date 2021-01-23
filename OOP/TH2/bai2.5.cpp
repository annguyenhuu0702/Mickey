#include<iostream>
#include<string>
using namespace std;
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
class Person:public MyAddress{
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
	ten=sdt="";
}
Person::~Person(){}
void Person::nhapP(){
	cout<<"Ten: ";
	getline(cin,ten);
	Person::nhapAdd();
	cout<<"SDT: ";
	getline(cin,sdt);
}
void Person::out(){
	cout<<endl<<"Ten: ";
	cout<<ten;
	Person::xuatAdd();
	cout<<endl<<"SDT: ";
	cout<<sdt;
}
class Officer:public Person{
	private:
		float Salary;
	public:
		Officer();
		~Officer();
		void nhapO();
		void outO();
		bool operator>(Officer);
};
Officer::Officer(){
	Officer::Person();
	Salary=0;
}
Officer::~Officer(){}
void Officer::nhapO(){
	Officer::nhapP();
	cout<<"Luong: ";
	cin>>Salary;
	cin.ignore(1);
}
void Officer::outO(){
	Officer::out();
	cout<<endl<<"Luong: ";
	cout<<Salary;
}
bool Officer::operator>(Officer x){
	if(Salary>x.Salary)
		return true;
	return false;
}
void swap(Officer &x, Officer &y){
	Officer t=x;
	x=y;
	y=t;
}
int main(){
	Officer *x=new Officer[4];
	int min;
	for(int i=0;i<4;i++){
		(x+i)->nhapO();
	}
	cout<<endl<<"#################";
	for(int i=0;i<4;i++){
		min=i;
		for(int j=i+1;j<4;j++){
			if(*(x+min)>*(x+j)){
				min=j;	
			}
		}
		swap(*(x+min),*(x+i));
	}
	for(int i=0;i<4;i++){
		(x+i)->outO();
		cout<<endl;
	}
}