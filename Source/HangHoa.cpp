#include "HangHoa.h"

// istream& operator >> (istream& is, HangHoa& a) 
// {
// 	// ofstream out("hanghoa.txt", ios::app);
//     // LinkedList<HangHoa> HHList;
// 	cout << "Nhap ma hang, ten hang, mau sac, gia ban, so luong\n";

// 	is >> a.maHang >> a.tenHang >> a.noiSanXuat >> a.mauSac >> a.giaBan >> a.ngayNhapKho >> a.soLuong;

// 	// out << '\n' << a.maHang << '*' << a.tenHang << '*' << a.noiSanXuat
// 	// 	<< '*' << a.mauSac << '*' << a.giaBan << '*'
// 	// 	<< a.ngayNhapKho << '*' << a.soLuong;
// 	return is;
// }

// ostream& operator << (ostream& os, HangHoa a)
// {
//     os << a.getMH() << setw(5) << a.getTH() << setw(5) << a.getNSX() << setw(5) 
//         << a.getMS() << setw(5) << a.getGB() << setw(5) << a.getNNK() << setw(5) 
//         << a.getSL() << setw(5) << endl;
//     return os;
// }

void HangHoa::readListHH(LinkedList<HangHoa>& listHH)
{
    ifstream in("hanghoa.txt");
    HangHoa hh;
    string str;
    while (getline(in, str))
    {
        stringstream ss(str);
        getline(ss, str, '*'); hh.maHang = str;
        getline(ss, str, '*'); hh.tenHang = str;
        getline(ss, str, '*'); hh.noiSanXuat = str;
        getline(ss, str, '*'); hh.mauSac = str;
        getline(ss, str, '*'); hh.giaBan = stoi(str);
        getline(ss, str, '*'); hh.ngayNhapKho = str;
        getline(ss, str, '*'); hh.soLuong = stoi(str);
        listHH.addTail(hh);
    }
}

void HangHoa::ofstreamHH(HangHoa a)
{
    ofstream out("hanghoa.txt", ios::app);
    out << '\n' << a.maHang << '*' << a.tenHang << '*' << a.noiSanXuat
        << '*' << a.mauSac << '*' << a.giaBan << '*'
        << a.ngayNhapKho << '*' << a.soLuong;
}

void HangHoa::ofstreamListHH(LinkedList<HangHoa> listHH)
{
    ofstream out("temp.txt", ios_base::out);
    Node<HangHoa>* pTemp;
    for (pTemp = listHH.getHead(); pTemp != listHH.getTail(); pTemp = pTemp->getpNext())
    {
        out << pTemp->getData().getMH() << "*" << pTemp->getData().getTH() << "*"
            << pTemp->getData().getNSX() << "*" << pTemp->getData().getMS() << "*"
            << pTemp->getData().getGB() << "*" << pTemp->getData().getNNK() << "*"
            << pTemp->getData().getSL();
    }
    //remove("hanghoa.txt");
    rename("temp.txt", "hanghoa.txt");
    out.close();
}

void HangHoa::printListHH(LinkedList<HangHoa> listHH)
{
    Node<HangHoa>* p;
    for (p = listHH.getHead(); p != listHH.getTail(); p = p->getpNext())
        cout << p->getData() << endl;
}

void HangHoa::delete1LineHH(LinkedList<HangHoa>& listHH)
{
    cout << "Nhập mã mặt hàng bạn muốn xoá: ";
    string maHH; cin >> maHH;
    readListHH(listHH);
    Node<HangHoa>* p;
    ofstream out("temp.txt", ios_base::out);
    for (p = listHH.getHead(); p != listHH.getTail(); p = p->getpNext())
    {
        if (p->getData().maHang == maHH)
            listHH.searchDataAndRemove(p->getData());
    }
    ofstreamListHH(listHH);
}

void HangHoa::addListHH(LinkedList<HangHoa>& listHH)
{
    HangHoa a;
    cout << setw(5) << "Nhập thông tin mặt hàng cần thêm" << endl;
    cout << "Nhap ma hang, ten hang, noi san xuat, mau sac, gia ban, ngay nhap kho, so luong\n";
    string str; cin >> a.maHang >> a.tenHang >> a.noiSanXuat >> a.mauSac >> a.giaBan >> a.ngayNhapKho >> a.soLuong;
    ofstream out("hanghoa.txt", ios_base::app);
    out << a.getMH() << "*" << a.getTH() << "*" << a.getNSX() << "*"
        << a.getMS() << "*" << a.getGB() << "*" << a.getNNK() << "*" << a.getSL();
    out.close();
}

void HangHoa::alter1LineHH(LinkedList<HangHoa>& listHH)
{
    cout << "Nhập mã mặt hàng bạn muốn thay đổi thuộc tính: ";
    string maHH; cin >> maHH;
    cout << "Nhập thuộc tính bạn muốn thay đổi: " << endl;
    cout << "1. Tên hàng " << endl << "2. Màu sắc" << endl << "3. Giá bán" << endl << "4.Số lượng";
    int choice; cin >> choice;
    readListHH(listHH);
    Node<HangHoa>* p;
    ofstream out("temp.txt", ios_base::out);
    for (p = listHH.getHead(); p != listHH.getTail(); p = p->getpNext())
    {
        if (p->getData().maHang == maHH)
        {
            if (choice == 1)
            {
                cout << "Nhập tên hàng mới: "; string _str; cin >> _str;
                p->getData().tenHang = _str;
            }
            else if (choice == 2)
            {
                cout << "Nhập màu sắc mới: "; string _str; cin >> _str;
                p->getData().mauSac = _str;
            }
            else if (choice == 3)
            {
                cout << "Nhập giá bán mới cho mặt hàng: "; int _str; cin >> _str;
                p->getData().setGB(_str);
            }
            else if (choice == 4)
            {
                cout << "Nhập số lượng mới cho mặt hàng: "; int _str; cin >> _str;
                p->getData().setSL(_str);
            }
        }
    }
    ofstreamListHH(listHH);
}

void HangHoa::search1HH(LinkedList<HangHoa> listHH)
{
    cout << "Nhập mã hàng bạn cần tìm kiếm: "; string _str; cin >> _str;
    ifstream in("hanghoa.txt", ios_base::in);
    cout << setw(5) << "Thông tin mặt hàng" << endl;
    bool checkVari = false;
    Node<HangHoa>* pTemp;
    for (pTemp = listHH.getHead(); pTemp != listHH.getTail(); pTemp = pTemp->getpNext())
    {
        if (pTemp->getData().maHang == _str)
        {
            cout << pTemp->getData();
            checkVari = true;
        }
    }
    if (!checkVari)
        cout << "Không có sản phẩm bạn cần tìm trong danh sách hàng hoá" << endl;
}

void HangHoa::swapGiaBan(HangHoa& hh1, HangHoa& hh2)
{
    float temp = hh1.giaBan;
    hh1.giaBan = hh2.giaBan;
    hh2.giaBan = temp;
}


void HangHoa::sortByGiaBan(LinkedList<HangHoa> listHH)
{
    readListHH(listHH);
    Node<HangHoa>* pTemp, * qTemp, * minNode;
    for (pTemp = listHH.getHead(); pTemp != listHH.getTail(); pTemp = pTemp->getpNext())
    {
        minNode = pTemp;
        for (qTemp = pTemp->getpNext(); qTemp != listHH.getTail(); qTemp = qTemp->getpNext())
        {
            if (qTemp->getData().getGB() < minNode->getData().getGB())
                minNode = qTemp;
        }
        Node<HangHoa>* _tempp;
        _tempp->setData(pTemp->getData());
        pTemp->setData(minNode->getData());
        minNode->setData(_tempp->getData());
    }
    printListHH(listHH);
}

void HangHoa::sortBySoLuong(LinkedList<HangHoa> listHH)
{
    readListHH(listHH);
    Node<HangHoa>* pTemp, * qTemp, * minNode;
    for (pTemp = listHH.getHead(); pTemp != listHH.getTail(); pTemp = pTemp->getpNext())
    {
        minNode = pTemp;
        for (qTemp = pTemp->getpNext(); qTemp != listHH.getTail(); qTemp = qTemp->getpNext())
        {
            if (qTemp->getData().getSL() < minNode->getData().getSL())
                minNode = qTemp;
        }
        Node<HangHoa>* _tempp; _tempp->setData(pTemp->getData());
        pTemp->setData(minNode->getData());
        minNode->setData(_tempp->getData());
    }
    printListHH(listHH);
}

void HangHoa::operator=(HangHoa x)
{
    this->maHang = x.maHang;
    this->tenHang = x.tenHang;
    this->noiSanXuat = x.noiSanXuat;
    this->mauSac = x.mauSac;
    this->giaBan = x.giaBan;
    this->ngayNhapKho = x.ngayNhapKho;
    this->soLuong = x.soLuong;
}
