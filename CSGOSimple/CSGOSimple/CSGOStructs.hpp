#pragma once

#include <Windows.h>
#include "SourceEngine/SDK.hpp"
#include "NetvarManager.hpp"
#include "XorStr.hpp"

class C_CSPlayer;

class C_BaseCombatWeapon : public SourceEngine::IClientEntity {
     template<class T>
     inline T GetFieldValue(int offset) {
          return *(T*)((DWORD)this + offset);
     }
	 template<class T>
	 T* GetFieldPointer(int offset) {
		 return (T*)((DWORD)this + offset);
	 }
public:
     C_CSPlayer* GetOwner() {
          using namespace SourceEngine;
          static int m_hOwnerEntity = GET_NETVAR(XorStr("DT_BaseEntity"), XorStr("m_hOwnerEntity"));
          return (C_CSPlayer*)Interfaces::EntityList()->GetClientEntityFromHandle(GetFieldValue<CHandle<C_CSPlayer>>(m_hOwnerEntity));
     }
     float NextPrimaryAttack() {
          static int m_flNextPrimaryAttack = GET_NETVAR(XorStr("DT_BaseCombatWeapon"), XorStr("LocalActiveWeaponData"), XorStr("m_flNextPrimaryAttack"));
          return GetFieldValue<float>(m_flNextPrimaryAttack);
     }
     int GetId() {
          typedef int(__thiscall* tGetId)(void*);
          return SourceEngine::CallVFunction<tGetId>(this, 458)(this);
     }
     const char* GetName() {
          typedef const char* (__thiscall* tGetName)(void*);
          return SourceEngine::CallVFunction<tGetName>(this, 378)(this);
     }
	 int* GetViewModelIndex() {
		 static int m_iViewModelIndex = GET_NETVAR(XorStr("DT_BaseCombatWeapon"), XorStr("m_iViewModelIndex"));
		 return GetFieldPointer<int>(m_iViewModelIndex);
	 }
	 int* GetWorldModelIndex() {
		 static int m_iWorldModelIndex = GET_NETVAR(XorStr("DT_BaseCombatWeapon"), XorStr("m_iWorldModelIndex "));
		 return GetFieldPointer<int>(m_iWorldModelIndex);
	 }
	 int* GetItemDefinitionIndex() {
		 // DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iItemDefinitionIndex
		 static int m_iItemDefinitionIndex = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_AttributeManager"), XorStr("m_Item"), XorStr("m_iItemDefinitionIndex"));
		 return GetFieldPointer<int>(m_iItemDefinitionIndex);
	 }
	 int* GetItemIDHigh() {
		 // DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iItemIDHigh
		 static int m_iItemIDHigh = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_AttributeManager"), XorStr("m_Item"), XorStr("m_iItemIDHigh"));
		 return GetFieldPointer<int>(m_iItemIDHigh);
	 }
	 int* GetAccountID() {
		 // DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iAccountID
		 static int m_iAccountID = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_AttributeManager"), XorStr("m_Item"), XorStr("m_iAccountID"));
		 return GetFieldPointer<int>(m_iAccountID);
	 }
	 int* GetEntityQuality() {
		 // DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iEntityQuality
		 static int m_iEntityQuality = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_AttributeManager"), XorStr("m_Item"), XorStr("m_iEntityQuality"));
		 return GetFieldPointer<int>(m_iEntityQuality);

	 }
	 char* GetCustomName() {
		 // DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_szCustomName
		 static int m_szCustomName = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_AttributeManager"), XorStr("m_Item"), XorStr("m_szCustomName"));
		 return GetFieldPointer<char>(m_szCustomName);

	 }
	 int* GetOriginalOwnerXuidLow() {
		 // DT_BaseAttributableItem -> m_OriginalOwnerXuidLow
		 static int m_OriginalOwnerXuidLow = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_OriginalOwnerXuidLow"));
		 return GetFieldPointer<int>(m_OriginalOwnerXuidLow);

	 }
	 int* GetOriginalOwnerXuidHigh() {
		 // DT_BaseAttributableItem -> m_OriginalOwnerXuidHigh
		 static int m_OriginalOwnerXuidHigh = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_OriginalOwnerXuidHigh"));
		 return GetFieldPointer<int>(m_OriginalOwnerXuidHigh);

	 }
	 int* GetFallbackPaintKit() {
		 // DT_BaseAttributableItem -> m_nFallbackPaintKit
		 static int m_nFallbackPaintKit = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_nFallbackPaintKit"));
		 return GetFieldPointer<int>(m_nFallbackPaintKit);

	 }
	 int* GetFallbackSeed() {
		 // DT_BaseAttributableItem -> m_nFallbackSeed
		 static int m_nFallbackSeed = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_nFallbackSeed"));
		 return GetFieldPointer<int>(m_nFallbackSeed);

	 }
	 float* GetFallbackWear() {
		 // DT_BaseAttributableItem -> m_flFallbackWear
		 static int m_flFallbackWear = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_flFallbackWear"));
		 return GetFieldPointer<float>(m_flFallbackWear);

	 }
	 int* GetFallbackStatTrak() {
		 // DT_BaseAttributableItem -> m_nFallbackStatTrak
		 static int m_nFallbackStatTrak = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_nFallbackStatTrak"));
		 return GetFieldPointer<int>(m_nFallbackStatTrak);

	 }
};

class C_CBaseViewModel : public SourceEngine::IClientEntity {
	template<class T>
	inline T GetFieldValue(int offset) {
		return *(T*)((DWORD)this + offset);
	}

public:
	int GetModelIndex() {
		static int m_nModelIndex = GET_NETVAR(XorStr("DT_BaseViewModel"), XorStr("m_nModelIndex"));
		return GetFieldValue<int>(m_nModelIndex);
	}
	DWORD GetOwner() {
		static int m_hOwner = GET_NETVAR(XorStr("DT_BaseViewModel"), XorStr("m_hOwner"));
		return GetFieldValue<DWORD>(m_hOwner);
	}
	DWORD GetWeapon() {
		static int m_hWeapon = GET_NETVAR(XorStr("DT_BaseViewModel"), XorStr("m_hWeapon"));
		return GetFieldValue<DWORD>(m_hWeapon);
	}
	void SetWeaponModel(const char* Filename, IClientEntity* Weapon) {
		using namespace SourceEngine;
		typedef void(__thiscall* tSetWeaponModel)(void*, const char*, IClientEntity*);
		return CallVFunction<tSetWeaponModel>(this, 242)(this, Filename, Weapon);
	}
};

class C_CSPlayer : public SourceEngine::IClientEntity {
     template<class T>
     inline T GetFieldValue(int offset) {
          return *(T*)((DWORD)this + offset);
     }
     template<class T>
     T* GetFieldPointer(int offset) {
          return (T*)((DWORD)this + offset);
     }
public:
     static C_CSPlayer* GetLocalPlayer() {
          return (C_CSPlayer*)SourceEngine::Interfaces::EntityList()->GetClientEntity(SourceEngine::Interfaces::Engine()->GetLocalPlayer());
     }
     int GetHealth() {
          static int m_iHealth = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_iHealth"));
          return GetFieldValue<int>(m_iHealth);
     }
     bool IsAlive() {
          static int m_lifeState = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_lifeState"));
          return GetFieldValue<int>(m_lifeState) == 0;
     }
     int GetTeamNum() {
          static int m_iTeamNum = GET_NETVAR(XorStr("DT_BaseEntity"), XorStr("m_iTeamNum"));
          return GetFieldValue<int>(m_iTeamNum);
     }
     int GetFlags() {
          static int m_fFlags = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_fFlags"));
          return GetFieldValue<int>(m_fFlags);
     }
	 BYTE GetLifeState() {
		 static int m_lifeState = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_lifeState"));
		 return GetFieldValue<BYTE>(m_lifeState);
	 }
	 UINT* GetWeapons() {
		 static int m_hMyWeapons = GET_NETVAR(XorStr("DT_BaseCombatCharacter"), XorStr("m_hMyWeapons"));
		 return GetFieldPointer<UINT>(m_hMyWeapons);
	 }
     SourceEngine::Vector GetViewOffset() {
          static int m_vecViewOffset = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_vecViewOffset[0]"));
          return GetFieldValue<SourceEngine::Vector>(m_vecViewOffset);
     }
     SourceEngine::Vector GetOrigin() {
          static int m_vecOrigin = GET_NETVAR(XorStr("DT_BaseEntity"), XorStr("m_vecOrigin"));
          return GetFieldValue<SourceEngine::Vector>(m_vecOrigin);
     }
     SourceEngine::Vector GetEyePos() {
          return GetOrigin() + GetViewOffset();
     }
     SourceEngine::Vector* ViewPunch() {
          static int m_viewPunchAngle = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_Local"), XorStr("m_viewPunchAngle"));
          return GetFieldPointer<SourceEngine::Vector>(m_viewPunchAngle);
     }
     SourceEngine::Vector* AimPunch() {
          static int m_aimPunchAngle = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_Local"), XorStr("m_aimPunchAngle"));
          return GetFieldPointer<SourceEngine::Vector>(m_aimPunchAngle);
     }
	 C_CBaseViewModel* GetViewModel() {
		 using namespace SourceEngine;
		 static int m_hViewModel = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_hViewModel[0]"));
		 return (C_CBaseViewModel*)Interfaces::EntityList()->GetClientEntityFromHandle(GetFieldValue< CHandle<IClientEntity> >(m_hViewModel));
	 }
	 C_BaseCombatWeapon* GetWeapon() {
		using namespace SourceEngine;
		static int m_hActiveWeapon = GET_NETVAR(XorStr("DT_BaseCombatCharacter"), XorStr("m_hActiveWeapon"));
		return (C_BaseCombatWeapon*)Interfaces::EntityList()->GetClientEntityFromHandle(GetFieldValue< CHandle<IClientEntity> >(m_hActiveWeapon));
	 }
};