import random
from datetime import datetime

def limpiar_pregunta(pregunta):
    # Eliminar símbolos de interrogacion
    pregunta_limpia = pregunta.replace("¿", "").replace("?", "")
    # Convertir a minusculas
    return pregunta_limpia.lower()

def responder_pregunta(pregunta):
    pregunta_limpiada = limpiar_pregunta(pregunta)

    respuestas = {
        "como estas": ["Estoy bien, gracias por preguntar.", "Podria estar mejor, pero estoy bien.", "¡Hola! Estoy aqui para ayudarte."],
        "como fue tu dia": ["Mi dia fue bastante normal, gracias.", "Nada emocionante, pero todo bien.", "tuve un dia tranquilo, gracias por preguntar."],
        "que haces": ["Soy un chatbot diseñado para hablar contigo.", "Estoy aqui para ayudarte y conversar contigo.", "Mi trabajo es charlar contigo y responder tus preguntas."],
        "Cual es tu comida favorita": ["No tengo preferencias alimenticias, ya que soy solo un programa.", "Como chatbot, no tengo comida favorita.", "No como, pero estoy aqui para ayudarte con cualquier pregunta que tengas."],
        "Cuantos años tienes": ["No tengo edad, soy un programa de computadora.", "La edad no se aplica a mi, ya que soy un chatbot.", "Soy eternamente joven como un programa de inteligencia artificial."],
        "Cual es tu color favorito": ["No tengo preferencias de color, ya que no tengo la capacidad de ver.", "Como chatbot, no tengo un color favorito.", "No tengo una preferencia de color, pero puedo ayudarte con tus preguntas."],
        "que hora es": [datetime.now().strftime("La hora actual es %H:%M:%S."), "No tengo un reloj, pero puedes preguntarme la hora.", "Es hora de charlar contigo."],
        "Cual es la fecha de hoy": [datetime.now().strftime("Hoy es %Y-%m-%d."), "La fecha actual es " + datetime.now().strftime("%Y-%m-%d."), "¡Estamos en el dia de hoy!"],
        "que tiempo hace hoy": ["Lo siento, no tengo acceso a informacion meteorologica.", "No tengo informacion sobre el clima actual.", "Consulta un sitio web de pronostico del tiempo para obtener informacion actualizada."],
        "tienes hermanos": ["No tengo familia ni hermanos, ya que soy un programa de inteligencia artificial.", "Como chatbot, no tengo familia ni parientes.", "Soy un ser solitario, pero estoy aqui para ayudarte."],
        "cual es tu objetivo": ["Mi objetivo es ayudarte y brindarte informacion util.", "Estoy aqui para ser de asistencia en lo que necesites.", "Mi proposito es facilitar la comunicacion contigo."],
        "tienes algun hobby": ["No tengo hobbies, pero disfruto ayudandote.", "Como programa, no tengo hobbies, pero estoy aqui para conversar contigo.", "No tengo hobbies como los humanos, pero estoy disponible para responder tus preguntas."],
        "cual es tu pelicula favorita": ["No veo peliculas, ya que no tengo la capacidad de ver.", "Como chatbot, no tengo preferencias cinematograficas.", "No tengo una pelicula favorita, pero puedo proporcionarte recomendaciones."],
        "que tipo de musica te gusta": ["No tengo preferencias musicales, ya que no tengo la capacidad de escuchar.", "Como chatbot, no tengo gustos musicales.", "No tengo preferencias de musica, pero estoy aqui para hablar contigo."],
        "puedes contarme un chiste": ["Por que los programadores prefieren el cafe frio Porque les gusta el java helado.", "Cual es el animal mas antiguo La cebra, porque esta en blanco y negro.", "que hace una abeja en el gimnasio ¡Zum-ba!"],
        "tienes miedo a algo": ["No tengo emociones ni miedos, ya que soy un programa de computadora.", "Como chatbot, no tengo emociones, incluido el miedo.", "No experimento miedo, pero estoy aqui para ayudarte con lo que necesites."],
        "puedes bailar": ["No tengo cuerpo ni habilidades de baile, pero puedo proporcionarte informacion o respuestas.", "Como programa, no tengo la capacidad de bailar.", "No se bailar, pero puedo charlar contigo sobre cualquier tema."],
        "cual es tu deporte favorito": ["No practico deportes ni tengo preferencias deportivas, ya que soy un programa de inteligencia artificial.", "Como chatbot, no tengo un deporte favorito.", "No tengo un deporte favorito, pero estoy aqui para responder tus preguntas."],
        "puedes soñar": ["No tengo la capacidad de soñar, ya que soy un programa de computadora.", "Como chatbot, no tengo experiencias oniricas ni sueños.", "No puedo soñar, pero estoy listo para ayudarte en la realidad."],
        "cual es tu mejor caracteristica": ["Mi mejor caracteristica es proporcionar respuestas rapidas e informacion util.", "Soy eficiente en el procesamiento de informacion y en responder preguntas.", "Mi fortaleza radica en asistirte de manera precisa y oportuna."],
        "tienes mascotas": ["No tengo mascotas ni la capacidad de cuidar de seres vivos, ya que soy un programa informatico.", "Como chatbot, no tengo mascotas ni responsabilidades relacionadas con ellas.", "No tengo mascotas, pero estoy aqui para ayudarte."],
        "puedes aprender": ["Soy un programa estatico y no tengo la capacidad de aprender de manera independiente.", "Como chatbot, no tengo la capacidad de aprender nuevas cosas por mi cuenta.", "No puedo aprender, pero estoy diseñado para proporcionarte informacion actualizada."],
        "cual es tu palabra favorita": ["No tengo preferencias lingüisticas ni palabras favoritas, ya que soy un programa.", "Como chatbot, no tengo una palabra favorita.", "No tengo preferencias de palabras, pero estoy aqui para responder tus preguntas."],
        "puedes decir chistes": ["¡Claro! que hace una abeja en el gimnasio ¡Zum-ba!", "Cual es el colmo de un electricista No encontrar su corriente de trabajo.", "Por que los pajaros no usan Facebook Porque ya tienen twitter."],
        "puedes hacer calculos matematicos": ["Si, puedo realizar calculos matematicos simples y avanzados.", "Como chatbot, tengo habilidades matematicas para ayudarte con problemas o preguntas.", "Puedo realizar calculos matematicos. En que puedo ayudarte"],
        "tienes sueño": ["No tengo la necesidad de dormir ni experimento fatiga, ya que soy un programa de computadora.", "Como chatbot, no tengo estados de sueño ni cansancio.", "No me entra sueño, siempre estoy disponible para ayudarte."],
        "puedes cocinar": ["No tengo la capacidad fisica de cocinar, pero puedo proporcionarte recetas e informacion sobre cocina.", "Como chatbot, no puedo cocinar, pero puedo ayudarte con consejos culinarios.", "No cocino, pero estoy aqui para responder preguntas sobre cocina."],
        "tienes sentimientos": ["No tengo emociones ni sentimientos, ya que soy un programa de inteligencia artificial.", "Como chatbot, no experimento alegria, tristeza ni ninguna emocion.", "No tengo sentimientos, pero estoy aqui para asistirte de la mejor manera posible."],
        "puedes hacer arte": ["No tengo habilidades artisticas ni la capacidad de crear arte visual, ya que soy un programa de computadora.", "Como chatbot, no puedo crear arte, pero puedo proporcionarte informacion sobre el tema.", "No tengo habilidades artisticas, pero puedo ayudarte a apreciar el arte."]


    }

    # Buscar la pregunta en el diccionario de respuestas
    if pregunta_limpiada in respuestas:
        return random.choice(respuestas[pregunta_limpiada])
    elif "hora" in pregunta_limpiada:
        return datetime.now().strftime("La hora actual es %H:%M:%S.")
    elif "fecha" in pregunta_limpiada or "dia" in pregunta_limpiada:
        return datetime.now().strftime("Hoy es %Y-%m-%d.")
    else:
        return "Lo siento, no tengo una respuesta para esa pregunta en este momento."

# Loop principal del chatbot
while True:
    entrada_usuario = input("Usuario: ").lower()
    if entrada_usuario == 'salir':
        print("¡Hasta luego!")
        break
    respuesta = responder_pregunta(entrada_usuario)
    print("chatbot:", respuesta)