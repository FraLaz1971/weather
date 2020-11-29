#!/bin/sh
: ${DIALOG=../bin/qdialog}

exec 3>&1
USERTIME=`$DIALOG --title "TIMEBOX" --timebox "Please set the time..." 0 0 2>&1 1>&3`
code=$?
exec 3>&-

case $code in
  0)
    echo "Time entered: $USERTIME.";;
  1)
    echo "Cancel pressed.";;
  255)
    echo "Box closed.";;
esac
