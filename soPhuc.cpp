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
    void nhap();
    void xuat();
    float getPT();
    float getPA();
    friend soPhuc operator + (soPhuc, soPhuc);
    friend soPhuc operator - (soPhuc, soPhuc);
};
soPhuc::soPhuc() {
    pt=pa=0;
}
soPhuc::soPhuc(float a, float b) {
    pt=a;
    pa=b;
}
soPhuc::~soPhuc(){}
void soPhuc::nhap() {
    cout<<"Nhap phan thuc: ";
    cin>>pt;
    cout<<"Nhap phan ao: ";
    cin>>pa;
}
void soPhuc::xuat() {
    cout<<endl<<"so phuc: ";
	if(pa==0){
		cout<<pt;
	}
	else if(pa>0){
		if(pt==0){
			if(pa==1)
				cout<<"i";
			else
				cout<<pa<<"i";
		}
		else
			if(pa==1)
				cout<<pt<<"+i";
			else
				cout<<pt<<"+"<<pa<<"i";
	}
	else{
		if(pt==0){
			if(pa==-1)
				cout<<"-i";
			else
				cout<<pa<<"i";
		}
		else
			if(pa==-1)
				cout<<pt<<"-i";
			else
				cout<<pt<<pa<<"i";
	}
	cout<<endl;	
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
	soPhuc sp[2];
	for(int i=0;i<2;i++){
		cout<<"so phuc "<<i+1<<endl;
		sp[i].nhap();
		sp[i].xuat();
	}
    cout<<"Tong 2: ";
	(sp[0]+sp[1]).xuat();
	cout<<"Hieu 2: ";
	(sp[0]-sp[1]).xuat();
    system("pause");
    return 0;
}