<?php
session_start();
$servername="localhost";
$username="root";
$password="";
$dbname="userdb";
$conn=mysqli_connect($servername,$username,$password,$dbname);

if(isset($_POST['login'])){
    $user=$_POST['username'];
    $pass=$_POST['password'];
    $sql="SELECT * FROM users WHERE username='$user'";
    $result=mysqli_query($conn,$sql);
  
    if(mysqli_num_rows($result)>0){
        $row=mysqli_fetch_assoc($result);
        if($row['password']==$pass){
            $_SESSION['username']==$user;
            echo"login successfull welcome back $user";
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
