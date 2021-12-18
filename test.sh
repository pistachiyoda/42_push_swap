#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
INT_MIN=-2147483648
INT_MAX=2147483647

function check() {
	echo ARG = $*
	./push_swap $* | ./checker_Mac $* > tmp
	if grep -q 'OK' ./tmp; then
		echo -e "${GREEN}OK${NC}"
	else
		echo -e "${RED}NG${NC}"
	fi
	./push_swap $* | wc -l > tmp2
}

function cnt() {
	cnt=$(cat tmp2)
	echo cnt:$cnt vs limit_cnt:$1
	if [ ${cnt} -gt $1 ]; then
		echo -e "${RED}KO${NC}"
	else
		echo -e "${GREEN}OK${NC}"
	fi
}

echo "====Error management===="
echo "1/4 Non numeric"
./push_swap 123 456 ghj
echo "2/4 Duplicate num"
./push_swap 123 456 123
echo "3/4 Greater than max int, Smaller than min int"
./push_swap 9223372036854775807
./push_swap -9223372036854775808
./push_swap 2147483648
./push_swap -2147483649
echo "4/4 No param"
./push_swap

echo "====simple version===="
ARG="2 1 0"
check ${ARG}
cnt 3

echo "====Another simple version===="
ARG="1 5 2 4 3"
check ${ARG}
cnt 12
i=5
while [ ${i} -gt 0 ]; do
	echo "---------"
	ARG=`jot -r 5 ${INT_MIN} ${INT_MAX}`
	check ${ARG}
	cnt 12
	i=$((${i} - 1))
done

echo "====Middle version===="
i=5
while [ ${i} -gt 0 ]; do
	echo "---------"
	ARG=`jot -r 100 ${INT_MIN} ${INT_MAX}`
	check ${ARG}
	cnt 900
	i=$((${i} - 1))
done

# while [ ${i} -gt 0 ]; do
# 	echo "---------"
# 	ARG=`jot -r 15 1 1000`
# 	check ${ARG}
# 	cnt 900
# 	i=$((${i} - 1))
# done

# echo "====Adovanced version===="
# i=5
# while [ ${i} -gt 0 ]; do
# 	echo "---------"
# 	ARG=`jot -r 500 ${INT_MIN} ${INT_MAX}`
# 	check ${ARG}
# 	cnt 7000
# 	i=$((${i} - 1))
# done

rm tmp
rm tmp2
