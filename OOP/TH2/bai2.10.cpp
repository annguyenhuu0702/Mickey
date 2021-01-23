#include<iostream>
#include<cmath>
using namespace std;
class MyColor{
	protected:
		int sh;
	public:
		void nhapC();
		void xuatC();
};
void MyColor::nhapC(){
	cout<<"So hieu: ";
	cin>>sh;
}
void MyColor::xuatC(){
	cout<<endl<<"So hieu: "<<sh<<endl;
}
class Point{
	private:
		float x,y;
	public:
		void nhapP();
		void xuatP();
		friend float kc(Point, Point);
};
void Point::nhapP(){
	cout<<"X=";
	cin>>x;
	cout<<"Y=";
	cin>>y;
}
void Point::xuatP(){
	cout<<endl<<"Toa do: ("<<x<<";"<<y<<")"<<endl;
}
float kc(Point a,Point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
class Line:public MyColor{
	private:
		Point A,B;
	public:
		void move(float,float);
		void nhapL();
		float kcL();
		void xuatL();
};
void Line::nhapL(){
	Line::nhapC();
	cout<<"Diem 1"<<endl;
	A.nhapP();
	cout<<"Diem 2"<<endl;
	B.nhapP();
}
float Line::kcL(){
	return kc(A,B);
}
void Line::xuatL(){
	A.xuatP();
	B.xuatP();
	Line::xuatC();
	cout<<endl<<"AB="<<kcL()<<endl;
}
int main(){
	
	Line l;
	l.nhapL();
	l.xuatL();
}