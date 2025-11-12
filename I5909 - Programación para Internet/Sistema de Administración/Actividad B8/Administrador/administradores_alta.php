<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Alta de Administradores</title>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
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
    </script>
    <body>
        <form name="form" action="administradores_salva.php" method="POST" enctype="multipart/form-data" novalidate>
            <div>
                <table>
                    <tr>
                        <td class="title" colspan="2">ALTA DE ADMINISTRADORES</td> 
                    </tr>
                    <tr>
                        <td id="photo" class="first" width="500" rowspan="5">
                            <label for="archivo">
                                <div class="image-container">
                                    <img class="preview" id="preview-image" src="css/icons/default.png" alt="Administrador">
                                </div>
                            </label>
                            <input id="archivo" type="file" name="archivo" accept="image/*" onchange="preview(event)" required>
                        </td>
                        <td class="first">Nombre:<br>
                            <input type="text" name="nombre" placeholder="Nombre" required>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Apellidos:<br>
                            <input type="text" name="apellidos" placeholder="Apellidos" required>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Correo electrónico:<br>
                            <input type="email" name="correo" id="correo" placeholder="usuario@mail.com" required onblur="validarCorreo()">
                            <div id="correo-error" class="message"></div>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Contraseña:<br>
                            <input type="password" name="pass" placeholder="Contraseña" required>
                        </td>
                    </tr>
                    <tr >
                        <td class="first">Rol:
                            <select class="select" name="rol">
                                <option value="1">Gerente</option>
                                <option value="2">Ejecutivo</option>
                            </select>
                        </td>
                    </tr>
                    <tr>
                        <td class="bottom" colspan="2">
                            <input class="button" type="submit" value="Guardar" onclick="return validarFormulario();">
                            <input class="button" type="reset" value="Regresar al Listado" onclick="window.history.back(); return false;">
                            <div class="message" id="mensaje-error"></div>
                        </td>
                    </tr>
                </table>
            </div>
        </form>
    </body>
</html>