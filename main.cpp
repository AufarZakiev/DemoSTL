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

  if (points.size() == 0)
    return result;

  int p = 0;
  bool found = false;
  for (int i = 1; i < points.size() && ~found; ++i)
  {
    if (points[i - 1].x < 0 && points[i].x >= 0)
    {
      p = i;
      found = true;
    }
  }

  int q = 0;
  bool found2 = false;
  for (int i = 1; i < points.size() && ~found; ++i)
  {
    if (points[i - 1].x >= 0 && points[i].x < 0)
    {
      q = i;
      found2 = true;
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
