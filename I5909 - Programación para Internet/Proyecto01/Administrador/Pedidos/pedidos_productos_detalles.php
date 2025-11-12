<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $cantidad_total = $_GET['cantidad_total'] ?? 0;
    $precio_total = $_GET['precio_total'] ?? 0;
    $ruta_salir = "../Empleado/Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_inicio = "../bienvenido.php";
    $ruta_empleados = "../Empleado/empleados_lista.php";
    $ruta_productos = "../Productos/productos_lista.php";
    $ruta_promociones = "../Promociones/promociones_lista.php";
    $ruta_pedidos = "pedidos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Detalles</title>
        <?php
            require "../../Funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $id_p = $_REQUEST['id_p'];
            $sql = "SELECT * FROM productos
                    WHERE id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $id = $row["id"];
                $nombre = $row["nombre"];
                $codigo = $row["codigo"];
                $descripcion = $row["descripcion"];
                $archivo = $row["archivo"];
                $ruta_archivo = "../Productos/Archivos/Fotos/$archivo";
                $timestamp = time();
                $url_imagen = $ruta_archivo . "?v=" . $timestamp;
            }
            $sql2 = "SELECT * FROM pedidos_productos
                     WHERE id_pedido = $id_p AND id_producto = $id";
            $res2 = $con->query($sql2);
            while($row = $res2->fetch_array()){
                $precio = $row['precio'];
                $cantidad = $row['cantidad'];
            }
        ?>
    </head>
    <link href="../../css/style.css" type="text/css" rel="stylesheet">
    <script src="../../js/jquery-3.3.1.min.js"></script>
    <script>
        function atras(id){
                window.location.href = 'pedidos_detalles.php?id=' + id;
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="3">Detalles de Producto</td>
                </tr>
                <?php include('../Funciones/menu.php'); ?>
                <tr>
                    <td id="photo" class="first" width="500" rowspan="6">
                        <div class="image-container">
                            <?php
                                if(!is_file("../Productos/Archivos/fotos/$archivo"))
                                echo "<img class=\"preview\" src=\"../css/icons/light_default.png\" alt=\"Producto\">";
                            else
                                echo "<img class=\"preview\" src=\"$url_imagen\" alt=\"Producto\">";
                            ?>
                        </div>
                    </td>
                    <td class="first">ID: </td>
                    <?php
                        echo "<td>$id</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Nombre: </td>
                    <?php
                        echo "<td>$nombre</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Código: </td>
                    <?php
                        echo "<td>$codigo</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Descripcion: </td>
                    <?php
                        echo "<td>$descripcion</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Precio: </td>
                    <?php
                        echo "<td>$".number_format($precio, 2)."</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Cantidad: </td>
                    <?php
                        echo "<td>$cantidad</td>";
                    ?>
                </tr>
                <tr>
                    <td class="bottom" colspan="3">
                        <input class="button" type="reset" value="Regresar al Listado" onclick="atras(<?php echo $id_p; ?>);">
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>