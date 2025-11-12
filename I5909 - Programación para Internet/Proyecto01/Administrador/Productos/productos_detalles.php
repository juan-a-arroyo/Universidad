<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "../Empleado/Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_inicio = "../bienvenido.php";
    $ruta_empleados = "../Empleado/empleados_lista.php";
    $ruta_productos = "productos_lista.php";
    $ruta_promociones = "../Promociones/promociones_lista.php";
    $ruta_pedidos = "../Pedidos/pedidos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Detalles de producto</title>
        <?php
            require "../../Funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT * FROM productos
                    WHERE id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $id = $row["id"];
                $nombre = $row["nombre"];
                $codigo = $row["codigo"];
                $descripcion = $row["descripcion"];
                $costo = $row["costo"];
                $stock = $row["stock"];
                $archivo = $row["archivo"];
                $ruta_archivo = "Archivos/Fotos/$archivo";
                $timestamp = time();
                $url_imagen = $ruta_archivo . "?v=" . $timestamp;
            }
        ?>
    </head>
    <link href="../../css/style.css" type="text/css" rel="stylesheet">
    <script src="../../js/jquery-3.3.1.min.js"></script>
    <script>
        function atras(){
            window.location.href = 'productos_lista.php';
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
                                if(!is_file("archivos/fotos/$archivo"))
                                    echo "  <img class=\"preview\" src=\"../../css/icons/light_default.png\" alt=\"Producto\">";
                                else{
                                    echo "<div class=\"product-image-container\">";
                                    echo "  <img class=\"product-image\" src=\"$url_imagen\" alt=\"Producto\">";
                                    echo "</div>";
                                }
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
                    <td class="first">Descripción: </td>
                    <?php
                        echo "<td>$descripcion</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Costo: </td>
                    <?php
                        echo "<td>$".number_format($costo, 2)."</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Stock: </td>
                    <?php
                        echo "<td>$stock</td>";
                    ?>
                </tr>
                <tr>
                    <td class="bottom" colspan="3">
                        <input class="button" type="reset" value="Regresar" onclick="atras();">
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>