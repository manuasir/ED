#!/bin/csh
@ inicio = 10000
@ fin = 128500
@ incremento = 100
set ejecutable = burbuja
set salida = burbuja_modificado.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end
