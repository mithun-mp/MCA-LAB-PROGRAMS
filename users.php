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
        session_start();
        $servername="localhost";
        $username="root";
        $password="";
        $dbname="MITHUN";
        $conn=mysqli_connect($servername,$username,$password,$dbname);
        if(!$conn){
            die("connection failed: ".mysqli_connect_error());
        }
        if(isset($_POST['register'])){
            $user=$_POST['user'];
            $pass=$_POST['pass'];
            $sql="INSERT INTO user VALUES('$user','$pass')";
            if(!mysqli_query($conn,$sql))
            echo "<br> Error: ".mysqli_error($conn);
            else{
                echo"User Registration Successfull";
            }
        }
       if(isset($_GET['login'])){
            $u=$_GET['User'];
            $p=$_GET['Pass'];
            $sql2="SELECT *from user WHERE user='$u'";
            $r=mysqli_query($conn,$sql2);
            if(mysqli_num_rows($r)>0){
                $row=mysqli_fetch_assoc($r);
                if($row['pass']==$p){
                    $_SESSION['User']==$u;
                    header("Location: welcome.php");
                }else{
                    echo"Incorrect password";
                }
            }else{
                echo"Incorrect username";
            }
            }
        ?>
    </body>
</html>
        


