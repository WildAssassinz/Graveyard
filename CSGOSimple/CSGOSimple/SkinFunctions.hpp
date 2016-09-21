#pragma once

#include "CSGOStructs.hpp"

struct EconomyItemConfig {
	int iItemDefinitionIndex = 0;
	int nFallbackPaintKit = 0;
	int nFallbackSeed = 0;
	int nFallbackStatTrak = -1;
	int iEntityQuality = 4;
	char* szCustomName = nullptr;
	float flFallbackWear = 0.1f;
};

std::unordered_map<int, EconomyItemConfig> g_SkinChangerCfg;
std::unordered_map<int, const char*> g_ViewModelCfg;
std::unordered_map<const char*, const char*> g_KillIconCfg;

class SkinFunctions {
public:
	static bool ApplyCustomSkin(C_BaseCombatWeapon* pWeapon, int nWeaponIndex) {
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

	static bool ApplyCustomModel(C_CSPlayer* pLocal, C_BaseCombatWeapon* pWeapon, int nWeaponIndex) {
		C_CBaseViewModel* pViewModel = pLocal->GetViewModel();

		if (!pViewModel)
			return false;

		DWORD hViewModelWeapon = pViewModel->GetWeapon();
		C_BaseCombatWeapon* pViewModelWeapon = (C_BaseCombatWeapon*)SourceEngine::Interfaces::EntityList()->GetClientEntityFromHandle(hViewModelWeapon);

		if (pViewModelWeapon != pWeapon)
			return false;

		int nViewModelIndex = pViewModel->GetModelIndex();

		if (g_ViewModelCfg.find(nViewModelIndex) == g_ViewModelCfg.end())
			return false;

		pViewModel->SetWeaponModel(g_ViewModelCfg[nViewModelIndex], pWeapon);

		return true;
	}

	static bool ApplyCustomKillIcon(SourceEngine::IGameEvent* pEvent) {
		// Get the user ID of the attacker.
		int nUserID = pEvent->GetInt("attacker");

		if (!nUserID)
			return false;

		// Only continue if we were the attacker.
		if (SourceEngine::Interfaces::Engine()->GetPlayerForUserID(nUserID) != SourceEngine::Interfaces::Engine()->GetLocalPlayer())
			return false;

		// Get the original weapon used to kill.
		const char* szWeapon = pEvent->GetString("weapon");

		for (auto ReplacementIcon : g_KillIconCfg) {
			// Search for a valid replacement.
			if (!strcmp(szWeapon, ReplacementIcon.first)) {
				// Replace with user defined value.
				pEvent->SetString("weapon", ReplacementIcon.second);
				break;
			}
		}

		return true;
	}
		
	static void SetSkinConfig() {
		using namespace SourceEngine;
		// StatTrak™ AWP | Dragon Lore
		g_SkinChangerCfg[WEAPON_AWP].nFallbackPaintKit = 344;
		g_SkinChangerCfg[WEAPON_AWP].flFallbackWear = 0.00000001f;
		g_SkinChangerCfg[WEAPON_AWP].nFallbackStatTrak = 1337;

		// Valve AK-47 | Redline
		g_SkinChangerCfg[WEAPON_AK47].nFallbackPaintKit = 282;
		g_SkinChangerCfg[WEAPON_AK47].iEntityQuality = 6;

		// Souvenir M4A4 | Howl
		g_SkinChangerCfg[WEAPON_M4A1].nFallbackPaintKit = 309;
		g_SkinChangerCfg[WEAPON_M4A1].iEntityQuality = 12;

		// Prototype Desert Eagle | Conspiracy
		g_SkinChangerCfg[WEAPON_DEAGLE].nFallbackPaintKit = 351;
		g_SkinChangerCfg[WEAPON_DEAGLE].iEntityQuality = 7;

		// Glock-18 | Fade
		g_SkinChangerCfg[WEAPON_GLOCK].nFallbackPaintKit = 38;

		// USP-S | Stainless
		g_SkinChangerCfg[WEAPON_USP_SILENCER].nFallbackPaintKit = 277;

		// Karambit | Fade (CT)
		g_SkinChangerCfg[WEAPON_KNIFE].iItemDefinitionIndex = WEAPON_KNIFE_KARAMBIT;
		g_SkinChangerCfg[WEAPON_KNIFE].nFallbackPaintKit = 38;
		g_SkinChangerCfg[WEAPON_KNIFE].iEntityQuality = 3;

		// Bowie Knife | Crimson Web (T)
		g_SkinChangerCfg[WEAPON_KNIFE_T].iItemDefinitionIndex = WEAPON_KNIFE_SURVIVAL_BOWIE;
		g_SkinChangerCfg[WEAPON_KNIFE_T].nFallbackPaintKit = 12;
		g_SkinChangerCfg[WEAPON_KNIFE_T].iEntityQuality = 3;
	}

	static void SetModelConfig() {
		using namespace SourceEngine;
		// Get the indexes of the models we want to replace.
		int nOriginalKnifeCT = Interfaces::ModelInfo()->GetModelIndex("models/weapons/v_knife_default_ct.mdl");
		int nOriginalKnifeT = Interfaces::ModelInfo()->GetModelIndex("models/weapons/v_knife_default_t.mdl");

		// Configure model replacements.
		g_ViewModelCfg[nOriginalKnifeCT] = "models/weapons/v_knife_karam.mdl";
		g_ViewModelCfg[nOriginalKnifeT] = "models/weapons/v_knife_survival_bowie.mdl";
	}

	static void SetKillIconCfg() {
		// Define replacement kill icons. (these only apply to you)
		g_KillIconCfg["knife_default_ct"] = "knife_karambit";
		g_KillIconCfg["knife_t"] = "knife_survival_bowie";
	}
};
