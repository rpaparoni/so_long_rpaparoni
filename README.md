# so_long 🧙‍♂️

so_long es un pequeño juego en 2D desarrollado en C utilizando la biblioteca gráfica **MiniLibX**. El objetivo del juego es mover al personaje a través del mapa, recoger todos los objetos y llegar a la salida.

## Instalación

### Requisitos
- Sistema Unix (Linux o macOS)
- **Make** y **GCC**
- **MiniLibX** (incluido en el proyecto o instalado por separado)

### Compilación
Ejecuta el siguiente comando para compilar el proyecto:
```sh
make
```

## Uso
Para ejecutar el juego, usa:
```sh
./so_long maps/mapa.ber
```

### Controles
- `W` / `↑` → Mover hacia arriba
- `A` / `←` → Mover hacia la izquierda
- `S` / `↓` → Mover hacia abajo
- `D` / `→` → Mover hacia la derecha
- `ESC` → Salir del juego

## Formato del Mapa
El mapa debe ser un archivo **.ber** con las siguientes reglas:
- Debe estar rodeado de paredes (`1`).
- Debe contener un jugador (`P`), una salida (`E`) y al menos un objeto coleccionable (`C`).
- Solo puede contener los caracteres permitidos: `0` (espacio vacío), `1` (pared), `P` (jugador), `C` (coleccionable), `E` (salida).

Ejemplo de mapa:
```
11111
1P0C1
1C0E1
11111
```

## Créditos
Proyecto desarrollado como parte del plan de estudios de la **Escuela 42**.

