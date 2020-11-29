#!/bin/sh
: ${DIALOG=../bin/qdialog}

input=`tempfile 2>/dev/null` || input=/tmp/input$$
output=`tempfile 2>/dev/null` || output=/tmp/test$$
trap "rm -f $input $output" 0 1 2 5 15

cat << EOF > $input
Hi, this is an edit box. It can be used to edit text from a file.

It's like a simple text editor, with these keys implemented:

PGDN	- Move down one page
PGUP	- Move up one page
DOWN	- Move down one line
UP	- Move up one line
DELETE	- Delete the current character
BACKSPC	- Delete the previous character

Unlike Xdialog, it does not do these:

CTRL C	- Copy text
CTRL V	- Paste text

Because dialog normally uses TAB for moving between fields,
this editbox uses CTRL/V as a literal-next character.  You
can enter TAB characters by first pressing CTRL/V.  This
example contains a few tab characters.

It supports the mouse - but only for positioning in the editbox,
or for clicking on buttons.  Your terminal (emulator) may support
cut/paste.

Try to input some text below:

EOF

$DIALOG --title "EDIT BOX" \
	--fixed-font --editbox $input 0 0 2>$output

case $? in
  0)
    diff -c $input $output
    echo "OK"
    ;;
  1)
    echo "Button 1 (Cancel) pressed";;
  2)
    echo "Button 2 (Help) pressed";;
  3)
    echo "Button 3 (Extra) pressed";;
  255)
    echo "ESC pressed.";;
esac
