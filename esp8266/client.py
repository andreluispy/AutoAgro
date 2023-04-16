import random
import time
import paho.mqtt.client as mqtt
import tkinter
import ssl
import tkinter as tk

ssl_context = ssl.SSLContext()
broker = 'ea19786227fb48539c94010249c4ecfb.s2.eu.hivemq.cloud'
port = 8883
topic = "autoagro/car"
# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 1000)}'
# username = 'emqx'
# password = 'public'
def on_connect(client, userdata, flags, rc, properties=None):
    if rc == 0:
        print("Connected to MQTT Broker!")
    else:
        print("Failed to connect, return code %d\n", rc)

client = mqtt.Client(client_id)
client.username_pw_set("guidanidias", "V3cM@g5T2RwWNxw")
client.on_connect = on_connect
client.connect(broker, port)
client.tls_set_context(ssl_context)
client.loop_start()


# cria a janela
janela = tk.Tk()
janela.geometry("300x300") # define o tamanho da janela
def publish(client, message):
    print(f"Mensagem publicada {message}")
    result = client.publish(topic, message)
    status = result[0]
    if status == 0:
        print(f"Send `{message}` to topic `{topic}`")
    else:
        print(f"Failed to send message to topic {topic}")

# cria os botões
# cria os botões
botao_up_left = tk.Button(janela, text="Up Left", command=lambda: publish(client, "ul"), width=10, height=5, bg="orange", fg="white")
botao_up_left.grid(row=0, column=0)

botao_up = tk.Button(janela, text="Up", command=lambda: publish(client, "u"), width=10, height=5, bg="green", fg="white")
botao_up.grid(row=0, column=1)

botao_up_right = tk.Button(janela, text="Up Right", command=lambda: publish(client, "ur"), width=10, height=5, bg="orange", fg="white")
botao_up_right.grid(row=0, column=2)

botao_left = tk.Button(janela, text="Left", command=lambda: publish(client, "l"), width=10, height=5, bg="blue", fg="white")
botao_left.grid(row=1, column=0)

botao_stop = tk.Button(janela, text="Stop", command=lambda: publish(client, "s"), width=10, height=5, bg="red", fg="white")
botao_stop.grid(row=1, column=1)

botao_right = tk.Button(janela, text="Right", command=lambda: publish(client, "r"), width=10, height=5, bg="blue", fg="white")
botao_right.grid(row=1, column=2)

botao_down_left = tk.Button(janela, text="Down Left", command=lambda: publish(client, "dl"), width=10, height=5, bg="orange", fg="white")
botao_down_left.grid(row=2, column=0)

botao_down = tk.Button(janela, text="Down", command=lambda: publish(client, "d"), width=10, height=5, bg="green", fg="white")
botao_down.grid(row=2, column=1)

botao_down_right = tk.Button(janela, text="Down Right", command=lambda: publish(client, "dr"), width=10, height=5, bg="orange", fg="white")
botao_down_right.grid(row=2, column=2)

# inicia o loop da janela
janela.mainloop()
