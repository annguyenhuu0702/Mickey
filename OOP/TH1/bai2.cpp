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
		Complex operator+(Complex);
		Complex operator=(Complex);
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
				cout<<pt<<pa<<"i";
	}
	cout<<endl;	
}
float Complex::getPA(){
	return pa;
}
float Complex::getPT(){
	return pt;
}
Complex Complex::operator+(Complex a){
	return Complex(a.getPT()+this->pt,a.getPA()+this->pa);
}
Complex Complex::operator=(Complex a){
	pt=a.getPT();
	pa=a.getPA();
	return Complex(pt,pa);
}
int main(){
	int n;
	cout<<"Nhap so luong so phuc: ";
	cin>>n;
	Complex *x=new Complex[n];
	float t=0,a=0;
	for(int i=0;i<n;i++){
		cout<<"Input Complex number "<<i+1<<endl;
		x[i].Input();
		x[i].Output();
		t=t+x[i].getPT();
		a=a+x[i].getPA();
	}
	cout<<"Tong mang: ";
	Complex(t,a).Output();
}