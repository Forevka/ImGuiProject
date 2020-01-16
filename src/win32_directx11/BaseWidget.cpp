
#include "imgui.h"
#include <iostream>
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <string>
#include <utility>
#include <src\win32_directx11\ObservableBool.cpp>

class BaseWidget
{
public:
	std::string widgetName;

	static BaseWidget* MakeWidget(const std::string widget_name);

	virtual void Draw() = 0;
};

class TextWrapper: public BaseWidget
{
	void Draw()
	{
		ImGui::Text("TEST TEXT");
	}
};

class ButtonWrapper : public BaseWidget
{
public:
	//ObservableBool* test = new ObservableBool();
	std::vector<ObserverABC*> observers_ = std::vector<ObserverABC*>();
	
	void Draw()
	{
		if (ImGui::Button("Button test"))
		{
			this->raiseEvent();
		}
	}

	void addObserver(ObserverABC* observer) {
		observers_.push_back(observer);
	}

	void removeObserver(ObserverABC* observer) {
		auto a = std::find(observers_.begin(), observers_.end(), observer);
		observers_.erase(a);
	}
	
private:
	void raiseEvent() {
		for (int i = 0; i < observers_.size(); ++i) {
			observers_[i]->trigger();
		}
	}
};

inline BaseWidget* BaseWidget::MakeWidget(const std::string widget_name)
{
	if (widget_name == "Text")
	{
		return new TextWrapper;
	}
	
	if(widget_name == "Button")
	{
		ButtonWrapper* but = new ButtonWrapper();

		TestObserver* obs = new TestObserver;
		
		but->addObserver(obs);
		return but;
	}
}
