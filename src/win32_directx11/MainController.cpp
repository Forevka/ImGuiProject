#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <list>
#include <src\win32_directx11\BaseWindow.cpp>

class MainController {
private:
    std::list<BaseWindow*> textWindows;
    std::list<BaseWindow*>::iterator it;

public:
    void Update() {
        for (it = textWindows.begin(); it != textWindows.end(); it++)
        {
            (*it)->Draw();
        }
    }

    bool AddNewWindow() {
        BaseWindow* baseWindow = new BaseWindow(200, 200, "New Window", textWindows.size());
        baseWindow->Initialize();
    	
        baseWindow->AddWidget(BaseWidget::MakeWidget("Text"));
        baseWindow->AddWidget(BaseWidget::MakeWidget("Button"));
    	
        textWindows.push_front(baseWindow);

        return true;
    }
};
