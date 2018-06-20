#!/bin/bash

# @filename           :  code_refactoring.bash
# @author             :  Copyright (C) drunkwater
# @date               :  Fri Mar  9 09:54:17 HKT 2018
# @function           :  
# @see                :  
# @require            :  

EX_OK=0
EX_USAGE=64

echo -n -e "\t Warning! You will lost all codes. Reset the whole Project? [Y/n]: "
read key
if [ ! "${key}" = "y" ];then
	exit 1
fi

WORK_DIR=`pwd`

FILE_README_MD=${WORK_DIR}/template/win32/README.md
FILE_README_PDF=${WORK_DIR}/template/win32/README.pdf

if [ ! -f ${FILE_README_MD} ];then
	echo "${FILE_README_MD} not exist!"
	exit ${EX_USAGE}
else
	cp -f ${FILE_README_MD}  ${WORK_DIR}/README.md
	cp -f ${FILE_README_PDF}  ${WORK_DIR}/README.pdf
fi


languages=(c cpp csharp golang java javascript kotlin python python3 ruby scala swift)

for difficulty in easy medium hard
do
	for lang in ${languages[*]}
	do
		dirs_list=${WORK_DIR}/template/win32/leetcode_all_${difficulty}.dirs
		if [ ! -f "${dirs_list}" ];then
			echo "${dirs_list} not exist!"
			exit ${EX_USAGE}
		fi

		echo "language=${lang}"
		rm -fr ${WORK_DIR}/${difficulty}/${lang}
		mkdir -p ${WORK_DIR}/${difficulty}/${lang}

		cp -a ${WORK_DIR}/template/languages/${lang}/*  ${WORK_DIR}/${difficulty}/${lang}/
		cp -f ${dirs_list} ${WORK_DIR}/${difficulty}/${lang}

		copy_bash=${WORK_DIR}/template/bash/template_copy.bash
		chmod u+x ${copy_bash} && ${copy_bash} ${difficulty} ${lang}
		${WORK_DIR}/template/bash/add_each_description_prototypes.pl ${difficulty} ${lang}
	done
done


exit $EX_OK
#real    4m37.049s
#user    0m1.720s
#sys     3m1.112s
