# Licensed under the MIT License.

for i in {0001..0007};
do
    ./../id${i}.o
done

cat ./../data/id0008.txt | ./../id0008.o

for i in {0009..0010};
do
    ./../id${i}.o
done

cat ./../data/id0011.txt | ./../id0011.o
./../id0012.o
cat ./../data/id0013.txt | ./../id0013.o

for i in {0014..0017};
do
    ./../id${i}.o
done

cat ./../data/id0018.txt | ./../id0018.o

for i in {0019..0021};
do
    ./../id${i}.o
done

cat ./../data/id0022.txt | ./../id0022.o

for i in {0023..0050};
do
    ./../id${i}.o
done

cat ./../data/id0067.txt | ./../id0018.o 67
