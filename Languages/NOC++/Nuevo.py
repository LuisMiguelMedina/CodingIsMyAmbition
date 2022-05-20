from importlib.resources import path
from lib2to3.pgen2 import driver
from webbrowser import Chrome
from selenium import webdriver
import time
import pandas as pd

def obtener_monedas():
    path = "C:/Users/luism/OneDrive/Documentos/GitHub/CodingIsMyAmbition/Languages/NOC++"
    url = "httpa://coinmarket.com"
    tiempo_de_espera = 1
    numero_de_monedas = 10
    monedas = []
    options = webdriver.ChromeOptions()
    driver = webdriver.Chrome(executable_path=path,options=options)
    driver.set_window_size(1120, 1000)
    driver.get(url)

    time.sleep(tiempo_de_espera)


    for i in range(numero_de_monedas): 

        time.sleep(tiempo_de_espera)

        recolectado = False

        while not recolectado:
            try:
                posicion = driver.find_element_by_xpath('//*[@id="__next"]/div/div[1]/div[2]/div/div/div[5]/table/tbody/tr['+str(i+1)+']/td[2]/p').text
                nombre = driver.find_element_by_xpath('//*[@id="__next"]/div/div[1]/div[2]/div/div/div[5]/table/tbody/tr['+str(i+1)+']/td[3]/div/a/div/div/p').text
                siglas = driver.find_element_by_xpath('//*[@id="__next"]/div/div[1]/div[2]/div/div/div[5]/table/tbody/tr['+str(i+1)+']/td[3]/div/a/div/div/div/p').text
                precio = driver.find_element_by_xpath('//*[@id="__next"]/div/div[1]/div[2]/div/div/div[5]/table/tbody/tr['+str(i+1)+']/td[4]/div/a/span').text

                recolectado = True
                print("Recolecto correctamente: "+str(i+1))
            except:
                print("Fallo la coleccion")
                time.sleep(tiempo_de_espera)

        monedas.append({"Posicion de moneda" : posicion,"Nombre de moneda" : nombre,"Siglas" : siglas,"Precio" : precio})

    return pd.DataFrame(monedas)

    df = obtener_monedas()
    df.to_csv('crypto.csv',index = False)