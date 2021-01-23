#include<iostream>
using namespace std;
class Complex{
	private:
		float pt,pa;
	public:
		Complex();
		Complex(float ,float );
		Complex(const Complex& );
		~Complex();
		void Input();
		void Output();
		float getPT();
		float getPA();
		friend bool operator==(Complex,Complex);
		friend Complex operator-(Complex,Complex);
};
Complex::Complex(){
	pt=pa=0;
}
Complex::Complex(float a,float b){
	pt=a;
	pa=b;
}
Complex::Complex(const Complex& x){
	pt=x.pt;
	pa=x.pa;
}
Complex::~Complex(){}
void Complex::Input(){
	cout<<"Enter the real number: ";
	cin>>pt;
	cout<<"Enter the no real number: ";
	cin>>pa;
}
void Complex::Output(){
	cout<<endl<<"Complex number: ";
	if(pa==0){
		cout<<pt;
	}
	else if(pa>0){
		if(pt==0){
			if(pa==1)
				cout<<"i";
			else
				cout<<pa<<"i";
		}
		else
			if(pa==1)
				cout<<pt<<"+i";
			else
				cout<<pt<<"+"<<pa<<"i";
	}
	else{
		if(pt==0){
			if(pa==-1)
				cout<<"-i";
			else
				cout<<pa<<"i";
		}
		else
			if(pa==-1)
				cout<<pt<<"-i";
			else
				cout<<pt<<"-"<<pa<<"i";
	}
	cout<<endl;	
}
float Complex::getPA(){
	return pa;
}
float Complex::getPT(){
	return pt;
}
bool operator==(Complex a, Complex b){
	if(a.getPA()==b.getPA() && a.getPT()==b.getPT())
		return true;
	return false;
}
int main(){
	int n;
	cout<<"So luong so phuc: ";
	cin>>n;
	Complex *x=new Complex[n+1];
	for(int i=0;i<n;i++){
		cout<<"Input Complex number "<<i+1<<endl;
		x[i].Input();
		x[i].Output();
	}
	cout<<"Nhap so phuc can tim: "<<endl;
	x[n].Input();
	bool kt=false;
	for(int i=0;i<n;i++){
		if(x[i]==x[n]){
			kt=true;
			cout<<endl<<"CO TRONG MANG O VI TRI "<<i;
			break;
		}
	}
	if(kt==false)
		cout<<endl<<"KHONG CO TRONG MANG";
}