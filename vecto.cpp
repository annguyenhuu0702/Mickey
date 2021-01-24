#include <iostream>

using namespace std;

class Vector{
	private:
		int n;
		float *v;
	public:
		Vector(int size);
		Vector(const Vector &);
		~Vector();
		void nhap();
		void xuat();
		Vector &operator =(const Vector &);
		friend istream &operator >>(istream &is, Vector &);
		friend ostream &operator <<(ostream &os, Vector );
		friend Vector operator +(const Vector &, const Vector &);
		friend Vector operator -(const Vector &, const Vector &);	
		friend Vector operator *(const Vector &, float );
		bool check(const Vector &);
};

Vector::Vector(int size)
{
	n=size;
	v=new float [n];
}

Vector::Vector(const Vector &a)
{
	int i;
	n=a.n;
	v=new float [n];
	for (i=0;i<n;i++)
		v[i]=a.v[i];
}

Vector::~Vector()
{
	delete v;
}

void Vector::nhap()
{
	int i;
	for (i=0;i<n;i++)
	{
		cout<<"v["<<i<<"]: ";
		cin>>v[i];
	}
}

void Vector::xuat()
{
	int i;
	for (i=0;i<n;i++)
		cout<<v[i]<<"\t";
}

Vector &Vector::operator =(const Vector &a)
{
	int i;
	delete v;
	n = a.n;
	v = new float[n];
	for(i=0; i<n; i++)
	{
		v[i] = a.v[i];
	}
	return *this;
}

istream &operator >>(istream &is, Vector &a)
{
	for(int i=0; i<a.n; i++)
	{
		cout<<"v["<<i<<"]: ";
		is>>a.v[i];
	}
	return is;
}

ostream &operator <<(ostream &os, Vector a)
{
	for (int i=0;i<a.n;i++)
		os<<"\t"<<a.v[i];
	return os;
}

Vector operator +(const Vector &a, const Vector &b)
{
	Vector *tmp = new Vector(a.n);
	if(a.n == b.n)
	{	
		for(int i=0; i<a.n; i++)
		{
			tmp->v[i] = a.v[i] + b.v[i];
		}
	}
	return *tmp;
}

Vector operator -(const Vector &a, const Vector &b)
{
	Vector *tmp = new Vector(a.n);
	if(a.n == b.n)
	{	
		for(int i=0; i<a.n; i++)
		{
			tmp->v[i] = a.v[i] - b.v[i];
		}
	}
	return *tmp;
}

Vector operator *(const Vector &a,float k)
{
	Vector *tmp = new Vector(a.n);
	for(int i=0; i<a.n; i++)
	{
		tmp->v[i] = a.v[i] * k;
	}
	return *tmp;
}

bool Vector::check(const Vector &a)
{
	if(n == a.n)
		return true;
	return false;
}

int main()
{
	int n, m, k;
	cout<<"Nhap so phan tu cua vector a: ";
	cin>>n;
	Vector *a = new Vector(n);
	cin>>*a;
	cout<<"Vector a: ";
	cout<<*a;
	
	cout<<"\n\nNhap so phan tu cua vector b: ";
	cin>>m;
	Vector *b = new Vector(m);
	cin>>*b;
	cout<<"Vector b: ";
	cout<<*b;
	
	cout<<"\n\nNhap so thuc k = ";
	cin>>k;
	Vector c = *a * k;
	cout<<"Vecto c = a * k: "<<c<<endl;
	
	if(a->check(*b))
	{
		Vector tong = *a + *b;
		cout<<"\nTong 2 vector a va b: "<<tong<<endl;
		Vector hieu = *a - *b;
		cout<<"Hieu 2 vector a va b: "<<hieu<<endl;
	}
	else
		cout<<" hai vector a, b không cong/tru duoc voi nhau.";
	return 0;
}