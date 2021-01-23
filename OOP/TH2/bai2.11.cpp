#include<iostream>
#define pi 3.14
using namespace std;
class MyColor{
	protected:
		int sh;
	public:
		MyColor();
		MyColor(int );
		~MyColor();
		void xuatC();
};
MyColor::MyColor(){
	sh=0;
}
MyColor::MyColor(int k){
	sh=k;
}
MyColor::~MyColor(){}
void MyColor::xuatC(){
	cout<<endl<<"So hieu: "<<sh<<endl;
}
class Point{
	private:
		float x,y;
	public:
		Point();
		Point(float,float);
		~Point();
		void xuatP();
};
Point::Point(){
	x=y=0;
}
Point::Point(float x,float y){
	this->x=x;
	this->y=y;
}
Point::~Point(){}
void Point::xuatP(){
	cout<<endl<<"Toa do: ("<<x<<";"<<y<<")"<<endl;
}
class Circle:public MyColor{
	private:
		Point O;
		float r;
	public:
		Circle();
		Circle(Point,float,int);
		~Circle();
		void xuatCir();
		float Dientich();
		bool operator>(Circle);
};
Circle::Circle(){
	Point x;
	O=x;
}
Circle::Circle(Point a,float bk, int k){
	O=a;
	r=bk;
	sh=k;
}
Circle::~Circle(){}
float Circle::Dientich(){
	return pi*r*r;
}
void Circle::xuatCir(){
	Circle::xuatC();
	O.xuatP();
	cout<<endl<<"r="<<r;
	cout<<endl<<"Dien tich: "<<Dientich();
}
bool Circle::operator>(Circle x){
	if(this->Dientich()>x.Dientich())
		return true;
	return false;
}
int main(){
	int n;
	cout<<"Nhap so luong duong tron: ";
	cin>>n;
	Circle *c=new Circle[n];
	float x,y,r;
	int k;
	for(int i=0;i<n;i++){
		cout<<"Duong tron "<<i<<endl;
		cout<<"X=";
		cin>>x;
		cout<<"Y=";
		cin>>y;
		cout<<"R=";
		cin>>r;
		cout<<"So hieu mau: ";
		cin>>k;
		*(c+i)=Circle(Point(x,y),r,k);
	}
	int max=0;
	for(int i=1;i<n;i++){
		if(*(c+i)>*(c+max)){
			max=i;
		}
	}
	cout<<endl<<"Duong tron co dien tich lon nhat"<<endl;
	(c+max)->xuatCir();
}