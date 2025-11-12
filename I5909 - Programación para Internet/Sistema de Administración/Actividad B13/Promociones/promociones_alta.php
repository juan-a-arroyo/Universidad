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
    $ruta_productos = "../Productos/productos_lista.php";
    $ruta_promociones = "promociones_lista.php";
    $ruta_pedidos = "../Pedidos/pedidos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Alta de Promociones</title>
    </head>
    <link href="../css/style.css" type="text/css" rel="stylesheet">
    <script src="../js/jquery-3.3.1.min.js"></script>
    <script>
        function validarFormulario() {
            var nombre = $('#nombre').val();
            var archivoInput = $('#archivo');
            var archivo = archivoInput[0].files[0];
            if (nombre == "" || !archivo) {
                $('#mensaje-error').text('Faltan Campos por Llenar').show();
                if (nombre != "" && !archivo){
                    $('#mensaje-error').text('Falta Subir una Fotografía').show();
                }
                setTimeout(function () {
                    $('#mensaje-error').hide();
                }, 5000);
                return false;
            }
        }
        function preview(event) {
            var input = event.target;
            var reader = new FileReader();
            reader.onload = function() {
                var previewImage = document.getElementById('preview-image');
                previewImage.src = reader.result;
            };
            reader.readAsDataURL(input.files[0]);
        }
        function atras(){
            window.location.href = 'promociones_lista.php';
        }
    </script>
    <body>
        <form name="form" action="promociones_salva.php" method="POST" enctype="multipart/form-data">
            <div>
                <table>
                    <tr>
                        <td class="title">ALTA DE PROMOCIONES</td> 
                    </tr>
                    <?php include('../Funciones/menu.php'); ?>
                    <tr>
                        <td class="first">Nombre:<br>
                            <input id="nombre" type="text" name="nombre" placeholder="Nombre">
                        </td>
                    </tr>
                    <tr>
                        <td id="photo" class="first">
                            <label for="archivo">
                                <div class="image-container">
                                    <img class="preview-banner" id="preview-image" src="../css/icons/wide_dark_default.png" alt="Banner">
                                </div>
                            </label>
                            <input id="archivo" type="file" name="archivo" accept="image/*" onchange="preview(event)">
                        </td>
                    </tr>
                    <tr>
                        <td class="bottom">
                            <input class="button" type="submit" value="Guardar" onclick="return validarFormulario();">
                            <input class="button" type="reset" value="Regresar al Listado" onclick="atras();">
                            <div class="message" id="mensaje-error"></div>
                        </td>
                    </tr>
                </table>
            </div>
        </form>
    </body>
</html>