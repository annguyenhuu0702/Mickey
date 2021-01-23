#include<iostream>
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
		Point TinhTien(float, float);
		void nhapP();
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
Point Point::TinhTien(float dx,float dy){
	return Point(x+dx,y+dy);
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
		void move(float,float);
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
void Triangle::move(float dx,float dy){
	A=A.TinhTien(dx,dy);
	B=B.TinhTien(dx,dy);
	C=C.TinhTien(dx,dy);
}
void Triangle::xuatT(){
	Triangle::xuatC();
	A.xuatP();
	B.xuatP();
	C.xuatP();
}
int main(){
	float x[3],y[3],dx,dy;
	int k;
	for(int i=0;i<3;i++){
		cout<<"Diem "<<i<<endl;
		cout<<"X=";
		cin>>x[i];
		cout<<"Y=";
		cin>>y[i];
		cout<<endl;
		if(i==2){
			cout<<"dx=";
			cin>>dx;
			cout<<"dy=";
			cin>>dy;
			cout<<"So hieu mau: ";
			cin>>k;
			cout<<endl;
		}
	}
	Triangle t(Point(x[0],y[0]),Point(x[1],y[1]),Point(x[2],y[2]), k);
	cout<<"Truoc khi tinh tien";
	t.xuatT();
	t.move(dx,dy);
	cout<<"Sau khi tinh tien";
	t.xuatT();
}