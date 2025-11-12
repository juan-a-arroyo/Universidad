<?php
    require "conecta.php";
    $con = conecta();
    $correo = $_REQUEST['correo'];
    $pass = $_REQUEST['pass'];
    $passEnc = md5($pass);
    $ban = 0;
    $sql = "SELECT pass FROM administradores WHERE correo = '$correo'";
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