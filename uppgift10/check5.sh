#!/bin/bash

# köra make all
echo "Check command: make all ----->"
cd 5D/ && make all &> ../log.txt
cd ..
if ls 5D/ | grep -q program1.sh ;
then
   if [ `ls -l log.txt | awk '{print $5}'` -eq 0 ];
   then
      echo "Make success!"
      rm log.txt
   else
      echo "Error from make. Got: $(cat log.txt)"
      rm log.txt
   fi
else
   echo "Error program1.sh not found"
fi

#köra install
echo "Check command: make install ----->"
cd 5D/ && make install &> ../log.txt
cd ..

if ls /usr/local/bin/ | grep -q program1.sh ;
then
   if [ `ls -l log.txt | awk '{print $5}'` -eq 0 ];
   then
      echo "Make install success!"
   else
      echo "Error from make. Got: $(cat log.txt)"
   fi
else
   echo "Error program1.sh not installed"
fi

#köra uninstall
echo "Check command: make uninstall ----->"
cd 5D/ && make uninstall &> ../log.txt
cd ..

if ! ls /usr/local/bin/ | grep -q program1.sh ;
then
   if [ `ls -l log.txt | awk '{print $5}'` -eq 0 ];
   then
      echo "Make uninstall success!"
   else
      echo "Error from make. Got: $(cat log.txt)"
   fi
else
   echo "Error program1.sh not installed"
fi

#köra clean
echo "Check command: make uninstall ----->"
cd 5D/ && make clean &> ../log.txt
cd ..

if ! ls 5D/ | grep -q -e *.sh -e *.o -e *.out;
then
   if [ `ls -l log.txt | awk '{print $5}'` -eq 0 ];
   then
      echo "Make clean success!"
   else
      echo "Error from make. Got: $(cat log.txt)"
   fi
else
   echo "Error program1.sh not installed"
fi

rm log.txt
