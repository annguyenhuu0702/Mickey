#include<iostream>
using namespace std;
class soPhuc {
    private:
    float pt;
    float pa;
    public:
    soPhuc();
    soPhuc(float a, float b);
    ~soPhuc();
    float getPT();
    float getPA();
    friend soPhuc operator + (soPhuc, soPhuc);
    friend soPhuc operator - (soPhuc, soPhuc);
    friend istream& operator>>(istream& is,soPhuc &x);
	friend ostream& operator<<(ostream& os,soPhuc &x);
};
soPhuc::soPhuc() {
    pt=pa=0;
}
soPhuc::soPhuc(float a, float b) {
    pt=a;
    pa=b;
}
soPhuc::~soPhuc(){}
//tuong tu phan so ne`
istream& operator>>(istream& is,soPhuc &x){
	cout<<"Nhap phan thuc: ";
	is>>x.pt;
	cout<<"Nhap phan ao: ";
	is>>x.pa;
	return is;
}
ostream& operator<<(ostream& os,soPhuc &x){
	if(x.pa==0){
		os<<x.pt;
	}
	else if(x.pa>0){
		if(x.pt==0){
			if(x.pa==1)
				os<<"i";
			else
				os<<x.pa<<"i";
		}
		else
			if(x.pa==1)
				os<<x.pt<<"+i";
			else
				os<<x.pt<<"+"<<x.pa<<"i";
	}
	else{
		if(x.pt==0){
			if(x.pa==-1)
				os<<"-i";
			else
				os<<x.pa<<"i";
		}
		else
			if(x.pa==-1)
				os<<x.pt<<"-i";
			else
				os<<x.pt<<x.pa<<"i";
	}
	os<<endl;
	return os;
}
float soPhuc::getPA() {
    return pa;
}
float soPhuc::getPT() {
    return pt;
}
soPhuc operator+ (soPhuc a, soPhuc b) {
    return soPhuc(a.getPT()+b.getPT(),a.getPA()+b.getPA());
}
soPhuc operator- (soPhuc a, soPhuc b) {
    return soPhuc(a.getPT()-b.getPT(),a.getPA()-b.getPA());
}
int main(){
	soPhuc *a;
	a=new soPhuc[2];
	cin>>*a;
	cout<<*a;
	cin>>*(a+1);
    soPhuc c=*a+*(a+1);
	cout<<"Tong hai so phuc:";
	cout<<c;
	soPhuc d=*a-*(a+1);
	cout<<"Hieu 2 so phuc:";
	cout<<d;
    system("pause");
    return 0;
}