from selenium import webdriver
import time
import pandas as pd

def obtener_monedas():
    path = "C:/Users/luism/OneDrive/Documentos/GitHub/CodingIsMyAmbition/Languages/NOC++/chromedriver"
    url = 'https://coinmarketcap.com' 
    monedas = []

    options = webdriver.ChromeOptions()
    driver = webdriver.Chrome(executable_path=path,options=options)
    driver.set_window_size(1120, 1000)
    driver.get(url)
    time.sleep(5)

    for i in range(10): 

        time.sleep(1)

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
                time.sleep(1)

        monedas.append({"Posicion de moneda" : posicion,"Nombre de moneda" : nombre,"Siglas" : siglas,"Precio" : precio})

    return pd.DataFrame(monedas)

    df = obtener_monedas()
    df.to_csv('monedas.csv',index = False)