<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "../Administrador/Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_administradores = "../Administrador/administradores_lista.php";
    $ruta_productos = "productos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Alta de Productos</title>
    </head>
    <link href="../css/style.css" type="text/css" rel="stylesheet">
    <script src="../js/jquery-3.3.1.min.js"></script>
    <script>
        var codigoValido = true;
        function validarCodigo() {
            var codigoInput = $('#codigo');
            var codigo = codigoInput.val();
            $.ajax({
                url: 'Funciones/validar_codigo.php',
                method: 'POST',
                data: { codigo: codigo },
                success: function(res) {
                    if (res == 1){
                        $('#codigo-error').text('El código ya existe').show();
                        setTimeout(function() {
                            $('#codigo-error').hide();
                        }, 5000);
                        codigoValido = false;
                        return false;
                    }
                    else{
                        $('#codigo-error').text('');
                        codigoValido = true;
                    }
                }
            });
        }
        function validarFormulario() {
            var nombre = $('#nombre').val();
            var codigo = $('#codigo').val();
            var descripcion = $('#descripcion').val();
            var costo = $('#costo').val();
            var stock = $('#stock').val();
            var archivoInput = $('#archivo');
            var archivo = archivoInput[0].files[0];
            if (nombre == "" || codigo == "" || descripcion == "" || costo == "" || stock == "" || codigoValido == false || !archivo) {
                $('#mensaje-error').text('Faltan Campos por Llenar').show();
                if(nombre != "" && codigo != "" && descripcion != "" && costo != "" && stock != "" && !archivo)
                    $('#mensaje-error').text('Falta Subir una Fotografía').show();
                if(nombre != "" && codigo != "" && descripcion != "" && costo != "" && stock != "" && codigoValido == false)
                    $('#mensaje-error').text('Código inválido').show();
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
            window.location.href = 'productos_lista.php';
        }
    </script>
    <body>
        <form name="form" action="productos_salva.php" method="POST" enctype="multipart/form-data">
            <div>
                <table>
                    <tr>
                        <td class="title" colspan="2">ALTA DE PRODUCTOS</td> 
                    </tr>
                    <?php include('../Funciones/menu.php'); ?>
                    <tr>
                        <td id="photo" class="first" width="500" rowspan="5">
                            <label for="archivo">
                                <div class="image-container">
                                    <img class="preview" id="preview-image" src="../css/icons/default.png" alt="Producto">
                                </div>
                            </label>
                            <input id="archivo" type="file" name="archivo" accept="image/*" onchange="preview(event)">
                        </td>
                        <td class="first">Nombre:<br>
                            <input type="text" name="nombre" placeholder="Nombre">
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Código:<br>
                            <input type="text" name="codigo" id="codigo" placeholder="Código" onblur="validarCodigo()">
                            <div id="codigo-error" class="message"></div>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Descripción:<br>
                            <input type="text" name="descripcion" placeholder="Descripción">
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Costo:<br>
                            <input type="text" name="costo" placeholder="Costo">
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Stock:<br>
                            <input type="text" name="stock" placeholder="Stock">
                        </td>
                    </tr>
                    <tr>
                        <td class="bottom" colspan="2">
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