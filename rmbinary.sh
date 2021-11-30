#!/bin/bash
COLOR_Y='\033[0;33m'
COLOR_OFF='\033[0m'
echo -e "${COLOR_Y}result of solution binaries${COLOR_OFF}"
find */*/solution
echo -e "\n${COLOR_Y}result of solution debug directories${COLOR_OFF}"
find */*/solution.dSYM
echo -e "\n${COLOR_Y}result of solution classes${COLOR_OFF}"
find */*/*.class
echo ''

read -p "Do you want to delete? (Y/N) > " ok
if [ $ok = "Y" ]
then
    rm */*/solution
    rm -r */*/solution.dSYM
    rm */*/*.class
    echo 'Done.'
else
    echo "Abort."
fi
