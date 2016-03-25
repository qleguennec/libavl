#!/bin/bash

RENDU_DIR=$(pwd)/test/lib/libavl . util/rendu.sh
make -C test
if [ "$?" -ne 0 ]; then
	exit 1
fi
cd test

NINPUTS=(1 10 42 100 1000 10000)
MAX=100

BLACK="\033[0;30m"
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
BLUE="\033[0;34m"
MAGENTA="\033[0;35m"
CYAN="\033[0;36m"
WHITE="\033[0;37m"
END="\033[0m"

OK=$GREEN
NOK=$RED
INFO=$CYAN

echo -e "$INFO"Sort tests$END
echo
for N in ${NINPUTS[@]}; do
	echo -e "$INFO"Testing for $N integers$END
	RAND="$(shuf -i1-$MAX -n $N)"
	MY=$(echo "$RAND" | ./test-avl sort)
	SORT=$(echo "$RAND" | sort -n)
	if [ ! "$MY" = "$SORT" ]; then
		echo -e "$NOK"input: "\t"$BLUE$RAND$END
		echo -e "$NOK"output:"\t"$END$MY
		echo -e "$OK"answer:"\t"$SORT$END
		exit 1
	else
		echo -e "$OK"OK$END
		echo
	fi
done

echo "$OK"OK$END
exit 0
