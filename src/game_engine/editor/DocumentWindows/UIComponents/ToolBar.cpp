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

using PrimitiveFunction = void (engine::editor::Main3DScene::*)();



void engine::editor::Main3DScene::createPrimitivePopUp(const char *popup_name = "add_primitive")
{
    static bool chose_primitive = false;

    // pop up to create primitive
    if (ImGui::BeginPopup(popup_name))
    {
        const char* primitives_names[] = { "  Cube  ", "  Plan  ", "  Sphere  ",\
            "  Cylinder  ", "  Cone  ", "  Polygon  ", "  Torus  ", "  Knot  ",\
            "  Hemisphere  " };
        constexpr PrimitiveFunction add_primitive_fct[] = {
            &Main3DScene::add_cube,
            &Main3DScene::add_plan,
            &Main3DScene::add_sphere,
            &Main3DScene::add_cylinder,
            &Main3DScene::add_cone,
            &Main3DScene::add_polygon,
            &Main3DScene::add_torus,
            &Main3DScene::add_knot,
            &Main3DScene::add_hemisphere
        };
        for (int i = 0; i < IM_ARRAYSIZE(primitives_names); i++)
            if (ImGui::Selectable(primitives_names[i], &chose_primitive))
                (this->*add_primitive_fct[i])();
        ImGui::EndPopup();
    }
}

void engine::editor::Main3DScene::rightClickMenu(const char *popup_name)
{
    if (ImGui::BeginPopup(popup_name))
    {
        if (ImGui::BeginMenu("  New...  "))
        {
            const char* primitives_names[] = { "  Cube  ", "  Plan  ", "  Sphere  ",\
                "  Cylinder  ", "  Cone  ", "  Polygon  ", "  Torus  ", "  Knot  ",\
                "  Hemisphere  " };
            constexpr PrimitiveFunction add_primitive_fct[] = {
                &Main3DScene::add_cube,
                &Main3DScene::add_plan,
                &Main3DScene::add_sphere,
                &Main3DScene::add_cylinder,
                &Main3DScene::add_cone,
                &Main3DScene::add_polygon,
                &Main3DScene::add_torus,
                &Main3DScene::add_knot,
                &Main3DScene::add_hemisphere
            };
            for (int i = 0; i < IM_ARRAYSIZE(primitives_names); i++)
                if (ImGui::MenuItem(primitives_names[i]))
                    (this->*add_primitive_fct[i])();
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
