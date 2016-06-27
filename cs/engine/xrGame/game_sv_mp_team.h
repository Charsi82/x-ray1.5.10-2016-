#pragma once


// ������ ���� ������ ��������
using TEAM_SKINS_NAMES = xr_vector<xr_string>;
using TEAM_SKINS_NAMES_it = TEAM_SKINS_NAMES::iterator;	

// ������ ���� ������ ��������
using DEF_ITEMS_LIST = xr_vector<u16>;
using DEF_ITEMS_LIST_it = DEF_ITEMS_LIST::iterator;	

//��������� ������ �� �������
struct		TeamStruct
{
	shared_str			caSection;		// ��� ������ ��������
	TEAM_SKINS_NAMES	aSkins;			// ������ ������ ��� �������
	DEF_ITEMS_LIST		aDefaultItems;	// ������ ��������� �� ���������

	//---- Money -------------------
	s32					m_iM_Start			;
	s32					m_iM_OnRespawn		;
	s32					m_iM_Min			;
	
	s32					m_iM_KillRival		;
	s32					m_iM_KillSelf		;
	s32					m_iM_KillTeam		;

	s32					m_iM_TargetRival	;
	s32					m_iM_TargetTeam		;
	s32					m_iM_TargetSucceed	;
	s32					m_iM_TargetSucceedAll	;
	s32					m_iM_TargetFailed	;

	s32					m_iM_RoundWin		;
	s32					m_iM_RoundLoose		;
	s32					m_iM_RoundDraw		;		

	s32					m_iM_RoundWin_Minor		;
	s32					m_iM_RoundLoose_Minor	;
	s32					m_iM_RivalsWipedOut		;
	//---------------------------------------------
	s32					m_iM_ClearRunBonus		;
	//---------------------------------------------
	float				m_fInvinsibleKillModifier;

};

//������ ������ �� ��������
using TEAM_DATA_LIST = xr_deque<TeamStruct>;
using TEAM_DATA_LIST_it = TEAM_DATA_LIST::iterator;



