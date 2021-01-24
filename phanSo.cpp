#include<iostream>
using namespace std;
class phan_so{
	private:
		int tu_so,mau_so;
	public:
		phan_so();
		phan_so(int, int);
		phan_so(const phan_so &);
		~phan_so();
		friend istream& operator>>(istream& ,phan_so&);
		friend ostream& operator<<(ostream& ,phan_so&);
		friend phan_so operator+(phan_so,phan_so);
		phan_so operator-(phan_so);
		friend phan_so operator*(phan_so,phan_so);
		phan_so operator/(phan_so);
		friend bool operator>(phan_so,phan_so);
		bool operator<(phan_so);
		bool operator==(phan_so);
		phan_so operator++();
		phan_so operator--();
		void nghich_dao();
		void rut_gon();
};
phan_so::phan_so(){
	tu_so=mau_so=0;
}
phan_so::phan_so(int x,int y){
	tu_so=x;
	mau_so=y;
}
phan_so::phan_so(const phan_so &x){
	tu_so=x.tu_so;
	mau_so=x.mau_so;
}
phan_so::~phan_so(){}
istream& operator>>(istream& is, phan_so& x){
	cout<<endl<<"Nhap tu so: ";
	is>>x.tu_so;
    do{
	cout<<endl<<"Nhap mau so: ";
	is>>x.mau_so;
    }
    while(x.mau_so==0);
	return is;
}
ostream& operator<<(ostream& os, phan_so &x){
	if(x.mau_so!=0){
		if(x.mau_so==1)
			os<<endl<<x.tu_so;
		else if(x.mau_so==-1)
			os<<endl<<x.tu_so*(-1);
		else if(x.tu_so==0)
			os<<endl<<x.tu_so;
		else
			os<<endl<<x.tu_so<<"/"<<x.mau_so;
	}
	return os;
}
phan_so operator+(phan_so a,phan_so b){
	return phan_so(a.tu_so*b.mau_so+a.mau_so*b.tu_so,a.mau_so*b.mau_so);
}
phan_so phan_so::operator-(phan_so a){
	return phan_so(tu_so*a.mau_so-mau_so*a.tu_so,mau_so*a.mau_so);
}
phan_so operator*(phan_so a,phan_so b){
	return phan_so(a.tu_so*b.tu_so,a.mau_so*b.mau_so);
}
phan_so phan_so::operator/(phan_so a){
	return phan_so(tu_so*a.mau_so,mau_so*a.tu_so);
}
bool operator>(phan_so a,phan_so b){
	return (a.tu_so*b.mau_so>a.mau_so*b.tu_so)?true:false;
}
bool phan_so::operator<(phan_so a){
	return (tu_so*a.mau_so<mau_so*a.tu_so)?true:false;
}
bool phan_so::operator==(phan_so a){
	return (tu_so*a.mau_so==mau_so*a.tu_so)?true:false;
}
phan_so phan_so::operator++(){
	return phan_so(tu_so+mau_so,mau_so);
}
phan_so phan_so::operator--(){
	return phan_so(tu_so-mau_so,mau_so);
}
void phan_so::nghich_dao(){
	int t=tu_so;
	tu_so=mau_so;
	mau_so=t;
}
int UCLN(int a,int b){
	a=(a<0)?a*(-1):a;
	b=(b<0)?b*(-1):b;
	if(b==0) return a;
	if(a%b==0) return b;
	return UCLN(b,a%b);
}
void phan_so::rut_gon(){
	int c=UCLN(tu_so,mau_so);
	tu_so/=c;
	mau_so/=c;
}
int main(){
	phan_so *a;
	a=new phan_so[2];
	cin>>*a;
	cout<<*a;
	cin>>*(a+1);
	cout<<*(a+1);
	phan_so c=*a+*(a+1);
	cout<<"Tong 2 phan so:";
	c.rut_gon();
	cout<<c;
	phan_so d=*a-*(a+1);
	cout<<"Hieu 2 phan so:";
	d.rut_gon();
	cout<<d;
    system("pause");
    return 0;
}