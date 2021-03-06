 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "如意天魔连环八式");
        set("usage/blade", 1);
        set("usage/parry", 1);
        set("effective_level", 200);
        set("learn_bonus", 0);
        set("practice_bonus", -5);
        set("black_white_ness", 20);
        set("skill_class", "bandit");
        set("parry_msg", ({
        "$n将天魔八式融会贯通，舞出重重刀幕，手中的$v化成一片魔影护住全身。\n",
                })
        );
        set("unarmed_parry_msg", ({
        "$n将天魔八式融会贯通，舞出重重刀幕，手中的$v化成一片魔影护住全身。\n",
                })
        );
        action = ({
        ([      "action":               "$N使出天魔八式中的起手式“万魔初醒”，手中的$w划出一溜光芒斩向$n的$l",
                "damage":               60,
                "dodge":                160,
                "parry":                160,
//               "force":                400,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手一抖，一招“魔焰万丈”手中的$w幻成一片刀花，散向$n的$l",
                "damage":               70,
                "dodge":                90,
                "parry":                90,
//                "force":                200,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N刀锋忽转，手中的$w一招“魔光乍现”，闪电般劈向$n的$l",
                "damage":               80,
                "dodge":                190,
                "parry":                190,
//                "force":                200,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身影晃动，刀锋忽左忽右，一招“天魔独尊”，手中的$w，从中路突然砍至$n的$l",
                "damage":               60,
                "dodge":                100,
                "parry":                100,
//                "force":                200,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               "$N的双脚点地，刀背贴身，一招“万刃天魔”全身转出一团刀光滚向$n",
                "damage":               80,
                "dodge":                80,
                "parry":                80,
//				"force":                200,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N刀刃向上，一招“天魔回天”，从一个$n意想不到的角度撩向$n的$l",
                "damage":               60,
                "dodge":                130,
                "parry":                130,
//                "force":                200,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N手中的$w左右横划，一招“天魔七现”，来来回回地狂扫向$n的$l",
                "damage":               70,
                "dodge":                110,
                "parry":                120,
//                "force":                200,
                "damage_type":  "割伤"
        ]),
		([		"action":               "$N使出如意天魔连环八式中的收手式“万魔归宗”，手中的$w迅捷无比地砍向$n的$l",
                "damage":               100,
                "dodge":                200,
                "parry":                200,
//		  		  "force":                500,
				"damage_type":  "砍伤"
     ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }

        if((string)me->query_skill_mapped("force")!= "demon-force") {
                return notify_fail("如意天魔连环八式必须配合天地人魔心法才能练。\n");
        }
        
        if (me->query_skill("demon-force",1)<(int)me->query_skill("demon-blade",1))
                return notify_fail("你的天地人魔心法火候不够。\n");

        if((int)me->query_skill("force", 1) < 50) {
                return notify_fail("你的内功心法火候不足，无法练如意天魔连环八式。\n");
        }
        if( (int)me->query_skill("demon-force", 1) < 60 ) {
            return notify_fail("你的天地人魔心法火候不足，无法练如意天魔连环八式。\n");
                }
        return 1;
} 
int practice_skill(object me)
{
        object weapon; 
        if( (int)me->query("kee") < 40 ) {
                return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        }
        me->receive_damage("kee", 40);
        return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob;
        if( random(damage_bonus) < 300 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "blade")
        if(victim->query_skill_mapped("blade") == "wind-blade" )
        if(me->query_skill("blade") > victim->query_skill("blade")) {
        switch(random(3)) {
                case 0:
                        message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                        break;
                case 1:
                        message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                        break;
                case 2:
                        message_vision(HIR "\n因刀法相克，$n逐渐施展不开了！" NOR,me,victim);
                        break;
                        }
        return random(me->query_skill("blade")) * 10;
        }
        return 0;
}      
