<?php
    session_start();
    require "conecta.php";
    $con = conecta();
    $user = $_REQUEST['user'];
    $pass = $_REQUEST['pass'];
    $pass = md5($pass);
    $sql = "SELECT * FROM clientes
            WHERE correo = '$user' AND pass = '$pass'";
    $res = $con->query($sql);
    $num = $res->num_rows;
    $row = $res->fetch_assoc();
    if($num){
        $id_usuario = $row['id'];
        $nombre_usuario = $row['nombre'].' '.$row['apellidos'];
        $correo_usuario = $row ['correo'];
        $_SESSION['id_usuario'] = $id_usuario;
        $_SESSION['nombre_usuario'] = $nombre_usuario;
        $_SESSION['correo_usuario'] = $correo_usuario;
    }
    echo $num;
?>