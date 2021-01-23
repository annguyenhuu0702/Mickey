#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class Sinhvien
{
    private:
        int MSV;
        string Hoten;
        int NamSinh;
        string Lop;
        float DTB;
    public:
        Sinhvien();
        Sinhvien(int MSV, string Hoten, int NamSinh,string Lop, float DTB);
        ~Sinhvien();
        friend istream &operator>>(istream &is, Sinhvien &SV);
        friend ostream &operator<<(ostream &os, Sinhvien &SV);
        bool operator>(Sinhvien SV);
        bool operator<(Sinhvien SV);
        bool operator==(Sinhvien SV);
        float getDTB();
        int getNamsinh();
};
//hàm tạo không có tham số
Sinhvien::Sinhvien()
{
    this->MSV = 000;
    this->NamSinh = 000;
    this->Hoten = "Mickey";
    this->Lop = "CNTT";
    this->DTB = 10;
}
//hàm tạo có tham số
Sinhvien::Sinhvien(int MSV, string Hoten,int Namsinh, string Lop, float DTB)
{
    this->MSV = MSV;
    this->Hoten = Hoten;
    this->NamSinh = Namsinh;
    this->Lop = Lop;
    this->DTB = DTB;
}
//hàm hủy
Sinhvien::~Sinhvien(){}
//toán tử nhập
istream &operator >> (istream &is, Sinhvien &SV){
    cout<<"Nhap ma so sinh vien: ";
    is>>SV.MSV;
    cout<<"Nhap ho ten: ";
    cin.ignore();
    getline(is,SV.Hoten);
    cout<<"Nhap nam sinh: ";
    is>>SV.NamSinh;
    cout<<"Nhap lop: ";
    cin.ignore();
    getline(is,SV.Lop);
    cout<<"Nhap diem trung binh: ";
    is>>SV.DTB;
    return is;
}
ostream &operator <<(ostream &os, Sinhvien &SV){
    cout <<"Ma so sinh vien: " <<SV.MSV<<endl;
    cout <<"Ho ten: " <<SV.Hoten<<endl;
    cout <<"Nam sinh: "<<SV.NamSinh<<endl;
    cout <<"Lop: "<<SV.Lop<<endl;
    cout <<"Diem trung binh: "<<SV.DTB<<endl;
    return os;
}
//toán tử so sánh >
bool Sinhvien::operator>(Sinhvien SV){
    return this->DTB>SV.DTB ? 1 : 0;
}
//toán tử so sánh <
bool Sinhvien::operator<(Sinhvien SV){
    return this->DTB<SV.DTB ? 1 : 0;
}
//toán tử so sánh ==
bool Sinhvien::operator==(Sinhvien SV){
    return this->DTB==SV.DTB ? 1 : 0;
}
//hàm lấy điểm trung bình 
float Sinhvien::getDTB(){
    return this->DTB;
}
//hàm lấy năm sinh
int Sinhvien::getNamsinh(){
    return this->NamSinh;
}
//nhập danh sách sinh viên
void nhapDSSV(int n, Sinhvien *SV){
    for(int i=0;i<n;i++){
       cin >> *(SV+i);
    }
}
//xuất danh sách sinh viên
void xuatDSSV(int n,Sinhvien *SV){
    for(int i=0;i<n;i++){
        cout<<"============="<<endl;
        cout<<"STT: "<<i+1<<endl;
        cout<<*(SV+i);
    }
}
//sắp xếp điểm trung bình giảm dần
void sapXepDTB(int n, Sinhvien *SV)
{
    Sinhvien temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((SV+i)->getDTB()<(SV+j)->getDTB())
            {
                temp=*(SV+i);
                *(SV+i)=*(SV+j);
                *(SV+j)=temp;
            }
        }
    }
    xuatDSSV(n,SV);
}
//sắp xếp năm sinh tăng dần
void sapXepNS(int n, Sinhvien *SV)
{
    Sinhvien temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((SV+i)->getNamsinh()>(SV+j)->getNamsinh())
            {
                temp=*(SV+i);
                *(SV+i)=*(SV+j);
                *(SV+j)=temp;
            }
        }
    }
    xuatDSSV(n,SV);
}
//thống kê số lượng sinh viên bị canh(điểm trung bình < 1 -->cảnh cáo)
void thongKe(int n,Sinhvien *SV)
{
    int SLCC=0;
    for(int i=0;i<n;i++)
    {
        if((SV+i)->getDTB()<1)
        {
            SLCC++;
        }
    }
    cout <<"So luong sinh vien bi cao: "<<SLCC<<endl;
}
int main()
{
    Sinhvien *SV;
    int n,luachon;
    while(1)
    {
        cout<<"Moi ban lua chon chuc nang: "<<endl;
        cout<<"1.Nhap danh sach sinh vien: "<<endl;
        cout<<"2.Xuat danh sach sinh vien: "<<endl;
        cout<<"3.Sap xep sinh vien theo thu tu diem trung binh giam dan "<<endl;
        cout<<"4.Sap xep sinh vien theo thu tu nam sinh tang dan "<<endl;
        cout<<"5.Thong ke so luong sinh vien thuoc dien canh cao hoc tap (DTB<1) "<<endl;
        cout<<"6.Thoat "<<endl;
        cin>>luachon;
        switch(luachon)
        {
            case 1:
                cout <<"Nhap so luong sinh vien: ";
                cin>>n;
                SV = new Sinhvien[n];
                nhapDSSV(n,SV);
                break;
                getch();
            case 2:
                xuatDSSV(n,SV);
                break;
                getch();
            case 3:
                sapXepDTB(n,SV);
                break;
                getch();
            case 4:
                sapXepNS(n,SV);
                break;
                getch();
            case 5:
                thongKe(n,SV);
                break;
                getch();
            case 6:
                exit(0);
        }
    }
return 0;
system("pause");
}