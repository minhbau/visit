// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include "QvisExtractPointFunction2DWindow.h"

#include <ExtractPointFunction2DAttributes.h>

#include <QLabel>
#include <QLayout>
#include <QLineEdit>


// ****************************************************************************
// Method: QvisExtractPointFunction2DWindow::QvisExtractPointFunction2DWindow
//
// Purpose: 
//   Constructor
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

QvisExtractPointFunction2DWindow::QvisExtractPointFunction2DWindow(const int type,
                         ExtractPointFunction2DAttributes *subj,
                         const QString &caption,
                         const QString &shortName,
                         QvisNotepadArea *notepad)
    : QvisOperatorWindow(type,subj, caption, shortName, notepad)
{
    atts = subj;
}


// ****************************************************************************
// Method: QvisExtractPointFunction2DWindow::~QvisExtractPointFunction2DWindow
//
// Purpose: 
//   Destructor
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

QvisExtractPointFunction2DWindow::~QvisExtractPointFunction2DWindow()
{
}


// ****************************************************************************
// Method: QvisExtractPointFunction2DWindow::CreateWindowContents
//
// Purpose: 
//   Creates the widgets for the window.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisExtractPointFunction2DWindow::CreateWindowContents()
{
    QGridLayout *mainLayout = new QGridLayout(0);
    topLayout->addLayout(mainLayout);

    ILabel = new QLabel(tr("I"), central);
    mainLayout->addWidget(ILabel,0,0);
    I = new QLineEdit(central);
    connect(I, SIGNAL(returnPressed()),
            this, SLOT(IProcessText()));
    mainLayout->addWidget(I, 0,1);

    JLabel = new QLabel(tr("J"), central);
    mainLayout->addWidget(JLabel,1,0);
    J = new QLineEdit(central);
    connect(J, SIGNAL(returnPressed()),
            this, SLOT(JProcessText()));
    mainLayout->addWidget(J, 1,1);

}


// ****************************************************************************
// Method: QvisExtractPointFunction2DWindow::UpdateWindow
//
// Purpose: 
//   Updates the widgets in the window when the subject changes.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisExtractPointFunction2DWindow::UpdateWindow(bool doAll)
{

    for(int i = 0; i < atts->NumAttributes(); ++i)
    {
        if(!doAll)
        {
            if(!atts->IsSelected(i))
            {
                continue;
            }
        }

        switch(i)
        {
          case ExtractPointFunction2DAttributes::ID_I:
            I->setText(IntsToQString(atts->GetI()));
            break;
          case ExtractPointFunction2DAttributes::ID_J:
            J->setText(IntsToQString(atts->GetJ()));
            break;
        }
    }
}


// ****************************************************************************
// Method: QvisExtractPointFunction2DWindow::GetCurrentValues
//
// Purpose: 
//   Gets values from certain widgets and stores them in the subject.
//
// Note:       Autogenerated by xml2window.
//
// Programmer: xml2window
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
QvisExtractPointFunction2DWindow::GetCurrentValues(int which_widget)
{
    bool doAll = (which_widget == -1);

    // Do I
    if(which_widget == ExtractPointFunction2DAttributes::ID_I || doAll)
    {
        intVector val;
        if(LineEditGetInts(I, val))
            atts->SetI(val);
        else
        {
            ResettingError(tr("I"),
                IntsToQString(atts->GetI()));
            atts->SetI(atts->GetI());
        }
    }

    // Do J
    if(which_widget == ExtractPointFunction2DAttributes::ID_J || doAll)
    {
        intVector val;
        if(LineEditGetInts(J, val))
            atts->SetJ(val);
        else
        {
            ResettingError(tr("J"),
                IntsToQString(atts->GetJ()));
            atts->SetJ(atts->GetJ());
        }
    }

}


//
// Qt Slot functions
//


void
QvisExtractPointFunction2DWindow::IProcessText()
{
    GetCurrentValues(ExtractPointFunction2DAttributes::ID_I);
    Apply();
}


void
QvisExtractPointFunction2DWindow::JProcessText()
{
    GetCurrentValues(ExtractPointFunction2DAttributes::ID_J);
    Apply();
}


