<?php
session_start();
if(!isset($_SESSION['User'])){
    header("Location:users.php");
    exit();
}
?>
<DOCTYPE html>
    <html>
        <body>
            <h2>Welcome page</h2>
            <P>Welcome,<?php echo $_SESSION['User'];?>!</p>
            <a href="users.php">logout</a>
</body>
</html>