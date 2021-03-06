#include "SettingsFrame.h"
#include "Settings.h"

//(*InternalHeaders(SettingsFrame)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SettingsFrame)
const long SettingsFrame::ID_STATICBOX8 = wxNewId();
const long SettingsFrame::ID_CHK_LOAD_LAST_SAVEGAME = wxNewId();
const long SettingsFrame::ID_STATICBOX9 = wxNewId();
const long SettingsFrame::ID_CHK_BACKUP_SAVEGAME = wxNewId();
const long SettingsFrame::ID_TAP_GENERAL = wxNewId();
const long SettingsFrame::ID_STATICBOX2 = wxNewId();
const long SettingsFrame::ID_LANGLIST = wxNewId();
const long SettingsFrame::ID_STATICBOX3 = wxNewId();
const long SettingsFrame::ID_STATICTEXT2 = wxNewId();
const long SettingsFrame::ID_BTN_SETLANG = wxNewId();
const long SettingsFrame::ID_TAP_LANG = wxNewId();
const long SettingsFrame::ID_STATICBOX1 = wxNewId();
const long SettingsFrame::ID_BTN_RESETUI = wxNewId();
const long SettingsFrame::ID_STATICTEXT1 = wxNewId();
const long SettingsFrame::ID_TAP_UI = wxNewId();
const long SettingsFrame::ID_TAP_SHORTCUT = wxNewId();
const long SettingsFrame::ID_STATICBOX5 = wxNewId();
const long SettingsFrame::ID_STATICBOX4 = wxNewId();
const long SettingsFrame::ID_TXTCTRL_FS11InstallPath = wxNewId();
const long SettingsFrame::ID_BTN_FS11InstallPath = wxNewId();
const long SettingsFrame::ID_BTN_FS11SavePath = wxNewId();
const long SettingsFrame::ID_TXTCTRL_FS11SavePath = wxNewId();
const long SettingsFrame::ID_CHKBOX_FS11Enabled = wxNewId();
const long SettingsFrame::ID_BTN_FS11AutoDetect = wxNewId();
const long SettingsFrame::ID_TAP_FS2011 = wxNewId();
const long SettingsFrame::ID_STATICBOX7 = wxNewId();
const long SettingsFrame::ID_CHKBOX_FS13Enabled = wxNewId();
const long SettingsFrame::ID_STATICBOX6 = wxNewId();
const long SettingsFrame::ID_TXTCTRL_FS13SavePath = wxNewId();
const long SettingsFrame::ID_TXTCTRL_FS13InstallPath = wxNewId();
const long SettingsFrame::ID_BTN_FS13SavePath = wxNewId();
const long SettingsFrame::ID_BTN_FS13InstallPath = wxNewId();
const long SettingsFrame::ID_BTN_FS13AutoDetect = wxNewId();
const long SettingsFrame::ID_TAP_FS2013 = wxNewId();
const long SettingsFrame::ID_SETTINGSTAPS = wxNewId();
const long SettingsFrame::ID_BTN_Close = wxNewId();
const long SettingsFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SettingsFrame,wxFrame)
	//(*EventTable(SettingsFrame)
	//*)
END_EVENT_TABLE()

SettingsFrame::SettingsFrame(Settings *conf, wxAuiManager *m_mgr, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    // Setup variables
    setup = conf;
    AuiMan = m_mgr;
    langList.fileNames.Clear();
    langList.identifiers.Clear();
    langList.names.Clear();



	//(*Initialize(SettingsFrame)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, _("Settings"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxCAPTION, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	SettingsTaps = new wxNotebook(this, ID_SETTINGSTAPS, wxDefaultPosition, wxSize(360,240), 0, _T("ID_SETTINGSTAPS"));
	SettingsTaps->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
	GeneralSettings = new wxPanel(SettingsTaps, ID_TAP_GENERAL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TAP_GENERAL"));
	GeneralSettings->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
	StaticBox8 = new wxStaticBox(GeneralSettings, ID_STATICBOX8, _("On Program Start"), wxPoint(8,8), wxSize(336,48), 0, _T("ID_STATICBOX8"));
	ChkLoadLastSavegame = new wxCheckBox(GeneralSettings, ID_CHK_LOAD_LAST_SAVEGAME, _("Load Last Savegame"), wxPoint(16,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHK_LOAD_LAST_SAVEGAME"));
	ChkLoadLastSavegame->SetValue(false);
	ChkLoadLastSavegame->SetToolTip(_("Load the last savegame that was edited."));
	StaticBox9 = new wxStaticBox(GeneralSettings, ID_STATICBOX9, _("Backup"), wxPoint(8,64), wxSize(336,48), 0, _T("ID_STATICBOX9"));
	chkBackupSavegame = new wxCheckBox(GeneralSettings, ID_CHK_BACKUP_SAVEGAME, _("Backup Savegame When Saving"), wxPoint(16,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHK_BACKUP_SAVEGAME"));
	chkBackupSavegame->SetValue(true);
	LangSettings = new wxPanel(SettingsTaps, ID_TAP_LANG, wxDefaultPosition, wxSize(352,212), wxTAB_TRAVERSAL, _T("ID_TAP_LANG"));
	LangSettings->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
	StaticBox2 = new wxStaticBox(LangSettings, ID_STATICBOX2, _("Language Select"), wxPoint(8,8), wxSize(336,200), 0, _T("ID_STATICBOX2"));
	LanguageList = new wxListBox(LangSettings, ID_LANGLIST, wxPoint(16,28), wxSize(152,172), 0, 0, 0, wxDefaultValidator, _T("ID_LANGLIST"));
	StaticBox3 = new wxStaticBox(LangSettings, ID_STATICBOX3, _("Current Language"), wxPoint(176,24), wxSize(160,40), 0, _T("ID_STATICBOX3"));
	currentLangLabel = new wxStaticText(LangSettings, ID_STATICTEXT2, _("English"), wxPoint(184,40), wxSize(144,16), wxST_NO_AUTORESIZE|wxALIGN_CENTRE|wxTRANSPARENT_WINDOW, _T("ID_STATICTEXT2"));
	BtnSetLang = new wxButton(LangSettings, ID_BTN_SETLANG, _("Set Language"), wxPoint(176,72), wxSize(160,23), 0, wxDefaultValidator, _T("ID_BTN_SETLANG"));
	BtnSetLang->Disable();
	UISettings = new wxPanel(SettingsTaps, ID_TAP_UI, wxDefaultPosition, wxSize(352,249), wxTAB_TRAVERSAL, _T("ID_TAP_UI"));
	UISettings->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
	StaticBox1 = new wxStaticBox(UISettings, ID_STATICBOX1, _("Resetting User Interface"), wxPoint(8,8), wxSize(336,96), 0, _T("ID_STATICBOX1"));
	BtnResetUI = new wxButton(UISettings, ID_BTN_RESETUI, _("Reset User Interface"), wxPoint(216,72), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_RESETUI"));
	BtnResetUI->Disable();
	if (setup->defaultLayout != AuiMan->SavePerspective())
	{
	   BtnResetUI->Enable();
	}
	StaticText1 = new wxStaticText(UISettings, ID_STATICTEXT1, _("When pressing the \"Reset User Interface\" button, the userinterface will reset to it\'s defaut positions."), wxPoint(24,24), wxSize(304,48), 0, _T("ID_STATICTEXT1"));
	ShortcutSettings = new wxPanel(SettingsTaps, ID_TAP_SHORTCUT, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TAP_SHORTCUT"));
	ShortcutSettings->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
	FS2011Settings = new wxPanel(SettingsTaps, ID_TAP_FS2011, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TAP_FS2011"));
	FS2011Settings->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
	StaticBox5 = new wxStaticBox(FS2011Settings, ID_STATICBOX5, _("Savegame Location"), wxPoint(8,104), wxSize(336,56), 0, _T("ID_STATICBOX5"));
	StaticBox4 = new wxStaticBox(FS2011Settings, ID_STATICBOX4, _("Install Location"), wxPoint(8,40), wxSize(336,56), 0, _T("ID_STATICBOX4"));
	FS11InstallPath = new wxTextCtrl(FS2011Settings, ID_TXTCTRL_FS11InstallPath, wxEmptyString, wxPoint(16,64), wxSize(296,21), 0, wxDefaultValidator, _T("ID_TXTCTRL_FS11InstallPath"));
	FS11InstallPath->Disable();
	BtnFS2011InstallPath = new wxButton(FS2011Settings, ID_BTN_FS11InstallPath, _("..."), wxPoint(312,63), wxSize(23,23), 0, wxDefaultValidator, _T("ID_BTN_FS11InstallPath"));
	BtnFS2011InstallPath->Disable();
	BtnFS11SavePath = new wxButton(FS2011Settings, ID_BTN_FS11SavePath, _("..."), wxPoint(312,127), wxSize(23,23), 0, wxDefaultValidator, _T("ID_BTN_FS11SavePath"));
	BtnFS11SavePath->Disable();
	FS11SavePath = new wxTextCtrl(FS2011Settings, ID_TXTCTRL_FS11SavePath, wxEmptyString, wxPoint(16,128), wxSize(296,21), 0, wxDefaultValidator, _T("ID_TXTCTRL_FS11SavePath"));
	FS11SavePath->Disable();
	ChkBoxFS11Enabled = new wxCheckBox(FS2011Settings, ID_CHKBOX_FS11Enabled, _("Enable Farming Simulator 2011"), wxPoint(16,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKBOX_FS11Enabled"));
	ChkBoxFS11Enabled->SetValue(false);
	BtnFS11AutoDetect = new wxButton(FS2011Settings, ID_BTN_FS11AutoDetect, _("Auto Detect Locations"), wxPoint(112,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_FS11AutoDetect"));
	BtnFS11AutoDetect->Disable();
	FS2013Settings = new wxPanel(SettingsTaps, ID_TAP_FS2013, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TAP_FS2013"));
	FS2013Settings->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
	StaticBox7 = new wxStaticBox(FS2013Settings, ID_STATICBOX7, _("Savegame Location"), wxPoint(8,104), wxSize(336,56), 0, _T("ID_STATICBOX7"));
	ChkBoxFS13Enabled = new wxCheckBox(FS2013Settings, ID_CHKBOX_FS13Enabled, _("Enable Farming Simulator 2013"), wxPoint(16,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKBOX_FS13Enabled"));
	ChkBoxFS13Enabled->SetValue(false);
	StaticBox6 = new wxStaticBox(FS2013Settings, ID_STATICBOX6, _("Install Location"), wxPoint(8,40), wxSize(336,56), 0, _T("ID_STATICBOX6"));
	FS13SavePath = new wxTextCtrl(FS2013Settings, ID_TXTCTRL_FS13SavePath, wxEmptyString, wxPoint(16,128), wxSize(296,21), 0, wxDefaultValidator, _T("ID_TXTCTRL_FS13SavePath"));
	FS13SavePath->Disable();
	FS13InstallPath = new wxTextCtrl(FS2013Settings, ID_TXTCTRL_FS13InstallPath, wxEmptyString, wxPoint(16,64), wxSize(296,21), 0, wxDefaultValidator, _T("ID_TXTCTRL_FS13InstallPath"));
	FS13InstallPath->Disable();
	BtnFS13SavePath = new wxButton(FS2013Settings, ID_BTN_FS13SavePath, _("..."), wxPoint(312,127), wxSize(23,23), 0, wxDefaultValidator, _T("ID_BTN_FS13SavePath"));
	BtnFS13SavePath->Disable();
	BtnFS2013InstallPath = new wxButton(FS2013Settings, ID_BTN_FS13InstallPath, _("..."), wxPoint(312,63), wxSize(23,23), 0, wxDefaultValidator, _T("ID_BTN_FS13InstallPath"));
	BtnFS2013InstallPath->Disable();
	BtnFS13AutoDetect = new wxButton(FS2013Settings, ID_BTN_FS13AutoDetect, _("Auto Detect Locations"), wxPoint(112,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_FS13AutoDetect"));
	BtnFS13AutoDetect->Disable();
	SettingsTaps->AddPage(GeneralSettings, _("General"), true);
	SettingsTaps->AddPage(LangSettings, _("Language"), false);
	SettingsTaps->AddPage(UISettings, _("User Interface"), false);
	SettingsTaps->AddPage(ShortcutSettings, _("Shortcuts"), false);
	SettingsTaps->AddPage(FS2011Settings, _("FS2011"), false);
	SettingsTaps->AddPage(FS2013Settings, _("FS2013"), false);
	BoxSizer1->Add(SettingsTaps, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTRANSPARENT_WINDOW, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer2->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BtnClose = new wxButton(Panel1, ID_BTN_Close, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_Close"));
	BoxSizer2->Add(BtnClose, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	SetSizer(BoxSizer1);
	SelectPathDialog = new wxDirDialog(this, wxEmptyString, wxEmptyString, wxDD_DEFAULT_STYLE|wxDD_DIR_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();

	Connect(ID_CHK_LOAD_LAST_SAVEGAME,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnChkLoadLastSavegameClick);
	Connect(ID_CHK_BACKUP_SAVEGAME,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnChkBackupSavegameClick);
	Connect(ID_LANGLIST,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&SettingsFrame::OnLangListSelect);
	Connect(ID_BTN_SETLANG,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnSetLangClick);
	Connect(ID_BTN_RESETUI,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnResetUIClick);
	Connect(ID_TXTCTRL_FS11InstallPath,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SettingsFrame::OnFS11InstallPathTextChange);
	Connect(ID_BTN_FS11InstallPath,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnFS2011InstallPathClick);
	Connect(ID_BTN_FS11SavePath,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnFS11SavePathClick);
	Connect(ID_TXTCTRL_FS11SavePath,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SettingsFrame::OnFS11SavePathTextChange);
	Connect(ID_CHKBOX_FS11Enabled,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnChkBoxFS11EnabledClick);
	Connect(ID_BTN_FS11AutoDetect,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnFS11AutoDetectClick);
	Connect(ID_CHKBOX_FS13Enabled,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnChkBoxFS13EnabledClick);
	Connect(ID_TXTCTRL_FS13SavePath,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SettingsFrame::OnFS13SavePathTextChange);
	Connect(ID_TXTCTRL_FS13InstallPath,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SettingsFrame::OnFS13InstallPathTextChange);
	Connect(ID_BTN_FS13SavePath,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnFS13SavePathClick);
	Connect(ID_BTN_FS13InstallPath,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnFS2013InstallPathClick);
	Connect(ID_BTN_FS13AutoDetect,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnFS13AutoDetectClick);
	Connect(ID_SETTINGSTAPS,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&SettingsFrame::OnSettingsTapsPageChanged);
	Connect(ID_BTN_Close,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SettingsFrame::OnBtnCloseClick);
	Connect(wxEVT_ENTER_WINDOW,(wxObjectEventFunction)&SettingsFrame::OnMouseEnter);
	//*)

}

SettingsFrame::~SettingsFrame()
{
	//(*Destroy(SettingsFrame)
	//*)
}

void SettingsFrame::OnBtnCloseClick(wxCommandEvent& event)
{
    Show(false);
}

void SettingsFrame::OnBtnResetUIClick(wxCommandEvent& event)
{
    if (AuiMan->LoadPerspective(setup->defaultLayout))
        BtnResetUI->Disable();
}

void SettingsFrame::OnSettingsTapsPageChanged(wxNotebookEvent& event)
{
    updateTapPanels();
}

bool SettingsFrame::updateLanguageList()
{
    LangList temp;
    setup->getInstalledLanguages(temp);

    // To prevent it don't reload the language list each time the page is shown unless it have changed
    if (temp.identifiers.Count() != langList.identifiers.Count())
    {
        setup->getInstalledLanguages(langList);
        LanguageList->Clear();
        LanguageList->Append(langList.names);
        BtnSetLang->Disable();
        return true;
    }
    return false;
}

void SettingsFrame::updateTapPanels()
{
    switch (SettingsTaps->GetSelection())
    {
        case 0: // General Tap
        {
            ChkLoadLastSavegame->SetValue(setup->loadLastSavegame);
            break;
        }
        case 1: // Language Tap
        {
            if (updateLanguageList()) // Only update the label if the language list have changed.
            {
                const wxLanguageInfo *langInfo = wxLocale::GetLanguageInfo(setup->selectedLangId);
                currentLangLabel->SetLabel(langInfo->Description);
            }
            break;
        }
        case 2: // User Interface Tap
        {
            if (setup->defaultLayout != AuiMan->SavePerspective())
                BtnResetUI->Enable();
            else
                BtnResetUI->Disable();
            break;
        }
        case 3: // Shortcut Tap
        {
            break;
        }
        case 4: // FS2011 Tap
        {
            if (setup->gameIsEnabled[FS2011])
            {
                ChkBoxFS11Enabled->SetValue(true);
                FS11InstallPath->Enable();
                BtnFS2011InstallPath->Enable();
                FS11SavePath->Enable();
                BtnFS11SavePath->Enable();
            }
            else
            {
                ChkBoxFS11Enabled->SetValue(false);
                FS11InstallPath->Disable();
                BtnFS2011InstallPath->Disable();
                FS11SavePath->Disable();
                BtnFS11SavePath->Disable();
            }

            FS11InstallPath->ChangeValue(setup->installPath[FS2011]);

            FS11SavePath->ChangeValue(setup->savegamePath[FS2011]);

            updateBtnFS11AutoDetect();

            break;
        }
        case 5: // FS2013 Tap
        {
            if (setup->gameIsEnabled[FS2013])
            {
                ChkBoxFS13Enabled->SetValue(true);
                FS13InstallPath->Enable();
                BtnFS2013InstallPath->Enable();
                FS13SavePath->Enable();
                BtnFS13SavePath->Enable();
            }
            else
            {
                ChkBoxFS13Enabled->SetValue(false);
                FS13InstallPath->Disable();
                BtnFS2013InstallPath->Disable();
                FS13SavePath->Disable();
                BtnFS13SavePath->Disable();
            }

            FS13InstallPath->ChangeValue(setup->installPath[FS2013]);

            FS13SavePath->ChangeValue(setup->savegamePath[FS2013]);

            updateBtnFS13AutoDetect();

            break;
        }
    }
}

void SettingsFrame::OnMouseEnter(wxMouseEvent& event)
{
    updateTapPanels();
}

void SettingsFrame::OnLangListSelect(wxCommandEvent& event)
{
    BtnSetLang->Enable();
}

void SettingsFrame::OnBtnSetLangClick(wxCommandEvent& event)
{
    // TODO: Implement language selection.

    wxMessageBox(_("You need to restart Courseplay Editor for this to take effect.\nRemember to save your savegame before restarting!"),
                 _("Language Setup Info"),
                 wxOK | wxCENTER, this);
    currentLangLabel->SetLabel(LanguageList->GetStringSelection());
    setup->setSelectedLangId((wxLanguage) langList.identifiers[LanguageList->GetSelection()]);
    LanguageList->Deselect(LanguageList->GetSelection());
    BtnSetLang->Disable();
}

void SettingsFrame::updateBtnFS11AutoDetect()
{
    if (setup->gameIsEnabled[FS2011] && (FS11InstallPath->GetValue() == wxEmptyString || FS11SavePath->GetValue() == wxEmptyString))
        BtnFS11AutoDetect->Enable();
    else
        BtnFS11AutoDetect->Disable();
}

void SettingsFrame::OnChkBoxFS11EnabledClick(wxCommandEvent& event)
{
    int returnVal;
    if (setup->selectedGameId == FS2011 && setup->savegameHasChanges && !event.IsChecked())
    {
        ChkBoxFS11Enabled->SetValue(true);
        wxString msg = _("You have unsaved changes in your current savegame!\nYou will lose those changes if you disable %s.\n\nAre you sure you will disable %s?");
        returnVal = wxMessageBox(wxString::Format(msg, _("Farming Simulator 2011"), _("Farming Simulator 2011")),
                                 _("Unsaved Changes"),
                                 wxYES_NO|wxCENTER|wxICON_EXCLAMATION,
                                 this);
    }
    else
        returnVal = wxYES;

    if (returnVal == wxYES)
    {
        short oldId = (short)setup->selectedGameId;
        setup->enableGame(FS2011, event.IsChecked());
        ChkBoxFS11Enabled->SetValue(event.IsChecked());

        if (oldId != (short)setup->selectedGameId)
            setup->updateSavegameList();

        updateTapPanels();
    }
    else
    {
        ChkBoxFS11Enabled->SetValue(true);
    }

}

void SettingsFrame::autoDetectPath(FSGames gameId)
{
    bool foundInstallPath  = setup->findInstallPath (gameId);
    bool foundSavegamePath = setup->findSavegamePath(gameId);

    if (foundInstallPath && foundSavegamePath)
    {
        updateTapPanels();
        setup->updateSavegameList();
    }
    else
    {
        updateTapPanels();
        setup->updateSavegameList();

        wxString tempText = wxEmptyString;
        if (!foundInstallPath)
            tempText += _("Install Location");

        if (!foundSavegamePath)
        {
            if (!foundInstallPath)
            {
                tempText += wxT(" ");
                tempText += _("and");
                tempText += wxT(" ");
            }

            tempText += _("Savegame Location");
        }


        wxString location = _("location");
        if (!foundInstallPath && !foundSavegamePath)
            location = _("locations");

        wxString msgText = wxString::Format(_("Was not able to auto detect %s.\n\nYou can manually set the %s, if you have the game installed."),
                                            tempText.c_str(),
                                            location.c_str()
                                            );
        wxMessageBox(msgText, _("Auto Detect Failed!"), wxOK | wxICON_EXCLAMATION | wxCENTER, this);
    }
}

void SettingsFrame::OnFS11InstallPathTextChange(wxCommandEvent& event)
{
    setup->setInstallPath(FS2011, FS11InstallPath->GetValue());
    setup->updateSavegameList();

    updateBtnFS11AutoDetect();
}

void SettingsFrame::OnFS11SavePathTextChange(wxCommandEvent& event)
{
    setup->setSavegamePath(FS2011, FS11SavePath->GetValue());
    setup->updateSavegameList();

    updateBtnFS11AutoDetect();
}

void SettingsFrame::OnBtnFS2011InstallPathClick(wxCommandEvent& event)
{
    SelectPathDialog->SetPath(FS11InstallPath->GetValue());
    SelectPathDialog->SetMessage(_("Select Farming Simulator 2011 Install Location."));

    if (SelectPathDialog->ShowModal() == wxID_OK)
        FS11InstallPath->SetValue(SelectPathDialog->GetPath());
}

void SettingsFrame::OnBtnFS11SavePathClick(wxCommandEvent& event)
{
    SelectPathDialog->SetPath(FS11SavePath->GetValue());
    SelectPathDialog->SetMessage(_("Select Farming Simulator 2011 Savegame Location."));

    if (SelectPathDialog->ShowModal() == wxID_OK)
        FS11SavePath->SetValue(SelectPathDialog->GetPath());
}

void SettingsFrame::OnBtnFS11AutoDetectClick(wxCommandEvent& event)
{
    autoDetectPath(FS2011);
}

void SettingsFrame::updateBtnFS13AutoDetect()
{
    if (setup->gameIsEnabled[FS2013] && (FS13InstallPath->GetValue() == wxEmptyString || FS13SavePath->GetValue() == wxEmptyString))
        BtnFS13AutoDetect->Enable();
    else
        BtnFS13AutoDetect->Disable();
}

void SettingsFrame::OnChkBoxFS13EnabledClick(wxCommandEvent& event)
{
    int returnVal;
    if (setup->selectedGameId == FS2013 && setup->savegameHasChanges && !event.IsChecked())
    {
        ChkBoxFS13Enabled->SetValue(true);
        wxString msg = _("You have unsaved changes in your current savegame!\nYou will lose those changes if you disable %s.\n\nAre you sure you will disable %s?");
        returnVal = wxMessageBox(wxString::Format(msg, _("Farming Simulator 2013"), _("Farming Simulator 2013")),
                                 _("Unsaved Changes"),
                                 wxYES_NO|wxCENTER|wxICON_EXCLAMATION,
                                 this);
    }
    else
        returnVal = wxYES;

    if (returnVal == wxYES)
    {
        short oldId = (short)setup->selectedGameId;
        setup->enableGame(FS2013, event.IsChecked());
        ChkBoxFS13Enabled->SetValue(event.IsChecked());

        if (oldId != (short)setup->selectedGameId)
            setup->updateSavegameList();

        updateTapPanels();
    }
    else
    {
        ChkBoxFS13Enabled->SetValue(true);
    }
}

void SettingsFrame::OnFS13InstallPathTextChange(wxCommandEvent& event)
{
    setup->setInstallPath(FS2013, FS13InstallPath->GetValue());
    setup->updateSavegameList();

    updateBtnFS13AutoDetect();
}

void SettingsFrame::OnFS13SavePathTextChange(wxCommandEvent& event)
{
    setup->setSavegamePath(FS2013, FS13SavePath->GetValue());
    setup->updateSavegameList();

    updateBtnFS13AutoDetect();
}

void SettingsFrame::OnBtnFS2013InstallPathClick(wxCommandEvent& event)
{
    SelectPathDialog->SetPath(FS13InstallPath->GetValue());
    SelectPathDialog->SetMessage(_("Select Farming Simulator 2013 Install Location."));

    if (SelectPathDialog->ShowModal() == wxID_OK)
        FS13InstallPath->SetValue(SelectPathDialog->GetPath());
}

void SettingsFrame::OnBtnFS13SavePathClick(wxCommandEvent& event)
{
    SelectPathDialog->SetPath(FS13SavePath->GetValue());
    SelectPathDialog->SetMessage(_("Select Farming Simulator 2013 Savegame Location."));

    if (SelectPathDialog->ShowModal() == wxID_OK)
        FS13SavePath->SetValue(SelectPathDialog->GetPath());
}

void SettingsFrame::OnBtnFS13AutoDetectClick(wxCommandEvent& event)
{
    autoDetectPath(FS2013);
}

void SettingsFrame::OnChkLoadLastSavegameClick(wxCommandEvent& event)
{
    setup->setLoadLastSavegame(event.IsChecked());
}

void SettingsFrame::OnChkBackupSavegameClick(wxCommandEvent& event)
{
    setup->setBackupSavegame(event.IsChecked());
}
