<!DOCTYPE html>
<html>
    <head>
        <title>Factorial</title>
    </head>
    <body>
        <h2>Factorial</h2>
        <form method="post" >
            Enter Number:
            <input type="number" name="a" required><br><br>
            <input type="submit" name="submit" value="Print">
        </form>
        <?php
        function fact($n){
            if($n==0 || $n==1){
                return 1;
            }else{
                return $n*fact($n-1);
            }
        }
        if(isset($_POST['submit'])){
            $n=$_POST['a'];
            echo "factorial : ".fact($n);
        }
        ?>
    </body>
</html>