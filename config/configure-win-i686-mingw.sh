#/usr/bin/env bash
echo "generating total makefile for $(uname) $OS ..." >/dev/stderr
a=0;t=0;TARGETS="";RMTARGETS=""; EEXT=".exe";OEXT=".o"
echo 'CC=i686-w64-mingw32-gcc -g -O2'
echo 'MAKE = mingw32-make'
echo 'SRC = $(wildcard src/*.c)'
echo "OBJ = src/weather.o src/readfile.o"
printf "QOBJ = qdialog/capplication.o qdialog/ccalendarbox.o qdialog/cdialogapp.o "
printf "qdialog/cfilebox.o qdialog/cformbox.o qdialog/cgaugebox.o qdialog/cinputbox.o "
printf "qdialog/cmenubox.o qdialog/cmsgbox.o qdialog/cpausebox.o qdialog/ctailbox.o qdialog/ctextbox.o qdialog/ctimebox.o qdialog/cxmlbase.o qdialog/cxmlsettings.o qdialog/fileutils.o qdialog/main.o qdialog/moc_capplication.o qdialog/moc_ccalendarbox.o qdialog/moc_cdialogapp.o qdialog/moc_cfilebox.o qdialog/moc_cformbox.o qdialog/moc_cgaugebox.o qdialog/moc_cinputbox.o qdialog/moc_cmenubox.o qdialog/moc_cmsgbox.o qdialog/moc_cpausebox.o qdialog/moc_ctailbox.o qdialog/moc_ctextbox.o qdialog/moc_ctimebox.o "
echo "qdialog/strutils.o qdialog/utils.o"
echo 'CPPFLAGS = -Iinclude -Isrc '
echo 'LIBS = -lm'
echo 'LDFLAGS = -L/lib'
for t in $(ls -1 src/*.c)
do
	TARGET=$(basename ${t%.*})
	echo 'TARGET'$a = $TARGET
	TARGETS="$TARGET $TARGETS"
	RMTARGETS="src/$TARGET $RMTARGETS"
	a=$(($a+1)) 
done
echo 'TARGETS' = $TARGETS qdialog/qdialog
echo 'RMTARGETS' = $RMTARGETS qdialog/qdialog
echo 'qdialog/qdialog: '
echo -e "\t"'cd qdialog && qmake && $(MAKE)'
echo 'all: $(TARGETS) qdialog/qdialog'
a=0
for s in $(ls -1 src/*.c)
do
	TARGET=$(basename ${s%.*})
	echo '$(TARGET'$a').o: src/'$TARGET'.c'
	echo -e "\t"'$(CC) -c   $< -o src/'$TARGET'.o $(CPPFLAGS)'
	echo '$(TARGET'$a'): src/'$TARGET'.o'
	echo -e "\t"'$(CC) $< $(LIBS) -o src/'$TARGET' $(LDFLAGS)'
	a=$(($a+1)) 
done
echo 'echo created all targets' >/dev/stderr
echo 'install: all'
echo -e '\tmv $(RMTARGETS) bin'
echo '.PHONY: clean distclean cleanqdialog qdialog'
echo 'clean: cleanqdialog'
echo -e "\t"'rm -f $(OBJ) $(RMTARGETS)'
echo 'cleanqdialog:'
echo -e "\t"'cd qdialog && $(MAKE) clean'
echo 'distclean: clean'
echo -e "\trm -f bin/* Makefile* *.fit *.fits *.csv *.ssv *.tsv *.dat *.txt *.log"
echo "generating dirs" >/dev/stderr
if ! test -d bin; then mkdir  bin; fi
if ! test -d lib; then mkdir  lib; fi
