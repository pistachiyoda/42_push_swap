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

echo "====Original version===="
i=20
while [ ${i} -gt 0 ]; do
	echo "---------"
	ARG=`jot -r 8 ${INT_MIN} ${INT_MAX}`
	check ${ARG}
	# cnt 900
	i=$((${i} - 1))
done

rm tmp
rm tmp2
