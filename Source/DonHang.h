#pragma once
#include "HangHoa.h"

class DonHang : public HangHoa
{
protected:
    int status = 0; //0: đang chuẩn bị hàng
    string tenKH, diachiKH, sdt, ngayDatHang, MH_SL;
    int stt, soLuong, tongTien;
public:
    string Datetime()
    {
        // Lấy thời gian hiện tại
        std::time_t currentTime = std::time(nullptr);
        // Chuyển đổi thời gian thành chuỗi
        char timeString[80];

        // Chuyển đổi thời gian thành chuỗi và lưu trữ vào biến timeString
        ctime_s(timeString, sizeof(timeString), currentTime);
        return timeString;
    }
    bool operator == (DonHang x)
    {
        if ((this)->status == x.status && (this)->tenKH == x.tenKH && (this)->diachiKH == x.diachiKH && (this)->sdt == x.sdt
            && (this)->ngayDatHang == x.ngayDatHang && (this)->stt == x.stt && (this)->soLuong == x.soLuong && (this)->tongTien == x.tongTien)
            return true;
        return false;
    }
    DonHang() {}
    DonHang operator &=(const DonHang& dh)
    {
        this->status = dh.status;
        this->tenKH = dh.tenKH;
        this->diachiKH = dh.diachiKH;
        this->sdt = dh.sdt;
        this->ngayDatHang = dh.ngayDatHang;
        this->MH_SL = dh.MH_SL;
        this->soLuong = dh.soLuong;
        this->tongTien = dh.tongTien;
        this->stt = dh.stt;
        return *this;
    }
    void setStatus(int _status) { status = _status; }
    int getStatus() { return status; }
    void setTenKH(string _tenKH) { tenKH = _tenKH; }
    string getTenKH() { return tenKH; }
    void setDiaChiKH(string _diachi) { diachiKH = _diachi; }
    string getDiaChiKH() { return diachiKH; }
    void setSdt(string _sdt) { sdt = _sdt; }
    string getSdt() { return sdt; }
    void setNgayDatHang(string _ngayDH) { ngayDatHang = _ngayDH; }
    string getNgayDatHang() { return ngayDatHang; }
    void setStt(int _stt) { stt = _stt; }
    int getStt() { return stt; }
    void setSL(int _soLuong) { soLuong = _soLuong; }
    int getSL() { return soLuong; }
    void DatHang(vector<DonHang>& listDH, ifstream fileIn, LinkedList<HangHoa>& listHH);
    vector<string> getAddressChar(string line);
    void readFileDH(vector<DonHang>& vecDH);
    void changeListDHbyStr(vector<DonHang>& vecDH, string str, string choice);
    void changeListDHbyInt(vector<DonHang>& vecDH, string str, string choice);
    void delete1LineDH(vector<DonHang>& vecDH, string maHH, string choice);
    void ofstreamCompleteBillsDH(DonHang dh);
    void showListHangHoa();
    void initQueueDH(queue<DonHang>& queDH);
    void search1DH(vector<DonHang> vecDH);
    void findAndChangeSoLuongHH(string line);
    void ofstreamQueue(queue<DonHang> queDH);
    void xuLiTinhTrangDonHang(vector<DonHang> vecDH);
};

