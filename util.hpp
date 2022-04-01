#pragma once
namespace util
{
	/*enter color in BGR from 1.0f to 0.0f*/
	typedef struct Color {
		float b = 0, g = 0, r = 0;
		Color(float _b, float _g, float _r) {
			b = _b;
			g = _g;
			r = _r;
		}
		Color() {}
	};

}