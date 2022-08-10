make
rm -f result
while read rows
do
echo $rows > temp
echo "input: $rows" >> result
./p1 < temp >> result
rm temp
done < testcases
make clean