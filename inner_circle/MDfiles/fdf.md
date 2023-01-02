# fdf
> Wireframe model
>> fdf is short for 'fil de fer' in French which means 'Wireframe model'

## Before start
### 1. MiniLibX(mlx)
> Simple Window Interface Library for students

#### Introductions
- MiniLibX is an easy way to create graphical software, without any X-window/X11, AppKit
	- It provides simple **window creation**, **a drawing tool**, **image and basic events management**
- Linking MiniLibX
	- On MacOs, the dynamic Metal library will find on its own the missing components : `-lmlx`
	- and still on MacOs, the static OpenGL version will need : `-lmlx -framework OpenGL -framework AppKit -lz`
- `#include <mlx.h>` : mlx.h should be included for a correct use of the MiniLibX API

##### `void *mlx_init()`
- Once the connection between your software and the display is established, you'll be able to use other MiniLibX functions
- This function will create this connection
- Parameters : No parameters are needed
- Return :  a void * identifier, used for further calls to the library routines
	> if `mlx_init()` fails to set up the connection to the display, it will return NULL

#### Handle events
##### `int mlx_loop(void *mlx_ptr);`
- To receive events, you must use `mlx_loop()`
- It is an infinite loop that waits for an event
- Parameters : A single parameter is needed, the connection identifier `mlx_ptr`.
- Return : This function never returns

##### `int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);`
- A key is pressed
- Parameters
	- `funct_ptr` : a pointer to the function you want to be called when an event occurs
	- `win_ptr` : This assignment is specific to the window defined by the `win_ptr` identifier
	- `param` : adress will be passed to the function everytime it is called, and should be used to store the parameters it might need
- Return : simply 0

##### `int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);`
- The mouse button is pressed
- Parameters
	- `funct_ptr` : a pointer to the function you want to be called when an event occurs
	- `win_ptr` : This assignment is specific to the window defined by the `win_ptr` identifier
	- `param` : adress will be passed to the function everytime it is called, and should be used to store the parameters it might need
- Return : simply 0

##### `int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);`
- A part of thw window should be re-drawn(this is called an "expose" event)
- Parameters
	- `funct_ptr` : a pointer to the function you want to be called when an event occurs
	- `win_ptr` : This assignment is specific to the window defined by the `win_ptr` identifier
	- `param` : adress will be passed to the function everytime it is called, and should be used to store the parameters it might need
- Return : simply 0

##### `int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);`
- This function will be called when no event occurs
- Parameters
	- `mlx_ptr` : Connection identifier
	- `funct_ptr` : a pointer to the function you want to be called when an event occurs
	- `param` : adress will be passed to the function everytime it is called, and should be used to store the parameters it might need
- Return : simply 0

> `param` is the address specified in the `mlx_*_hook` calls
>> On key events : `keycode` tells you which key is pressed  
>> On mounse events :  
>> - `(x, y)` are the coordinates of the mouse click in the window
>> - `button` tells you which mouse button was pressed

#### Manipulating images
##### `void *mlx_new_image(void *mlx_ptr, int width, int height);`
- This function creates a new image in memory
- Parameters
	- `mlx_ptr` : Connection identifier
	- `width` & `heigh` : Size of the image to be created
- Return : a `void *` identifier needed to manipulate this image later

##### `int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);`
- The user can dump the image inside a specified window at any time to display it on the screen
- Parameter
	- `mlx_ptr` : Connection to the display
	- `win_ptr` : The window to use
	- `img_ptr` : The image to use
- Return : simply 0

##### `char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);`
- Parameter
	- `img_ptr` : Specifies the image to use
	- `bits_per_pixel` : depth of the image = the number of bits needed to represent a pixel color
	- `size_line` : the number of bytes used to store one line of the image in memory
		> this information is needed to move from one line to another in the image
	- `endian` : 
- Return : Information about the created image, allowing a user to modify it later

##### `unsigned int mlx_get_color_value(void *mlx_ptr, int color);`

##### `void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);`

##### `void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);`

##### `void *mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);`

##### `int mlx_destroy_image(void *mlx_ptr, void *img_ptr);`

### 2. perror, strerror, exit

### 3. math library

### 4. isometric projection

## Mandatory part
|Program name|fdf|
|---|---|
|Turn in files|Makefile, \*.h, \*.c|
|Makefile|NAME, all, clean, fclean, re|
|Arguments|A file in format \*.fdf|
|External functs|open, close, read, write, malloc, free, perror, strerror, exit|
||All functions of the math library|
||All functions of the MiniLibX|
|Libft authorized|Yes|

> This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).

- Global variables are forbidden

### 1. Rendering
- The coordinate of the landscape are stored in a `.fdf` file passed as a parameter to your program
	- The horizontal position corresponds to its axit
	- The vertical position corresponds to its ordinate
	- The value corresponds to its altitude
> The goal of this project is not to parse maps, It means that we assume the map contained in the file is properly formatted

### 2. Graphic management
- Your program has to display the image in a window
- The management of your window must remain smooth (changing to another window, minimizing, and so forth)
- Pressing ESC must close the window and quit the program in a clean way
- Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way
- The use of the images of the MiniLibX is mandatory

## Bonus part
- Include one extra projection (such as parallel or conic)!
- Zoom in and out
- Translate your model
- Rotate your model
- Add one more bonus of your choice
