#pragma once

namespace Math {
	const float Pi = 3.14159265359; // 180
	const float PiDouble = 6.28318530718; // 360
	const float HalfPi = 1.57079632679; // 90

	inline float DegToRad(float Degrees) {
		return Degrees * (Pi / 180);
	}

	inline float RadToDeg(float Radians) {
		return Radians * (180 / Pi);
	}

	int SQR(int V);
	inline int Half(int V) { return V / 2; }
}