
private int Master;                     // 帮主标识
private int Master2;                    // 帮主标识２

private string MasterName;              // 帮主姓名
private string MasterName2;             // 帮主姓名２

private string MasterId;                // 帮主帐号
private string MasterId2;               // 帮主帐号２

private string * Presbyter = ({ });	// 长老

private string * Manager4 = ({ });	// 堂主
private string * Manager5 = ({ });	// 香主
private string * Manager6 = ({ });	// 精英

private string * trader = ({ });		// 商人

private string Creator;                 // 创始人
private int CreateTime;                 // 创建时间

// private int Develop;                 // 发展系数
private int Gold;                       // 金库

private int Research;                   // 研究技能
private int ResearchLevel;              // 研究层次

// 其他研究技能
private mapping Researchs;                   // 研究技能


private int Total;                      // 帮众人数

private string Bulletin;                // 公告
private string Note;                    // 大事记

private static int War;                 // 战争时间
private static int Battle;              // 战场编号
private static object Enemy95;          // 敌方总管

private int iHouse;			// 厢房的数量
private int iStable;			// 安定值
private int iScience;			// 研究力
private int iScienceTime;		// 研究力结束时间
private int iFavour;			// 人气度
private int iStore;			// 储备
private int iGrade;			// 规模
private int iGradeTime;			// 规模提升的结束标志
private static int iGradeWarTime;	// 规模提升的怪物攻需的开始时间
private static int iWarDamage;		// 怪物攻城的损伤
private int iTrain;			// 训练度
private int iTrainTime;			// 训练度的提升结束标志
private int iEngage;			// 雇佣NPC的数量
private int iStrong;			// 强化技能开启标志，每位对应多个强化技能
private static int iStrongCount;	// 强化技能的数量

private int demissnumber;		// 禅让的number
private int demisstime;			// 禅让的生效时间
private int producttime;		// 制作成品的时间
private string productfile;		// 成品路径
private string * productfile2;		// 成品路径

private int buytime;			// 购买图纸的时间

// 帮派战争相关的临时数据
private static int iWood;		// 木头
private static int iWeapon;		// 战斗傀儡 1 表示已经有了，否则就是完成的时间
private static int iLevel1;		// 战场总管的等级
private static int iLevel2;		// 战场部队的等级
private static int iLevel3;		// 战场箭塔的等级
private static int iLevel1time;		// 战场总管的升级时间
private static int iLevel2time;		// 战场部队的升级时间
private static int iLevel3time;		// 战场箭塔的升级时间


// 厢房数量
int set_house(int count)
{
	count = range_value(count, 1, iGrade);
	return iHouse = count;
}

int get_house()
{
	return iHouse;
}

// 厢房数量
int set_producttime(int count)
{
	return producttime = count;
}

int get_producttime()
{
	return producttime;
}

// 厢房数量
string set_productfile(string file)
{
	return productfile = file;
}

string get_productfile()
{
	return productfile;
}

string * set_productfile2(string * file)
{
	return productfile2  = file;
}

int get_buytime() {return buytime;}

int set_buytime(int i) {return buytime = i;}

string * get_productfile2()
{
	if (productfile2==0) productfile2 = ({ });
	return productfile2;
}

int add_house(int count) {return set_house(iHouse+count);}

// 安定度
int set_stable(int count)
{
	count = range_value(count, 0, 10000);
	return iStable = count;
}

int get_stable()
{
	return iStable;
}
int add_stable(int count) {return set_stable(iStable+count);}

// 研究力
int set_science(int count)
{
	count = range_value(count, 1, iGrade*4);
	return iScience = count;
}

int get_science()
{
	return iScience;
}

int add_science(int count) {return set_science(iScience+count);}

// 研究力提升的结束时间
int set_sciencetime(int count)
{
	return iScienceTime = count;
}

int get_sciencetime()
{
	return iScienceTime;
}

// 人气度
int set_favour(int count)
{
	count = range_value(count, 0, iGrade*2000);
	return iFavour = count;
}

int get_favour()
{
	return iFavour;
}

int add_favour(int count) {return set_favour(iFavour+count);}

// 储备
int set_store(int count)
{
	count = range_value(count, 0, iGrade*500);
	return iStore = count;
}

int get_store()
{
	return iStore;
}

int add_store(int count) {return set_store(iStore+count);}

// 帮派规模
int set_grade(int count)
{
	count = range_value(count, 1, 5);
	return iGrade = count;
}

int get_grade()
{
	return iGrade;
}

int add_grade(int count) {return set_grade(iGrade+count);}

// 帮派规模提升的结束时间
int set_gradetime(int count)
{
	return iGradeTime = count;
}

int get_gradetime()
{
	return iGradeTime;
}

// 帮派规模提升怪物攻城的开始时间
int set_gradewartime(int count)
{
	return iGradeWarTime = count;
}

int get_gradewartime()
{
	return iGradeWarTime;
}

// 帮派规模提升怪物攻城的开始时间
int set_wardamage(int count)
{
	return iWarDamage = count;
}

int get_wardamage()
{
	return iWarDamage;
}

int add_wardamage(int count) {return set_wardamage(get_wardamage()+count);}

// 训练度
int set_train(int count)
{
	count = range_value(count, 0, 20*iGrade);
	return iTrain = count;
}

int get_train()
{
	return iTrain;
}

int add_train(int count) {return set_train(iTrain+count);}

// 训练度提升结束时间
int set_traintime(int count)
{
	return iTrainTime = count;
}

int get_traintime()
{
	return iTrainTime;
}

// 雇佣的npc数量
int set_engage(int count)
{
	count = range_value(count, 0, 4+iGrade*2);
	return iEngage = count;
}

int get_engage()
{
	return iEngage;
}

int add_engage(int count) {return set_engage(iEngage+count);}

// 强化技能标志
int get_strong(int type)
{
	if (type<0) return;
	if (iStrong & (1<<type)) return 1;
	return 0;
}

int set_strong(int type)
{
	if (type<0) return;
	iStrong = iStrong | (1<<type);
	return 1;
}

int get_strongcount()
{
	int count, i;
	count = 0;
	for (i=0;i<=8;i++)
		if (iStrong & (1<<i)) count ++;
	return count;
}

int get_max_number()
{
/*	
	int count;
	count = iGrade;
	if (count<1) count = 1;
	return count* 40;
*/
	return 200;	
}

string * get_trader()
{
	return copy(trader);
}

void set_trader( string * number)
{
	trader = copy(number);
}

string * get_manager4()
{
	return copy(Manager4);
}

void set_manager4( string * number)
{
	Manager4 = copy(number);
}

string * get_manager5()
{
	return copy(Manager5);
}

void set_manager5( string * number)
{
	Manager5 = copy(number);
}

string * get_manager6()
{
	return copy(Manager6);
}

void set_manager6( string * number)
{
	Manager6 = copy(number);
}

// 禅让的id
int get_demissnumber()
{
	return demissnumber;
}

// 
void set_demissnumber( int number)
{
	demissnumber = number;
}

// 禅让的结束时间
int get_demisstime()
{
	return demisstime;
}

// 
int set_demisstime( int number)
{
	return demisstime = number;
}

// 木头储备
int set_wood(int count)
{
	return iWood = count;
}

int get_wood()
{
	return iWood;
}

int add_wood(int count) {return set_wood(iWood+count);}

// 战斗傀儡
int set_weapon(int count)
{
	return iWeapon = count;
}

int get_weapon()
{
	return iWeapon;
}

// 总管等级
int set_level1(int count)
{
	return iLevel1 = count;
}

int get_level1()
{
	return iLevel1;
}

int add_level1(int count) {return set_level1(iLevel1+count);}

// 部队等级
int set_level2(int count)
{
	return iLevel2 = count;
}

int get_level2()
{
	return iLevel2;
}

int add_level2(int count) {return set_level2(iLevel2+count);}

// 箭塔等级
int set_level3(int count)
{
	return iLevel3 = count;
}

int get_level3()
{
	return iLevel3;
}

int add_level3(int count) {return set_level3(iLevel3+count);}

// 函数：获取总管升级时间
int get_level1_time() { return iLevel1time; }

int set_level1_time( int number ) { return iLevel1time = number; }

// 函数：获取部队升级时间
int get_level2_time() { return iLevel2time; }

int set_level2_time( int number ) { return iLevel2time = number; }

// 函数：获取总管升级时间
int get_level3_time() { return iLevel3time; }

int set_level3_time( int number ) { return iLevel3time = number; }

// -------------------------------------------------------------

// 函数：获取帮主标识
int get_master() { return Master; }

// 函数：设置帮主标识
int set_master( int number ) { return Master = number; }

// 函数：获取帮主标识２
int get_master_2() { return Master2; }

// 函数：设置帮主标识２
int set_master_2( int number ) { return Master2 = number; }

// 函数：获取长老标识１
string * get_presbyter() { return copy(Presbyter); }

// 函数：设置长老标识１
void set_presbyter( string * list ) { return Presbyter = copy(list); }

// -------------------------------------------------------------

// 函数：获取帮主姓名
string get_master_name() { return MasterName ? MasterName : "－－"; }

// 函数：设置帮主姓名
string set_master_name( string name ) { return MasterName = name; }

// 函数：获取帮主姓名２
string get_master_name_2() { return MasterName2 ? MasterName2 : "－－"; }

// 函数：设置帮主姓名２
string set_master_name_2( string name ) { return MasterName2 = name; }

// -------------------------------------------------------------

// 函数：获取帮主帐号
string get_master_id() { return MasterId ? MasterId : ""; }

// 函数：设置帮主帐号
string set_master_id( string name ) { return MasterId = name; }

// 函数：获取帮主帐号２
string get_master_id_2() { return MasterId2 ? MasterId2 : ""; }

// 函数：设置帮主帐号２
string set_master_id_2( string name ) { return MasterId2 = name; }

// -------------------------------------------------------------

// 函数：获取创始人
string get_creator() { return Creator ? Creator : "－－"; }

// 函数：设置创始人
string set_creator( string name ) { return Creator = name; }

// 函数：获取创建时间
int get_create_time() { return CreateTime; }

// 函数：设置创建时间
int set_create_time( int time ) { return CreateTime = time; }

// 函数：获得势力
int get_power()
{
	int ret;
	ret = (iStable+iFavour)/100 + iTrain + iScience;
	if (ret<1) ret = 1; 
	return ret;
}

/*  // 函数：获取发展系数
int get_develop() { return Develop; }

// 函数：设置发展系数
int set_develop( int point ) { return Develop = point; }    */

// 函数：获取金库
int get_gold() { return Gold; }

// 函数：设置金库
int set_gold( int point ) { return Gold = range_value(point, 0, iGrade*40000000); }

// 函数：增添金库
int add_gold( int point ) { return set_gold( Gold + point ); }

// 函数：获取研究技能
int get_research() { return Research; }

// 函数：设置研究技能
int set_research( int point ) { return Research = point; }

// 函数：获取研究层次
int get_research_level() { return ResearchLevel; }

// 函数：设置研究层次
int set_research_level( int point ) { return ResearchLevel = point; }

// 函数：获取研究技能
mapping get_researchs() 
{ 
	if (Researchs==0) Researchs = ([ ]);
	return Researchs; 
}

// 函数：设置研究技能
int set_researchs( int point, int level ) 
{ 
	if (Researchs==0) Researchs = ([ ]);
	if (level==0)
	{
		map_delete(Researchs, point);
	}
	else	
		Researchs[point] = level;
	return level; 
}

// 函数：获取帮众人数
int get_total() { return Total; }

// 函数：设置帮众人数
int set_total( int point ) { return Total = point; }

// 函数：增添帮众人数
int add_total( int point ) { return set_total( Total + point ); }

// 函数：获取公告
string get_bulletin() { return Bulletin ? Bulletin : "Hãy nhấn “Biên tập” sau đó nhấn “Xác nhận”."; }

// 函数：设置公告
string set_bulletin( string text ) { return Bulletin = text; }

// 函数：获取大事记
string get_note() { return Note ? Note : "Hãy nhấn “Biên tập” sau đó nhấn “Xác nhận”."; }

// 函数：设置大事记
string set_note( string text ) { return Note = text; }

// -------------------------------------------------------------

// 函数：获取战争时间
int get_war() { return War; }

// 函数：设置战争时间
int set_war( int flag ) { return War = flag; }

// 函数：获取战场编号
int get_battle() { return Battle; }

// 函数：设置战场编号
int set_battle( int flag ) { return Battle = flag; }

// 函数：获取敌方总管
object get_enemy_95() { return Enemy95; }

// 函数：设置敌方总管
object set_enemy_95( object who ) { return Enemy95 = who; }
