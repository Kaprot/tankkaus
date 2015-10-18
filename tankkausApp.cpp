/***************************************************************
 * Name:      tankkausApp.h
 * Purpose:   Defines Application Class
 * Author:    Kaprot ()
 * Created:   2015-09-19
 * Copyright: Kaprot ()
 * License:   MIT
 **************************************************************/

#include "tankkausApp.h"

//(*AppHeaders
#include "tankkausMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(tankkausApp);

bool tankkausApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	tankkausDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
