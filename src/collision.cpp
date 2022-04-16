#include "collision.h"
#include "engine.h"
#include <SDL/SDL.h>

const float PI = 3.1415;

AABB AABB::make_from_position_size(float x, float y, float w, float h)
{
	AABB box;
	box.x_min = x - w / 2;
	box.y_min = y - h / 2;
	box.x_max = x + w / 2;
	box.y_max = y + h / 2;

	return box;
}

bool aabb_intersect(const AABB& a, const AABB& b)
{
	return (a.x_max > b.x_min &&
			b.x_max > a.x_min &&
			a.y_max > b.y_min &&
			b.y_max > a.y_min);
}


float clamp(float a, float min, float max)
{
	if (a < min)
		return min;
	if (a > max)
		return max;

	return a;
}

bool aabb_circle_intersect(const AABB& a, const Circle& b)
{
	float clamped_x = clamp(b.x, a.x_min, a.x_max);
	float clamped_y = clamp(b.y, a.y_min, a.y_max);

	float dx = b.x - clamped_x;
	float dy = b.y - clamped_y;

	float dist_sqrd = dx * dx + dy * dy;
	float dist = sqrt(dist_sqrd); // feedack: when you are only interested in comparing two radii you don't need to perform an expensive sqrt operation.
									// Its enough to compare just dist_sqrd in this case.

	return dist < b.radius;
}
