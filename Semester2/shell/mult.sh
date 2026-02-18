for i in $(seq 1 10)
do
echo "table of $i"
for j in $(seq 1 10)
do
echo "$i * $j = $((i*j))"
done
echo " "
done
