#!/bin/sh

# this differs from msgbox3 by making a window small enough to force scrolling.
DIALOG=../bin/qdialog

width=20
while test $width != 60
do
$DIALOG --title "MESSAGE BOX (width $width)" --clear \
        --msgbox "\
	.a .b .c .d .e .f .g .h .j .i .j .k .l .m .n .o .p .q .r .s .t .u .v .w .x .y .z
	.A .B .C .D .E .F .G .H .J .I .J .K .L .M .N .O .P .Q .R .S .T .U .V .W .X .Y .Z
" 15 $width
test $? = 255 && break
width=`expr $width + 5`
done
