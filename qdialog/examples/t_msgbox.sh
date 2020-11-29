#!/bin/sh
DIALOG=../bin/qdialog

$DIALOG --trim --begin 10 20 --title "MESSAGE BOX" --clear \
        --msgbox "Hi, this is a simple message box. You can use this to \
                  display any message you like. The box will remain until \
                  you press the ENTER key." 0 0

case $? in
  0)
    echo "OK";;
  255)
    echo "ESC pressed.";;
esac
