#include "fdf.h"
#include <stdio.h>

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int bits_per_pixel=0;
	int size_line=0;
	int endian=0;
	char *image;
	int i;
	int j;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "test");
	img_ptr = mlx_new_image(mlx_ptr, 1000, 1000);
	image = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	j = 0;
	while (j < 1000)
	{
		i = 0;
		while (i < 1000)
		{
			*(image + (bits_per_pixel * i / 8) + (size_line * j)) = 0xFF;
			*(image + 1 + (bits_per_pixel * i / 8) + (size_line * j)) = 0xFF;
			*(image + 2 + (bits_per_pixel * i / 8) + (size_line * j)) = 0xFF;
			*(image + 3 + (bits_per_pixel * i / 8) + (size_line * j)) = 0;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}
