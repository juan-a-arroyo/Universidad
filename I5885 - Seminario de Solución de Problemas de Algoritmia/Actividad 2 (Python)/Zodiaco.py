import os
os.system("CLS")
print("SIGNO ZODIACAL\n")
dia=int(input("Introduzca su día de nacimiento: "))
mes=int(input("Introduzca su mes de nacimiento: "))
if (mes==12 and dia>=22 or mes==1 and dia<=19):
    print("Caprcornio")
if (mes==1 and dia>=20 or mes==2 and dia<=18):
    print("Acuario")
if (mes==2 and dia>=19 or mes==3 and dia<=20):
    print("Picis")
if (mes==3 and dia>=21 or mes==4 and dia<=19):
    print("Aries")
if (mes==4 and dia>=20 or mes==5 and dia<=21):
    print("Tauro")
if (mes==5 and dia>=21 or mes==6 and dia<=20):
    print("Géminis")
if (mes==6 and dia>=21 or mes==7 and dia<=22):
    print("Cáncer")
if (mes==7 and dia>=23 or mes==8 and dia<=22):
    print("Leo")
if (mes==8 and dia>=23 or mes==9 and dia<=22):
    print("Virgo")
if (mes==9 and dia>=23 or mes==10 and dia<=22):
    print("Libra")
if (mes==10 and dia>=23 or mes==11 and dia<=21):
    print("Escorpio")
if (mes==11 and dia>=22 or mes==12 and dia<=21):
    print("Sagitario")