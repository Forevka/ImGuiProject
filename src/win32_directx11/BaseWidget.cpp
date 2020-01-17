
#include "imgui.h"
#include <iostream>
#include <string>
#include <src/win32_directx11/TriggerComponent.cpp>
#include <array>
#include <fmt/format.h>


class BaseWidget
{
public:
	std::string widget_name;
	int myId;
	static int widgetId;

	BaseWidget()
	{
		widgetId++;
		myId = widgetId;

		std::cout << fmt::format("Creating BaseWidget With Id = {0} ", myId) << std::endl;
	}
	
	virtual ~BaseWidget() = default;
	
	virtual void Draw() = 0;

	static BaseWidget* MakeWidget(const std::string& widget_name);
};

class TextWrapper final : public BaseWidget
{
	void Draw() override
	{
		ImGui::Text("TEST TEXT");
	}
};

class InputWrapper final : public BaseWidget
{
public:
	char str[512] = "Input here...";
	
	void Draw() override
	{
		ImGui::InputTextMultiline("text", str, IM_ARRAYSIZE(str), ImVec2(-1.0f, ImGui::GetTextLineHeight() * 16), ImGuiInputTextFlags_AllowTabInput);
	}

	static int TextCallback(ImGuiTextEditCallbackData* data)
	{
		data->EventChar = 'A';
		return 0;
	}
};

class LinkWidget final: public BaseWidget
{
public:
	char str[512] = "Link widget...";
	BaseWidget* linkedTo = nullptr;

	void Draw() override
	{
		ImGui::InputText("text", str, IM_ARRAYSIZE(str));
	}

	void SetLinkedTo(BaseWidget* link_to)
	{
		linkedTo = link_to;
	}

	void DeleteLink()
	{
		linkedTo = nullptr;
	}
};


class ButtonWrapper final : public BaseWidget, public TriggerComponent
{
public:
	void Draw() override
	{
		if (ImGui::Button("Button test"))
		{
			this->RaiseEvent();
		}
	}
};

inline auto BaseWidget::MakeWidget(const std::string& widget_name) -> BaseWidget*
{
	if (widget_name == "Text")
	{
		return new TextWrapper;
	}
	
	if(widget_name == "Button")
	{
		auto* but = new ButtonWrapper();

		auto* obs = new TestTrigger;
		
		but->AddTrigger(obs);
		return but;
	}
	return nullptr;
}
