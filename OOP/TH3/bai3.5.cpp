#include<iostream>
#include<string>
#include<queue>
using namespace std;
class Media{
	protected:
		string ten;
		int gia;
	public:
		Media();
		Media(string,int);
		~Media();
		virtual void nhap();
		virtual void xuat();
};
Media::Media(){
	ten="";
	gia=0;
}
Media::Media(string a,int b){
	ten=a;
	gia=b;
}
Media::~Media(){
}
void Media::nhap(){
	cout<<"Nhap ten: ";
	getline(cin,ten);
	cout<<"Gia: ";
	cin>>gia;
	cin.ignore(1);
}
void Media::xuat(){
	cout<<endl<<"Ten: "<<ten;
	cout<<endl<<"Gia: "<<gia;
}
class Video:public Media{
	private:
		int Speed;
	public:
		Video();
		~Video();
		void nhap();
		void xuat();
};
Video::Video(){
	gia=0;
	Speed=0;
}
Video::~Video(){
}
void Video::nhap(){	
	cout<<"Thoi gian: ";
	cin>>Speed;
	cout<<"Gia ban: ";
	cin>>gia;
}
void Video::xuat(){
	cout<<endl<<"Thoi gian: "<<Speed;
	cout<<endl<<"Gia ban: "<<gia;
}
class Book:public Media{
	private:
		int Dpi;
	public:
		Book();
		~Book();
		void xuat();
		void nhap();
};
Book::Book(){
	ten="";
	Dpi=0;
}
Book::~Book(){
}
void Book::nhap(){
	
	cout<<"So trang: ";
	cin>>Dpi;
	cout<<"Tac gia";
	cin.ignore(1);
	getline(cin,ten);
}
void Book::xuat(){
cout<<endl<<"So trang: "<<Dpi;
	cout<<endl<<"Tac gia: "<<ten;
}
class DS{
	private:
		queue <Media*> mt;
		queue <Media*> mi;
	public:
		void nhapds();
		void xuatds();
};
void DS::nhapds(){
	int lc,i=1;
	while(i){
		cout<<"1. Nhap BOOK"<<endl;
		cout<<"2. Nhap VIDEO"<<endl;
		cout<<"3. Xuat danh sach"<<endl;
		cout<<"Nhap lua chon cua ban: ";
		cin>>lc;
		cin.ignore(1);
		switch(lc){
			case 1:{
				Media *a=new Video;
				a->nhap();
				mt.push(a);
				break;
			}
			case 2:{
				Media *b=new Book;
				b->nhap();
				mi.push(b);
				break;
			}
			default:{
				i=0;
				break;
			}
		}
	}
}
void DS::xuatds(){
	cout<<endl<<"#BOOK"<<endl;
	while(!mt.empty()){
		mt.front()->xuat();
		cout<<endl;
		mt.pop();
	}
	cout<<endl<<"#VIDEO"<<endl;
	while(!mi.empty()){
		mi.front()->xuat();
		cout<<endl;
		mi.pop();
	}
}
int main(){
	DS ds;
	ds.nhapds();
	cout<<endl<<"-------------"<<endl;	
	ds.xuatds();
}