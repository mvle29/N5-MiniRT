#ifndef TYPE_MLX_H
# define TYPE_MLX_H

#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
}	t_mlx;

typedef struct	s_mlx_img
{
	t_mlx	*mlx;
	void	*img;
	int		img_w;
	int		img_h;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_mlx_img;

#endif
