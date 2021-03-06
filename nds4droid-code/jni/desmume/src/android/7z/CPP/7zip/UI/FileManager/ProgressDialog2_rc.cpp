// ProgressDialog2_rc.cpp

#include "StdAfx.h"

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
 
#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "ProgressDialog2Res.h"

#include "Windows/Control/DialogImpl.h"

/*
IDD_DIALOG_PROGRESS  DIALOG  0, 0, xSize, ySize  MY_MODAL_DIALOG_STYLE | WS_MINIMIZEBOX 
CAPTION "Progress"
MY_FONT
BEGIN
  PUSHBUTTON  "&Background", IDC_BUTTON_PROGRESS_PRIORITY,  bXPos3, bYPos, bXSize, bYSize
  PUSHBUTTON  "&Pause",      IDC_BUTTON_PAUSE,              bXPos2, bYPos, bXSize, bYSize
  PUSHBUTTON  "Cancel",      IDCANCEL,                      bXPos1, bYPos, bXSize, bYSize
  LTEXT  "Elapsed time:",   IDC_PROGRESS_ELAPSED,   marg, y0, x0Size, 8
  LTEXT  "Remaining time:", IDC_PROGRESS_REMAINING, marg, y1, x0Size, 8
  LTEXT  "Files:",          IDC_PROGRESS_FILES,     marg, y2, x0Size, 8
  LTEXT  "Compression ratio:",IDC_PROGRESS_RATIO,   marg, y3, x0Size, 8

  LTEXT  "Total size:",      IDC_PROGRESS_TOTAL,    x2, y0, x2Size, 8
  LTEXT  "Speed:",           IDC_PROGRESS_SPEED,    x2, y1, x2Size, 8
  LTEXT  "Processed:",       IDC_PROGRESS_UNPACKED, x2, y2, x2Size, 8
  LTEXT  "Compressed size:", IDC_PROGRESS_PACKED,   x2, y3, x2Size, 8

  RTEXT  "00:00:00",  IDC_PROGRESS_ELAPSED_VALUE,     x1, y0, x1Size, 8
  RTEXT  "",          IDC_PROGRESS_REMAINING_VALUE,   x1, y1, x1Size, 8
  RTEXT  "",          IDC_PROGRESS_FILES_VALUE,       x1, y2, x1Size, 8
  RTEXT  "",          IDC_PROGRESS_RATIO_VALUE,       x1, y3, x1Size, 8

  RTEXT  "",          IDC_PROGRESS_TOTAL_VALUE,       x3, y0, x3Size, 8
  RTEXT  "",          IDC_PROGRESS_SPEED_VALUE,       x3, y1, x3Size, 8
  RTEXT  "",          IDC_PROGRESS_UNPACKED_VALUE,    x3, y2, x3Size, 8
  RTEXT  "",          IDC_PROGRESS_PACKED_VALUE,      x3, y3, x3Size, 8

  LTEXT  "", IDC_PROGRESS_FILE_NAME, marg, bYPos - 30, xSize2, 8, SS_NOPREFIX
  CONTROL "Progress1", IDC_PROGRESS1, "msctls_progress32", PBS_SMOOTH | WS_BORDER, marg, bYPos - 20, xSize2, 13
END


STRINGTABLE DISCARDABLE 
BEGIN
  IDS_PROGRESS_PAUSED     "Paused"
  IDS_PROGRESS_FOREGROUND "&Foreground"
  IDS_PROGRESS_CONTINUE   "&Continue"
  IDS_PROGRESS_ASK_CANCEL "Are you sure you want to cancel?"
END

*/
class CProgressDialogImpl : public NWindows::NControl::CModalDialogImpl
{
  public:
   CProgressDialogImpl(NWindows::NControl::CModalDialog *dialog,wxWindow * parent , int id) : CModalDialogImpl(dialog,parent, id, wxT("Progress"))
  {
// FIXME : ProgressDialog2 but ProgressDialog ...

	///Sizer for adding the controls created by users
	wxBoxSizer* topsizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText *pStaticTextElapsedTime = new wxStaticText(this, IDC_PROGRESS_ELAPSED, wxT("Elapsed time:"));
	wxStaticText *m_pStaticTextElapsedTime = new wxStaticText(this, IDC_PROGRESS_ELAPSED_VALUE, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	wxStaticText *pStaticTextRemainingTime = new wxStaticText(this, IDC_PROGRESS_REMAINING, wxT("Remaining time"));
	wxStaticText *m_pStaticTextRemainingTime = new wxStaticText(this, IDC_PROGRESS_REMAINING_VALUE, wxT("00:00:00"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);

	wxStaticText *pStaticTextFiles = new wxStaticText(this, IDC_PROGRESS_FILES, wxT("Files:"));
	wxStaticText *m_pStaticTextFiles = new wxStaticText(this, IDC_PROGRESS_FILES_VALUE, wxT("      "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);

	wxStaticText *pStaticTextRatio = new wxStaticText(this, IDC_PROGRESS_RATIO, wxT("Compression ratio:"));
	wxStaticText *m_pStaticTextRatio = new wxStaticText(this, IDC_PROGRESS_RATIO_VALUE, wxT("       "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);


	wxStaticText *pStaticTextSize = new wxStaticText(this, IDC_PROGRESS_TOTAL, wxT("Total Size:"));
	wxStaticText *m_pStaticTextSize = new wxStaticText(this, IDC_PROGRESS_TOTAL_VALUE, wxT("          "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	wxStaticText *pStaticTextSpeed = new wxStaticText(this, IDC_PROGRESS_SPEED, wxT("Speed:"));
	wxStaticText *m_pStaticTextSpeed = new wxStaticText(this, IDC_PROGRESS_SPEED_VALUE, wxT("          "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);

	wxStaticText *pStaticTextUnpacked = new wxStaticText(this, IDC_PROGRESS_UNPACKED, wxT("Processed:"));
	wxStaticText *m_pStaticTextUnpacked = new wxStaticText(this, IDC_PROGRESS_UNPACKED, wxT("          "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	
	wxStaticText *pStaticTextPacked = new wxStaticText(this, IDC_PROGRESS_PACKED, wxT("Compressed size:"));
	wxStaticText *m_pStaticTextPacked = new wxStaticText(this, IDC_PROGRESS_PACKED_VALUE, wxT("          "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);

	wxBoxSizer *pInfoSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *pTimeSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *pTimeLabelSizer = new wxBoxSizer(wxVERTICAL);
	pTimeLabelSizer->Add(pStaticTextElapsedTime  , 0, wxALL|wxEXPAND, 5);
	pTimeLabelSizer->Add(pStaticTextRemainingTime, 0, wxALL|wxEXPAND, 5);
	pTimeLabelSizer->Add(pStaticTextFiles        , 0, wxALL|wxEXPAND, 5);
	pTimeLabelSizer->Add(pStaticTextRatio        , 0, wxALL|wxEXPAND, 5);
	wxBoxSizer *pTimeInfoSizer = new wxBoxSizer(wxVERTICAL);
	pTimeInfoSizer->Add(m_pStaticTextElapsedTime  , 0, wxALL|wxEXPAND, 5);
	pTimeInfoSizer->Add(m_pStaticTextRemainingTime, 0, wxALL|wxEXPAND, 5);
	pTimeInfoSizer->Add(m_pStaticTextFiles        , 0, wxALL|wxEXPAND, 5);
	pTimeInfoSizer->Add(m_pStaticTextRatio        , 0, wxALL|wxEXPAND, 5);
	pTimeSizer->Add(pTimeLabelSizer               , 0, wxALL|wxEXPAND, 5);
	pTimeSizer->Add(pTimeInfoSizer                , 0, wxALL|wxEXPAND, 5);
	wxBoxSizer *pSizeSpeedSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *pSizeSpeedLabelSizer = new wxBoxSizer(wxVERTICAL);
	pSizeSpeedLabelSizer->Add(pStaticTextSize     , 0, wxALL|wxEXPAND, 5);
	pSizeSpeedLabelSizer->Add(pStaticTextSpeed    , 0, wxALL|wxEXPAND, 5);
	pSizeSpeedLabelSizer->Add(pStaticTextUnpacked , 0, wxALL|wxEXPAND, 5);
	pSizeSpeedLabelSizer->Add(pStaticTextPacked   , 0, wxALL|wxEXPAND, 5);

	wxBoxSizer *pSizeSpeedInfoSizer = new wxBoxSizer(wxVERTICAL);
	pSizeSpeedInfoSizer->Add(m_pStaticTextSize    , 0, wxALL|wxEXPAND, 5);
	pSizeSpeedInfoSizer->Add(m_pStaticTextSpeed   , 0, wxALL|wxEXPAND, 5);
	pSizeSpeedInfoSizer->Add(m_pStaticTextUnpacked, 0, wxALL|wxEXPAND, 5);
	pSizeSpeedInfoSizer->Add(m_pStaticTextPacked  , 0, wxALL|wxEXPAND, 5);

	pSizeSpeedSizer->Add(pSizeSpeedLabelSizer, 1, wxALL|wxEXPAND, 5);
	pSizeSpeedSizer->Add(pSizeSpeedInfoSizer, 1, wxALL|wxEXPAND, 5);
	pInfoSizer->Add(pTimeSizer, 0, wxALL|wxEXPAND, 5);
	pInfoSizer->Add(pSizeSpeedSizer, 0, wxALL|wxEXPAND, 5);

	wxStaticText *m_pStaticArchiveName = new wxStaticText(this, IDC_PROGRESS_FILE_NAME, wxT(" \n "));
	wxGauge *m_pGaugeProgress = new wxGauge(this, IDC_PROGRESS1, 100);

	wxBoxSizer *pButtonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxButton *m_pButtonBackground = new wxButton(this, IDC_BUTTON_PROGRESS_PRIORITY, wxT("&Background"));
	wxButton *m_pButtonPause = new wxButton(this, IDC_BUTTON_PAUSE, wxT("&Pause"));
	wxButton *m_pButtonCancel = new wxButton(this, wxID_CANCEL, wxT("&Cancel"));
	// FIXME pButtonSizer->AddStretchSpacer(1);
	pButtonSizer->Add(m_pButtonBackground, 0, wxALL|wxEXPAND, 5);
	pButtonSizer->Add(m_pButtonPause, 0, wxALL|wxEXPAND, 5);
	pButtonSizer->Add(m_pButtonCancel, 0, wxALL|wxEXPAND, 5);

	topsizer->Add(pInfoSizer, 0, wxBOTTOM|wxEXPAND, 5);
	topsizer->Add(m_pStaticArchiveName, 0, wxLEFT|wxRIGHT|wxEXPAND, 10);
	topsizer->Add(m_pGaugeProgress, 0, wxALL|wxEXPAND, 10);
	topsizer->Add(pButtonSizer, 0, wxALL|wxEXPAND, 5);

	this->OnInit();

	SetSizer(topsizer); // use the sizer for layout
	topsizer->SetSizeHints(this); // set size hints to honour minimum size
  }
private:
	// Any class wishing to process wxWindows events must use this macro
	DECLARE_EVENT_TABLE()
};

static CStringTable g_stringTable[] =
{
	{ IDS_PROGRESS_PAUSED     , L"Paused" },
	{ IDS_PROGRESS_FOREGROUND , L"&Foreground" },
	{ IDS_PROGRESS_CONTINUE   , L"&Continue" },
	{ IDS_PROGRESS_ASK_CANCEL , L"Are you sure you want to cancel?" },
	{ 0 , 0 }
};

REGISTER_DIALOG(IDD_DIALOG_PROGRESS,CProgressDialog,g_stringTable)

BEGIN_EVENT_TABLE(CProgressDialogImpl, wxDialog)
	EVT_TIMER(wxID_ANY, CModalDialogImpl::OnAnyTimer)
	EVT_BUTTON(wxID_ANY, CModalDialogImpl::OnAnyButton)
END_EVENT_TABLE()

