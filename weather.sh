#!/usr/bin/env bash
bin/qdialog --inputbox "insert temperature (C deg.)" 2> out.txt
bin/weatherEU $(bin/readfile out.txt)
