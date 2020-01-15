#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
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

    std::list<BaseWidget*> textWindows;
    std::list<BaseWidget*>::iterator it;

    BaseWindow(float width, float height, std::string name, int id)
    {
        this->width = width;
        this->height = height;
        this->id = id;
        this->name = GetUnicalName(name);

        std::cout << fmt::format("Creating {1} With Id = {0} ", id, name) << std::endl;
    }

    void Initialize() const {
    }

    void AddWidget(BaseWidget* widget)
    {
        textWindows.push_back(widget);
    }
	
    void Draw()
    {
        ImGui::Begin(name);
    	
        for (it = textWindows.begin(); it != textWindows.end(); it++)
        {
            (*it)->Draw();
        }
    	
        ImGui::End();
    }

    const char* GetUnicalName(const std::string& newName) const {
        std::string unical = fmt::format("{0} #{1}", newName, id);

        char* cstr = new char[unical.length() + 1];

        strcpy(cstr, unical.c_str());

        return cstr;
    }
};
