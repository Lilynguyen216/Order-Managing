#pragma once
// #include "LinkedList.h"
#include "LinkedList.h"

class HangHoa
{
protected:
    string maHang, tenHang, noiSanXuat, mauSac, ngayNhapKho;
    int giaBan, soLuong;
    
public:
    void operator=(HangHoa x);
    void setMH(string MH) { maHang = MH; }
    string getMH() { return maHang; }

    string getTH() { return tenHang; }
    void setTH(string MH) { tenHang = MH; }

    string getNSX() { return noiSanXuat; }
    void setNSX(string MH) { noiSanXuat = MH; }

    string getMS() { return mauSac; }
    void setMS(string MH) { mauSac = MH; }

    void setGB(int SL) { giaBan = SL; }
    int getGB() { return giaBan; }

    string getNNK() { return ngayNhapKho; }
    void setNNK(string MH) { ngayNhapKho = MH; }

    void setSL(int SL) { soLuong = SL; }
    int getSL() { return soLuong; }

    bool operator == (HangHoa x)
    {
        if (this->maHang == x.maHang && this->tenHang == x.tenHang && this->noiSanXuat == x.noiSanXuat
            && this->mauSac == x.mauSac && this->giaBan == x.giaBan && this->ngayNhapKho == x.ngayNhapKho
            && this->soLuong == x.soLuong)
            return true;
        return false;
    }

    // HangHoa& operator=(const HangHoa& x);
    

    // friend istream& operator >> (istream& is, HangHoa& a);
    friend istream& operator >> (istream& is, HangHoa& a)
    {
        ofstream out("hanghoa.txt", ios_base::app);
        LinkedList<HangHoa> HHList;
        cout << "Nhap ma hang, ten hang, noi san xuat, mau sac, gia ban, ngay nhap kho, so luong\n";

        is >> a.maHang >> a.tenHang >> a.noiSanXuat >> a.mauSac >> a.giaBan >> a.ngayNhapKho >> a.soLuong;

        out << '\n' << a.maHang << '*' << a.tenHang << '*' << a.noiSanXuat
            << '*' << a.mauSac << '*' << a.giaBan << '*'
            << a.ngayNhapKho << '*' << a.soLuong << endl;
        return is;
    }
    // friend ostream& operator << (ostream& os, HangHoa a);
    friend ostream& operator << (ostream& os, HangHoa a)
    {
        os << a.getMH() << setw(5) << a.getTH() << setw(5) << a.getNSX() << setw(5)
            << a.getMS() << setw(5) << a.getGB() << setw(5) << a.getNNK() << setw(5)
            << a.getSL() << setw(5) << endl;
        return os;
    }

    void ofstreamHH(HangHoa a);
    void readListHH(LinkedList<HangHoa>& listHH);
    void ofstreamListHH(LinkedList<HangHoa> listHH);
    void delete1LineHH(LinkedList<HangHoa>& listHH);
    void printListHH(LinkedList<HangHoa> listHH);
    void addListHH(LinkedList<HangHoa>& listHH);
    void alter1LineHH(LinkedList<HangHoa>& listHH);
    void search1HH(LinkedList<HangHoa> listHH);
    void swapGiaBan(HangHoa& hh1, HangHoa& hh2);
    void sortByGiaBan(LinkedList<HangHoa> listHH);
    void sortBySoLuong(LinkedList<HangHoa> listHH);
};
