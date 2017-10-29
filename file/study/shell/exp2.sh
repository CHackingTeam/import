#!/usr/bin/sh

IFS=::
set x y z
echo "$*"
echo $@


var="'(]\\}\$\""
echo $var
echo "$var"

echo

IFS='\'
echo $var
echo "$var"

exit 0

