#include<iostream>
#include<string>
#include<queue>
using namespace std;
class SV{
	protected:
		string ten,lop;
	public:
		SV();
		~SV();
		virtual void nhap();
		virtual void xuat();
};
SV::SV(){
	ten=lop="";
}
SV::~SV(){
}
void SV::nhap(){
	cout<<"Nhap ten: ";
	getline(cin,ten);
	cout<<"Nhap lop: ";
	getline(cin,lop);
}
void SV::xuat(){
	cout<<endl<<"Ten: "<<ten;
	cout<<endl<<"Lop: "<<lop;
}
class SVSP:public SV{
	private:
		string hocbong;
	public:
		SVSP();
		~SVSP();
		void nhap();
		void xuat();
};
SVSP::SVSP(){
	SVSP::SV();
	hocbong="";
}
SVSP::~SVSP(){
}
void SVSP::nhap(){
	SV::nhap();
	cout<<"Hoc bong: ";
	getline(cin,hocbong);
}
void SVSP::xuat(){
	SV::xuat();
	cout<<endl<<"Hoc bong: "<<hocbong;
}
class SVTC:public SV{
	private:
		int hocphi;
	public:
		SVTC();
		~SVTC();
		void xuat();
		void nhap();
};
SVTC::SVTC(){
	SVTC::SV();
	hocphi=0;
}
SVTC::~SVTC(){
}
void SVTC::nhap(){
	SV::nhap();
	cout<<"Hoc phi: ";
	cin>>hocphi;
	cin.ignore(1);
}
void SVTC::xuat(){
	SV::xuat();
	cout<<endl<<"Hoc phi: "<<hocphi;
}
class DS{
	private:
		queue <SV*> svtc;
		queue <SV*> svsp;
	public:
		void nhapds();
		void xuatds();
};
void DS::nhapds(){
	int lc,i=1;
	while(i){
		cout<<"1. Nhap sinh vien tai chuc"<<endl;
		cout<<"2. Nhap sinh vien su pham"<<endl;
		cout<<"3. Xuat danh sach sinh vien"<<endl;
		cout<<"Nhap lua chon cua ban: ";
		cin>>lc;
		cin.ignore(1);
		switch(lc){
			case 1:{
				SV *a=new SVTC;
				a->nhap();
				svtc.push(a);
				break;
			}
			case 2:{
				SV *b=new SVSP;
				b->nhap();
				svsp.push(b);
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
	cout<<endl<<"Sinh vien tai chuc"<<endl;
	while(!svtc.empty()){
		svtc.front()->xuat();
		cout<<endl;
		svtc.pop();
	}
	cout<<endl<<"Sinh vien su pham"<<endl;
	while(!svsp.empty()){
		svsp.front()->xuat();
		cout<<endl;
		svsp.pop();
	}
}
int main(){
	DS ds;
	ds.nhapds();
	cout<<endl<<"-------------"<<endl;	
	ds.xuatds();
}