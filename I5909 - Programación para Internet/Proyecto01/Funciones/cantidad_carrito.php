<?php
    require "conecta.php";
    $con = conecta();
    session_start();
    $id_usuario = $_SESSION['id_usuario'];
    $id_pedido = null;
    $sql = "SELECT id
            FROM pedidos
            WHERE `id_usuario` = $id_usuario AND `status` = 0";
    $res = $con->query($sql);
    while($row = $res->fetch_array()){
        $id_pedido = $row["id"];
    }
    $cantidad = 0;
    if ($id_pedido != null) {
        $sql = "SELECT SUM(cantidad) AS suma
                FROM pedidos_productos
                WHERE `id_pedido` = $id_pedido";
        $res = $con->query($sql);
        while($row = $res->fetch_array()){
            $cantidad = $row["suma"];
        }
        if($cantidad == null)
            $cantidad = 0;
    }
    echo $cantidad;
?>