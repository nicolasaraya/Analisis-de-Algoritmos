Este código contiene tres variaciones del algoritmo MergeSort. La finalidad es probar los tiempos de ejecucion
de cada uno, por lo que en la funcion main se preestableció para realizar 10 test sobre cada algoritmo de merge, con
un arreglo de 10millones de elementos hasta 100millones, con un incremento de 10millones entre cada uno

Cada vez que se haga un test, se imprimira por pantalla el nombre del algoritmo en cuestion y la duracion
que tardo en ejecutarse con esa cantidad de elementos. 

Se recomienda ejecutar para generar un archivo de texto de salida
	g++ merges.cpp -o merges
	./merges > ArchivoSalida