# Taller2EDatos
--------------------------------------------
Taller de estructura 2: Conect 4
Nombre: Bruno Toro Elgueta - 20864066-6
--------------------------------------------
Linea de compilación:
g++ -o main main.cpp
--------------------------------------------
# Diseño del juego
--------------------------------------------
El conecta 4 está representado en una matriz de 6x7, las cuales serán rellenadas por "X" (ficha del jugador)  y "O" (ficha de la maquina). Siempre el primer movimiento será del jugador. En este juego, se pedirá por pantalla la columna deseada para insertar la ficha, en el caso de que esta columna esté totalmente llena (desde la fila 1 a la 6) se aplicará control de errores e insertará la ficha en otra columna deseada, la maquina hará lo mismo, pero sin necesidad de escojer columna (claramente).

Cada "estado" del tablero será mostrado por pantalla. Un estado corresponde al ingreso de fichas al tablero, el estado 1 del tablero es vacío, el estado 2 es con la ficha ingresada por el jugador, el estado 3 por la maquina, y así continuamente hasta encontrar un ganador. Esto nos permite visualizar de forma precisa qué estado corresponde a qué jugador:

Inicio:         Jugador:            Maquina:
<-------------->;<--------------->;<--------------->
| | | | | | | | ; | | | | | | | | ; | | | | | | | |
| | | | | | | | ; | | | | | | | | ; | | | | | | | |
| | | | | | | | ; | | | | | | | | ; | | | | | | | |
| | | | | | | | ; | | | | | | | | ; | | | | | | | |
| | | | | | | | ; | | | | | | | | ; | |O| | | | | |
| | | | | | | | ; | |X| | | | | | ; | |X| | | | | |
<-------------->;<--------------->;<--------------->

El ganador se definirá cuando hayan 4 fichas iguales:
- Horizontales consecutivas
- Verticales consecutivas
- Diagonal derecha consecutivas
- Diagonal izquierda consecutivas

Opciones:
El jugador tendrá la posibilidad de esoger entre 3 dificultades:
-Facil: La maquina hará movimientos al azar.
-Media: La maquina intentará ganar realizando movimientos consecutivos.
-Dificil: La maquina buscará la mejor estrategia para ganar.

Cada vez que sea el turno del jugador, este tendrá la opción de "guardar partida", para posteriormente cargarla, o de lo contrario, realizar otro movimiento si así lo desea.
--------------------------------------------
# Implementación
--------------------------------------------
La función Minimax es un algoritmo de búsqueda utilizado en juegos de decisión, como el Conecta 4, para determinar el mejor movimiento posible de un jugador en función de todas las posibles jugadas. Opera recursivamente explorando el árbol de juego hasta una cierta profundidad o un estado terminal, evaluando y asignando un valor a cada posición del tablero. En el caso del Conecta 4, el algoritmo simula movimientos alternos de los jugadores, considerando los posibles resultados y eligiendo el movimiento que maximiza o minimiza la puntuación, dependiendo de si es el turno del jugador maximizador o minimizador, respectivamente. La función utiliza los parámetros alpha y beta para realizar poda alfa-beta, eliminando ramas innecesarias de exploración y mejorando la eficiencia computacional del algoritmo. En esencia, Minimax busca encontrar la estrategia óptima para un jugador, asumiendo que el oponente también juega de manera óptima.

La poda alfa-beta es una técnica de optimización aplicada al algoritmo Minimax en juegos de decisión, como el ajedrez. Su objetivo es reducir la complejidad computacional al eliminar la exploración de ramas innecesarias en el árbol de juego. Utilizando dos parámetros, alfa y beta, que representan los valores del mejor movimiento encontrado hasta el momento para el jugador maximizador y minimizador respectivamente, la poda alfa-beta interrumpe la exploración de una rama tan pronto como se determina que no influirá en la elección final. Al ir actualizando los valores de alfa y beta durante la búsqueda, se evita evaluar movimientos que no alterarán la decisión final, mejorando significativamente la eficiencia del algoritmo Minimax en términos de tiempo de ejecución.