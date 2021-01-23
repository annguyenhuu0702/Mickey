#include<iostream>
#include<queue>
using namespace std;
class Shape{
	protected:
		bool type;
	public:
		virtual	float dientich(){
			return 0;
		}
		virtual void nhap()=0;
		virtual void xuat();
		bool gettype(){
			return type;
		}
		void settype(bool t){
			type=t;
		}
};
void Shape::xuat(){
	cout<<dientich();
}
class Circle:public Shape{
	private:
		float r;
	public:
		Circle();
		~Circle();
		float getR(){
			return r;
		}
		void nhap();
		void xuat();
		float dientich();
};
Circle::Circle(){
	r=0;
}
Circle::~Circle(){}
void Circle::nhap(){
	cout<<"nhap ban kinh: ";
	cin>>r;
}
float Circle::dientich(){
	return r*r*3.14;
}
void Circle::xuat(){
	cout<<dientich();
}
class Rectangle:public Shape{
	private:
		float cd,cr;
	public:
		Rectangle();
		~Rectangle();
		void nhap();
		float getCR(){
			return cr;
		}
		float getCD(){
			return cd;
		}
		void xuat();
		float dientich();
};
Rectangle::Rectangle(){
	cd=cr=0;
}
Rectangle::~Rectangle(){}
float Rectangle::dientich(){
	return cd*cr;
}
void Rectangle::xuat(){
	cout<<dientich();
}
void Rectangle::nhap(){
	cout<<"Chieu dai: ";
	cin>>cd;
	cout<<"Chieu rong: ";
	cin>>cr;
}
class list:public Circle,public Rectangle{
	private:
		queue <Shape*> li;
	public:
		void nhapds();
		void xuatds();
};
void list::nhapds(){
	int lc;
	int i=1;
	while(i){
		cout<<"1. Nhap hinh tron"<<endl;
		cout<<"2. Nhap hinh chu nhat"<<endl;
		cout<<"3. Thoat"<<endl;
		cout<<"Nhap lua chon: ";
		cin>>lc;
		switch(lc){
			case 1:{
				Shape *c=new Circle;
				c->nhap();
				c->settype(true);
				li.push(c);
				break;
			}
				
			case 2:{
				Shape *r=new Rectangle;
				r->nhap();
				r->settype(false);
				li.push(r);
				break;
			}
				
			default:
				i=0;
				break;
		}
	}
}
void list::xuatds(){
	queue <Shape*> li1;
	while(!li.empty()){
		if(li.front()->gettype()==true){
			cout<<"Hinh tron: ";
			li.front()->xuat();
			cout<<endl;
		}
		else{
			cout<<"Hinh chu nhat: ";
			li.front()->xuat();
			cout<<endl;
		}
		li1.push(li.front());
		li.pop();
	}
	li=li1;
}
int main(){
	list li;
	li.nhapds();
	cout<<endl<<"##xuat##"<<endl;
	li.xuatds();
}