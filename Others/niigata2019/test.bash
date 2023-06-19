cat ./input.txt | while read line
do
    echo $line > tmp.txt
    ./a.out < tmp.txt >> output.txt
done
