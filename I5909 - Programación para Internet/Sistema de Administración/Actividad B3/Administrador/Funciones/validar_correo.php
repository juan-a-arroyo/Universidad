<?php
    require "conecta.php";
    $con = conecta();
    $correo = $_REQUEST['correo'];
    $ban = 0;
    $sql = "SELECT * FROM administradores WHERE correo = '$correo'";
    $res = $con->query($sql);
    if($res->num_rows > 0)
        $ban = 1;
    echo "$ban";
?>