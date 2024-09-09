#include "DonHang.h"
#include "Queue.h"

string checkSTT()
{
    string num = "0", _str;
    ifstream in("donhang.txt", ios_base::in);
    while (getline(in, _str))
    {
        num = _str.substr(0, _str.find('*'));
    }
    in.close();
    return num;
}

int checkSoLuong(string line)
{
    int totalSL = 0;
    stringstream lineStream(line);
    string subLine;
    while (lineStream >> subLine)
    {
        stringstream subLineStream(subLine);
        string subSubLine;
        getline(subLineStream, subSubLine, ':');
        getline(subLineStream, subSubLine, ':');
        totalSL += stoi(subSubLine);
    }
    return totalSL;
}

int checkTongTien()
{
    int tongTien = 0;
    LinkedList<HangHoa> listHH;
    HangHoa hh; hh.readListHH(listHH);
    string line; getline(cin, line);
    string subLine;
    stringstream lineStream(line);
    while (lineStream >> subLine)
    {
        stringstream subLineStream(subLine);
        string subSubLine; getline(subLineStream, subSubLine, ':');
        string _subsl; getline(subLineStream, _subsl, ':');
        // HangHoa hhHead = listHH.getHead()->getData();
        // Node<HangHoa>* _pTemp = new Node<HangHoa>(hhHead);
         Node<HangHoa>* _pTemp = listHH.getHead();
        // for (  _pTemp = listHH.getHead(); _pTemp != NULL; _pTemp = _pTemp->getpNext())
        while (_pTemp != NULL) {
            if (_pTemp->getData().getMH() == subSubLine)
            {
                if (stoi(_subsl) <= _pTemp->getData().getSL())
                {
                    tongTien += _pTemp->getData().getGB() * stoi(_subsl);
                    cout << "Đơn hàng với mã hàng " << subSubLine << " đã được thêm thành công " << endl;
                }
                else
                    cout << "Đơn hàng với mã hàng " << subSubLine << " đã vượt quá số lượng hàng có trong kho" << endl;
            }
            _pTemp = _pTemp->getpNext();
        }
    }
    return tongTien;
}

void DonHang::DatHang(vector<DonHang>& listDH, ifstream fileIn, LinkedList<HangHoa>& listHH)
{
    ofstream out("donhang.txt", ios_base::app);
    DonHang dh;
    cout << setw(5) << " Nhập thông tin khách hàng " << endl;
    cout << "Tên KH: "; getline(cin, dh.tenKH); cin.ignore();
    cout << "Địa chỉ KH: "; getline(cin, dh.diachiKH); cin.ignore();
    cout << "SĐT: "; getline(cin, dh.sdt); cin.ignore();
    cout << "Nhập mã và SL mặt hàng bạn muốn đặt (nhập theo cú pháp: MH1:SL1 MH2:SL2 MH3:SL3): ";
    string line; getline(cin, line);
    int tongTien = checkTongTien();
    cout << "Tổng số tiền cần trả: " << tongTien << endl;
    cout << "Bạn muốn tiếp tục thanh toán ? (1. YES | 2. NO)" << endl << "Nhập lựa chọn của bạn: ";
    int choice; cin >> choice;
    if (choice == 1)
    {
        string _stt = checkSTT();
        if (_stt == "0")
            out << "1" << "*";
        else
        {
            int _sttNextNum = stoi(_stt) + 1;
            out << to_string(_sttNextNum) << "*";
        }
        out << dh.tenKH << "*";
        out << dh.diachiKH << "*";
        out << dh.sdt << "*";
        dh.ngayDatHang = dh.Datetime();
        out << dh.ngayDatHang << "*";
        HangHoa hh; hh.readListHH(listHH);
        stringstream lineStream(line);
        string subLine;
        while (lineStream >> subLine)
        {
            stringstream subLineStream(subLine);
            string subSubLine; getline(subLineStream, subSubLine, ':');
            string _subsl; getline(subLineStream, _subsl, ':');
            Node<HangHoa>* _pTemp;
            // HangHoa* _pTemp;
            for (_pTemp = listHH.getHead(); _pTemp != nullptr; _pTemp = _pTemp->getpNext())
                if (_pTemp->getData().getMH() == subSubLine)
                {
                    if (stoi(_subsl) <= _pTemp->getData().getSL())
                    {
                        // int _newsl = _pTemp->getData().getSL() - stoi(_subsl);
                        // _pTemp->getData().setSL(_newsl);
                        out << subSubLine << ":" << _subsl << " ";
                    }
                }
        }
        out << "*" << tongTien << "*" << dh.status;
        ofstreamListHH(listHH);
    }
    else { // quay trở về trang chủ
    }
}

vector<string> DonHang::getAddressChar(string line)
{
    vector<string> vecAddress;
    for (int i = 0; i < line.length(); i++)
        if (line[i] == '*')
            vecAddress.push_back(&line[i]);
    return vecAddress;
}

void DonHang::readFileDH(vector<DonHang>& vecDH)
{
    ifstream in("donhang.txt", ios_base::in);
    DonHang dh;
    string line;
    while (getline(in, line))
    {
        stringstream lineStream(line);
        string subLine;
        int indexSubLine = 1;
        getline(lineStream, subLine, '*'); dh.stt = stoi(subLine);
        getline(lineStream, subLine, '*'); dh.tenKH = subLine;
        getline(lineStream, subLine, '*'); dh.diachiKH = subLine;
        getline(lineStream, subLine, '*'); dh.sdt = subLine;
        getline(lineStream, subLine, '*'); dh.ngayDatHang = subLine;
        getline(lineStream, subLine, '*'); dh.MH_SL = subLine;
        getline(lineStream, subLine, '*'); dh.tongTien = stoi(subLine);
        getline(lineStream, subLine, '*'); dh.status = stoi(subLine);
        vecDH.push_back(dh);
    }
    in.close();
}

void DonHang::showListHangHoa()
{
    vector<DonHang> vecDH;
    readFileDH(vecDH);
    cout << setw(15) << "Danh sách đơn hàng" << endl;
    cout << "STT" << setw(5) << "Tên KH" << setw(5) << "Địa chỉ KH" << setw(5)
        << "Ngày đặt" << setw(5) << "Mặt hàng - SL" << setw(5) << "Tổng tiền" << setw(5)
        << "Tình trạng" << endl;
    for (auto x : vecDH)
    {
        cout << x.stt << setw(5) << x.tenKH << setw(5)
            << x.diachiKH << setw(5) << x.sdt << setw(5)
            << x.ngayDatHang << setw(5) << x.MH_SL << setw(5)
            << x.tongTien << setw(5);
        if (x.status == 0)
            cout << "Đang chuẩn bị hàng" << endl;
        else if (x.status == 1)
            cout << "Đang giao hàng" << endl;
        else if (x.status == 2)
            cout << "Giao thành công" << endl;
        else if (x.status == 3)
            cout << "Bị huỷ" << endl;
    }
}

void DonHang::initQueueDH(queue<DonHang>& queDH)
{
    DonHang dh;
    string line;
    ifstream in("donhang.txt", ios_base::in);
    while (getline(in, line))
    {
        stringstream lineStream(line);
        string subLine;
        int indexSubLine = 1;
        getline(lineStream, subLine, '*'); dh.stt = stoi(subLine);
        getline(lineStream, subLine, '*'); dh.tenKH = subLine;
        getline(lineStream, subLine, '*'); dh.diachiKH = subLine;
        getline(lineStream, subLine, '*'); dh.sdt = subLine;
        getline(lineStream, subLine, '*'); dh.ngayDatHang = subLine;
        getline(lineStream, subLine, '*'); dh.MH_SL = subLine;
        getline(lineStream, subLine, '*'); dh.tongTien = stoi(subLine);
        getline(lineStream, subLine, '*'); dh.status = stoi(subLine);
        queDH.enQueue(dh);
    }
    in.close();
}

// void DonHang::ofstreamFileDHbyQueue (que)

void DonHang::ofstreamQueue(queue<DonHang> queDH)
{
    ofstream out("temp.txt", ios_base::out);
    while (!queDH.isEmpty())
    {
        out << queDH.peek().stt << "*" << queDH.peek().tenKH << "*"
            << queDH.peek().diachiKH << "*" << queDH.peek().sdt << "*"
            << queDH.peek().ngayDatHang << "*" << queDH.peek().MH_SL << "*"
            << queDH.peek().tongTien << "*" << queDH.peek().status << endl;
        queDH.deQueue();
    }
    rename("temp.txt", "donhang.txt");
    out.close();
}

void DonHang::search1DH(vector<DonHang> vecDH)
{
    cout << setw(5) << "Tìm kiếm đơn hàng";
    cout << "Nhập STT đơn hàng cần tìm: ";
    int _stt; cin >> _stt;
    bool checkVari = false;
    for (auto dh : vecDH)
    {
        if (dh.stt == stt)
        {
            cout << dh.sdt << setw(5) << dh.tenKH << setw(5) << dh.diachiKH << setw(5)
                << dh.sdt << setw(5) << dh.ngayDatHang << setw(5) << dh.MH_SL << setw(5)
                << dh.tongTien << setw(5) << dh.status << endl;
            checkVari = true;
        }
    }
    if (!checkVari)
        cout << "Không tìm thấy STT đơn hàng trong list Đơn Hàng" << endl;
}

void DonHang::findAndChangeSoLuongHH(string line)
{
    ifstream in("hanghoa.txt", ios_base::in);
    LinkedList<HangHoa> listHH;
    HangHoa hh;
    hh.readListHH(listHH);
    stringstream lineStream(line);
    string subLine;
    while (lineStream >> subLine)
    {
        stringstream subLineStream(subLine);
        string subSubLine; getline(subLineStream, subSubLine, ':');
        string _subsl; getline(subLineStream, _subsl, ':');
        Node<HangHoa>* _pTemp;
        for (_pTemp = listHH.getHead(); _pTemp != NULL; _pTemp = _pTemp->getpNext())
        {
            if (_pTemp->getData().getMH() == subSubLine)
            {
                if (stoi(_subsl) <= _pTemp->getData().getSL())
                {
                    int _newsl = _pTemp->getData().getSL() - stoi(_subsl);
                    _pTemp->getData().setSL(_newsl);
                }
            }
        }
    }
    hh.ofstreamListHH(listHH);
}

void DonHang::xuLiTinhTrangDonHang(vector<DonHang> vecDH)
{
    ifstream in("donhang.txt", ios_base::in);
    queue<DonHang> queDH;
    initQueueDH(queDH);
    cout << setw(5) << "Đơn hàng cần xử lí " << endl;
    cout << queDH.peek().tenKH << setw(5) << queDH.peek().diachiKH << setw(5)
        << queDH.peek().sdt << setw(5) << queDH.peek().ngayDatHang << setw(5)
        << queDH.peek().MH_SL << setw(5) << queDH.peek().tongTien << setw(5);
    if (queDH.peek().status == 0)
        cout << "Đang chuẩn bị hàng" << endl;
    else if (queDH.peek().status == 1)
        cout << "Đang giao hàng" << endl;
    else if (queDH.peek().status == 2)
        cout << "Giao thành công" << endl;
    else if (queDH.peek().status == 3)
        cout << "Bị huỷ" << endl;
    cout << "Cập nhật tình trạng đơn hàng: " << endl;
    cout << "1. Đang giao hàng" << endl << "2. Đã giao thành công" << endl << "3. Huỷ đơn hàng";
    string choice;
    do
    {
        cout << "Nhập lựa chọn (or \"c:\" cancel): ";
        cin >> choice;
        if (choice == "c" || choice == "C")
        {
            // trở về trang chủ
        }
        if ((stoi(choice) <= 0 || stoi(choice) > 3) && stoi(choice) <= queDH.peek().status)
            cout << "Input không hợp lệ" << endl;
    } while ((stoi(choice) <= 0 || stoi(choice) > 3) && stoi(choice) <= queDH.peek().status);
    if (stoi(choice) == 2 || stoi(choice) == 3)
    {
        if (stoi(choice) == 2)
        {
            cout << "Đã xử lí đơn hàng thành công" << endl;
            findAndChangeSoLuongHH(queDH.peek().MH_SL);
        }
        else
            cout << "Đơn hàng đã bị huỷ" << endl;
        queDH.deQueue();
    }
    else if (stoi(choice) == 1)
    {
        queDH.peek().setStatus(1);
    }
    ofstreamQueue(queDH);
}

void DonHang::ofstreamCompleteBillsDH(DonHang dh)
{
    ofstream out("completed.txt", ios_base::app);
    out << dh << endl;
    out.close();
}

void DonHang::delete1LineDH(vector<DonHang>& vecDH, string maHH, string choice)
{
    vector<DonHang>::iterator it;
    for (it = vecDH.begin(); it != vecDH.end(); ++it)
        if (it->maHang == maHH)
            break;
    if (choice == "ht") // ht: hoàn thành
        ofstreamCompleteBillsDH(*it);
    vecDH.erase(remove(vecDH.begin(), vecDH.end(), *it));
    ofstream newFileOut("temp.txt", ios_base::app);
    for (auto x : vecDH)
        newFileOut << x << endl;
    rename("temp.txt", "donhang.txt");
    newFileOut.close();
}

