
const int CREATURE_NAMELEN = 40;

enum Activity
{
	ACTIVITY_NONE,
	ACTIVITY_VISIT,
	ACTIVITY_HOSTAGETENDING,
	ACTIVITY_TROUBLE,
	ACTIVITY_GRAFFITI,
	ACTIVITY_COMMUNITYSERVICE,
	ACTIVITY_SELL_ART,
	ACTIVITY_SELL_MUSIC,
	ACTIVITY_SELL_TSHIRTS,
	ACTIVITY_DONATIONS,
	ACTIVITY_SELL_DRUGS,
	ACTIVITY_PROSTITUTION,
	ACTIVITY_POLLS,
	ACTIVITY_CCFRAUD,
	ACTIVITY_DOS_RACKET,
	ACTIVITY_DOS_ATTACKS,
	ACTIVITY_HACKING,
	ACTIVITY_REPAIR_ARMOR,
	ACTIVITY_MAKE_ARMOR,
	ACTIVITY_STEALCARS,
	ACTIVITY_WHEELCHAIR,
	ACTIVITY_BURY,
	ACTIVITY_WRITE_BLOG,
	ACTIVITY_WRITE_LETTERS,
	ACTIVITY_WRITE_GUARDIAN,
	ACTIVITY_TEACH_POLITICS,
	ACTIVITY_TEACH_FIGHTING,
	ACTIVITY_TEACH_COVERT,
	ACTIVITY_STUDY_DEBATING,
	ACTIVITY_STUDY_MARTIAL_ARTS,
	ACTIVITY_STUDY_DRIVING,
	ACTIVITY_STUDY_PSYCHOLOGY,
	ACTIVITY_STUDY_FIRST_AID,
	ACTIVITY_STUDY_LAW,
	ACTIVITY_STUDY_DISGUISE,
	ACTIVITY_STUDY_SCIENCE,
	ACTIVITY_STUDY_BUSINESS,
	ACTIVITY_STUDY_GYMNASTICS,
	ACTIVITY_STUDY_MUSIC,
	ACTIVITY_STUDY_ART,
	ACTIVITY_STUDY_TEACHING,
	ACTIVITY_STUDY_WRITING,
	ACTIVITY_STUDY_LOCKSMITHING,
	ACTIVITY_STUDY_COMPUTERS,
	ACTIVITY_STUDY_FENCING,
	ACTIVITY_STUDY_WEAVING,
	ACTIVITY_STUDY_RELIGION,
	ACTIVITY_STUDY_CLUB,
	ACTIVITY_STUDY_STREETSENSE,
	ACTIVITY_STUDY_THROWING,
	ACTIVITY_STUDY_STEALTH,
	ACTIVITY_STUDY_SEDUCTION,
	ACTIVITY_CLINIC,
	ACTIVITY_HEAL,
	ACTIVITY_SLEEPER_LIBERAL,
	ACTIVITY_SLEEPER_CONSERVATIVE,
	ACTIVITY_SLEEPER_SPY,
	ACTIVITY_SLEEPER_RECRUIT,
	ACTIVITY_SLEEPER_SCANDAL,
	ACTIVITY_SLEEPER_EMBEZZLE,
	ACTIVITY_SLEEPER_STEAL,
	ACTIVITY_SLEEPER_JOINLCS,
	ACTIVITY_RECRUITING,
	ACTIVITY_AUGMENT,
	ACTIVITYNUM
};

enum CreatureGender
{
	GENDER_NEUTRAL,
	GENDER_MALE,
	GENDER_FEMALE,
	// Used to get some more specific names.
	GENDER_WHITEMALEPATRIARCH,
	// Used in creature creation.
	GENDER_MALE_BIAS,
	GENDER_FEMALE_BIAS,
	GENDER_RANDOM
};
enum CheckDifficulty
{
	DIFFICULTY_AUTOMATIC = 1,
	DIFFICULTY_VERYEASY = 3,
	DIFFICULTY_EASY = 5,
	DIFFICULTY_AVERAGE = 7,
	DIFFICULTY_CHALLENGING = 9,
	DIFFICULTY_HARD = 11,
	DIFFICULTY_FORMIDABLE = 13,
	DIFFICULTY_HEROIC = 15,
	DIFFICULTY_SUPERHEROIC = 17,
	DIFFICULTY_IMPOSSIBLE = 19
};
enum CreatureAttribute
{
	ATTRIBUTE_STRENGTH,
	ATTRIBUTE_INTELLIGENCE,
	ATTRIBUTE_WISDOM,
	ATTRIBUTE_AGILITY,
	ATTRIBUTE_HEALTH,
	ATTRIBUTE_CHARISMA,
	ATTRIBUTE_HEART,
	ATTNUM
};
enum CreatureSkill
{
	PSEUDOSKILL_ESCAPEDRIVE = -2,
	PSEUDOSKILL_DODGEDRIVE,
	SKILL_ART = 0,
	SKILL_AXE,
	SKILL_BUSINESS,
	SKILL_CLUB,
	SKILL_COMPUTERS,
	SKILL_DISGUISE,
	SKILL_DODGE,
	SKILL_DRIVING,
	SKILL_FIRSTAID,
	SKILL_HEAVYWEAPONS,
	SKILL_KNIFE,
	SKILL_LAW,
	SKILL_HANDTOHAND, // actually this is called "Martial Arts"
	SKILL_MUSIC,
	SKILL_PERSUASION,
	SKILL_PISTOL,
	SKILL_PSYCHOLOGY,
	SKILL_RELIGION,
	SKILL_RIFLE,
	SKILL_SCIENCE,
	SKILL_SECURITY,
	SKILL_SEDUCTION,
	SKILL_SHOTGUN,
	SKILL_SMG,
	SKILL_STEALTH,
	SKILL_STREETSENSE,
	SKILL_SWORD,
	SKILL_TAILORING,
	SKILL_TEACHING,
	SKILL_THROWING,
	SKILL_WRITING,
	SKILLNUM
};
enum ActivityMenuChecks // these codes are used to add special checks to what you're allowed to pick in activity menus
{
	ACTIVITIY_MENU_CHECK_NONE,
	ACTIVITIY_MENU_CHECK_PRESS,
	ACTIVITIY_MENU_CHECK_AGE,
	ACTIVITIY_MENU_CHECK_CAN_WALK,
	ACTIVITIY_MENU_CHECK_WHEELCHAIR,
	ACTIVITIY_MENU_CHECK_CAN_AUGMENT
};
//typedef map< Activity, string> ActivityToString;
struct ActivityAndString {
	int i;
	Activity activity;
	string str;
	string str2;
	string str3;
	ActivityMenuChecks check;
	CreatureSkill skill;
	ActivityAndString(Activity activity_, string str_) : i(0), activity(activity_), str(str_), skill(SKILLNUM) {}
	ActivityAndString(int i_, Activity activity_, string str_) : i(i_), activity(activity_), str(str_), skill(SKILLNUM) {}
	ActivityAndString(int i_, Activity activity_, string str_, ActivityMenuChecks check_) : i(i_), activity(activity_), str(str_), skill(SKILLNUM), check(check_) {}
	ActivityAndString(int i_, Activity activity_, string str_, string str2_, string str3_, CreatureSkill skill_) : i(i_), activity(activity_), str(str_), str2(str2_), str3(str3_), skill(skill_) {}
};

enum CreatureTypes
{
	CREATURE_BOUNCER,
	CREATURE_SECURITYGUARD,
	CREATURE_SCIENTIST_LABTECH,
	CREATURE_SCIENTIST_EMINENT,
	CREATURE_CORPORATE_MANAGER,
	CREATURE_CORPORATE_CEO,
	CREATURE_WORKER_SERVANT,
	CREATURE_WORKER_JANITOR,
	CREATURE_WORKER_SWEATSHOP,
	CREATURE_WORKER_FACTORY_NONUNION,
	CREATURE_WORKER_FACTORY_CHILD,
	CREATURE_WORKER_SECRETARY,
	CREATURE_WORKER_FACTORY_UNION,
	CREATURE_LANDLORD,
	CREATURE_TEENAGER,
	CREATURE_COP,
	CREATURE_SWAT,
	CREATURE_DEATHSQUAD,
	CREATURE_FIREFIGHTER,
	CREATURE_EDUCATOR,
	CREATURE_GANGUNIT,
	CREATURE_JUDGE_LIBERAL,
	CREATURE_JUDGE_CONSERVATIVE,
	CREATURE_AGENT,
	CREATURE_RADIOPERSONALITY,
	CREATURE_NEWSANCHOR,
	CREATURE_GENETIC,
	CREATURE_GUARDDOG,
	CREATURE_PRISONER,
	CREATURE_JUROR,
	CREATURE_LAWYER,
	CREATURE_SEWERWORKER,
	CREATURE_COLLEGESTUDENT,
	CREATURE_MUSICIAN,
	CREATURE_MATHEMATICIAN,
	CREATURE_TEACHER,
	CREATURE_HSDROPOUT,
	CREATURE_BUM,
	CREATURE_GANGMEMBER,
	CREATURE_CRACKHEAD,
	CREATURE_PRIEST,
	CREATURE_ENGINEER,
	CREATURE_FASTFOODWORKER,
	CREATURE_BAKER,
	CREATURE_BARISTA,
	CREATURE_BARTENDER,
	CREATURE_TELEMARKETER,
	CREATURE_CARSALESMAN,
	CREATURE_OFFICEWORKER,
	CREATURE_FOOTBALLCOACH,
	CREATURE_PROSTITUTE,
	CREATURE_MAILMAN,
	CREATURE_GARBAGEMAN,
	CREATURE_PLUMBER,
	CREATURE_CHEF,
	CREATURE_CONSTRUCTIONWORKER,
	CREATURE_AMATEURMAGICIAN,
	CREATURE_TANK,
	CREATURE_MERC,
	CREATURE_HICK,
	CREATURE_SOLDIER,
	CREATURE_VETERAN,
	CREATURE_HARDENED_VETERAN,
	CREATURE_PRISONGUARD,
	CREATURE_HIPPIE,
	CREATURE_CRITIC_ART,
	CREATURE_CRITIC_MUSIC,
	CREATURE_SOCIALITE,
	CREATURE_PROGRAMMER,
	CREATURE_RETIREE,
	CREATURE_PAINTER,
	CREATURE_SCULPTOR,
	CREATURE_AUTHOR,
	CREATURE_JOURNALIST,
	CREATURE_DANCER,
	CREATURE_PHOTOGRAPHER,
	CREATURE_CAMERAMAN,
	CREATURE_HAIRSTYLIST,
	CREATURE_FASHIONDESIGNER,
	CREATURE_CLERK,
	CREATURE_THIEF,
	CREATURE_ACTOR,
	CREATURE_YOGAINSTRUCTOR,
	CREATURE_MARTIALARTIST,
	CREATURE_ATHLETE,
	CREATURE_BIKER,
	CREATURE_TRUCKER,
	CREATURE_TAXIDRIVER,
	CREATURE_NUN,
	CREATURE_MUTANT,
	CREATURE_DOCTOR,
	CREATURE_NURSE,
	CREATURE_CCS_VIGILANTE,
	CREATURE_CCS_ARCHCONSERVATIVE,
	CREATURE_POLITICALACTIVIST,
	CREATURE_CCS_MOLOTOV,
	CREATURE_CCS_SNIPER,
	CREATURE_PSYCHOLOGIST,
	CREATURE_LOCKSMITH,
	CREATURE_MILITARYPOLICE,
	CREATURE_SEAL,
	CREATURE_MILITARYOFFICER,
	CREATURE_BANK_TELLER,
	CREATURE_BANK_MANAGER,
	CREATURE_SECRET_SERVICE,
	CREATURE_POLITICIAN,
	CREATURENUM
};

struct RecruitData
{
	CreatureTypes type;
	char name[CREATURE_NAMELEN];
	int difficulty;
	RecruitData(CreatureTypes type_, const char* name_, int difficulty_) : type(type_), difficulty(difficulty_) { strcpy(name, name_); }
	RecruitData(CreatureTypes type_, const string name_, int difficulty_) : type(type_), difficulty(difficulty_) { strcpy(name, name_.c_str()); }
};
enum SpecialWounds
{
	SPECIALWOUND_TEETH,
	SPECIALWOUND_RIGHTEYE,
	SPECIALWOUND_LEFTEYE,
	SPECIALWOUND_NOSE,
	SPECIALWOUND_TONGUE,
	SPECIALWOUND_RIGHTLUNG,
	SPECIALWOUND_LEFTLUNG,
	SPECIALWOUND_HEART,
	SPECIALWOUND_LIVER,
	SPECIALWOUND_STOMACH,
	SPECIALWOUND_RIGHTKIDNEY,
	SPECIALWOUND_LEFTKIDNEY,
	SPECIALWOUND_SPLEEN,
	SPECIALWOUND_RIBS,
	SPECIALWOUND_NECK,
	SPECIALWOUND_UPPERSPINE,
	SPECIALWOUND_LOWERSPINE,
	SPECIALWOUNDNUM
};
enum BodypartBreakType {
	HEAVY, POKE, BREAK, ANY
};
