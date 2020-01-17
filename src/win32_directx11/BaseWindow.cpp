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

    std::list<BaseWidget*> textWindows;
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
        textWindows.push_back(widget);
    }
	
    void Draw()
    {
        ImGui::Begin(name);
    	
        for (it = textWindows.begin(); it != textWindows.end(); it++)
        {
            (*it)->Draw();
        }

		ImVec2 p = ImGui::GetWindowPos();
		p.x += ImGui::GetWindowWidth();
		p.y += ImGui::GetWindowHeight() / 2;
    	
		ImGui::BeginChild("Test");
		ImGui::GetOverlayDrawList()->AddLine(p, ImVec2(p.x + 500, p.y + 500), IM_COL32(255, 0, 0, 255), 3.0f);

		ImGui::GetOverlayDrawList()->AddBezierCurve(p, ImVec2(p.x, p.y + 500), ImVec2(p.x + 500, p.y), ImVec2(p.x + 500, p.y + 500), IM_COL32(255, 0, 0, 255), 3.0f, 16);
		ImGui::EndChild();
        ImGui::End();
    }

    const char* GetUnicalName(const std::string& newName) const {
	    const auto unical = fmt::format("{0} #{1}", newName, id);

	    const auto cstr = new char[unical.length() + 1];

        strcpy(cstr, unical.c_str());

        return cstr;
    }
};
