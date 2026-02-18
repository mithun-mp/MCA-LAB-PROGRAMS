#!bin/bash
read -p "enter file name " f
echo "enter text"
cat > "$f"
echo "lines : $(wc -l < $f)"
echo "words : $(wc -w < $f)"
echo "Characters : $(wc -c < $f)"
echo "Symbols :$(grep -o '[^a-zA-Z0-9 ]' $f | wc -l)"
