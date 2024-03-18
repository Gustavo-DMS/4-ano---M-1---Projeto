import random
import serial

sorteados = []
flagCerto = True
entrada = ""
while flagCerto:
    sorteados.append(random.randint(0, 3))

    for i in sorteados:
        if(i == 0):
            print("led_amarelo")
        elif(i == 1):
            print("led_verde")
        elif(i == 2):
            print("led_vermelho")
        elif(i == 3):
            print("led_azul")

    for i in sorteados:
        entrada = ""
        # while len(entrada) < 0:
        entrada = int(input("Digite a sequência: "))
        if(entrada == i):
            pass
        else:
            print("Errou")
            flagCerto = False
            break
    print("Parabéns")




