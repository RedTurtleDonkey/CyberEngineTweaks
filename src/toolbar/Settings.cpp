#include <stdafx.h>

#include "Settings.h"

#include "HelperWidgets.h"

#include <toolbar/Toolbar.h>

void Settings::OnEnable()
{
    Load();
    
    VKBindings::StopRecordingBind();
}

void Settings::OnDisable()
{
    VKBindings::StopRecordingBind();
}

void Settings::Update()
{
    if (ImGui::Button("Load"))
        Load();
    ImGui::SameLine();
    if (ImGui::Button("Save"))
        Save();
    ImGui::SameLine();
    if (ImGui::Button("Defaults"))
        ResetToDefaults();

    ImGui::Spacing();

    if (!Options::IsFirstLaunch)
        ImGui::BeginChild("##SETTINGS_ACTUAL", ImVec2(0,0), true);

    BindWidget(m_toolbarKeyBindInfo);
    if (Options::IsFirstLaunch && (m_toolbarKeyBindInfo.SavedCodeBind != m_toolbarKeyBindInfo.CodeBind))
    {
        Save();
        Load();
    }

    BoolWidget("Enable Debug Menu:", m_patchEnableDebug, Options::PatchEnableDebug);
    BoolWidget("Remove Pedestrians:", m_patchRemovePedestrians, Options::PatchRemovePedestrians);
    BoolWidget("Disable Async Compute:", m_patchAsyncCompute, Options::PatchAsyncCompute);
    BoolWidget("Disable Antialiasing:", m_patchAntialiasing, Options::PatchAntialiasing);
    BoolWidget("Skip Start Menu:", m_patchSkipStartMenu, Options::PatchSkipStartMenu);
    BoolWidget("Suppress Intro Movies:", m_patchDisableIntroMovies, Options::PatchDisableIntroMovies);
    BoolWidget("Disable Vignette:", m_patchDisableVignette, Options::PatchDisableVignette);
    BoolWidget("Disable Boundary Teleport:", m_patchDisableBoundaryTeleport, Options::PatchDisableBoundaryTeleport);
    BoolWidget("Disable V-Sync (Windows 7 only):", m_patchDisableWin7Vsync, Options::PatchDisableWin7Vsync);
    BoolWidget("Dump Game Options:", m_dumpGameOptions, Options::DumpGameOptions);

    if (!Options::IsFirstLaunch)
        ImGui::EndChild();
}

void Settings::Load()
{
    Options::Load();

    m_toolbarKeyBindInfo.Fill(Options::ToolbarKeyBind, Toolbar::VKBToolbar);
    m_patchEnableDebug = Options::PatchEnableDebug;
    m_patchRemovePedestrians = Options::PatchRemovePedestrians;
    m_patchAsyncCompute = Options::PatchAsyncCompute;
    m_patchAntialiasing = Options::PatchAntialiasing;
    m_patchSkipStartMenu = Options::PatchSkipStartMenu;
    m_patchDisableIntroMovies = Options::PatchDisableIntroMovies;
    m_patchDisableVignette = Options::PatchDisableVignette;
    m_patchDisableBoundaryTeleport = Options::PatchDisableBoundaryTeleport;
    m_patchDisableWin7Vsync = Options::PatchDisableWin7Vsync;
    m_dumpGameOptions = Options::DumpGameOptions;
}

void Settings::Save()
{
    Options::ToolbarKeyBind = m_toolbarKeyBindInfo.Apply();
    Options::PatchEnableDebug = m_patchEnableDebug;
    Options::PatchRemovePedestrians = m_patchRemovePedestrians;
    Options::PatchAsyncCompute = m_patchAsyncCompute;
    Options::PatchAntialiasing = m_patchAntialiasing;
    Options::PatchSkipStartMenu = m_patchSkipStartMenu;
    Options::PatchDisableIntroMovies = m_patchDisableIntroMovies;
    Options::PatchDisableVignette = m_patchDisableVignette;
    Options::PatchDisableBoundaryTeleport = m_patchDisableBoundaryTeleport;
    Options::PatchDisableWin7Vsync = m_patchDisableWin7Vsync;
    Options::DumpGameOptions = m_dumpGameOptions;

    Options::Save();
}

void Settings::ResetToDefaults()
{
    Options::ResetToDefaults();
    Load();
}
