<?php
session_start();
$servername="localhost";
$username="root";
$password="";
$dbname="MITHUN";
$conn=mysqli_connect($servername,$username,$password,$dbname);
if(!$conn){
    die("connection failed: ".mysqli_connect_error());
}
if(isset($_POST['login'])){
    $user=$_POST['username'];
    $pass=$_POST['password'];
    $sql="SELECT * FROM users WHERE username='$user'";
    $result=mysqli_query($conn,$sql);
    $row=mysqli_fetch_assoc($result);
    if($row){
        if($row['password']==$pass){
            $_SESSION['username']==$user;
            header("Location:welcome.php");
        }else{
            echo"Incorrect password";
        }
        }else{
            echo"Incorrect username";
        }
    
}
?>
<!DOCTYPE html>
<html>
    <body>
        <h2>Login Form</h2>
        <form method="post">
            username:<input type="text" name="username"><br>
            password:<input type="password" name="password"><br>
            <input type="submit" name="login" value="login">
        </form>
</body>
</html>
