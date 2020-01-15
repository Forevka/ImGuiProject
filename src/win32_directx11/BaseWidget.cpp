
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <string>
#include <utility>

class BaseWidget
{
public:
	std::string widgetName;

	BaseWidget(std::string widget_name)
	{
		this->widgetName = std::move(widget_name);
	}

	void Draw()
	{
		if (widgetName == "Text")
		{
			ImGui::Text("TEST TEXT");
		}else if (widgetName == "Button")
		{
			ImGui::Button("Button test");
		}
	}
};
