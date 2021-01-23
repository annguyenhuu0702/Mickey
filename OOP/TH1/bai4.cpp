#include<iostream>
using namespace std;
class Vector{
	private:
		int n;
		int *v;
	public:
		Vector(int );
		Vector(const Vector&);
		~Vector();
		void nhap();
		void xuat();
		Vector operator=(Vector);
		friend Vector operator+(Vector,Vector);
};
Vector::Vector(int n){
	this->n=n;
	v=new int[this->n];
	for(int i=0;i<n;i++)
		v[i]=0;
}
Vector::Vector(const Vector& x){
	n=x.n;
	v=new int[n];
	for(int i=0;i<n;i++)
		v[i]=x.v[i];
}
Vector::~Vector(){}
void Vector::nhap(){
	for(int i=0;i<n;i++){
		cout<<"Phan tu "<<i<<": ";
		cin>>*(v+i);
	}
}
void Vector::xuat(){
	cout<<"(";
	for(int i=0;i<n;i++){
		cout<<v[i];
		if(i==n-1){
		    cout<<")";
			break;
		}
		cout<<" ; ";
	}
	cout<<endl;
}
Vector Vector::operator=(Vector a){
	for(int i=0;i<a.n;i++){
		v[i]=a.v[i];
	}
	return a;
} 
Vector operator+(Vector a, Vector b){
	Vector c(a.n);
	for(int i=0;i<a.n;i++){
		c.v[i]=a.v[i]+b.v[i];
	}
	return c;
}
int main(){
	int n;
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	Vector a(n),b(n);
	cout<<"Vector a: "<<endl;
	a.nhap();
	cout<<"a = ";
	a.xuat();
	cout<<"Vector b: "<<endl;
	b.nhap();
	cout<<"b = ";
	b.xuat();
	cout<<"Vector a+b: "<<endl;
	cout<<"a + b = ";
	Vector c(n);
	c=a+b;
	c.xuat();
}