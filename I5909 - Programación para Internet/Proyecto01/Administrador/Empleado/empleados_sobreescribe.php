<?php
        require "../../Funciones/conecta.php";
        $con = conecta();
        $id = $_REQUEST['id'];
        $nombre = $_REQUEST['nombre'];
        $apellidos = $_REQUEST['apellidos'];
        $correo = $_REQUEST['correo'];
        $pass = $_REQUEST['pass'];
        $rol = $_REQUEST['rol'];
        $passEnc = md5($pass);
        if(isset($_FILES['archivo']) && $_FILES['archivo']['error'] === UPLOAD_ERR_OK) {
                $file_name = $_FILES['archivo']['name'];
                $file_tmp = $_FILES['archivo']['tmp_name'];
                $ext = strtolower(pathinfo($file_name, PATHINFO_EXTENSION));
                $dir = "Archivos/fotos/";
                $hash = md5_file($file_tmp);
                if($file_name != ''){
                        $fileName1 = "$hash.$ext";
                        copy($file_tmp, $dir.$fileName1);
                }
                $archivo_n = $file_name;
                $archivo = $fileName1;
                $sqlFile = "UPDATE `empleados`
                        SET `archivo_n` = '$archivo_n', `archivo` = '$archivo'
                        WHERE `id` = $id';
                        ";
                $res = $con->query($sqlFile);
        }
        $sql = "UPDATE `empleados`
                SET `nombre` = '$nombre', `apellidos` = '$apellidos', `correo` = '$correo', `rol` = '$rol'
                WHERE `id` = $id';
                ";
        $res = $con->query($sql);
        if($pass != ""){
                $sqlPass = "UPDATE `empleados`
                        SET `pass` = '$passEnc'
                        WHERE `id` = $id';";
                $res = $con->query($sqlPass);
        }
        header("Location: empleados_lista.php");
        exit;
?>