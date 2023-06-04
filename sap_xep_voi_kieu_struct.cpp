// Mô tả: 
// một cửa hàng có n quyển sách

// mỗi quyển sách có các thông tin:
// 1. mã sách
// 2. tên sách
// 3. tác giả
// 4. giá sách (đây là giá tiền sách)
// 5. số lượng


// Yêu cầu:
// 1. nhập n
// 2. nhập thông tin cho n quyển sách
// 3. in ra thông tin của n quyển sách vừa nhập

// 4. tìm ra những tác giả tên là "An"
// ví dụ: "Ngo Ngoc An" là 1 kết quả đúng
// 

#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

// tạo kiểu dữ liệu bản ghi
struct QuyenSach{
    string maSach;
    string tenSach;
    string tacGia;
    int giaSach;
    int soLuong;
};

// hàm nhập dữ liệu
void NhapDuLieu(QuyenSach mang[SIZE], int do_dai){
    for (int i = 0; i < do_dai; i++)
    {
        cout << "\nNhap thong tin cho quyen sach thu " << i << "\n";
        cout << "Nhap ma sach: ";
        getline(cin, mang[i].maSach, '\n');

        cout << "Nhap ten sach: ";
        getline(cin, mang[i].tenSach, '\n');

        cout << "Nhap ten tac gia: ";
        getline(cin, mang[i].tacGia, '\n');

        cout << "Nhap gia tien sach: ";
        cin >> mang[i].giaSach;
        cin.ignore();

        cout << "Nhap so luong sach: ";
        cin >> mang[i].soLuong;
        cin.ignore();
    }
}

// hàm copy dữ liệu từ mảng Chính sang mảng clone
void Function_Copy_To_Clone(QuyenSach arr[SIZE], int do_dai, QuyenSach clone[SIZE]){
    for (int i = 0; i < do_dai; i++)
    {
        clone[i] = arr[i];
    }    
}

// hàm hiển thị
void HienThi(QuyenSach mang[SIZE],int do_dai){
    cout << "\n------------------------- Hien thi thong tin";
    cout << " -------------------------\n";
    
    for (int i = 0; i < do_dai; i++)
    {
        cout << "\nTHONG TIN QUYEN SACH THU " << i << "\n";
        cout << "Ma sach:\t\t" << mang[i].maSach << "\n";
        cout << "Ten sach:\t\t" << mang[i].tenSach << "\n";
        cout << "Tac gia:\t\t" << mang[i].tacGia << "\n";
        cout << "Gia tien sach:\t\t" << mang[i].giaSach << "\n";
        cout << "So luong sach:\t\t" << mang[i].soLuong << "\n";
    }
}

// hàm đảo ngược chuỗi
string Dao_Nguoc_Chuoi(string thamSo){
    string khoi_tao = "";

    // dùng tính năng cộng chuỗi để đảo ngược chuỗi
    for (int i = thamSo.size() - 1; i >= 0; i--)
    {
        khoi_tao = khoi_tao + thamSo[i];
    }

    return khoi_tao;
}

// hàm tìm sách theo tên tác giả
// input:
// 1. mảng
// 2. độ_dài
// 3. chuỗi tên tác giả (ví dụ: "An")

// output:
// 1. in ra tên sách
// 2. in ra tên tác giả
void Tim_Sach_Theo_Ten_Tac_Gia(QuyenSach mang[SIZE], int do_dai, string ten_tg){
    string ten_nguoc = Dao_Nguoc_Chuoi(ten_tg);
    
    int stt = 1; // số thứ tự

    cout << "\n---------------------- List sach co ten tac gia la: " << ten_tg;
    cout << " ----------------------\n";

    for (int i = 0; i < do_dai; i++)
    {
        // việc 1:
        // đảo ngược cả họ và tên của tác giả
        string ho_ten_nguoc = Dao_Nguoc_Chuoi(mang[i].tacGia);

        // việc 2:
        // tìm thử xem có tên tác giả không
        // nếu có thì sẽ thu được số 0, 1, 2, ...
        // nếu không có thì thu được số -1
        int vi_tri = ho_ten_nguoc.find(ten_nguoc);

        if (vi_tri == -1)
        {
            // không làm gì cả
        }
        else if(vi_tri != -1){
            cout << stt << ". Ten sach: " << mang[i].tenSach << "\t\t\t";
            cout << "Ten tac gia: " << mang[i].tacGia << "\n";
            stt = stt + 1;
        }
    }
}

// hàm tìm sách theo tên và tìm sách theo giá tiền
// input:
// 1. mảng
// 2. độ_dài
// 3. tên_sách (kiểu string)
// 4. giá_tiền (kiểu int)

// output:
// 1. in ra số lượng sách tìm được
void Dem_TenSach_Va_GiaTien(QuyenSach mang[SIZE], int do_dai, string ten_sach, int tien){
    int stt = 1; // số thứ tự
    int dem = 0;

    cout << "\n---------------------- List sach co ten sach la: " << ten_sach;
    cout << ", gia tien: " << tien << " ----------------------\n";
    
    for (int i = 0; i < do_dai; i++)
    {
        // nếu có sách thì sẽ được = 0
        // nếu không có thì sẽ được = -1
        int vi_tri = mang[i].tenSach.find(ten_sach); 
        
        if (vi_tri == -1)
        {
            // thì không làm gì
        }
        else if(vi_tri != -1){
            // đến đây thì kiểm tra giá tiền
            if(mang[i].giaSach == tien){
                cout << stt << ". Ten sach: " << mang[i].tenSach;
                cout << "\t\t\tGia tien: " << mang[i].giaSach << "\n";
                stt = stt + 1;
                dem = dem + 1;
            }
        }
    }

    cout << "\nCo: " << dem << " quyen sach " + ten_sach + "\n";
}

// hàm hiển thị thông tin của những cuốn sách có giá cao nhất
// input:
// 1. mảng
// 2. độ_dai

// output:
// 1. in ra List sách có giá cao nhất
void In_Ra_ThongTinSach_Co_Gia_CaoNhat(QuyenSach mang[SIZE], int do_dai){
    int stt = 1; // số thứ tự
    
    // việc 1:
    // tìm giá cao nhất xem nó bằng bao nhiêu
    int max = mang[0].giaSach;

    cout << "\n------------------------- Lish sach co gia cao nhat";
    cout << " -------------------------\n";

    for (int i = 0; i < do_dai; i++)
    {
        if (max < mang[i].giaSach)
        {
            max = mang[i].giaSach;
        }        
    }

    for (int i = 0; i < do_dai; i++)
    {
        if (max == mang[i].giaSach)
        {
            cout << stt << ". Ten sach: " << mang[i].tenSach << "\n";
            stt = stt + 1;
        }        
    }
}

// hàm tính tổng tiền cho mỗi loại sách
// tổng_tiền = giá_sách * số_lượng
// input:
// 1. mảng
// 2. độ_dài

// output:
// 1. mã sách
// 2. tên sách
// 3. tác giả
// 4. giá sách (đây là giá tiền sách)
// 5. số lượng
// 6. tổng tiền
void In_Ra_TongTien_Cua_Tung_Loai_Sach(QuyenSach mang[SIZE], int do_dai){
    cout << "\n------------------------- List tong tien sach";
    cout << " -------------------------\n";
    
    for (int i = 0; i < do_dai; i++)
    {
        cout << "\nMa sach:\t\t" << mang[i].maSach << "\n";
        cout << "Ten sach:\t\t" << mang[i].tenSach << "\n";
        cout << "Tac gia:\t\t" << mang[i].tacGia << "\n";
        cout << "Gia tien sach:\t\t" << mang[i].giaSach << "\n";
        cout << "So luong sach:\t\t" << mang[i].soLuong << "\n";
        cout << "TONG TIEN = " << mang[i].giaSach * mang[i].soLuong << "\n";
    }
}

// hàm sắp xếp List các cuốn sách theo chiều không giảm của giá sách
// in ra thông tin của danh sách sau khi được sắp xếp
void SapXep_TheoChieuTangDan_Cua_GiaSach(QuyenSach mang[SIZE], int do_dai){
    cout << "\n------------------------- List sap xep theo chieu tang dan cua gia sach";
    cout << " -------------------------\n";
    
    string temp1 = "";
    string temp2 = "";
    string temp3 = "";
    int temp4 = 0;
    int temp5 = 0;

    for (int i = 0; i < do_dai; i++)
    {
        for (int j = i + 1; j < do_dai; j++)
        {
            if (mang[i].giaSach > mang[j].giaSach)
            {
                // sắp xếp mã sách
                temp1 = mang[i].maSach;
                mang[i].maSach = mang[j].maSach;
                mang[j].maSach = temp1;

                // sắp xếp tên sách
                temp2 = mang[i].tenSach;
                mang[i].tenSach = mang[j].tenSach;
                mang[j].tenSach = temp2;

                // sắp xếp tên tác giả
                temp3 = mang[i].tacGia;
                mang[i].tacGia = mang[j].tacGia;
                mang[j].tacGia = temp3;

                // sắp xếp giá tiền
                temp4 = mang[i].giaSach;
                mang[i].giaSach = mang[j].giaSach;
                mang[j].giaSach = temp4;

                // sắp xếp số lượng
                temp5 = mang[i].soLuong;
                mang[i].soLuong = mang[j].soLuong;
                mang[j].soLuong = temp5;
            }
        }        
    }

    for (int i = 0; i < do_dai; i++)
    {
        cout << "\nMa sach:\t\t" << mang[i].maSach << "\n";
        cout << "Ten sach:\t\t" << mang[i].tenSach << "\n";
        cout << "Tac gia:\t\t" << mang[i].tacGia << "\n";
        cout << "Gia tien sach:\t\t" << mang[i].giaSach << "\n";
        cout << "So luong sach:\t\t" << mang[i].soLuong << "\n";
    }
}

int main(){
    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;
    cin.ignore();

    // tạo mảng
    QuyenSach arr[SIZE];

    cout << "\n-------------------- Nhap thong tin cho " << n;
    cout << " quyen sach --------------------\n";

    // gọi hàm nhập dữ liệu
    NhapDuLieu(arr, n);

    QuyenSach clone1[SIZE];
    Function_Copy_To_Clone(arr, n, clone1);

    QuyenSach clone2[SIZE];
    Function_Copy_To_Clone(arr, n, clone2);

    QuyenSach clone3[SIZE];
    Function_Copy_To_Clone(arr, n, clone3);

    QuyenSach clone4[SIZE];
    Function_Copy_To_Clone(arr, n, clone4);

    QuyenSach clone5[SIZE];
    Function_Copy_To_Clone(arr, n, clone5);

    // gọi hàm hiển thị dữ liệu
    HienThi(arr, n);

    // gọi hàm tìm sách theo tên tác giả
    Tim_Sach_Theo_Ten_Tac_Gia(clone1, n, "An");

    // gọi hàm đếm sách theo tên và giá tiền
    // fake nhập vào "Lap trinh" và 100000
    Dem_TenSach_Va_GiaTien(clone2, n, "Lap trinh", 100000);

    // gọi hàm tìm sách có giá tiền lớn nhất
    In_Ra_ThongTinSach_Co_Gia_CaoNhat(clone3, n);

    // gọi hàm in ra tổng số tiền của từng loại sách
    In_Ra_TongTien_Cua_Tung_Loai_Sach(clone4, n);

    // gọi hàm sắp xếp theo chiều tăng dần giá sách
    SapXep_TheoChieuTangDan_Cua_GiaSach(clone5, n);

    cout << "\n\n";

    return 0;
}