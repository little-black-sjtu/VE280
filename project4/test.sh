#!/bin/bash
for a in {1..10}
do
    ./compress testcases/text$a > result/binary$a.in
    ./compress -tree testcases/text$a > result/tree$a.in
    ./decompress result/tree$a.in result/binary$a.in > testcases/text$a.out
    diff testcases/text$a testcases/text$a.out > difference.txt
done
