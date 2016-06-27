#include "pch_script.h"
#include "ScriptXmlInit.h"
#include "ui\UIXmlInit.h"
#include "ui\UITextureMaster.h"
#include "ui\UICheckButton.h" //#include "ui\UI3tButton.h"
#include "ui\UISpinNum.h"
#include "ui\UISpinText.h"
#include "ui\UIComboBox.h"
#include "ui\UIListWnd.h"
#include "ui\UITabControl.h"
#include "ui\UIFrameWindow.h"
#include "ui\UILabel.h"
#include "ui\ServerList.h"
#include "ui\UIMapList.h"
#include "ui\UIKeyBinding.h"
#include "ui\UIEditBox.h"
#include "ui\UIAnimatedStatic.h"
#include "ui\UITrackBar.h"
#include "ui\UICDkey.h"
#include "ui\UIMapInfo.h"
#include "ui\UIMMShniaga.h"
#include "ui\UIScrollView.h"
#include "ui\UIProgressBar.h"

using namespace luabind;

void _attach_child(CUIWindow* _child, CUIWindow* _parent)
{
	if(!_parent)	return;
	CUIScrollView* _parent_scroll = smart_cast<CUIScrollView*>(_parent);
	if(_parent_scroll)
		_parent_scroll->AddWindow	(_child, true);
	else
		_parent->AttachChild		(_child);
}
CScriptXmlInit::CScriptXmlInit(){

}

CScriptXmlInit::CScriptXmlInit(const CScriptXmlInit&){
	// do nothing
}

CScriptXmlInit& CScriptXmlInit::operator =(const CScriptXmlInit& other){
	// do nothing
	return (*this);
}

void CScriptXmlInit::ParseFile(LPCSTR xml_file){
	m_xml.Load(CONFIG_PATH, UI_PATH, xml_file);
}

void CScriptXmlInit::InitWindow(LPCSTR path, int index, CUIWindow* pWnd){
	CUIXmlInit::InitWindow(m_xml, path, index, pWnd);
}


CUIFrameWindow*	CScriptXmlInit::InitFrame(LPCSTR path, CUIWindow* parent){
	CUIFrameWindow* pWnd = new CUIFrameWindow();
	CUIXmlInit::InitFrameWindow(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}


CUIFrameLineWnd* CScriptXmlInit::InitFrameLine(LPCSTR path, CUIWindow* parent){
	CUIFrameLineWnd* pWnd = new CUIFrameLineWnd();
	CUIXmlInit::InitFrameLine(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}
/*
CUILabel* CScriptXmlInit::InitLabel(LPCSTR path, CUIWindow* parent){
	CUILabel* pWnd = new CUILabel();
	CUIXmlInit::InitLabel(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
	return pWnd;
}
*/

CUIEditBox* CScriptXmlInit::InitEditBox(LPCSTR path, CUIWindow* parent){
	CUIEditBox* pWnd = new CUIEditBox();
	CUIXmlInit::InitEditBox(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
	return pWnd;
}

CUIStatic* CScriptXmlInit::InitStatic(LPCSTR path, CUIWindow* parent){
	CUIStatic* pWnd = new CUIStatic();
	CUIXmlInit::InitStatic(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
	return pWnd;
}

void CScriptXmlInit::InitAutoStaticGroup(LPCSTR path, CUIWindow* pWnd)
{
	CUIXmlInit::InitAutoStaticGroup(m_xml, path, 0, pWnd);
}

CUIStatic* CScriptXmlInit::InitAnimStatic(LPCSTR path, CUIWindow* parent){
	CUIAnimatedStatic* pWnd = new CUIAnimatedStatic();
	CUIXmlInit::InitAnimatedStatic(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}

CUIScrollView* CScriptXmlInit::InitScrollView(LPCSTR path, CUIWindow* parent){
	CUIScrollView* pWnd = new CUIScrollView();
	CUIXmlInit::InitScrollView(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}



CUICheckButton* CScriptXmlInit::InitCheck(LPCSTR path, CUIWindow* parent){
	CUICheckButton* pWnd = new CUICheckButton();
	CUIXmlInit::InitCheck(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}

CUISpinNum* CScriptXmlInit::InitSpinNum(LPCSTR path, CUIWindow* parent){
	CUISpinNum* pWnd = new CUISpinNum();
	CUIXmlInit::InitSpin(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}

CUISpinFlt* CScriptXmlInit::InitSpinFlt(LPCSTR path, CUIWindow* parent){
	CUISpinFlt* pWnd = new CUISpinFlt();
	CUIXmlInit::InitSpin(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}

CUISpinText* CScriptXmlInit::InitSpinText(LPCSTR path, CUIWindow* parent){
	CUISpinText* pWnd = new CUISpinText();
	CUIXmlInit::InitSpin(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}

CUIComboBox* CScriptXmlInit::InitComboBox(LPCSTR path, CUIWindow* parent){
	CUIComboBox* pWnd = new CUIComboBox();
	CUIXmlInit::InitComboBox(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}

CUIButton* CScriptXmlInit::InitButton(LPCSTR path, CUIWindow* parent){
	CUIButton* pWnd = new CUIButton();
	CUIXmlInit::InitButton(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}


CUI3tButton* CScriptXmlInit::Init3tButton(LPCSTR path, CUIWindow* parent){
	CUI3tButton* pWnd = new CUI3tButton();
	CUIXmlInit::Init3tButton(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;	
}

CUI3tButtonEx* CScriptXmlInit::Init3tButtonEx(LPCSTR path, CUIWindow* parent){
	CUI3tButtonEx* pWnd = new CUI3tButtonEx();
	pWnd->SetAutoDelete(true);
	pWnd->init_from_xml(m_xml, path);
	_attach_child(pWnd, parent);
	return pWnd;	
}

CUIListWnd* CScriptXmlInit::InitList(LPCSTR path, CUIWindow* parent){
	CUIListWnd* pWnd = new CUIListWnd();
	CUIXmlInit::InitListWnd(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;
}


CUITabControl* CScriptXmlInit::InitTab(LPCSTR path, CUIWindow* parent){
	CUITabControl* pWnd = new CUITabControl();
	CUIXmlInit::InitTabControl(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;	
}


CServerList* CScriptXmlInit::InitServerList(LPCSTR path, CUIWindow* parent){
	CServerList* pWnd = new CServerList();
	pWnd->InitFromXml(m_xml, path);	
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;	
}

CUIMapList* CScriptXmlInit::InitMapList(LPCSTR path, CUIWindow* parent){
	CUIMapList* pWnd = new CUIMapList();
	pWnd->InitFromXml(m_xml, path);	
	pWnd->SetAutoDelete(true);
	_attach_child(pWnd, parent);
//.	if(parent) parent->AttachChild(pWnd);
	return pWnd;	
}

CUIMMShniaga* CScriptXmlInit::InitMMShniaga(LPCSTR path, CUIWindow* parent){
	CUIMMShniaga* pWnd	= new CUIMMShniaga();
	pWnd->InitShniaga	(m_xml, path);
	pWnd->SetAutoDelete	(true);
	_attach_child		(pWnd, parent);
	return pWnd;
}

CUIMapInfo* CScriptXmlInit::InitMapInfo(LPCSTR path, CUIWindow* parent){
	CUIMapInfo* pWnd	= new CUIMapInfo();
	CUIXmlInit::InitWindow(m_xml,path,0,pWnd);
	pWnd->InitMapInfo(pWnd->GetWndPos(),pWnd->GetWndSize());
	pWnd->SetAutoDelete	(true);
	_attach_child		(pWnd, parent);
	return pWnd;	
}

CUIWindow* CScriptXmlInit::InitKeyBinding(LPCSTR path, CUIWindow* parent){
	CUIKeyBinding* pWnd				= new CUIKeyBinding();
	pWnd->InitFromXml				(m_xml, path);	
	pWnd->SetAutoDelete				(true);
	_attach_child					(pWnd, parent);
	return							pWnd;
}

CUITrackBar* CScriptXmlInit::InitTrackBar(LPCSTR path, CUIWindow* parent){
	CUITrackBar* pWnd				= new CUITrackBar();
	CUIXmlInit::InitTrackBar		(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete				(true);
	_attach_child					(pWnd, parent);
	return							pWnd;	
}

CUIProgressBar* CScriptXmlInit::InitProgressBar(LPCSTR path, CUIWindow* parent)
{
	CUIProgressBar* pWnd			= new CUIProgressBar();
	CUIXmlInit::InitProgressBar		(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete				(true);
	_attach_child					(pWnd, parent);
	return							pWnd;	
}

CUIEditBox* CScriptXmlInit::InitCDkey(LPCSTR path, CUIWindow* parent){
	CUICDkey* pWnd					= new CUICDkey();
	CUIXmlInit::InitEditBox			(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete				(true);
	_attach_child					(pWnd, parent);
	pWnd->SetCurrentValue			();
	return							pWnd;	
}

CUIEditBox* CScriptXmlInit::InitMPPlayerName(LPCSTR path, CUIWindow* parent){
	CUIMPPlayerName* pWnd			= new CUIMPPlayerName();
	CUIXmlInit::InitEditBox			(m_xml, path, 0, pWnd);
	pWnd->SetAutoDelete				(true);
	_attach_child					(pWnd, parent);
	return							pWnd;	
}

#pragma optimize("s",on)
void CScriptXmlInit::script_register(lua_State *L){
	module(L)
	[
		class_<CScriptXmlInit>			("CScriptXmlInit")
		.def(							constructor<>())
		.def("ParseFile",				&CScriptXmlInit::ParseFile)
		.def("InitWindow",				&CScriptXmlInit::InitWindow)
		.def("InitFrame",				&CScriptXmlInit::InitFrame)
		.def("InitFrameLine",			&CScriptXmlInit::InitFrameLine)
//		.def("InitLabel",				&CScriptXmlInit::InitLabel)
		.def("InitEditBox",				&CScriptXmlInit::InitEditBox)		
		.def("InitStatic",				&CScriptXmlInit::InitStatic)
		.def("InitAnimStatic",			&CScriptXmlInit::InitAnimStatic)		
		.def("InitCheck",				&CScriptXmlInit::InitCheck)
		.def("InitSpinNum",				&CScriptXmlInit::InitSpinNum)
		.def("InitSpinFlt",				&CScriptXmlInit::InitSpinFlt)
		.def("InitSpinText",			&CScriptXmlInit::InitSpinText)
		.def("InitComboBox",			&CScriptXmlInit::InitComboBox)		
		.def("InitButton",				&CScriptXmlInit::InitButton)
		.def("Init3tButton",			&CScriptXmlInit::Init3tButtonEx) // Init3tButton
//		.def("Init3tButtonEx",			&CScriptXmlInit::Init3tButtonEx)
		.def("InitList",				&CScriptXmlInit::InitList)
		.def("InitTab",					&CScriptXmlInit::InitTab)
		.def("InitServerList",			&CScriptXmlInit::InitServerList)
		.def("InitMapList",				&CScriptXmlInit::InitMapList)
		.def("InitMapInfo",				&CScriptXmlInit::InitMapInfo)
		.def("InitTrackBar",			&CScriptXmlInit::InitTrackBar)
		.def("InitCDkey",				&CScriptXmlInit::InitCDkey)
		.def("InitMPPlayerName",		&CScriptXmlInit::InitMPPlayerName)
		.def("InitKeyBinding",			&CScriptXmlInit::InitKeyBinding)
		.def("InitMMShniaga",			&CScriptXmlInit::InitMMShniaga)
		.def("InitScrollView",			&CScriptXmlInit::InitScrollView)
		.def("InitAutoStaticGroup",		&CScriptXmlInit::InitAutoStaticGroup)
		.def("InitProgressBar",			&CScriptXmlInit::InitProgressBar)
	];

}