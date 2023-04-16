import random
import paho.mqtt.client as mqtt
import ssl

# CONFIGS
ssl_context = ssl.SSLContext()
broker = 'ea19786227fb48539c94010249c4ecfb.s2.eu.hivemq.cloud'
port = 8883
topic = "autoagro/car"
# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 1000)}'


def on_connect(client, userdata, flags, rc, properties=None):
    if rc == 0:
        print("Connected to MQTT Broker!")
    else:
        print("Failed to connect, return code %d\n", rc)


def on_publish(client, userdata, mid, properties=None):
    print(f"Mid: {str(mid)}")


# Exibe em qual tópico foi realizada a subscrição
def on_subscribe(client, userdata, mid, granted_qos, properties=None):
    print("Subscribed: " + str(mid) + " " + str(granted_qos))


def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload))


client = mqtt.Client(client_id)
client.username_pw_set("guidanidias", "V3cM@g5T2RwWNxw")
client.on_connect = on_connect
client.connect(broker, port)
client.tls_set_context(ssl_context)
client.loop_forever()


# Função para publicar as mensagens
# Pode ser chamada de outro lugar
def publish(client, message):
    result = client.publish(topic, message)
    status = result[0]
    if status == 0:
        print(f"Send `{message}` to topic `{topic}`")
    else:
        print(f"Failed to send message to topic {topic}")
