#include <cmath>
#include <iostream>
#include <vector>
#include <limits>

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

  auto isRight = [](const Point& pt) { return pt.x >= 0; };

  auto findBoundary = [&](bool flag) {
    int p = 0;
    for (int i = 1; i < points.size(); ++i)
    {
      if (isRight(points[i - 1]) == flag && isRight(points[i]) != flag)
      {
        p = i;
        return i;
      }
    }
    return 0;
  };

  int p = findBoundary(false);
  int q = findBoundary(true);

  if (p == q)
  {
    return (isRight(points[0])) ? points : result;
  }

  auto appendResult = [&](int from, int to, bool shouldBeRight) {
    int i = from;
    while (i != to)
    {
      if (isRight(points[i]) != shouldBeRight)
      {
        throw std::runtime_error("Unexpected order");
      }
      if (shouldBeRight)
      {
        result.push_back(points[i]);
      }
      if (++i >= points.size())
        i = 0;
    }
    return true;
  };

  bool success = appendResult(p, q, true) && appendResult(q, p, true);
}

int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
