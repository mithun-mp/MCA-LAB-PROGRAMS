<!DOCTYPE html>
<html>
    <head>
        <title>Odd or Even</title>
    </head>
    <body>
        <h2>Check odd or evee</h2>
        <form method="GET">
            Enter Number:
            <input type="number" name="a" required><br><br>
            <input type="submit" name="submit" >
        </form>
        <?php
        if(isset($_GET['a'])){
            $n=$_GET['a'];
            if($n%2==0){
                echo "$n is even";
            }else{
                echo"$n is odd";
            }
            }
        ?>
    </body>
</html>