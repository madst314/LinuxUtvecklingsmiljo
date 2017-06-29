#!/bin/bash

function who_is_loged_on ()
{
   who | cut -d" " -f1
}

if ! [ -z $1 ]; then
   if who_is_loged_on | grep -q "$1" ; then
      exit 0
   else
      exit 1
   fi
fi

