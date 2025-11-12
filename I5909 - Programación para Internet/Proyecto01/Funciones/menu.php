<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
    </head>
    <link href="../css/style.css" type="text/css" rel="stylesheet">
    <script src="../js/jquery-3.3.1.min.js"></script>
    <script>
        function inicio(){
            window.location.href = "index.php";
        }
        function productos(){
            window.location.href = "productos.php";
        }
        function carrito(){
            window.location.href = "carrito_paso1.php";
        }
        function iniciarSesion(){
            window.location.href = "iniciar_sesion.php";
        }
        function contacto(){
            window.location.href = "contacto.php";
        }
        function cerrarSesion(){
            if(confirm("¿Desea cerrar su sesión?")){
                window.location.href = "Funciones/cerrar_sesion.php";
            }
        }
        function actualizarCantidadCarrito() {
            var xhr = new XMLHttpRequest();
            xhr.open('GET', 'Funciones/cantidad_carrito.php', true);
            xhr.onload = function () {
                if (xhr.status === 200) {
                    var cantidad = xhr.responseText;
                    document.getElementById('carrito').value = 'Carrito (' + cantidad + ')';
                } else {
                    console.error('Error al obtener la cantidad del carrito.');
                }
            };
            xhr.send();
        }
        actualizarCantidadCarrito();
    </script>
    <body>
        <tr>
            <td colspan="10" class="tab">
                <img class="logo" src="css/icons/logo.png" alt="LOGO" width="75">
                <input class="button" type="button" value="Inicio" onclick="inicio();">
                <input class="button" type="button" value="Productos" onclick="productos();">
                <input class="button" type="button" value="Contacto" onclick="contacto();">
                <?php
                    if($id_usuario  != ""){
                        echo "<input class=\"button\" type=\"button\" value=\"Hola $nombre_usuario\">";
                        echo "<input class=\"button\" type=\"button\" id=\"cerrar-sesion\" value=\"Cerrar Sesión\" onclick=\"cerrarSesion();\">";
                        echo "<input class=\"button\" type=\"button\" id=\"carrito\" value=\"Carrito\" onclick=\"carrito();\">";
                    }
                    else{
                        echo "<input class=\"button\" type=\"button\" id=\"iniciar-sesion\" value=\"Iniciar Sesión\" onclick=\"iniciarSesion();\">";
                    }
                ?>
            </td>
        </tr>
    </body>
</html>