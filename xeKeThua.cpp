#include <iostream>
using namespace std;
#include <string>
class Xe
{
private:
    string BienSo;
    float TrongLuong;

public:
    Xe();
    ~Xe();
    float Get_TrongLuong()
    {
        return TrongLuong;
    }
    void Nhap();
    void Xuat();
};
Xe::Xe()
{
    BienSo = "";
    TrongLuong = 0;
}
Xe::~Xe()
{
}
void Xe::Nhap()
{
    cin.ignore();
    cout << "Nhap vao bien so: ";
    getline(cin, BienSo);
    cout << "Nhap vao trong luong(kg): ";
    cin >> TrongLuong;
}
void Xe::Xuat()
{
    cout << "Bien So: " << BienSo << endl;
    cout << "Trong Luong: " << TrongLuong << " kg" << endl;
}

class XeCon : public Xe
{
private:
    int SoChoNgoi;

public:
    XeCon();
    ~XeCon();
    int Get_SoChoNgoi()
    {
        return SoChoNgoi;
    }
    void Nhap();
    void Xuat();
    void TrongLuong_Min(XeCon *xc, int n);
    void SoSanh_SCN(XeCon *xc, int n);
};
void Nhap_DS_XeCon(XeCon *xc, int n);
void Xuat_DS_XeCon(XeCon *xc, int n);
XeCon::XeCon()
{
    SoChoNgoi = 0;
}
XeCon::~XeCon()
{
}
void XeCon::Nhap()
{
    Xe::Nhap();
    cout << "Nhap so cho ngoi: ";
    cin >> SoChoNgoi;
}
void XeCon::Xuat()
{
    Xe::Xuat();
    cout << "So Cho Ngoi: " << SoChoNgoi << endl;
}
void Nhap_DS_XeCon(XeCon *xc, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap Xe Con thu " << i + 1 << endl;
        (xc + i)->Nhap();
    }
}
void Xuat_DS_XeCon(XeCon *xc, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nXe Con thu " << i + 1 << endl;
        (xc + i)->Xuat();
    }
}
void XeCon::TrongLuong_Min(XeCon *xc, int n)
{
    int temp = 0;
    float min = (xc + 0)->Get_TrongLuong();
    for (int i = 0; i < n; i++)
    {
        if ((xc + i)->Get_TrongLuong() < min)
        {
            min = (xc + i)->Get_TrongLuong();
            temp = i;
        }
    }
    (xc + temp)->Xuat();
}


void XeCon::SoSanh_SCN(XeCon *xc, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((xc + i)->Get_SoChoNgoi() == 7)
        {
            (xc + i)->Xuat();
        }
    }
}
class XeTai : public Xe
{
private:
    float TaiTrong;

public:
    XeTai();
    ~XeTai();
    float Get_TaiTrong()
    {
        return TaiTrong;
    }
    void Nhap();
    void Xuat();
    void KT_TaiTrong(XeTai *xt, int m);
};
void Nhap_DS_XeTai(XeTai *xt, int m);
void Xuat_DS_XeTai(XeTai *xt, int m);
XeTai::XeTai()
{
    TaiTrong = 0;
}
XeTai::~XeTai()
{
}
void XeTai::Nhap()
{
    Xe::Nhap();
    cout << "Nhap Tai Trong: ";
    cin >> TaiTrong;
}
void XeTai::Xuat()
{
    Xe::Xuat();
    cout << "Tai Trong: " << TaiTrong << endl;
}
void Nhap_DS_XeTai(XeTai *xt, int m)
{

    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap Xe Tai thu " << i + 1 << endl;
        (xt + i)->Nhap();
    }
}
void Xuat_DS_XeTai(XeTai *xt, int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << "\nXe Tai thu " << i + 1 << endl;
        (xt + i)->Xuat();
    }
}
void XeTai::KT_TaiTrong(XeTai *xt, int m)
{
    for (int i = 0; i < m; i++)
    {
        if ((xt + i)->Get_TaiTrong() == 5000)
        {
            cout<<"\nXe Tai thu "<<i + 1<<endl;
            (xt + i)->Xuat();
        }
    }
}
int main()
{
    int n, m, luachon;
    XeCon *xc;
    XeTai *xt;

    while (true)
    {
        system("cls");
        cout << "\n 1. Nhap thong tin";
        cout << "\n 2. Xuat thong tin";
        cout << "\n 3. Xe Con co trong luong nho nhat";
        cout << "\n 4. Xe con co So Cho Ngoi = 7";
        cout << "\n 5. Xe Tai co Tai Trong bang 5000kg";
        cout << "\n 6. Thoat";

        cout << "\nNhap lua chon cua ban: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            cout << "\nNhap vao so luong Xe Con: ";
            cin >> n;
            xc = new XeCon[n];
            Nhap_DS_XeCon(xc, n);
            cout << "\nNhap vao so luong Xe Tai: ";
            cin >> m;
            xt = new XeTai[m];
            Nhap_DS_XeTai(xt, m);
            break;
        }
        case 2:
        {
            Xuat_DS_XeCon(xc, n);
            Xuat_DS_XeTai(xt, m);
            system("pause");
            break;
        }
        case 3:
        {
            xc->TrongLuong_Min(xc, n);
            system("pause");
            break;
        }
        case 4:
        {
            xc->SoSanh_SCN(xc, n);
            system("pause");
            break;
        }
        case 5:
        {
            xt->KT_TaiTrong(xt, m);
            system("pause");
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            cout << "\nLua chon khong hop le. Xin vui long kiem tra lai!!!" << endl;
            system("pause");
            break;
        }
        }
    }
    return 0;
}