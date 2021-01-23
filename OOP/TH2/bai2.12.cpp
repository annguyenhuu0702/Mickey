#include<iostream>
#include<cmath>
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
		friend float kc(Point, Point);
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
float kc(Point a,Point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
void Point::xuatP(){
	cout<<endl<<"Toa do: ("<<x<<";"<<y<<")"<<endl;
}
class Triangle:public MyColor{
	private:
		Point A,B,C;
	public:
		Triangle();
		Triangle(Point,Point,Point,int);
		~Triangle();
		float chuvi();
		bool operator>(Triangle);
		void xuatT();
};
Triangle::Triangle(){
	Point x;
	A=B=C=x;
}
Triangle::Triangle(Point a, Point b, Point c, int k){
	A=a;
	B=b;
	C=c;
	sh=k;
}
Triangle::~Triangle(){}
float Triangle::chuvi(){
	return kc(A,B)+kc(B,C)+kc(A,C);
}
void Triangle::xuatT(){
	Triangle::xuatC();
	A.xuatP();
	B.xuatP();
	C.xuatP();
	cout<<endl<<"Chu vi: "<<chuvi()<<endl;
}
bool Triangle::operator>(Triangle x){
	if(this->chuvi()>x.chuvi())
		return true;
	return false;
}
int main(){
	int n;
	cout<<"Nhap so luong tam giac: ";
	cin>>n;
	Triangle *t=new Triangle[n];
	float x[3],y[3];
	int k;
	for(int i=0;i<n;i++){
		cout<<"Tam giac "<<i<<endl;
		for(int j=0;j<3;j++){
			cout<<"Diem "<<j<<endl;
			cout<<"X=";
			cin>>x[j];
			cout<<"Y=";
			cin>>y[j];	
		}
		cout<<"So hieu mau: ";
		cin>>k;
		*(t+i)=Triangle(Point(x[0],y[0]),Point(x[1],y[1]),Point(x[2],y[2]),k);
	}
	int max=0;
	for(int i=1;i<n;i++){
		if(*(t+i)>*(t+max)){
			max=i;
		}
	}
	cout<<endl<<"Tam giac co chu vi lon nhat"<<endl;
	(t+max)->xuatT();
}