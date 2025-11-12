<?php
    require "../../Funciones/conecta.php";
    $con = conecta();
    $codigo = $_REQUEST['codigo'];
    $ban = 0;
    $sql = "SELECT * FROM productos WHERE codigo = '$codigo'";
    $res = $con->query($sql);
    if($res->num_rows > 0)
        $ban = 1;
    echo $ban;
?>