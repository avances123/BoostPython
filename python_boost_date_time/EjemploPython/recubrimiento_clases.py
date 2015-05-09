
import numpy as np
import pandas as pd
import datetime
import rc_datetime as rc
import __future__

# Definimos 
dia_de_manana=rc.tomorrow()
dia_de_hoy=datetime.datetime.today()
dia_pasado=rc.day_before(dia_de_hoy)

print ("El dia de hoy es: {}".format(dia_de_hoy))
print ("El dia pasado es: {}".format(dia_pasado))
print ("El dia futuro es: {}".format(dia_de_manana))   