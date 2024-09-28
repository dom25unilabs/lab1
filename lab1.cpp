#include <iostream>
#include <io.h>
#include <fcntl.h>

constexpr int M = 3, N = 4;
static inline bool check(double x, double y)
{
	if (x < 0 || y < 0)
	{
		return false;
	}
	else if (M * y > M * N - N * x)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int wmain(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	_setmode(_fileno(stderr), _O_U8TEXT);
	double x = 1, y = 1;
	if (argc <= 1 || std::wcsncmp(argv[1], L"false", sizeof(L"false") - 1) != 0)
	{
		while (1)
		{
			std::wcout << L"Новая точка?\nВведите значение 0 в координаты X и Y, чтобы выйти из программы.\nВведите значение координаты X:";
			std::wcin >> x;
			std::wcout << L"Введите значение координаты Y:";
			std::wcin >> y;
			if (x == 0 && y == 0)
			{
				break;
			}
			else
			{
				std::wcout << L"Точка (" << x << L", " << y << (check(x, y) ? L") " : L") не ") << L"входит в треугольник с вершинами (0, 0); (" << M << L", 0); (0, " << N << L")\n";
			}
		}	return 0;
	}
	while (1)
	{
		std::wcin >> x >> y;
		if (x == 0 && y == 0)
		{
			break;
		}
		else
		{
			std::wcout << (check(x, y) ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}