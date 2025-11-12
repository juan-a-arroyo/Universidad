<?php
    require "conecta.php";
    $con = conecta();
    session_start();
    $id_usuario = $_SESSION['id_usuario'];
    $id_producto = $_REQUEST['id'];
    $cantidad = $_REQUEST['cantidad'];
    date_default_timezone_set('America/Mexico_City');
    $fecha_actual = date("Y-m-d H:i:s");
    $sql = "SELECT * FROM productos
            WHERE `id` = $id_producto";
        $res = $con->query($sql);
    while($row = $res->fetch_array()){
        $precio = $row["costo"];
        $stock = $row["stock"];
    }
    $sql = "SELECT * FROM pedidos
            WHERE `id_usuario` = $id_usuario AND `status` = 0";
    $res = $con->query($sql);
    if ($res && $res->num_rows > 0){
        while($row = $res->fetch_array()){
            $id_pedido = $row["id"];
        }
        $sql = "SELECT * FROM pedidos_productos
                WHERE `id_pedido` = $id_pedido AND `id_producto` = $id_producto";
        $res = $con->query($sql);
        if ($res && $res->num_rows > 0){ 
            while($row = $res->fetch_array()){
                $id_producto_pedido = $row["id"];
                $cantidad_existente = $row["cantidad"];
            }
            $cantidad += $cantidad_existente;
            if($cantidad < 1)
                $cantidad = 1;
            if($cantidad > $stock)
                $cantidad = $stock;
            $sql = "UPDATE `pedidos_productos`
                    SET `cantidad` = $cantidad
                    WHERE `id` = $id_producto_pedido";
            $res = $con->query($sql);
        }
        else{
            if($cantidad < 1)
                $cantidad = 1;
            if($cantidad > $stock)
                $cantidad = $stock;
            $sql = "INSERT INTO pedidos_productos
                    (id_pedido, id_producto, cantidad, precio)
                    VALUES ('$id_pedido', '$id_producto', '$cantidad', '$precio');";
            $res = $con->query($sql);
        }
    }
    else{
        $sql = "INSERT INTO pedidos (fecha, id_usuario) VALUES ('$fecha_actual', '$id_usuario')";
        $res = $con->query($sql);
        $sql = "SELECT id FROM pedidos
                WHERE `id_usuario` = $id_usuario";
        $res = $con->query($sql);
        while($row = $res->fetch_array()){
            $id_pedido = $row["id"];
        }
        if($cantidad < 1)
                $cantidad = 1;
        if($cantidad > $stock)
            $cantidad = $stock;
        $sql = "INSERT INTO pedidos_productos
                (id_pedido, id_producto, cantidad, precio)
                VALUES ('$id_pedido', '$id_producto', '$cantidad', '$precio');";
        $res = $con->query($sql);
    }
?>