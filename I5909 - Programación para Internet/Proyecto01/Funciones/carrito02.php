<?php
    require "conecta.php";
    $con = conecta();
    session_start();
    $id_usuario = $_SESSION['id_usuario'];
    $sql = "UPDATE `pedidos`
            SET `status` = 1
            WHERE `id_usuario` = $id_usuario AND `status` = 0";
    $res = $con->query($sql);
    header("Location: ../index.php");
?>