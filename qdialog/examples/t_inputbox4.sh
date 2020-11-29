#!/bin/sh
# An example which does not use temporary files, as suggested by Cary Evans:
: ${DIALOG=../bin/qdialog}

exec 3>&1
RESULT=`$DIALOG --stderr --title "INPUT BOX" --clear \
        --inputbox "Hi, this is an input dialog box. You can use \n
this to ask questions that require the user \n
to input a string as the answer. You can \n
input strings of length longer than the \n
width of the input box, in that case, the \n
input field will be automatically scrolled. \n
You can use BACKSPACE to correct errors. \n\n
Try entering your name below:" 13 51 2>&1 1>&3`
retval=$?
exec 3>&-

case $retval in
  0)
    echo "Input string is $RESULT";;
  1)
    echo "Cancel pressed.";;
  255)
    if test -n "$RESULT" ; then
      echo "$RESULT"
    else
      echo "ESC pressed."
    fi
    ;;
esac