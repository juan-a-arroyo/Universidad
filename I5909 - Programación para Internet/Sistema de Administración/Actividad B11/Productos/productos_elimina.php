<?php
    require "../Funciones/conecta.php";
    $con = conecta();
    $id = $_REQUEST['id'];
    if($id > 0){
        $sql = "UPDATE productos
        SET eliminado = 1
        WHERE id = $id";
        $res = $con->query($sql);
        if(mysqli_affected_rows($con) > 0)
            $ban = true;
        else
            $ban = false;
    }
    echo "$ban";
?>