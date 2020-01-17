#include "imgui.h"
#include <list>
#include <src/win32_directx11/NodeWindow.cpp>

class MainController {
    std::list<BaseWindow*> textWindows;

public:
    void Update() {
		for (auto& window : textWindows)
		{
			window->Draw();
		}

    	if (ImGui::IsMouseClicked(ImGuiMouseButton_Right, false))
    	{
			AddNodeWindow();
    	}
    }

    /*bool AddNewWindow() {
	    auto baseWindow = new BaseWindow(200, 200, "New Window", textWindows.size());
    	
        baseWindow->AddWidget(BaseWidget::MakeWidget("Text"));
        baseWindow->AddWidget(BaseWidget::MakeWidget("Button"));
    	
        textWindows.push_front(baseWindow);

        return true;
    }*/

	void AddNodeWindow()
    {
		auto nodeWindow = new NodeWindow(200, 200, "New Window", textWindows.size());

		textWindows.push_front(nodeWindow);
    }
};
