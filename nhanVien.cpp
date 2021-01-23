#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class Nhanvien
{
    private:
       int MaNV;
       string Hoten;
       int NS;
       string Phongban;
       float Luong;
    public:
       Nhanvien();
       Nhanvien(int MaNV, string Hoten, int NS, string Phongban, float Luong);
       ~Nhanvien();
       friend istream &operator>>(istream &is,Nhanvien &NV);
       friend ostream &operator<<(ostream &os,Nhanvien &NV);
       bool operator>(Nhanvien NV);
       bool operator<(Nhanvien NV);
       bool operator== (Nhanvien NV);
       float getLuong();
       int getNS();
};
//hàm tạo không có tham số
Nhanvien::Nhanvien()
{
    this->MaNV = 0;
    this->Hoten = "Mickey";
    this->NS = 0;
    this->Phongban = "0";
    this->Luong = 0;
}
//hàm tạo đầy đủ tham số
Nhanvien::Nhanvien(int MaNV, string Hoten, int NS, string Phongban, float Luong)
{
    this->MaNV = MaNV;
    this->Hoten = Hoten;
    this->NS = NS;
    this->Phongban = Phongban;
    this->Luong = Luong;
}
//toán tử hủy
Nhanvien::~Nhanvien(){}
//toán tử nhập
istream &operator >> (istream &is, Nhanvien &NV)
{   
    cout<<"Nhap ma nhan vien: ";
    is>>NV.MaNV;
    cout<<"Nhap ho ten: ";
    cin.ignore();
    getline(is,NV.Hoten);
    cout<<"Nhap nam sinh ";
    is>>NV.NS;
    cout<<"Nhap phong ban: ";
    cin.ignore();
    getline(is,NV.Phongban);
    cout<<"Nhap luong: ";
    is>>NV.Luong;
    return is;
}
//toán tử xuất 
ostream &operator <<(ostream &os, Nhanvien &NV)
{
    cout<<"Ma nhan vien: "<<NV.MaNV<<endl;
    cout<<"Ho ten: "<<NV.Hoten<<endl;
    cout<<"Nam sinh: "<<NV.NS<<endl;
    cout<<"Phong ban:"<<NV.Phongban<<endl;
    cout<<"Luong: "<<NV.Luong<<endl;
    return os;
}
//toán tử lấy lương nhân viên
float Nhanvien::getLuong()
{
    return this->Luong;
}
//toán tử lấy năm sinh nhân viên
int Nhanvien::getNS()
{
    return this->NS;
}
//toán tử so sánh
bool Nhanvien::operator>(Nhanvien NV)
{
    return this->Luong > NV.Luong ? 1 : 0;
}
bool Nhanvien::operator<(Nhanvien NV)
{
    return this->Luong < NV.Luong ? 1 : 0;
}
bool Nhanvien::operator==(Nhanvien NV)
{
    return this->Luong == NV.Luong ? 1 : 0;
}
//nhập danh sách nhân viên
void nhapDSNV(int n,Nhanvien *NV)
{
    for(int i=0;i<n;i++)
    {
        cin>>*(NV+i);
    }
}
//xuất danh sách nhân viên
void xuatDSNV(int n,Nhanvien *NV)
{
    for(int i=0;i<n;i++)
    {
        cout<<"======="<<endl;
        cout<<"STT: "<<i+1<<endl;
        cout<<*(NV+i);
    }
}
//sắp xếp nhân viên theo thứ tự lương giảm dần
void sapXepLuong(int n, Nhanvien *NV)
{
    Nhanvien temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((NV+i)->getLuong()<(NV+j)->getLuong())
            {
                temp=*(NV+i);
                *(NV+i)=*(NV+j);
                *(NV+j)=temp;
            }
        }
    }
    xuatDSNV(n,NV);
}
//sắp xếp nhân viên theo năm sinh tăng dần
void sapXepNS(int n,Nhanvien *NV)
{
    Nhanvien temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((NV+i)->getNS()>(NV+j)->getNS())
            {
                temp=*(NV+i);
                *(NV+i)=*(NV+j);
                *(NV+j)=temp;
            }
        }
    }
    xuatDSNV(n,NV);
}
//thống kê số lượng nhân viên lớn hơn 10 triệu
void thongKeLuong(int n,Nhanvien *NV)
{
    int SLNV=0;
    for(int i=0;i<n;i++)
    {
        if((NV+i)->getLuong()>=10000000)
        {
            SLNV++;
        }
    }
     cout<<"So luong nhan vien luong lon hon 10 trieu: "<<SLNV<<endl;
}
int main()
{
    {
    Nhanvien *NV;
    int n,luachon;
    while(1)
    {
        cout<<"Moi ban lua chon chuc nang: "<<endl;
        cout<<"1.Nhap danh sach nhan vien: "<<endl;
        cout<<"2.Xuat danh sach nhan vien: "<<endl;
        cout<<"3.Sap xep nhan vien theo thu tu luong giam dan "<<endl;
        cout<<"4.Sap xep nhan vien theo thu tu nam sinh tang dan "<<endl;
        cout<<"5.Thong ke so luong nhan vien co luong >= 10 trieu "<<endl;
        cout<<"6.Thoat "<<endl;
        cin>>luachon;
        switch(luachon)
        {
            case 1:
                cout <<"Nhap so luong nhan vien: ";
                cin>>n;
                NV = new Nhanvien[n];
                nhapDSNV(n,NV);
                break;
            case 2:
                xuatDSNV(n,NV);
                break;
            case 3:
                sapXepLuong(n,NV);
                break;
            case 4:
                sapXepNS(n,NV);
                break;
            case 5:
                thongKeLuong(n,NV);
                break;
            case 6:
                exit(0);
        }        
    }
}
return 0;
system("pause");
}