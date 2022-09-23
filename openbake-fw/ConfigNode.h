// ConfigNode.h

#ifndef _CONFIGNODE_h
#define _CONFIGNODE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "View.h"

class ConfigNode
{
public:
	ConfigNode(String _name, ConfigNode* _parent, ConfigNode** _children, int _num_children);
	ConfigNode(String name, View* exit_dest);
	~ConfigNode();

	String name;
	ConfigNode* parent;
	ConfigNode** children;
	int num_children;

	bool exit_node;
	View* exit_dest;
};

#endif

