<div align="center">
<img src="subject/cover.png" alt="Covers" width="650" />

</br>
</br>

<strong>Cub3D 🎮</strong>

<p>Cub3D is a project inspired by Wolfenstein 3D, one of the first first-person shooter games. It allows you to explore ray-casting techniques to create a 3D maze representation. The goal is to navigate through this environment while respecting the constraints of the graphic engine.</p>

</br>

<img src="subject/output_compressed.gif" alt="GIF Cub3d" width="650" />

<p><a href="https://github.com/MathysCogne/42_Cub3D/blob/main/subject/fr.subject.pdf"><strong>Subject</strong></a></p>

</div>

## Features

- 3D rendering using ray-casting

- Custom textures and configurable map

- Player movement and interactions

- Minimap display (bonus)

- Animated sprites (bonus)

- Door system (bonus)

- 360-degree full viewpoint management  (bonus)

- Mouse interaction for precise aiming and camera control (bonus)

- Weapon, and stats player (Heath, stamina..) (bonus)

</br>


## Controls

| Key     | Description       |
|:--------|:-------------------
| ESC        | Quit the game  |
| W/A/S/D     | Move         |
| ⬆️ / ⬇️     | Tilt the camera vertically      |
| ⬅️ / ➡️      | Rotate the camera horizontally      |
| Mouse movement     | Adjust camera viewpoint     |
| Left Mouse Click     | Shoot weapon     |
| Right Mouse Click     | Interaction weapon     |


</br>

## Map  `(.cub formar)`

** NO ./path_to_the_north_texture
** SO ./path_to_the_south_texture
** WE ./path_to_the_west_texture
** EA ./path_to_the_east_texture
**
** F 220,100,0
** C 225,30,0
**
**         1111111111111111111111111
**         1000000000110000000000001
**         1011000001110000000000001
**         1001000000000000000000001
** 111111111011000001110000000000001
** 100000000011000001110111111111111
** 11110111111111011100000010001
** 11110111111111011101010010001
** 11000000110101011100000010001
** 10000000000000001100000010001
** 10000000000000001101010010001
** 11000001110101011111011110N0111
** 11110111 1110101 101111010001
** 11111111 1111111 111111111111


## Compilation and Usage

</br>

```bash
# Compile:
make

# Start game:
./cub3d [path_map]
```

</br>


⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖

</br>

## RayCasting
Ray Casting Solution</br>
This guide explains the logic behind ray casting for rendering a 3D-like environment using a 2D map.</br>

- 1/ Rays & Field of View (FOV)

If the player has a 90° field of view (FOV) and is looking straight north (90°, depending on your implementation), then the rays will cover an angular range from 90° - 45° to 90° + 45°.

If you cast 90 rays, each one corresponds to a specific angle in this range:
Angles: 45°, 46°, 47°, ..., 134°, 135°

Each ray is traced independently to detect walls and compute the depth of field.
- 2/ Calculating Ray Vectors

To compute the movement vector for each ray, use trigonometry:

    X displacement:
    dx=cos⁡(angleh)
    dx=cos(angleh​)
    Y displacement:
    dy=sin⁡(angleh)
    dy=sin(angleh​)

For example, if the player is looking straight north (90°), then:

    dx=cos⁡(90°)=0dx=cos(90°)=0
    dy=sin⁡(90°)=1dy=sin(90°)=1

This means the ray moves vertically upwards on the 2D grid.
Proportionality Calculations

To find the movement needed to reach the next X or Y intersection, use the cross-multiplication rule:
Case 1: Moving x_len on the X-axis, how much do we move in Y?
ylen=sin⁡(angleh)×xlencos⁡(angleh)
ylen​=cos(angleh​)sin(angleh​)×xlen​​
Case 2: Moving y_len on the Y-axis, how much do we move in X?
xlen=cos⁡(angleh)×ylensin⁡(angleh)
xlen​=sin(angleh​)cos(angleh​)×ylen​​

These formulas allow us to step through the grid along the ray's direction.
- 3/ Wall Detection (Grid Intersection Check)

We need to determine where the ray first intersects a wall (represented by 1 in the grid).
Step 1: Initialize the Ray

    Start at player's position (x = 4.5, y = 3.5)
    Determine the first intersections with the vertical and horizontal grid lines.

Step 2: Compute Next Grid Intersections

The first horizontal and vertical intersections can be calculated as:

    Horizontal intersection (y-grid line)
    disty=ynext−ysin⁡(angleh)
    disty​=sin(angleh​)ynext​−y​

    Vertical intersection (x-grid line)
    distx=xnext−xcos⁡(angleh)
    distx​=cos(angleh​)xnext​−x​

Where:

    ynextynext​ is the closest integer y-grid line
    xnextxnext​ is the closest integer x-grid line

Step 3: Select the Closest Intersection

Compare dist_x and dist_y:

    If dist_x < dist_y, move in the X direction
    Otherwise, move in the Y direction

Step 4: Check for Wall Collision

After moving to the new grid cell, check:
grid[(int)y−1][(int)x−1]==1
grid[(int)y−1][(int)x−1]==1

    If true → Wall hit detected, stop the ray.
    If false → Continue stepping forward until a wall is found.

- 4/ Rendering the Ray on the Image

Once we have the distance to the wall, we can determine the height of the projected wall on the screen.

    The shorter the distance, the taller the wall appears.
    The farther the distance, the shorter the wall appears.

The result is mapped as a pixel offset (x %, y %) between 0 and 1 to determine how to draw the final scene.
- 5/ Draw the Image and Enjoy Your 3D View!

Once all rays have been processed and wall distances calculated, render the walls on the screen using perspective projection.

## Disclaimer
> At 42 School, most projects must comply with the [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).

