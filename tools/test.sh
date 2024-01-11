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
./../id0012.o
cat ./../data/id0013.txt | ./../id0013.o

for i in {0014..0016};
do
    ./../id${i}.o
done
