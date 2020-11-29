#!/bin/sh
DIALOG=../bin/qdialog

width=10
while test $width != 42
do
$DIALOG --title "MESSAGE BOX (width $width)" --clear --no-collapse \
        --msgbox "\
        H   H EEEEE L     L      OOO
        H   H E     L     L     O   O
        HHHHH EEEEE L     L     O   O
        H   H E     L     L     O   O
        H   H EEEEE LLLLL LLLLL  OOO

Hi, this is a simple message box.  You can use this to \
display any message you like.  The box will remain until \
you press the ENTER key." 0 $width
test $? = 255 && break
width=`expr $width + 4`
done
