<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_inicio = "../bienvenido.php";
    $ruta_empleados = "empleados_lista.php";
    $ruta_productos = "../Productos/productos_lista.php";
    $ruta_promociones = "../Promociones/promociones_lista.php";
    $ruta_pedidos = "../Pedidos/pedidos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Alta de Empleados</title>
    </head>
    <link href="../../css/style.css" type="text/css" rel="stylesheet">
    <script src="../../js/jquery-3.3.1.min.js"></script>
    <script>
        var correoValido = true;
        function validarCorreo() {
            var correoInput = $('#correo');
            var correo = correoInput.val();
            $.ajax({
                url: 'Funciones/validar_correo.php',
                method: 'POST',
                data: { correo: correo },
                success: function(res) {
                    if (res == 1){
                        $('#correo-error').text('El correo electrónico ya existe').show();
                        setTimeout(function() {
                            $('#correo-error').hide();
                        }, 5000);
                        correoValido = false;
                        return false;
                    }
                    else{
                        $('#correo-error').text('');
                        correoValido = true;
                    }
                }
            });
        }
        function validarFormulario() {
            var nombre = $('#nombre').val();
            var apellidos = $('#apellidos').val();
            var correo = $('#correo').val();
            var pass = $('#pass').val();
            var archivoInput = $('#archivo');
            var archivo = archivoInput[0].files[0];
            if (nombre == "" || apellidos == "" || correo == "" || pass == "" || correoValido == false || !archivo) {
                $('#mensaje-error').text('Faltan Campos por Llenar').show();
                if(nombre != "" && apellidos != "" && correo != "" && pass != "" && !archivo)
                    $('#mensaje-error').text('Falta Subir una Fotografía').show();
                if(nombre != "" && apellidos != "" && correo != "" && pass != "" && correoValido == false)
                    $('#mensaje-error').text('Correo electrónico inválido').show();
                setTimeout(function() {
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
            window.location.href = 'empleados_lista.php';
        }
    </script>
    <body>
        <form name="form" action="empleados_salva.php" method="POST" enctype="multipart/form-data">
            <div>
                <table>
                    <tr>
                        <td class="title" colspan="2">Alta de Empleados</td> 
                    </tr>
                    <?php include('../Funciones/menu.php'); ?>
                    <tr>
                        <td id="photo" class="first" width="500" rowspan="5">
                            <label for="archivo">
                                <div class="image-container">
                                    <img class="preview" id="preview-image" src="../../css/icons/default.png" alt="Empleado">
                                </div>
                            </label>
                            <input id="archivo" type="file" name="archivo" accept="image/*" onchange="preview(event)">
                        </td>
                        <td class="first">Nombre:<br>
                            <input id="nombre" type="text" name="nombre" placeholder="Nombre">
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Apellidos:<br>
                            <input id="apellidos" type="text" name="apellidos" placeholder="Apellidos">
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Correo electrónico:<br>
                            <input id="correo" type="email" name="correo" id="correo" placeholder="usuario@mail.com" onblur="validarCorreo()">
                            <div id="correo-error" class="message"></div>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Contraseña:<br>
                            <input id="pass" type="password" name="pass" placeholder="Contraseña">
                        </td>
                    </tr>
                    <tr >
                        <td class="first">Rol:
                            <select class="select" id="rol" name="rol">
                                <option value="1">Gerente</option>
                                <option value="2">Ejecutivo</option>
                            </select>
                        </td>
                    </tr>
                    <tr>
                        <td class="bottom" colspan="2">
                            <input class="button" type="submit" value="Guardar" onclick="return validarFormulario();">
                            <input class="button" type="reset" value="Regresar" onclick="atras();">
                            <div class="message" id="mensaje-error"></div>
                        </td>
                    </tr>
                </table>
            </div>
        </form>
    </body>
</html>