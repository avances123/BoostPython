
import numpy as np
import pandas as pd
import datetime
import rc_clase_vector_datetime as rc
import __future__

# # Definimos 
dia_de_hoy=datetime.datetime.today()

mi_serie_historica=rc.SerieHistorica(np.array([1,2,3,4,6]),dia_de_hoy)

print ("Fecha primera del historico:.{}".format(mi_serie_historica.UltimaFechaValida()))
for elemento in mi_serie_historica:
    elemento=elemento*2
    print (" {},".format(elemento))
    
    
