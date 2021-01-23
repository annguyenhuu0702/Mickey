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
		float getT();
		float getM();
		void nhap();
		void xuat();
		PS RutGon();
		friend bool operator>=(PS,PS);
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
float PS::getM(){
	return m;
}
float PS::getT(){
	return t;
}
bool operator>=(PS a, PS b){
	if(a.getT()/a.getM()>=b.getT()/b.getM())
		return true;
	return false;
}

int main(){
	PS x[5];
	for(int i=0;i<5;i++){
		cout<<"Phan so "<<i+1<<": "<<endl;
		x[i].nhap();
		x[i].RutGon().xuat();
	}
	int max=0;
	for(int i=0;i<5;i++){
		if(x[i]>=x[max])
			max=i;
	}
	cout<<endl<<"PHAN SO LON NHAT: ";
	x[max].xuat();
}