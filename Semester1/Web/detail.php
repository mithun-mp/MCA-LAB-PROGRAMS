<!DOCTYPE html>
<html>
    <head>
        <title>student data</title>
    </head>
    <body>
        <h2>Student data</h2>
        <form method="$_REQUEST">
          
            Name:<input type="text" name="name" required><br><br>
            Email:<input type="email" name="email" required><br><br>
            Address:<input type="address" name="adress" required><br><br>
            Gender:<input type="text" name="gender" required><br><br>
            DOB:<input type="date" name="dob" required><br><br>
            <input type="submit" name="submit" >
        </form>
        <?php
        if(isset($_REQUEST['submit'])){

            $name =$_REQUEST['name'];
            $email =$_REQUEST['email'];
            $address =$_REQUEST['address'];
            $gender =$_REQUEST['gender'];
            $dob =$_REQUEST['dob'];
            echo"name :$name<br><br>";
            echo"email :$email<br><br>";
            echo"address :$address<br><br>";
            echo"gender :$gender<br><br>";
            echo"dob :$dob<br><br>";
            }
        ?>
    </body>
</html>