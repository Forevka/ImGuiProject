#include "imgui.h"
#include <iostream>
#include <fmt/format.h>
#include <list>
#include "src/win32_directx11/BaseWidget.cpp" 



class BaseWindow
{
public:
    float width;
    float height;

    const char* name;

    int id;

    bool isOpen = true;

    std::list<BaseWidget*> widgets;
    std::list<BaseWidget*>::iterator it;

    BaseWindow(const float width, const float height, std::string name, int id)
    {
        this->width = width;
        this->height = height;
        this->id = id;
        this->name = GetUnicalName(name);

        std::cout << fmt::format("Creating {1} With Id = {0} ", id, name) << std::endl;
    }

    void AddWidget(BaseWidget* widget)
    {
		widgets.push_back(widget);
    }
	
	virtual void Draw() = 0;

    const char* GetUnicalName(const std::string& newName) const {
	    const auto unical = fmt::format("{0} #{1}", newName, id);

	    const auto cstr = new char[unical.length() + 1];

        strcpy(cstr, unical.c_str());

        return cstr;
    }
};
