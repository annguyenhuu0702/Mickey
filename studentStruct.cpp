#include <iostream>
using namespace std;
#define MAX 10
typedef struct Student
{
        char  name[30];
        int   rollNo;
        int   total;
        float perc;
};
void getDetails(Student &student);
void putDetails(Student student);
int main()
{
    Student students[MAX];    
    int n,loop;
    cout << "Enter total number of students: ";
    cin >> n; 
    for(loop=0;loop< n; loop++){
        cout << "Enter details of student " << loop+1 << ":\n";
        getDetails(students[loop]);
    }  
    for(loop=0;loop< n; loop++){
        cout <<endl<< "Details of student " << (loop+1);
        putDetails(students[loop]);
    }
     
    return 0;
}
// getdetails
void getDetails(Student &student){
    cout << "Enter name: " ;
    cin >> student.name ;
    cout << "Enter roll number: ";
    cin >> student.rollNo;
    cout << "Enter total marks outof 500: ";
    cin >> student.total;
     
    student.perc=(float)student.total/500*100;
}
 // put details of the student
void putDetails(Student student){
    cout << "Name:"<< student.name << ",Roll Number:" << student.rollNo << ",Total:" << student.total << ",Percentage:" << student.perc;
}
 