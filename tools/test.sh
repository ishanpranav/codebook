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

for i in {0014..0017};
do
    ./../id${i}.o
done

cat ./../data/id0018.txt | ./../id0018.o
cat ./../data/id0067.txt | ./../id0018.o 67

for i in {0019..0020};
do
    ./../id${i}.o
done
