#LO QUE SE INTRODUCE EN INPUT SE CONSIDERA STRING

print('Evaluación de notas de alumnos')              

def evaluacion(nota):
	valoracion='aprobado'
	if nota<=5:
		valoracion='reprobado'
	return valoracion

nota_alumno=input('Introduca la nota del alumno: ')

print(evaluacion(int(nota_alumno)))

input()