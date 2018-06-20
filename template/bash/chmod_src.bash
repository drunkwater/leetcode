#!/bin/bash

# @filename           :  chmod_src.bash
# @author             :  Copyright (C) drunkwater
# @date               :  Tue Jan 16 12:59:51 HKT 2018
# @function           :  
# @see                :  https://github.com/drunkwater/leetcode
# @require            :  

# {c,cpp,csharp,go,java,javascript,kotlin,python,python3,ruby,scala,swift}
for f in `find . -regex '.*\.\(c\|h\|cpp\|hpp\)'`
do
	echo $f
	chmod -x $f
done

exit 0