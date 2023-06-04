// Yêu cầu:
// sắp xếp nổi bọt kiểu dữ liệu "struct Person"

#include <iostream>
#include <string>
#define SIZE 50
using namespace std;

struct Person{
    int id;
    string ten;
};

int main(){
    Person arr[SIZE];

    for (int i = 0; i < 3; i++)
    {
        cout << "\nid: ";
        cin >> arr[i].id;
        cin.ignore();

        cout << "ten: ";
        getline(cin, arr[i].ten, '\n');
    }
    
    // hiển thị
    cout << "\nHIEN THI\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "id: " << arr[i].id << ",\t\t ten: " << arr[i].ten << "\n";
    }
    
    int temp1 = 0;
    string temp2 = "";

    // sắp xếp theo id
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (arr[i].id > arr[j].id)
            {
                temp1 = arr[i].id;
                arr[i].id = arr[j].id;
                arr[j].id = temp1;

                temp2 = arr[i].ten;
                arr[i].ten = arr[j].ten;
                arr[j].ten = temp2;
            }            
        }        
    }
    
// hiển thị
    cout << "\n\nHIEN THI SAU KHI SAP XEP\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "id: " << arr[i].id << ",\t\t ten: " << arr[i].ten << "\n";
    }

    cout << "\n\n";
    return 0;
}