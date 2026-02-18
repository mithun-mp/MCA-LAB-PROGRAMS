read -p "enter the word:" w
read -p "enter the filename:" f
read -p "enter the starting line:" s
read -p "enter the ending line:" e
count=$(sed -n "$s,$e p" "$f"|grep -o "$w"|wc -l)
echo "occurance between lines $s-$e :$count"
