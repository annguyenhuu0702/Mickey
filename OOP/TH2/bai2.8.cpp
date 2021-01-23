#include<iostream>
#include<string>
using namespace std;
class Mytime{
	protected:
		int h,m,s;
	public:
		Mytime();
		~Mytime();
		void nhaptime();
		void xuattime();
};
Mytime::Mytime(){
	h=m=s=0;
}
Mytime::~Mytime(){}
void Mytime::nhaptime(){
	cout<<"Nhap thoi gian: ";
	cin>>h>>m>>s;
}
void Mytime::xuattime(){
	cout<<endl<<"Thoi gian: "<<h<<":"<<m<<":"<<s<<endl;
}
class Mydate{
	protected:
		int n,t,nm;
	public:
		Mydate();
		~Mydate();
		void nhapdate();
		void xuatdate();
};
Mydate::Mydate(){
	n=t=nm=0;
}
Mydate::~Mydate(){}
void Mydate::nhapdate(){
	cout<<"Nhap ngay: ";
	cin>>n>>t>>nm;
}
void Mydate::xuatdate(){
	cout<<endl<<"Ngay: "<<n<<"-"<<t<<"-"<<nm<<endl;
}
class Myfile:public Mydate, public Mytime{
	private:
		string filename;
		int filesize;
	public:
		Myfile();
		~Myfile();
		void nhapfile();
		void xuatfile();
		bool operator>(Myfile);
};
Myfile::Myfile(){
	Myfile::Mytime();
	Myfile::Mydate();
	filename="";
	filesize=0;
}
Myfile::~Myfile(){}
void Myfile::nhapfile(){
	Myfile::nhaptime();
	Myfile::nhapdate();
	cin.ignore(1);
	cout<<"Ten file: ";
	getline(cin,filename);
	cout<<"Kich thuoc file: ";
	cin>>filesize;
}
void Myfile::xuatfile(){
	Myfile::xuatdate();
	Myfile::xuattime();
	cout<<endl<<"Ten file: "<<filename;
	cout<<endl<<"Kich thuoc file: "<<filesize;
}
bool Myfile::operator>(Myfile x){
	if(filesize>x.filesize)
		return true;
	return false;
}
void swap(Myfile &a, Myfile &b){
	Myfile t=a;
	a=b;
	b=t;
}
int main(){
	Myfile *f=new Myfile[5];
	for(int i=0;i<5;i++){
		(f+i)->nhapfile();
	}
	for(int i=0;i<4;i++){
		for(int j=i+1;j<5;j++){
			if(*(f+j)>*(f+i))
				swap(*(f+j),*(f+i));
		}
	}
	cout<<endl<<"##############";
	for(int i=0;i<5;i++){
		(f+i)->xuatfile();
	}
}