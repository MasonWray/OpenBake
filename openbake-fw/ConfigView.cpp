// 
// 
// 

#include "ConfigView.h"

using namespace Theme;

ConfigView::ConfigView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, Adafruit_MAX31855* _tc)
{
	type = ViewType::CONFIG_VIEW;
	next_view = ViewType::CONFIG_VIEW;
	display_width = width;
	display_height = height;
	tft = _tft;
	ts = _ts;
	tc = _tc;

	initialize();
}

ConfigView::~ConfigView()
{
	delete root;
}

void ConfigView::initialize()
{
	tft->fillScreen(ILI9341_BLACK);

	root = new ConfigNode("Config", nullptr, nullptr, 2);

	ConfigNode* profile = new ConfigNode("Profile", root, nullptr, 0);
	ConfigNode* settings = new ConfigNode("Settings", root, nullptr, 0);
	ConfigNode* root_children[] = { profile, settings };
	root->children = root_children;
	node = root;
	prev = nullptr;

	update();
}

void ConfigView::update()
{
	bool rerender = false;

	if (node != prev)
	{
		rerender = true;
	}

	if (rerender)
	{
		tft->fillScreen(background_color);
		items[0] = ConfigListItem(tft, ts, 0);

		for (int i = 0; i < node->num_children && i + 1 < ITEMS_PER_PAGE; i++)
		{
			items[i + 1] = ConfigListItem(node->children[i], tft, ts, i + 1);
		}
	}

	prev = node;
}


