#!/bin/sh

DIALOG=../bin/qdialog

left=10
unit="seconds"
while test $left != 0
do

$DIALOG --timeout 1 --sleep 1 \
	--title "INFO BOX" \
        --infobox "Hi, this is an information box. It is
different from a message box: it will
not pause waiting for input after displaying
the message. The pause here is only introduced
by the sleep command within dialog.
You have $left $unit to read this..." 10 0
left=`expr $left - 1`
test $left = 1 && unit="seconds"
done
