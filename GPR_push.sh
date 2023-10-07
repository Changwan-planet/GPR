#!/bin/bash

date=`date`
username="Changwan-planet"
#username="tjsckddhks@gmail.com"
github_Token="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"
github_Address="https://github.com/Changwan-planet/GPR.git"
logFile="/home/changwan/GPR/push.log"
SourceDir="/home/changwan/GPR"

cd $SourceDir

echo "git add *.sh *.h *.f90 *.py ..." && echo "git add *.sh *.h *.f90 *.py ..." > $logFile 2>&1
echo "`git add *.sh *.h *.f90 *.py`" >> $logFile 2>&1
echo "" && echo "" >> $logFile 2>&1 && echo "==" >> $logFile 2>&1

echo "git status" && echo "git status" >> $logFile 2>&1
echo "`git status`" >> $logFile 2>&1
echo "" && echo "" >> $logFile 2>&1 && echo "==" >> $logFile 2>&1

echo "git commit -m $date commit" && echo "git commit -m $date commit" >> $logFile 2>&1
echo "`git commit -m "$date commit"`" >> $logFile 2>&1
echo "" && echo "" >> $logFile 2>&1 && echo "==" >> $logFile 2>&1

echo "git push!" && echo "git push!" >> $logFile 2>&1
git push https://$username:$github_Token@$github_Address >> $logFile 2>&1

sleep 2

result="`awk '/Everything up-to-date/' $logFile 2>&1`"
echo "$result"


if [ -z "$result" ];then
        echo "git push Success~!" && echo "git push Success~!" >> $logFile 2>&1
else
        echo "!! git push ERROR! please check $logFile !!" && echo "!! git push ERROR! please check $logFile !!" >> $logFile 2>&1
fi

exit 0
