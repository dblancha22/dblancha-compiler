#!/bin/bash

program=$1

bminor -codegen $program.bminor $program.s
gcc $program.s library.c -o $program
./$program