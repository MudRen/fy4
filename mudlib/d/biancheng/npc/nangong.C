// banker.c
#include <ansi.h> 
inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("�Ϲ�С��", ({ "xiaodi" }) );
        set("title", RED "Ǯׯ�ƹ�"NOR);
        set("gender", "����" );
        set("richness",100000);
        set("age", 22);
        set("long",
                
                "��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�С��Ҳ���Ϲ����ҵ�����\n"); 
        set("attitude", "friendly");
        set("fly_target",1);
        set("max_atman", 1000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_force", 1000);
        set("force", 1000);             
        set("force_factor", 3);
        set("max_mana", 1000);   
        set("mana", 1000);              
        set("mana_factor", 3); 
        set_skill("dodge", 10);
        set_skill("parry",100);
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
        add_money("gold", 10);
} 
void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");

}    