#!/bin/bash
read -p "enter url " url
if [[ $url =~ ^https?:// ]];then
echo "url is valid"
else 
echo "invalid url"
fi
