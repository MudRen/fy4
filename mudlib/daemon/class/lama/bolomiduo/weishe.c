 // weishe.c
#include <ansi.h> 
inherit F_CLEAN_UP; 
int exert(object me, object target)
{
        object *ob,victim;
        string who,weapon;
        int cps, skill, myexp,tarexp; 
	
	weapon=target->query_temp("weapon");
	myexp = (int)me->query("combat_exp");
	tarexp = (int)target->query("combat_exp");
	cps = (int)target->query("cps");
	skill=(int)me->query_skill("bolomiduo",1);
	
	if( skill < 160 )
		return notify_fail("你的婆萝蜜多心经等级不够，不能使用威慑！\n");
	if( me->query("class") != "lama")
		return notify_fail("「威慑」只有密宗弟子才能使用！\n");
	if( me->is_fighting() )
                return notify_fail("战斗中不能使用「威慑」。\n");
        if( me->query("weishe/timer")+300 > time())
        	return notify_fail("威慑很耗费体力，你还是休息一下吧。\n");
	victim = present(who, environment(me)); 
        if( !victim || victim == me) return notify_fail("你想威慑的对象不在这里。\n"); 
        if( !living(victim) || !objectp(victim))
                return notify_fail("你要威慑谁？\n"); 
        if( !me->is_fighting() && !target->is_fighting() &&
 		environment(me) == environment(target))
 	{
 		if(objectp(weapon)){
 			message_vision(HIR"$N对着$n大喝一声道：还不放下手中的武器，束手就擒！更待何时？！\n"NOR,me,target);
 			if(myexp+random(myexp/2) < tarexp/2)
 				message_vision(HIC"$N对$n冷笑一声道：这样的雕虫小技，也来吓我？\n"NOR,target,me);
 			else {
 				message_vision(WHT"$N被$n的阵势所慑，不由自主的放下了手中的武器。\n"NOR,target,me);
 				weapon->unequip();
 			}
 		me->set("weishe/timer",time());
 		}else return notify_fail("对方没有用武器，不需要使用威慑！\n");
	}
	me->start_busy(1);
        return 1;
}     
