#!/bin/csh
@ inicio = 100
@ fin = 1000000
@ incremento = 100
set ejecutable = burbuja
set salida = mejorcaso.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000 1` >> $salida
  @ i += $incremento
end
