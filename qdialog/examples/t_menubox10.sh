#!/bin/sh
# zero-width column
: ${DIALOG=../bin/qdialog}

exec 3>&1
value=`$DIALOG --backtitle "Debian Configuration" \
	--title "Configuring debconf" \
	--default-item Dialog \
	--menu "Packages that use debconf for co" 19 50 6 \
	Dialog		"" \
	Readline	"" \
	Gnome		"" \
	Kde		"" \
	Editor		"" \
	Noninteractive	"" \
2>&1 1>&3`
retval=$?
exec 3>&-

case $retval in
  0)
    echo "$value chosen.";;
  1)
    echo "Cancel pressed.";;
  2)
    echo "Help pressed ($value)";;
  255)
    if test -n "$value" ; then
      echo "$value"
    else
      echo "ESC pressed."
    fi
    ;;
esac
