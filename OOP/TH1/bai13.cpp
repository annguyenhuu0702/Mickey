#include<iostream>
#include<string>
using namespace std;
class Student{
	private:
		string name;
		float D1,D2,DTB;
	public:
		Student();
		Student(string,float,float);
		Student(const Student&);
		~Student();
		void Input();
		void Output();
		bool operator>(Student);
};
Student::Student(){
	name="";
	D1=D2=DTB=0;
}
Student::Student(string name_,float d1,float d2){
	name=name_;
	D1=d1;
	D2=d2;
	DTB=(d1+2*d2)/3;
}
Student::Student(const Student& x){
	name=x.name;
	D1=x.D1;
	D2=x.D2;
	DTB=(x.D1+2*x.D2)/3;
}
Student::~Student(){}
void swap(Student &a,Student &b){
	Student t=a;
	a=b;
	b=t;
}
void Student::Input(){
	cout<<"Nhap ten: ";
	getline(cin,name);
	cout<<"Diem ki 1: ";
	cin>>D1;
	cout<<"Diem ki 2: ";
	cin>>D2;
	DTB=(D1+2*D2)/3;
	cin.ignore(1);
}
void Student::Output(){
	cout<<endl<<name<<endl<<D1<<"\t"<<D2<<"\t"<<DTB<<endl;
}
bool Student::operator>(Student a){
	if(DTB>a.DTB)
		return true;
	return false;
}
int main(){
	Student stu[5];
	for(int i=0;i<5;i++){
		cout<<"Student "<<i+1<<endl;
		stu[i].Input();
	}
	cout<<endl<<"Truoc khi sap xep: "<<endl;
	for(int i=0;i<5;i++){
		stu[i].Output();
	}
	cout<<endl<<"Sau khi sap xep: "<<endl;
	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if(stu[j]>stu[i])
				swap(stu[i],stu[j]);
		}
		stu[i].Output();
	}
}