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

std::vector<Point> extract(std::vector<Point>& points)
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

  points.erase(std::partition_point(points.begin(), points.end(), isRight), points.end());
}

int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
