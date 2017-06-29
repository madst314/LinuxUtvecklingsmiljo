#!/bin/bash

input=$1
if !  ls | grep -q starttime.txt ; then
   echo 0 > starttime.txt
fi

if [ "$input" == "start" ]
then
   echo $(date +%s)  > starttime.txt
   echo "Tiden har startats ..."
elif [ "$input" == "status" ]
then
   start=$(cat starttime.txt)
   if [ "$start" == "0" ]
   then
      echo "Timetrack ej aktiv"
   else
      echo "Tid sedan start (sec): " $(($(date +%s) - $start))
   fi
elif [ "$input" == "stop" ]
then
   start=$(cat starttime.txt)
   if [ "$start" == "0" ]
   then
      echo "Timetrack ej aktiv"
   else
      echo "Tiden har stoppats. Tid sedan start (sec): "  $(($(date +%s) - $start))
   fi
   echo 0 > starttime.txt
   rm starttime.txt
fi

