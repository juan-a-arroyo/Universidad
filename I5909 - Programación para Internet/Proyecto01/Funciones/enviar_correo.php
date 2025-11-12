<?php
    function remove_accents($str) {
        $search = explode(",","á,é,í,ó,ú,Á,É,Í,Ó,Ú,ñ,Ñ");
        $replace = explode(",","a,e,i,o,u,A,E,I,O,U,n,N");
        return str_replace($search, $replace, $str);
    }
    use PHPMailer\PHPMailer\PHPMailer;
    use PHPMailer\PHPMailer\Exception;
    require '../PHPMailer/PHPMailer.php';
    require '../PHPMailer/Exception.php';
    require '../PHPMailer/SMTP.php';
    $nombre = remove_accents($_REQUEST['nombre']);
    $correo = $_REQUEST['correo'];
    $comentarios = $_REQUEST['comentarios'];
    $mail = new PHPMailer(true);
    $mail->isSMTP();
    $mail->Host = 'smtp.gmail.com';
    $mail->SMTPAuth = true;
    $mail->Username = 'circuitcraft.hardware.hub@gmail.com';
    $mail->Password = 'fvup mfio sokh rrxy';
    $mail->SMTPSecure = 'tls';
    $mail->Port = 587;
    $mail->setFrom('circuitcraft.hardware.hub@gmail.com', $correo);
    $mail->addAddress('circuitcraft.hardware.hub@gmail.com');
    $mail->Subject = 'Contacto: '.$nombre;
    $mail->Body = $comentarios;
    $mail->send();
    header("Location: ../contacto.php");
?>
