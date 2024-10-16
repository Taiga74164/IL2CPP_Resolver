#pragma once

namespace Unity
{
	struct TimeFunctions_t
	{
		void* m_GetDeltaTime = nullptr;
		void* m_GetFixedDeltaTime = nullptr;
		void* m_GetTime = nullptr;
		void* m_GetFixedTime = nullptr;
		void* m_GetTimeScale = nullptr;
		void* m_SetTimeScale = nullptr;
	};
	TimeFunctions_t m_TimeFunctions;

	class CTime : public IL2CPP::CClass
	{
	public:
		float GetDeltaTime()
		{
			return reinterpret_cast<CTime*(UNITY_CALLING_CONVENTION)(void*)>(m_TimeFunctions.m_GetDeltaTime)(this);
		}

		float GetFixedDeltaTime()
		{
			return reinterpret_cast<CTime*(UNITY_CALLING_CONVENTION)(void*)>(m_TimeFunctions.m_GetFixedDeltaTime)(this);
		}

		float GetTime()
		{
			return reinterpret_cast<CTime*(UNITY_CALLING_CONVENTION)(void*)>(m_TimeFunctions.m_GetTime)(this);
		}

		float GetFixedTime()
		{
			return reinterpret_cast<CTime*(UNITY_CALLING_CONVENTION)(void*)>(m_TimeFunctions.m_GetFixedTime)(this);
		}

		float GetTimeScale()
		{
			return reinterpret_cast<CTime*(UNITY_CALLING_CONVENTION)(void*)>(m_TimeFunctions.m_GetTimeScale)(this);
		}

		void SetTimeScale(float m_fValue)
		{
			return reinterpret_cast<CTime*(UNITY_CALLING_CONVENTION)(void*, float)>(m_TimeFunctions.m_SetTimeScale)(this, m_fValue);
		}
	};

	namespace Time
	{
		void Initialize()
		{
			IL2CPP::SystemTypeCache::Initializer::Add(UNITY_TIME_CLASS);

			m_TimeFunctions.m_GetDeltaTime 		= IL2CPP::ResolveCall(UNITY_TIME_GETDELTATIME);
			m_TimeFunctions.m_GetFixedDeltaTime = IL2CPP::ResolveCall(UNITY_TIME_GETFIXEDDELTATIME);
			m_TimeFunctions.m_GetTime 			= IL2CPP::ResolveCall(UNITY_TIME_GETTIME);
			m_TimeFunctions.m_GetFixedTime 		= IL2CPP::ResolveCall(UNITY_TIME_GETFIXEDTIME);
			m_TimeFunctions.m_GetTimeScale 		= IL2CPP::ResolveCall(UNITY_TIME_GETTIMESCALE);
			m_TimeFunctions.m_SetTimeScale 		= IL2CPP::ResolveCall(UNITY_TIME_SETTIMESCALE);
		}
	}
}