<?php
    require "conecta.php";
    $con = conecta();
    $user = $_REQUEST['user'];
    $pass = $_REQUEST['pass'];
    $pass = md5($pass);
    $sql = "SELECT * FROM administradores
            WHERE correo = '$user' AND pass = '$pass' AND status = 1 AND eliminado = 0";
    $res = $con->query($sql);
    $num = $res->num_rows;
    $row = $res->fetch_assoc();
    echo $num;
?>