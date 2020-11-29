#!/bin/sh

# get rid of all flickering by constructing a script unroll the loop, leaving
# us in curses-mode until we're done counting.
#
# a little fancier than infobox5, this moves the widget at each step.
DIALOG=../bin/qdialog
tempfile=`tempfile 2>/dev/null` || tempfile=/tmp/test$$
trap "rm -f $tempfile" 0 1 2 5 15

left=10
unit="seconds"
last='\'

cat >>$tempfile <<EOF
$DIALOG $last
EOF

while test $left != 0
do

cat >>$tempfile <<EOF
	--sleep 1 \
	--begin $left `expr $left + 5` \
	--title "INFO BOX" $last
        --infobox "Hi, this is an information box. It is
different from a message box: it will
not pause waiting for input after displaying
the message. The pause here is only introduced
by the sleep command within dialog.
You have $left $unit to read this..." 0 0 $last
EOF

left=`expr $left - 1`
test $left = 1 && unit="second"
done

echo >>$tempfile

. $tempfile
