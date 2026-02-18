read -p "enter the word:" w
read -p "enter the filename:" f
count=$(grep -o "$w" "$f"|wc -l)
echo "occurances of "$w":$count"
