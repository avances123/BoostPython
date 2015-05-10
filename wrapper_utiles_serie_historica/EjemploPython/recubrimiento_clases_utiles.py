
import numpy as np
import pandas as pd
import datetime
import wrapper_utiles_serie_historica as rc
import __future__

# # Definimos 
dia_de_hoy=datetime.datetime.today()

mi_serie_historica=rc.SerieHistorica(np.array([1,2,3,4,6]),dia_de_hoy,"Serie sin conversores")


print ("Fecha primera del historico:.{}".format(mi_serie_historica.UltimaFechaValida()))
for elemento in mi_serie_historica:
    elemento=elemento*2
    print (" {},".format(elemento))
    

serie_historica_por_conversores=rc.SerieHistoricaPorConversores(np.array([8,6,9]),dia_de_hoy,"Serie con conversores")   
print ("Fecha primera del historico:.{}".format(serie_historica_por_conversores.UltimaFechaValida()))
for elemento in serie_historica_por_conversores:
    print (" {},".format(elemento))
    
contenedor_series_historicas=rc.VectorSeriesHistoricas()
contenedor_series_historicas.append(serie_historica_por_conversores)
serie_historica_por_conversores_v2=rc.SerieHistoricaPorConversores(np.array([1,1,2]),dia_de_hoy,"Serie con conversores 2") 
serie_historica_por_conversores_v2.Descripcion="He cambiado la descripcion"
contenedor_series_historicas.append(serie_historica_por_conversores_v2)

for series in contenedor_series_historicas:
    print ("La descripcion de la serie es: {}".format(series.Descripcion))
    for elemento in series:
        print (" {},".format(elemento))
    