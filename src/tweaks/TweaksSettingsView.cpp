#include "TweaksSettingsView.h"

#include <iostream>

#include "MainWindowController.h"
#include "TweaksSettingsHomeMenuView.h"
#include "TweaksSettingsLEDView.h"
#include "TweaksSettingsMiscView.h"
#include "TweaksSettingsPageView.h"

using namespace std;

TweaksSettingsView::TweaksSettingsView(TweaksPlugin *plugin, QWidget *parent)
    : QWidget(parent),
      plugin(plugin)
{
    setupUi(this);
    cout << "TweaksSettingsView()" << endl << flush; 
    connect(ledLabel, SIGNAL(tapped()), this, SLOT(led()));
    connect(homeMenuLabel, SIGNAL(tapped()), this, SLOT(homeMenu()));
    connect(miscLabel, SIGNAL(tapped()), this, SLOT(misc()));
}

void TweaksSettingsView::led()
{
    TweaksSettingsPageView *pv = new TweaksSettingsPageView(this, new TweaksSettingsLEDView(0));
    MainWindowController::sharedInstance()->pushView(pv);
}

void TweaksSettingsView::misc()
{
    TweaksSettingsPageView *pv = new TweaksSettingsPageView(this, new TweaksSettingsMiscView(plugin, 0));
    MainWindowController::sharedInstance()->pushView(pv);
}

void TweaksSettingsView::homeMenu()
{
    TweaksSettingsPageView *pv = new TweaksSettingsPageView(this, new TweaksSettingsHomeMenuView(plugin, 0));
    MainWindowController::sharedInstance()->pushView(pv);
}
