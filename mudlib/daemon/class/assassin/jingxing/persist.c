#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
        int skill;
        skill = me->query_skill("jingxing",1); 
        if (me->query("class")!="assassin")
                return notify_fail ("静气诀只有金钱帮弟子能使用。\n"); 
        if( skill < 150) 
                return notify_fail("你的静行心法太差了！\n");
        
        if (me->query("combat_exp")<3000000)
                return notify_fail("你的战斗经验不足，还不能领会静气诀。\n");
                                
        if( target != me ) 
                return notify_fail("静心诀只能施用于自身。\n");
        if( (int)me->query("force") < 200 )   
                return  notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("jingxing/persist")) 
                return  notify_fail("你已经在运用类似的内功了。\n");
        
        me->add("force", -200);
        message_vision(YEL "$N缓吐深纳，运起“静气诀”，脑中空明澄澈，魂不内荡，神不外游。\n" NOR, me);
        call_out("fillup",10,me,10,0,skill*4);        
        me->set_temp("jingxing/persist", 1);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void fillup (object me, int total, int count, int amount)
{
        if(++count>=total)
        {
                tell_object(me,WHT"你的静气诀运转完毕，将内息收回丹田。\n"NOR);
                me->delete_temp("jingxing/persist");
                return;
        }
        else {
                if (me->query("force")<me->query("max_force"))
                        me->add("force",amount);
                tell_object(me,GRN"你只觉丹田中有一股气渐渐暖将上来。\n"NOR);
           call_out("fillup",10,me,total,count, amount);
        }
        return ;
}    
