#include<iostream>
#include<string>
using namespace std;
class SV{
	protected:
		string Lop,Hoten;
	public:
		SV();
		SV(string,string);
		~SV();
		void nhapSV();
		void xuatSV();
};
SV::SV(){
	Lop=Hoten="";
}
SV::SV(string a, string b){
	Hoten=a;
	Lop=b;
}
SV::~SV(){}
void SV::nhapSV(){
	cout<<"Ten: ";
	getline(cin,Hoten);
	cout<<"Lop: ";
	getline(cin,Lop);
}
void SV::xuatSV(){
	cout<<endl<<"Ten: "<<Hoten;
	cout<<endl<<"Lop: "<<Lop;
}
class SVSP:public SV{
	protected:
		float Dtb;
		string hocbong;
	public:
		SVSP();
		~SVSP();
		void nhapSVSP();
		void xuatSVSP();
};
SVSP::SVSP(){
	SVSP::SV();
	Dtb=0;
	hocbong="";
}
SVSP::~SVSP(){}
void SVSP::nhapSVSP(){
	SVSP::nhapSV();
	cout<<"Diem trung binh: ";
	cin>>Dtb;
	cin.ignore(1);
	cout<<"Hoc bong: ";
	getline(cin,hocbong);
}
void SVSP::xuatSVSP(){
	SVSP::xuatSV();
	cout<<endl<<"Diem trung binh: "<<Dtb;
	cout<<endl<<"Hoc bong: "<<hocbong;
}
class SVCN:public SVSP{
	private:
		float Hocphi;
	public:
		SVCN();
		~SVCN();
		void nhapSVCN();
		void xuatSVCN();
};
SVCN::SVCN(){
	Hocphi=0;
}
SVCN::~SVCN(){}
void SVCN::nhapSVCN(){
	SVCN::nhapSVSP();
	cout<<"Hoc phi: ";
	cin>>Hocphi;
	cin.ignore(1);
}
void SVCN::xuatSVCN(){
	SVCN::xuatSVSP();
	cout<<endl<<"Hoc phi: "<<Hocphi;
}
int main(){
	SVCN *sv=new SVCN[3];
	for(int i=0;i<3;i++){
		(sv+i)->nhapSVCN();
	}
	cout<<endl<<"##################";
	for(int i=0;i<3;i++){
		(sv+i)->xuatSVCN();
		cout<<endl;
	}
}