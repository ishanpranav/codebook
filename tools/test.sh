for i in {0001..0002};
do
    ./../id${i}.o
done

for i in {0004..0008};
do
    ./../id${i}.o
done

./../id0010.o
cat ./../data/id0011.txt | ./../id0011.o
