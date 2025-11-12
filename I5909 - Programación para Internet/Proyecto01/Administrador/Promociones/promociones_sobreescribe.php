<?php
        require "../../Funciones/conecta.php";
        $con = conecta();
        $id = $_REQUEST['id'];
        $nombre = $_REQUEST['nombre'];
        if(isset($_FILES['archivo']) && $_FILES['archivo']['error'] === UPLOAD_ERR_OK) {
                $file_name = $_FILES['archivo']['name'];
                $file_tmp = $_FILES['archivo']['tmp_name'];
                $ext = strtolower(pathinfo($file_name, PATHINFO_EXTENSION));
                $dir = "Archivos/Fotos/";
                $hash = md5_file($file_tmp);
                if($file_name != ''){
                        $fileName1 = "$hash.$ext";
                        copy($file_tmp, $dir.$fileName1);
                }
                $archivo = $fileName1;
                $sqlFile = "UPDATE `promociones`
                        SET `archivo` = '$archivo'
                        WHERE `id` = $id';
                        ";
                $res = $con->query($sqlFile);
        }
        $sql = "UPDATE `promociones`
                SET `nombre` = '$nombre'
                WHERE `id` = $id';
                ";
        $res = $con->query($sql);
        header("Location: promociones_lista.php");
        exit;
?>