#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Printer{
	protected:
		string ten;
		bool type;
	public:
		Printer();
		~Printer();
		virtual void nhap();
		virtual void xuat();
		bool gettype(){
			return type;
		}
		void settype(bool t){
			type=t;
		}
		string getten(){
			return ten;
		}
		virtual bool operator>(Printer);

};
Printer::Printer(){
	ten="";
}
Printer::~Printer(){
}
void Printer::nhap(){
	cout<<"Nhap ten: ";
	getline(cin,ten);
}
void Printer::xuat(){
	if(type==true){
		cout<<endl<<"#Laser: ";
	}
	else{
		cout<<endl<<"#ColorLaser: ";
	}
	cout<<endl<<"Ten: "<<ten;
}
bool Printer::operator>(Printer x){
	if(ten>x.ten)
		return true;
	return false;
}
class Laser:public Printer{
	private:
		int Dpi;
	public:
		Laser();
		~Laser();
		void nhap();
		void xuat();
};

Laser::Laser(){
	Laser::Printer();
	Dpi=0;
}
Laser::~Laser(){
}
void Laser::nhap(){
	Printer::nhap();
	cout<<"Dpi: ";
	cin>>Dpi;
}
void Laser::xuat(){
	Printer::xuat();
	cout<<endl<<"Dpi: "<<Dpi;
}
class ColorLaser:public Printer{
	private:
		string Color;
	public:
		ColorLaser();
		~ColorLaser();
		void xuat();
		void nhap();
};
ColorLaser::ColorLaser(){
	ColorLaser::Printer();
	Color="";
}
ColorLaser::~ColorLaser(){
}
void ColorLaser::nhap(){
	Printer::nhap();
	cout<<"Color: ";
	getline(cin,Color);
}
void ColorLaser::xuat(){
	Printer::xuat();
	cout<<endl<<"Color: "<<Color;
}
class DS{
	private:
		vector <Printer*> pi;
		
	public:
		void nhapds();
		void xuatds();
		void sx();
};
void DS::nhapds(){
	int lc,i=1;
	Printer *a;
	while(i){
		cout<<"1. Nhap Laser"<<endl;
		cout<<"2. Nhap ColorLaser"<<endl;
		cout<<"3. Xuat danh sach may in"<<endl;
		cout<<"Nhap lua chon cua ban: ";
		cin>>lc;
		cin.ignore(1);
		switch(lc){
			case 1:{
				a=new Laser;
				a->nhap();
				a->settype(true);
				pi.push_back(a);
				break;
			}
			case 2:{
				a=new ColorLaser;
				a->nhap();
				a->settype(false);
				pi.push_back(a);
				break;
			}
			default:{
				i=0;
				break;
			}
		}
	}
}


void DS::xuatds(){
	for(int i=0;i<pi.size();i++){
		pi[i]->xuat();
		cout<<endl;
	}
}
void DS::sx(){
	Printer *p;
	int i,j;
	for(i=1;i<pi.size();i++){
		j=i-1;
		p=pi[i];
		while(j>=0&&pi[j]->getten()>p->getten()){
			pi[j+1]=pi[j];
			j--;
		}
		pi[j+1]=p;
	}
	xuatds();
}
int main(){
	DS ds;
	ds.nhapds();
	cout<<endl<<"-------------"<<endl;	
	ds.sx();
}