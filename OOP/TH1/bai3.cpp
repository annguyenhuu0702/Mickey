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
		friend bool operator>=(Mydate, Mydate);
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
bool operator>=(Mydate a,Mydate b){
	if(a.y<b.y){
		return true;
	}
	else if(b.y<a.y){
		return false;
	}
	else{
		if(a.m<b.m){
			return true;
		}
		else if(b.m<a.m){
			return false;
		}
		else{
			if(a.d<=b.d){
				return true;
			}
			else if(b.d<=a.d){
				return false;
			}
		}
	}
}
int main(){
	Mydate date[5];
	for(int i=0;i<5;i++){
		cout<<"Input date "<<i+1<<endl;
		date[i].Input();
		date[i].Output();
		cout<<endl;
	}
	int max=0;
	for(int i=1;i<5;i++){
		if(date[i]>=date[max])
			max=i;
	}
	cout<<"Date MAX: ";
	date[max].Output();
}