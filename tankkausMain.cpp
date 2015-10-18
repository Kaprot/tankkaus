/***************************************************************
 * Name:      tankkausApp.h
 * Purpose:   Defines Application Class
 * Author:    Kaprot ()
 * Created:   2015-09-19
 * Copyright: Kaprot ()
 * License:   MIT
 * **************************************************************/

#include "tankkausMain.h"
#include <wx/msgdlg.h>
#include <wx/textfile.h>
#include <wx/dir.h>
//#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/dynarray.h>
#include <wx/textdlg.h>
#define  STORE_LABEL  "Store"
#define  NEW_VEHICLE_LABEL  "New Vehicle"

//(*InternalHeaders(tankkausDialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(tankkausDialog)
const long tankkausDialog::ID_PANEL1 = wxNewId();
const long tankkausDialog::ID_COMBOBOX1 = wxNewId();
const long tankkausDialog::ID_DATEPICKERCTRL1 = wxNewId();
const long tankkausDialog::ID_TEXTCTRL1 = wxNewId();
const long tankkausDialog::ID_TEXTCTRL2 = wxNewId();
const long tankkausDialog::ID_BUTTON3 = wxNewId();
const long tankkausDialog::ID_BUTTON1 = wxNewId();
const long tankkausDialog::ID_BUTTON2 = wxNewId();
const long tankkausDialog::ID_CHECKBOX1 = wxNewId();
const long tankkausDialog::ID_SLIDER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(tankkausDialog,wxDialog)
    //(*EventTable(tankkausDialog)
    //*)
END_EVENT_TABLE()
void tankkausDialog::UpdateCarList()
{
    wxString filename;
    wxDir dir(wxGetCwd());
    carsComboBox->Clear();
    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS | wxDIR_FILES);
    while ( cont )
        {
        //printf("%s\n", filename.c_str());
        if (filename.EndsWith(".csv"))carsComboBox->Append(filename);
        cont = dir.GetNext(&filename);
        //
        }
}
tankkausDialog::tankkausDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(tankkausDialog)
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("Tankkaus"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(661,310));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(366,300), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    carsComboBox = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(140,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    BoxSizer3->Add(carsComboBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    DatePickerCtrl1 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxSize(140,29), wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    BoxSizer3->Add(DatePickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    txtLiter = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(140,29), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    txtLiter->SetToolTip(_("Liter"));
    txtLiter->SetHelpText(_("Liter"));
    BoxSizer3->Add(txtLiter, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    txtKm = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(140,29), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    txtKm->SetToolTip(_("Km"));
    txtKm->SetHelpText(_("Km"));
    BoxSizer3->Add(txtKm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    btnStore = new wxButton(this, ID_BUTTON3, _(" New Vehicle"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer3->Add(btnStore, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    tripMeterCheck = new wxCheckBox(this, ID_CHECKBOX1, _("No Trip Meter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    tripMeterCheck->SetValue(true);
    BoxSizer3->Add(tripMeterCheck, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxDefaultPosition, wxSize(140,29), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    BoxSizer3->Add(Slider1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&tankkausDialog::OnPanel1Paint,0,this);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&tankkausDialog::OnComboBox1Selected);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&tankkausDialog::OntxtLiterText);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&tankkausDialog::OntxtKmText);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tankkausDialog::OnbtnStoreClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tankkausDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tankkausDialog::OnQuit);
    Connect(ID_SLIDER1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&tankkausDialog::OnSlider1CmdScroll1);
    Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&tankkausDialog::OnSlider1CmdScroll1);
    //*)

    UpdateCarList();
    //float cons[32000];
    //int dates[32000];
    //float kmBefore=0;
}

tankkausDialog::~tankkausDialog()
{
    //(*Destroy(tankkausDialog)
    //*)
}

void tankkausDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void tankkausDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = _("Tankkaus\n") + wxbuildinfo(long_f);
    wxMessageBox(msg, _("Tankkaus"));
}
float processLine (wxString txtLine,float *cons,int *dates,int *counter,float kmBefore=0)
{
    if (txtLine.StartsWith("\"NoTripMeter\""))return(-2);
    int year=wxAtoi(txtLine.BeforeFirst(','));txtLine=txtLine.AfterFirst(',');
    int day=wxAtoi(txtLine.BeforeFirst(','));txtLine=txtLine.AfterFirst(',');
    int month=wxAtoi(txtLine.BeforeFirst(','));txtLine=txtLine.AfterFirst(',');
    float km=wxAtoi(txtLine.BeforeFirst(','));txtLine=txtLine.AfterFirst(',');
    float liter=wxAtoi(txtLine.BeforeFirst(','));txtLine=txtLine.AfterFirst(',');
    if (year*day*month*km*liter!=0)
        {
        cons[*counter]=liter/((km-kmBefore)/100);
        dates[*counter]=year+(month<<16)+(day<<24);
        *counter+=1;
        }
        else
            km=kmBefore;
    //    wxMessageBox(wxString::Format(wxT("%i"),km),_("Should not be here..."));
    return km;
}
void tankkausDialog::OnComboBox1Selected(wxCommandEvent& event)
{
    wxTextFile      tfile;
    wxString        str;
    tfile.Open(carsComboBox->GetValue());
    int counter=0;
    // read the first line
    str = tfile.GetFirstLine();
    //txtKm->AppendText (str);
    kmBefore=processLine(str,&this->cons[0],&this->dates[0],&counter,0); // placeholder, do whatever you want with the string
    tripMeterCheck->SetValue(kmBefore==-2);
    kmBefore=0;
    // read all lines one by one
    // until the end of the file
    bool NoTrip=tripMeterCheck->GetValue();
    //txtKm->AppendText (wxString::Format(wxT("%i"),NoTrip));
    while(!tfile.Eof())
    {

        str = tfile.GetNextLine();
        kmBefore=processLine(str,&this->cons[0],&this->dates[0],&counter,NoTrip*kmBefore); // placeholder, do whatever you want with the string

    }
    cons[counter]=0;
    tfile.Close();
    Slider1->SetMax(abs(counter*10-346));
    if (counter>34)
            Slider1->SetValue(Slider1->GetMax());
    else
            Slider1->SetValue(0);
    this->Refresh();
    btnStore->SetLabel(STORE_LABEL);
    //btnStore->Enable(false);
}

void tankkausDialog::OnPanel1Paint(wxPaintEvent& event)
{
    wxPaintDC paintDC(this->Panel1);
    paintDC.SetPen(wxPen(wxColour(0,0,255),2,wxPENSTYLE_SOLID));
    //paintDC.SetBrush(wxBrush(wxColour(230,230,240),wxBRUSHSTYLE_CROSSDIAG_HATCH));
    paintDC.DrawRectangle(1,1,365,299);
    paintDC.SetFont(wxFont(wxFontInfo(8).Bold(0).Underlined(0)));
    int multiplier=20;
    paintDC.SetPen(wxPen(wxColour(0,200,0),1,wxPENSTYLE_SOLID));
    paintDC.DrawLine(0,295-(5*multiplier),600,295-(5*multiplier));
    paintDC.SetPen(wxPen(wxColour(200,200,0),1,wxPENSTYLE_SOLID));
    paintDC.DrawLine(0,295-(7.5*multiplier),600,295-(7.5*multiplier));
    paintDC.SetPen(wxPen(wxColour(200,0,0),1,wxPENSTYLE_SOLID));
    paintDC.DrawLine(0,295-(10*multiplier),600,295-(10*multiplier));

    for (unsigned int c=0;this->cons[c]!=0;c++)
        {
        unsigned int year=(dates[c]) & 65535;
        unsigned int month=((dates[c]) & 16711680)>>16;
        unsigned int day=((dates[c]) & 4278190080)>>24;
        wxString date = wxString::Format(wxT("%i.%i.%i"),day,month,year);
        wxString con = wxString::Format(wxT("%0.2f"),cons[c]);
        //TextCtrl2->SetValue(date);
        paintDC.SetPen(wxPen(wxColour(0,month*15+50,200-month*15+50),9,wxPENSTYLE_SOLID));
        paintDC.DrawLine(c*10-this->Slider1->GetValue()+10,295-(cons[c]*multiplier),c*10-this->Slider1->GetValue()+10,295);
        paintDC.DrawRotatedText(con,c*10-this->Slider1->GetValue()+4,295,90);
        paintDC.DrawRotatedText(date,c*10-this->Slider1->GetValue()+4,280-(cons[c]*multiplier),90);
        }
        if (wxAtof(txtKm->GetValue())>0 && wxAtof(txtLiter->GetValue())>0)
        {
            float liter=wxAtof(txtLiter->GetValue());
            float km=wxAtof(txtKm->GetValue());
            int tripMultiplier=(tripMeterCheck->GetValue()==TRUE);
            float curCon=liter/((km-tripMultiplier*kmBefore)/100);
            paintDC.SetPen(wxPen(wxColour(0,255,0),10,wxPENSTYLE_SOLID));
            paintDC.DrawLine(357,295-(curCon*multiplier),357,295);
            paintDC.DrawRotatedText(wxString::Format(wxT("%0.2f"),curCon),351,295,90);
            if (carsComboBox->GetValue()!="")btnStore->Enable(true);
            //btnStore->Enable((btnStore->GetLabel()==STORE_LABEL));
        }
        else
        {
            btnStore->Enable((btnStore->GetLabel()==NEW_VEHICLE_LABEL));
        }
}





void tankkausDialog::OnSlider1CmdScroll1(wxScrollEvent& event)
{
    this->Refresh();
}


void tankkausDialog::OntxtLiterText(wxCommandEvent& event)
{
    this->Refresh();
}

void tankkausDialog::OntxtKmText(wxCommandEvent& event)
{
    this->Refresh();
}


void tankkausDialog::newVehicle()
{
    wxString carname;
    wxTextEntryDialog carnameDialog(this, _("Name of the New Vehicle"), _("New Vehicle"));
    if ( carnameDialog.ShowModal() == wxID_OK )
    {

        carname = carnameDialog.GetValue();
        int answer = wxMessageBox(_("Does vehicle have trip meter?"),_("Trip meter"),wxYES_NO|wxCANCEL);
        if (answer!=wxCANCEL)
        {
            wxTextFile      tfile;
            tfile.Create(carname +".csv" );
            if (answer==wxNO)tfile.AddLine("\"NoTripMeter\"");
            tfile.AddLine("\"YEAR\",\"DAY\",\"MONTH\",\"KILOMETERS\",\"LITERS\"");
            tfile.Write();
            tfile.Close();
        }
    }
}
void tankkausDialog::OnbtnStoreClick(wxCommandEvent& event)
{
    if (btnStore->GetLabel()==NEW_VEHICLE_LABEL)
    {
        newVehicle();
        UpdateCarList();
    }
    else
    {
        //wxMessageBox(btnStore->GetLabel(),_("Should not be here..."));
        wxDateTime D = DatePickerCtrl1->GetValue();
        wxString line=wxString::Format(wxT("%i,%i,%i"),D.GetYear(),D.GetDay(),D.GetMonth()+1);
        wxString km = wxString::Format(wxT("%0.2f"),wxAtof(txtKm->GetValue()));
        wxString liter = wxString::Format(wxT("%0.2f"),wxAtof(txtLiter->GetValue()));
        //btnStore->SetLabel(liter);
        wxTextFile      tfile;
        tfile.Open(carsComboBox->GetValue());
        tfile.AddLine(line + "," + km + "," + liter);
        tfile.Write();
        tfile.Close();
        txtKm->SetValue("");
        txtLiter->SetValue("");
        btnStore->Enable(false);
        //btnStore->SetLabel(NEW_VEHICLE_LABEL);
        int c;
        for (c=0;this->cons[c]!=0;c++);
        int tripMultiplier=(tripMeterCheck->GetValue()==TRUE);
        kmBefore=processLine(line + "," + km + "," + liter,&this->cons[0],&this->dates[0],&c,tripMultiplier*kmBefore);
        cons[c]=0;
        this->Refresh();
        if (c>34)Slider1->SetMax(abs(c*10-346));else Slider1->SetMax(0);
        Slider1->SetValue(Slider1->GetMax());
    }
}
