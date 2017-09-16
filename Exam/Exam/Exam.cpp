#include "stdafx.h"

struct Point
{
	int x;
	int y;
};


using namespace std;

// Холст, позволяющий рисовать графические примитивы
class ICanvas
{
public:
	virtual void DrawLine(int x0, int y0, int x1, int y1) = 0;
	virtual ~ICanvas() {}
};

// Реализация холста, выполняющая вывод информации о рисуемых примитивах в stdout в виде:
// DrawLine:(<x0>, <y0>) - (<x1>, <y1>)
class CCanvas : public ICanvas
{
public:
	void DrawLine(int x0, int y0, int x1, int y1) override
	{
		std::cout << "DrawLine:(<" << x0 << ">, <" << y0 << ">) - (<" << x1 << ">, <" << y1 << ">) \n";
	}
private:
	int m_width;
	int m_height;
};

// Интерфейс объектов, которые можно нарисовать на холсте
class ICanvasDrawable
{
public:
	virtual void Draw(ICanvas & canvas) const = 0;
	virtual ~ICanvasDrawable() = default;
};

// Прямоугольник, обладающий координатами верхнего левого угла, шириной и высотой
class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(int x, int y, int width, int height)
		: m_x(x)
		, m_y(y)
		, m_width(width)
		, m_height(height)
	{
	}

	void Draw(ICanvas & canvas) const
	{
		canvas.DrawLine(m_x, m_y, m_x + m_width, m_y);
		canvas.DrawLine(m_x + m_width, m_y, m_x + m_width, m_y + m_height);
		canvas.DrawLine(m_x + m_width, m_y + m_height, m_x, m_y + m_height);
		canvas.DrawLine(m_x, m_y + m_height, m_x, m_y);
	}

private:
	int m_x, m_y, m_width, m_height;
};

// Треугольник, задается координатами трех вершин
class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(Point vertex1, Point vertex2, Point vertex3)
		: m_vertex1(vertex1)
		, m_vertex2(vertex2)
		, m_vertex3(vertex3)
	{
	}

	void Draw(ICanvas & canvas) const
	{
		canvas.DrawLine(m_vertex1.x, m_vertex1.y, m_vertex2.x, m_vertex2.y);
		canvas.DrawLine(m_vertex2.x, m_vertex2.y, m_vertex3.x, m_vertex3.y);
		canvas.DrawLine(m_vertex3.x, m_vertex3.y, m_vertex1.x, m_vertex1.y);
	}

private:
	Point m_vertex1, m_vertex2, m_vertex3;
};

// Рисует картину picture на холсте canvas
void DrawPicture(ICanvas & canvas, const vector<shared_ptr<const ICanvasDrawable>> & picture)
{
	for (const auto & drawable : picture)
	{
		drawable->Draw(canvas);
	}
}

int main()
{
	/*
	Задание:
	При помощи имеющихся фигур описать домик
	"Нарисовать" его при помощи функции DrawPicture на "холсте"
	/\
	/  \
	/    \
	--------
	|    |
	|    |
	|    |
	------
	*/
	CCanvas canvas;

	std::shared_ptr<CTriangle> roof = std::shared_ptr<CTriangle>(new CTriangle({ 1, 2 }, { 2, 3 }, { 3, 2 }));
	std::shared_ptr<CRectangle> rect = std::shared_ptr<CRectangle>(new CRectangle(1, 1, 2, 1));

	const std::vector<std::shared_ptr<const ICanvasDrawable>> picture = { roof, rect };

	DrawPicture(canvas, picture);
	getchar();
	return 0;
}
