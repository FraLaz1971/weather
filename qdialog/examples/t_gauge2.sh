#!/bin/sh

# The original dialog program assumed the first line after the first "XXX"
# was a percentage value (compare with "gauge" script).
DIALOG=../bin/qdialog

(echo "10" ; sleep 2 ; 

echo "XXX"; 
echo "The new"
echo "\\n"
echo "message";
echo "XXX";
echo "20"
sleep 2; 

echo "75" ; sleep 1
echo "100") | \

$DIALOG --title "GAUGE" --gauge "Hi, this is a gauge widget" 10 40 0

if [ "$?" = 255 ] ; then
	echo ""
	echo "Box closed !"
fi