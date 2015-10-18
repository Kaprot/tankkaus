/***************************************************************
 * Name:      tankkausApp.h
 * Purpose:   Defines Application Class
 * Author:    Kaprot ()
 * Created:   2015-09-19
 * Copyright: Kaprot ()
 * License:   MIT
 **************************************************************/

#ifndef TANKKAUSMAIN_H
#define TANKKAUSMAIN_H

//(*Headers(tankkausDialog)
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/datectrl.h>
#include <wx/button.h>
#include <wx/dateevt.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
//*)

class tankkausDialog: public wxDialog
{
    public:

        tankkausDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~tankkausDialog();

    private:

        //(*Handlers(tankkausDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnComboBox1Selected(wxCommandEvent& event);
        //void OnTextCtrl1Text(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnScrollBar1Scroll(wxScrollEvent& event);
        void OnSlider1CmdScroll(wxScrollEvent& event);
        void OnSlider1CmdScroll1(wxScrollEvent& event);
        //void OnTextCtrl1Text1(wxCommandEvent& event);
        //void OnTextCtrl2Text(wxCommandEvent& event);
        void OntxtLiterText(wxCommandEvent& event);
        void OntxtKmText(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnbtnStoreClick(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        //*)

        //(*Identifiers(tankkausDialog)
        static const long ID_PANEL1;
        static const long ID_COMBOBOX1;
        static const long ID_DATEPICKERCTRL1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_CHECKBOX1;
        static const long ID_SLIDER1;
        //*)

        //(*Declarations(tankkausDialog)
        wxPanel* Panel1;
        wxTextCtrl* txtLiter;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* btnStore;
        wxComboBox* carsComboBox;
        wxBoxSizer* BoxSizer1;
        wxCheckBox* tripMeterCheck;
        wxSlider* Slider1;
        wxTextCtrl* txtKm;
        wxDatePickerCtrl* DatePickerCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
        float cons[32000];
        int dates[32000];
        void UpdateCarList();
        void newVehicle();
        float kmBefore;
};

#endif // TANKKAUSMAIN_H
