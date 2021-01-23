#include<iostream>
#include<string>
using namespace std;
class Media{
	protected:
		string ten;
		float gia;
	public:
		Media();
		Media(string,float);
		~Media();
		void nhapMedia();
		void xuatMedia();
};
Media::Media(){
	ten="";
	gia=0;
}
Media::Media(string t, float g){
	ten=t;
	gia=g;
}
Media::~Media(){}
void Media::nhapMedia(){
	cout<<"Ten: ";
	getline(cin,ten);
	cout<<"Gia: ";
	cin>>gia;
}
void Media::xuatMedia(){
	cout<<endl<<"Ten: "<<ten;
	cout<<endl<<"Gia: "<<gia;
}
class Book:public Media{
	private:
		int sotrang;
		string tenTG;
	public:
		Book();
		~Book();
		void nhapBook();
		void xuatBook();
};
Book::Book(){
	Book::Media();
	tenTG="";
	sotrang=0;
}
Book::~Book(){}
void Book::nhapBook(){
	Book::nhapMedia();
	cout<<"So trang: ";
	cin>>sotrang;
	cin.ignore(1);
	cout<<"Ten tac gia: ";
	getline(cin,tenTG);
}
void Book::xuatBook(){
	Book::xuatMedia();
	cout<<endl<<"So trang: "<<sotrang;
	cout<<endl<<"Ten tac gia: "<<tenTG;
}
class Video:public Media{
	private:
		float giaban;
		int thoigian;
	public:
		Video();
		~Video();
		void nhapVideo();
		void xuatVideo();
};
Video::Video(){
	Video::Media();
	giaban=0;
	thoigian=0;
}
Video::~Video(){}
void Video::nhapVideo(){
	Video::nhapMedia();
	cout<<"Gia ban: ";
	cin>>giaban;
	cout<<"Thoi gian chay: ";
	cin>>thoigian;
	cin.ignore(1);
}
void Video::xuatVideo(){
	Video::xuatMedia();
	cout<<endl<<"Gia ban: "<<giaban;
	cout<<endl<<"Thoi gian chay: "<<thoigian;
}
int main(){
	int n1,n2;
	cout<<"Nhap bao nhieu Book: ";
	cin>>n1;
	cin.ignore(1);
	Book *b=new Book[n1];
	for(int i=0;i<n1;i++){
		(b+i)->nhapBook();
	}
	cout<<"Nhap bao nhieu Video: ";
	cin>>n2;
	Video *v=new Video[n2];
	cin.ignore(1);
	for(int i=0;i<n2;i++){
		(v+i)->nhapVideo();
	}
	cout<<endl<<"######Book############";
	for(int i=0;i<n1;i++){
		(b+i)->xuatBook();
		cout<<endl;
	}
	cout<<endl<<"######Video############";
	for(int i=0;i<n2;i++){
		(v+i)->xuatVideo();
		cout<<endl;
	}
}