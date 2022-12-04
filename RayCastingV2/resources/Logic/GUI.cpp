#include "../../headers/Logic.h"

void GUI::DrawWallsMap()
{
	SetDCPenColor(*dc, RGB(0, 0, 0));
	SetDCBrushColor(*dc, RGB(255, 150, 100));

	for (float y = 0; y < (float)map_height; y += 100.f)
	{
		for (float x = 0; x < (float)map_width; x += 100.f)
		{
			if (map[(short)trunc(y / 100.f)][(short)trunc(x / 100.f)] == 'w')
			{
				Rectangle(*dc, (short)(x * scale), (short)(y * scale), (short)((x + 100.f) * scale), (short)((y + 100.f) * scale));
			}
		}
	}
}

void GUI::DrawRaysMap()
{
	cur_angle = object->angle - object->FOV / 2.f;

	for (int ray_num = 0; ray_num < screen_width; ray_num++)
	{
		if (crosses[ray_num] < object->max_ray_depth + 1.f)
		{
			SetDCBrushColor(*dc, RGB(255, 255, 0));
			SetDCPenColor(*dc, RGB(150, 150, 150));

			float cross_pos_x = object->pos_x + crosses[ray_num] * cos(cur_angle * PI / 180);
			float cross_pos_y = object->pos_y + crosses[ray_num] * sin(cur_angle * PI / 180);

			MoveToEx(*dc, (short)(object->pos_x * scale), (short)(object->pos_y * scale), NULL);
			LineTo(*dc, (short)(cross_pos_x * scale), (short)(cross_pos_y * scale));

			//SetDCPenColor(dc, RGB(255, 255, 0));
			//Rectangle(dc, (short)((cross_pos_x - 5.f) * scale), (short)((cross_pos_y - 5.f) * scale), (short)((cross_pos_x + 5.f) * scale), (short)((cross_pos_y + 5.f) * scale));
		}
		else if (crosses[ray_num] == object->max_ray_depth + 1.f)
		{
			SetDCBrushColor(*dc, RGB(255, 255, 0));
			SetDCPenColor(*dc, RGB(150, 150, 150));

			float cross_pos_x = object->pos_x + (crosses[ray_num] - 1.f) * cos(cur_angle * PI / 180);
			float cross_pos_y = object->pos_y + (crosses[ray_num] - 1.f) * sin(cur_angle * PI / 180);

			MoveToEx(*dc, (short)(object->pos_x * scale), (short)(object->pos_y * scale), NULL);
			LineTo(*dc, (short)(cross_pos_x * scale), (short)(cross_pos_y * scale));

			//SetDCPenColor(dc, RGB(255, 255, 0));
			//Rectangle(dc, (short)((cross_pos_x - 5.f) * scale), (short)((cross_pos_y - 5.f) * scale), (short)((cross_pos_x + 5.f) * scale), (short)((cross_pos_y + 5.f) * scale));
		}

		cur_angle += object->delta_angle;
	}
}

void GUI::DrawPlayerMap()
{
	SetDCBrushColor(*dc, RGB(100, 255, 255));
	SetDCPenColor(*dc, RGB(0, 0, 0));
	Rectangle(*dc, (short)((object->pos_x - 10.f) * scale), (short)((object->pos_y - 10.f) * scale), (short)((object->pos_x + 10.f) * scale), (short)((object->pos_y + 10.f) * scale));
}

void GUI::DrawMap(HDC* hdc, struct PlayerProperties* obj, float crosses[screen_width], float scale)
{
	dc = hdc;
	hdc = nullptr;

	object = obj;
	obj = nullptr;

	for (int i = 0; i < screen_width; i++)
	{
		this->crosses[i] = crosses[i];
	}

	this->scale = scale;

	//Clean screen
	SetDCPenColor(*dc, RGB(50, 50, 50));
	SetDCBrushColor(*dc, RGB(50, 50, 50));
	Rectangle(*dc, 0 * scale, 0 * scale, map_width * scale, map_height * scale);

	DrawWallsMap();
	DrawRaysMap();
	DrawPlayerMap();

	dc = nullptr;
}