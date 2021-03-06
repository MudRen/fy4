 // luoriquan.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "落日神拳");
        set("usage/unarmed", 1);
        set("effective_level", 248);
        set("learn_bonus", -150);
        set("skill_class", "bat");
        set("parry_msg", ({
        "$n一声大喝使出「风生万马间」，幻出满天掌影，将$N所有招式化于无形。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n冉冉腾空而起，早以一招「江鸣夜雨悬」令$N所有招式都落在空处。\n",
        }) );   
        action = ({
                ([      "action":               "$N长啸连连，使一招「暮色千山入」，双手闪电般击向$n$l",
                        "force":                70,
                        "dodge":                30,
                        "parry":                70,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N飘然有出尘之意，一招「穿花露滴衣」回拍$n的$l",
                        "force":                80,
                        "dodge":                40,
                        "parry":                70,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N陡然回身一转，一招「白云回望合」向$n$l虚空拍出一掌",
                        "force":                90,
                        "dodge":                50,
                        "parry":                80,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N一招「因风离海上」，身行飘渺如云烟，忽地向$n的$l一拂",
                        "force":                80,
                        "dodge":                20,
                        "parry":                80,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N双手合击，一招「月涌大江流」猛然击向$n的$l",
                   "force":                70,
                        "dodge":                10,
                        "parry":                80,
                        "damage_type":  "瘀伤"
                ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if ((int)me->query("max_force") < 500){
        return notify_fail("你的内力太弱，无法练落日神拳。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("luoriquan",1) > 180)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");       
        if ((int)me->query("force") < 20) {
                return notify_fail("你的内力不够练习。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}   
mixed hit_ob(object me, object victim, int damage_bonus) {
        if(random(damage_bonus) < 150) {
                return 0;
        }
        if(victim->query_skill_mapped("blade") == "moon-blade" )
        if(me->query_skill("unarmed") > victim->query_skill("blade")){
                switch(random(3)) {
                        case 0:
                                message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                                break;
                        case 1:
                                message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                                break;
                        case 2:
                                message_vision(HIR "\n因武功相克，$n逐渐施展不开了！" NOR,me,victim);
                                break;
                }
                return random(me->query_skill("unarmed")) *5/3;
        }
        return 0;
}    