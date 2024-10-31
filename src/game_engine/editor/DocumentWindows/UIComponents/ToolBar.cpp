//// ToolBar.cpp //////////////////////////////////////////////////////////
//
//  zzzzz       zzz  zzzzzzzzzzzzz    zzzz      zzzz       zzzzzz  zzzzz
//  zzzzzzz     zzz  zzzz                    zzzz       zzzz           zzzz
//  zzz   zzz   zzz  zzzzzzzzzzzzz         zzzz        zzzz             zzz
//  zzz    zzz  zzz  z                  zzzz  zzzz      zzzz           zzzz
//  zzz         zzz  zzzzzzzzzzzzz    zzzz       zzz      zzzzzzz  zzzzz
//
//  Author:      Marie GIACOMEL
//  Date:        31/10/2024
//  Description: Components for the toolbar
//
///////////////////////////////////////////////////////////////////////////////


#include "imgui.h"
#include <editor/DocumentWindows/Main3DScene.hpp>


void engine::editor::Main3DScene::createPrimitivePopUp(const char *popup_name = "add_primitive")
{
    // pop up to create primitive
    if (ImGui::BeginPopup(popup_name))
    {
        auto primitives = this->getPrimitives();
        for (auto& primitive : primitives) {
            if (ImGui::MenuItem(primitive.first.c_str()))
                (this->*primitive.second)();
        }
        ImGui::EndPopup();
    }
}

void engine::editor::Main3DScene::rightClickMenu(const char *popup_name)
{
    if (ImGui::BeginPopup(popup_name))
    {
        if (ImGui::BeginMenu("  New...  "))
        {
            auto primitives = this->getPrimitives();
            for (auto& primitive : primitives) {
                if (ImGui::MenuItem(primitive.first.c_str())) {
                    (this->*primitive.second)();
                }
            }
            ImGui::EndMenu();
        }
        ImGui::MenuItem("  Save  ");
        ImGui::MenuItem("  Save as...  ");
        ImGui::MenuItem("  Import  ");
        ImGui::MenuItem("  Export  ");
        ImGui::MenuItem("  Settings  ");

        ImGui::EndPopup();
    }
}
