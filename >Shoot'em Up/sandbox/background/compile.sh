#!/bin/bash


for c_file in $(find . -name "*.c" -type f)
do
    o_file=$(echo $c_file | cut -d'/' -f 3 | cut -d'.' -f 1)
    # echo -e $o_file
    gcc  -I ./include/ -o ./obj/$o_file.o -c $c_file $(sdl2-config --cflags --libs)
done

     gcc  -I ./include/ -o test ./obj/*.o $(sdl2-config --cflags --libs)