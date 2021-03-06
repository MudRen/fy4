 // xiaolang
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("［缠字诀］只传授给丐帮弟子！\n");
        
        extra = me->query_skill("dagou-stick",1);
        if ( extra < 175) return notify_fail("你的打狗棒法还不够纯熟！\n");
        
        if (userp(me) && me->query_skill_mapped("force") != "huntunforce")
                return notify_fail("［缠字诀］需要［混沌心法］的配合！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［缠字诀］只能对战斗中的对手使用。\n");
        
        if(target->is_busy())
                return notify_fail("对方已经都快狗急跳墙了，你就不要在缠他了。\n");
        
        myexp = (int) me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        
        if (!userp(target))
        if (hisexp>3500000) 
                hisexp = hisexp*2;
        weapon = me->query_temp("weapon");
        message_vision(HIY"$N"HIY"看准$n招式破绽，棒法一变，一招“"NOR+CYN"缠"NOR+HIY"”字诀，手中的"+weapon->name()+"贴身缠绕在$n周围。\n"NOR,me,target);
        if(random(hisexp) < myexp*1.2)  {
            message_vision(HIG "$N"HIG"眼看$n棒法缜密，无法闪躲，只能就地一滚，只见"+weapon->name()+"跟随着$N在地上不停的晃动。\n"NOR,target,me);
            target->start_busy(2+random(3));
        } else  {
                message_vision(HIW"但是$N未等$n招式使老，陡然护住自己的破绽，全身上下无懈可击！\n"NOR,target,me);        
                me->start_busy(2);
        }
        return 1;
}   
