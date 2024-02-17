//Static addresses
static DWORD addr;
static DWORD addr1;
static DWORD addr_Health;
static DWORD addr_1HK;
static DWORD addr_arrows;
static DWORD addr_ammo;
static DWORD addr_ammo1;
static DWORD addr_After;
static DWORD addr_Ability;
static DWORD addr_Special;
static DWORD addr_Skill;
static DWORD addr_Gren;
static DWORD addr_Cash;
static DWORD addr_Cash1;
static DWORD addr_XP;
static DWORD addr_Silencer;
static DWORD addr_Stamina;
static DWORD addr_Stamina1;
static DWORD addr_Focus;
static DWORD addr_Light;
static DWORD addr_Weapon;
static DWORD addr_Rage;
static DWORD addr_Timer;
static DWORD addr_Items;
static DWORD addr_Items1;
static DWORD addr_Score; 
static DWORD Money_addr;
static DWORD seal_addr;
static DWORD uv_addr;
static DWORD Gold_addr;
static DWORD Charge_addr;
static BYTE Gamexex;
DWORD start1 = 0x82;
DWORD MYPtr1;
DWORD MYPtr2;
DWORD MYPtr3;

//###########Bools##############
//Player/////////////////
bool InfHealth = false;
bool InfHealth2 = false;
bool InfHealthZOM = false;
bool InfArmor = false;
bool InfStamina = false;
bool Max_XP = false;
bool InfRage = false;

//Ammo & Items/////////
bool InfAmmo = false;
bool InfAmmoZom = false;
bool InfGrenade = false;
bool InfItems = false;
bool item = false;
//Cash///////////////
bool Max_Cash = false;
bool InfCash = false;
bool maxcashzm = false;
bool InfGold = false;
bool MoneyMOD = false;
bool MoneyMOD1 = false;
//Enemy//////////////
bool OneHitKo = false;
bool DontDie = false;
bool NOAmmo = false;
//Misc//////////////
bool NoWeight = false;
bool InfLight = false;
bool InfScore = false;
bool InfSeal = false;

bool Unbreakable = false;
bool InfSkill = false;
bool InfSpecial = false;
bool InfAbility = false;
bool InfFocus = false;
bool killstreaks = false;
bool InfTimer = false;
bool ALLCheats = false;
bool ALLCheats1 = false;
bool ALLCheats2 = false;
bool CheatXX = FALSE;
bool CheatLB = FALSE;
bool CheatYY = FALSE;
bool CheatRB = FALSE;
bool CheatRT = FALSE;
bool CheatLT = FALSE;
bool CheatDU = FALSE;
bool CheatDL = FALSE;
bool CheatDR = FALSE;
//System/////////////
static BYTE staticcode = 0;
bool HooksSet = false;
bool SetAddr = false;
bool Spammer = false;
//##############################

//#########Values#############
DWORD NOPThis = 0x60000000;
DWORD Max_IT = 0x3b9ac9ff;//999999999
DWORD Li_r11_Max = 0x39607530;
DWORD Li_r11_999 = 0x396003E7;
DWORD Li_r11_99 = 0x39600063;
DWORD Li_r11_Nil = 0x39600000;
DWORD Addi_r11_FFFF = 0x396bffff;
DWORD Addi_r11_nil = 0x396b0000;
DWORD Addi_r11_1 = 0x396b0001;
DWORD Addi_r9_99 = 0x39290063;
//#######Other Functions#######
static void Null_Menu(void)
{

}
static DWORD Check_Remove;
static DWORD Check_Remove1;
static DWORD Check_Remove2;
static DWORD Check_Remove3;