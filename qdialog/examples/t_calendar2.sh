#!/bin/sh
: ${DIALOG=../bin/qdialog}

exec 3>&1
USERDATE=`$DIALOG --title "CALENDAR" --calendar "Please choose a date..." 0 0 2>&1 1>&3`
code=$?
exec 3>&-

case $code in
  0)
    echo "Date entered: $USERDATE.";;
  1)
    echo "Cancel pressed.";;
  255)
    echo "Box closed.";;
esac
