#include<iostream>
#include<string>
using namespace std;
class Printer{
	protected:
		string ten;
		int sl;
	public:
		Printer();
		~Printer();
		void nhapkho(int);
		void xuatkho(int);
};
Printer::Printer(){
	sl=0;
	ten="";
}
Printer::~Printer(){}
void Printer::nhapkho(int q){
	sl=q;
	cout<<"Ten mat hang: ";
	getline(cin,ten);
}
void Printer::xuatkho(int q){
	sl=q;
	cout<<endl<<"Ten mat hang: ";
	cout<<ten;
	cout<<endl<<"So luong mat hang: ";
	cout<<sl;
}
class Laser:public Printer{
	protected:
		int dpi;
	public:
		Laser();
		~Laser();
		void nhapL(int);
		void xuatL(int);
};
Laser::Laser(){
	Laser::Printer();
	dpi=0;
}
Laser::~Laser(){}
void Laser::nhapL(int q){
	Laser::nhapkho(q);
	cout<<"Dpi: ";
	cin>>dpi;
	cin.ignore(1);
}
void Laser::xuatL(int q){
	Laser::xuatkho(q);
	cout<<endl<<"Dpi: "<<dpi;
}
class ColorPrinter:public Printer{
	protected:
		string mau;
	public:
		ColorPrinter();
		~ColorPrinter();
		void nhapCP(int );
		void xuatCP(int );
};
ColorPrinter::ColorPrinter(){
	ColorPrinter::Printer();
	mau="";
}
ColorPrinter::~ColorPrinter(){}
void ColorPrinter::nhapCP(int q){
	ColorPrinter::nhapkho(q);
	cout<<"Mau: ";
	getline(cin,mau);
}
void ColorPrinter::xuatCP(int q){
	ColorPrinter::xuatkho(q);
	cout<<endl<<"Mau: "<<mau;
}
class ColorLaser:public Laser,public ColorPrinter{
	public:
		ColorLaser();
		~ColorLaser();
		void nhapCL(int);
		void xuatCL(int);
};
ColorLaser::ColorLaser(){
	ColorLaser::ColorPrinter();
	ColorLaser::Laser();
}
ColorLaser::~ColorLaser(){}
void ColorLaser::nhapCL(int q){
	ColorLaser::nhapL(q);
	cout<<"Mau: ";
	getline(cin,mau);
}
void ColorLaser::xuatCL(int q){
	ColorLaser::xuatL(q);
	cout<<endl<<"Mau: "<<mau;
}
int main(){
	ColorLaser a,b,c;
	cout<<"####### May in mau #######"<<endl; 
	a.nhapCP(3);
	cout<<endl;
	a.xuatCP(3);
	cout<<endl<<"####### May in Laser #######"<<endl; 
	b.nhapL(4);
	cout<<endl; 
	b.xuatL(4);
	cout<<endl<<"####### May in Laser mau #######"<<endl; 
	c.nhapCL(2);
	cout<<endl; 
	c.xuatCL(2);
}