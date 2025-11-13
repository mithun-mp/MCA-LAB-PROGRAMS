<!DOCTYPE html>
<html>
    <body>
        <h2>Book Information</h2>
        <form method="POST">
            Book No:<input type="number" name="book_no"><br>
            Title:<input type="text" name="title"><br>
            Edition:<input type="text" name="edition"><br>
            Publisher:<input type="text" name="publisher"><br>
            <input type="submit" name="submit" value="submit">
        </form>
        <form method="get">
            <br>search by Title:<input type="text" name="search">
            <input type="submit" value="search">
        </form>
        <?php
        $server="localhost";
        $user="root";
        $pass="";
        $db="libraryb";
        $conn=mysqli_connect($server,$user,$pass,$db);
        if(!$conn){
            die("Connection failed: ".mysqli_connect_error());
        }
        if(isset($_POST['submit'])){
            $no=$_POST['book_no'];
            $title=$_POST['title'];
            $edition=$_POST['edition'];
            $publisher=$_POST['publisher'];
            $sql="INSERT INTO book VALUES('$no','$title','$edition','$publisher')";
        if(mysqli_query($conn,$sql)){
            echo"<h3>book added</h3>";
        }
    }
        if(isset($_GET['search'])){
            $title=$_GET['search'];
            $res=mysqli_query($conn,"select * from book where title like '%$title%'");
            echo "<table border='1px'><tr><th>No</th><th>title</th><th>edition</th><th>publisher</th></tr>";
            while($row=mysqli_fetch_assoc($res)){
                echo"<tr><th>{$row['book_no']}</th><th>{$row['title']}</th><th>{$row['edition']}</th><th>{$row['publisher']}</th></tr>" ;
            }}
            else if(!isset($_GET['search'])){
                $res=mysqli_query($conn,"select * from book");
                echo"all books";
                echo "<tr><th>No</th><th>title</th><th>edition</th><th>publisher</th></tr>";
                while($row=mysqli_fetch_assoc($res)){
                echo"<tr><th>{$row['book_no']}</th><th>{$row['title']}</th><th>{$row['edition']}</th><th>{$row['publisher']}</th></tr></table>" ;
            }
            echo"</table>";
            $conn.close();
            // mysqli_num_rows($r)>0
        }
        ?>
        </body>
        </html>
/opt/lampp/htdocs/adithya/loginpage/welcome.php

