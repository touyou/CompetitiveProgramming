#! /bin/sh

g++ $1.cpp
./a.out < $2.in > $2.out
gedit $2.out
