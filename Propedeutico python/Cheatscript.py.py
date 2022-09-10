"""
# WORKING WTIH DATETIME

import datetime


x = datetime.datetime.now()

print(x) # Fecha
print(x.year) # Año
print(x.strftime("%A")) # Día de la semana
print(x.strftime("%B")) # Mes
print(x.strftime("%d")) # Día del mes
print(x.strftime("%H:%M:%S %p")) # Hora, minuto, segundo y am/pm



# NUMPY
import numpy as np

	# Inspeccionar arreglos

a = np.arange(15).reshape(3 ,5) # Arreglo con números de 0-14
b = np.zeros((3,5)) # Arreglo con 0´s
c = np.ones( (2,3,4), dtype=np.int16) # Crea dos arreglos de (3,4) con 1's
d = np.ones((3,5)) # Arreglo con 1's

a.shape # Dimensión

len(b) # número de filas

c.ndim # Dimesnión de los arreglos

a.size # Número total de elementos

b.dtype # Datatype de los elementos	

c.dtype.name # Nombre del typo de datos

c.astype(float) # Camibia el tipo de arreglo

	# Operaciones matemáticas básicas

np.add(a,b) # Suma arreglos entrada por entrada

np.subtract(a,b) # Análogo para la resta

np.divide(a,d) # Divisón

np.multiply(a,d)

np.array_equal(a,b) # Revisa si dos arreglos son iguales

	# Funciones sobre arreglos

a.sum() # Suma los elementos del arreglo

a.min() # Devuleve el menor valor

a.mean() # Promedio aritmético

a.max(axis = 0) # Devuelve la fila con el valor máximo
a.max(axis = 1) # Devuelve la columna con el valor máximo

np.std(a) # Calcula la desviación estándar de sus elementos

	# Indexación

a[1,2] # Elemento en el índice especificado

a[0:2] # Selecciona las filas en el rango especificado

a[:1] # Selecciona las primeras filas

a[-1:] # Selecciona las filas empezando desde la última

a[a<2] # Elementos menores a cierto número

	# Manipulación de arreglos

np.transpose(a) # Transponer el arreglo

a.ravel() # Convierte el arreglo en una sola fila

a.reshape(5,-2) # Cambia la dimensión del arreglo sin alterar datos.
				# para ello, debe mantenerse la cantidad de elementos

np.append(a,b) # Une los elementos de ambos arreglos en una sola lista

np.concatenate((a,d), axis=0) # Concatena arreglos por fila
np.concatenate((a,d), axis=1) # Concatena arreglos por columna

np.hsplit(a,5) # Parte al arreglo horizontalmente en 5 arreglos
np.vsplit(a,3) # Parte al arreglo verticalmente en 3 arreglos


# PANDAS
import numpy as np
import pandas as pd

df = pd.DataFrame({'num_legs': [2, 4, np.nan, 0],
                   'num_wings': [2, 0, 0, 0],
                   'num_specimen_seen': [10, np.nan, 1, 8]},
                   index=['falcon', 'dog', 'spider', 'fish'])
df # Tabla de datos

df1 = pd.date_range('20130101', periods=6) # Lista de datos
df2 = pd.DataFrame(np.random.randn(6, 4), index=df1, columns=list('ABCD'))
df2 # Tabla de datos apartir de la lista

	# Visualizar datos

df2.head(2) # Datos de las primeras filas

df2.tail(2) # Datos de las últimas filas

df2.index # Columna de índices. Equivalente a df1

df2.dtypes # Tipos de datos por columna

df2.describe() # Datos estadísticos: Media, mínimo, máximo, etc.

	# Subconjuntos e Indexación

df2.T # Datos transpuestos; filas -> columnas.

df2.sort_index(axis=1, ascending=False) # Refleja datos en el eje horizontal
df2.sort_index(axis=0, ascending=False) # Refleja datos en el eje vertical

df2.sort_values(by='A') # Acomoda los datos, de menor a mayor en la columna A,
						  # y en las demás coliumnas de acuerdo a la columna A.

df2['B'] # Selecciona solo la columna B

df2[0:3] # Selecciona las filas con índices 0,1,2.

df2['20130102':'20130104'] # Selecciona las filas de acuerdo al nombre del índice

df2.loc[:, ['A', 'C']] # Selecciona las columnas indicadas por su nombre

df2.iloc[3] # Selecciona de cada columna los datos con el índice indicado

df2[df2 > -1] # Deja solo aquellos datos que cumplen la condición

df3 = df2.copy() # Copia el conjunto de datos
df3['E'] = ['one', 'one', 'two', 'three', 'four', 'three']
			# Añade una columna con el nombre y datos indicados
df3[df3['E'].isin(['two', 'four'])]
			# Filtra los datos coincidentes en la columna E, y devuelve sus filas

	# Datos faltantes (Se indican con NaN)

df.dropna(how='any') # Quita las filas con datos faltantes
df.dropna(how='any', axis=1) # Quita las columnas con datos faltantes

df.fillna(value=5) # Llena los datos faltantes con el valor 5

pd.isna(df) # Pone True en los lugares donde faltan datos

	# Manipulación de archivos

#df.to_csv('foo.csv') # Esrcibe los datos en un archivos llamado foo.csv
					  # Los pone en un excel y lo guarda como archivo de valores

pd.read_csv('foo.csv') # Lee los datos como están en el archivo

#df.to_excel('foo.xlsx', sheet_name='Sheet1')
					# Pone los datos en excel y lo guarda como hoja de cálculo

pd.read_excel('foo.xlsx', 'Sheet1', index_col=None, na_values=['NA'])
pd.read_excel('foo.xlsx')
					# Lee los datos como están en el archivo


# PLOTEO
from matplotlib import pyplot as plt
import numpy as np
import pandas as pd

ts = pd.Series(np.random.randn(1000),index=pd.date_range('1/1/2000', periods=1000))
			# Genera 1000 datos aleatorios y los indexa de acuerdo a la fecha
ts.head() # Imprime los primerso datos

ts = ts.cumsum() # Suma acumulada de los datos a lo largo del eje
ts.plot()  # Imprime la gráfica
plt.show() # Nos muestra la gráfica

df4 = pd.DataFrame(np.random.randn(1000, 4), index=ts.index,columns=['A', 'B', 'C', 'D'])
		# 4 columnas con 1000 datos aleatorios cada una
df4 = df4.cumsum() # Suma aumulada a lo largo del eje vertical
df4.head() # Primeras filas del conjunto de datos

df4.plot()
plt.show() # Grafica los datos de cada columna






