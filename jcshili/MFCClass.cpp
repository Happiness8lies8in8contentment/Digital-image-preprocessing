// MFCClass.cpp : 实现文件
//

#include "stdafx.h"
#include "jcshili.h"
#include "MFCClass.h"


// MFCClass

IMPLEMENT_DYNAMIC(MFCClass, CButton)

MFCClass::MFCClass()
{

}

MFCClass::~MFCClass()
{
}


BEGIN_MESSAGE_MAP(MFCClass, CButton)
END_MESSAGE_MAP()



// MFCClass 消息处理程序




void MFCClass::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: Add your code to draw the specified item
	UINT uStyle = DFCS_BUTTONPUSH;

	// This code only works with buttons.
	ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);

	// If drawing selected, add the pushed style to DrawFrameControl.
	if (lpDrawItemStruct->itemState & ODS_SELECTED)
		uStyle |= DFCS_PUSHED;

	// Draw the button frame.
	::DrawFrameControl(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem, 
		DFC_BUTTON, uStyle);

	// Get the button's text.
	CString strText;
	GetWindowText(strText);

	// Draw the button text using the text color red.
	COLORREF crOldColor = ::SetTextColor(lpDrawItemStruct->hDC, RGB(255,0,0));
	::DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(), 
		&lpDrawItemStruct->rcItem, DT_SINGLELINE|DT_VCENTER|DT_CENTER);
	::SetTextColor(lpDrawItemStruct->hDC, crOldColor);
}
