#!/usr/bin/env bash

echo "Compiling"
g++ -Wall -Wextra -I. main.cxx -o main

if [[ $? != 0 ]]; then
	echo "compilation failed"
else
	echo "Compiled successfully"
fi
