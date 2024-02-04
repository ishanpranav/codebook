# Licensed under the MIT License.

run="valgrind -q"
#run=""

for i in {0001..0007};
do
    $run ./../id${i}
done

cat ./../data/id0008.txt | $run ./../id0008

for i in {0009..0010};
do
    $run ./../id${i}
done

cat ./../data/id0011.txt | $run ./../id0011
$run ./../id0012
cat ./../data/id0013.txt | $run ./../id0013

for i in {0014..0017};
do
    $run ./../id${i}
done

cat ./../data/id0018.txt | $run ./../id0018 18

for i in {0019..0021};
do
    $run ./../id${i}
done

cat ./../data/id0022.txt | $run ./../id0022

for i in {0023..0041};
do
    $run ./../id${i}
done

cat ./../data/id0042.txt | $run ./../id0042

for i in {0043..0053};
do
    $run ./../id${i}
done

cat ./../data/id0054.txt | $run ./../id0054

for i in {0055..0058};
do
    $run ./../id${i}
done

cat ./../data/id0059.txt | $run ./../id0059

for i in {0060..0065};
do
    $run ./../id${i}
done

python3 ../src/id0065.py
$run ./../id0066
cat ./../data/id0067.txt | $run ./../id0018 67

for i in {0068..0077};
do
    $run ./../id${i}
done

python3 ../src/id0077.py

for i in {0078..0080}:
do
    $run ./../id${i}
done
