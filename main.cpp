#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Point
{
public:
  int x, y;
};

std::vector<Point> extract(const std::vector<Point>& points)
{
  std::vector<Point> result;

  if (points.empty())
    return result;

  auto isRight = [](const Point& pt) { return pt.x >= 0; }

  int p = 0;
  for (int i = 1; i < points.size(); ++i)
  {
    if (!isRight(points[i - 1]) && isRight(points[i]))
    {
      p = i;
      break;
    }
  }

  int q = 0;
  for (int i = 1; i < points.size(); ++i)
  {
    if (isRight(points[i - 1]) && !isRight(points[i]))
    {
      q = i;
      break;
    }
  }

  if (p == q)
  {
    if ((*points.begin()).x >= 0)
      return points;
    else
      return result;
  }

  int i = p;
  while (i != q)
  {
    if (points[i].x >= 0)
    {
      result.clear();
      Point nan;
      nan.x = std::sqrt(-1);
      nan.x = std::sqrt(-1);
      result.push_back(nan);
      return result;
    }
    result.push_back(points[i]);
    if (++i >= points.size())
      i = 0;
  }

  i = q;
  while (i != p)
  {
    if (points[i].x >= 0)
    {
      result.clear();
      Point nan;
      nan.x = std::sqrt(-1);
      nan.x = std::sqrt(-1);
      result.push_back(nan);
      return result;
    }
    if (++i >= points.size())
      i = 0;
  }
}

int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
