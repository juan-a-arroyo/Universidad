<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
    </head>
    <link href="../css/style.css" type="text/css" rel="stylesheet">
    <script src="../js/jquery-3.3.1.min.js"></script>
    <script>
        function empleados(){
            window.location.href = "<?php echo $ruta_empleados; ?>";
        }
        function productos(){
            window.location.href = "<?php echo $ruta_productos; ?>";
        }
        function promociones(){
            window.location.href = "<?php echo $ruta_promociones; ?>";
        }
        function cerrarSesion(){
            window.location.href = "<?php echo $ruta_salir; ?>";
        }
    </script>
    <body>
        <tr>
            <td colspan="10" class="tab">
                <input class="button" type="button" value="Inicio" onclick="">
                <input class="button" type="button" value="Empleados" onclick="empleados();">
                <input class="button" type="button" value="Productos" onclick="productos();">
                <input class="button" type="button" value="Promociones" onclick="promociones();">
                <input class="button" type="button" value="Pedidos" onclick="">
                <input class="button" type="button" value="Bienvenido/a <?php echo $nombreU;?>" onclick="">
                <input class="button" type="button" value="Cerrar Sesión" onclick="cerrarSesion();">
            </td>
        </tr>
    </body>
</html>