#!/bin/zsh
BLINK='\e[5m'
RED='\033[0;31m'
RED_B='\033[1;31m'
BLACK='\033[0;30m'
GREEN='\033[0;32m'
GREEN_B='\033[1;32m'
YELLOW='\033[0;33m'
YELLOW_B='\033[3;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
GRAY='\033[0;37m'
YELLOW_B='\033[1;33m'
WHITE='\033[1;37m'
NC='\033[0m'

# -no arguments- #
TEST_E0=''
TEST_E1='"" "" "" ""'

# -wrong number of arguments- #
TEST_E2='1'
TEST_E3='1 2'
TEST_E4='1 2 3'

# -negative number- #
TEST_E5='-1 1 1 1'
TEST_E6='1 -1 1 1'
TEST_E7='1 1 -1 1'
TEST_E8='1 1 1 -1'

TEST_E9='-1 1 1 1 1'
TEST_E10='1 -1 1 1 1'
TEST_E11='1 1 -1 1 1'
TEST_E12='1 1 1 -1 1'
TEST_E13='1 1 1 1 -1'

# -zero number- #
TEST_E14='0 1 1 1'
TEST_E15='1 0 1 1'
TEST_E16='1 1 0 1'
TEST_E17='1 1 1 0'
TEST_E18='0 1 1 1 1'
TEST_E19='1 0 1 1 1'
TEST_E20='1 1 0 1 1'
TEST_E21='1 1 1 0 1'
TEST_E22='1 1 1 1 0'

# -wrong type of argument char- #
TEST_E23='a 1 1 1'
TEST_E24='1 a 1 1'
TEST_E25='1 1 a 1'
TEST_E26='1 1 1 a'

TEST_E27='a 1 1 1 1'
TEST_E28='1 a 1 1 1'
TEST_E29='1 1 a 1 1'
TEST_E30='1 1 1 a 1'
TEST_E31='1 1 1 1 a'

#-wrong type of argument Minus no space-
TEST_E32='1- 1 1 1'
TEST_E33='1 1- 1 1'
TEST_E34='1 1 1- 1'
TEST_E35='1 1 1 1-'

TEST_E36='1- 1 1 1 1'
TEST_E37='1 1- 1 1 1'
TEST_E38='1 1 1- 1 1'
TEST_E39='1 1 1 1- 1'
TEST_E40='1 1 1 1 1-'

#-wrong type of argument Minus space-
TEST_E41='- 1 1 1'
TEST_E42='1 - 1 1'
TEST_E43='1 1 - 1'
TEST_E44='1 1 1 -'

TEST_E45='- 1 1 1 1'
TEST_E46='1 - 1 1 1'
TEST_E47='1 1 - 1 1'
TEST_E48='1 1 1 - 1'
TEST_E49='1 1 1 1 -'


echo "    ${GREEN_B}----START----${NC}"
make
concat=TEST_E
tmp=$concat
i=0
echo "    ${GREEN_B}----No Arguments----${NC}"
while [ $i -le 49 ]
do
	if [[ ( $i = 2 ) ]]; then
		echo "    ${GREEN_B}----Wrong Number of Arguments----${NC}"
	elif [[ ( $i = 5 ) ]]; then
		echo "    ${GREEN_B}----Negative Number----${NC}"
	elif [[ ( $i = 14 ) ]]; then
		echo "    ${GREEN_B}----Zero Number Argument----${NC}"
	elif [[ ( $i = 23 ) ]]; then
		echo "    ${GREEN_B}----Wrong Type of Argument char----${NC}"
	elif [[ ( $i = 32 ) ]]; then
		echo "    ${GREEN_B}----Wrong Type of Argument minus no space----${NC}"
	elif [[ ( $i = 41 ) ]]; then
		echo "    ${GREEN_B}----Wrong Type of Argument minus with space----${NC}"
	fi
	concat="$tmp$i"
	echo $concat "🠚" "${(P)concat}"
	final="${(P)concat}"
	parts=("${(@s[ ])final}")
	# for j ("$parts[@]") print -r -- $j
	timeout 10s ./philo $parts[1] $parts[2] $parts[3] $parts[4] $parts[5]
	i=$(( $i + 1 ))
	# echo $i
done
echo "    ${YELLOW_B}🠝🠝 ALL TESTS BEFORE SHOULD NOT BE WORKING 🠝🠝${NC}"
	
	
	
	
	
	
	
	
	
	# timeout 2s ./philo "${!concat}"