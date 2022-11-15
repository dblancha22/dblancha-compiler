#!/bin/sh

bminor=./bminor
path=./typecheck_tests/example_tests

for testfile in $path/good*.bminor
do
    if $bminor -typecheck $testfile > $testfile.out; then
        echo "$testfile success (as expected)"
    else
        echo "$testfile failure (INCORRECT)"
    fi
done

for testfile in $path/bad*.bminor
do
    if $bminor -typecheck $testfile > $testfile.out; then
        echo "$testfile failure (INCORRECT)"
    else
        echo "$testfile success (as expected)"
    fi
done
