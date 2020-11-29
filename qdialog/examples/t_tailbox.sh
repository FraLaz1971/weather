#!/bin/sh

DIALOG=../bin/qdialog

$DIALOG --begin 8 0 --title "/var/log/kern.log. It tails the file in multitasking with /var/log/kern.log" --tailbox /var/log/kern.log -1 -1
