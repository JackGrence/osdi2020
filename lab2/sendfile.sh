#!/bin/bash
tty=/dev/pts/3
size=`stat --printf="%s" $1`
sudo stty -F $tty 115200
printf "0: %.8x" $size | sed -E 's/0: (..)(..)(..)(..)/0: \4\3\2\1/' | xxd -r | sudo tee $tty &>/dev/null
sudo tee $tty < $1 &>/dev/null
