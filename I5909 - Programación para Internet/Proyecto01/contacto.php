<?php
    session_start();
    $id_usuario = $_SESSION['id_usuario'] ?? null;
    $nombre_usuario = $_SESSION['nombre_usuario'] ?? null;
    $correo_usuario = $_SESSION['correo_usuario'] ?? null;
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Contacto</title>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <script>
        document.addEventListener('DOMContentLoaded', function() {
            document.addEventListener('keydown', function(event) {
                if (event.key == 'Enter' && event.target.tagName !== 'TEXTAREA') {
                    event.preventDefault();
                    return false;
                }
            });
        });
        function validarFormulario() {
            var nombre = $('#nombre').val();
            var correo = $('#correo').val();
            var comentarios = $('#comentarios').val();
            if (nombre == "" ||  correo == "" || comentarios == "") {
                $('#mensaje-error').text('Campos Vacíos').show();
                setTimeout(function() {
                    $('#mensaje-error').hide();
                }, 5000);
                return false;
            }
        }
    </script>
    <body>
        <form name="form" action="Funciones/enviar_correo.php" method="POST" enctype="multipart/form-data">
            <div>
                <table>
                    <tr>
                        <td class="title" colspan="2">Contáctanos</td> 
                    </tr>
                    <?php include('Funciones/menu.php'); ?>
                    <tr>
                        <td class="first">Nombre y Apellidos:<br>
                            <?php
                                if($id_usuario  != "")
                                    echo "<input id=\"nombre\" type=\"text\" name=\"nombre\" value=\"$nombre_usuario\" placeholder=\"Nombre\">";
                                else
                                    echo "<input id=\"nombre\" type=\"text\" name=\"nombre\" placeholder=\"Nombre\">";
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Correo electrónico:<br>
                            <?php
                                if($id_usuario  != "")
                                    echo "<input id=\"correo\" type=\"email\" name=\"correo\" id=\"correo\" value=\"$correo_usuario\" placeholder=\"usuario@mail.com\">";
                                else
                                echo "<input id=\"correo\" type=\"email\" name=\"correo\" id=\"correo\" placeholder=\"usuario@mail.com\">";
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Comentarios:<br>
                            <textarea id="comentarios" name="comentarios" placeholder="Comentarios" rows="4"></textarea>
                        </td>
                    </tr>
                    <tr>
                        <td class="bottom" colspan="2">
                            <input class="button" type="submit" value="Enviar" onclick="return validarFormulario();">
                            <div class="message" id="mensaje-error"></div>
                        </td>
                    </tr>
                </table>
            </div>
        </form>
    </body>
</html>