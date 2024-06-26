




/*
	File created by Chris Johnson.
	These were previously all in game.cpp.

	This file includes all the the enums, defines, and included headers required globally by all components.

	All code released under GNU GPL.
*/
#include <windows.h>
#include <vector>
#include <map>
#include <deque>
#include "cmarkup/Markup.h"
using namespace std;


const int BIT1 = (1 << 0);
const int BIT2 = (1 << 1);
const int BIT3 = (1 << 2);
const int BIT4 = (1 << 3);
const int BIT5 = (1 << 4);
const int BIT6 = (1 << 5);
const int BIT7 = (1 << 6);
const int BIT8 = (1 << 7);
const int BIT9 = (1 << 8);


const int MAX_PATH_SIZE = 2048;
const int RNG_SIZE = 4;

long LCSrandom(long max);
/* Determine size of vectors and any other container that implements the size() function.
This basically includes all types of containers except for the C++11 std::forward_list. */
template <class Container> inline long len(const Container& x)
{
	return x.size();
}
/* Determine array size in pickrandom() and various functions throughout the code.
Only works on actual arrays, not on vectors or other containers. */
template <typename T, size_t N> inline long len(const T(&x)[N])
{
	return N;
}
/* Override of the prior function for null-terminated C-strings as char arrays.
This override allows pickrandom() to pick a random character from a C-string we have as a char array. */
template <size_t N> inline long len(const char(&x)[N])
{
	return strlen(x);
}
/* Override of the prior function for null-terminated C-strings as char pointers.
This override allows pickrandom() to pick a random character from a C-string we have as a char pointer. */
inline long len(const char* x)
{
	return strlen(x);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline long len(char* x)
{
	return strlen(x);
}
/* Pick a random element from a vector/deque/map/std::string/C++11 std::array/etc. (e.g. a random string from a vector of strings).
It works on any container class that implements the [] operator, size() function, and value_type typename.
This doesn't work if the vector/deque/map/std::string/C++11 std::array/etc. has zero elements. */
template <class Container> inline typename Container::value_type& pickrandom(const Container& x)
{
	return const_cast<typename Container::value_type&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from an array (e.g. a random string from an array of strings).
This doesn't work if the array has zero elements. */
template <typename T, size_t N> inline T& pickrandom(const T(&x)[N])
{
	return const_cast<T&>(x[LCSrandom(len(x))]);
}
/* Pick a random element from a C-string.
Returns '\x0' (null character) for empty string. */
inline char& pickrandom(const char* x)
{
	return const_cast<char&>(x[LCSrandom(len(x))]);
}
/* Override for when it doesn't work with const in front of the char*
(compilers are weird about template function overrides) */
inline char& pickrandom(char* x)
{
	return x[LCSrandom(len(x))];
}
/* Deletes a specified pointer and sets it to NULL. */
template <typename T> inline void delete_and_nullify(T* &o)
{
	delete o;
	o = NULL;
}
/* Deletes and removes a specified pointer from a container. */
template <class Container> inline void delete_and_remove(Container& c, int i)
{
	if (i <= -1) return; // check for invalid index, and don't delete anything in this case
	delete c[i];
	c.erase(c.begin() + i);
}
/* Deletes and removes a specified pointer from 2 containers it's in.
c1 and c2 must not be the same container! */
template <class Container> inline void delete_and_remove(Container& c1, int i1, Container& c2, int i2)
{
	if (i1 <= -1 || i2 <= -1) return; // check for invalid index, and don't delete anything in this case
	if (c1[i1] == c2[i2])
	{ // it's the same pointer, so just delete it once, then remove it from both containers
		delete_and_remove(c1, i1);
		if (c1 != c2 || i1 != i2) c2.erase(c2.begin() + i2); // remove it from 2nd location, unless 2nd location is identical to 1st location
	}
	else
	{ // it's 2 different pointers, so delete them both and remove them from both containers
		delete_and_remove(c1, i1);
		delete_and_remove(c2, i2);
	}
}
/* Deletes and removes all pointers in a container. */
template <class Container> inline void delete_and_clear(Container& c)
{
	while (len(c))
	{
		delete c.back();
		c.pop_back();
	}
}
/* Deletes and removes all pointers that 2 containers have in common. */
template <class Container> inline void delete_and_clear(Container& c1, Container& c2)
{
	for (int i1 = len(c1) - 1; i1 >= 0; i1--)
		for (int i2 = len(c2) - 1; i2 >= 0; i2--)
			if (c1[i1] == c2[i2]) delete_and_remove(c1, i1, c2, i2);
}



//#define CH_USE_CP437



const int ENTER = 10;
const int ESC = 27;
const int SPACEBAR = 32;


enum Alignment
{
	ALIGN_ARCHCONSERVATIVE = -2,
	ALIGN_CONSERVATIVE,
	ALIGN_MODERATE,
	ALIGN_LIBERAL,
	ALIGN_ELITELIBERAL,
	ALIGN_STALINIST
};

enum UnlockTypes
{
	UNLOCK_DOOR,
	UNLOCK_CAGE,
	UNLOCK_CAGE_HARD,
	UNLOCK_CELL,
	UNLOCK_SAFE,
	UNLOCK_ARMORY,
	UNLOCK_VAULT,
	UNLOCKNUM
};

enum EndGameStatus
{
	ENDGAME_NONE,
	ENDGAME_CCS_APPEARANCE,
	ENDGAME_CCS_ATTACKS,
	ENDGAME_CCS_SIEGES,
	ENDGAME_CCS_DEFEATED,
	ENDGAME_MARTIALLAW,
	ENDGAMENUM
};



enum AnimalGlosses
{
	ANIMALGLOSS_NONE,//IMPORTANT THAT THIS BE HERE AT ZERO
	ANIMALGLOSS_TANK,
	ANIMALGLOSS_ANIMAL,
	ANIMALGLOSSNUM
};




const int ENCMAX = 18;
// ENCMAX _HAS_ to be 26 or less, or else there aren't enough letters


enum GameModes
{
	GAMEMODE_TITLE,
	GAMEMODE_BASE,
	GAMEMODE_SITE,
	GAMEMODE_CHASECAR,
	GAMEMODE_CHASEFOOT
};


enum FieldSkillRates
{
	FIELDSKILLRATE_FAST,
	FIELDSKILLRATE_CLASSIC,
	FIELDSKILLRATE_HARD
};


enum Laws
{
	LAW_STALIN = -2, // not a real law: this is -2 and is actually calculated based on views >=0 and <VIEWNUM-3
	LAW_MOOD, // not a real law: this is -1 and is likewise calculated based on views >=0 and <VIEWNUM-3
	LAW_ABORTION, // law #0, the first one that is actually in the law[] array
	LAW_ANIMALRESEARCH,
	LAW_POLICEBEHAVIOR,
	LAW_PRIVACY,
	LAW_DEATHPENALTY,
	LAW_NUCLEARPOWER,
	LAW_POLLUTION,
	LAW_LABOR,
	LAW_GAY,
	LAW_CORPORATE,
	LAW_FREESPEECH,
	LAW_FLAGBURNING,
	LAW_GUNCONTROL,
	LAW_TAX,
	LAW_WOMEN,
	LAW_CIVILRIGHTS,
	LAW_DRUGS,
	LAW_IMMIGRATION,
	LAW_ELECTIONS,
	LAW_MILITARY,
	LAW_PRISONS,
	LAW_TORTURE,
	LAWNUM
};

enum Crimes
{
	CRIME_STOLEGROUND,
	CRIME_UNLOCKEDDOOR,
	CRIME_BROKEDOWNDOOR,
	CRIME_ATTACKED_MISTAKE,
	CRIME_ATTACKED,
	CRIME_CARCHASE,
	CRIME_CARCRASH,
	CRIME_FOOTCHASE,
	CRIME_KILLEDSOMEBODY,
	CRIME_SHUTDOWNREACTOR,
	CRIME_POLICE_LOCKUP,
	CRIME_COURTHOUSE_LOCKUP,
	CRIME_PRISON_RELEASE,
	CRIME_JURYTAMPERING,
	CRIME_HACK_INTEL,
	CRIME_BREAK_SWEATSHOP,
	CRIME_BREAK_FACTORY,
	CRIME_HOUSE_PHOTOS,
	CRIME_CORP_FILES,
	CRIME_FREE_RABBITS,
	CRIME_FREE_BEASTS,
	CRIME_ARSON,
	CRIME_TAGGING,
	CRIME_ARMORY,
	CRIME_VANDALISM,
	CRIME_BANKVAULTROBBERY,
	CRIME_BANKTELLERROBBERY,
	CRIME_BANKSTICKUP,
	CRIMENUM
};

enum NewsStories
{
	NEWSSTORY_MAJOREVENT,
	NEWSSTORY_SQUAD_SITE,
	NEWSSTORY_SQUAD_ESCAPED,
	NEWSSTORY_SQUAD_FLEDATTACK,
	NEWSSTORY_SQUAD_DEFENDED,
	NEWSSTORY_SQUAD_BROKESIEGE,
	NEWSSTORY_SQUAD_KILLED_SIEGEATTACK,
	NEWSSTORY_SQUAD_KILLED_SIEGEESCAPE,
	NEWSSTORY_SQUAD_KILLED_SITE,
	NEWSSTORY_CCS_SITE,
	NEWSSTORY_CCS_DEFENDED,
	NEWSSTORY_CCS_KILLED_SIEGEATTACK,
	NEWSSTORY_CCS_KILLED_SITE,
	NEWSSTORY_CARTHEFT,
	NEWSSTORY_MASSACRE,
	NEWSSTORY_KIDNAPREPORT,
	NEWSSTORY_NUDITYARREST,
	NEWSSTORY_WANTEDARREST,
	NEWSSTORY_DRUGARREST,
	NEWSSTORY_GRAFFITIARREST,
	NEWSSTORY_BURIALARREST,
	NEWSSTORY_RAID_CORPSESFOUND,
	NEWSSTORY_RAID_GUNSFOUND,
	NEWSSTORY_HOSTAGE_RESCUED,
	NEWSSTORY_HOSTAGE_ESCAPES,
	NEWSSTORY_CCS_NOBACKERS,
	NEWSSTORY_CCS_DEFEATED,
	NEWSSTORY_PRESIDENT_IMPEACHED,
	NEWSSTORY_PRESIDENT_BELIEVED_DEAD,
	NEWSSTORY_PRESIDENT_FOUND_DEAD,
	NEWSSTORY_PRESIDENT_FOUND,
	NEWSSTORY_PRESIDENT_KIDNAPPED,
	NEWSSTORY_PRESIDENT_MISSING,
	NEWSSTORY_PRESIDENT_ASSASSINATED,
	NEWSSTORYNUM
};

const int SQUAD_NAMELEN = 40;



//just a float that is initialized to 0
#include "floatZero.h"
//Interrogation information for the InterrogationST system, to be
//dynamically created on capture and deleted when InterrogationST ends,
//referenced using a pointer typecast into one of the arguments
//of the target's current action.
#include "activityST.h"

//int get_associated_attribute(int skill_type);



//#ifdef	SITEMODE_CPP
// sitemode.cpp

#include "../creature/creature.h"
////

#include "../creature/deprecatedCreatureC.h"

#include "../creature/deprecatedCreatureD.h"

////
#include "../locations/locations.h"
#include "../vehicle/vehicletype.h"
#include "../vehicle/vehicle.h"
#include "../basemode/baseactions.h"
// for orderparty
#include "../basemode/reviewmode.h"
#include "advance.h"
void special_bouncer_assess_squad();
void special_bouncer_greet_squad();
void special_lab_cosmetics_cagedanimals();
void special_readsign(int sign);
void special_nuclear_onoff();
void special_lab_genetic_cagedanimals();
void special_policestation_lockup();
void special_courthouse_lockup();
void special_courthouse_jury();
void special_prison_control(short prison_control_type);
void special_intel_supercomputer();
void special_sweatshop_equipment();
void special_polluter_equipment();
void special_house_photos();
void special_corporate_files();
void special_radio_broadcaststudio();
void special_news_broadcaststudio();
void special_graffiti();
void special_armory();
void special_display_case();
void special_security_checkpoint();
void special_security_metaldetectors();
void special_security_secondvisit();
void special_bank_teller();
void special_bank_money();
void special_bank_vault();
void special_ccs_boss();
void special_oval_office();
#include "stealth.h"
#include "miscactions.h"
void reloadparty(bool wasteful = false);
#include "sitedisplay.h"
void prepareencounter(short type, char sec);
char addsiegeencounter(char type);
#include "../items/lootTypePoolItem.h"
	// for commondisplay.h
#include "../common/commondisplay.h"
// for printparty()
#include "../common/commonactions.h"

enum EndTypes
{
	END_BUT_NOT_END = -2,
	END_OTHER = -1,
	END_WON,
	END_HICKS,
	END_CIA,
	END_POLICE,
	END_CORP,
	END_REAGAN,
	END_DEAD,
	END_PRISON,
	END_EXECUTED,
	END_DATING,
	END_HIDING,
	END_DISBANDLOSS,
	END_DISPERSED,
	END_CCS,
	END_FIREMEN,
	END_STALIN,
	ENDNUM
};


/* common - test for possible game over */
char endcheck(char cause = END_OTHER);
/* common - tests if the person is a wanted criminal */
bool iscriminal(CreatureJustice cr);
/* common - applies a crime to a person */
void criminalize(DeprecatedCreature& cr, short crime);
// for squadsize
#include "../common/translateid.h"
// for  id_getcar
/* review squad equipment */
void equip(vector<Item *> &loot, int loc);
/* daily - returns true if the site type supports high security */
char securityable(int type);
#include "../daily/siege.h"
//for void conquertext();
#include "../combat/fight.h"
#include "../combat/fightCreature.h"  
//for void enemyattack();
#include "../combat/haulkidnap.h"
#include "../combat/haulkidnapCreature.h"
//for void kidnapattempt();
#include "../combat/chase.h"
//for void makechasers(long sitetype,long sitecrime);

int getEncounterAnimalGloss(const int e);
bool get_encounter_cantbluff_is_zero(const int e);
bool get_encounter_cantbluff_is_two(const int e);
bool get_encounter_cantbluff_is_one(const int e);
bool isThereASiteAlarm();
void setSiteAlarmOne();
bool isThereNoActivesquad();
void resetSiteAlarm();
#include "../cursesAlternativeConstants.h"
#include "../common/creaturePoolCreature.h"
#include "../locations/locationsPool.h"
#include "../common/creaturePool.h"
#include "../common/musicClass.h"

extern bool encounterwarnings;

extern bool mapshowing;

extern char ccs_kills;
extern char endgamestate;
extern char foughtthisround;
extern char showcarprefs;

extern chaseseqst chaseseq;

extern coordinatest loc_coord;

extern Deprecatednewsstoryst *sitestory;
extern Deprecatedsquadst *activesquad;

extern int ccs_boss_kills;
extern int sitecrime;
extern MusicClass music;

extern short fieldskillrate;
extern short lawList[LAWNUM];
extern short mode;
extern short offended_amradio;
extern short offended_cablenews;
extern short party_status;
extern short postalarmtimer;
extern short sitealarmtimer;
extern short sitealienate;
extern short sitetype;
extern siteblockst levelmap[MAPX][MAPY][MAPZ];

extern UniqueCreatures uniqueCreatures;
extern vector<Item *> groundloot;


void emptyEncounter();
void delete_and_clear_groundloot();
bool isThereGroundLoot();

void deleteVehicle(int carid);
void deleteVehicles(vector<Vehicle *>& carid);
enum INDEX_WITH_SPECIAL_MEANING {
	MULTIPLE_LIVING_MEMBERS = -2,
	NO_VALID_MEMBERS = -1,
};
vector<NameAndAlignment> getEncounterNameAndAlignment();
char haveActiveSquadTalk(const int sp, const int tk);
void printActiveSquadTalkOptions();
bool activeSquadMemberIsAliveAndExists(const int sp);
CantBluffAnimal encounterGetCantBluffAnimal(const int t);
CreatureBio encounterGetCreatureBio(const int t);
vector<NameAndAlignment> getEncounterNameAndAlignment();
int checkForPeopleWhoCanRecruit();
void addNewRecruit(int i, int e);
int countactivesquadhostages();
void assembleActiveSquad();
/* base - review - assemble a squad */
void criminalizeEncounterPrisonerEscape(const int e);
void duplicateEncounterMember(const int e);
void unpersonLastEncounterMember();
void getRandomLoot(int cursite);
Weapon* spawnNewWeapon(string newWeaponType);
Armor* spawnNewArmor(string newArmorType);

void giveActiveSquadThisLoot(Item* de);
void putBackSpecials(const int olocx, const int olocy, const int olocz);
void spawnCreatureCEO();

void killActiveSquad();
int getactivesquadCarID(const int p);
void set_sitestory_type();
int getactivesquadBase();


char shouldWeBailOnBase();
bool isActiveSquadAnonymous();
void set_site_story_as_last_news_story();
void setSiteStoryClaimedZero();
void resetSiteGlobals();
void setCurrentSite(const short i);
void resetCCSSiegeGlobals();

int getEncounterCarID(const int e);
int getEncounterIsDriver(const int e);

void printMap(const bool has_cameras);
void printLocationSpecificWarning(const int lsite, const bool ccsRent);
void printLocationNameAndAlarm(const string lname, const int postalarmtimer, const int locz);
void printCONSERVATIVES_SUSPICIOUS();
void printCONSERVATIVES_ALARMED();
void printALIENATED_EVERYONE();
void printALIENATED_MASSES();
void printCONSERVATIVE_REINFORCEMENTS_INCOMING();
void printSiegeName(const string sname, const int locz);
bool isPrisoner(const string tkname);
void printEnemyCar(const string cname, const int v);
void printClearChaseScreen();
void printEnemyCarPassenger(const string ename, const int vnum, const int pnum, const bool driver);
void printReflectOnIneptitude();
void printSneakOrRun(const bool evade);
void printReorganize(const int libnum);
void printReleaseHostages(const bool hostages);
void printReleaseOppressed();
void printEquipAndFight(const bool enemy);
void printEvade();
void printUseOrGraffiti(const bool graffiti, const bool print_me);
void printPlayerSiteOptions(const bool isThereASiteAlarm, const bool enemy, const int partysize, const int party_status, const bool talkers);
void printShowEncounterWarning(const int numenc, const bool squadmoved);
void printTheLandlordIsIn();
void printTheLandlordIsOut();
void printTheCEOIsIn();
void printTheCEOIsOut();
void printTheCEOHasFled();
void printEmptyBench();
void printFullBench();
void printRestaurantTableFull();
void printRestaurantTableHiding();
void printCafeComputerEmpty();
void printCafeComputerFull();
void printTheCCSIsBroken();
void logBailOnBase(const string aname, const string sitename);
void printFoughtOffConservatives();
void printSneakPast();
void printYouFind(const string that_thing);
void printFreeThem(const int followers);
void printYouHaveEnemiesFirst();
void printFreeThemWithoutYou(const int followers, const int actgot);
void printIWontTalkToYou(const string tkname);
void printCreatureEncounter(const int t, const int talign, const string tname, const string tage);
void printToWhom();
void printActiveSquadTalkOptionsHeader();
void printMusicEnabled(const bool musice);
void printEncounterWarnings(const bool ewarn);
void printSitemodeOptions();
void printSitemodeOptionsHeader();
void printWhichWay();
void printSquadSubduedHostagesFreed(const int hostages);
void printItOpensWithAlarm();
void printVaultIsImpenetrable();
void printUnlockedButAlarmed(const bool locked);
void printShakeHandle(const bool locked, const bool has_security);
void printLockpickPrompt();
void printLockSetOffAlarm();
void printAlarmGoesOff();
//#endif//SITEMODE_CPP
//#endif// INCLUDES_H_INCLUDED
