#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <iostream>
#include <fmt/format.h>

class BaseWindow
{
public:
    float width;
    float height;

    std::string name;

    int id;

    bool isOpen = true;

public:
    BaseWindow(float width, float height, std::string name, int id)
    {
        this->width = width;
        this->height = height;
        this->id = id;
        this->name = name;

        std::cout << fmt::format("Creating {1} With Id = {0} ", id, name) << std::endl;
    }

public:
    void Initialize() const {
    }

    void Draw() const {
        //std::cout << GetUnicalName();
        const char* name = GetUnicalName();
        //std::cout << name << std::endl;
        ImGui::Begin(name);
        ImGui::End();
    }

    const char* GetUnicalName() const {
        std::string unical = fmt::format("{0} #{1}", name, id);

        char* cstr = new char[unical.length() + 1];

        strcpy(cstr, unical.c_str());

        return cstr;
    }
};
