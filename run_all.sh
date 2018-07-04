#!/bin/bash

gnome-terminal --geometry=80x16 -e 'sh -c "make posix && sudo ./main"'
sleep 3
sed '0,/ROUTERID_0/! s/ROUTERID_0/ROUTERID_1/' src/constants.h > src/constantsx.h
mv src/constantsx.h src/constants.h
gnome-terminal --geometry=80x16 -e 'sh -c "make posix && sudo ./main"'

sleep 2
sed '0,/ROUTERID_1/! s/ROUTERID_1/ROUTERID_2/' src/constants.h > src/constantsx.h
mv src/constantsx.h src/constants.h
gnome-terminal --geometry=80x16 -e 'sh -c "make posix && sudo ./main"'

sleep 1
sed '0,/ROUTERID_2/! s/ROUTERID_2/ROUTERID_3/' src/constants.h > src/constantsx.h
mv src/constantsx.h src/constants.h
gnome-terminal --geometry=80x16 -e 'sh -c "make posix && sudo ./main"'

sleep 1
sed '0,/ROUTERID_3/! s/ROUTERID_3/ROUTERID_4/' src/constants.h > src/constantsx.h
mv src/constantsx.h src/constants.h
gnome-terminal --geometry=80x16 -e 'sh -c "make posix && sudo ./main"'

sleep 1
sed '0,/ROUTERID_4/! s/ROUTERID_4/ROUTERID_5/' src/constants.h > src/constantsx.h
mv src/constantsx.h src/constants.h
gnome-terminal --geometry=80x16 -e 'sh -c "make posix && sudo ./main"'

sleep 1

sed '0,/ROUTERID_5/! s/ROUTERID_5/ROUTERID_0/' src/constants.h  > src/constantsx.h
mv src/constantsx.h src/constants.h

sudo chmod a+rwx *
sudo chmod a+rwx */*

