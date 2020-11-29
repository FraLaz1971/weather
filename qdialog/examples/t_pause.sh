#!/bin/sh

DIALOG=../bin/qdialog

$DIALOG --title "PAUSE" --no-cancel --no-ok  --pause "Hi, this is a pause widget" 20 70 10

retval=$?

case $retval in
  0)
    echo "Timeout expired.";;
  1)
    echo "Cancel pressed.";;
  *)
    echo "Unexpected return code: $retval";;
esac
