#pragma once

#include "Image.h"

struct Paths;

struct Options
{
    Options(Paths& aPaths);
    ~Options() = default;

    void Load();
    void Save();
    void ResetToDefaults();

    Image GameImage;
    bool PatchEnableDebug{ false };
    bool PatchRemovePedestrians{ false };
    bool PatchAsyncCompute{ false };
    bool PatchAntialiasing{ false };
    bool PatchSkipStartMenu{ false };
    bool PatchAmdSmt{ false };
    bool PatchDisableIntroMovies{ false };
    bool PatchDisableVignette{ false };
    bool PatchDisableBoundaryTeleport{ false };
    bool PatchDisableWin7Vsync{ false };
    bool PatchMinimapFlicker{ false };
    bool DumpGameOptions{ false };
    std::string FontPath{ };
    std::string FontGlyphRanges{"Default"};
    float FontSizeBase{ 18.0f };
    int32_t FontOversampleHorizontal{ 3 };
    int32_t FontOversampleVertical{ 1 };
    bool ExeValid{ false };
    bool RemoveDeadBindings{ true };
    bool DrawImGuiDiagnosticWindow{ false };
    bool EnableImGuiAssertionsLogging{ false };

private:

    Paths& m_paths;
};