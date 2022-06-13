#define _USE_MATH_DEFINES
#include <vectors.h>
#include <math.h>
#include <string>

using std::to_string;
using sspe::Vec2;

Vec2::Vec2() {}
Vec2::Vec2(double px, double py): x(px), y(py) {}
Vec2::Vec2(double pxy) : x(pxy), y(pxy) {}

Vec2 sspe::operator* (Vec2 u, double s) {
	return { u.x * s, u.y * s };
}

Vec2 sspe::operator* (double s, Vec2 u) {
	return u * s;
}

Vec2 sspe::operator/ (Vec2 u, double s) {
	return u * (1 / s);
}

Vec2 sspe::operator+ (Vec2 u, Vec2 v) {
	return { u.x + v.x, u.y + v.y };
}

Vec2 sspe::operator- (Vec2 u, Vec2 v) {
	return { u.x - v.x, u.y - v.y };
}

void Vec2::operator*= (double s) {
	x *= s;
	y *= s;
}

void Vec2::operator/= (double s) {
	x /= s;
	y /= s;
}

void Vec2::operator+= (Vec2 v) {
	x += v.x;
	y += v.y;
}

void Vec2::operator-= (Vec2 v) {
	x -= v.x;
	y -= v.y;
}

Vec2 Vec2::orthogonal() {
	return { y, -x };
}

double Vec2::dot(Vec2 v) {
	return x * v.x + y * v.y;
}

double Vec2::cross(Vec2 v) {
	return x * v.y - v.x * y;
}

double Vec2::magnitude() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

double Vec2::magnitude_squared() {
	return pow(x, 2) + pow(y, 2);
}

double Vec2::angle_between(Vec2 v) {
	return atan2(cross(v), dot(v));
}

Vec2 Vec2::normalize() {
	double m = magnitude();

	if (m != 0)
		return { x / m, y / m };
	else if (isNormal())
		return { x, y };
	else
		return { 0, 0 };
}

double Vec2::distance_to(Vec2 v) {
	return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2));
}

double Vec2::distance_squared_to(Vec2 v) {
	return pow(v.x - x, 2) + pow(v.y - y, 2);
}

bool Vec2::isNormal() {
	return magnitude_squared() == 1;
}

Vec2 Vec2::reflect(Vec2 v) {
	double dv = dot(v);

	if (!v.isNormal())
		v = v.normalize();

	return { x - 2 * dv * v.x, y - 2 * dv * v.y };
}

string Vec2::repr() {
	return "(" + to_string(x) + "i + " + to_string(y) + "j)";
}

Vec2 sspe::weightedAverageVec2(Vec2* points, double* weights, int n) {
	double x = 0, y = 0, w = 0;

	for (int i = 0; i < n; i++) {
		x += points[i].x * weights[i];
		y += points[i].y * weights[i];
		w += weights[i];
	}

	return { x / w, y / w };
}

Vec2 sspe::basicAverageVec2(Vec2* points, int n) {
	double x{}, y{};

	for (int i = 0; i < n; i++) {
		x += points[i].x;
		y += points[i].y;
	}

	return { x / n, y / n };
}
