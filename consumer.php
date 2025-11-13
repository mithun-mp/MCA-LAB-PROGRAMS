<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form method="POST">
        Consumer Name:<input type="text" name="cname"><br><br>
        Consumer No:<input type="text" name="cno"><br><br>
        Units Consumed:<input type="text" name="unit"><br>
        <input type="submit" name="submit" value="submit">

    </form>
    <?php
    if (isset($_POST['submit'])){
        $name=$_POST["cname"];
        $cno=$_POST['cno'];
        $unit=$_POST['unit'];
        $fixed=70;
        $meter=25;
        if($unit<=100){
            $energy=$unit*3.50;
            $calc="$unit X 3.50";
        }else if($unit<=200){
            $energy=(100*3.50)+(($unit-100)*4.50);
            $lu=$unit-100;
            $calc="(100 X 3.50)+($lu X 4.50)";
        }else if($unit<=400){
            $energy=(100*3.50)+(100*4.50)+(($unit-200)*6.50);
            $lu=$unit-200;
            $calc="(100 X 3.50)+(100 X 4.50)+($lu X 6.50)";
        }
        else{
            $energy=(100*3.50)+(100*4.50)+(200*6.50)+(($unit-400)*8.50);
            $lu=$unit-400;
            $calc="(100 X 3.50)+(100 X 4.50)+(200 X 6.50)+($lu X 8.50)";
        }
        $total=$energy+$fixed+$meter;
        $total=round($total,2);
        echo"<h2>Eletricity Bill:</h2><br><br>";
        echo"<table border='1px'><tr><th>Consumer NO:</th><th>Consumer:</th><th><Units></th><th>Consumed energy Rate</th><th>Total</th></tr><tr><td>$cno</td><td>$name</td><td>$unit</td><td>$calc</td><td>$total</td></tr></table>";
    }
    ?>
</body>
</html>