<!DOCTYPE html>
<html>
    <body>
        <h2>Book Information</h2>
        <form method="POST">
            user<input type="text" name="user"><br>
            pass<input type="text" name="pass"><br>
            <input type="submit" name="submit" value="login">
        </form>
        <!--  -->
        <?php
        $server="localhost";
        $user="root";
        $pass="";
        $db="libraryb";
        $conn=mysqli_connet($server,$user,$pass,$db);
        if(!$conn){
            die("Connection failed: ".mysqli_connect_error());
        }

        if(isset($_POST['submit'])){
            $user=$_POST['user'];
            $pass=$_POST['pass'];
            $sql="INSERT INTO book VALUES('$user','$pass')";
        }
        if(mysqli_query($conn,$sql)){
            echo"<h3>book added</h3>";
        }
        if(isset($_GET['search'])){
            $title=$_GET['search'];
            $res=mysqli_query($conn,"select * from book where title like '%$title%'");
            echo "<table><tr><th>No</th><th>title</th><th>edition</th><th>publisher</th></tr>";
            while($row=mysqli_fetch_assoc($res)){
                echo"<tr><th>{$row['book_no']}</th><th>{$row['title']}</th><th>{$row['edition']}</th><th>{$row['publisher']}</th></tr></table>" ;
            }}
            else if(!isset($_GET['search'])){
                $res=mysqli_query($conn,"select * from book");
                echo "<table><tr><th>No</th><th>title</th><th>edition</th><th>publisher</th></tr>";
                while($row=mysqli_fetch_assoc($res)){
                echo"<tr><th>{$row['book_no']}</th><th>{$row['title']}</th><th>{$row['edition']}</th><th>{$row['publisher']}</th></tr></table>" ;
            }
            $conn.close();
        }
        ?>
        </body>
        </html>


