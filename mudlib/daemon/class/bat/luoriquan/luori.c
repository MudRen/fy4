#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        
        extra = me->query_skill("unarmed")*3;
         if (me->query("class")!="bat") extra /= 2;
        if (me->query_skill("luoriquan",1) < 220 && userp(me)) 
                return notify_fail("落日拳法需要220级落日神拳！\n");
        if( !target ) target = offensive_target(me);
        if( !target
                ||      !target->is_character()
                ||      !me->is_fighting(target) )
                return notify_fail("［落日］只能对战斗中的对手使用。\n");
        
        me->add_temp("apply/attack",extra/5);
        me->add_temp("apply/damage",extra/8);
        
        msg = HIM  "\n$N仰天发出一声长笑，放声高歌，顿时间天地亦为之变色！\n" NOR;
        message_vision(msg,me,target);
        msg = HIC    " 一身托天地，
　　　　　　　　　　　醒醉寄浮舟。\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  " 忽然酹中流， 
　　　　　　　　　　扣舷发狂歌。\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "歌尽续长笑， 
　　　　　　　　　　浪子意如何？ \n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW   "回首来时路， 
　　　　　　　　　　灼灼日已没！\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR   "－－－长－－－日－－－将－－－尽－－－\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra/5);
        me->add_temp("apply/damage",-extra/8); 
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}
