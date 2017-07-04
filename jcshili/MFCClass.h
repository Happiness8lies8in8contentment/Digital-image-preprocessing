#pragma once


// MFCClass

class MFCClass : public CButton
{
	DECLARE_DYNAMIC(MFCClass)

public:
	MFCClass();
	virtual ~MFCClass();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
};


