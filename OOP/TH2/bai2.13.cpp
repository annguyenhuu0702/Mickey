#include<iostream>
#include<string>
using namespace std;
class Printer{
	protected:
		string sohieu;
		int sl;
	public:
		Printer();
		~Printer();
		void nhapkho(int);
		void xuatkho(int);
};
Printer::Printer(){
	sl=0;
	sohieu="";
}
Printer::~Printer(){}
void Printer::nhapkho(int q){
	sl=q;
	cout<<"So hieu mat hang: ";
	getline(cin,sohieu);
}
void Printer::xuatkho(int q){
	sl=q;
	cout<<endl<<"So hieu mat hang: ";
	cout<<sohieu;
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
class ColorLaser:public Laser{
	private:
		string mau;
	public:
		ColorLaser();
		~ColorLaser();
		void nhapCL(int);
		void xuatCL(int);
};
ColorLaser::ColorLaser(){
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
	ColorLaser a,b;
	cout<<endl<<"####### May in Laser mau #######"<<endl; 
	a.nhapCL(5);
	b.nhapCL(2);
	a.xuatCL(5);
	b.xuatCL(2);
}