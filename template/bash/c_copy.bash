#!/bin/bash

# @filename           :  c_copy.bash
# @author             :  Copyright (C) drunkwater
# @date               :  Tue Jan 16 12:59:51 HKT 2018
# @function           :  
# @see                :  
# @require            :  

EX_OK=0


set="easy medium hard"
usage() {
	echo "Usage: `basename $0` [$set]"
}

if [ $# -ne 1 ]
then
	usage
	exit -1
fi

difficulty=$1
if [[ $set =~ $difficulty ]]
then
	echo "c $difficulty"
else
	usage
	exit -1
fi




WORK_DIR=`pwd`
LIST_FILENAME=${WORK_DIR}/template/win32/leetcode_all_$difficulty.dirs

echo -n "Warning! You will lost all codes. Reset all? [Y/n]: "
read key
if [ ! "${key}" = "y" ]
then
	exit 1
fi

test -f $LIST_FILENAME || exit 0

i=0
while read line
do
	list=(${line//' '/ })
	dir=${list[0]}
	if [ -z "$dir" ]
	then
		continue
	fi

	suffix=`printf %04d $i`
	d=${WORK_DIR}/$difficulty/c/${dir}/
	t=${WORK_DIR}/template/languages/c/c0000/
	echo $d

	rm -fr $d
	mkdir -p $d


	cp -f $t/kmacro.h          $d/
	cp -f $t/list.h            $d/
	cp -f $t/Makefile          $d/

	cp -f $t/00_leetcode_0000.c $d/00_leetcode_$suffix.c
	#cp -f $t/01_leetcode_0000.c $d/01_leetcode_$suffix.c
	#cp -f $t/02_leetcode_0000.c $d/02_leetcode_$suffix.c
	#cp -f $t/03_leetcode_0000.c $d/03_leetcode_$suffix.c
	#cp -f $t/04_leetcode_0000.c $d/04_leetcode_$suffix.c
	#cp -f $t/05_leetcode_0000.c $d/05_leetcode_$suffix.c

	sed s/0000/$suffix/g -i $d/Makefile
	echo -e "$d done\n"
	i=$(($i+1))

done  < $LIST_FILENAME


exit $EX_OK
