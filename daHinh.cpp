//Tim nhan vien co luong cao nhat
//Sap xep nhan vien theo luong giam dan
//Tim mot nhan vien bat ky
//Bo sung cac ham tao, ham huy cho cac class
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Staff{
	protected:
		string Name;
		int Age;
		int Salary_Level;
		bool Type_Staff;
	public:
		virtual void Input(); //ham ao
		virtual void Output(); //ham ao
		virtual float Salary() = 0; //ham thuan ao
		void setType(bool);
		bool getType();
		string getName();
};
void Staff::setType(bool x){
	Type_Staff=x;
}
bool Staff::getType(){
	return Type_Staff;
}
string Staff::getName(){
	return Name;
}
class Official: public Staff
{
	private:
		int Seniority;
	public:
		Official();
		~Official();
		void Input();
		void Output();
		float Salary();
};
Official::Official(){
	Name="";
	Age=Salary_Level=Seniority=0;
}
Official::~Official(){
}
class Probationary:public Staff
{
	private:
		string Day_Work;
	public:
		Probationary();
		~Probationary();
		void Input();
		void Output();
		float Salary();
};
Probationary::Probationary(){
	Name=Day_Work="";
	Age=Salary_Level=0;
}
Probationary::~Probationary(){
}
void Staff::Input(){
	cout<<"\nEnter to the name of the staff: ";
	cin.ignore(1);
	getline(cin,Name);
	cout<<"Enter to the age of the staff: ";
	cin>>Age;
	cin.ignore(1);
	cout<<"Enter to the salary level of the staff: ";
	cin>>Salary_Level;
}
void Staff::Output(){
	cout<<"\tName:  "<<Name<<endl;
	cout<<"\tAge: "<<Age<<endl;
	cout<<"\tSalary level "<<Salary_Level<<endl;	
}
void Official::Input(){
	Staff::Input();
	cout<<"Enter to the seniority of the staff: ";
	cin>>Seniority;
}
void Official::Output(){
	Staff::Output();
	cout<<"\tSeniority: "<<Seniority<<endl;
	cout<<"\tSalary: "<<this->Salary()<<endl;
}
float Official::Salary(){
	return (Salary_Level*1600);
}
void Probationary::Input(){
	Staff::Input();
	cout<<"Enter to the day when start work of the staff: ";
	cin.ignore(1);
	getline(cin,Day_Work);
}
void Probationary::Output(){
	Staff::Output();
	cout<<"\tDay Work: "<<Day_Work<<endl;
	cout<<"\tSalary: "<<this->Salary()<<endl;
}
float Probationary::Salary(){ 
	return Salary_Level*1600*0.8;
}
class Company{
	private:
		vector <Staff *> DSNV;
	public:
		void InputList();
		void OutputList();
		float Sum_Salary();
		void Max_Salary();
		void Sort_Salary_Decrease();
		void Search_Staff();
};
void Company::InputList(){
	int i=1,Choice;
	while(i){
		cout<<"\n1. Enter to official staff."<<endl;
		cout<<"2. Enter to probationary staff."<<endl;
		cout<<"3. Back"<<endl;
		Staff *sta;
		cout<<"Enter to your choice: ";
		cin>>Choice;
		system("cls");
		switch(Choice){
			case 1:
				sta=new Official;
				sta->Input();
				DSNV.push_back(sta);
				sta->setType(true);
				break;
			case 2:
				sta=new Probationary;
				sta->Input();
				DSNV.push_back(sta);
				sta->setType(false);
				break;
			case 3:
				i=0;
				break;
			default:
				cout<<"Error. Try again"<<endl;
		}
	}
}
void Company::OutputList(){
	for(int i=0;i<DSNV.size();i++){
		if(DSNV[i]->getType()==true){
			cout<<endl<<"Official staff: "<<endl;
			DSNV[i]->Output();
		}
		else{
			cout<<endl<<"Probationary staff: "<<endl;
			DSNV[i]->Output();
		}
	}
}
float Company::Sum_Salary(){
	float sum=0;
	for(int i=0;i<DSNV.size();i++){
		sum+=DSNV[i]->Salary();
	}
	return sum;
} 
void Company::Max_Salary(){
	Staff *max=DSNV[0];
	for(int i=1;i<DSNV.size();i++){
		if(max->Salary()<DSNV[i]->Salary())
			max=DSNV[i];
	}
	cout<<"Staff has the highest salary in company: ";
	if(max->getType()==true){
		cout<<endl<<"Official staff: "<<endl;
		max->Output();
	}
	else{
		cout<<endl<<"Probationary staff: "<<endl;
		max->Output();
	}
}
void Company::Sort_Salary_Decrease(){
	Staff* temp;
	int i,j;
	for(int i=1;i<DSNV.size();i++){
		temp=DSNV[i];
		j=i-1;
		while(j>=0&&temp->Salary()>DSNV[j]->Salary()){
			DSNV[j+1]=DSNV[j];
			j--;
		}
		DSNV[j+1]=temp;	
	}
	OutputList();
}
void Company::Search_Staff(){
	string temp;
	cout<<"Enter to the name of staff whom you want to search: ";
	cin.ignore(1);
	getline(cin,temp);
	cout<<"Search result:";
	for(int i=0;i<DSNV.size();i++){
		if(DSNV[i]->getName()==temp){
			if(DSNV[i]->getType()==true){
				cout<<endl<<"Official staff: "<<endl;
				DSNV[i]->Output();
			}
			else{
				cout<<endl<<"Probationary staff: "<<endl;
				DSNV[i]->Output();
			}
			break;
		}
	}	
}
int main(){
	Company *a=new Company;
	a->InputList();
	cout<<"\n******************************"<<endl;
	a->OutputList();
	cout<<"\n******************************"<<endl;
	cout<<"Sum of all staff's salay: "<<a->Sum_Salary()<<endl;
	a->Max_Salary();
	cout<<"\n******************************"<<endl;
	cout<<"Sort by salary decrease: ";
	a->Sort_Salary_Decrease();
	cout<<"\n******************************"<<endl;
	a->Search_Staff();
	delete a;
	return 0;
}