#include <ansi.h>
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIY "��ȸ��" NOR, ({ "bird box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
һ�����������ԲͲ��ԲͲ������ܹ⻬������
������ƽ����ֻ������������ġ�
ԲͲ�Ͽ��ż��б����Ӵ�һ����֣� 
���µ�һ��ť
���ɾ��ѷ���
���µڶ���ť
����û���ܾ�
ԲͲ����һ���¿��ϵľ��䣺 
����Ҳ��������
�������������岢����ɱ��
����ֹɱ

LONG);
                set("material", "gold");
        }
        ::init_item();
} 
void init()
{
        add_action("do_shoot","shoot");
} 
int do_shoot(string arg)
{
        object ob;
        object me;
   string where;
        int dp;
        int damage;
        if (!arg) return notify_fail("��Ҫ��˭��\n");
//        if (query("used")) return notify_fail(this_object()->name()+"�Ѿ������ˡ�\n");
        me=this_player();
        if ( me->query("combat_exp") < 50000 )
                return notify_fail("�㾭��̫���ˣ�û�а취����" + this_object()->name()+"�ķ����ؾ���\n");
        if( environment(me)->query("no_fight") || environment(me)->query("no_magic") || environment(me)->query("no_spells"))
                return notify_fail("���ⲻ��͵Ϯ��\n");
        ob=present(arg,environment(me));
        if (!objectp(ob) || !living(ob)) 
                return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
        
        message_vision(BLU"$N��Ȼ��������һ��ԲͲ״�Ķ�������\n"NOR,me);
        if (ob!=me)
                message_vision(HIY"$N����$n���������еĿ�ȸ�ᣬ��ϻ������������һƬ��⡣��������\n",me,ob);
        else {
                message("vision",HIY""+me->name()+HIW"�����Լ����������еĿ�ȸ�ᣬ��ϻ������������һƬ���⡣��������\n"NOR,environment(me),me);
                tell_object(me,HIY"������Լ����������еĿ�ȸ�ᣬ��ϻ������������һƬ���⡣��������\n"NOR);
        }
            
        where=file_name(environment(ob));
        if (!userp(ob) && where[0..6]=="/d/cave") {
                message_vision(YEL"$N��Ц��:�����С��Ҳ�������������������Ū,��ү���ö��ˣ�\n"NOR,ob);
                message_vision(YEL"$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n\n"NOR,ob);
        } else {                
                if (ob->query_skill("perception")/10>random(22)) {
                        if (me!=ob) message_vision("$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n\n",ob);
                        else {
                                message("vision",me->name()+"������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n\n",environment(me),me);
                                tell_object(me,"��������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n\n");
                        }       
                }else {
                        message_vision(RED"������$N���ϣ�һ������ʧ�ˡ�\n\n"NOR,ob);
                        dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
                        damage=3000000-dp;
                        damage/=100;
                        if (damage<0) damage=0;
                        ob->receive_wound("kee",damage,me);    
                           ob->receive_wound("gin",damage,me);    
                        ob->receive_wound("sen",damage,me);    
                }       
        }       
        COMBAT_D->report_status(ob);                                         
        if (ob!=me)     ob->kill_ob(me); 
        set("used",10);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
}     