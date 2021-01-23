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
class SVTC:public SV{
	private:
		float Hocphi;
	public:
		SVTC();
		~SVTC();
		void nhapSVTC();
		void xuatSVTC();
		bool operator>(SVTC);
};
SVTC::SVTC(){
	Hocphi=0;
}
SVTC::~SVTC(){}
void SVTC::nhapSVTC(){
	SVTC::nhapSV();
	cout<<"Hoc phi: ";
	cin>>Hocphi;
	cin.ignore(1);
}
void SVTC::xuatSVTC(){
	SVTC::xuatSV();
	cout<<endl<<"Hoc phi: "<<Hocphi;
}
bool SVTC::operator>(SVTC x){
	if(Hocphi>x.Hocphi)
		return true;
	return false;
}
class SVCN:public SVTC{
	protected:
		float Dtb;
		string hocbong;
	public:
		SVCN();
		~SVCN();
		void nhapSVCN();
		void xuatSVCN();
};
SVCN::SVCN(){
	SVCN::SV();
	Dtb=0;
	hocbong="";
}
SVCN::~SVCN(){}
void SVCN::nhapSVCN(){
	SVCN::nhapSVTC();
	cout<<"Diem trung binh: ";
	cin>>Dtb;
	cin.ignore(1);
	cout<<"Hoc bong: ";
	getline(cin,hocbong);
}
void SVCN::xuatSVCN(){
	SVCN::xuatSVTC();
	cout<<endl<<"Diem trung binh: "<<Dtb;
	cout<<endl<<"Hoc bong: "<<hocbong;
}
void swap(SVCN &a, SVCN &b){
	SVCN t=a;
	a=b;
	b=t;
}
int main(){
	SVCN *sv=new SVCN[5];
	for(int i=0;i<5;i++){
		(sv+i)->nhapSVCN();
	}
	cout<<endl<<"##################";
	SVCN val;
	int m,n;
	for(m=1;m<5;m++){
		n=m-1;
		val=*(sv+m);
		while(n>=0&&val>*(sv+n)){
			*(sv+n+1)=*(sv+n);
			n--;
		}
		*(sv+n+1)=val;
	}
	for(int i=0;i<5;i++){
		(sv+i)->xuatSVCN();
		cout<<endl;
	}
}