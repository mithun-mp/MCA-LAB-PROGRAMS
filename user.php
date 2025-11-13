<!DOCTYPE html>
<html>
    <body>
        <h2>User Register</h2>
        <form method="post">
            User Name:<input type="text" name="user"><br>
            Password:<input type="text" name="pass"><br>
            <input type="submit" name="register" value="Register">
        </form>
        <h2>User Login</h2>
        <form method="get">
            User Name:<input type="text" name="User"><br>
            Password:<input type="text" name="Pass"><br>
            <input type="submit" name="login" value="Login">
        </form>
        <?php
        $server="localhost";
        $user="root";
        $pass="";
        $db="MITHUN";
        $conn=mysqli_connect($server,$user,$pass,$db);
        if(!$conn){
            die("Connection failed: ".mysqli_connect_error());
        }
        if(isset($_POST['login'])){
            $user=$_POST['user'];
            $pass=$_POST['pass'];
            $sql="INSERT INTO user VALUES('$user','$pass')";
            if(mysqli_query($conn,$sql))
            echo "<br> Error: ".mysqli_error($conn);
        }
       if(isset($_GET['login'])){
            $u=$_GET['User'];
            $p=$_GET['Pass'];
            $r=mysqli_query($conn,"SELECT pass from user WHERE user='$u'");
            if(mysqli_num_rows($r)>0){
            if($r==$p){
            echo" hello $u welcome back";
            }else{
            echo"incorrect password";
            }
            }else{
            echo"user not found";
            }
        }
        mysqli_close($conn);
        ?>
    </body>
</html>
        


