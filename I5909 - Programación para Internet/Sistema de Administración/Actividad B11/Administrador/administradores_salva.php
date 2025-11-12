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
                $new_file_name = $nombre."_".$apellidos."_".$correo.".";
                $file_enc = md5($new_file_name);
                if($file_name != ''){
                        $fileName1 = "$file_enc.$ext";
                        copy($file_tmp, $dir.$fileName1);
                }
                $archivo_n = $file_name;
                $archivo = $fileName1;
        }
        $sql = "INSERT INTO administradores
                (nombre, apellidos, correo, pass, rol, archivo_n, archivo)
                VALUES ('$nombre', '$apellidos', '$correo', '$passEnc', '$rol', '$archivo_n', '$archivo');";
        $res = $con->query($sql);
        header("Location: administradores_lista.php");
        exit;
?>