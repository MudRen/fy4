 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "金殿纵火法");
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        set("practice_damage", 40);
        set("effective_level", 200);
        set("practice_bonus", -5);
        set("skill_class", "quanli");
        set("parry_msg", ({
                "$n慢慢伏身，突然一团火焰将$N逼得连退几步。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n手中一道火光封向$N。\n",
        }) );
        action = ({
                ([      "action":               "$N手中火光一现罩向$n的$l",
                        "dodge":                100,
                        "parry" :               100,
                        "force":                200,
                        "damage":               100,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N一招[火光冲天]，烈火焚风裹向$n的$l",
                        "dodge":                30,
                        "parry" :               100,
                        "damage":               100,
                        "force":                100,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "火烟中$N象狂风中的流云，忽聚忽散出掌击向$n的$l",
                        "dodge":                120,
                        "parry" :               80,
                        "force":                50,
                        "damage":               100,
                        "damage_type":  "瘀伤"
           ]),
                ([      "action":               "$N和着火光，纵火散向$n的$l",
                        "dodge":                100,
                        "parry" :               400,
                        "force":                50,
                        "damage":               100,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N聚起全身的功力，双手打出火团飞向$n",
                        "dodge":                300,
                        "parry" :               300,
                        "force":                100,
                        "damage":               100,
                        "damage_type":  "瘀伤"
                ]),
        });
}
int valid_learn(object me)
{
    if( (int)me->query_skill("force", 1) < 150 ) {
        return notify_fail("你的内功心法火候不足，无法练金殿纵火法。\n");
        }
        return 1;
}   
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int my_exp, your_exp, damage, lvl;
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        lvl= me->query_skill("jindian-fire",1);
        damage = lvl*2;
        
        if( 10*random(my_exp)>your_exp) {
                victim->receive_wound("kee",damage+random(damage));
                victim->set_temp("last_damage_from",me);
                return HIR "$n被烈火灼烧得焦头烂额。\n" NOR;
        }       
}   
