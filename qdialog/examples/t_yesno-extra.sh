#!/bin/sh

DIALOG=../bin/qdialog

$DIALOG --title "YES/NO/MAYBE BOX" \
	--clear \
	--ok-label "Next" \
	--no-label "Cancel" \
	--trim --cr-wrap \
	--extra-label "Previous" --extra-button \
        --yesno "Hi, this is a yes/no dialog box with its labels changed.\n \
                 You can use this to ask\n \
                 questions that have an answer of either yes or no (or maybe).\n \
                 BTW, do you notice that long lines will be automatically\n \
                 wrapped around so that they can fit in the box? You can\n \
                 also control line breaking explicitly by inserting\n \
                 'backslash n' at any place you like, but in this case,\n \
                 auto wrap around will be disabled and you will have to\n \
                 control line breaking yourself." 13 61

case $? in
  0)
    echo "Next chosen.";;
  1)
    echo "Cancel chosen.";;
  2)
    echo "Help pressed.";;
  3)
    echo "Previous pressed.";;
  255)
    echo "ESC pressed.";;
esac
