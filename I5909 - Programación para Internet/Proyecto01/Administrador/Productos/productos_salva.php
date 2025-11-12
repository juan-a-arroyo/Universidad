<?php
        require "../../Funciones/conecta.php";
        $con = conecta();
        $nombre = $_REQUEST['nombre'];
        $codigo = $_REQUEST['codigo'];
        $descripcion = $_REQUEST['descripcion'];
        $costo = $_REQUEST['costo'];
        $stock = $_REQUEST['stock'];
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
                $archivo_n = $file_name;
                $archivo = $fileName1;
        }
        $sql = "INSERT INTO productos
                (nombre, codigo, descripcion, costo, stock, archivo_n, archivo)
                VALUES ('$nombre', '$codigo', '$descripcion', '$costo', '$stock', '$archivo_n', '$archivo');";
        $res = $con->query($sql);
        header("Location: productos_lista.php");
        exit;
?>