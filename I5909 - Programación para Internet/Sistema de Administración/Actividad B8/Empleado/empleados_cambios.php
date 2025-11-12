<?php
        require "funciones/conecta.php";
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
                $cadena = explode(".", $file_name);
                $ext = $cadena[1];
                $dir = "archivos/fotos/";
                $new_file_name = $nombre."_".$apellidos."_".$correo.".";
                $file_enc = md5($new_file_name);
                if($file_name != ''){
                        $fileName1 = "$file_enc.$ext";
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