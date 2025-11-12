<?php
    session_start();
    require "../../../Funciones/conecta.php";
    $con = conecta();
    $user = $_REQUEST['user'];
    $pass = $_REQUEST['pass'];
    $pass = md5($pass);
    $sql = "SELECT * FROM empleados
            WHERE correo = '$user' AND pass = '$pass' AND status = 1 AND eliminado = 0";
    $res = $con->query($sql);
    $num = $res->num_rows;
    $row = $res->fetch_assoc();
    if($num){
        $idU = $row['id'];
        $nombre = $row['nombre'].' '.$row['apellidos'];
        $correo = $row ['correo'];
        $_SESSION['idU'] = $idU;
        $_SESSION['nombre'] = $nombre;
        $_SESSION['correo'] = $correo;
    }
    echo $num;
?>