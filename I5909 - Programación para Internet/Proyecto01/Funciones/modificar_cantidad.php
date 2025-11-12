<?php
    require "conecta.php";
    $con = conecta();
    session_start();
    $id_usuario = $_SESSION['id_usuario'];
    $id_producto = $_REQUEST['id'];
    $cantidad = $_REQUEST['cantidad'];
    $sql = "SELECT id FROM pedidos
            WHERE `id_usuario` = $id_usuario AND `status` = 0";
    $res = $con->query($sql);
    while($row = $res->fetch_array()){
        $id_pedido = $row["id"];
    }
    $sql = "UPDATE `pedidos_productos`
            SET `cantidad` = $cantidad
            WHERE `id_pedido` = $id_pedido AND `id_producto` = $id_producto";
    $res = $con->query($sql);
?>