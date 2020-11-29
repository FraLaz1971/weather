#!/bin/sh

DIALOG=../bin/qdialog

$DIALOG --title "MESSAGE BOX" --clear --trim --check blablabla \
	--extra-button \
	--help-button \
        --msgbox "Hi, this is a simple message box. You can use this to \
                  display any message you like. The box will remain until \
                  you press the ENTER key." 100X300 -10+24

case $? in
  0)
    echo "OK";;
  1)
    echo "Button 1 (Cancel) pressed.";;
  2)
    echo "Button 2 (Help) pressed.";;
  3)
    echo "Button 3 (Extra) pressed.";;
  255)
    echo "ESC pressed.";;
esac
