<?php
    require "conecta.php";
    $con = conecta();
    $user = $_REQUEST['user'];
    $pass = $_REQUEST['pass'];
    $passEnc = md5($pass);
    $ban = 0;
    $sql = "SELECT pass FROM administradores WHERE correo = '$user' AND eliminado != '1'";
    $res = $con->query($sql);
    if ($res->num_rows > 0) {
        $row = $res->fetch_assoc();
        $passDB = $row['pass'];
        if ($passEnc == $passDB) {
            $ban = 1;
        }
    }
    echo $ban;
?>