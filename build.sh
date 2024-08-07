#!/bin/bash

rm ./ok

gcc main.c -o ok -L. -llist1 -Wl,-rpath,.
