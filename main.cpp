#include <cmath>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

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

  auto middle = std::adjacent_find(points.begin(), points.end(),
                                   [&](auto& pt1, auto& pt2) { return !isRight(pt1) && isRight(pt2); });

  if (middle != points.end())
  {
    std::rotate(points.begin(), points.end(), std::next(middle));
  }

  if (!std::is_partitioned(points.begin(), points.end(), isRight))
  {
    throw std::runtime_error("Unexpected order");
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
