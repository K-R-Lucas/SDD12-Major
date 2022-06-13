#define _USE_MATH_DEFINES
#include <vectors.h>
#include <math.h>
#include <string>

using std::to_string;
using sspe::Vec3;

Vec3::Vec3() {}
Vec3::Vec3(double px, double py, double pz) : x(px), y(py), z(pz) {}
Vec3::Vec3(double pxyz) : x(pxyz), y(pxyz), z(pxyz) {}

Vec3 sspe::operator* (Vec3 u, double s) {
	return { u.x * s, u.y * s, u.z * s };
}

Vec3 sspe::operator* (double s, Vec3 u) {
	return u * s;
}

Vec3 sspe::operator/ (Vec3 u, double s) {
	return u * (1 / s);
}

Vec3 sspe::operator+ (Vec3 u, Vec3 v) {
	return { u.x + v.x, u.y + v.y, u.z + v.z };
}

Vec3 sspe::operator- (Vec3 u, Vec3 v) {
	return { u.x - v.x, u.y - v.y, u.z - v.y };
}

void Vec3::operator*= (double s) {
	x *= s;
	y *= s;
	z *= s;
}

void Vec3::operator/= (double s) {
	x /= s;
	y /= s;
	z /= s;
}

void Vec3::operator+= (Vec3 v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vec3::operator-= (Vec3 v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

double Vec3::dot(Vec3 v) {
	return x * v.x + y * v.y;
}

double Vec3::magnitude() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Vec3::magnitude_squared() {
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

double Vec3::angle_between(Vec3 v) {
	return acos(dot(v) / (magnitude() * v.magnitude()));
}

Vec3 Vec3::normalize() {
	double m = magnitude();

	if (m != 0)
		return { x / m, y / m, z / m };
	else
		return { 0, 0, 0 };
}

double Vec3::distance_to(Vec3 v) {
	return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2) + pow(v.z - z, 2));
}

double Vec3::distance_squared_to(Vec3 v) {
	return pow(v.x - x, 2) + pow(v.y - y, 2) + pow(v.z - z, 2);
}

bool Vec3::isNormal() {
	return Vec3::magnitude_squared() == 1;
}

Vec3 Vec3::reflect(Vec3 v) {
	double dv = dot(v);

	if (!v.isNormal())
		v = v.normalize();

	return { x - 2 * dv * v.x, y - 2 * dv * v.y, z - 2 * dv * v.z };
}

string Vec3::repr() {
	return "(" + to_string(x) + "i + " + to_string(y) + "j + " + to_string(z) + "k)";
}