#!/bin/sh

DIALOG=../bin/qdialog

PCT=10
(
while test $PCT != 100
do
echo "XXX"
echo $PCT
echo "The new\n\
message ($PCT percent)"
echo "XXX"
PCT=`expr $PCT + 10`
sleep 1
done
) |

$DIALOG --title "GAUGE" --no-ok --gauge "Hi, this is a gauge widget" 0 0 10
