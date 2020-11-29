#!/bin/sh
: ${DIALOG=../bin/qdialog}

tempfile=`tempfile 2>/dev/null` || tempfile=/tmp/test$$
trap "rm -f $tempfile" 0 1 2 5 15

$DIALOG --title "INPUT BOX" --clear \
	--insecure \
        --passwordbox "Hi, this is an password dialog box. You can use \n
this to ask questions that require the user \n
to input a string as the answer. You can \n
input strings of length longer than the \n
width of the input box, in that case, the \n
input field will be automatically scrolled. \n
You can use BACKSPACE to correct errors. \n\n
Try entering your name below:" 16 51 stupid 2> $tempfile

retval=$?

case $retval in
  0)
    echo "Input string is `cat $tempfile`";;
  1)
    echo "Cancel pressed.";;
  255)
    if test -s $tempfile ; then
      cat $tempfile
    else
      echo "ESC pressed."
    fi
    ;;
esac
