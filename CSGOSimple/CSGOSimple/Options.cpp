#include "Options.hpp"

namespace Options
{
     //Here we defined the extern variables declared on Options.hpp

     bool g_bMainWindowOpen = true;

     bool g_bESPEnabled = true;
     bool g_bESPShowBoxes = true;
     bool g_bESPShowNames = true;
     bool g_bRCSEnabled = true;
	 bool g_bSkinChangerEnabled = true;
     bool g_bBHopEnabled = true;
     bool g_bAutoAccept = true;
     float g_bESPAllyColor[4] = {0.0f, 0.0f, 1.0f, 1.0f}; //RGBA color
     float g_bESPEnemyColor[4] = {1.0f, 0.0f, 0.0f, 1.0f};

	 //Skin Changer
	 int g_iKnifeSkin = 416;
	 int g_iKnifeSeed = 1;
	 int g_iKnifeQuality = 3;
	 int g_iKnifeStatKills = 1337;

	 bool g_bKnifeStatEnabled = true;

	 char* g_cKnifeName = "Default";
}