#pragma once
#include <string>

using std::string;
// Vector arithmetic module of the physics engine
// For any comment, u and v are both vectors
// u is referring to the object in question
// v is referring to the object in comparison

namespace sspe
{
	// Two dimension Vector, containing the components x and y
	struct Vec2
	{
		double x{}, y{};

		Vec2(); // Default contructor
		Vec2(double px, double py); // Manual parameter assignment
		Vec2(double pxy); // Single parameter for both values

		//Multiplication operation specifications
		friend Vec2 operator* (Vec2 u, double s);
		friend Vec2 operator* (double s, Vec2 v);

		//Division operation specifications
		friend Vec2 operator/ (Vec2 u, double s);

		//Addition operation specifications
		friend Vec2 operator+ (Vec2 u, Vec2 v);

		//Subtraction operation specifications
		friend Vec2 operator- (Vec2 u, Vec2 v);

		void operator*= (double s);
		void operator/= (double s);
		void operator+= (Vec2 v);
		void operator-= (Vec2 v);

		// Create a perpendicular vector
		Vec2 orthogonal();

		// Find the dot product of u and v
		double dot(Vec2 v);

		// Find the cross product of u and v
		double cross(Vec2 v);

		// Find the length of the vector u
		double magnitude();

		// Find the squared length of the vector u (avoids the sqrt function)
		double magnitude_squared();

		// Calculate the angle between two vectors u and v
		double angle_between(Vec2 v);

		// Create a unit vector in the same direction of u
		Vec2 normalize();

		// Distance between two vectors u and v, equivalent to (v-u).magnitude()
		double distance_to(Vec2 v);

		// Squared Distance between two vectors u and v, equivalent to (v-u).magnitude_squared() (avoids the sqrt function)
		double distance_squared_to(Vec2 v);

		// Check if u is a unit vector
		bool isNormal();

		// Reflect u off of v
		Vec2 reflect(Vec2 v);

		// Displays the vector in component form for printing and debugging
		string repr();
	};

	// Addition operation definitions
	Vec2 operator+ (Vec2 u, Vec2 v);

	// Subtraction operation definitions
	Vec2 operator- (Vec2 u, Vec2 v);

	// Take the weighted average of a list of vectors
	Vec2 weightedAverageVec2(Vec2* points, double* weights, int n);

	Vec2 basicAverageVec2(Vec2* points, int n);

	// Three dimension Vector, containing the components x, y and z
	struct Vec3
	{
		double x{}, y{}, z{};
		Vec3(); // Default contructor
		Vec3(double px, double py, double pz); // Manual parameter assignment
		Vec3(double pxyz); // Single parameter for all values

		//Multiplication operation specifications
		friend Vec3 operator* (Vec3 u, double s);
		friend Vec3 operator* (double s, Vec3 v);

		//Division operation specifications
		friend Vec3 operator/ (Vec3 u, double s);

		//Addition operation specifications
		friend Vec3 operator+ (Vec3 u, Vec3 v);

		//Subtraction operation specifications
		friend Vec3 operator- (Vec3 u, Vec3 v);

		void operator*= (double s);
		void operator/= (double s);
		void operator+= (Vec3 v);
		void operator-= (Vec3 v);

		// Find the dot product of u and v
		double dot(Vec3 v);

		// Find the length of the vector u
		double magnitude();

		// Find the squared length of the vector u (avoids the sqrt function)
		double magnitude_squared();

		// Calculate the angle between two vectors u and v
		double angle_between(Vec3 v);

		// Create a unit vector in the same direction of u
		Vec3 normalize();

		// Distance between two vectors u and v, equivalent to (v-u).magnitude()
		double distance_to(Vec3 v);

		// Squared Distance between two vectors u and v, equivalent to (v-u).magnitude_squared() (avoids the sqrt function)
		double distance_squared_to(Vec3 v);

		// Check if the u is a unit vector
		bool isNormal();

		// Reflect u off of v
		Vec3 reflect(Vec3 v);

		// Displays the vector in component form for printing and debugging
		string repr();
	};

	// Multiplication operation definitions
	Vec3 operator* (Vec3 u, double s);
	Vec3 operator* (double s, Vec3 u);

	// Division operation definitions
	Vec3 operator/ (Vec3 u, double s);

	// Addition operation definitions
	Vec3 operator+ (Vec3 u, Vec3 v);

	// Subtraction operation definitions
	Vec3 operator- (Vec3 u, Vec3 v);
}