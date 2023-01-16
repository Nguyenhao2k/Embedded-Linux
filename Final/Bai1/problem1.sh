#-----------------------Quan ly thong tin - FAST---------------------------


#!/bin/bash
# declare STRING variablfor

function themgiangvien()
{
	clear
	echo "---------------THEM MOI GIANG VIEN--------------"
	echo "Ma khoa:  "
	read chuoi
	echo "Ma khoa: $chuoi">>giangvien.txt
	echo "Vi tri giang day: "
	read chuoi
	echo "Vi tri: $chuoi">>giangvien.txt
	echo "Ten giang vien: "
	read chuoi
	echo "Ten: $chuoi">>giangvien.txt
	echo "------------Da them thanh cong du lieu vao tep giangvien.txt--------------"
	Menu
}
function themkhoa()
{
	clear
	echo "--------------THEM MOI KHOA-------------"
	echo "Ma khoa: "
	read chuoi
	echo "ID: $chuoi">>khoa.txt
	echo "Ten khoa: "
	read chuoi
	echo "Tenkhoa: $chuoi">>khoa.txt
	echo "Kieu khoa: "
	read chuoi
	echo "Kieu: $chuoi">>khoa.txt
	echo "Truong khoa: "
	read chuoi
	echo "TruongKhoa: $chuoi">>khoa.txt
	echo "------------Da them thanh cong du lieu vao tep khoa.txt--------------"
	Menu
}
function timgiangvien
{
	clear
	echo "Nhap ten giang vien can tim kiem: "
	read tengv
	file=giangvien.txt;
	dong=0;
	chisokt=2;
	timkiem=0;
	dongtimkiem=0;
	while read banghi; do
		if [ $dong -eq $chisokt ]
		then
			#echo "$banghi"
			chisokt=$(($chisokt+3))	
			case $banghi in #Dong 50
			"Ten: $tengv") echo "Reply: Giang vien co ten: $tengv ton tai trong tep giangvien.txt "
			dongtimkiem=$dong
			timkiem="1"
			;;*)			
			esac
		fi
		dong=$(($dong+1))
	done <$file
#	echo "So dong: $dong"
	if [ $timkiem != 1 ]
	then
		echo "Reply: $tengv khong ton tai trong tep giangvien.txt"
	else
		dong=0;
		while read banghi; do
		if [ $dong -ge $dongtimkiem ] #Dong 66
		then
			if [ $dong -le $(($dongtimkiem+2)) ]
			then
				echo "$banghi"
			fi
		fi
		
		dong=$(($dong+1))
		done <$file
	fi
	Menu
}

function thongkekhoa
{
	clear
	echo "Nhap ID Khoa can thong ke: "
	read idkhoa
	file=giangvien.txt;
	dong=0;
	chisokt=0;
	timkiem=0;
	dongtimkiem=0;
	echo "-----DANH SACH GIANG VIEN THUOC ID KHOA $idkhoa----"
	while read banghi; do
#		echo "Dong so: $dong co ban ghi: $banghi, chi so kt: $chisokt"
		if [ $dong -eq $chisokt ]
		then
			#echo "$banghi"
			chisokt=$(($chisokt+3))	
			case $banghi in 
			"Ma khoa: $idkhoa") 
			dongtimkiem=$dong

			readfilegiangvien
			;;*)			
			esac
		fi
		dong=$(($dong+1))
	done <$file
#	echo "So dong: $dong"	
	Menu

}
function readfilegiangvien
{
		file=giangvien.txt;
		dongl1=0;
		while read banghi; do
		if [ $dongl1 -ge $dongtimkiem ] #Dong 66
		then
			if [ $dongl1 -le $(($dongtimkiem+2)) ]
			then
				echo "$banghi"
			fi
		fi
		
		dongl1=$(($dongl1+1))
		done <$file
}
function timkiemkhoa
{
	clear
	echo "Nhap ID Khoa can tim kiem: "
	read idkhoa
	file=khoa.txt;
	dong=0;
	chisokt=0;
	timkiem=0;
	dongtimkiem=0;
	while read banghi; do
		if [ $dong -eq $chisokt ]
		then
#			echo "$banghi"
			chisokt=$(($chisokt+4))	
			case $banghi in #Dong 50
			"ID: $idkhoa") echo "Reply: ID khoa: $idkhoa ton tai trong tep khoa.txt "
			dongtimkiem=$dong
			timkiem="1"
			;;*)			
			esac
		fi
		dong=$(($dong+1))
	done <$file
#	echo "So dong: $dong"
	if [ $timkiem != 1 ]
	then
		echo "Reply: idkhoa $idkhoa khong ton tai trong tep khoa.txt"
	else
		dong=0;
		while read banghi; do
		if [ $dong -ge $dongtimkiem ] #Dong 66
		then
			if [ $dong -le $(($dongtimkiem+3)) ]
			then
				echo "$banghi"
			fi
		fi
		dong=$(($dong+1))
		done <$file
	fi
	Menu

}
function show_department
{
	clear
	echo "=====DANH MUC KHOA======="
	file=khoa.txt;	
	while read banghi; do
		echo "$banghi"
	done <$file
	Menu
}
function show_teacher
{
	clear
	echo "=====DANH MUC GIANG VIEN======="
	file=giangvien.txt;	
	while read banghi; do
		echo "$banghi"
	done <$file
	Menu
}
function Menu
{
	echo "=============MENU=============="
	echo "1: Adding new deparment"
	echo "2: Adding new teacher"
	echo "3: Teacher profile"
	echo "4: Deparment profile"
	echo "5: Deparment list"
	echo "6: Teacher list"
	echo "7: Thoat chuong trinh"

	read choice
	case $choice in
		1)Adding_Department;;
		2)Adding_teacher;;
		3)Finding_teacher;;
		4)Finding_department;;
		5)other;;
		6)show_department;;
		7)show_teacher;;
		8)exit 0;;*)

	esac
}
Menu


