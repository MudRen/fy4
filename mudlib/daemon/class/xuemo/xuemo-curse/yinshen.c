 // curse_yinshen.c
#include <ansi.h> 
inherit SSERVER;
int curse(object me, object target)
{
        int lvl,i;
        object env, *inv;

        if(me->query("env/invisibility"))
                return notify_fail("你正在施展［隐身术］\n");

        message_vision(RED "$N口中念念有词，整个身形逐渐虚化消失......\n" NOR, me);
        me->start_call_out( (: call_other, __FILE__, "take_effect", me :), 1);
//        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 20+lvl/10+3*random(lvl/10));
//        if( me->is_fighting() ) me->start_busy(3);
        return 1; 
}
/* void remove_effect(object me)
{
        me->set("env/invisibility", 0);
        message_vision(HIG "$N的身形渐渐地显现出来。\n" NOR, me);
        me->move(environment(me));
        me->start_busy(1);
        tell_object(me,YEL"你的隐识失效了。\n"NOR);
} */
void take_effect (object me)
{
        me->set("env/invisibility", 1);
        tell_object(me,YEL"你成功隐身了。\n"NOR);
        
} 
        
       
