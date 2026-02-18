read -p "enter the filename :" f
read -p "enter the word to delete:" w
grep -i -v "$w" "$f">temp && mv temp "$f"
echo "Line containing "$w" deleted"
