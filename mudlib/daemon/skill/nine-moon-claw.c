 // nine-moon-claw.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "九阴白骨爪");
        set("usage/unarmed", 1);
        set("effective_level", 200);
        set("skill_class", "shenshui");
        set("learn_bonus", 0);
        set("practice_bonus", -50);
        set("black_white_ness", -80);
        set("parry_msg", ({
                "$n伸出两指，一招「金石为开」，将$N的$w牢牢的夹在指中！\n",
                "$n后退一步，双手向下连抓，$N手中的$w似乎突然沉重起来，几乎连拿都拿不稳。\n",
                "$n向地上凌空一抓，一招「阴河倒卷」，整个人象一片枯叶一样在$N$w的气流中飘荡。\n",
                "$n双爪劲力一吐一吸，一招「阴毒敷骨」，竟将$N手中的$w吸于双爪之上！\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n双臂暴长，一招「阴爪搜魂」，将$N双臂所有大穴全然罩于爪下！\n",
                "$n左臂一转，从$N意想不到的角度猛然回击，一招「阴龙乍现」将$N逼退。\n",
                "$n中指微弹，一招「无孔不入」，一股阴森森的指风直刺$N的面门。\n",
                "$n双手交错，一招「天地皆阴」将$N圈于爪风之下。\n",     
        }) );
        action = ({
        ([      "action":               
"$N使出一招「穿心百抓」，右手抓向$n的$l",
                "dodge":                330,
                "parry":                290,
                "force":                400,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出一招「残天九连抓」，左手化指为爪，连续击向$n的$l",
                "dodge":                200,
                "parry":                320,
                "force":                370,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出九阴白骨爪的「爪底亡魂」，如鬼魅般欺至$n身前，一爪勾向$n的$l",
                "dodge":                200,
                "parry":                320,
                "force":                350,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N双臂一错，使出「戕帝狂爪」，对准$n的$l连续抓出",
                "dodge":                250,
                "parry":                300,
                "force":                390,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N左手指甲暴突，奋力推出，一招「九阴腐万象」，抓向$n$l",
                "dodge":                250,
                "parry":                350,
                "force":                470,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出「九阴穿两仪」，双手同时向$n的$l出爪攻击",
                "dodge":                280,
                "parry":                380,
                "force":                380,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N吐气扬声，一招「邪巫神天爪」双臂并力递出",
                "parry":                400,
                "dodge":                280,
                "force":                320,
                "damage_type":  "抓伤"
        ]),
        });
}
int valid_learn(object me)
{
        if( (string)me->query("gender") != "女性" ){
                return notify_fail("九阴白骨爪是只有女子才能练的武功。\n");
        }
   if (me->query_skill("nine-moon-claw",1) >= 50+ me->query_skill("nine-moon-force",1)){
                return notify_fail("你的九阴心经火候不够。\n");
        }
        if( (int)me->query("max_force") < 100 ){
                return notify_fail("你的内力太弱，无法练九阴白骨爪。\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if (me->query_skill("nine-moon-claw",1) > 190)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");
    if( (int)me->query("force") < 5 ){
        return notify_fail("你的内力不够了，休息一下再练吧。\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -5);
    return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    
    int damage;
    
    if( damage_bonus < 110 ) return 0;
    
    if( random(damage_bonus)/4> victim->query_str() ) {
    
        damage = (damage_bonus - 100) / 2;
        victim->add("kee",-damage);
        victim->add("eff_kee",-damage);        
        victim->receive_wound("kee",1,me );
        switch(random(3)) {
            case 0: return "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n";
            case 1: return "$N劲力一吐，$n的$l发出「喀」地一声爆响！\n";
            case 2: return "只听见$n的$l「喀」地一声 ...\n";
        }
    }
}
    
void skill_improved(object me)
{
    if( (int)me->query_skill("nine-moon-claw", 1)  % 10 == 0 ) {
        tell_object(me, RED "\n你突然觉得一股阴气冲上心头，只觉得想杀人....\n\n"NOR);
        me->add("bellicosity", 500);
    } else {
            me->add("bellicosity", 100);
        }
} 
mixed parry_ob(object victim,object me)
{
        int mylvl,extra ;
        string msg;
        mylvl=me->query_skill("nine-moon-force",1);
        if (extra=me->query_temp("nine-moon-force_poison"))
        {
                victim->receive_wound("kee",extra/3,me);
                victim->receive_damage("kee",extra/3*2,me);
                if (!victim->query_temp("weapon"))      return MAG"$N只觉触手处紫气一闪，缕缕阴寒锥心而至！\n"NOR;
                        else return MAG"$N只觉一层淡淡的紫气从兵刃上蔓延而来，刺骨的寒气几乎令手腕转动不灵。\n"NOR;
                return msg;
        }
}     
