#pragma once
#include "Vec2.h"
#include <vector>

# define M_PI   3.14159265358979323846  /* pi */
# define EPS    0.0001

namespace geom {
	bool isCross(Vec2 a, Vec2 b, Vec2 c, Vec2 d);
	bool inPolygon(Vec2 point, std::vector<Vec2> polygon);

	Vec2 getCross(Vec2 a, Vec2 b, Vec2 c, Vec2 d);
	Vec2 direction(double a);
	Vec2 direction(Vec2  a, Vec2  b);
	Vec2 rotate(Vec2 p, double angle);

	double angle(Vec2 p);
	double angle(Vec2 a, Vec2 b, Vec2 c);
	double distance(Vec2  a, Vec2 b);
	double distance(Vec2  p, Vec2 a, Vec2 b);
	double square(std::vector<Vec2> polygon);
	double dotProd(const Vec2& a, const Vec2& b);
	double crossProd(const Vec2& a, const Vec2& b);

	std::vector<double> angleDistribution(double direction, double width, int n);
}