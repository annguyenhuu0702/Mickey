#include <iostream>
using namespace std;
#define MAX 10
class student
{
    private:
        char name[30];
        int rollNo;
        int total;
        float perc;
    public:
        void getDetails(void);
        void putDetails(void);
};

void student::getDetails(void){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter roll number: ";
    cin >> rollNo;
    cout << "Enter total marks out of 500: ";
    cin >> total;
    perc = (float)total/500*100;
}

void student::putDetails(void){
    cout << "Name: " << ", Roll Number: " << rollNo << ", Total: " << total << ", Percentage: " << perc;
}

int main()
{
    student students[MAX];
    int n, loop;
    cout << "Enter total number of student: ";
    cin >> n;
    for(loop=0; loop<n; loop++){
        cout << "Enter details of student " << loop+1 << ":\n";
        students[loop].getDetails();
    }
    for(loop=0; loop<n; loop++){
        cout << endl << "Details of student " << (loop+1) << ":\n";
        students[loop].putDetails();
    }
    return 0;
}