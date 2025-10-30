<?php
$marks=82;
if ($marks>=90 && $marks<=100){
    echo"your grade is A";
}elseif($marks>=75 && $marks<=90){
    echo"your grade is B";
}elseif($marks>=50 && $marks<=75){
    echo"your grade is C";
}else{
    echo"Failed";
}
?>