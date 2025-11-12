<?php
    $nombre = $_POST['nombre'];
    $correo = $_POST['correo'];
    $sexo = $_POST['sexo'];
    $comentario = $_POST['comentario'];
    $carrera = $_POST['carrera'];
    $password = $_POST['password'];
    $promedio = $_POST['promedio'];
    $fechaNacimiento = $_POST['fecha'];
    $sexo_txt = ($sexo == 1) ? 'Femenino' : 'Masculino';
    $carrera_txt = ($carrera == 1) ? 'Ing. Informática' : 'Ing. Computación';
    if(isset($_POST['boletin']))
        $boletin = 'Sí';
    else
        $boletin = 'No';

    echo "Nombre: $nombre<br>";
    echo "Correo: $correo<br>";
    echo "Sexo: $sexo_txt<br>";
    echo "Boletín: $boletin<br>";
    echo "Comentario: $comentario<br>";
    echo "Carrera: $carrera_txt<br>";
    echo "Contraseña: $password<br>";
    echo "Promedio: $promedio<br>";
    echo "Fecha de Nacimiento: $fechaNacimiento<br>";
?>