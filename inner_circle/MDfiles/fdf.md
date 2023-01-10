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
	- `char *` : the begining of th memory area where the image is stored
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
>> This make `mlx_pixel_put` slow, consider using images instead
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
- 3차원 물체를 평면 상에 표현하기 위한 방법의 일종으로 x,y,z 세 좌표축이 서로 이루는 각도가 모두 같거나 120도를 이루는 특성을 가진다
- 물체의 면을 정사도법으로 봤을 때, 물체에 대해서 수직 축으로 +/-45를 회전시킨 다음, 이어서 수평 축으로 약 +/-36.264도(=arcsin(tan30)) 회전시킨 것과 같다

### 5. rotation matrix
#### In 2 dimentions
$$
\begin{pmatrix}
x' \\
y'
\end{pmatrix} =
\begin{pmatrix}
cos\theta & -sin\theta \\
sin\theta & cos\theta
\end{pmatrix}
\begin{pmatrix}
x \\
y
\end{pmatrix}
$$

$$
x' = xcos\theta - ysin\theta \\
y' = xsin\theta + ycos\theta
$$

#### In 3 dimentions
- x축 기준
$$
\begin{pmatrix}
x' \\
y' \\
z'
\end{pmatrix} =
\begin{pmatrix}
1 & 0 & 0 \\
0 & cos\theta & -sin\theta \\
0 & sin\theta & cos\theta
\end{pmatrix}
\begin{pmatrix}
x \\
y \\
z
\end{pmatrix}
$$

$$
x' = x \\
y' = ycos\theta - zsin\theta \\
z' = ysin\theta + zcos\theta
$$

- y축 기준
$$
\begin{pmatrix}
x' \\
y' \\
z'
\end{pmatrix} =
\begin{pmatrix}
cos\theta & 0 & sin\theta \\
0 & 1 & 0 \\
-sin\theta & 0 & cos\theta
\end{pmatrix}
\begin{pmatrix}
x \\
y \\
z
\end{pmatrix}
$$

$$
x' = xcos\theta + zsin\theta \\
y' = y \\
z' = -xsin\theta + zcos\theta
$$

- z축 기준
$$
\begin{pmatrix}
x' \\
y' \\
z'
\end{pmatrix} =
\begin{pmatrix}
cos\theta & -sin\theta & 0 \\
sin\theta & cos\theta & 0 \\
0 & 0 & 1
\end{pmatrix}
\begin{pmatrix}
x \\
y \\
z
\end{pmatrix}
$$

$$
x' = xcos\theta - ysin\theta \\
y' = xsin\theta + ycos\theta \\
z' = z
$$

### 6. line drawing algorithm
#### DDA line drawing algorithm
- Digital Differential Analyzer
	- 중간값을 취하지 않는양
- 원리
	1. 기울기의 절댓값 확인
	1. 기울기가 1보다 작으면 x축을 기준, 기울가가 1보다 크면 y축을 기준
	1. (기울기가 1보다 작을 때) x축을 1씩 이동시키고 y값은 y값에 기울기를 더함
	1. (기울기가 1보다 클 때) y축을 1씩 이동시키고 x값은 x값에 기울기의 역수를 더함
	1. 나온 값이 실수라면 반올림을 한 좌표에 점을 찍는다
- 단점
	- 긴 선분일수록 오차가 누적되 잘 못 그려질 수 있음
	- 소수점계산 및 반올림을 해서 연산속도가 오래걸림


#### Bresenham's line algorithm
- 실수 연산이 필요없고 정수 연산만으로 처리되는 속도가 매우 빠른 래스터 방식 컴퓨터 그래픽에서 선을 긋는 알고리즘
- 직선의 방적식 : $y = mx + b$
	> $m = 기울기 = y증가량 / x증가량$  
	> $b = y절편$
	- $y = mx + b$ : 특정 좌표가 직선상에 위치함
	- $y > mx + b$ : 특정 좌표가 직선보다 위에 위치함
	- $y < mx + b$ : 특정 좌표가 직선보다 아래 위치함
- 원리
	1. 기울기가 0과 1사이인 직선을 가정 (x좌표 = Xk, y좌표 = Yk)
	1. x는 항상 1만큼 증가(Xk + 1), y는 Yk, Yk + 1 둘 중 하나를 선택
		1. 중단점(Mk + 1) 이 직선 위에 위치하면 &rarr; y값은 그대로 Yk선택
			> 중단점(Mk + 1) : Yk와 Yk + 1의 중간값
		1. 중단점(Mk + 1) 이 직선 아래에 위치하면 &rarr; y값은 1증가하여 Yk + 1선택
- 정수형 판별식 구하기
	> 기울기가 0 < m < 1인 경우에 대해서 진행
	>> 기울기가 m > 1인 경우는 y축 기준으로 진행하므로 y=x대칭 하여 유도할 수 있음
	- 좌표 2개(Xl, Yl), (Xr, Yr) 에 대해서 두 좌표를 연결하는 직선 (Xl, Yl) - (Xr, Yr)
		- W(width) = Xr - Xl
		- H(height) = Yr - Yl
1. 직선의 방정식에 W, H 대입
$$
y = {H \over W}x + b
$$
2. x에 xl, y에 yl을 넣어 b계산
$$
b = yl - {H \over W}xl
$$
3. b를 1번식에 대입
$$
y = {H \over W}x + yl - {H \over W}xl
$$
4. 위의 식을 직선보다 위의 있는 경우와 아래있는 경우에 대해서 정리하면,
	- 한쪽으로 넘긴 후 W를 곱해 분모가 없도록 만듬
	- 이후 양변에 2를 곱해 정리하면 아래의 식을 얻음
		- 직선보다 위에 있을 때 : $-2W(y - yl) + 2H(x - xl) < 0$
		- 직선보다 아래에 있을 때 : $-2W(y - yl) + 2H(x - xl) > 0$
5. 위에 얻은 판별식을 중단점에 대해서 판단
	- Mk+1 이 직선 위에 있음 &rarr; $F(Mk + 1) =  -2W(y - yl) + 2H(x - xl) < 0 \rightarrow (Xk + 1, Yk)$
	- Mk+1 이 직선 아래에 있음 &rarr; $F(Mk + 1) =  -2W(y - yl) + 2H(x - xl) > 0 \rightarrow (Xk + 1, Yk + 1)$
6. (Xk + 1, Yk + 1)을 결정하기 위한 판별식을 구함
	- 중단값은 $Mk + 1 = (Xk + 1, Yk + 0.5)$ 이므로
	- $F(Mk + 1) = -2W(Yk + 0.5 - yl) + 2H(Xk + 1 - xl)$ 을 최종적으로 얻음
7. 다음 중단점인 (Xk + 2, Yk + 2)을 결정하기 위한 판별식을 구함
	- F(Mk + 1) < 0인 경우,
		- y좌표는 그대로 x좌표는 +1 되었으므로, 중단값이  $Mk + 2 = (Xk + 2, Yk + 0.5)$
		- $F(Mk + 2) = -2W(Yk + 0.5 - yl) + 2H(Xk + 2 - xl)$ 을 얻음
		- 정리하면, $F(Mk + 2) = F(Mk + 1) + 2H$
	- F(Mk + 1) > 0인 경우,
		- y좌표, x좌표 모두 +1 되었으므로, 중단값이  $Mk + 2 = (Xk + 2, Yk + 1.5)$
		- $F(Mk + 2) = -2W(Yk + 1.5 - yl) + 2H(Xk + 2 - xl)$ 을 얻음
		- 정리하면, $F(Mk + 2) = F(Mk + 1) + 2(H - W)$
8. 판별식의 초깃값 F(M1)을 구함
	- $M1 = (x1 + 1, y1 + 0.5)$
$$
\begin{align*}
F(M1) &= -2W(y1 + 0.5 - y1) + 2H(x1 + 1 - x1) \\
&= -2Wy1 + 2Wy1 - W + 2Hx1 +2H - 2Hx1 \\
&= 2H - W
\end{align*}
$$
10. 픽셀위치 결정, 판별식 갱신
- F < 0 인 경우,
	- (Xk + 1, Yk) 에 점을 그림
	- 판별식 갱신 : F = F + 2H
- F > 0 인 경우
	- (Xk + 1, Yk + 1) 에 점을 그림
	- 판별식 갱신 : F = F + 2(H - W)

> cf) 위의 판별식 유도는 기울기가 0 < m < 1인 경우를 표현한 것이며 1 < m 일 경우 y축의 변위가 더 크기 때문에 식이 달라지게 된다
>> 위와 동일한 방식으로 유도한 기울기가 < 1인 경우의 픽셀위치와 판별식은 아래와 같다(y = x축 대칭)
>>> 초기값 : 2W - H

>>> F < 0 인 경우,
>>> - (Xk, Yk + 1)에 점을 그림
>>> - 판결식 갱신 : F = F + 2W 로 갱신

>>> F > 0 인 경우,
>>> - (Xk + 1, Yk + 1)에 점을 그림
>>> - 판별식 갱신 : F = F + 2(W - H)

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
