#!/bin/bash

# @filename           :  template_copy.bash
# @author             :  Copyright (C) drunkwater
# @date               :  Tue Jan 16 12:59:51 HKT 2018
# @function           :  
# @see                :  
# @require            :  

SECONDS=0

EX_OK=0

set="easy medium hard"
#languages=(c cpp csharp golang java javascript kotlin python python3 ruby scala swift)

function usage() {
	echo "Usage: `basename $0` [$set] [language]"
}

if [ $# -ne 2 ]
then
	usage
	exit -1
fi


difficulty=$1
language=$2
if [[ $set =~ $difficulty ]]
then
	echo "${language} ${difficulty}"
else
	usage
	exit -1
fi


WORK_DIR=`pwd`
LIST_FILENAME=${WORK_DIR}/template/win32/leetcode_all_$difficulty.dirs

function confirm(){
	echo -n "Warning! You will lost all codes. Reset all? [Y/n]: "
	read key
	if [ ! "${key}" = "y" ]
	then
		exit 1
	fi
}


test -f $LIST_FILENAME || exit 0
# avoid the mistake of a slip of the thumb
#confirm
# avoid the mistake of a slip of the thumb




function c_copy(){
	suffix=$1
	dir=$2

	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/kmacro.h          ${d}/
	cp -f $t/list.h            ${d}/
	cp -f $t/Makefile          ${d}/

	cp -f $t/00_leetcode_0000.c ${d}/00_leetcode_$suffix.c
	#cp -f $t/01_leetcode_0000.c ${d}/01_leetcode_$suffix.c
	#cp -f $t/02_leetcode_0000.c ${d}/02_leetcode_$suffix.c
	#cp -f $t/03_leetcode_0000.c ${d}/03_leetcode_$suffix.c
	#cp -f $t/04_leetcode_0000.c ${d}/04_leetcode_$suffix.c
	#cp -f $t/05_leetcode_0000.c ${d}/05_leetcode_$suffix.c

	sed s/0000/$suffix/g -i ${d}/Makefile
	sync;sync;
	echo -e "${d} done\n"
}
function cpp_copy(){
	suffix=$1
	dir=$2

	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/Makefile            ${d}/
	cp -f $t/solution.hpp        ${d}/

	cp -f $t/00_leetcode_0000.cpp ${d}/00_leetcode_$suffix.cpp
	#cp -f $t/01_leetcode_0000.cpp ${d}/01_leetcode_$suffix.cpp
	#cp -f $t/02_leetcode_0000.cpp ${d}/02_leetcode_$suffix.cpp
	#cp -f $t/03_leetcode_0000.cpp ${d}/03_leetcode_$suffix.cpp
	#cp -f $t/04_leetcode_0000.cpp ${d}/04_leetcode_$suffix.cpp
	#cp -f $t/05_leetcode_0000.cpp ${d}/05_leetcode_$suffix.cpp

	sed s/0000/$suffix/g -i ${d}/Makefile
	sync;sync;
	echo -e "${d} done\n"
}
function csharp_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.cs ${d}/00_leetcode_$suffix.cs
	sync;sync;
	echo -e "${d} done\n"
}
function golang_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.go ${d}/00_leetcode_$suffix.go
	sync;sync;
	echo -e "${d} done\n"
}
function java_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.java ${d}/00_leetcode_$suffix.java
	sync;sync;
	echo -e "${d} done\n"
}
function javascript_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.js ${d}/00_leetcode_$suffix.js
	sync;sync;
	echo -e "${d} done\n"
}
function kotlin_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.kt ${d}/00_leetcode_$suffix.kt
	sync;sync;
	echo -e "${d} done\n"
}
function python_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.py ${d}/00_leetcode_$suffix.py
	sync;sync;
	echo -e "${d} done\n"
}
function python3_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.py ${d}/00_leetcode_$suffix.py
	sync;sync;
	echo -e "${d} done\n"
}
function ruby_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.rb ${d}/00_leetcode_$suffix.rb
	sync;sync;
	echo -e "${d} done\n"
}
function scala_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.scala ${d}/00_leetcode_$suffix.scala
	sync;sync;
	echo -e "${d} done\n"
}
function swift_copy(){
	#echo ${FUNCNAME}
	suffix=$1
	dir=$2


	d=${WORK_DIR}/$difficulty/${language}/${dir}/
	t=${WORK_DIR}/template/languages/${language}/c0000/
	#echo ${d}
	rm -fr ${d} && mkdir -p ${d}


	cp -f $t/00_leetcode_0000.swift ${d}/00_leetcode_$suffix.swift
	sync;sync;
	echo -e "${d} done\n"
}




k=0
while read line
do
	list=(${line//' '/ })
	dir=${list[0]}
	if [ -z "${dir}" ]
	then
		continue
	fi

	suffix=`printf %04d $k`

	#echo "${difficulty} ${language} ${suffix} ${dir}"
	if [ x"${language}" == x"c" ];then
		c_copy ${suffix} ${dir}
	elif [ x"${language}" == x"cpp" ];then
		cpp_copy ${suffix} ${dir}
	else
		cmd="${language}_copy ${suffix} ${dir}"
		eval $cmd
	fi

	k=$(($k+1))

done  < $LIST_FILENAME

# do some work( or time yourscript.sh)
duration=$SECONDS
echo "$(($duration / 60)) minutes and $(($duration % 60)) seconds elapsed."

exit $EX_OK