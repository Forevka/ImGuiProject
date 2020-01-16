
#include "imgui.h"
#include <iostream>
#include <string>
#include <src/win32_directx11/TriggerComponent.cpp>

class BaseWidget
{
public:
	std::string widget_name;
	
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
