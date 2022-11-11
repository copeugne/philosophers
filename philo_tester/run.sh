#! /bin/bash


#makefile a modifier
#cc -Wall -Wextra -Werror -pthread -fsanitize=address -g3 test.c -o test
#valgrind
#valgrind --tool=helgrind --tool=drd ./philo
#https://github.com/MichelleJiam/LazyPhilosophersTester
#https://github.com/Snaipe/Criterion
#http://butunclebob.com/ArticleS.UncleBob.TheThreeRulesOfTdd
#http://cleancoder.com/products
#uncle bob clean code videos
#karim dridi (k vert youtube)
clear
cc bis.c -o test
# =============  COLOR VARIABLES  ============= #

BLINK='\e[5m'
RED='\033[0;31m'
RED_B='\033[1;31m'
BLACK='\033[0;30m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
GRAY='\033[0;37m'
YELLOW_B='\033[1;33m'
WHITE='\033[1;37m'
NC='\033[0m'

# =============   ERROR TESTS VARIABLES  ============= #
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
# -wrong type of argument- #
TEST_E23='a 1 1 1'
TEST_E24='1 a 1 1'
TEST_E25='1 1 a 1'
TEST_E26='1 1 1 a'
TEST_E27='a 1 1 1 1'
TEST_E28='1 a 1 1 1'
TEST_E29='1 1 a 1 1'
TEST_E30='1 1 1 a 1'
TEST_E31='1 1 1 1 a'
TEST_E32='1- 1 1 1'
TEST_E33='1 1- 1 1'
TEST_E34='1 1 1- 1'
TEST_E35='1 1 1 1-'
TEST_E36='1- 1 1 1 1'
TEST_E37='1 1- 1 1 1'
TEST_E38='1 1 1- 1 1'
TEST_E39='1 1 1 1- 1'
TEST_E40='1 1 1 1 1-'





# =============   TESTS VARIABLES  ============= #


echo "		${RED_B}${BLINK}----START----${NC}"
# =============  ERROR TESTS  ============= #

echo "${YELLOW_B}	--ERRORS--${NC}"
#ret= $(./test ${TEST_E1} | echo $?)
#./test
#if []
#then
	echo "${GRAY}TEST 1: ${GREEN}OK${NC}"
	echo "${GRAY}TEST 1: ${RED}WRONG${NC}"
	echo "${BLUE}Should return :${NC}\nError no arguments."
	#echo "${BLUE}return : ${PURPLE}$ret ${NC} "


#	echo "${BLUE}return bisi : ${PURPLE}"
#	./test 11 | echo $?
#	echo " ${NC} "
#	./test ${TEST_E1}
	echo "${BLUE}end.${NC}"

# =============  GLOBAL VARIABLES  ============= #

# =============  TESTS  ============= #


#1 800 200 200 philo ne mange pas et meurt
#5 800 200 200 personne ne meurt

#5 800 200 200 7 philo ne mange pas et meurt
#4 410 200 200 philo ne mange pas et meurt
#4 310 200 100 philo ne mange pas et meurt

#1 800 200 200 philo ne mange pas et meurt
#1 800 200 200 philo ne mange pas et meurt
#1 800 200 200 philo ne mange pas et meurt


# =============  YOUR TEST  ============= #

echo "${YELLOW_B}	--Test with your own parameters--${NC}"
echo "${YELLOW}	Must they eat? ${PURPLE}1${YELLOW} if they do ${PURPLE}0${YELLOW} if they don't.${NC}"
	read eat
# - no response - #
if [ -z "$eat" ]
then
	echo "	${YELLOW}No arguments provided.${NC}"

	echo "		${RED_B}${BLINK}----END----${NC}"
	exit 1
fi
# - response - #
if [ $eat -eq 0 ]
then

	echo "Enter ${CYAN}number_of_philosophers${NC} <= 200"
		read number_of_philosophers
	echo "Enter ${CYAN}time_to_die${NC} >= 60"
		read time_to_die
	echo "Enter ${CYAN}time_to_eat${NC} >= 60"
		read time_to_eat
	echo "Enter ${CYAN}time_to_sleep${NC} >= 60"
		read time_to_sleep

else
	if [ $eat -eq 1 ]
	then
		echo "Enter ${CYAN}number_of_philosophers${NC} <= 200"
			read number_of_philosophers
		echo "Enter ${CYAN}time_to_die${NC} >= 60"
			read time_to_die
		echo "Enter ${CYAN}time_to_eat${NC} >= 60"
			read time_to_eat
		echo "Enter ${CYAN}time_to_sleep${NC} >= 60"
			read time_to_sleep
		echo "Enter ${CYAN}number_of_times_each_philosopher_must_eat${NC}"
			read number_of_times_each_philosopher_must_eat
	else
		echo "	${YELLOW}Invalid input.${NC}"
	fi
fi

echo "		${RED_B}${BLINK}----END----${NC}"
exit 1
