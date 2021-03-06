 // yingjichangkong
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        int extra;
        int yourexp,myexp,cpexp;
        string msg;
        
        
        extra = me->query_skill("hawk-steps",1);
        if ( userp(me) && extra < 100) return notify_fail("你的［鲲鹏步法］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［鹰击长空］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
   
        if (target->query("step_less")==1) 
                return notify_fail(HIW"此人身势灵活，功力深湛，不会被此步法迷惑的。\n"NOR);
        
        message_vision(HIB "$N"+HIB"腾身而起，身形有若鹰翔九天，翩若惊鸿！\n"NOR,me,target);
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=myexp/2+ (2+extra/50)*random(myexp)/2;
        
        if(me->query("class") != "fugui" && userp(me)) cpexp=(2+extra/50)*random(myexp)/2;
        
        if( yourexp < cpexp)    {
                message_vision(HIB"$N"+HIB"仰首一望，不由心神俱失，竟已忘了自己尚身处险境，呆若木鸡！\n"NOR,target);
                target->start_busy(2+random(2));
        }
        else{
                msg = HIR"可惜$N"+HIR"看出了$n"+HIR"的破绽，抱元守一，结果$p"+HIR"一筹莫展！"NOR;
                COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
                me->start_busy(2);      
   }
        return 1;
} 
