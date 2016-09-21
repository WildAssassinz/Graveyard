#pragma once

namespace SourceEngine {

	class IGameEvent {
	public:
		const char* GetName() {
			return CallVFunction<const char*(__thiscall *)(void*)>(this, 1)(this);
		}

		int GetInt(const char* szKeyName, int nDefault = 0) {
			return CallVFunction<int(__thiscall *)(void*, const char*, int)>(this, 6)(this, szKeyName, nDefault);
		}

		const char* GetString(const char* szKeyName) {
			return CallVFunction<const char*(__thiscall *)(void*, const char*, int)>(this, 9)(this, szKeyName, 0);
		}

		void SetString(const char* szKeyName, const char* szValue) {
			return CallVFunction<void(__thiscall *)(void*, const char*, const char*)>(this, 15)(this, szKeyName, szValue);
		}
	};

	class IGameEventManager2 {
	public:
		bool FireEventClientSide(IGameEvent* pEvent) {
			return CallVFunction<bool(__thiscall *)(void*, IGameEvent*)>(this, 8)(this, pEvent);
		}
	};
}
