
import numpy as np
import pandas as pd
import datetime
import wrapper_utiles_serie_historica as rc
import __future__

def Mostrar(serie_historica):
    print("\nFecha: {};\nDescripcion: {};\nElementos: [".format(serie_historica.UltimaFechaValida(),serie_historica.Descripcion))
    for elemento in serie_historica: 
        print (" {},".format(elemento))
    else:   
        print ("]")

# # Definimos 
dia_de_hoy=datetime.datetime.today()
serie_historica_01=rc.SerieHistoricaPorConversores(np.array([1,2,3]),dia_de_hoy,"Serie 1") 
serie_historica_02=rc.SerieHistoricaPorConversores(np.array([10,20,30,40]),dia_de_hoy,"Serie 2") 

# Demostramos el acceso a los elementos
Mostrar(serie_historica_01)

# Slice
print ("\nSlice de la Serie Historica: {}".format(np.array_str(serie_historica_02[::-1])))

# Enumerate
print ("\nProbamos enumerate, numero de elementos de la serie historica: {}".format(serie_historica_02.__len__()))
for index,valor in enumerate(serie_historica_02):
    print ("[Index: {},Valor: {}]".format(index,valor))

# Demostramos que podemos cambiar la descripccion
serie_historica_01.Descripcion="Cambio de descripcion de la serie 1"
Mostrar(serie_historica_01)
    
# Contenedor de series historicas    
contenedor_series_historicas=rc.VectorSeriesHistoricas()
contenedor_series_historicas.append(serie_historica_01)
contenedor_series_historicas.append(serie_historica_02)

# Acceso por unitario al contenedor
Mostrar(contenedor_series_historicas[1])



    