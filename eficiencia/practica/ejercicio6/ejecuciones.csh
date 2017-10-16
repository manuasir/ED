#!/bin/csh
@ inicio = 100
@ fin = 49500
@ incremento = 100
set ejecutable = burbuja
set salida = burbuja_sin_optimizar.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end
