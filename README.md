1. Phiên bản đầu tiên thì tôi code đến cái đoạn sắp xếp ấy, ban đầu tôi sắp xếp mà không truyền tham chiếu.

2. Bài học rút ra là sắp xếp thì truyền tham chiếu, code sẽ chạy ok ngay

Những cái chỗ nào mà tôi code nó hay bị dài như này, đó là tại tôi chưa chưa biết truyền tham chiếu
--> cô giáo dạy nên tôi biết truyền tham chiếu
                temp1 = arr[i].id;
                arr[i].id = arr[j].id;
                arr[j].id = temp1;
                            
                temp2 = arr[i].ten;
                arr[i].ten = arr[j].ten;
                arr[j].ten = temp2;
=> Đây là code của tôi khi chưa biết truyền tham chiếu trong lúc sắp xếp với struct

3. Bài cây nấm độc _ Ứng dụng thuật toán sắp xếp với struct _ Tôi đã truyền tham chiếu để giúp code ngắn hơn thay vì phải chấm tên chấm tuổi
