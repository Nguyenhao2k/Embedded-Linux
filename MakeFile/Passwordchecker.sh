#! usr/bin/bash

read -p "Enter your password: " password
pass=`echo ${#password}`
if [[ $pass -lt 8 ]]; then
        echo "Mat khau phai co toi thieu 8 ky tu!!!"
else
        if [[ $password =~ " " ]]; then
                echo "Mat khau khong duoc chua dau cach!!!"
        else
                if [[ $password =~ [A-Z] ]] && [[ $password =~ [a-z] ]] && [[ $password =~ [0-9] ]] && [[ $password =~ ['!@#$%^&*'] ]]; then
                        echo "Valid"

                else
                        echo -e "Invalid!!!.\nMat khau phai chua it nhat 1 chu Hoa, 1 chua thuong, 1 so va 1 ky tu dac biet."
                fi
        fi
fi
