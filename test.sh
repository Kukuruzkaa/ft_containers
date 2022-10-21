#!/bin/bash

if [ "$#" == "0" ]
then
	printf "./test.sh seed\n";
	exit 1
fi

FT_RES="ft_res"
STD_RES="std_res"
EXE=_containers

make;

./ft$EXE $1 > $FT_RES
./std$EXE $1 > $STD_RES

diff $2 $FT_RES $STD_RES
