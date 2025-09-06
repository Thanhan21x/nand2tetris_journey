#!/bin/bash

make clean
make 

if [ $? -eq 0 ]; then
	./VMTranslater ../ProgramFlow/BasicLoop/BasicLoop.vm

	echo "Translated code:"

	cat ../ProgramFlow/BasicLoop/BasicLoop.asm
else
	echo "Build failed."
fi
