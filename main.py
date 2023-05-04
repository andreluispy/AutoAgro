import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
import tkinter as tk

cred = credentials.Certificate('credentials.json')
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://mqttfb-14368-default-rtdb.firebaseio.com/'
})

ref = db.reference('/')

data = ref.get()
print(data)
def setValue(v):
    ref.update({
        'direction': v
    })

janela = tk.Tk()
janela.geometry("340x350")

ahead = tk.Button(text = "frente", width=15, height = 7, command =lambda: setValue(1), bg = "#FFFF00")
ahead.grid(row = 0, column=1)

left = tk.Button(text = "Esquerda", width=15, height = 7, command =lambda: setValue(3), bg="#FFFF00")
left.grid(row = 2, column=0)

right = tk.Button(text = "Direita", width=15, height = 7, command =lambda: setValue(4), bg="#FFFF00")
right.grid(row = 2, column=2)

stop = tk.Button(text = "Parar", width=15, height = 7, command =lambda: setValue(0),  bg="#FF0000")
stop.grid(row = 2, column=1)

down = tk.Button(text = "Baixo", width=15, height = 7, command =lambda: setValue(2), bg = "#FFFF00")
down.grid(row = 3, column=1)

janela.mainloop()