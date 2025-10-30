<?php
function isprime($n){
    if($n<=1){
        return false;
    }
    for($i=2;$i<sqrt($n);$i++){
        if($n%$i==0){
           return false;
        }
     }return true;
     
}
$n=13;
     if(isprime($n)){
        echo"$n is prime";
     }
     else{
        echo"$n is not prime ";
     }
?>