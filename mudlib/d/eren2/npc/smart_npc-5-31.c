#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
void do_defense(int n);
void do_remove_defense(int n);
string  do_choose_weapon_attack(object target);
void setup_npc_skill(string name,string char_type,string random_choose,
        int special,int basic,int autoweapon,string weapon_dir); 
/*
void auto_npc_setup(string name, int basic, int special, int auto_weapon, string weapon_dir, string char_type, string my_char) {
        
//      name ---  char name, used in random NPC generator so they have same name.
//      basic --- basic skill level (move,spells,magic,...)     
//      special --- special skill level (diesword,shenji-blade,anxiang-steps,...)
//      auto-weapon --- 0: Do not define weapon; 1: auto define a weapon using sword, blade ....
//      weapon_dir ---- when auto define weapon, the directory of weapon obj located, for exampe, "/d/fy/"
//      char_type ---- fighter_weapon,fighter_unarmed,healer,ironman,magician,zombie-wiper,
//              if you call smart_fight() in chat_chance, NPC will react according to this setting.
//              healer: heal friend in fight, ironman: have iron-cloth
//              magician: using sanqing skills.
//              char_num:
//      my_char ---- this lets you define exactly the type of NPC you want, check string *type for the correct name. 
        string *basic_skill= ({"move","dodge","parry","unarmed","blade","sword",
        "staff","axe","spells","magic","spear","throwing","hammer","whip","force",
        "perception","lingxi-zhi","yue-strike","xiaohun-sword","xiaohun-whip"}); 
        string *type_fighter_w= ({
        "shenji", "bat-blade", "lefthand", "diesword","shortsong",
        "dagou-stick","yue-spear","taiji-sword","sharen-sword","longfenghuan",
        "cloudstaff","doomsword","tanzhi-shentong","qingfeng-sword","liuquan-steps",
        "qiusheng-blade","xuezhan-spear","xuanyuan-axe1","xuanyuan-axe2","softsword",
        "ittouryu","ass-hammer","pangu-hammer","thunderwhip","xinyue-dagger","feixian",         
        "xuezhan-spear2","nine-moon-sword","qingpingsword","siqi-sword",
        });
        string *type_fighter_u = ({"dragonstrike","doomstrike","taiji","hanshan-strike",
                "yiyangzhi","enmeiryu","tenderzhi","wolf-strike","bazhentu","wolf-claw",
                "nine-moon-claw","yue-strike","luoriquan","shadowsteps",
                "yizhichan","mukuha","yaozhan",
                });
        string *type_healer =({});
   string *type_magician = ({"sq-male","sq-male2","sq-female","dz-an","sq-female2",});
        string *type_ironman= ({"jin-gang","sl-hammer","sl-axe","sl-spear",
                        "sl-yijinjing",});
        
        int i, total, x;
        
        string random_choose;
        int size_w,size_u,size_i,size_m; 
        size_w=sizeof(type_fighter_w);
        size_u=sizeof(type_fighter_u);
        size_i=sizeof(type_ironman);
        size_m=sizeof(type_magician); 
//      setup all basic skills and defensive special skills
        for (i=1;i<sizeof(basic_skill);i++){
                set_skill(basic_skill[i],basic);
                }
        set_skill("anxiang-steps", special);
        map_skill("move","anxiang-steps");
        
//      random choose npc skills        
        if (my_char == "all")
                switch (char_type) {
                        case "fighter_w": random_choose= type_fighter_w[random(size_w)];
                                                break;
                        case "fighter_u": random_choose= type_fighter_u[random(size_u)];                
                                                break;
                        case "ironman":  random_choose= type_ironman[random(size_i)];
                                                break;
                        case "magician":  random_choose= type_magician[random(size_m)];
                                                break;
                        case "all":     total=size_w+size_u+size_i+size_m;
                                        x= random(total);
                                        if (x>size_u+size_i+size_m) {
                                                random_choose= type_fighter_w[random(size_w)];
                                                char_type="fighter_w";
                                                }
                                                else if (x>size_u+size_m)       {
                                                        random_choose=type_ironman[random(size_i)];
                                                        char_type="ironman";
                                                   }
                                                else if (x>size_u) {
                                                        random_choose=type_magician[random(size_m)];
                                                        char_type="magician";
                                                        }
                                                else {
                                                        random_choose= type_fighter_u[random(size_u)];
                                                        char_type="fighter_u";
                                                        }                                       
                        default:        break;
                        }                       
         
        if ((!random(10)&& my_char=="all") || char_type=="healer") {
                set("npc_type","healer");
                set("class","bonze");
                set_name("妙手回春",({name}));
                set("skill_type_w","staff/cloudstaff");
                set("skill_type_u","dabei-strike");
                set("defense_type",1);
                set_skill("cloudstaff",special);
                set_skill("essencemagic",200);
                set_skill("notracesnow",special+20);
                set_skill("dabei-strike",special+20);
                set_skill("lotusforce",200);
                map_skill("magic","essencemagic");
                map_skill("force","lotusforce");
                map_skill("unarmed","dabei-strike");
                map_skill("staff","cloudstaff");
                map_skill("parry","cloudstaff");
                map_skill("dodge","notracesnow");
                set_temp("apply/dodge",special);
                set("perform_attack","staff.longxianyuye");
                set("perform_attack_u","unarmed.qianshouqianbian");     
                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                return;
        }
        
        if (my_char != "all")  random_choose= my_char; 
        setup_npc_skill(name,char_type,random_choose,special,basic,auto_weapon,weapon_dir);

*/
// this function sets up NPC skills.
/*
setup_npc_skill(name,char_type,random_choose,special,basic,auto_weapon,weapon_dir){
        
        // below are fighter_w types.   
        if (char_type=="fighter_w") {           
                set("npc_type","fighter_w");
                switch (random_choose) {        
                case "feixian":  
                                set_name("飞仙",({name}));
                                set("skill_type_w","sword/feixian-sword");
                                set("skill_type_u","dabei-strike");
                                set("class","baiyun");
                                set_skill("feixian-sword",special+50);
                                set_skill("feixian-steps",special);
                                set_skill("dabei-strike",special);
                                set_skill("painting",special);
                                set_skill("chess",special);
                                map_skill("force","painting");
                                map_skill("unarmed","dabei-strike");
                                map_skill("sword","feixian-sword");
                                map_skill("parry","feixian-sword");
                                map_skill("dodge","feixian-steps");
                                set("perform_busy_u","shaolin/unarmed/dabei-strike/qianshouqianbian");
                                set("perform_weapon_attack","baiyun/sword/feixian-sword/tianwaifeixian");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "shenji":   
                                set_name("神算子",({name}));
                                set("skill_type_w","blade/shenji-blade");
                                set("skill_type_u","luoriquan");
                                set("skill_type_d","shenji-steps");
                                set_skill("shenji-blade",special);
                                set_skill("shenji-steps",special);
                                set_skill("luoriquan",special+50);
                                set_skill("wind-blade",special);
                                map_skill("unarmed","luoriquan");
                           map_skill("blade","shenji-blade");
                                map_skill("parry","shenji-blade");
                                map_skill("dodge","shenji-steps");
                                set("perform_weapon_attack","bat/blade/shenji-blade/jichulianhuan");
                                set("perform_weapon_attack2","npc/blade/wind-blade/leitingpili");
                                set("perform_unarmed_attack","bat/unarmed/luoriquan/luori");
                                set("perform_busy_d","bat/dodge/shenji-steps/shenjimiaosuan");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break; 
                case "bat-blade": 
                                set("class","bat");
                                set_name("飞天蝙蝠",({name}));
                                set("skill_type_w","blade/bat-blade");
                                set("skill_type_u","luoriquan");
                                set_skill("bat-blade",special-20);
                                set_skill("meng-steps",special);
                                set_skill("luoriquan",special+50);
                                set_skill("wind-blade",special);
                                map_skill("unarmed","luoriquan");
                                map_skill("blade","bat-blade");
                                map_skill("parry","bat-blade");
                                map_skill("dodge","meng-steps");
                                set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");
                                set("perform_weapon_attack2","npc/blade/wind-blade/leitingpili");
                                set("perform_unarmed_attack","bat/unarmed/luoriquan/luori");
                                set("perform_busy_d","bat/dodge/meng-steps/huanyinqianchong");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "lefthand": 
                                set("class","assassin");
                                set_name("毒剑",({name}));
                                set("skill_type_w","sword/sharen-sword");
                                set("skill_type_u","flame-strike");
                                set_skill("jinhong-steps",special+50);
                                set_skill("flame-strike",special+20);
                                set_skill("lefthand-sword",special+50);
                                set_skill("sharen-sword",special+30);
                                map_skill("unarmed","flame-strike");
                                map_skill("sword","sharen-sword");
                           map_skill("parry","lefthand-sword");
                                map_skill("dodge","jinhong-steps");
                                set("perform_weapon_attack","assassin/sword/sharen-sword/sharenruma");
                                set("perform_busy_d","assassin/dodge/jinhong-steps/canglongzhaxian");   
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "diesword": 
                                set_name("花蝴蝶",({name}));
                                set("class","legend");
                                set("gender","女性");
                                set("skill_type_w","sword/diesword");
                                set("skill_type_u","meihua-shou");
                                set_skill("diesword",special-20);
                                set_skill("fall-steps",special+50);
                                set_skill("qidaoforce",special);
                                set_skill("meihua-shou",special+50);
                                map_skill("unarmed","meihua-shou");
                                map_skill("force","qidaoforce");
                                map_skill("sword","diesword");
                                map_skill("parry","diesword");
                                map_skill("dodge","fall-steps");
                                set_temp("qidaoforce_juqi",special*2+random(special));
                                set("perform_weapon_attack","legend/sword/diesword/caidiekuangwu");
                                set("perform_busy_d","legend/dodge/fall-steps/luoyeqiufeng");
                                set("perform_busy_u","legend/unarmed/meihua-shou/meihai");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "shortsong": 
                                set_name("落叶",({name}));
                                set("class","legend");
                                set("skill_type_w","blade/shortsong-blade");
                                set("skill_type_u","meihua-shou");
                                set_skill("shortsong-blade",special-10);
                                set_skill("fall-steps",special+50);
                                set_skill("qidaoforce",special+50);
                                set_skill("meihua-shou",special+50);
                                map_skill("force","qidaoforce");
//                              map_skill("unarmed","meihua-shou");
                                map_skill("blade","shortsong-blade");
                           map_skill("parry","shortsong-blade");
                                map_skill("dodge","fall-steps");
                                set_temp("qidaoforce_juqi",special*2+random(special));
                                set("perform_weapon_attack","legend/blade/shortsong-blade/duangechangmeng");
                                set("perform_busy","legend/dodge/fall-steps/luoyeqiufeng");
                                set("perform_busy_u","legend/unarmed/meihua-shou/meihai");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "dagou-stick": 
                                set_name("天下无狗",({name}));
                                set("class","beggar");
                                set("skill_type_w","staff/dagou-stick");
                                set("skill_type_u","dragonstrike");
                                set_skill("dragonstrike",special+20);
                                set_skill("doggiesteps",special+80);
                                set_skill("dagou-stick",special);
                                map_skill("staff","dagou-stick");
                                map_skill("parry","dagou-stick");
                                map_skill("unarmed","dragonstrike");
                                map_skill("dodge","doggiesteps");
                                set("perform_attack","staff.tianxiawugou");
                                set("perform_attack_2","unarmed.xianglongwuhui");
                                set("perform_busy_u","unarmed.xianglongwuhui");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                                break;
                case "yue-spear": 
                                set_name("丹青",({name}));
                                set("class","official");
                                set("marks/官府/岳飞",1);
                                set("family/master_id","master yue");
                                set("skill_type_w","spear/yue-spear");
                                set("skill_type_u","changquan");
                                set_skill("changquan",300);
                                set_skill("puti-steps",special+80);
                                set_skill("yue-spear",special);
                                set_skill("manjianghong",special);
                                map_skill("force","manjianghong");
                                map_skill("spear","yue-spear");
                                map_skill("parry","yue-spear");
                           map_skill("unarmed","changquan");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","spear.zonghengtianxia");
                                set("perform_attack_2","unarmed.yuhuan");
                                set_temp("apply/dodge",160);
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();
                                break;
                case "taiji-sword": 
                                set_name("棉里藏针",({name}));
                                set("class","wudang");
                                set("skill_type_w","sword/taiji-sword");
                                set("skill_type_u","taiji");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taiji-sword",special+50);
                                set_skill("taijiforce",200);
                                map_skill("force","taijiforce");
                                map_skill("sword","taiji-sword");
                                map_skill("unarmed","taiji");
                                map_skill("dodge","five-steps");
                                set("perform_attack","sword.chanzijue");
                                set("perform_attack_2","nianzijue");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "sharen-sword": 
                                set("class","assassin");
                                set_name("杀人如麻",({name}));
                                set("skill_type_w","sword/lefthand-sword");
                                set("skill_type_u","flame-strike");
                                set_skill("lefthand-sword",special+20);
                                set_skill("sharen-sword",special+20);
                                set_skill("jinhong-steps",special+50);
                                set_skill("flame-strike",special+20);
                                map_skill("unarmed","flame-strike");
                                map_skill("sword","sharen-sword");
                                map_skill("parry","lefthand-sword");
                                map_skill("dodge","jinhong-steps");
                                set("perform_attack","sword.sharenruma");
                                set("perform_busy","dodge.canglongzhaxian");    
                           if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "nine-moon-sword": 
                                set("class","shenshui");
                                set("gender","女性");
                                set_name("冰冻",({name}));
                                set("skill_type_w","sword/nine-moon-sword");
                                set("skill_type_u","nine-moon-claw");                           
                                set_temp("nine-moon-force_poison",special*2);
                                set_skill("nine-moon-claw",special);
                                set_skill("nine-moon-sword",special);
                                set_skill("nine-moon-steps",special);
                                set_skill("nine-moon-force",200);
                                set_skill("qingpingsword",special);
                                map_skill("force","nine-moon-force");
                                map_skill("sword","nine-moon-sword");
                                map_skill("unarmed","nine-moon-claw");
                                map_skill("dodge","nine-moon-steps");
                                map_skill("parry","nine-moon-sword");
                                set("perform_attack","sword.shuanglengcanxia");
                                set("perform_busy","dodge.lianhuanbu");
                                set("perform_busy_w","qingpingsword/sword.fengzijue");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "longfenghuan": 
                                set("class","assassin");
                                set_name("双飞燕",({name}));
                                set("skill_type_w","hammer/longfenghuan");
                                set("skill_type_u","flame-strike");
                                set_skill("longfenghuan",special);
                                set_skill("jinhong-steps",special+50);
                                set_skill("flame-strike",special+20);
                                map_skill("unarmed","flame-strike");
                                map_skill("hammer","longfenghuan");
                                map_skill("parry","longfenghuan");
                                map_skill("dodge","jinhong-steps");
                                set("perform_attack","hammer.longfengshuangfei");
                                set("perform_busy","dodge.canglongzhaxian");    
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();
                           break;
                case "cloudstaff": 
                                set("class","bonze");
                                set_name("浮云写意",({name}));
                                set("skill_type_w","staff/cloud-staff");
                                set("skill_type_u","dabei-strike");
                                set_skill("cloudstaff",special);
                                set_skill("notracesnow",special+20);
                                set_skill("dabei-strike",special+20);
                                map_skill("unarmed","dabei-strike");
                                map_skill("staff","cloudstaff");
                                map_skill("parry","cloudstaff");
                                map_skill("dodge","notracesnow");
                                set_temp("apply/dodge",150);
                                set("perform_attack","staff.longxianyuye");
                                set("perform_busy_u","unarmed.qianshouqianbian");       
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                                break;
                case "doomsword": 
                                set("class","fighter");
                                set_name("湘西一剑",({name}));
                                set("skill_type_w","sword/doomsword");
                                set("skill_type_u","doomstrike");
                                set_skill("doomsword",special-50);
                                set_skill("doomstrike",special);
                                set_skill("doomsteps",special);
                                map_skill("unarmed","doomstrike");
                                map_skill("sword","doomsword");
                                map_skill("parry","doomsword");
                                map_skill("dodge","doomsteps");
                                set("perform_attack","sword.hunranyijian");
                                set("perform_attack_2","unarmed.hantian");      
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "xuezhan-spear":   
                                set_name("血枪",({name}));
                                set("class","fugui");
                                set("skill_type_w","spear/xuezhan-spear");
                                set("skill_type_u","eagle-claw");
                           set_skill("xuezhan-spear",special);
                                set_skill("hawk-steps",special);
                                set_skill("eagle-claw",special+30);
                                set_skill("skyforce",200);
                                set_skill("iron-cloth",special-50);
                                set_skill("henglian",special-50);
                                map_skill("iron-cloth","henglian");
                                map_skill("force","skyforce");
                                map_skill("unarmed","eagle-claw");
                                map_skill("spear","xuezhan-spear");
                                map_skill("parry","xuezhan-spear");
                                map_skill("dodge","hawk-steps");
                                set_temp("apply/iron-cloth",150);
                                set("perform_attack","spear.bafangfengyu");
                                set("perform_busy","dodge.yingjichangkong");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();
                                break;
                case "xuezhan-spear2":  
                                set_name("凝血枪",({name}));
                                set("class","fugui");
                                set("skill_type_w","spear/xuezhan-spear");
                                set("skill_type_u","eagle-claw");
                                set_skill("xuezhan-spear",special);
                                set_skill("hawk-steps",special);
                                set_skill("eagle-claw",special+30);
                                set_skill("skyforce",200);
                                set_skill("iron-cloth",special-50);
                                set_skill("henglian",special-50);
                                map_skill("iron-cloth","henglian");
                                map_skill("force","skyforce");
                                map_skill("unarmed","eagle-claw");
                                map_skill("spear","xuezhan-spear");
                                map_skill("parry","xuezhan-spear");
                                map_skill("dodge","hawk-steps");
                                set_temp("apply/iron-cloth",150);
                                set("perform_attack","spear.yutianbigao");
                                set("perform_busy","dodge.yingjichangkong");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();
                                break;
           case "liuquan-steps":   
                                set_name("流泉",({name}));
                                set("class","huangshan");
                                set("gender","女性");
                                set("skill_type_w","sword/siqi-sword");
                                set("skill_type_u","yunwu-strike");
                                set_skill("siqi-sword",special);
                                set_skill("liuquan-steps",special);
                                set_skill("yunwu-strike",special);
                                set_skill("xianjing",200);
                                map_skill("force","xianjing");
                                map_skill("unarmed","yunwu-strike");
                                map_skill("sword","siqi-sword");
                                map_skill("parry","siqi-sword");
                                map_skill("dodge","liuquan-steps");
                                set("perform_busy","dodge.liushuichanchan");
                                set("perform_busy_u","unarmed.miwu");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "siqi-sword":      
                                set_name("四奇",({name}));
                                set("class","huangshan");
                                set("gender","女性");
                                set("skill_type_w","sword/siqi-sword");
                                set("skill_type_u","yunwu-strike");
                                set_skill("siqi-sword",special);
                                set_skill("liuquan-steps",special);
                                set_skill("yunwu-strike",special);
                                set_skill("xianjing",200);
                                map_skill("force","xianjing");
                                map_skill("unarmed","yunwu-strike");
                                map_skill("sword","siqi-sword");
                                map_skill("parry","siqi-sword");
                                map_skill("dodge","liuquan-steps");
                                set("perform_busy_u","unarmed.miwu");
                                set("perform_attack","sword.siqi");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "qiusheng-blade":  
                           set_name("秋声",({name}));
                                set("class","huangshan");
                                set("gender","男性");
                                set("skill_type_w","blade/qiusheng-blade");
                                set("skill_type_u","yunwu-strike");
                                set_skill("qiusheng-blade",special);
                                set_skill("liuquan-steps",special);
                                set_skill("yunwu-strike",special);
                                set_skill("xianjing",200);
                                map_skill("force","xianjing");
                                map_skill("unarmed","yunwu-strike");
                                map_skill("sword","qiusheng-blade");
                                map_skill("parry","qiusheng-blade");
                                map_skill("dodge","liuquan-steps");
                                set("perform_busy_u","unarmed.miwu");
                                set("perform_attack","blade.jingsheng");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "qingfeng-sword":  
                                set_name("清风",({name}));
                                set("class","huashan");
                                set("gender","女性");
                                set("skill_type_w","sword/qingfeng-sword");
                                set("skill_type_u","zhaixin-claw");
                                set_skill("qingfeng-sword",special+20);
                                set_skill("cloud-dance",special);
                                set_skill("zhaixin-claw",special);
                                set_skill("hanmei-force",200);
                                set_skill("iron-cloth",special-50);
                                set_skill("spring-water",special-50);
                                map_skill("iron-cloth","spring-water");
                                map_skill("force","hanmei-force");
                                map_skill("unarmed","zhaixin-claw");
                                map_skill("sword","qingfeng-sword");
                                map_skill("parry","qingfeng-sword");
                                map_skill("dodge","cloud-dance");
                                set_temp("apply/iron-cloth",120);
                                set("perform_busy","dodge.yexuechuji");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                           break;
                case "tanzhi-shentong": 
                                set_name("千手观音",({name}));
                                set("class","huashan");
                                set("gender","女性");
                                set("skill_type_w","throwing/tanzhi-shentong");
                                set("skill_type_u","zhaixin-claw");
                                set_skill("tanzhi-shentong",special);
                                set_skill("anxiang-steps",special);
                                set_skill("zhaixin-claw",special);
                                set_skill("hanmei-force",200);
                                set_skill("iron-cloth",special-50);
                                set_skill("spring-water",special-50);
                                map_skill("iron-cloth","spring-water");
                                map_skill("force","hanmei-force");
                                map_skill("unarmed","zhaixin-claw");
                                map_skill("throwing","tanzhi-shentong");
                                map_skill("dodge","anxiang-steps");
                                set("perform_attack","throwing.mantianhuayu");
                                set("perform_busy","dodge.yexuechuji");
                                if (auto_weapon) carry_object(weapon_dir+"dart")->wield();
                                break;  
                case "xuanyuan-axe1": 
                                set("class","knight");
                                set_name("霹雳斧",({name}));
                                set("skill_type_w","axe/xuanyuan-axe");
                                set("skill_type_u","hanshan-strike");
                                set_skill("hanshan-strike",special+50);
                                set_skill("windy-steps",special);
                                set_skill("xuanyuan-axe",special);
                                map_skill("parry","xuanyuan-axe");
                                map_skill("axe","xuanyuan-axe");
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack","axe.guifushengong");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");
                                if (auto_weapon) carry_object(weapon_dir+"axe")->wield();       
                                break;
           case "xuanyuan-axe2": 
                                set("class","knight");
                                set_name("雷霆斧",({name}));
                                set("skill_type_w","axe/xuanyuan-axe");
                                set("skill_type_u","hanshan-strike");
                                set_skill("hanshan-strike",special+50);
                                set_skill("windy-steps",special);
                                set_skill("xuanyuan-axe",special);
                                map_skill("parry","axe.xuanyuan-axe");
                                map_skill("axe","xuanyuan-axe");
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack","axe.jiuqipoxiao");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");
                                if (auto_weapon) carry_object(weapon_dir+"axe")->wield();       
                                break;
                case "softsword": 
                                set("class","swordsman");
                                set_name("剑奴",({name}));
                                set("skill_type_w","sword/softsword");
                                set("skill_type_u","yue-strike");
                                set_skill("yue-strike",special);
                                set_skill("shadowsteps",special+50);
                                set_skill("softsword",special);
                                map_skill("sword","softsword");
                                map_skill("parry","softsword");
                                map_skill("unarmed","yue-strike");
                                map_skill("dodge","shadowsteps");
                                set("perform_attack","sword.muyufeihong");
                                set("perform_attack_2","dodge.lianhuanjiao");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();     
                                break;                          
                case "ittouryu": 
                                set("npc_type","fighter_w");
                                set("class","ninja");
                                set_name("恶鬼",({name}));
                                set("skill_type_w","blade/ittouryu");
                                set("skill_type_u","yue-strike");

                                set_skill("yue-strike",special);
                                set_skill("ghosty-steps",special);
                                set_skill("ittouryu",special);
                                map_skill("blade","ittouryu");
                                map_skill("unarmed","yue-strike");
                                map_skill("dodge","ghosty-steps");
                                set_temp("apply/dodge",special/2);
                                set("perform_attack","blade.hyakki");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();     
                                break;
                case "ass-hammer": 
                                set("npc_type","fighter_w");
                                set("class","wolf");
                                set_name("搏浪",({name}));
                                set("skill_type_w","hammer/assasin-hammer");
                                set("skill_type_u","wolf-strike");
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special);
                                set_skill("assasin-hammer",special);
                                map_skill("hammer","assasin-hammer");
                                map_skill("parry","assasin-hammer");
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack_2","unarmed.duanhou");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;                          
                case "pangu-hammer": 
                                set("npc_type","fighter_w");
                                set("class","yinshi");
                                set_name("轰天锤",({name}));
                                set("skill_type_w","hammer/pangu-hammer");
                                set("skill_type_u","pofeng-strike");
                                set_skill("pofeng-strike",special+50);
                                set_skill("zuixian-steps",special);
                                set_skill("pangu-hammer",special);
                                map_skill("hammer","pangu-hammer");
                                map_skill("parry","pangu-hammer");
                                map_skill("unarmed","pofeng-strike");
                                map_skill("dodge","zuixian-steps");

                                set_temp("apply/dodge",special);
                                set("perform_attack","hammer.kaitianpidi");
                                set("perform_attack_2","unarmed.luanpofeng");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;  
                default:        
                case "thunderwhip": 
                                set("npc_type","fighter_w");
                                set("class","yinshi");
                                set_name("飞龙",({name}));
                                set("skill_type_w","hammer/pangu-hammer");
                                set("skill_type_u","pofeng-strike");
                                set_skill("pofeng-strike",special+50);
                                set_skill("zuixian-steps",special);
                                set_skill("pangu-hammer",200);
                                set_skill("thunderwhip",special);
                                map_skill("hammer","pangu-hammer");
                                map_skill("whip","thunderwhip");
                                map_skill("parry","thunderwhip");
                                map_skill("unarmed","pofeng-strike");
                                map_skill("dodge","zuixian-steps");
                                set_temp("apply/dodge",special);
                                set("marks/hammerwhip",1); 
                                set("perform_attack","whip.tianleiyiji");
                                set("perform_attack_2","unarmed.luanpofeng");
                                if (auto_weapon) carry_object(weapon_dir+"whip")->wield();      
                                break;  
                case "yunlong": 
                                set("npc_type","fighter_w");
                                set("class","yinshi");
                                set_name("云龙",({name}));
                                set("skill_type_w","hammer/pangu-hammer");
                                set("skill_type_u","pofeng-strike");
                                set_skill("pofeng-strike",special+50);
                                set_skill("zuixian-steps",special);
                                set_skill("pangu-hammer",200);
                                set_skill("thunderwhip",special);
                                set_skill("celecurse",special);
                                set_skill("cursism",special);

                                map_skill("cursism","celecurse");
                                map_skill("hammer","pangu-hammer");
                                map_skill("whip","thunderwhip");
                                map_skill("parry","thunderwhip");
                                map_skill("unarmed","pofeng-strike");
                                map_skill("dodge","zuixian-steps");
                                set_temp("apply/dodge",special);
                                set("marks/hammerwhip",1); 
                                set("perform_attack","whip.yunlongjiuxian");
                                set("perform_attack_2","unarmed.luanpofeng");
                                if (auto_weapon) carry_object(weapon_dir+"whip")->wield();      
                                break;  
                case "xinyue-dagger": 
                                set("npc_type","fighter_w");
                                set("class","wolfmount");
                                set_name("乾坤",({name}));
                                set("skill_type_w","dagger/xinyue-dagger");
                                set("skill_type_u","wolf-strike");
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special+20);
                                set_skill("xinyue-dagger",special-40);
                                set_skill("assasin-hammer",200);
                                map_skill("dagger","xinyue-dagger");
                                map_skill("parry","xinyue-dagger");
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack","dagger.douzhuanxingyi");
                                set("perform_attack_2","unarmed.duanhou");
                                if (auto_weapon) carry_object(weapon_dir+"dagger")->wield();    
                                break;  
                } 
        } else  {
// below are fighter_u types:                                   
                switch (random_choose) {
                case "qingpingsword": 
                                set("class","shenshui");
                                set("gender","女性");
                                set_name("新娘",({name}));
                                set("skill_type_u","nine-moon-claw");                           

                                set_temp("nine-moon-force_poison",special*2);
                                set_skill("nine-moon-claw",special);
                                set_skill("nine-moon-spirit",special);
                                set_skill("nine-moon-sword",special);
                                set_skill("nine-moon-steps",special);
                                set_skill("nine-moon-force",200);
                                set_skill("qingpingsword",special);
                                map_skill("force","nine-moon-force");
                                map_skill("sword","qingping-sword");
                                map_skill("unarmed","nine-moon-claw");
                                map_skill("dodge","nine-moon-steps");
                                map_skill("parry","qingping-sword");
                                set("perform_attack_2","unarmed.polu");
                                set("perform_busy_w","qingpingsword/sword.fengzijue");
                                break;
                case "dragonstrike": 
                                set("npc_type","fighter_u");
                                set_name("降龙",({name}));
                                set("class","beggar");
                                set("skill_type_u","dragonstrike");
                                set_skill("dragonstrike",special+20);
                                set_skill("doggiesteps",special+80);
                                set_skill("dagou-stick",special);
                                map_skill("staff","dagou-stick");
                                map_skill("parry","dagou-stick");
                                map_skill("unarmed","dragonstrike");
                                map_skill("dodge","doggiesteps");
                                set("perform_attack_2","unarmed.xianglongwuhui");
                                set("perform_busy_u","unarmed.xianglongwuhui");
                                break;
                case "taiji": 
                                set_name("如意",({name}));
                                set("class","wudang");
                                set("skill_type_u","taiji");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taijiforce",200);
                                map_skill("force","taijiforce");
                                map_skill("unarmed","taiji");

                                map_skill("dodge","five-steps");
                                set("perform_attack_2","unarmed.nianzijue");
                                break;
                case "bazhentu": 
                                set_name("失魂落魄",({name}));
                                set("class","wudang");
                                set("skill_type_u","taiji");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taijiforce",200);
                                map_skill("force","taijiforce");
                                map_skill("unarmed","taiji");
                                map_skill("dodge","five-steps");
                                set("perform_attack_2","dodge.bazhentu");
                                break;
                case "doomstrike": 
                                set("npc_type","fighter_u");
                                set("class","fighter");
                                set("skill_type_u","doomstrike");
                                set_name("单掌断魂",({name}));
                                set_skill("doomstrike",special);
                                set_skill("doomsteps",special);
                                map_skill("unarmed","doomstrike");
                                map_skill("dodge","doomsteps");
                                set("perform_attack_2","unarmed.hantian");      
                                break;
                case "hanshan-strike": 
                                set("npc_type","fighter_u");
                                set("class","knight");
                                set("skill_type_u","hanshan-strike");
                                set_name("姑苏",({name}));
                                set_skill("hanshan-strike",special+50);
                                set_skill("windy-steps",special);
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");    
                                break;
                case "yiyangzhi": 

                                set("npc_type","fighter_u");
                                set("class","shaolin");
                                set("skill_type_u","yiyangzhi");
                                set_name("一阳",({name}));
                                set_skill("yiyangzhi",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                set_skill("fumostaff",special);
                                map_skill("staff","fumostaff");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","yiyangzhi");
                                map_skill("dodge","puti-steps");
                                set_temp("apply/dodge",special/2);
                                set("perform_busy_w","fumostaff/staff.hequhecong");
                                set("perform_attack_2","unarmed.qiankun");
                                break;
                case "yizhichan": 
                                set("npc_type","fighter_u");
                                set("class","shaolin");
                                set("skill_type_u","yizhichan");
                                set_name("拈花",({name}));
                                set_skill("yizhichan",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                set_skill("fumostaff",special);
                                map_skill("staff","fumostaff");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","yizhichan");
                                map_skill("dodge","puti-steps");
                                set_temp("apply/dodge",special/2);
                                set("perform_busy_w","fumostaff/staff.hequhecong");
                                set("perform_attack_2","unarmed.nianhua");
                                break;
                case "enmeiryu": 
                                set("npc_type","fighter_u");
                                set("class","ninja");
                                set("skill_type_u","enmeiryu");

                                set_name("紫电",({name}));
                                set_skill("enmeiryu",special);
                                set_skill("ghosty-steps",special);
                                map_skill("unarmed","enmeiryu");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack_2","unarmed.shiden");
                                break;
                case "yaozhan": 
                                set("npc_type","fighter_u");
                                set("class","ninja");
                                set("skill_type_u","enmeiryu");
                                set_name("朱雀",({name}));
                                set_skill("enmeiryu",special);
                                set_skill("ghosty-steps",special);
                                map_skill("unarmed","enmeiryu");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack_2","unarmed.shimon");
                                break;
                case "mukuha": 
                                set("npc_type","fighter_u");
                                set("class","ninja");
                                set("skill_type_u","enmeiryu");
//                              set("mark/true_mukuha",1);
                                set_name("玄武",({name}));
                                set_skill("enmeiryu",special);
                                set_skill("ghosty-steps",special);
                                map_skill("unarmed","enmeiryu");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack_2","unarmed.mukuha");
                                break;
                case "tenderzhi": 
                                set("npc_type","fighter_u");
                                set("class","taoist");
                                set("skill_type_u","tenderzhi");
                                set_name("柔虹",({name}));
                                set("gender","女性");
                                set_skill("tenderzhi",special);
                                set_skill("iron-cloth",basic);
                                set_skill("puti-steps",special);
                           map_skill("unarmed","tenderzhi");
                                map_skill("dodge","puti-steps");
                                set_temp("apply/dodge",special);
                                set("perform_attack_2","unarmed.qiankun");
                                break;
                case "wolf-strike": 
                                set("npc_type","fighter_u");
                                set("class","legend");
                                set("skill_type_u","wolf-strike");
                                set_name("穿心爪",({name}));
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special);
                                set_skill("fall-steps",special);
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","fall-steps");
                                set("perform_busy","dodge.luoyeqiufeng");
                                set("perform_attack_2","unarmed.duanhou");
                                break;
                case "wolf-claw": 
                                set("npc_type","fighter_u");
                                set("class","wolfmount");
                                set("skill_type_u","wolf-claw");
                                set_name("勾心爪",({name}));
                                set_skill("wolf-claw",special);
                                set_skill("xueyeqianzong",special);
                                map_skill("unarmed","wolf-claw");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack_2","unarmed.ningxie");
                                break;
                case "nine-moon-claw": 
                                set("npc_type","fighter_u");
                                set("class","shenshui");
                                set("skill_type_u","nine-moon-claw");
                                set("gender","女性");
                                set_name("勾心爪",({name}));
                                set_temp("nine-moon-force_poison",special*2);
                                set_skill("nine-moon-claw",special);
                                set_skill("nine-moon-steps",special);
                                set_skill("nine-moon-force",200);
                           map_skill("force","nine-moon-force");
                                map_skill("unarmed","nine-moon-claw");
                                map_skill("dodge","nine-moon-steps");
                                set("perform_busy","dodge.lianhuanbu");
                                break;
                case "luoriquan": 
                                set("npc_type","fighter_u");
                                set("class","bat");
                                set("skill_type_u","luoriquan");
                                set_name("落日",({name}));
                                set_skill("meng-steps",special);
                                set_skill("luoriquan",special+50);
                                map_skill("unarmed","luoriquan");
                                map_skill("dodge","meng-steps");
                                set("perform_attack_2","unarmed.luori");
                                set("perform_busy","dodge.huanyinqianchong");
                                break;
                case "shadowsteps": 
                                set("class","swordsman");
                                set_name("迷宗腿",({name}));
                                set("skill_type_u","yue-strike");
                                set_skill("yue-strike",special);
                                set_skill("shadowsteps",special+50);
                                set_skill("softsword",special);
                                set_skill("cloudforce",200);
                                map_skill("force","cloudforce");
                                map_skill("sword","softsword");
                                map_skill("parry","softsword");
                                map_skill("unarmed","yue-strike");
                                map_skill("dodge","shadowsteps");
                                set("perform_attack_2","dodge.lianhuanjiao");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;  
// below are ironman types:
                case "jin-gang": 
                                set("npc_type","ironman");
                                set("class","lama");
                                set("skill_type_w","staff/cloudstaff");
                                set("skill_type_u","bloodystrike");

                                set_name("铁汉",({name}));
                                set_skill("bloodystrike",special);
                                set_skill("cloudstaff",special);
                                set_skill("iron-cloth",basic);
                                set_skill("jin-gang",special);
                                map_skill("parry","cloudstaff");
                                map_skill("staff","cloudstaff");
                                map_skill("iron-cloth","jin-gang");
                                map_skill("unarmed","bloodystrike");
                                map_skill("dodge","windy-steps");
                                set_temp("apply/iron-cloth",special/2);
                                set("perform_attack","staff.longxianyuye");
                                set("perform_busy_u","unarmed.fefawubian");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();     
                                break;
                case "sl-hammer": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set("skill_type_w","hammer/liuxing-hammer");
                                set("skill_type_u","dabei-strike");
                                set_name("流星",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("liuxing-hammer",special+50);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                set_skill("fumostaff",special+80);
                                map_skill("staff","fumostaff");
                                map_skill("parry","liuxing-hammer");
                                map_skill("hammer","liuxing-hammer");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-strike");
                                map_skill("dodge","puti-steps");
                                set_temp("apply/dodge",special/2);
                                set("perform_busy_w","fumostaff/staff.hequhecong");
                                set("perform_busy_u","unarmed.qianshouqianbian");
                                set("perform_weapon_attack","hammer.fanbei");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;

                case "sl-axe": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set("skill_type_w","axe/wuche-axe");
                                set("skill_type_u","dabei-strike");
                                set_name("泼风",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("wuche-axe",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                set_skill("fumostaff",special);
                                map_skill("staff","fumostaff");
                                map_skill("parry","wuche-axe");
                                map_skill("axe","wuche-axe");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-strike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","axe.sanbanfu");
                                set("perform_busy_u","unarmed.qianshouqianbian");
                                set("perform_busy_w","fumostaff/staff.hequhecong");
                                if (auto_weapon) carry_object(weapon_dir+"axe")->wield();       
                                break;
                case "sl-spear": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set("skill_type_w","spear/duanhun-spear");
                                set("skill_type_u","dabei-strike");
                                set_name("索魂客",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("duanhun-spear",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                set_skill("fumostaff",special+80);
                                map_skill("staff","fumostaff");
                                map_skill("parry","duanhun-spear");
                                map_skill("spear","duanhun-spear");
                                map_skill("iron-cloth","yijinjing");

                                map_skill("unarmed","dabei-strike");
                                map_skill("dodge","puti-steps");
                                set_temp("apply/dodge",special/2);
                                set("perform_weapon_attack","shaolin/spear/duanhun-spear/suomengchanhun");
                                set("perform_busy_w","shaolin/staff/fumostaff/hequhecong");
                                set("perform_busy_u","shaolin/unarmed/dabei-strike/qianshouqianbian");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();     
                                break;
                default:        
                case "sl-yijinjing": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set("skill_type_u","yijinjing");
                                set_name("金刚",({name}));
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special);
                                set_skill("puti-steps",special);
                                set_skill("fumostaff",special+80);
                                map_skill("staff","fumostaff");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","yijinjing");
                                map_skill("dodge","puti-steps");
                                set_temp("apply/dodge",special/2);
                                set("force_factor",100);
                                set("no_busy",10);
                                break;
//              below are magician types
                case "sq-female":
                                set("npc_type","magician");
                                set("class","taoist");
                                set("skill_type_u","tenderzhi");
                                set("my_type","sq-female");
                                set_name("辣手仙姑",({name}));
                                set("gender","女性");
                                set_skill("necromancy",special);
                                set_skill("notracesnow",special);
                                set_skill("tenderzhi",special);
                                set_skill("gouyee",200);
                                map_skill("spells","necromancy");

                                map_skill("force","gouyee");
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","notracesnow");
                                set_temp("apply/dodge",special);
                                set("cast_attack","invocation");
                                break;
                case "sq-female2":
                                set("npc_type","magician");
                                set("class","taoist");
                                set("my_type","sq-female");
                                set("skill_type_u","tenderzhi");
                                set_name("辣手仙姑",({name}));
                                set("gender","女性");
                                set_skill("necromancy",special);
                                set_skill("notracesnow",special);
                                set_skill("tenderzhi",special);
                                set_skill("gouyee",200);
                                set("open_sesame",1);
                                set("open_sesame/taoist",1);
                                set("sen",special*20);
                                set("max_sen",special*20);
                                set("eff_sen",special*20);
                                set("mana",special*10);
                                set("max_mana",special*10);
                                map_skill("spells","necromancy");
                                map_skill("force","gouyee");
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","notracesnow");
                                set_temp("apply/dodge",special);
                                set("cast_attack","superbolt");
                                break;
                case "sq-male":
                                set("npc_type","magician");
                                set("class","taoist");
                                set("skill_type_w","sword/snowshade-sword");
                                set("skill_type_u","tenderzhi");
                                set("my_type","sq-male");
                                set_name("催命道长",({name}));
                                set_skill("alchemy",special);
                           set_skill("notracesnow",special+20);
                                set_skill("tenderzhi",special+20);
                                set_skill("gouyee",200);
                                set_skill("snowshade-sword",special+50);
                                set_skill("scratching",special);
                                set_skill("scratmancy",special);
                                map_skill("sword","snowshade-sword");
                                map_skill("scratching","scratmancy");
                                map_skill("force","gouyee");
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","notracesnow");
                                map_skill("parry","snowshade-sword");
                                set_temp("apply/dodge",special);
                                set_temp("shield_force/type","mana");
                                set_temp("shield_force/ratio",450);
                                set_temp("shield_force/msg",
                                MAG"$N招式甫及$n身前三尺之外，便如牛入海,消失在紫气中。\n"NOR);
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;  
                case "sq-male2":
                                set("npc_type","magician");
                                set("class","taoist");
                                set("my_type","sq-male2");
                                set("skill_type_w","sword/snowshade-sword");
                                set("skill_type_u","tenderzhi");
                                set_name("天师道长",({name}));
                                set_skill("alchemy",special);
                                set_skill("notracesnow",special+20);
                                set_skill("tenderzhi",special+20);
                                set_skill("gouyee",200);
                                set_skill("snowshade-sword",special+50);
                                set_skill("scratching",special);
                                set_skill("scratmancy",special);
                                map_skill("sword","snowshade-sword");
                                map_skill("scratching","scratmancy");
                                map_skill("force","gouyee");
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","notracesnow");
                                map_skill("parry","snowshade-sword");

                                set_temp("apply/dodge",special);
                                set_temp("shield_force/type","mana");
                                set_temp("shield_force/ratio",450);
                                set_temp("shield_force/msg",
                                MAG"$N招式甫及$n身前三尺之外，便如牛入海,消失在紫气中。\n"NOR);
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;                  
                case "dz-an":
                                set("npc_type","magician");
                                set("class","lama");
                                set("my_type","dz-an");
                                set("skill_type_w","staff/cloudstaff");
                                set("skill_type_u","bloodystrike");
                                set_name("哼哼上人",({name}));
                                set_skill("kwan-yin-spells",special);
                                set_skill("jin-gang",special);
                                set_skill("iron-cloth",special);
                                set_skill("cloudstaff",special);
                                set_skill("bloodystrike",special);
                                set_skill("gouyee",200);
                                map_skill("spells","kwan-yin-spells");
                                map_skill("force","gouyee");
                                map_skill("iron-cloth","jin-gang");
                                map_skill("unarmed","bloodystrike");
                                map_skill("staff","cloudstaff");
                                map_skill("parry","cloudstaff");
                                set_temp("apply/iron-cloth",special);
                                set("cast_attack","an");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                                break;
                }
}
}
*/
auto_smart_fight()
{
        int i,n,j,k,count,num;
        string dodge_pfm;
        object *enemy, me, weapon,*inv;

        string unarmed_skill,weapon_skill,weapon_type;
        
        int pfm_dodge_busy,pfm_weapon_attack,pfm_unarmed_attack,pfm_unarmed_busy,pfm_weapon_busy;
        string w_attack_class,w_attack_type,w_attack_skill,w_attack_name;
        string u_attack_class,u_attack_type,u_attack_skill,u_attack_name;
        string d_busy_class,d_busy_type,d_busy_skill,d_busy_name;
        string u_busy_class,u_busy_type,u_busy_skill,u_busy_name;
        string w_busy_class,w_busy_type,w_busy_skill,w_busy_name;
        
        me= this_object();
        
        message_vision("start round.\n",me);
        
//      message_vision(me->query("id")+" is busied"+(string)(me->query_busy())+" turns.\n",me);                                                                  
        
//      starting to protect friends
        baohu();
                
        num = me->query("defense_type");
        
        if (me->query("npc_type")=="healer") {
                help_friend();
        }       
                
        if (me->query("npc_type")=="magician") {
                switch (me->query("my_type")) {
                        case "sq-male": alchemy_fight();
                                        break;
                        case "sq-male2": sheet_fight();
                                        break;
                        case "sq-female":
                        case "sq-female2":
                        case "dz-an":   cast_attack();
                                        break;
                        default:                
                        }       
        }       
        
//      auto setting up attack/busy parameters: 
   if (me->query("perform_weapon_attack"))
        if (sscanf(me->query("perform_weapon_attack"),"%s/%s/%s/%s",w_attack_class,
                        w_attack_type,w_attack_skill,w_attack_name)==4)
                { 
                pfm_weapon_attack=1;
                message_vision(w_attack_class+" "+w_attack_type+" "+w_attack_skill+" "+w_attack_name+".\n",me); 
        } 
        if (me->query("perform_unarmed_attack"))
        if (sscanf(me->query("perform_unarmed_attack"),"%s/%s/%s/%s",u_attack_class,
                        u_attack_type,u_attack_skill,u_attack_name)==4)
                { 
                pfm_unarmed_attack=1;
                message_vision(u_attack_class+" "+u_attack_type+" "+u_attack_skill+" "+u_attack_name+".\n",me); 
        }
        
        if (me->query("perform_busy_d"))        
        if (sscanf(me->query("perform_busy_d"),"%s/%s/%s/%s",d_busy_class,
                        d_busy_type,d_busy_skill,d_busy_name)==4)
                { 
                pfm_dodge_busy=1;
                message_vision(d_busy_class+" "+d_busy_type+" "+d_busy_skill+" "+d_busy_name+".\n",me); 
        }       
        
        if (me->query("perform_busy_u"))        
        if (sscanf(me->query("perform_busy_u"),"%s/%s/%s/%s",u_busy_class,
                        u_busy_type,u_busy_skill,u_busy_name)==4)
                { 
                pfm_unarmed_busy=1;
                message_vision(u_busy_class+" "+u_busy_type+" "+u_busy_skill+" "+u_busy_name+".\n",me); 
        }       
        
        if (me->query("perform_busy_w"))        
        if (sscanf(me->query("perform_busy_w"),"%s/%s/%s/%s",w_busy_class,
                        w_busy_type,w_busy_skill,w_busy_name)==4)
                { 
                pfm_weapon_busy=1;
                message_vision(w_busy_class+" "+w_busy_type+" "+w_busy_skill+" "+w_busy_name+".\n",me); 
        }       
        
   
        
        n=1;
        if (pfm_unarmed_busy) n=8;
        if (pfm_dodge_busy || pfm_weapon_busy) n =3; 
//      resort enemy here, prepare to attack the weakest enemy. 
        
        message_vision(" check officer.\n",me);
        if (query("officer-killer")) find_officer();
        
        message_vision(" sort enemy.\n",me);
        enemy = resort_enemy(); 
        message_vision(" asking help.\n",me);                   
        ask_help(); 
        if (me->query("npc_type")=="healer")    return;
                
        if (me->query("zombie-killer")) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                        
                }
                if (count>=2)
                        command("perform zombie-wp1");
        } 
//      how to fight like a player ?    
//      (1) how to do busy?             
//      if one enemy, and if enemy exp>3x my exp, use unarmed busy if available.
//      otherwise use dodge busy... then weapon busy.... depends on skills.
//      if sizeof(enemy)>1, definately use no-self-busy-dodge busy if available. and 
//      start with lowest exp non-guard enemy till 2x exp. skip the rest highest exp 
//      ones,
//      pfm unarmed busy on high exp enemies if having friends with you
//      pfm attack on busied ones.
//      (2) how to perform attack?
//      perform on player first rather than guard.
//      perform on those weakest one first.
        
        i = sizeof(enemy);
   
//      if there is only one enemy:
        if (i==1) {
                if( enemy[0] && living(enemy[0]) ) {
                message_vision("before pfms.\n",me);
                enemy_type(enemy[0]);
//      message_vision(enemy[0]->query("id")+" is busied"+(string)(enemy[0]->query_busy())+" turns.\n",me);
                        if (!enemy[0]->is_busy()) {
                                message_vision("busy pfm.\n",me);
                                if (enemy[0]->query("combat_exp")<3*this_object()->query("combat_exp")
                                        && (pfm_dodge_busy || pfm_weapon_busy)) {
                                        if (pfm_dodge_busy)     {
                                                me->set("class",d_busy_class);
                                                SKILL_D(d_busy_skill)->perform_target(this_object(),d_busy_name,enemy[0]);
                                                }
                                                else if (pfm_weapon_busy) 
                                                        this_object()->do_weapon_busy(enemy[0]);                                
                                        }
                                        else if (enemy[0]->query("combat_exp")<6*this_object()->query("combat_exp")) {
                                                if (pfm_unarmed_busy)
                                                        this_object()->do_unarmed_busy(enemy[0]);                       
                                        }
                        }
                        if (enemy[0]->is_busy() || n==1 ) {
                                message_vision("attack pfms.\n",me);
                                if (!me->query_temp("weapon")) {
                                if (pfm_unarmed_attack) {
                                                me->set("class",u_attack_class);
                                                SKILL_D(u_attack_skill)->perform_target(me,u_attack_name,enemy[0]);
                                        }
                                } else if (pfm_weapon_attack) {
//                                              me->set("class",w_attack_class);
                                                do_weapon_attack(enemy[0]);
//                                              SKILL_D(w_attack_skill)->perform_target(me,w_attack_name,enemy[0]);
                                        }
                        }
                }
        }
        

//      if there are multiple enemies, things become complicated.
        if (sizeof(enemy)>1) {
//              message_vision("multiple enemy!!!.\n",me); 
//      first use dodge busy on all not-so-high enemies;        
        for (k=0;k<sizeof(enemy);k++) {
                if( enemy[k] && living(enemy[k]) ) {
                        if (!enemy[k]->is_busy()
                                && enemy[k]->query("combat_exp")<2*this_object()->query("combat_exp")) {
                                if (pfm_dodge_busy) {
                                        me->set("class",d_busy_class);
                                        SKILL_D(d_busy_skill)->perform_target(me,d_busy_name,enemy[k]);
                                        }
                        }                               
                }
        }
        
//      secondly, if have friends around, use unarmed busy as well;     
        if (!this_object()->is_busy()&& accompany(this_object())) {
//              message_vision("unarmed busy run.\n",me);
        for (k=0;k<sizeof(enemy);k++) {
                if(enemy[k] && living(enemy[k])) {
                        if (!enemy[k]->is_busy() && userp(enemy[k])
                                && enemy[k]->query("combat_exp")<6*this_object()->query("combat_exp")) {
                                if (pfm_unarmed_busy)
                                        this_object()->do_unarmed_busy(enemy[k]);                       
                        }                               
                }
        }       
        } 
//      now when the busy is done, attack time; 
        for (k=0;k<sizeof(enemy);k++) {
                if (pfm_weapon_busy) n=1;
                if (enemy[k]->is_busy() || n==1 ) {
                        message_vision("check attack pfms."+n+" \n",me);
                        if (!me->query_temp("weapon")) {
                        if (pfm_unarmed_attack) {
                                me->set("class",u_attack_class);
                                SKILL_D(u_attack_skill)->perform_target(me,u_attack_name,enemy[k]);
                                }

                        } else if (pfm_weapon_attack) {
                                me->set("class",w_attack_class);
                                if (w_attack_name=="sharenruma") perform_action(w_attack_type+"."+w_attack_name);
                                else SKILL_D(w_attack_skill)->perform_target(this_object(),w_attack_name,enemy[k]);
                                }
                }
        }
        
        }
//      end of multiple enmeies turn; 
        if (num) do_defense(num);       
        message_vision("round ends.\n",me);
        return;
} 
void    do_weapon_attack(object target) {
        object me;
        string attack_name;
        string w_attack_class,w_attack_type,w_attack_skill,w_attack_name;
        
        me=this_object();
        attack_name = do_choose_weapon_attack(target);
        if (attack_name=="none") {
                command("say I will idle one turn so i can busy again.");
                return;
                }
        if (sscanf(attack_name,"%s/%s/%s/%s",w_attack_class,
                        w_attack_type,w_attack_skill,w_attack_name)==4)
                { 
                message_vision(w_attack_class+" "+w_attack_type+" "+w_attack_skill+" "+w_attack_name+".\n",me); 
        }
        me->set("class",w_attack_class);
        me->map_skill(w_attack_type,w_attack_skill);
        if (w_attack_name=="sharenruma") perform_action(w_attack_type+"."+w_attack_name);
        else SKILL_D(w_attack_skill)->perform_target(me,w_attack_name,target);
        return;
} 
string  do_choose_weapon_attack(object target) { 
        object me;
        string type;

        me=this_object();
        switch (me->query("skill_type_w")) {
        case "blade/shenji-blade": 
                if (target->query("kee")<1000) type=me->query("perform_weapon_attack2");
                        else if (target->query("kee")<4000) type=me->query("perform_weapon_attack");
                        else { if (target->query_busy()==1) type ="none";
                                        else type=me->query("perform_weapon_attack2");
                                if (target->query_busy()>3) type=me->query("perform_weapon_attack");
                                }
                break;
        default: type =me->query("perform_weapon_attack");
        }
        return type;
} 
void    find_officer() {
        object me,*enemy,owner;
        int i;
                
        me=this_object();
        enemy=me->query_enemy();
//      command("say in officer now.");
        for (i=0;i<sizeof(enemy);i++) {
                if (!userp(enemy[i])) { 
                        if(owner=enemy[i]->query("possessed")) {
                                if (!is_fighting(owner)) {
                                        command("say 竟敢在我面前玩花招！");
                                        kill_ob(owner);
                                        owner->kill_ob(me);
                                }
                        }
                }
        }
}  
//      this function set NPC with same group starting to protect each other.
void    baohu() {
        object me, *pros, *inv, ob;
        string type;
        int i,j, gotit;
        

        pros= ({});
        me= this_object();
        pros = me->query_temp("protectors");
//      message_vision(" in baohu.\n",me);      
        type = me->query("dungeon_npc");
        if (!type) return;
        
        inv = all_inventory(environment(me));
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type || ob==me) {
                        continue;
                }
//              message_vision(" find a baohu.\n",me);
                gotit=0;
                if (sizeof(pros)) {
                        for (j=0;j<sizeof(pros);j++) {
                                if (pros[j]==ob) gotit=1;
//                              command("say already protecting me");}
                        }
                }
                if (gotit) continue;
                
                if(sizeof(pros))
                        pros += ({ ob });
                else
                        pros = ({ ob });
//              message_vision(" one baohu is added.\n",me);
        }
        
        me->set_temp("protectors",pros);
//      message_vision(" out baohu.\n",me);
}       
                 
//      this function resort the query_enemy(), put lowest-exp-player on top, and
//      put NPC below players. 
object *resort_enemy() {
        object *enemy,*new_enemy,*mid_enemy,me;

        int i,k,j;
        int num,lowest;
        object mem;
        
        new_enemy= ({});
        mid_enemy= ({});
        me=this_object();
        enemy=me->query_enemy();
        
        if (sizeof(enemy)<=1) return enemy;
        for( i=0;i<sizeof(enemy);i++) {
                if (userp(enemy[i])) {
                        new_enemy += ({ enemy[i] });
                }
        }
        num=sizeof(new_enemy);
        if (num>1) {
        for (j=0;j<num;j++) {   
                lowest=100000000;
                for (k=0;k<sizeof(new_enemy);k++) {
                        if (new_enemy[k]->query("combat_exp")<lowest) {
                                mem=new_enemy[k];
                                lowest=mem->query("combat_exp");
                        }
                }
                mid_enemy += ({ mem });
                new_enemy -= ({ mem });
        }
        new_enemy = mid_enemy;
        }
        for( i=0;i<sizeof(enemy);i++) {
                if (!userp(enemy[i])) {
                        new_enemy += ({ enemy[i] });
                }
        }
        return new_enemy;
}       
         
//      this function checks if there are similar group NPCs around.

int accompany(object me) {
        string type;
        object *inv;
        int i;
        
        type = me->query("dungeon_npc");
        if (!type) return 0;
        inv=all_inventory(environment(me));
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]==me) continue;
                if (inv[i]->query("dungeon_npc")==type) {
                        return 1;
                }
        }       
        return 0;
}  
void do_weapon_busy(object target) {
        
        object me,weapon,weapon_new, *inv;
        int k;
        string old_skill;
        int pfm_weapon_busy;
        string w_busy_class,w_busy_type,w_busy_skill,w_busy_name; 
//      command("say begin to weapon busy.");   
        me= this_object();
        if (me->query("perform_busy_w"))        
        if (sscanf(me->query("perform_busy_w"),"%s/%s/%s/%s",w_busy_class,
                        w_busy_type,w_busy_skill,w_busy_name)==4)
                { 
                pfm_weapon_busy=1;
        } 
        old_skill=me->query_skill_mapped(w_busy_type);
        map_skill(w_busy_type,w_busy_skill);
        
        weapon=me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type")!=w_busy_type){
                ccommand("unwield all");
                inv=all_inventory(me);
                for (k=0;k<sizeof(inv);k++){

                        if (inv[k]->query("skill_type")==w_busy_type){
                                weapon_new=inv[k];
                                command("wield "+inv[k]->query("id"));
                        }
                }
                if (!query_temp("weapon"))
                        weapon_new= carry_object("/obj/weapon/"+w_busy_type);
                        command("wield "+weapon_new->query("id"));
//              command("say found the right weapon to perform weapon busy");
        }
        me->set("class",w_busy_class);
        SKILL_D(w_busy_skill)->perform_target(me,w_busy_name,target);
        
//      me->perform_action(weapon_busy_type+"."+pfm+" "+target->get_id());
//      message_vision(" it is "+weapon_busy_type+pfm+".\n",me);
        if (weapon) {
        if (weapon_new) {
                command("unwield all");
                command("wield "+weapon->query("id"));
        } 
        } else command("unwield all");
        map_skill(w_busy_type,old_skill);
}  
void do_unarmed_busy(object target) { 
        object me,weapon;
        int pfm_unarmed_busy;
        string u_busy_class,u_busy_type,u_busy_skill,u_busy_name;
        
        me= this_object();
//      command("say begin to unarmed busy.");
        if (me->query("perform_busy_u"))        
        if (sscanf(me->query("perform_busy_u"),"%s/%s/%s/%s",u_busy_class,
                        u_busy_type,u_busy_skill,u_busy_name)==4)
                { 
                pfm_unarmed_busy=1;
                message_vision(u_busy_class+" "+u_busy_type+" "+u_busy_skill+" "+u_busy_name+".\n",me); 
        }
        weapon=me->query_temp("weapon");
        if (weapon) ccommand("unwield all");

        me->set("class",u_busy_class);
        SKILL_D(u_busy_skill)->perform_target(me,u_busy_name,target);
        if (weapon) command("wield "+weapon->query("id"));
        
} 
void heart_beat() {
        int wimpy_ratio, to_wimpy, cnd_flag;
        mapping my;
        object ob;
        string savemyass;
        object *enemy;
        if(!this_object()) {
                return;
        } 
        if (query_temp("in_heart_beat"))
                return; 
        my = query_entire_dbase();
        
        // If we are dying because of mortal wounds?
        if( my["eff_kee"] < 0 || my["eff_sen"] < 0 || my["eff_gin"] < 0  
                        || my["kee"] < -10 * my["dur"]  || my["sen"] < -10 * my["dur"] || my["gin"] < -10 * my["dur"]) {
                remove_all_enemy();
                die();
                return;
        }
        
        // If we are unconcious, just return;
        if(query_temp("is_unconcious"))  {
                return;
        }
        
        // If we're dying or falling unconcious?
        if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0) {
                remove_all_enemy();
                unconcious();
                return;
        }
        
        

        // do_densive/offensive choice
        if (query("defense_type") && is_fighting()) {
                if(is_busy()) do_defense(query("defense_type"));
                        else  {
                                do_remove_defense(query("defense_type"));
                        }
        }
        
        
        if (!is_busy()) {
        
        // (2) Do attack or clean up enemy if we have fleed.
        if(is_fighting()) {
                // as long as we are in a fight, we are nervous, our 心神 drops
                my["sen"]--;
                attack();
        } 
        // (3) chat() may do anything -- include destruct(this_object())
        // objectp check is added for some strange this_object() return 0 reason.
        if(objectp(this_object()) && !userp(this_object())) {
                this_object()->chat();
                if(!this_object()) {
                        return;
                }
        }
        }
        
        // If busy, continue action and return here.
        if(is_busy()) {
                continue_action();
                return;
        } 
        if(tick--) {
                return;
        } else {
                tick = 5 + random(10);
        }
        
        cnd_flag = update_condition();

        if (!living(this_object())) return;
        // If we are compeletely in peace, turn off heart beat.
        // heal_up() must be called prior to other two to make sure it is called
        // because the && operator is lazy :P 
        if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up()) && !is_fighting() 
                        && !interactive(this_object())) {
                if(environment()) {
                        ob = first_inventory(environment());
                        while(ob && !interactive(ob)) {
                                ob = next_inventory(ob);
                        }
                }
                if(!ob && !query("ALWAYS_ACTIVE")) set_heart_beat(0);
        }
        if(!this_object()) return;
        if(!interactive(this_object())) return;
        
}  
void do_remove_defense(int num) {
        
        object weapon,me,*inv;
        int k;
        string weapon_type,weapon_skill,unarmed_skill;
        
        me=this_object();
        
        if (num) {
                unarmed_skill=query("skill_type_u");
                command("enable unarmed "+unarmed_skill);
                if (query("skill_type_w")) {
                if (sscanf(query("skill_type_w"),"%s/%s",weapon_type,weapon_skill)==2){
                        command("enable parry "+weapon_skill);
                        command("enable "+weapon_type+" "+weapon_skill);
                        weapon=query_temp("weapon");
                        if (!weapon || weapon->query("skill_type")!=weapon_type){
                                command ("unwield all");
                                inv=all_inventory(me);
                                for (k=0;k<sizeof(inv);k++){
                                        if (inv[k]->query("skill_type")==weapon_type)

                                                command("wield "+inv[k]->query("id"));
                                }                       
                        }
                }
                } else command("unwield all");
        }
} 
void do_defense(int n) {
        object me, *inv,weapon;
        int k; 
        
        if (!n) return;
        me=this_object();
        switch (n) {
                case 1: map_skill("parry","xiaohun-sword");
                        map_skill("sword","xiaohun-sword");
                        weapon=me->query_temp("weapon");
                        if (!weapon || weapon->query("skill_type")!="sword")    {
                                command("unwield all");
                                inv=all_inventory(me);
                                for (k=0;k<sizeof(inv);k++){
                                        if (inv[k]->query("skill_type")=="sword")
                                                command("wield "+inv[k]->query("id"));
                                }
                                if (!query_temp("weapon"))
                                        carry_object("/obj/weapon/sword");
                                        command("wield sword");
//                              command("say xiaohun enabled from clone weapon");       
                        }
                        break;
                case 2: map_skill("parry","xiaohun-whip");
                        map_skill("whip","xiaohun-whip");
                        weapon=me->query_temp("weapon");
                        if (!weapon || weapon->query("skill_type")!="whip")     {
                                command("unwield all");
                                inv=all_inventory(me);
                                for (k=0;k<sizeof(inv);k++){
                                        if (inv[k]->query("skill_type")=="whip")
                                                command("wield "+inv[k]->query("id"));

                                }
                                if (!query_temp("weapon"))
                                        carry_object("/obj/weapon/whip");
                                        command("wield whip");
//                              command("say xiaohun enabled from clone weapon");       
                        }
                        break;
                case 3: command("unwield all");
                        map_skill("unarmed","yue-strike");
                        break;
                default: break;
                case 4: command("unwield all");
                        map_skill("unarmed","lingxi-zhi");
                        break;
                }               
}  
void cast_attack() {
        string cast_type;
        cast_type=this_object()->query("cast_attack");
        this_object()->set("mana",this_object()->query("max_mana"));
        this_object()->cast_spell(cast_type);
        this_object()->set("mana",this_object()->query("max_mana"));
        return;
}  
void sheet_fight() { 
        object obj, soldier, me;
        int spells;
        me = this_object();
        if( me->query_temp("max_guard") > 4 ) return;
        message_vision("$N集中精神，祭起三味真火，唿的一声天师符着了起来！\n", me);
        me->start_busy(1);
        spells = me->query_skill("scratching");
        seteuid(getuid());
        if( random(10) < 5 )
                soldier = new("/obj/npc/heaven_soldier");
        else
                soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me, spells);

        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
        message_vision(HIB "\n$N躲在$n的背后喊道：给我杀！\n" NOR, me, soldier );
} 
void alchemy_fight() {
                
        string weapon_name,x;
        int i;
        object *enemy,weapon,owner,victim;
        switch( random(4)){
                case 0: weapon_name="zhui";
                        break;
                case 1: weapon_name="chain";
                        break;
                case 2: weapon_name="mirror";
                        break;
                case 3: weapon_name="flag";
                        break;
                }
        switch (weapon_name) {
                case "mirror": x="m";break;
                case "flag" : x="f";break;
                case "chain": x="c";break;
                case "zhui": x="z";break;
        }
        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        while(i--)       {
                weapon = new("/obj/specials/alchemy/magic/"+weapon_name);
                weapon->move(this_object());
                if(enemy[i] && objectp(enemy[i]) && environment(this_object())==environment(enemy[i])) {
                        if (!userp(enemy[i])) { 
                                if(owner=enemy[i]->query("possessed")) {
                                        victim = owner;
                                        if (!victim->is_fighting()) {
                                                kill_ob(victim);
                                                command("shoot"+x+" "+victim->get_id());
                                        }
                                }

                        }
                        this_object()->stop_busy();
                        command("shoot"+x+" "+enemy[i]->get_id());
                        this_object()->stop_busy();
                }
        }
        this_object()->start_busy(2);
}  
void ask_help() {
        object me, *enemy, *inv, ob;
        string type;
        int i, j;
        
        me= this_object();
        type = me->query("dungeon_npc");
        if (!type) return;
        enemy = me->query_enemy();
        inv = all_inventory(environment(this_object()));
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type || ob==me) {
                        continue;
                }
                for (j=0;j<sizeof(enemy);j++) {
                        if (ob->is_fighting(enemy[j])) {
                                continue;
                                }
                        ob->kill_ob(enemy[j]);
                }               
        }
}  
void help_friend() {
        object me, *inv, ob;
        string type;
        int i, j;
        
        me= this_object();
        type = me->query("dungeon_npc");

        inv = all_inventory(environment(this_object()));
        
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type) {
                        continue;
                }
                if (ob->query("kee")>ob->query("max_kee")/3 
                        && ob->query("eff_kee")>ob->query("max_kee")/3
                        && ob->query("gin")>ob->query("max_gin")/3 
                        && ob->query("eff_gin")>ob->query("max_gin")/3
                        && ob->query("sen")>ob->query("max_sen")/3 
                        && ob->query("eff_sen")>ob->query("max_sen")/3)
                {
                        continue;
                }
                if (ob!=me)
                        message_vision(HIY "$N运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"NOR,me,ob);
                        else
                                message_vision(HIY "$N运起内功，缓缓地将真气在体内流转....\n\n"NOR,me);
                        call_out("heal_him", 6, me, ob);
                        me->start_busy(1);
                        return;
                                
        }
        return;
}  
int heal_him(object me, object target)
{
        int amount;
        amount=6000;
        if (!objectp(me)) return 0;
        if (me->is_unconcious()) return 0;
        
        if (!present(target,environment(me))) {
                tell_object(me,"你要救治的人已经不在这里了。\n");
                return notify_fail("");
                }

        if (target!=me)
        message_vision(HIY"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n"NOR,me,target);
        else 
        message_vision(HIY"过了不久，$N吐出一口瘀血，脸色看起来红润多了。\n"NOR,me);
        target->receive_curing("kee", amount);
        target->receive_curing("sen", amount);
        target->receive_curing("gin", amount);
        if (target->query("kee")+ amount<target->query("max_kee"))
                target->add("kee",amount);
                else target->set("kee",target->query("max_kee"));
        if (target->query("sen")+ amount<target->query("max_sen"))
                target->add("sen",amount);
                else target->set("sen",target->query("max_sen"));
        if (target->query("gin")+ amount<target->query("max_gin"))
                target->add("gin",amount);
                else target->set("gin",target->query("max_gin"));
        return 1;
}  
int enemy_value(object *all_enm)
{
        int i,val,exp;
        val=0;
        exp=query("combat_exp");
        for(i=0;i<sizeof(all_enm);i++)
        {
                if(all_enm[i]->query("combat_exp")<exp*2/3)
                        val+=1;
                else if(all_enm[i]->query("combat_exp")<exp)
                        val+=3;
                else if(all_enm[i]->query("combat_exp")<exp*2)
                        val+=6;
                else val+=10;
        }
        return val;
} 
int enemy_type(object enemy) {
        string class_type;
        int type;
        object me;

        
        me=this_object();
        class_type=enemy->query("class");
        message_vision("this is enemy type "+class_type+".\n",me);      
        switch (class_type) {
        //      this need cut mana by any means, then leave them alone
        case "taoist": if (enemy->query("mana")>200) type =1;
                                else type =6;
                        break;
        //      this needs cut mana than using special way to kill
        case "lama":    if (enemy->query("mana")>200) type =1;
                                else type =3;
                        break;
        //      this needs cut force if he is using shield, then put in asap kill
        case "shaolin": if (enemy->query("force")>50) type =2;
                                else type =3;
                        break;                          
        //      this needs to be killed asap purely due to their damage and busy power  
        case "fugui":
        case "legend":
        case "knight":
        case "huashan": type = 4;       break;
        //      this needs to be taken notice
        case "official": type = 5;      break;
        //      these are tricky classes and requires skills to play, so mostly we can 
        //      let them live a while.
        case "wudang":
        case "bonze":
        case "beggar":
        case "yinshi":
        case "shenshui":
        case "swordsman":
        case "assassin":
        case "bat":
        default:        type =6;        break;
        }
        message_vision("this is enemy return "+(string)(type)+".\n",me);        
        return type;
}       

          
void die(){
        object book;
        int i;
        message_vision(HIR"\n$N惨叫一声倒了下去，化作一阵轻烟消失了。\n"NOR,this_object());     
        book = new("obj/money/silver");
        book->set_amount(10);
        book->move(environment(this_object()));
        destruct(this_object());        
}     
 cr
cr
cr
cr
cr
cr
cr
cr
cr
cr
什么？
 什么？
 什么？
 什么？
 什么？
 什么？
 什么？
 什么？
 什么？
 什么？
