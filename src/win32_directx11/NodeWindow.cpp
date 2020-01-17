#include <src/win32_directx11/BaseWindow.cpp>

class NodeWindow: public BaseWindow
{
public:
	InputWrapper* textInput = nullptr;

	std::list<LinkWidget*> linkWidgets;
	
	NodeWindow(const float width, const float height, std::string name, int id) : BaseWindow(width, height, name, id)
	{
		textInput = new InputWrapper();
		linkWidgets.push_back(new LinkWidget());
		linkWidgets.push_back(new LinkWidget());
	}
	
	void Draw() override
	{
		if (isOpen)
		{
			ImGui::Begin(name);

			for (it = widgets.begin(); it != widgets.end(); it++)
			{
				(*it)->Draw();
			}

			textInput->Draw();
			
			/*ImVec2 p = ImGui::GetWindowPos();
			p.x += ImGui::GetWindowWidth();
			p.y += ImGui::GetWindowHeight() / 2;

			ImVec2 m = ImGui::GetMousePos();

			ImGui::BeginChild("Test");
			ImGui::GetOverlayDrawList()->AddLine(p, ImVec2(p.x + 500, p.y + 500), IM_COL32(255, 0, 0, 255), 3.0f);

			ImGui::GetOverlayDrawList()->AddBezierCurve(p, ImVec2(p.x, p.y), ImVec2(p.x, p.y + 32), m, IM_COL32(255, 0, 0, 255), 3.0f, 16);

			ImGui::EndChild();*/

			ImGui::NewLine();
			ImGui::Separator();

			for (auto& linkWidget : linkWidgets)
			{
				auto idName = fmt::format("linkWidget #{0}", linkWidget->myId);

				auto cstr = new char[idName.length() + 1];

				strcpy(cstr, idName.c_str());
				
				ImGui::BeginChild(cstr);
				linkWidget->Draw();
				ImGui::EndChild();
			}

			ImGui::End();
		}
	}
};