#pragma once

namespace Options
{
     extern bool g_bMainWindowOpen;

     extern bool g_bESPEnabled;
     extern bool g_bESPShowBoxes;
     extern bool g_bESPShowNames;
     extern bool g_bRCSEnabled;
	 extern bool g_bSkinChangerEnabled;
     extern bool g_bBHopEnabled;
     extern bool g_bAutoAccept;
     extern float g_bESPAllyColor[4];
     extern float g_bESPEnemyColor[4];

	 //Skin Changer
	 extern int g_iKnifeSkin;
	 extern int g_iKnifeSeed;
	 extern int g_iKnifeQuality;
	 extern int g_iKnifeStatKills;

	 extern bool g_bKnifeStatEnabled;

	 extern char* g_cKnifeName;
     //Add others as needed. 
     //Remember they must be defined on Options.cpp as well
}

