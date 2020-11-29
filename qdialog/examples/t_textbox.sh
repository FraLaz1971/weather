#!/bin/sh

DIALOG=../bin/qdialog

tempfile=`tempfile 2>/dev/null` || tempfile=/tmp/test$$
trap "rm -f $tempfile" 0 1 2 5 15

cat << EOF > $tempfile
Hi, this is a text dialog box. It can be used to display text from a file.
The file should not contain any 'tab' characters, so you should 'expand'
the file first if it contains 'tab' characters.

It's like a simple text file viewer, with these keys implemented:

PGDN/SPACE     - Move down one page
PGUP/'b'       - Move up one page
ENTER/DOWN/'j' - Move down one line
UP/'k'         - Move up one line
LEFT/'h'       - Scroll left
RIGHT/'l'      - Scroll right
'0'            - Move to beginning of line
HOME/'g'       - Move to beginning of file
END/'G'        - Move to end of file
'/'            - Forward search
'?'            - Backward search
'n'            - Repeat last search (forward)
'N'            - Repeat last search (backward)


The following is a sample text file:


EOF

TEXT=/usr/share/common-licenses/GPL
test -f $TEXT || TEXT=./COPYING

cat $TEXT | expand >> $tempfile

$DIALOG --clear --title "TEXT BOX" --textedit "$tempfile" 0 0

case $? in
  0)
    echo "OK";;
  1)
    echo "Button 1 (Cancel) pressed";;
  2)
    echo "Button 2 (Help) pressed";;
  3)
    echo "Button 3 (Extra) pressed";;
  255)
    echo "ESC pressed.";;
esac
