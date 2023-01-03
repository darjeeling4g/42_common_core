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
	- `endian` : little endian(endian == 0), big endian(endian == 1)
		> endian : 메모리상에 byte가 표현되는 방법
		>> Big endian : 큰 단위가 먼저 표현되는 것  
		>> Little endian : 작은 단위가 먼저 표현되는 것
- Return : Information about the created image, allowing a user to modify it later
	- `bits_per_pixel` : the color of the first pixel in the first line of the image
	- `size_line` : the address to get begining of the second line

##### `unsigned int mlx_get_color_value(void *mlx_ptr, int color);`
- Parameters
	- `mlx_ptr` : Screen Connection Identifier
	- `color` : a standard RGB color
- Return : color parameter to unsigned int value

##### `void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);`
- Parameters
	- `mlx_ptr` : Screen Connection Identifier
	- `xpm_data` : xpm data
	- `width` : width of image
	- `height` : height of image
- Return : non-null pointer as an image identifier
	> if an error occurs, return NULL

##### `void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);`
- Parameters
	- `mlx_ptr` : Screen Connection Identifier
	- `filename` : xpm filename
	- `width` : width of image
	- `height` : height of image
- Return : non-null pointer as an image identifier
	> if an error occurs, return NULL

##### `void *mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);`
- Parameters
	- `mlx_ptr` : Screen Connection Identifier
	- `filename` : png filename
	- `width` : width of image
	- `height` : height of image
- Return : non-null pointer as an image identifier
	> if an error occurs, it will return NULL

##### `int mlx_destroy_image(void *mlx_ptr, void *img_ptr);`
- Destroys the given image
- Parameters
	- `mlx_ptr` : Connection to the display
	- `img_ptr` : Specifies the image to use
- Return : simply 0

#### Managing windows
##### `void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);`
- Parameters
	- `mlx_ptr` : Screen Connection Identifier
	- `size_x` & `size_y` : determine its size
	- `title` : the text that should be displayed in the window's title bar
- Return : non-null pointer is returned as a window identifier
	> if fails to craete a new window, it will return NULL

##### `void *mlx_clear_window(void *mlx_ptr, void *win_ptr);`
- Clear the given window in black
- Parameters :
	- `mlx_ptr` : Screen Connection Identifier
	- `win_ptr` : Window Identifier
- Return : none

##### `void *mlx_destroy_window(void *mlx_ptr, void *win_ptr);`
- Destroy the given window in black
- Parameters :
	- `mlx_ptr` : Screen Connection Identifier
	- `win_ptr` : Window Identifier
- Return : none

#### Drawing inside windows
##### `int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);`
- Draws a defined pixel in the window
> discard any display outside the window
>> This make `mlx_pixel_put` slow
- Parameters
	- `mlx_ptr` : Screen Connection Identifier
	- `win_ptr` : Window Identifier
	- `x` & `y` : pixel coordinates
		> The origin (0,0) is the upper left corner of the window
		>> x and y axis pointing right and down
	- `color` : Specifies the color
- Return : none

##### `int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);`
- Draws a defined string in the window
- Parameters
	- `mlx_ptr` : Screen Connection Identifier
	- `win_ptr` : Window Identifier
	- `x` & `y` : string coordinates
	- `color` : Specifies the color
	- `string` : string will be displayed
- Return : simply 0

### 2. perror, strerror, exit
- 라이브러리 함수의 경우 오류가 발생하면 `NULL`을 반환
- 시스템 콜의 경우 오류가 발생하면 `-1`을 반환
	- 오류 원인을 나타내는 상수 값은 `errno`변수에 저장
		> `errno`을 사용하기 위해서는 `errno.h`필요
	- 상수로 저장되는 코드 값을 알아보기 힘들기 때문에 오류코드를 메시지로 변환해주는 함수(perror, strerror) 사용
- `void perror(const char *s);`
	> `perror`을 사용하기 위해서는 `stdio.h`필요
	- `s` : 출력하길 원하는 문자열
- `char *strerror(int errnum);`
	> `strerror`을 사용하기 위해서는 `string.h`필요
	- `errnum` : errno에 저장된 값
- `void exit(int status);` : 프로세스를 종료하는 함수
	> 사용하기 위해서는 `stdlib.h`필요
	>> `return`의 경우, 해당 스택의 함수만 종료하는 것
	- `exit(0)` : 정상 종료
	- `exit(1)` : 비정상 종료


### 3. math library
- Header file : `math.h`

|함수|설명|
|---|---|
|삼각함수||
|`double sin (double x);`|사인 x를 구한다|
|`double cos (double x);`|코사인 x를 구한다|
|`double tan (double x);`|탄젠트 x를 구한다|
|역 삼각함수||
|`double asin (double x);`|아크 사인 x를 구한다|
|`double acos (double x);`|아크 코사인 x를 구한다|
|`double atan (double x);`|아크 탄젠트 x를 구한다|
|`double atan2 (double x);`|아크 탄젠트 y/x를 구한다|
|쌍곡선 함수||
|`double sinh (double x);`|하이퍼볼릭 사인 x를 구한다|
|`double cosh (double x);`|하이퍼볼릭 코사인 x를 구한다|
|`double tanh (double x);`|하이퍼볼릭 탄제트 x를 구한다|
|지수 대수 함수||
|`double exp (double x);`|e^x를 구한다|
|`double frexp (double x, int *exp);`|지수를 exp가 가리키는 변수에 저장하고 가수를 반환한다|
|`double ldexp (double x, int exp);`|x * 2^exp를 반환한다|
|`double log (double x);`|loge x를 구한다|
|`double log10 (double x);`|log10 x를 구한다|
|`double modf (double x, double * intpart);`|정수부를 intpart가 가리키는 변수에 저장하고 소수부를 반환한다|
|거듭제곱, 거듭제곱근, 올림, 내림, 절댓값, 나머지 함수||
|`double pow (double x, double y);`|x^y를 구한다|
|`double sqrt (double x);`|루트x를 구한다|
|`double ceil (double x);`|x보다 작지 않는 가장 작은 정수를 구한다|
|`double floor (double x);`|x보다 크지 않은 가장 크 정수를 구한다|
|`double fabs (double x);`|x의 절댓값을 구한다|
|`double fmod (double x, double y);`|x를 y로 나눈 나머지를 구한다|

### 4. isometric projection

### 5. rotation matrix
- in 2 dimention
$$
x' = xcos\theta - ysin\theta \\
y' = xsin\theta + ycos\theta
$$

- in 3 dimention
$$
x' = xcos\theta - ysin\theta \\
y' = xsin\theta + ycos\theta
$$

### 6. line drawing algorithm
#### DDA line drawing algorithm

#### Bresenham's line algorithm

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
