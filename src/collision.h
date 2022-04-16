#pragma once

struct Circle
{
	float x;
	float y;
	float radius;
};

void draw_circle(const Circle& circle); // feedback: this function is never defined.
bool circle_intersect(const Circle& a, const Circle& b); // feedback: this function is never defined.

struct AABB
{
	static AABB make_from_position_size(float x, float y, float w, float h);

	float x_min;
	float y_min;

	float x_max;
	float y_max;
};

void draw_box(const AABB& box); // feedback: this function is never defined.
bool aabb_intersect(const AABB& a, const AABB& b); // feedback: this function is implemented but never used :) 

bool aabb_circle_intersect(const AABB& a, const Circle& b);
