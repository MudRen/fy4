#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
    int extra, bonus,n;
    string msg;
    if (me->query("class") != "huashan") return notify_fail("只有华山弟子可以使用「摘心式」。\n");
    if( !target ) target = offensive_target(me);
    extra=me->query_skill("zhaixin-claw",1);
    if (extra<50) return notify_fail("你的「摘心手」不够熟练！\n"); 
    if( !target||!target->is_character()||!me->is_fighting(target) )
        return notify_fail("「摘心式」只能对战斗中的对手使用。\n");
 
     if ((!userp(target)) && me->query("timer/zhaixin")+600>time())
        return notify_fail("「摘心式」耗费体力极大，不能连续使用。\n"); 
    
    msg = HIW "$n面色变得惨白如纸，双手提起，指尖发出莹莹的光芒。 
$n忽然用一种奇幻的身法闪到$N面前，双爪电击般抓向$N心口！ \n"NOR; 
    
        me->set("timer/zhaixin",time());        
/*  cloud-dance is temperorily taken out from huashan skills
        the bonus here is not reasonable, given players can using alias with Level 1 
        cloud-dance to get the bonus.
        we might consider add it back in the future patch. --- silener */ 
//  give bonus to NPC kill
        if (userp(target)) bonus = 2;
                else bonus = 3;  
                n = 150/extra + bonus;
    if( random(extra*extra*extra*bonus/4 + me->query("combat_exp")/8)*bonus + me->query("combat_exp")/2>
 (int)target->query("combat_exp")&& random(5) && !target->query("boss")) {
        msg += RED"\n\n$N"RED"用不可置信的眼光看着自己心口的血洞，身子一晃，倒在地上。 \n" NOR;
        target->receive_wound("kee", ((int) target->query("max_kee")+300000),me);
    }
    else msg += HIC"\n\n$N连忙收招封住$n手腕，在森森爪影下旋身急退，躲开了$n的致命一击。 \n" NOR; 
    message_vision(msg, target, me);
    me->set("sen",50);
    me->set("force",0);
    me->set("force_factor",0);
    me->start_busy(n);
    return 1;
}       
