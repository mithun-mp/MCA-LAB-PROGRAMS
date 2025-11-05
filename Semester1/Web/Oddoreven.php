<!DOCTYPE html>
<html>
<body>

<form method="post">
  Enter a number: <input type="number" name="num">
  <input type="submit" value="Check">
</form>

<?php
if (isset($_POST['num'])) {
    $n = $_POST['num'];
    if ($n % 2 == 0)
        echo "$n is Even";
    else
        echo "$n is Odd";
}
?>

</body>
</html>
