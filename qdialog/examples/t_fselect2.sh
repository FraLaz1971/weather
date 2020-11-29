#!/bin/sh
: ${DIALOG=../bin/qdialog}

exec 3>&1
FILE=`$DIALOG --title "Please choose a file" --fselect $HOME/ 0 0 2>&1 1>&3`
code=$?
exec 3>&-

case $code in
	0)
		echo "\"$FILE\" chosen";;
	1)
		echo "Cancel pressed.";;
	255)
		echo "Box closed.";;
esac
