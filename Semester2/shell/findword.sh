#/bin/bash
echo "Enter the name of file"
read fname
echo "Enter the word to delete"
read word
if [ ! -f "$fname" ]; then
echo "File doesn't exist..!"
exit 1
fi
grep -v "$word" "$fname"> temp.txt
mv temp.txt "$fname"
echo "lines containing '$word'deleted"

