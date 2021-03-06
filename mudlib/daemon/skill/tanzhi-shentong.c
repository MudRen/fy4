 // tanzhi-shentong.c
inherit SKILL;
#include <ansi.h>
mapping* throwing_action;
void setup(){ 
        
        set("name", "弹指神通");
//      set("usage/unarmed", 1); --- for uniqueness/balance of huashan skill, by silencer
        set("usage/throwing", 1);
        set("usage/parry", 1); //this is taken care of in enable.c
        set("effective_level", 200);
        set("learn_bonus", -250);
        set("practice_bonus", -10);
//      set("practice_limit",165);
        set("black_white_ness", 5);
        set("skill_class", "huashan");
        
        set("parry_msg", ({
        "$n无名指弹出，一缕指风点向$N曲池穴。$N急忙撤肘收招。\n",
                "$n右手轻弹，森森指风点向$N双目。$N几乎睁不开眼睛。\n",
                "$n浅笑声中，左手食指轻弹，一缕暗劲射向$N环跳穴。$N踉踉跄跄连连后退。\n", 
        }) );
        set("unarmed_parry_msg", ({
                "$n无名指弹出，一缕指风点向$N曲池穴。$N急忙撤肘收招。\n",
                "$n右手轻弹，森森指风点向$N双目。$N几乎睁不开眼睛。\n",
                "$n浅笑声中，左手食指轻弹，一缕暗劲射向$N环跳穴。$N踉踉跄跄连连后退。\n", 
        }) );   
        action = ({
        ([      "action":               
"$N食指微屈，轻轻弹出，一股细细的气劲射向$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "刺伤",
                "weapon":               "指风",
        ]),
        ([      "action":               
"$N中指弹出，指风如刀，划向$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "指风",
        ]),
        ([      "action":               
"$N左手斜展，小指微翘斜刺$n的$l，仪态神妙不可方物",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "刺伤",
                "weapon":               "指风",
        ]),
        ([      "action":               
"$N无名指“嗤”地弹出，指风如冷箭般射向$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "指风",
        ]),
        ([      "action":               
"$N身形闪动，左手五指连弹，右手拇指凝力按向$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,
                "damage_type":  "刺伤",
                "weapon":               "指风",
        ]),     
        }); 
        throwing_action = ({
        ([      "action":               
"$N食指微屈，轻轻弹出，$w如电光般射向$n的$l。 ",
                "dodge":                30,
                "parry":                30,
                "force":                280,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),
        ([      "action":               
"$N中指弹出，指风如刀，$w在劲风中飞向$n的$l。 ",
                "dodge":                30,
                "parry":                30,
                "force":                290,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),
        ([      "action":               
"$N左手斜展，小指微翘将$w弹出斜刺$n的$l，仪态神妙不可方物。 ",
                "dodge":                30,
                "parry":                30,
                "force":                340,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),
        ([      "action":               
"$N无名指“嗤”地弹出，$w如冷箭般射向$n的$l。 ",
                "dodge":                30,
                "parry":                30,
                "force":                290,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),
        ([      "action":               
"$N身形闪动，左手五指连弹，右手拇指凝力，将$w射向$n的$l。 ",
                "dodge":                100,
                "parry":                100,
                "force":                290,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),     
        });
}  
mapping query_action(object me, object weapon)
{
        if(this_player()->query_temp("weapon"))
                return throwing_action[random(sizeof(throwing_action))];
        else return action[random(sizeof(action))];
}
int valid_learn(object me)
{
/*  if((string)me->query("gender") != "女性") {
        return notify_fail("弹指神通是只有女子才能练的武功。\n");
    }*/
    if((int)me->query("max_force") < 250 ){
        return notify_fail("你的内力不够！\n");
        }
    return 1;
} 
int practice_skill(object me)
{
        if(!::practice_skill(me)){
                return 0;
        }
    if((int)me->query("force") < 10 ) {
        return notify_fail("你的内力不够了。\n");
        }
    me->add("force", -10);
    return 1;
}
  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 150 ) return 0;
    if( victim->query_temp("weapon")==0) {
        if(victim->query_skill_mapped("unarmed") == "dragonstrike" 
                && me->query_skill("tanzhi-shentong",1)+50 > victim->query_skill("dragonstrike",1)) {
        switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N射出满天指气，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
        return random(me->query_skill("throwing")) * 2;
        }
    }
    return 0;
}
