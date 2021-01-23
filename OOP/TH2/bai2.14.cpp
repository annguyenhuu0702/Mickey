#include<iostream>
#include<string>
using namespace std;
class Mytime{
	protected:
		int h,m,s;
	public:
		Mytime();
		~Mytime();
		void nhaptime();
		void xuattime();
};
Mytime::Mytime(){
	h=m=s=0;
}
Mytime::~Mytime(){}
void Mytime::nhaptime(){
	cout<<"Nhap thoi gian: ";
	cin>>h>>m>>s;
}
void Mytime::xuattime(){
	cout<<endl<<"Thoi gian: "<<h<<":"<<m<<":"<<s<<endl;
}
class Mydate{
	protected:
		int n,t,nm;
	public:
		Mydate();
		~Mydate();
		void nhapdate();
		void xuatdate();
};
Mydate::Mydate(){
	n=t=nm=0;
}
Mydate::~Mydate(){}
void Mydate::nhapdate(){
	cout<<"Nhap ngay: ";
	cin>>n>>t>>nm;
}
void Mydate::xuatdate(){
	cout<<endl<<"Ngay: "<<n<<"-"<<t<<"-"<<nm<<endl;
}
class Datetime:public Mydate, public Mytime{
	public:
		Datetime();
		~Datetime();
		void nhapdt();
		void xuatdt();
};
Datetime::Datetime(){
	Datetime::Mytime();
	Datetime::Mydate();
}
Datetime::~Datetime(){}
void Datetime::nhapdt(){
	Datetime::nhaptime();
	Datetime::nhapdate();
}
void Datetime::xuatdt(){
	Datetime::xuatdate();
	Datetime::xuattime();
}
int main(){
	Datetime a,b,c;
	a.nhapdt();
	a.xuatdt();
	b.nhapdt();
	b.xuatdt();
	c.nhapdt();
	c.xuatdt();
}