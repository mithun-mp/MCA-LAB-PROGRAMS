#/bin/bash
echo "enter file name"
read fname
sed -i '/^$/d' "$fname"
echo "empty lines deleted"
