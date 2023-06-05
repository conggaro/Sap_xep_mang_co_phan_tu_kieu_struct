// Mô tả:
// cho n loại nấm (n <= 1000)
// loại nấm thứ 1 có độ dinh dưỡng a (kiểu int)
// loại nấm thứ 1 có độc tố là b (kiểu int)

// người dân thì hái nấm về ăn
// để đảm bảo dinh dưỡng thì cây nấm kiểu:
// dinh dưỡng gấp đôi độc tố
// dinh_dưỡng = độc_tố x 2

// Yêu cầu:
// 1. nhập n
// 2. nhập thông tin cho n cây nấm
// 3. in ra thông tin nấm có thể ăn được (dinh_dưỡng, độc_tố)
// 4. in ra nấm có độc tố cao nhất

// 5. sắp xếp danh sách nấm theo mức dinh dưỡng
// dinh dưỡng tăng dần

#include <iostream>
#include <vector>
using namespace std;

// tạo kiểu dữ liệu bản ghi "Cây Nấm"
struct CayNam{
    int dinh_duong; // dinh dưỡng
    int doc_to;     // độc tố
};

// hàm hiển thị dữ liệu nhập vào
void HienThi(vector<CayNam> v){
    cout << "\n-------------------- HIEN THI --------------------\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\n(" << v[i].dinh_duong << ", " << v[i].doc_to << ")\n";
    }
}

// hàm kiểm tra nấm để ăn
// input:
// 1. bản ghi nấm

// output:
// 1. trả về true thì ăn được
// 2. trả về false thì không ăn được
bool KiemTra_ThucAn(CayNam item){
    bool ketQua;

    if(item.dinh_duong >= (item.doc_to * 2)){
        ketQua = true;
    }
    else if(item.dinh_duong < (item.doc_to * 2)){
        ketQua = false;
    }

    return ketQua;
}

// hàm in ra danh sách nấm ăn được
// input:
// 1. vector nấm

// output:
// 1. danh sách nấm ăn được
void Ham_In_Ra_Nam_An_Duoc(vector<CayNam> v){
    cout << "\n-------------------- List nam an duoc --------------------\n";
    for (int i = 0; i < v.size(); i++)
    {
        if ( KiemTra_ThucAn(v[i]) == true )
        {
            cout << "\n(" << v[i].dinh_duong << ", " << v[i].doc_to << ")\n";
        }        
    }    
}

// hàm in ra nấm có độc tố cao nhất
// input:
// 1. vector nấm

// output:
// 1. danh sách nấm có độc tố cao nhất
void Ham_In_Ra_DanhSach_Nam_Doc_Nhat(vector<CayNam> v){
    cout << "\n-------------------- DANH SACH NAM DOC NHAT --------------------\n";

    // việc 1:
    // tìm max độc
    int max = v[0].doc_to;

    for (int i = 0; i < v.size(); i++)
    {
        if (max < v[i].doc_to)
        {
            max = v[i].doc_to;
        }
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        if (max == v[i].doc_to)
        {
            cout << "\n(" << v[i].dinh_duong << ", " << v[i].doc_to << ")\n";
        }
    }
}

// hàm sắp xếp theo mức dinh dưỡng
// chiều tăng dần
// input:
// 1. vector nấm

// output:
// 1. nấm đã sắp xếp xong (chiều tăng dần dinh dưỡng)
void Ham_SapXep_Theo_MucDinhDuong(vector<CayNam> &v){
    cout << "\n-------------------- SAP XEP THEO DINH DUONG --------------------\n";

    CayNam temp;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i].dinh_duong > v[j].dinh_duong)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
            
        }              
    }
    
    HienThi(v);
}

int main(){
    vector<CayNam> v_nam; // vector nấm

    cout << "Nhap vao so nguyen n: ";
    int n;
    cin >> n;

    CayNam item;

    cout << "\n-------------------- NHAP THONG TIN CAY NAM --------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\ncay nam index = " << i << "\n";
        cin >> item.dinh_duong >> item.doc_to;

        // thêm item vào vector nấm
        v_nam.push_back(item);
    }
    
    // gọi hàm hiển thị
    HienThi(v_nam);

    // gọi hàm in ra thông tin nấm ăn được
    Ham_In_Ra_Nam_An_Duoc(v_nam);

    // hàm in ra danh sách nấm độc nhất
    Ham_In_Ra_DanhSach_Nam_Doc_Nhat(v_nam);

    // hàm in ra danh sách nấm theo mức dinh dưỡng
    // chiều tăng dần
    Ham_SapXep_Theo_MucDinhDuong(v_nam);

    return 0;
}