#include<iostream>
#include<cmath>
using namespace std;
class PS{
	private:
		float t,m;
	public:
		PS();
		PS(float,float);
		PS(const PS&);
		~PS();
		void nhap();
		void xuat();
		PS RutGon();
		float getT();
		float getM();
		PS operator+(PS);
		PS operator*(PS);
		PS operator/(PS);
		PS operator-(PS);
		PS operator=(PS);
};
PS::PS(){
	t=m=0;
}
PS::PS(float a,float b){
	t=a;
	m=b;
}
PS::PS(const PS& x){
	t=x.t;
	m=x.m;
}
PS::~PS(){}
float PS::getM(){
	return m;
}
float PS::getT(){
	return t;
}
PS PS::RutGon(){
	int a=abs(t),b=abs(m);
	while(a!=b){
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return PS(t/(float) a,m/(float)b);
}
void PS::nhap(){
	cout<<"Nhap tu so: ";
	cin>>t;
	do{
		cout<<"Nhap mau so: ";
		cin>>m;	
	}while(m==0);	
}
void PS::xuat(){
	if(m==1)
		cout<<t;
	else if(m==-1)
		cout<<t*(-1);
	else{
		if(t==0)
			cout<<t;
		else
			cout<<t<<"/"<<m;	
	} 
	cout<<endl;
}
PS PS::operator+(PS a){
	return PS(a.t*m+t*a.m,a.m*m).RutGon();
}
PS PS::operator-(PS a){
	return PS(t*a.m-a.t*m,a.m*m).RutGon();
}
PS PS::operator*(PS a){
	return PS(a.t*t,a.m*m).RutGon();
}
PS PS::operator/(PS a){
	return PS(a.m*t,m*a.t).RutGon();
}
PS PS::operator=(PS a){
	t=a.t;
	m=a.m;
	return PS(t,m).RutGon();
}
int main(){
	int n;
	cout<<"So luong phan so: ";
	cin>>n;
	PS *x=new PS[n];	
	float tong=0,mau=1;
	for(int i=0;i<n;i++){
		cout<<"Phan so "<<i+1<<": "<<endl;
		x[i].nhap();
		x[i].RutGon().xuat();
		tong=tong+(x[i].getT()/x[i].getM());
		mau=mau*x[i].getM();
	}
	cout<<"tong: ";
	PS(tong*mau,mau).RutGon().xuat();
}