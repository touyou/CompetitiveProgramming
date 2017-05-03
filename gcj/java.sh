#! /bin/sh

javac $1.java
java $1 < $2.in > $2.out
gedit $2.out
