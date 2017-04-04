#include "wolf.h"

void	generate_texture(int ans[5][TEXHEIGHT * TEXWIDTH])
{
	int	x;
	int	y;
	int xor;
	int xycolor;

	y = 0;
	while (y < TEXHEIGHT)
	{
		x = 0;
		while (x < TEXWIDTH)
		{
			xor = (x * 256 / TEXWIDTH) ^ (y * 256 / TEXHEIGHT);
			xycolor = y * 128 / TEXHEIGHT + x * 128 / TEXWIDTH;
			ans[0][TEXHEIGHT * x + y] = 256 * xor;
			ans[1][TEXHEIGHT * x + y] = xor + 256 * xor + 65536 * xor;
			ans[2][TEXHEIGHT * x + y] = 65536 * 192 * (x % 16 && y % 16);
			ans[3][TEXHEIGHT * x + y] =
				65536 * 254 * (x != y && x != TEXWIDTH - y);
			ans[4][TEXHEIGHT * x + y] = 256 * xycolor + 65536 * xycolor;
			x++;
		}
		y++;
	}
}
