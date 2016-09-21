#include "SkinFunctions.hpp"

bool SkinFunctions::ApplyCustomSkin(C_CBaseAttributableItem* pWeapon, int nWeaponIndex) {
	// Check if this weapon has a valid override defined.
	if (g_SkinChangerCfg.find(nWeaponIndex) == g_SkinChangerCfg.end())
		return false;

	// Apply our changes to the fallback variables.
	*pWeapon->GetFallbackPaintKit() = g_SkinChangerCfg[nWeaponIndex].nFallbackPaintKit;
	*pWeapon->GetEntityQuality() = g_SkinChangerCfg[nWeaponIndex].iEntityQuality;
	*pWeapon->GetFallbackSeed() = g_SkinChangerCfg[nWeaponIndex].nFallbackSeed;
	*pWeapon->GetFallbackStatTrak() = g_SkinChangerCfg[nWeaponIndex].nFallbackStatTrak;
	*pWeapon->GetFallbackWear() = g_SkinChangerCfg[nWeaponIndex].flFallbackWear;

	if (g_SkinChangerCfg[nWeaponIndex].iItemDefinitionIndex)
		*pWeapon->GetItemDefinitionIndex() = g_SkinChangerCfg[nWeaponIndex].iItemDefinitionIndex;

	// If a name is defined, write it now.
	if (g_SkinChangerCfg[nWeaponIndex].szCustomName) {
		sprintf_s(pWeapon->GetCustomName(), 32, "%s", g_SkinChangerCfg[nWeaponIndex].szCustomName);
	}

	// Edit "m_iItemIDHigh" so fallback values will be used.
	*pWeapon->GetItemIDHigh() = -1;

	return true;
}

bool SkinFunctions::ApplyCustomModel(C_CSPlayer* pLocal, C_CBaseAttributableItem* pWeapon, int nWeaponIndex) {
	C_CBaseViewModel* pViewModel = pLocal->GetViewModel();

	if (!pViewModel)
		return false;

	int nViewModelIndex = pViewModel->GetModelIndex();

	if (g_ViewModelCfg.find(nViewModelIndex) == g_ViewModelCfg.end())
		return false;

	pViewModel->SetWeaponModel(g_ViewModelCfg[nViewModelIndex], pWeapon);
}

void SkinFunctions::SetSkinConfig() {
	using namespace SourceEngine;
	// StatTrak™ AWP | Dragon Lore
	g_SkinChangerCfg[weapon_awp].nFallbackPaintKit = 344;
	g_SkinChangerCfg[weapon_awp].flFallbackWear = 0.00000001f;
	g_SkinChangerCfg[weapon_awp].nFallbackStatTrak = 1337;

	// Valve AK-47 | Redline
	g_SkinChangerCfg[weapon_ak47].nFallbackPaintKit = 282;
	g_SkinChangerCfg[weapon_ak47].iEntityQuality = 6;

	// Souvenir M4A4 | Howl
	g_SkinChangerCfg[weapon_m4a1].nFallbackPaintKit = 309;
	g_SkinChangerCfg[weapon_m4a1].iEntityQuality = 12;

	// Prototype Desert Eagle | Conspiracy
	g_SkinChangerCfg[weapon_deagle].nFallbackPaintKit = 351;
	g_SkinChangerCfg[weapon_deagle].iEntityQuality = 7;

	// Glock-18 | Fade
	g_SkinChangerCfg[weapon_glock].nFallbackPaintKit = 38;

	// USP-S | Stainless
	g_SkinChangerCfg[weapon_usp_silencer].nFallbackPaintKit = 277;

	// Karambit | Fade (CT)
	g_SkinChangerCfg[weapon_knife].iItemDefinitionIndex = weapon_knife_karambit;
	g_SkinChangerCfg[weapon_knife].nFallbackPaintKit = 38;
	g_SkinChangerCfg[weapon_knife].iEntityQuality = 3;

	// Bowie Knife | Crimson Web (T)
	g_SkinChangerCfg[weapon_knife_t].iItemDefinitionIndex = weapon_knife_survival_bowie;
	g_SkinChangerCfg[weapon_knife_t].nFallbackPaintKit = 12;
	g_SkinChangerCfg[weapon_knife_t].iEntityQuality = 3;
}

void SkinFunctions::SetModelConfig() {
	using namespace SourceEngine;
	// Get the indexes of the models we want to replace.
	int nOriginalKnifeCT = Interfaces::ModelInfo()->GetModelIndex("models/weapons/v_knife_default_ct.mdl");
	int nOriginalKnifeT = Interfaces::ModelInfo()->GetModelIndex("models/weapons/v_knife_default_t.mdl");

	// Configure model replacements.
	g_ViewModelCfg[nOriginalKnifeCT] = "models/weapons/v_knife_karam.mdl";
	g_ViewModelCfg[nOriginalKnifeT] = "models/weapons/v_knife_survival_bowie.mdl";
}