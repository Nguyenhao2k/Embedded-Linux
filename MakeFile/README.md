# Embedded-Linux
This is a folder that I study Linux for Embedded System

ASSIGNMENT 2: 
Unit 2 Linux Basic Home Work
I.	Bash script
1.	Password checker
Viết 1 bash script để kiểm tra password truyền vào (argument) có thỏa mãn các yêu cầu dưới hay không.
-	Có tối thiểu 8 ký tự
-	Không có ký tự space “ “
-	Có tối thiểu 1 ký tự số
-	Có tối thiểu 1 chữ HOA và 1 chữ thường
-	Có tối thiểu 1 trong ký tự đặc biệt sau: !@#$%^&*
Ví dụ:
./pass_check.sh asidfekg893
Invalid!!!
./pass_check.sh asd9f3igt930B$
Valid!!!
2.	Class management
Viết bash script để quản lý học sinh và lớp học.
Mỗi học sinh có các thông tin sau:
-	Tên
-	Họ
-	Tuổi
-	Địa chỉ
-	Số điện thoại
Mỗi lớp học có các thông tin:
-	Tên lớp
-	Tên phòng học
-	Học vào buổi sáng hay buổi chiều
Yêu cầu (chia làm 2 bài nhỏ như bên dưới):
1.	Script cần có các chức năng sau:
-	Xây dựng menu để chọn các chức năng
-	Thêm, sửa, xóa học sinh
-	Tìm kiếm học sinh theo tên, họ, tuổi, điện thoại (ví dụ tìm theo tên với chuỗi nhập vào là “an”, thì phải list ra các bạn có tên là An, Van A, Quan, Quang, …). Nếu có nhiều học sinh thì ấn phím Space để xem thông tin của học sinh tiếp theo, ấn Esc để thoát phần xem thông tin.
-	Thông tin của học sinh được lưu vào file (có thể nhiều file)
-	Khi script chạy, đọc các thông tin về học sinh từ các file.
2.	Add thêm các chức năng sau vào script:
-	Thêm, sửa, xóa lớp học
-	Thêm/xóa học sinh trong lớp học
-	Hiện thông tin về lớp học (bao gồm cả có bao nhiêu học sinh trong lớp)
-	Tìm kiếm lớp học
-	Hiển thị tất cả các học sinh trong 1 lớp học
II.	Makefile
Viết 1 chương trình đơn giản (bằng C), có cấu trúc thư mục như hình:
 
Module1 có 1 hàm để in ra “This is module 1”, tương tự module2 in ra “this is module2”. Main.c sẽ gọi đến 2 hàm trong 2 module này. Trong mỗi thư mục lại có 1 file Makefile.
Yêu cầu (chia thành 2 bài nhỏ như bên dưới):
1.	Tổ chức và viết các Makefile sao cho ở thư mục gốc (/tmp/hello_project) chạy lênh make thì:
a.	Toàn bộ các file .c sẽ được compile thành file .o và lưu ở thư mục /tmp/hello_project/build (vẫn giữ cấu trúc thư mục – build/src/module1/module1.o, build/src/main.o, build/src/module2/module2.o)
b.	Tất cả các Makefile (kể cả các thư mục con) phải được thực hiện
c.	Khi thêm file code ở module1 (src/module1/module1_add.c), chỉ cần sửa Makefile của module đó (src/module1/Makefile) và các file .c, .h liên quan thì chương trình vẫn build đúng (make ra file binary chứa code mới).
2.	Build được với cross toolchain (https://launchpad.net/gcc-arm-embedded) 
