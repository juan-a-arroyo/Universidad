<?php
        require "../Funciones/conecta.php";
        $con = conecta();
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
                $dir = "Archivos/Fotos/";
                $hash = md5_file($file_tmp);
                if($file_name != ''){
                        $fileName1 = "$hash.$ext";
                        copy($file_tmp, $dir.$fileName1);
                }
                $archivo_n = $file_name;
                $archivo = $fileName1;
        }
        $sql = "INSERT INTO empleados
                (nombre, apellidos, correo, pass, rol, archivo_n, archivo)
                VALUES ('$nombre', '$apellidos', '$correo', '$passEnc', '$rol', '$archivo_n', '$archivo');";
        $res = $con->query($sql);
        header("Location: empleados_lista.php");
        exit;
?>