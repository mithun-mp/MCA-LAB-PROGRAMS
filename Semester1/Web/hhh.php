<!DOCTYPE html>
<html>
    <head>
        <title>Print numbers</title>
    </head>
    <body>
        <h2>Print Numbers</h2>
        <form method="post">Number 1 :
            <input type="number" name="a" required><br><br>Number 2:
            <input type="number" name="b" required><br><br>
            <input type="submit" name="submit" value="Print">
        </form>
        <?php
        function printNumbers($num1,$num2){
            for($i=a;$i<=b;$i++)
            {
                return $i;
            }
        }
        if(isset($_POST['submit'])){
            $num1=$_POST['a'];
            $num2=$_POST['b'];
            $sum=printNumbers($num1,$num2);
            echo "<p> Numbers from $num1 to $num2 is: <strong>$i</strong></p>";
        }
        ?>
    </body>
</html>