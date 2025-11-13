<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<form method="POST">
name:<input type="text" name="name"><br>
<input type="submit" name="submit" value="submit">
</form>
<?php
if (isset($_POST['submit']))
{
    $students=trim($_POST['name']);
    if($student=""){
        echo"enter atleast one name";
    }
    else{
        $name=explode(",",$students);
        echo"original";
        print_r($name);
        echo"<br><br>";
        asort($name);
        print_r($name);
        echo"<br><br>";
        arsort($name);
        print_r($name);
    }
}
?>
</body>
</html>
