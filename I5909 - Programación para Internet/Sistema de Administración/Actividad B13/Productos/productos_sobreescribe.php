<?php
        require "../Funciones/conecta.php";
        $con = conecta();
        $id = $_REQUEST['id'];
        $nombre = $_REQUEST['nombre'];
        $codigo = $_REQUEST['codigo'];
        $descripcion = $_REQUEST['descripcion'];
        $costo = $_REQUEST['costo'];
        $stock = $_REQUEST['stock'];
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
                $sqlFile = "UPDATE `productos`
                        SET `archivo_n` = '$archivo_n', `archivo` = '$archivo'
                        WHERE `id` = $id';
                        ";
                $res = $con->query($sqlFile);
        }
        $sql = "UPDATE `productos`
                SET `nombre` = '$nombre', `codigo` = '$codigo', `descripcion` = '$descripcion', `costo` = '$costo', `stock` = '$stock'
                WHERE `id` = $id';
                ";
        $res = $con->query($sql);
        header("Location: productos_lista.php");
        exit;
?>