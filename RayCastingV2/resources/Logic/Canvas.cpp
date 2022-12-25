#include "../../headers/Logic.h"

void Canvas::DrawCanvas(HDC* hdc, PlayerProperties* obj)
{
	dc = hdc;
	hdc = nullptr;

	object = obj;
	obj = nullptr;

	//Background
	//sky
	SetDCPenColor(*dc, RGB(153, 217, 234));
	SetDCBrushColor(*dc, RGB(153, 217, 234));
	Rectangle(*dc, 0, 0, screen_width, screen_height / 2);
	//ground
	SetDCPenColor(*dc, RGB(50, 50, 50));
	SetDCBrushColor(*dc, RGB(50, 50, 50));
	Rectangle(*dc, 0, screen_height / 2, screen_width, screen_height);

	cur_angle = object->angle - object->FOV / 2;

	for (unsigned short ray_num = 0; ray_num < screen_width; ray_num++)
	{
		crosses[ray_num] = NearestCross();

		if (crosses[ray_num] < object->max_ray_depth + 1.f)
		{
			float wall_height = (float)screen_height * 50.f / (crosses[ray_num] * cos((object->angle - cur_angle) * PI / 180));

			SetDCPenColor(*dc, RGB(255, 150, 100));
			SetDCBrushColor(*dc, RGB(255, 150, 100));
			Rectangle(*dc, ray_num, (screen_height - wall_height) / 2, ray_num + 1, (screen_height + wall_height) / 2);
		}

		cur_angle += object->delta_angle;
	}

	dc = nullptr;
	object = nullptr;
}

float Canvas::NearestCross()
{
	float min_ray_depth_vertical = VerticalCross();

	float min_ray_depth_horizontal = HorizontalCross();

	if (min_ray_depth_vertical <= min_ray_depth_horizontal) return min_ray_depth_vertical;
	else return min_ray_depth_horizontal;
}

float Canvas::VerticalCross()
{
	float min_ray_depth = object->max_ray_depth + 1.f;

	for (float x = 0.f; x <= (float)map_width; x += 100.f)
	{
		float ray_depth = (x - object->pos_x) / cos(cur_angle * PI / 180.f);
		if (ray_depth <= object->max_ray_depth && ray_depth > 0.f)
		{
			float y = object->pos_y + ray_depth * sin(cur_angle * PI / 180.f);
			if (y <= (float)map_height && y >= 0.f)
			{
				if (map[(short)trunc(y) / 100][(short)x / 100] == 'w' || map[(short)trunc(y) / 100][(short)x / 100 - 1] == 'w')
				{
					if (min_ray_depth == object->max_ray_depth + 1.f || ray_depth < min_ray_depth) min_ray_depth = ray_depth;
				}
			}
		}
	}

	return min_ray_depth;
}

float Canvas::HorizontalCross()
{
	float min_ray_depth = object->max_ray_depth + 1.f;
	//float min_ray_depth = object->max_ray_depth / cos((object->angle - cur_angle) * PI / 180) + 1.f;

	for (float y = 0.f; y <= (float)map_height; y += 100.f)
	{
		float ray_depth = (y - object->pos_y) / sin(cur_angle * PI / 180.f);
		if (ray_depth <= object->max_ray_depth && ray_depth > 0.f)
		//if (ray_depth <= object->max_ray_depth / cos((object->angle - cur_angle) * PI / 180) && ray_depth > 0.f)
		{
			float x = object->pos_x + ray_depth * cos(cur_angle * PI / 180.f);
			if (x <= (float)map_width && x >= 0.f)
			{
				if (map[(short)trunc(y) / 100][(short)x / 100] == 'w' || map[(short)trunc(y) / 100 - 1][(short)x / 100] == 'w')
				{
					if (min_ray_depth == object->max_ray_depth + 1.f || ray_depth < min_ray_depth) min_ray_depth = ray_depth;
				}
			}
		}
	}

	return min_ray_depth;
}