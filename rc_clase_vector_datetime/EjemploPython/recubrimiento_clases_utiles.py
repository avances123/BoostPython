
import numpy as np
import pandas as pd
import datetime
import rc_clase_vector_datetime as rc
import __future__

# # Definimos 
dia_de_hoy=datetime.datetime.today()



print ("Clase 2")
mi_serie_historica=rc.SerieHistorica(np.array([1,2,3,4,6]),dia_de_hoy)
for elemento in mi_serie_historica:
    elemento=elemento*2
    print ("\nValor {}".format(elemento))
    
    
