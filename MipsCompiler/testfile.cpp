#include <iostream>
void uselessfunction()
{
	int a, b, c, d, e, f, g;
	for (int i = 0; i < 10; i++)
	{
		a = i;
		b = a * a;
		c = b % 5;
		if (c == 0)
		{
			d = c + 5;
			e = d * c;
		}
		else
		{
			d = c * c;
			e = d * c;
		}
		f = e - d;
		g = f * f;
	}
	std::cout << a << b << c << d << e << f << g << std::endl;
}