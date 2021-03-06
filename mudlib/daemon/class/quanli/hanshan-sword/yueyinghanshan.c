 // ice
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int perform(object me, object target) 
{ 
        string msg; 
        int extra, skill; 
        object weapon; 
        if (me->query("class")!="quanli")
                return notify_fail ("［月映寒山］只有财神庙的兄弟姐妹才能使用。\n");
        extra = me->query_skill("sword"); 
        skill = me->query_skill("hanshan-sword",1);
        if ( skill < 80)
			return notify_fail("你的［寒山十八式］还不够纯熟！\n"); 
		if ( me->query_skill_mapped("force") != "wuchenforce" )
			return notify_fail("寒山十八式需要以无尘心法为基础！\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［月映寒山］只能对战斗中的对手使用。\n"); 
        weapon = me->query_temp("weapon"); 
        me->add_temp("apply/attack", skill*3);    
        me->add_temp("apply/damage", extra*3);
        msg = HIW  "$N使出寒山十八式中的最后一式［"+HIY" 月"+HIG" 映"+HIB" 寒"+HIC" 山"+HIW" ］，手中的"+ weapon->name()+ HIW"直割$n"+HIW"的咽喉！" NOR; 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -skill*3);    
        me->add_temp("apply/damage", -extra*3);
		if(skill>120) {
        msg = RED  "只见$N"+RED"手上又多出一把"+ weapon->name()+HIR"，闪电般地刺向$n"+HIR"的眉心！" NOR; 
        me->add_temp("apply/attack", skill*2);    
        me->add_temp("apply/damage", extra*5);          
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg); 
        me->add_temp("apply/attack", -skill*2);
        me->add_temp("apply/damage", -extra*5);
        if(me->query_busy()<3) me->start_busy(3); 
		}
		else {
			if (me->query_busy()<2) me->start_busy(2);
		}
        return 1; 
}      
