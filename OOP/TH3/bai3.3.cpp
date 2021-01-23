#include<iostream>
#include<string>
#include<queue>
using namespace std;
class MatHang{
	protected:
		string ten;
	public:
		MatHang();
		~MatHang();
		virtual void nhap();
		virtual void xuat();
};
MatHang::MatHang(){
	ten="";
}
MatHang::~MatHang(){
}
void MatHang::nhap(){
	cout<<"Nhap ten: ";
	getline(cin,ten);
}
void MatHang::xuat(){
	cout<<endl<<"Ten: "<<ten;
}
class MayTinh:public MatHang{
	private:
		int Speed;
	public:
		MayTinh();
		~MayTinh();
		void nhap();
		void xuat();
};
MayTinh::MayTinh(){
	MayTinh::MatHang();
	Speed=0;
}
MayTinh::~MayTinh(){
}
void MayTinh::nhap(){
	MatHang::nhap();
	cout<<"Toc do: ";
	cin>>Speed;
}
void MayTinh::xuat(){
	MatHang::xuat();
	cout<<endl<<"Toc do: "<<Speed;
}
class MayIn:public MatHang{
	private:
		int Dpi;
	public:
		MayIn();
		~MayIn();
		void xuat();
		void nhap();
};
MayIn::MayIn(){
	MayIn::MatHang();
	Dpi=0;
}
MayIn::~MayIn(){
}
void MayIn::nhap(){
	MatHang::nhap();
	cout<<"Dpi: ";
	cin>>Dpi;
}
void MayIn::xuat(){
	MatHang::xuat();
	cout<<endl<<"Dpi: "<<Dpi;
}
class DS{
	private:
		queue <MatHang*> mt;
		queue <MatHang*> mi;
	public:
		void nhapds();
		void xuatds();
};
void DS::nhapds(){
	int lc,i=1;
	while(i){
		cout<<"1. Nhap may tinh"<<endl;
		cout<<"2. Nhap may in"<<endl;
		cout<<"3. Xuat danh sach mat hang"<<endl;
		cout<<"Nhap lua chon cua ban: ";
		cin>>lc;
		cin.ignore(1);
		switch(lc){
			case 1:{
				MatHang *a=new MayTinh;
				a->nhap();
				mt.push(a);
				break;
			}
			case 2:{
				MatHang *b=new MayIn;
				b->nhap();
				mi.push(b);
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
	cout<<endl<<"#May tinh"<<endl;
	while(!mt.empty()){
		mt.front()->xuat();
		cout<<endl;
		mt.pop();
	}
	cout<<endl<<"#May in"<<endl;
	while(!mi.empty()){
		mi.front()->xuat();
		cout<<endl;
		mi.pop();
	}
}
int main(){
	DS ds;
	ds.nhapds();
	cout<<endl<<"-------------"<<endl;	
	ds.xuatds();
}