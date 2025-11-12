<?php
    require "conecta.php";
    $con = conecta();
    session_start();
    $id_usuario = $_SESSION['id_usuario'];
    $id_producto = $_REQUEST['id'];
    $sql = "SELECT pedidos_productos.id
            FROM pedidos_productos
            INNER JOIN pedidos ON pedidos.id = pedidos_productos.id_pedido
            WHERE id_producto = $id_producto AND `status` = 0";
    $res = $con->query($sql);
    while($row = $res->fetch_array()){
        $id_pedidos_productos = $row["id"];
    }
    if($id_pedidos_productos > 0){
        $sql = "DELETE FROM pedidos_productos 
                WHERE id = $id_pedidos_productos";
        $res = $con->query($sql);
        if(mysqli_affected_rows($con) > 0)
            $ban = true;
        else
            $ban = false;
    }
    echo "$ban";
?>