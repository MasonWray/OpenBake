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

	ConfigNode* profile = new ConfigNode("Profile", ViewType::PROFILE_VIEW);
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
		tft->fillScreen(bg_default);
		items[0] = ConfigListItem(tft, ts, 0);

		for (int i = 0; i < node->num_children && i + 1 < ITEMS_PER_PAGE; i++)
		{
			items[i + 1] = ConfigListItem(node->children[i], tft, ts, i + 1);
		}
	}

	for (int i = 0; i < ITEMS_PER_PAGE; i++)
	{
		if (items[i].update())
		{
			// Back button was pressed
			if (items[i].is_back_button)
			{
				if (node == root)
				{
					next_view = ViewType::MAIN_VIEW;
				}
				else
				{
					node = node->parent;
				}
			}

			// Regular list item was pressed
			else
			{
				if (items[i].node->exit_node)
				{
					next_view = items[i].node->exit_dest;
				}
				else
				{

				}
			}
		}
	}

	prev = node;
}


