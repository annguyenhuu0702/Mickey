#include<iostream>
using namespace std;
class Mydate{
	private:
		int d,m,y;
	public:
		Mydate();
		Mydate(int, int, int);
		Mydate(const Mydate&);
		~Mydate();
		void Input();
		void Output();
		bool operator==(Mydate);
};
Mydate::Mydate(){
	d=m=y=0;
}
Mydate::Mydate(int a, int b, int c){
	d=a;
	m=b;
	y=c;
}
Mydate::Mydate(const Mydate& x){
	d=x.d;
	m=x.m;
	y=x.y;
}
Mydate::~Mydate(){}
void Mydate::Input(){
	cout<<"Day: ";
	cin>>d;
	cout<<"Month: ";
	cin>>m;
	cout<<"Year: ";
	cin>>y;
}
void Mydate::Output(){
	cout<<endl<<d<<"-"<<m<<"-"<<y;
}
bool Mydate::operator==(Mydate a){
	if(a.y==y){
		if(a.m==m){
			if(a.d==d)
				return true;
			return false;
		}
		return false;
	}
	return false;
}
int main(){
	Mydate date[5];
	for(int i=0;i<5;i++){
		cout<<"Input date "<<i+1<<endl;
		date[i].Input();
		date[i].Output();
		cout<<endl;
	}
	Mydate x;
	cout<<"Input x"<<endl;
	x.Input();
	bool kt=false;
	for(int i=0;i<5;i++){
		if(date[i]==x){
			kt=true;
			cout<<endl<<"x co trong mang";
			break;
		}
	}
	if(kt==false)
		cout<<endl<<"x khong co trong mang";
}