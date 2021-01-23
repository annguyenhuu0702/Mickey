#include<iostream>
#include<string>
using namespace std;
class Mydate{
	protected:
		int d,m,y;
	public:
		Mydate();
		Mydate(int , int ,int);
		~Mydate();
		void nhapdate();
		void outdate();
		bool operator>(Mydate);
		Mydate getdate();
};
Mydate::Mydate(){
	d=m=y=0;
}
Mydate::Mydate(int a, int b, int c){
	d=a;
	m=b;
	y=c;
}
Mydate::~Mydate(){}
Mydate Mydate::getdate(){
	return Mydate(d,m,y);
}
void Mydate::nhapdate(){
	cout<<"Ngay thang nam sinh: ";
	cin>>d>>m>>y;
	cin.ignore(1);
}
void Mydate::outdate(){
	cout<<endl<<d<<"-"<<m<<"-"<<y;
}
bool Mydate::operator>(Mydate x){
	if(y<x.y){
		if(m<x.m){
			if(d<x.d){
				return true;
			}
		}
	}
	return false;
}
class Person:public Mydate{
	protected:
		string ten,diachi,sdt;
	public:
		Person();
		~Person();
		void nhapP();
		void out();
};
Person::Person(){
	Person::Mydate();
	ten=diachi=sdt="";
}
Person::~Person(){}
void Person::nhapP(){
	cout<<"Ten: ";
	getline(cin,ten);
	Person::nhapdate();
	cout<<"Dia chi: ";
	getline(cin,diachi);
	cout<<"SDT: ";
	getline(cin,sdt);
}
void Person::out(){
	cout<<endl<<"Ten: ";
	cout<<ten;
	Person::outdate();
	cout<<endl<<"Dia chi: ";
	cout<<diachi;
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
void swap(Officer &x, Officer &y){
	Officer t=x;
	x=y;
	y=t;
}
int main(){
	Officer *x=new Officer[4];
	bool k=false;
	for(int i=0;i<4;i++){
		(x+i)->nhapO();
	}
	cout<<endl<<"#################";
	for(int i=0;i<4;i++){
		k=true;
		for(int j=0;j<3;j++){
			if((x+j)->getdate()>(x+j+1)->getdate()){
				k=false;
				swap(*(x+j+1),*(x+j));	
			}
		}
		if(k==true) break;
	}
	for(int i=0;i<4;i++){
		(x+i)->outO();
		cout<<endl;
	}
}