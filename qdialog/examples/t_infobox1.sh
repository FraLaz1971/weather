#!/bin/sh

DIALOG=../bin/qdialog

$DIALOG --timeout 10 --title "INFO BOX" \
        --infobox "Hi, this is an information box. It is
different from a message box: it will
not pause waiting for input after displaying
the message. The pause here is only introduced
by a sleep command in the shell script.
You have $left $unit to read this..." 10 52

