# cub3D

A first-person 3D view of a 2D maze, drawn with raycasting in C and MiniLibX, in the style of early 90s shooters. You give it a `.cub` file that describes a map, and you walk through it.

This is a project from the 42 curriculum, done at 1337 School.

## Features

- Textured walls, with a different texture for the north, south, east and west faces
- Floor and ceiling colours set in the map file
- Movement with collision: the player slides along a wall instead of stopping dead
- Rotation with the arrow keys or the mouse
- A parser that rejects broken map files with a clear error message
- 1200 x 800 window, 60 degree field of view

## Requirements

- Linux with X11
- `cc` and `make`
- MiniLibX for Linux, installed where the compiler can find it (`mlx.h` and `libmlx_Linux.a`)

To install MiniLibX on Debian or Ubuntu:

```sh
sudo apt install gcc make xorg libxext-dev libbsd-dev zlib1g-dev
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
sudo cp mlx.h /usr/local/include/
sudo cp libmlx_Linux.a /usr/local/lib/
```

## Build and run

```sh
git clone https://github.com/mfk-ayoub/cub-3d-v1.git
cd cub-3d-v1
make
./cub3D maps/valid_map/dungeon.cub
```

Run it from the root of the repository: the texture paths inside the maps are relative to it.

| Command | What it does |
| --- | --- |
| `make` | Builds `cub3D` (object files go in `bin/`) |
| `make clean` | Removes the object files |
| `make fclean` | Removes the object files and `cub3D` |
| `make re` | Rebuilds from scratch |

## Controls

| Key | Action |
| --- | --- |
| `W`, `S` | Move forward, move backward |
| `A`, `D` | Step left, step right |
| Left arrow, right arrow | Turn |
| Mouse | Turn by moving left or right |
| `Esc`, or the window's close button | Quit |

## Map format

A map is a text file ending in `.cub`. It has two parts: the settings, then the grid.

```
F 76,76,76
C 99,99,99

NO textures/simonkraft/cobblestone.xpm
SO textures/simonkraft/cobblestone_01.xpm
WE textures/simonkraft/mossy_cobblestone1.xpm
EA textures/simonkraft/cobblestone_02.xpm

1111111111111111111
10W1001001001000001
1011000001000001001
1001001001111101111
1001111000001001001
1000000000000001001
1001111111111001001
1111000000000001011
1000000001000000001
1111111111111111111
```

Settings, in any order, each exactly once:

| Line | Meaning |
| --- | --- |
| `NO`, `SO`, `WE`, `EA` | Path to the `.xpm` texture of the wall face looking north, south, west, east |
| `F` | Floor colour as `R,G,B`, each from 0 to 255 |
| `C` | Ceiling colour as `R,G,B`, each from 0 to 255 |

The grid comes last:

| Character | Meaning |
| --- | --- |
| `1` | Wall |
| `0` | Empty space |
| `N`, `S`, `E`, `W` | Where the player starts, and the direction they face |
| space | Outside the map |

The rules the parser checks:

- The file name ends in `.cub`.
- All six settings are present, none is repeated, every texture file exists and ends in `.xpm`.
- The map is closed: no empty space or player touches the outside.
- There is exactly one player.
- Nothing follows the grid except empty lines.

If a check fails, the program prints an error and exits without opening a window.

## Maps included

`maps/valid_map/` has seven maps to play: `dungeon`, `creepy`, `matrix`, `sub`, `sad_face`, `cheese_maze` and `eclpise`.

`maps/not_valid/` has broken files for testing the parser: an empty file, a wrong extension, a bad colour, a missing map, a map with no settings, and a map with no player.

## How the rendering works

Each frame, the program casts one ray for every column of the window, 1200 in all, spread across the field of view.

1. **Find the wall.** The ray advances through the grid one cell boundary at a time (the DDA algorithm) until it enters a wall cell. This gives the distance to the wall and which side of the cell was hit.
2. **Correct the distance.** The distance is multiplied by the cosine of the angle between the ray and the direction the player faces. Without this, walls bulge like through a fisheye lens.
3. **Size the wall.** The height of the wall slice on screen is the window height divided by that distance: the closer the wall, the taller the slice.
4. **Pick the texture.** The side that was hit and the direction of the ray decide which of the four textures to use. The exact point of impact along the wall gives the column of the texture to copy.
5. **Draw the column.** Ceiling colour above the slice, the stretched texture column in the middle, floor colour below.

The whole frame is written into one image in memory and sent to the window once, so nothing flickers.

## Layout

```
.
├── Makefile
├── main.c                 start-up, event hooks, game loop
├── includes/              settings (window size, keys, speeds) and structures
├── parser/                reading and checking the .cub file
├── src/                   raycasting, textures, movement, input, clean-up
├── assistants/            small string helpers and get_next_line
├── maps/
│   ├── valid_map/
│   └── not_valid/
└── textures/              .xpm wall textures
```

To change the window size, the field of view or the speeds, edit `includes/settings.h` and rebuild.
