<?php
        require "funciones/conecta.php";
        $con = conecta();
        $id = $_REQUEST['id'];
        $nombre = $_REQUEST['nombre'];
        $apellidos = $_REQUEST['apellidos'];
        $correo = $_REQUEST['correo'];
        $pass = $_REQUEST['pass'];
        $rol = $_REQUEST['rol'];
        $archivo_n = '';
        $archivo = '';
        $passEnc = md5($pass);
        $sql = "UPDATE `administradores`
                SET `nombre` = '$nombre', `apellidos` = '$apellidos', `correo` = '$correo', `rol` = '$rol', `archivo_n` = '$archivo_n', `archivo` = '$archivo'
                WHERE `id` = $id';
                ";
        $res = $con->query($sql);
        if($pass != ""){
                $sqlPass = "UPDATE `administradores`
                        SET `pass` = '$passEnc'
                        WHERE `id` = $id';";
                $res = $con->query($sqlPass);
        }
        header("Location: administradores_lista.php");
        exit;
?>