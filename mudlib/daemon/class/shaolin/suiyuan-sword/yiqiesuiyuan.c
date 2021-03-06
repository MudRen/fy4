 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("suiyuan-sword",1) ;
        if (extra < 100) 
                return notify_fail("你的随缘无忧剑法不够纯熟！\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［一切随缘］只能对战斗中的对手使用。\n");
                
        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        
        if (hisexp>3500000) hisexp=hisexp*3;
        
        if(random(hisexp) < myexp  && weapon && random(2))      
        {
        message_vision(
HIG "\n$N使出一式［一切随缘］，剑身似灵蛇般缠住$n手中的兵刃，"+ 
weapon->name()+  HIG"脱手而飞！\n" NOR, me,target);
        if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
        me->add_temp("apply/attack", extra*4);
        me->add_temp("apply/damage", extra*2);
        msg = HIY+ "\n$N使出一式［一切随缘］，手中的"+(me->query_temp("weapon"))->name()+HIY"如闪电般直刺$n的$l！\n"+ NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra*4);
        me->add_temp("apply/damage", -extra*2);
        if (me->query_busy()<2) me->start_busy(2);
        }
        return 1;
}   
