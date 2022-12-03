#include "../../headers/Logic.h"

void MiniMap::DrawWalls()
{
	SetDCPenColor(dc, RGB(0, 0, 0));
	SetDCBrushColor(dc, RGB(255, 150, 100));

	for (float y = 0; y < (float)map_height; y += 100.f)
	{
		for (float x = 0; x < (float)map_width; x += 100.f)
		{
			if (MiniMap::map[(short)trunc(y / 100.f)][(short)trunc(x / 100.f)] == 'w')
			{
				Rectangle(dc, (short)(x * scale), (short)(y * scale), (short)((x + 100.f) * scale), (short)((y + 100.f) * scale));
			}
		}
	}
}

void MiniMap::DrawRays()
{
	cur_angle = object->angle - object->FOV / 2.f;

	for (float ray_num = 0.f; ray_num < (float)screen_width; ray_num++)
	{
		float nearest_cross = NearestCross();

		if (nearest_cross < object->max_ray_depth + 1.f)
		{
			SetDCBrushColor(dc, RGB(255, 255, 0));
			SetDCPenColor(dc, RGB(150, 150, 150));

			float cross_pos_x = object->pos_x + nearest_cross * cos(cur_angle * PI / 180);
			float cross_pos_y = object->pos_y + nearest_cross * sin(cur_angle * PI / 180);

			MoveToEx(dc, (short)(object->pos_x * scale), (short)(object->pos_y * scale), NULL);
			LineTo(dc, (short)(cross_pos_x * scale), (short)(cross_pos_y * scale));

			//SetDCPenColor(dc, RGB(255, 255, 0));
			//Rectangle(dc, (short)((cross_pos_x - 5.f) * scale), (short)((cross_pos_y - 5.f) * scale), (short)((cross_pos_x + 5.f) * scale), (short)((cross_pos_y + 5.f) * scale));
		}
		else if (nearest_cross == object->max_ray_depth + 1.f)
		{
			SetDCBrushColor(dc, RGB(255, 255, 0));
			SetDCPenColor(dc, RGB(150, 150, 150));

			float cross_pos_x = object->pos_x + (nearest_cross - 1.f) * cos(cur_angle * PI / 180);
			float cross_pos_y = object->pos_y + (nearest_cross - 1.f) * sin(cur_angle * PI / 180);

			MoveToEx(dc, (short)(object->pos_x * scale), (short)(object->pos_y * scale), NULL);
			LineTo(dc, (short)(cross_pos_x * scale), (short)(cross_pos_y * scale));

			//SetDCPenColor(dc, RGB(255, 255, 0));
			//Rectangle(dc, (short)((cross_pos_x - 5.f) * scale), (short)((cross_pos_y - 5.f) * scale), (short)((cross_pos_x + 5.f) * scale), (short)((cross_pos_y + 5.f) * scale));
		}

		cur_angle += object->delta_angle;
	}
}

void MiniMap::DrawPlayer()
{
	SetDCBrushColor(dc, RGB(100, 255, 255));
	SetDCPenColor(dc, RGB(0, 0, 0));
	Rectangle(dc, (short)((object->pos_x - 10.f) * scale), (short)((object->pos_y - 10.f) * scale), (short)((object->pos_x + 10.f) * scale), (short)((object->pos_y + 10.f) * scale));
}

void MiniMap::ShowMap(HDC* hdc, struct PlayerProperties* obj, float scale)
{
	dc = *hdc;
	hdc = nullptr;

	object = obj;
	obj = nullptr;

	this->scale = scale;

	//Clean screen
	SetDCPenColor(dc, RGB(50, 50, 50));
	SetDCBrushColor(dc, RGB(50, 50, 50));
	Rectangle(dc, 0 * scale, 0 * scale, map_width * scale, map_height * scale);

	DrawWalls();

	DrawRays();

	//Draw player
	DrawPlayer();
}

float MiniMap::NearestCross()
{
	float min_ray_depth_vertical = MiniMap::VerticalCross();

	float min_ray_depth_horizontal = MiniMap::HorizontalCross();

	if (min_ray_depth_vertical <= min_ray_depth_horizontal) return min_ray_depth_vertical;
	else return min_ray_depth_horizontal;
}

float MiniMap::VerticalCross()
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
				if (map[(short)trunc(y / 100.f)][(short)(x / 100.f)] == 'w' || map[(short)trunc(y / 100.f)][(short)(x / 100.f - 1.f)] == 'w')
				{
					if (min_ray_depth == object->max_ray_depth + 1.f || ray_depth < min_ray_depth) min_ray_depth = ray_depth;
				}
			}
		}
	}

	return min_ray_depth;
}

float MiniMap::HorizontalCross()
{
	float min_ray_depth = object->max_ray_depth + 1.f;

	for (float y = 0.f; y <= (float)map_height; y += 100.f)
	{
		float ray_depth = (y - object->pos_y) / sin(cur_angle * PI / 180.f);
		if (ray_depth <= object->max_ray_depth && ray_depth > 0.f)
		{
			float x = object->pos_x + ray_depth * cos(cur_angle * PI / 180.f);
			if (x <= (float)map_width && x >= 0.f)
			{
				if (map[(short)trunc(y / 100.f)][(short)(x / 100.f)] == 'w' || map[(short)trunc(y / 100.f - 1.f)][(short)(x / 100.f)] == 'w')
				{
					if (min_ray_depth == object->max_ray_depth + 1.f || ray_depth < min_ray_depth) min_ray_depth = ray_depth;
				}
			}
		}
	}

	return min_ray_depth;
}