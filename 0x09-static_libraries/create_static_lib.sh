#!/bin/bash

gcc -c *.c
ar rc libmy.a *.o
echo y | rm -I *.o
