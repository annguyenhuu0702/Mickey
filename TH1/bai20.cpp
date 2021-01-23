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
		Complex operator-(Complex);
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
Complex Complex::operator+(Complex a){
	return Complex(a.getPT()+pt,a.getPA()+pa);
}
Complex Complex::operator-(Complex a){
	return Complex(pt-a.getPT(),pa-a.getPA());
}
int main(){
	Complex x[2];
	for(int i=0;i<2;i++){
		cout<<"Input Complex number "<<i+1<<endl;
		x[i].Input();
		x[i].Output();
	}
	cout<<endl<<"Sum two Complex numbers: ";
	(x[0]+x[1]).Output();
	cout<<endl<<"Sub two Complex numbers: ";
	(x[0]-x[1]).Output();
}